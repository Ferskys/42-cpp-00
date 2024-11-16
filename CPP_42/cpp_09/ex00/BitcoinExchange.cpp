
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    exchangeRates = other.exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

std::map<std::string, float> BitcoinExchange::getExchangeRates() const {
    return exchangeRates;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo de taxas de câmbio." << std::endl;
        return;
    }

    loadDatabaseFromFile(file);
}

void BitcoinExchange::loadDatabaseFromFile(std::ifstream &file) {
    std::string line, date;
    float rate;

    // Ignorar cabeçalho
    std::getline(file, line);  // Lê e ignora a primeira linha

    // Processa cada linha do arquivo
    while (std::getline(file, line)) {
        if (processLine(line, date, rate)) {
            // Armazena a taxa no mapa se a linha for válida
            exchangeRates[date] = rate;
            std::cout << "Carregada taxa para " << date << ": " << rate << std::endl;
        }
    }

    // Exibe as taxas carregadas
    showExchangeRates();
}

bool BitcoinExchange::processLine(const std::string &line, std::string &date, float &rate) {
    std::stringstream ss(line);
    std::getline(ss, date, ','); // Lê a data antes do separador ','
    if (!(ss >> rate)) {
        std::cerr << "Erro ao processar linha: " << line << std::endl;
        return false;  // Se não conseguir ler o valor, ignora a linha
    }

    return validateDateAndRate(date, rate);
}

bool BitcoinExchange::validateDateAndRate(const std::string &date, float rate) {
    // Verifique se a data está no formato correto, por exemplo, YYYY-MM-DD
    if (date.empty() || rate < 0 || rate > 1000) {
        std::cerr << "Erro: Dados inválidos - Data: " << date << ", Taxa: " << rate << std::endl;
        return false;
    }

    return true;
}

void BitcoinExchange::showExchangeRates() const {
    std::cout << "Taxas carregadas no mapa:" << std::endl;
    for (std::map<std::string, float>::const_iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it) {
        std::cout << "Data: " << it->first << " => Taxa: " << it->second << std::endl;
        /*Salvar os dados em um arquivo ou exibir na tela
        std::ofstream out("exchange_rates.txt", std::ios::app);
        out << it->first << " " << it->second << std::endl;*/
    }
}

// Método para buscar a taxa de câmbio de uma data
float BitcoinExchange::getRateForDate(const std::string &date) const {
    // Usa lower_bound para buscar a data mais próxima
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);

    // Se it == exchangeRates.begin() e a data é anterior, não existe taxa
    if (it == exchangeRates.begin() && it->first > date) {
        std::cerr << "Erro: Não foi possível encontrar uma taxa para a data: " << date << std::endl;
        return 0.0f;
    }

    // Se encontrou uma data exata
    if (it != exchangeRates.end() && it->first == date) {
        std::cout << "Taxa exata encontrada para " << date << ": " << it->second << std::endl;
        return it->second;
    }

    // Se não encontrou uma data exata, pega a taxa da data anterior
    --it;  // Move para o elemento anterior
    std::cout << "Taxa aproximada encontrada para " << date << ": " << it->second << std::endl;
    return it->second;
}
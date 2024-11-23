#include "BitcoinExchange.hpp"

/* Canonical Form =========================================================== */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : exchangeRates(other.exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}
/* ========================================================================== */

/* Validation Utilities ===================================================== */

/**
 * Verifica se uma string representa uma data válida no formato YYYY-MM-DD.
 */
bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;

    for (size_t i = 0; i < date.size(); ++i) {
        if ((i == 4 || i == 7) && date[i] == '-') continue;
        if (!std::isdigit(date[i])) return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31) return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear && day > 29) return false;
        if (!isLeapYear && day > 28) return false;
    }

    return true;
}

/**
 * Verifica se uma string representa um valor numérico válido e o converte para float.
 */
bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) {
    char* end;
    value = std::strtof(valueStr.c_str(), &end);

    if (*end != '\0' || end == valueStr.c_str()) return false; // Invalid float
    if (value < 0 || value > 1000) {
        std::cerr << (value < 0 ? "Error: not a positive number." : "Error: too large a number.") << std::endl;
        return false;
    }

    return true;
}
/* ========================================================================== */

/* Database Loading ========================================================= */

/**
 * Carrega o banco de dados de taxas de câmbio a partir de um arquivo CSV.
 */
void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rateStr;
        float rate;

        if (!std::getline(ss, date, ',') || !(ss >> rate)) {
            std::cerr << "Error: bad line in database: " << line << std::endl;
            continue;
        }

        if (isValidDate(date) && rate >= 0) {
            exchangeRates[date] = rate;
        } else {
            std::cerr << "Error: invalid date or rate in database: " << line << std::endl;
        }
    }
}
/* ========================================================================== */

/* Input File Processing ==================================================== */

/**
 * Processa o arquivo de entrada, avaliando cada linha com base nas taxas de câmbio do banco de dados.
 */
void BitcoinExchange::processInputFile(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open input file.");
    }

    std::string line;
    std::getline(file, line); // Ignore header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;
        float value;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
            reportBadInput(line);
            continue;
        }

        cleanWhitespace(date);
        cleanWhitespace(valueStr);

        if (!isValidDate(date) || !isValidValue(valueStr, value)) {
            reportBadInput(line);
            continue;
        }

        try {
            float rate = getRateForDate(date);
            displayResult(date, value, rate);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
/* ========================================================================== */

/* Helper Methods =========================================================== */

/**
 * Remove espaços em branco extras de uma string (início e fim).
 */
void BitcoinExchange::cleanWhitespace(std::string& str) const {
    str.erase(0, str.find_first_not_of(" \t"));
    str.erase(str.find_last_not_of(" \t") + 1);
}

/**
 * Exibe uma mensagem para entradas inválidas no arquivo de entrada.
 */
void BitcoinExchange::reportBadInput(const std::string& line) const {
    std::cerr << "Error: bad input => " << line << std::endl;
}

/**
 * Localiza a taxa de câmbio mais próxima da data especificada.
 */
float BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);

    if (it != exchangeRates.end() && it->first == date) {
        return it->second;
    }

    if (it == exchangeRates.begin()) {
        throw std::runtime_error("Error: no exchange rate available for this date.");
    }

    --it;
    return it->second;
}

/**
 * Exibe o resultado formatado para uma data, valor e taxa de câmbio.
 */
void BitcoinExchange::displayResult(const std::string& date, float value, float rate) const {
    std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << (value * rate) << std::endl;
}
/* ========================================================================== */
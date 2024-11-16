#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    // Verificação de argumentos
    if (argc != 2) {
        std::cerr << "Erro: número de argumentos inválido." << std::endl;
        return 1;
    }

    // Teste do Construtor Padrão
    std::cout << "Iniciando teste do Construtor Padrão..." << std::endl;
    BitcoinExchange btc;
    btc.loadDatabase(argv[1]);

    // Teste do Construtor de Cópia
    std::cout << "Iniciando teste do Construtor de Cópia..." << std::endl;
    BitcoinExchange btc_copy(btc);

    // Itera sobre todas as entradas de exchangeRates para verificar as taxas de câmbio
    std::map<std::string, float> exchangeRates = btc.getExchangeRates();
    for (std::map<std::string, float>::iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it) {
        const std::string& date = it->first;
        float rate_original = it->second;

        // Obtém a taxa correspondente na cópia
        float rate_copy = btc_copy.getRateForDate(date);

        // Compara as taxas para a data atual
        std::cout << "Taxa original para " << date << ": " << rate_original
                  << ", Taxa copiada para " << date << ": " << rate_copy << std::endl;

        // Verifica se as taxas são iguais, ou seja, a cópia é fiel
        assert(rate_original == rate_copy);
    }

    std::cout << "Construtor de Cópia: Teste passado!" << std::endl;

    // Teste do Operador de Atribuição
    std::cout << "Iniciando teste do Operador de Atribuição..." << std::endl;
    BitcoinExchange btc_assigned;
    btc_assigned = btc;  // Atribui o objeto btc a btc_assigned

    // Itera novamente sobre as entradas para validar a atribuição
    exchangeRates = btc_assigned.getExchangeRates();
    for (std::map<std::string, float>::iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it) {
        const std::string& date = it->first;
        float rate_original = it->second;

        float rate_assigned = btc_assigned.getRateForDate(date);

        std::cout << "Taxa original para " << date << ": " << rate_original
                  << ", Taxa atribuída para " << date << ": " << rate_assigned << std::endl;

        // Verifica se as taxas atribuídas são iguais
        assert(rate_original == rate_assigned);
    }

    std::cout << "Operador de Atribuição: Teste passado!" << std::endl;

    // Teste do Destruidor
    std::cout << "Iniciando teste do Destruidor..." << std::endl;
    // Simulando a destruição dos objetos ao sair do escopo
    {
        BitcoinExchange btc_temp;
        btc_temp.loadDatabase(argv[1]);
        std::cout << "Objetos temporários destruídos automaticamente." << std::endl;
    }
    std::cout << "Destruidor: Teste passado!" << std::endl;

    // Processamento do arquivo de entrada
    std::ifstream file(argv[1]);
    std::string line, date;

    if (!file.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo de entrada." << std::endl;
        return 1;
    }

    return 0;
}
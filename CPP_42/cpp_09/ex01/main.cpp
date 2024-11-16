#include "RPN.hpp"

int main(int argc, char **argv) {
    // Verifica se o número correto de argumentos foi fornecido
    if (argc != 2) {
        std::cerr << "Error: Invalid arguments." << std::endl;
        std::cerr << "Usage: " << argv[0] << " \"RPN_EXPRESSION\"" << std::endl;
        return 1;
    }

    try {
        RPN rpn; // Instancia o objeto RPN
        int result = rpn.evaluate(argv[1]); // Avalia a expressão RPN passada como argumento
        std::cout << "Result: " << result << std::endl; // Exibe o resultado
    } catch (const std::exception &e) {
        // Captura e exibe exceções do tipo std::exception
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        // Captura quaisquer outras exceções inesperadas
        std::cerr << "Error: An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}
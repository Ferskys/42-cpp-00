#include "Bureaucrat.hpp"
#include <sstream>  // Para usar std::istringstream

int main(int argc, char* argv[]) {
    // Verificação de número correto de argumentos
    if (argc != 3) {
        std::cerr << "Error: Incorrect number of arguments.\n" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <name> <grade>" << std::endl;
        std::cerr << "Please provide the following:\n";
        std::cerr << "1. A name for the Bureaucrat (string)." << std::endl;
        std::cerr << "2. A grade for the Bureaucrat (integer between 1 and 150)." << std::endl;
        std::cerr << "Example: ./ex00 \"John Doe\" 42" << std::endl;
        return 1;  // Código de erro se o número de argumentos for incorreto
    }

    std::string name = argv[1];
    int grade;

    // Converter argv[2] para int usando std::istringstream
    std::istringstream iss(argv[2]);
    if (!(iss >> grade) || grade < 1 || grade > 150) {
        std::cerr << "Error: Invalid grade." << std::endl;
        std::cerr << "The grade must be an integer between 1 (highest) and 150 (lowest)." << std::endl;
        return 1;  // Código de erro se o grade não for um número válido (fazer uma macro com uma msg de erro ?)
    }

    try {
        // Criando o objeto Bureaucrat
        Bureaucrat bureaucrat(name, grade);
        std::cout << bureaucrat << std::endl;

        // Teste de incremento e decremento da nota
        std::cout << "Incrementing the grade..." << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;

        std::cout << "Decrementing the grade..." << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
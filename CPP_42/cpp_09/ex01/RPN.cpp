#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &other) : values(other.values) {}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        values = other.values;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::exitProgram() const {
    std::exit(EXIT_FAILURE);
}

int RPN::evaluate(const std::string &expression) {
    std::stringstream ss(expression);
    std::string token;
    
    while (ss >> token) {
        // Verificar se o token é um número
        if (isdigit(token[0]) && token.length() == 1) {
            int number = token[0] - '0';
            if (number < 0 || number > 9) { 
                std::cerr << "Error: Numbers must be between 0 and 9." << std::endl;
                exitProgram();
            }
            values.push(number);
        } 
        // Verificar se o token é um operador válido
        else if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
            if (values.size() < 2) {
                std::cerr << "Error: Invalid expression (not enough operands for operator '" 
                          << token[0] << "')." << std::endl;
                exitProgram();
            }
            int val2 = values.top(); values.pop();
            int val1 = values.top(); values.pop();

            if (token[0] == '/' && val2 == 0) {
                std::cerr << "Error: Division by zero." << std::endl;
                exitProgram();
            }

            switch (token[0]) {
                case '+': values.push(val1 + val2); break;
                case '-': values.push(val1 - val2); break;
                case '*': values.push(val1 * val2); break;
                case '/': values.push(val1 / val2); break;
                default: 
                    std::cerr << "Error: Unknown operator '" << token[0] << "'." << std::endl;
                    exitProgram();
            }
        } 
        // Caso contrário, é um token inválido
        else {
            std::cerr << "Error: Invalid token '" << token << "'." << std::endl;
            exitProgram();
        }
    }

    // Verificar o estado final da pilha
    if (values.size() != 1) {
        std::cerr << "Error: Invalid expression (remaining operands in the stack)." << std::endl;
        exitProgram();
    }

    return values.top();
}
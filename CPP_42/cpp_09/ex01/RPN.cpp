#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN &other) : values(other.values) {}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        values = other.values;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression) {
    std::stringstream ss(expression);
    std::string token;
    
    while (ss >> token) {
        if (isdigit(token[0])) {
            values.push(token[0] - '0');
        } else {
            if (values.size() < 2) {
                std::cerr << "Error: Invalid expression." << std::endl;
                return 0;
            }
            int val2 = values.top(); values.pop();
            int val1 = values.top(); values.pop();
            switch (token[0]) {
                case '+': values.push(val1 + val2); break;
                case '-': values.push(val1 - val2); break;
                case '*': values.push(val1 * val2); break;
                case '/': values.push(val1 / val2); break;
                default: std::cerr << "Error: Invalid operator." << std::endl; return 0;
            }
        }
    }
    
    return values.top();
}

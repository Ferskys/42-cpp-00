#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Invalid arguments." << std::endl;
        return 1;
    }

    RPN rpn;
    int result = rpn.evaluate(argv[1]);
    std::cout << result << std::endl;
    return 0;
}

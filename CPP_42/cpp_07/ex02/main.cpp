#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> numbers(5);

    try {
        for (unsigned int i = 0; i < numbers.size(); i++) {
            numbers[i] = i * 2;
            std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
        }
        numbers[5] = 10;  // Out of bounds
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

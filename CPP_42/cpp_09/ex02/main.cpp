#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <deque>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: At least one positive integer argument is required." << std::endl;
        return 1;
    }

    std::list<int> lst;
    std::deque<int> deq;

    try {
        for (int i = 1; i < argc; ++i) {
            int num = std::atoi(argv[i]);
            if (num <= 0) throw std::invalid_argument("Non-positive integers are not allowed.");
            lst.push_back(num);
            deq.push_back(num);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    // Exibir antes da ordenação (usando iteradores para C++98)
    std::cout << "Before: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    PmergeMe pm;

    // Medir e realizar a ordenação para std::list
    std::clock_t start = std::clock();
    pm.sortList(lst);
    std::clock_t end = std::clock();
    double timeList = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    // Medir e realizar a ordenação para std::deque
    start = std::clock();
    pm.sortDeque(deq);
    end = std::clock();
    double timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    // Exibir depois da ordenação (usando iteradores para C++98)
    std::cout << "After: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << timeList << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << timeDeque << " us" << std::endl;

    return 0;
}

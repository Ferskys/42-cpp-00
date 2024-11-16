#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortWithVector(std::vector<int> &vec) {
    if (!vec.empty()) {
        std::sort(vec.begin(), vec.end());
    } else {
        throw std::invalid_argument("Vector is empty");
    }
}

void PmergeMe::sortWithList(std::list<int> &lst) {
    if (!lst.empty()) {
        lst.sort();
    } else {
        throw std::invalid_argument("List is empty");
    }
}

void PmergeMe::sortWithList(std::list<int> &lst) {
    lst.sort();
}

void PmergeMe::displayResults(const std::vector<int> &vec, const std::list<int> &lst) {
    std::cout << "Sorted vector: ";
    for (const int &n : vec) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "Sorted list: ";
    for (const int &n : lst) std::cout << n << " ";
    std::cout << std::endl;
}

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortWithVector(std::vector<int> &vec) {
    std::sort(vec.begin(), vec.end());
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

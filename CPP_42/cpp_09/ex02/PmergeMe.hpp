#pragma once
#include <vector>
#include <list>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    
    void sortWithVector(std::vector<int> &vec);
    void sortWithList(std::list<int> &lst);
    void displayResults(const std::vector<int> &vec, const std::list<int> &lst);
};

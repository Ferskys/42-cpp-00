#include "PmergeMe.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <ctime>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: Invalid arguments." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        vec.push_back(num);
        lst.push_back(num);
    }

    PmergeMe pm;
    
    clock_t startVec = clock();
    pm.sortWithVector(vec);
    clock_t endVec = clock();
    
    clock_t startLst = clock();
    pm.sortWithList(lst);
    clock_t endLst = clock();

    pm.displayResults(vec, lst);
    
    std::cout << "Time for vector: " << (double)(endVec - startVec) / CLOCKS_PER_SEC << " seconds." << std::endl;
    std::cout << "Time for list: " << (double)(endLst - startLst) / CLOCKS_PER_SEC << " seconds." << std::endl;
    
    return 0;
}

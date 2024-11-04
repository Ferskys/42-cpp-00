#include "easyfind.hpp"

int main() {
    // Initialize the vector using the constructor
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    try {
        std::cout << "Found: " << *easyfind(vec, 3) << std::endl;
        std::cout << "Found: " << *easyfind(vec, 6) << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Value not found!" << std::endl;
    }

    return 0;
}
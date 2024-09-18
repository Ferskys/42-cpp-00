#include <iostream>
#include "iter.hpp"

void print(int& x) {
    std::cout << x << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    ::iter(arr, 5, print);
    return 0;
}

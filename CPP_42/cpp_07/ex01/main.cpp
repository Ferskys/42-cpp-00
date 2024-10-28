#include <iostream>
#include "iter.hpp"

// Function to be passed to iter, which prints the value of the element
void print(int& x) {
    std::cout << x << std::endl;
}

// Function to be passed to iter, which doubles the value of the element
void doubleValue(int& x) {
    x *= 2;
}

// Function to be passed to iter, which prints the value of the element (for double type)
void printDouble(double& x) {
    std::cout << x << std::endl;
}

/*  Initial message explaining the purpose of the program
    Example 1: Applying print function to an array of integers
    Example 2: Applying doubleValue function to an array of integers and then printing the array
    Example 3: Applying print function to an array of doubles
    Final message indicating that the execution has finished */
int main() {
    std::cout << "This program demonstrates the iter function, which applies a function to each element of an array." << std::endl;

    std::cout << "\nExample 1: Printing an array of integers" << std::endl;
    int arr1[] = {1, 2, 3, 4, 5};
    iter(arr1, 5, print);

    std::cout << "\nExample 2: Doubling the values of an array of integers and then printing" << std::endl;
    int arr2[] = {1, 2, 3, 4, 5};
    iter(arr2, 5, doubleValue);
    iter(arr2, 5, print);

    std::cout << "\nExample 3: Printing an array of doubles" << std::endl;
    double arr3[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(arr3, 5, printDouble);

    std::cout << "\nExecution of the iter function completed." << std::endl;

    return 0;
}
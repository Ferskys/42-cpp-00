#include <iostream>
#include "Array.hpp"

int main() {
    // Test 1: Default constructor (empty array)
    Array<int> emptyArray;
    std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

    // Test 2: Constructor with size
    Array<int> intArray(5);
    std::cout << "Size of intArray: " << intArray.size() << std::endl;

    // Test 3: Accessing elements and default initialization
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    // Test 4: Copy constructor
    Array<int> copyArray(intArray);
    std::cout << "Size of copyArray: " << copyArray.size() << std::endl;

    // Modify original array and check that copy remains unchanged
    intArray[0] = 42;
    std::cout << "After modifying intArray[0] to 42:" << std::endl;
    std::cout << "intArray[0] = " << intArray[0] << std::endl;
    std::cout << "copyArray[0] = " << copyArray[0] << std::endl;

    // Test 5: Assignment operator
    Array<int> assignedArray;
    assignedArray = intArray;  // Using assignment operator
    std::cout << "Assigned Array size: " << assignedArray.size() << std::endl;

    // Modify original and check that assigned array remains unchanged
    intArray[1] = 100;
    std::cout << "After modifying intArray[1] to 100:" << std::endl;
    std::cout << "intArray[1] = " << intArray[1] << std::endl;
    std::cout << "assignedArray[1] = " << assignedArray[1] << std::endl;

    // Test 6: Exception handling for out-of-bounds access
    try {
        std::cout << intArray[10] << std::endl;  // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
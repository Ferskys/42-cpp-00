#include "MutantStack.hpp"
int main() 
{
    std::cout << "=== Testing MutantStack ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.pop();
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::vector<int> elements;
    std::stack<int> tempStack;

    while (!mstack.empty()) {
        tempStack.push(mstack.top());
        mstack.pop();
    }

    while (!tempStack.empty()) {
        elements.push_back(tempStack.top());
        tempStack.pop();
    }

    std::cout << "Contents of MutantStack in order of insertion:" << std::endl;
    for (size_t i = 0; i < elements.size(); ++i) {
        std::cout << elements[i] << std::endl;
    }

     std::cout << "Contents of MutantStack in reverse order of insertion:" << std::endl;
    for (size_t i = elements.size(); i > 0; --i) {
        std::cout << elements[i - 1] << std::endl;
    }

    std::cout << "=== Attempting to access the top element of an empty stack ===" << std::endl;
    if (mstack.empty()) {
        std::cout << "Stack is empty, cannot access top element." << std::endl;
    }

    std::cout << "=== Testing Element Order ===" << std::endl;
    MutantStack<int> testStack;
    testStack.push(10);
    testStack.push(20);
    testStack.push(30);
    std::vector<int> checkOrder;
    while (!testStack.empty()) {
        checkOrder.push_back(testStack.top());
        testStack.pop();
    }
    std::cout << "Checking order of elements retrieved from the stack:" << std::endl;
    for (size_t i = 0; i < checkOrder.size(); ++i) {
        std::cout << checkOrder[i] << std::endl;
    }

    std::cout << "=== Testing with Strings ===" << std::endl;
    MutantStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    while (!stringStack.empty()) {
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
    }

    std::cout << "=== Iterating Over MutantStack ===" << std::endl;
    MutantStack<int> iterStack;
    iterStack.push(1);
    iterStack.push(2);
    iterStack.push(3);
    std::cout << "Elements in MutantStack:" << std::endl;
    for (MutantStack<int>::iterator it = iterStack.begin(); it != iterStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "=== Testing Stack Copying ===" << std::endl;
    MutantStack<int> originalStack;
    originalStack.push(100);
    originalStack.push(200);
    MutantStack<int> copyStack(originalStack);
    std::cout << "Elements in the copied stack:" << std::endl;
    while (!copyStack.empty()) {
        std::cout << copyStack.top() << std::endl;
        copyStack.pop();
    }

    std::cout << "=== Testing Stack Cleanup ===" << std::endl;
    MutantStack<int> cleanStack;
    cleanStack.push(42);
    cleanStack.pop();
    if (cleanStack.empty()) {
        std::cout << "The cleanStack is now empty!" << std::endl;
    }

    std::cout << "=== Testing std::list ===" << std::endl;
    std::list<int> myList;
    myList.push_back(5);
    myList.push_back(17);
    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);
    myList.remove(17);
    std::cout << "Contents of the list after removing 17:" << std::endl;
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
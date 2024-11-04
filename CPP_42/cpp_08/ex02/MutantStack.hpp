#pragma once
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <exception>
#include <string>
#include <deque> 

template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::deque<T>::iterator iterator;
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    ~MutantStack() {}

    MutantStack& operator=(const MutantStack& other) {
        std::stack<T>::operator=(other);
        return *this;
    }

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
};
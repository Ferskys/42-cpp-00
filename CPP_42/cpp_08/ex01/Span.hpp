#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
public:
    Span(unsigned int n);
    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

private:
    std::vector<int> _numbers;
    unsigned int _maxSize;
};

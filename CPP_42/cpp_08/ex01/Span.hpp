#pragma once
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span {
public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void    addNumber(int num);
    int     shortestSpan() const;
    int     longestSpan() const;
    void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

private:
    std::vector<int>    _numbers;
    unsigned int        _maxSize;
};

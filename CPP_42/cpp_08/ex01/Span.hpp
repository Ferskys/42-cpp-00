#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
public:
    Span(); // Construtor padrão
    Span(unsigned int n);
    Span(const Span& other); // Construtor de cópia
    Span& operator=(const Span& other); // Operador de atribuição de cópia
    ~Span(); // Destrutor

    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

private:
    std::vector<int> _numbers;
    unsigned int _maxSize;
};

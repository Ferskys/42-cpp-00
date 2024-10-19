#include "Span.hpp"
#include <stdexcept>
#include <limits>
#include <algorithm>

// Construtor padrão
Span::Span() : _maxSize(0) {}

// Construtor com parâmetro
Span::Span(unsigned int n) : _maxSize(n) {}

// Construtor de cópia
Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

// Operador de atribuição de cópia
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

// Destrutor
Span::~Span() {}

// Função para adicionar um número
void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Span is full");
    }
    _numbers.push_back(num);
}

// Função para encontrar o menor span
int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers for a span");
    }
    std::vector<int> sorted_numbers = _numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted_numbers.size(); ++i) {
        int span = sorted_numbers[i] - sorted_numbers[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

// Função para encontrar o maior span
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers for a span");
    }
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

// Função para adicionar um intervalo de números
void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) + _numbers.size() > _maxSize) {
        throw std::out_of_range("Adding too many numbers");
    }
    _numbers.insert(_numbers.end(), begin, end);
}
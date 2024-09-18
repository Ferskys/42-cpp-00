#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Span is full");
    _numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers for a span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
        minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);

    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers for a span");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) + _numbers.size() > _maxSize)
        throw std::out_of_range("Adding too many numbers");
    _numbers.insert(_numbers.end(), begin, end);
}

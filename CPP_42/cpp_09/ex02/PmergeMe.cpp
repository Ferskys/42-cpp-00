#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>

Sorter::Sorter() {}
Sorter::Sorter(const Sorter&) {}
Sorter& Sorter::operator=(const Sorter&) { return *this; }
Sorter::~Sorter() {}

FordJohnsonSorter::FordJohnsonSorter() : Sorter() {}

FordJohnsonSorter::FordJohnsonSorter(const FordJohnsonSorter& other) 
    : Sorter(other) {
    // Não há membros próprios a serem copiados nesta classe
}

FordJohnsonSorter& FordJohnsonSorter::operator=(const FordJohnsonSorter& other) {
    if (this != &other) {
        Sorter::operator=(other); // Chama a atribuição da classe base
    }
    return *this;
}

FordJohnsonSorter::~FordJohnsonSorter() {}

void FordJohnsonSorter::sort(std::list<int>& lst) {
    mergeInsertSortList(lst);
}

void FordJohnsonSorter::sort(std::deque<int>& deq) {
    mergeInsertSortDeque(deq);
}

Sorter* FordJohnsonSorter::clone() const {
    return new FordJohnsonSorter(*this);
}

void FordJohnsonSorter::mergeInsertSortList(std::list<int>& lst) {
    if (lst.size() < 2) return;

    // Dividir pares e ímpares
    std::list<int> pairs, singles;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        pairs.push_back(*it);
        ++it;
        if (it != lst.end()) {
            singles.push_back(*it);
            ++it;
        }
    }

    // Ordenar pares e mesclar pares + ímpares
    pairs.sort();
    singles.sort();
    std::list<int> merged;
    std::merge(pairs.begin(), pairs.end(), singles.begin(), singles.end(), std::back_inserter(merged));
    lst.swap(merged);
}

void FordJohnsonSorter::mergeInsertSortDeque(std::deque<int>& deq) {
    if (deq.size() < 2) return;

    // Dividir pares e ímpares
    std::deque<int> pairs, singles;
    for (size_t i = 0; i < deq.size(); ++i) {
        pairs.push_back(deq[i]);
        ++i;
        if (i < deq.size()) {
            singles.push_back(deq[i]);
        }
    }

    // Ordenar pares e mesclar pares + ímpares
    std::sort(pairs.begin(), pairs.end());
    std::sort(singles.begin(), singles.end());
    std::deque<int> merged;
    std::merge(pairs.begin(), pairs.end(), singles.begin(), singles.end(), std::back_inserter(merged));
    deq.swap(merged);
}

PmergeMe::PmergeMe() : sorter(new FordJohnsonSorter()) {}
PmergeMe::PmergeMe(const PmergeMe& other) : sorter(0) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        delete sorter;
        sorter = other.sorter->clone();
    }
    return *this;
}

PmergeMe::~PmergeMe() {
    delete sorter;
}

void PmergeMe::sortList(std::list<int>& lst) {
    sorter->sort(lst);
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
    sorter->sort(deq);
}
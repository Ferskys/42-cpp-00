#pragma once

#include <list>
#include <deque>
#include <stdexcept>
#include <ctime>

// Classe base para algoritmos de ordenação
class Sorter {
public:
    Sorter();
    Sorter(const Sorter& other);
    Sorter& operator=(const Sorter& other);
    virtual ~Sorter();

    virtual void sort(std::list<int>& lst) = 0;
    virtual void sort(std::deque<int>& deq) = 0;
    virtual Sorter* clone() const = 0;
};

// Implementação do algoritmo Ford-Johnson
class FordJohnsonSorter : public Sorter {
public:
    FordJohnsonSorter();
    FordJohnsonSorter(const FordJohnsonSorter& other);
    FordJohnsonSorter& operator=(const FordJohnsonSorter& other);
    virtual ~FordJohnsonSorter();

    void sort(std::list<int>& lst);
    void sort(std::deque<int>& deq);
    Sorter* clone() const;

private:
    void mergeInsertSortList(std::list<int>& lst);
    void mergeInsertSortDeque(std::deque<int>& deq);
};

// Classe principal PmergeMe
class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sortList(std::list<int>& lst);
    void sortDeque(std::deque<int>& deq);

private:
    Sorter* sorter;
};

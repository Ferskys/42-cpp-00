#pragma once
#include <stdexcept>

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    // Default constructor: Creates an empty array
    Array() : _data(NULL), _size(0) {}

    // Constructor with size: Creates an array of n elements initialized by default
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Copy constructor: Creates a copy of another Array
    Array(const Array& other) : _data(new T[other._size]), _size(other._size) {
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    // Copy-and-Swap assignment operator
    Array& operator=(Array other) {
        swap(other); 
        return *this;
    }

    // Destructor: Frees the allocated memory
    ~Array() {
        delete[] _data;
    }

    // Swap function: Swaps the content of this Array with another using global swap
    void swap(Array& other) {
        ::swap(_data, other._data);
        ::swap(_size, other._size);
    }

    // Non-const index operator
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // Const index operator
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // Member function to return the number of elements in the array
    unsigned int size() const {
        return _size;
    }
};
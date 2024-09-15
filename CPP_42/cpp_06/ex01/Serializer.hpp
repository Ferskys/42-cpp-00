#pragma once
#include "Data.hpp"

// Use unsigned long instead of uintptr_t
class Serializer {
public:
    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long raw);
private:
    Serializer(); // Prevent instantiation
};

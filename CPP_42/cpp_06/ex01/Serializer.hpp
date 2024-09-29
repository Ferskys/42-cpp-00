#pragma once
#include "Data.hpp"
#include <stdint.h>

// Use unsigned long instead of uintptr_t
class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer(); // Prevent instantiation
};
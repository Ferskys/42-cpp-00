#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data data;
    data.value = 42;
    data.name = "Example";
    
    std::cout << "Original Data: " << data.value << ", " << data.name << std::endl;

    unsigned long raw = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Deserialized Data: " << deserializedData->value << ", " << deserializedData->name << std::endl;

    return 0;
}

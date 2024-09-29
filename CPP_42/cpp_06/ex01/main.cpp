#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    // Cria uma instância da estrutura Data e inicializa seus membros
    Data data;
    data.value = 42;
    data.name = "Example";
    
    // Exibe os valores originais da estrutura Data
    std::cout << "Original Data: " << data.value << ", " << data.name << std::endl;

    // Serializa o ponteiro para a estrutura Data em um valor bruto (raw)
    unsigned long raw = Serializer::serialize(&data);

    // Desserializa o valor bruto (raw) de volta para um ponteiro para a estrutura Data
    Data* deserializedData = Serializer::deserialize(raw);

    // Exibe os valores da estrutura Data desserializada
    std::cout << "Deserialized Data: " << deserializedData->value << ", " << deserializedData->name << std::endl;

    return 0;
}
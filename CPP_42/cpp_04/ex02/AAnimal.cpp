#include "AAnimal.hpp"

AAnimal::AAnimal() : type("") {
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}
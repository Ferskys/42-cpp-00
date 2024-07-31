#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << "Passing through WrongAnimal copy constructor" << std::endl;
	*this = other;
	return;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "Passing through WrongAnimal operator=() overload" << std::endl;
	this->type = other.getType();
	return *this;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

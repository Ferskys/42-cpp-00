#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Passing through Cat copy constructor" << std::endl;
	*this = other;
	return;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Passing through Cat operator=() overload" << std::endl;
	this->type = other.getType();
	return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

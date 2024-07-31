#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "Passing through Dog copy constructor" << std::endl;
	*this = other;
	return;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Passing through Dog operator=() overload" << std::endl;
	this->type = other.getType();
	return (*this);
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

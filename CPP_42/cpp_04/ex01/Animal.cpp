#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
	return;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
	return;
}

Animal::Animal(Animal const &other)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = other;
	return;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "operator=() overload" << std::endl;
    if ((this->type == "Cat" || this->type == "Dog") && (other.type == "Cat" || other.type == "Dog"))
        *get_brain() = *other.get_brain();
    this->type = other.type;
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << "BUUUUUAAAA" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

Brain	*Animal::get_brain(void) const
{
	return (NULL);
}
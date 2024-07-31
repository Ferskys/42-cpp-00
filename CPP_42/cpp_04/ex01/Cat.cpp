#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
	return;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
	return;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor" << std::endl;
	this->brain = new Brain();
	*this = other;
	return;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat operator=() overload" << std::endl;
	this->type = other.type;
	*(this->brain) = *(other.brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

Brain	*Cat::get_brain() const
{
	return (this->brain);
}
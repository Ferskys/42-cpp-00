#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
	return;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = other;
	return;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat operator=() overload" << std::endl;
	this->type = other.getType();
	return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "WrongMeow" << std::endl;
}

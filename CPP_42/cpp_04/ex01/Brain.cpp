#include "Brain.hpp"

Brain::Brain() : ideas()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	for (unsigned i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
	return *this;
}
#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain* brain;

public:
    Dog();
    virtual ~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	void makeSound() const;
	Brain *get_brain(void) const;
};

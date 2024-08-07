#pragma once

#include <string>
#include "Brain.hpp"

class Animal {
protected:
    std::string type;

public:
    Animal();
	virtual ~Animal(void);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	void makeSound(void) const;
	virtual Brain *get_brain(void) const;
	virtual std::string getType(void) const;
};

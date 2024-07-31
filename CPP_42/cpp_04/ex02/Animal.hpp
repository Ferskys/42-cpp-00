#pragma once

#include <string>

class AAnimal {
protected:
    std::string type;

public:
    Animal();
	virtual ~Animal(void);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	virtual void makeSound(void) const;
	virtual Brain *get_brain(void) const;

	std::string getType(void) const;
};

#pragma once

#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    virtual ~AAnimal(); // Destruidor virtual
    virtual void makeSound() const = 0; // Método puro virtual
    virtual void doSomething() const = 0; // Método adicional puro virtual
    std::string getType() const;
};

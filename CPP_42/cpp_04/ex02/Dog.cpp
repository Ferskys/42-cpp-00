#include "Dog.hpp"

Dog::Dog() : AAnimal() {
    brain = new Brain();
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    brain = new Brain(*other.brain);
    type = other.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        type = other.type;
        std::cout << "Dog assignment operator called" << std::endl;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

void Dog::doSomething() const {
    std::cout << "Dog is doing something" << std::endl;
}

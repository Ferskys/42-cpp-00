#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

int main() {
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    // Criar e preencher o array de objetos Animal
    for (int i = 0; i < numAnimals / 2; ++i)
	{
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i)
	{
        animals[i] = new Cat();
    }

    // Exibir os tipos e sons dos animais
    for (int i = 0; i < numAnimals; ++i)
	{
        std::cout << animals[i]->getType() << " " << std::endl;
        animals[i]->makeSound();
    }

    // Liberar a memória
    for (int i = 0; i < numAnimals; ++i)
	{
        delete animals[i];
    }

    return (0);
}

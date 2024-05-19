# Unnecessary Violence

## Descrição

Este programa demonstra o uso de ponteiros e referências em C++ através da implementação de classes `Weapon`, `HumanA` e `HumanB`. O objetivo é compreender a diferença entre passar objetos por referência e por ponteiro, bem como as implicações dessas práticas na programação.

## Objetivos

- Implementar uma classe `Weapon` com um atributo privado `type`, e métodos `getType()` e `setType()`.
- Implementar classes `HumanA` e `HumanB` que possuem um `Weapon` e um `name`, e uma função `attack()` que exibe `<name> attacks with their <weapon type>`.
- `HumanA` sempre tem uma arma passada no construtor, enquanto `HumanB` pode não ter uma arma inicialmente e pode defini-la posteriormente.

## Estrutura do Projeto

- `main.cpp`: Implementação principal do programa.
- `Weapon.hpp` e `Weapon.cpp`: Declaração e implementação da classe `Weapon`.
- `HumanA.hpp` e `HumanA.cpp`: Declaração e implementação da classe `HumanA`.
- `HumanB.hpp` e `HumanB.cpp`: Declaração e implementação da classe `HumanB`.
- `Makefile`: Para compilar e limpar o projeto.

A saída esperada ao executar o programa fornecido no main.cpp é a seguinte:

python

Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club

Explicação da Saída

    Primeiro Bloco (HumanA):

    cpp

{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
}

    Weapon club = Weapon("crude spiked club");: Cria uma arma chamada "crude spiked club".
    HumanA bob("Bob", club);: Cria um objeto HumanA chamado "Bob" com a arma club.
    bob.attack();: Imprime "Bob attacks with their crude spiked club".
    club.setType("some other type of club");: Muda o tipo da arma para "some other type of club".
    bob.attack();: Imprime "Bob attacks with their some other type of club".

Segundo Bloco (HumanB):

cpp

    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

        Weapon club = Weapon("crude spiked club");: Cria uma arma chamada "crude spiked club".
        HumanB jim("Jim");: Cria um objeto HumanB chamado "Jim" sem arma inicialmente.
        jim.setWeapon(club);: Define a arma de Jim como club.
        jim.attack();: Imprime "Jim attacks with their crude spiked club".
        club.setType("some other type of club");: Muda o tipo da arma para "some other type of club".
        jim.attack();: Imprime "Jim attacks with their some other type of club".

Resumo

A saída mostra que tanto HumanA quanto HumanB referenciam o mesmo objeto Weapon, e as mudanças no tipo da arma são refletidas nas instâncias de ambos os humanos.
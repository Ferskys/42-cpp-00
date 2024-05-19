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

Saída Esperada

A execução do programa deve gerar a seguinte saída:

python

Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club

Conceitos Envolvidos

    Ponteiros: Variáveis que armazenam endereços de memória.
    Referências: Apelidos para variáveis existentes.
    Alocação de Memória: Diferença entre stack e heap (embora não explicitamente usada aqui).

Exemplo Explicativo

Considere o código no main.cpp:

cpp

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}

Primeiro Bloco (HumanA):

    Weapon club = Weapon("crude spiked club");: Cria uma arma chamada "crude spiked club".
    HumanA bob("Bob", club);: Cria um objeto HumanA chamado "Bob" com a arma club.
    bob.attack();: Imprime "Bob attacks with their crude spiked club".
    club.setType("some other type of club");: Muda o tipo da arma para "some other type of club".
    bob.attack();: Imprime "Bob attacks with their some other type of club".

Segundo Bloco (HumanB):

    Weapon club = Weapon("crude spiked club");: Cria uma arma chamada "crude spiked club".
    HumanB jim("Jim");: Cria um objeto HumanB chamado "Jim" sem arma inicialmente.
    jim.setWeapon(club);: Define a arma de Jim como club.
    jim.attack();: Imprime "Jim attacks with their crude spiked club".
    club.setType("some other type of club");: Muda o tipo da arma para "some other type of club".
    jim.attack();: Imprime "Jim attacks with their some other type of club".

Resumo

A saída mostra que tanto HumanA quanto HumanB referenciam o mesmo objeto Weapon, e as mudanças no tipo da arma são refletidas nas instâncias de ambos os humanos.
Uso de Ponteiros vs Referências
Referências

    Quando usar: Use referências quando você sabe que o objeto sempre existirá enquanto a referência estiver em uso. Referências são ideais quando a relação entre o objeto e o referenciador é estável e não mudará durante o tempo de vida do objeto referenciado.
    Vantagens: Referências são mais seguras, pois elas não podem ser nulas e uma vez inicializadas, não podem ser alteradas para referenciar outro objeto.
    No programa: HumanA usa uma referência para Weapon porque HumanA é sempre criado com uma arma e essa arma não muda durante a vida do objeto HumanA.

Ponteiros

    Quando usar: Use ponteiros quando você precisa de flexibilidade para alterar qual objeto está sendo referenciado ou quando existe a possibilidade de não haver um objeto para referenciar (ou seja, o ponteiro pode ser nulo).
    Vantagens: Ponteiros permitem a dinâmica de mudança de objetos e podem ser reatribuídos.
    No programa: HumanB usa um ponteiro para Weapon porque HumanB pode ser criado sem uma arma e a arma pode ser definida ou alterada posteriormente.

Contribuindo

Sinta-se à vontade para enviar sugestões, correções de bugs ou melhorias por meio de pull requests.
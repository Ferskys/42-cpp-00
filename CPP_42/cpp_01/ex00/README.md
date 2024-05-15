# BraiiiiiiinnnzzzZ 🧟🧠

## Descrição 📝
O programa "BraiiiiiiinnnzzzZ" em C++ é um projeto que simula a criação e anúncio de zumbis. Ele demonstra conceitos fundamentais de alocação de memória e gerenciamento de objetos em C++. Os zumbis são representados pela classe `Zombie`, que possui um atributo privado do tipo `std::string` para o nome. O programa inclui também duas funções adicionais para criar zumbis: `newZombie` e `randomChump`.

## Funcionalidades 🔧
- **Criação de Zumbis**: A classe `Zombie` é criada com um atributo de nome privado. A função `newZombie` cria um zumbi na memória e retorna um ponteiro para ele.
- **Anúncio de Zumbis**: A classe `Zombie` possui um método `announce` que permite que um zumbi anuncie-se, exibindo seu nome seguido pela mensagem característica de zumbis.
- **Gerenciamento de Memória**: O programa demonstra a diferença entre alocar zumbis na pilha (stack) e na memória heap.

## Compilação e Execução ✏️
O código-fonte do programa é composto pelos seguintes arquivos, que devem ser compilados juntos:
- `main.cpp`: Contém a função `main` onde os zumbis são criados e utilizados.
- `Zombie.hpp` e `Zombie.cpp`: Contêm a definição e implementação da classe `Zombie`, respectivamente.
- `newZombie.hpp` e `newZombie.cpp`: Contêm a função `newZombie` que cria um zumbi na memória heap.
- `randomChump.hpp` e `randomChump.cpp`: Contêm a função `randomChump` que cria um zumbi na memória stack.

Para compilar o programa, utilize o comando `make` no terminal. Isso compilará todos os arquivos necessários e criará o executável `BraiiiiiiinnnzzzZ`.

## Exemplo de Uso 🛠️
```cpp
#include "newZombie.hpp"
#include "randomChump.hpp"

int main() {
    // Cria um novo Zombie na heap
    Zombie* zombie1 = newZombie("HeapZombie");
    zombie1->announce();
    delete zombie1;

    // Cria e anuncia um Zombie na stack
    randomChump("StackZombie");

    return 0;
}
```
Este exemplo demonstra como criar zumbis na memória heap e stack e como utilizá-los no programa.

## Conceitos Demonstrados
- **Classes e Objetos**: A classe `Zombie` é usada para representar zumbis no programa.
- **Alocação de Memória**: O programa demonstra a alocação de memória tanto na heap quanto na stack.
- **Ponteiros**: O uso de ponteiros é demonstrado ao criar e manipular objetos `Zombie`.
- **Funções**: Funções são utilizadas para criar e manipular zumbis no programa.
- **Gerenciamento de Memória**: O programa mostra a importância de liberar a memória alocada para os zumbis quando não forem mais necessários.
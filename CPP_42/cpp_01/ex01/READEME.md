# Moar Brainz!

Este é um programa em C++ desenvolvido como parte do exercício 01 do módulo de programação em C++.

## Descrição do Exercício

O exercício consiste em criar um programa que aloca uma "horda" de zumbis em memória e os inicializa com um nome específico. Cada zumbi deve ser capaz de anunciar seu nome de uma forma característica. Além disso, é necessário garantir que não haja vazamentos de memória, ou seja, todos os zumbis devem ser corretamente destruídos após o uso.

## Conteúdo do Projeto

O projeto é composto pelos seguintes arquivos:

- `main.cpp`: Contém a função principal do programa, responsável por criar a horda de zumbis e testar sua funcionalidade.
- `Zombie.hpp` e `Zombie.cpp`: Definem a classe `Zombie`, que representa um zumbi e possui métodos para anunciar seu nome e definir seu nome.
- `zombieHorde.cpp`: Implementa a função `zombieHorde`, que aloca uma horda de zumbis em memória.
- `Makefile`: Arquivo de script para compilar o programa.

## Compilação e Execução

Para compilar o programa, execute o seguinte comando no terminal:

make

Isso criará o executável `moar_brainz`.

Para executar o programa, utilize o seguinte comando:

./moar_brainz

## Conceitos Abordados

- Alocação dinâmica de memória: O programa aloca uma "horda" de zumbis em memória usando o operador `new`.
- Uso de classes em C++: A classe `Zombie` é utilizada para representar os zumbis, demonstrando conceitos de encapsulamento, construtores, destrutores e métodos de classe.
- Gerenciamento de memória: É essencial garantir que a memória alocada para os zumbis seja corretamente liberada para evitar vazamentos de memória.
- Utilização de Makefile: O arquivo `Makefile` é utilizado para automatizar o processo de compilação do programa, simplificando o processo para o desenvolvedor.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para enviar sugestões, correções de bugs ou melhorias por meio de pull requests.
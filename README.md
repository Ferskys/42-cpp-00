# 42_cpp

# Regras e Objetivos

## Objetivo Geral
- Introduzir conceitos de Programação Orientada a Objetos (OOP) usando C++.
- Seguir o padrão C++98.

## Compilação
- Compilar o código com `c++` e as flags `-Wall -Wextra -Werror`.
- O código deve compilar com a flag `-std=c++98`.

## Convenções de Formatação e Nomeação
- Direcionar os diretórios dos exercícios como `ex00, ex01, ..., exn`.
- Nomear arquivos, classes, funções, métodos e atributos conforme as diretrizes.
- Usar UpperCamelCase para nomes de classes.
- Arquivos de classe devem seguir o nome da classe (ex: `BrickWall.hpp` para a classe `BrickWall`).
- Mensagens de saída devem terminar com um caractere de nova linha.
- Código deve ser limpo e legível, mesmo sem uma norma de estilo específica.

## Permissões e Proibições
- Usar a biblioteca padrão do C++.
- Proibido usar bibliotecas externas como C++11 e Boost.
- Proibido usar `printf()`, `malloc()`, `calloc()`, `realloc()`, `free()`.
- Proibido usar `using namespace <ns_name>` e `friend`.
- Proibido usar STL até os Módulos 08 e 09.
- Gerenciar a memória adequadamente, evitando vazamentos.
- Classes devem seguir a Forma Canônica Ortodoxa (OCF) a partir do Módulo 02.
- Implementações de funções em arquivos header, exceto templates, resultam em nota 0.
- Headers devem ser independentes e incluir guardas de inclusão.

## Requisitos de Design
- Evitar vazamentos de memória ao usar `new`.
- Garantir que as classes sigam a Forma Canônica Ortodoxa onde aplicável.
- Headers devem evitar a inclusão dupla usando include guards.

## Notas Adicionais
- Arquivos adicionais são permitidos para melhor organização do código.
- Ler cada módulo completamente antes de começar.
- Seguir as diretrizes e exemplos fornecidos.
- Usar editores de texto favoritos para facilitar a criação de múltiplas classes.
- Utilizar conceitos teóricos conforme necessário.
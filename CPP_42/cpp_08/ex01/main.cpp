#include "Span.hpp"

int main()
{
    // Teste 1: Adicionar números e verificar o shortest e longest span
    Span sp1(5);
    sp1.addNumber(1);
    sp1.addNumber(3);
    sp1.addNumber(6);
    sp1.addNumber(10);
    sp1.addNumber(20);
    std::cout << "Test 1 - Shortest Span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Test 1 - Longest Span: " << sp1.longestSpan() << std::endl;

    // Teste 2: Tentativa de adicionar mais números do que o permitido
    try {
        Span sp2(2);
        sp2.addNumber(5);
        sp2.addNumber(10);
        sp2.addNumber(15);
    } catch (const std::exception &e) {
        std::cout << "Test 2 - Exception: " << e.what() << std::endl;
    }

    // Teste 3: Span com apenas um número (deve lançar exceção)
    try {
        Span sp3(1);
        sp3.addNumber(42);
        std::cout << "Test 3 - Shortest Span: " << sp3.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Test 3 - Exception: " << e.what() << std::endl;
    }

    // Teste 4: Span vazio (deve lançar exceção)
    try {
        Span sp4(5);
        std::cout << "Test 4 - Shortest Span: " << sp4.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Test 4 - Exception: " << e.what() << std::endl;
    }

    // Teste 5: Adicionar 10.000 números e verificar spans
    Span sp5(10000);
    for (int i = 0; i < 10000; ++i) {
        sp5.addNumber(rand() % 100000);
    }

    std::cout << "Test 5 - Shortest Span: " << sp5.shortestSpan() << std::endl; // Verifica o shortest span
    std::cout << "Test 5 - Longest Span: " << sp5.longestSpan() << std::endl;   // Verifica o longest span

    return 0;
}
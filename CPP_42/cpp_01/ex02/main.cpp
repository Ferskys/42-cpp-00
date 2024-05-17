/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:55:15 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/17 12:55:19 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    // Variável de string inicializada
    std::string myString = "HI THIS IS BRAIN";

    // Ponteiro para a string
    std::string *stringPTR = &myString;

    // Referência para a string
    std::string &stringREF = myString;

    // Imprime os endereços de memória
    std::cout << "Memory address of myString: " << &myString << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    // Imprime os valores das strings
    std::cout << "Value of myString: " << myString << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
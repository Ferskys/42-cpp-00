/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:45:53 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/11 14:46:05 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "Please, enter a command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Invalid command. Please, try again." << std::endl;
    }
    return (0);
}
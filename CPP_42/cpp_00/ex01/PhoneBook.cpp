/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:12:35 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/11 14:44:47 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "PhoneBook constructor called!" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook destructor called!" << std::endl;
}

void PhoneBook::addContact(void)
{
    static int i;
    
    
    this->_contacts[i % 8].setContact();
    if (i < 8)
        this->_contactsCount++;
    else
        this->_contactsCount = 8;
    i++;
}

void PhoneBook::searchContact(void)
{
    int i;
    int index;

    if (this->_contactsCount == 0)
    {
        std::cout << "PhoneBook is empty. Please, add a contact to search." << std::endl;
        return ;
    }
    std::cout << "     index|first name| last name| nickname" << std::endl;
    i = 0;
    while (i < this->_contactsCount)
    {
        std::cout << std::setw(10) << i << "|";
        this->_contacts[i].printContact();
        i++;
    }
    std::cout << "Please, enter the index of the contact you want to see: ";
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= this->_contactsCount)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index. Please, try again." << std::endl;
        return ;
    }
    this->_contacts[index].printFullContact();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
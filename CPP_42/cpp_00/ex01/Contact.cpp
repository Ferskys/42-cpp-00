/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:21:33 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/11 14:48:03 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void _get_input(std::string &input)
{
    std::getline(std::cin, input);
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}

void Contact::setContact(void)
{
    std::cout << "Please, enter the first name: ";
    _get_input(this->_firstName);
    std::cout << "Please, enter the last name: ";
    _get_input(this->_lastName);
    std::cout << "Please, enter the nickname: ";
    _get_input(this->_nickname);
    std::cout << "Please, enter the phone number: ";
    _get_input(this->_phoneNumber);
    std::cout << "Please, enter the darkest secret: ";
    _get_input(this->_darkestSecret);
}

void Contact::printContact(void)
{
    std::cout << std::setw(10) << (this->_firstName.length() > 10 ? this->_firstName.substr(0, 9) + "." : this->_firstName) << "|";
    std::cout << std::setw(10) << (this->_lastName.length() > 10 ? this->_lastName.substr(0, 9) + "." : this->_lastName) << "|";
    std::cout << std::setw(10) << (this->_nickname.length() > 10 ? this->_nickname.substr(0, 9) + "." : this->_nickname) << std::endl;
}

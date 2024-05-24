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

void Contact::_get_input(std::string &input)
{
    std::getline(std::cin, input);
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}

int Contact::_isContactEmpty(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    return (first_name.empty() && last_name.empty() && nickname.empty() && phone_number.empty() && darkest_secret.empty());
}

void Contact::setContact(void)
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Please, enter the first name: ";
    _get_input(firstName);
    std::cout << "Please, enter the last name: ";
    _get_input(lastName);
    std::cout << "Please, enter the nickname: ";
    _get_input(nickname);
    std::cout << "Please, enter the phone number: ";
    _get_input(phoneNumber);
    std::cout << "Please, enter the darkest secret: ";
    _get_input(darkestSecret);

    if (!_isContactEmpty(firstName, lastName, nickname, phoneNumber, darkestSecret))
    {
        this->_firstName = firstName;
        this->_lastName = lastName;
        this->_nickname = nickname;
        this->_phoneNumber = phoneNumber;
        this->_darkestSecret = darkestSecret;
    }
    else
    {
        std::cout << "Contact is empty. Please, try again." << std::endl;
    }
}

void Contact::printContact(void)
{
    std::cout << std::setw(10) << (this->_firstName.length() > 10 ? this->_firstName.substr(0, 9) + "." : this->_firstName) << "|";
    std::cout << std::setw(10) << (this->_lastName.length() > 10 ? this->_lastName.substr(0, 9) + "." : this->_lastName) << "|";
    std::cout << std::setw(10) << (this->_nickname.length() > 10 ? this->_nickname.substr(0, 9) + "." : this->_nickname) << std::endl;
}

void Contact::printFullContact(void)
{
    std::cout << "First name: " << this->_firstName << std::endl;
    std::cout << "Last name: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phoneNumber << std::endl;
    std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

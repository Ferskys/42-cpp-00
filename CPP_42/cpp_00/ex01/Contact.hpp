/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:16:28 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/11 14:47:13 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <limits>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
        void _get_input(std::string &input);
        int _isContactEmpty(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
    public:
        Contact(void);
        ~Contact(void);
        void setContact(void);
        void printContact(void);
        void printFullContact(void);
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:12:42 by fsuomins          #+#    #+#             */
/*   Updated: 2024/05/11 14:45:35 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _contactsCount;
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void addContact(void);
        void searchContact(void);
};
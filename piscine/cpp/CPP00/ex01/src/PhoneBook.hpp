/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:59:36 by doriani           #+#    #+#             */
/*   Updated: 2023/11/27 22:17:49 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"
# define MAXCONTACTS 8

class PhoneBook
{
    private:
        Contact contacts[MAXCONTACTS];
        void swapContacts(Contact& a, Contact& b);
        void shiftContacts();
        void printContact(Contact contact, int idx);
        void printSeparator(std::string left, 
                            std::string mid,
                            std::string right);
        void printHeader();
        void displayContact();
    public:
        PhoneBook();
        void addContact();
        void searchContact();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:59:39 by doriani           #+#    #+#             */
/*   Updated: 2023/11/27 22:51:34 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook()
{
    for (int i = 0; i < MAXCONTACTS; i++)
        contacts[i] = Contact();
}

void PhoneBook::swapContacts(Contact& a, Contact& b)
{
    Contact& tmp = a;
    a = b;
    b = tmp;
}

void PhoneBook::shiftContacts()
{
    for (int i = 0; i < MAXCONTACTS - 1; i++)
        swapContacts(contacts[i], contacts[i+1]);
    contacts[MAXCONTACTS - 1] = Contact();
}

void PhoneBook::addContact()
{
    int i;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cin.ignore();
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter dakest secret: ";
    std::getline(std::cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickname.empty()
    ||  phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "One ore more fields are missing. "
                  << "Contact has not been added to Phonebook."
                  << std::endl;
        return ;
    }

    i = 0;
    while (i < MAXCONTACTS && contacts[i].getFirstName() != "")
        i++;
    if (i == MAXCONTACTS) {
        shiftContacts();
        i--;
    }
    contacts[i] = Contact(firstName, lastName, nickname,
                         phoneNumber, darkestSecret);
}

void PhoneBook::printSeparator(std::string left,
                               std::string mid,
                               std::string right)
{
    std::string separator;
    for (int i = 0; i < 10; i++)
        separator += "─";
    std::cout << left;
    std::cout << separator;
    std::cout << mid;
    std::cout << separator;
    std::cout << mid;
    std::cout << separator;
    std::cout << mid;
    std::cout << separator;
    std::cout << right << std::endl;
}

void PhoneBook::printHeader()
{
    std::cout << "│" << "  Index   " << "│" << "First Name" << "│"
              << "Last  Name" << "│" << " Nickname " << "│" << std::endl;
}

void PhoneBook::printContact(Contact contact, int idx)
{
    std::string firstName = contact.getFirstName();
    if (firstName.size() > 10)
        firstName = firstName.substr(0,9) + ".";
    std::string lastName = contact.getLastName();
    if (lastName.size() > 10)
        lastName = lastName.substr(0,9) + ".";
    std::string nickname = contact.getNickname();
    if (nickname.size() > 10)
        nickname = nickname.substr(0,9) + ".";

    std::cout << "│" << std::setw(10) << idx
              << "│" << std::setw(10) << firstName
              << "│" << std::setw(10) << lastName
              << "│" << std::setw(10) << nickname
              << "│" << std::endl;
}

void PhoneBook::searchContact()
{
    int i;

    i = 0;
    if (contacts[i].getFirstName().empty())
    {
        std::cout << "Phonebook is empty" << std::endl;
        return ;
    }
    printSeparator("┌", "┬", "┐");
    printHeader();
    printSeparator("├", "┼", "┤");
    while (i < MAXCONTACTS && !contacts[i].getFirstName().empty())
    {
        printContact(contacts[i], i);
        i++;
        if (i < MAXCONTACTS && !contacts[i].getFirstName().empty())
            printSeparator("├", "┼", "┤");
    }
    printSeparator("└", "┴", "┘");
    std::cout << std::endl;
    displayContact();
}

void PhoneBook::displayContact()
{
    std::string request;
    char        *p;
    long        idx;

    while (true) {
        std::cout << "Enter a contact index to display "
                  << "(\"Q\" to return to main menu): ";
        std::cin >> request;
        if (!request.compare("Q"))
            break ;
        idx = std::strtol(request.c_str(), &p, 10);
        if (*p || idx < 0 || idx >= MAXCONTACTS
            || contacts[idx].getFirstName().empty())
        {
            std::cout << "Bad request." << std::endl;
            continue ;
        }
        std::cout << "First name: "
                  << contacts[idx].getFirstName() << std::endl;
        std::cout << "Last name: "
                  << contacts[idx].getLastName() << std::endl;
        std::cout << "Nickname: "
                  << contacts[idx].getNickname() << std::endl;
        std::cout << "Phone number:: "
                  << contacts[idx].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: "
                  << contacts[idx].getSecret() << std::endl;
        std::cout << std::endl;
        break ;
    }
    return ;
}

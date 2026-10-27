/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:05:13 by doriani           #+#    #+#             */
/*   Updated: 2023/11/27 19:36:24 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
# include <iostream>

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to the Awesome PhoneBook!" << std::endl << std::endl;
    while (true)
    {
        std::cout << "Choose a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (!command.compare("ADD"))
            phoneBook.addContact();
        else if (!command.compare("SEARCH"))
            phoneBook.searchContact();
        else if (!command.compare("EXIT")){
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
            std::cout << "The command you entered is invalid." << std::endl;
    }
    return (0);
}

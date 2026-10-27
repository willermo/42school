/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:18:23 by doriani           #+#    #+#             */
/*   Updated: 2023/11/28 21:29:16 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main( void )
{
    std::string str("HI THIS IS BRAIN");
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "The memory address of the string variable is: "
              << &str
              << std::endl;
    std::cout << "The memory address held by stringPTR is: "
              << &stringPTR
              << std::endl;
    std::cout << "The memory address held by stringREF is: "
              << &stringREF
              << std::endl;
    std::cout << "The value of the string variable is: "
              << str
              << std::endl;
    std::cout << "The value pointed to by stringPTR is: "
              << *stringPTR
              << std::endl;
    std::cout << "The value pointed to by stringREF is: "
              << stringREF
              << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:21:04 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 16:11:58 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"

// static int testNumber = 0;

// static void
// testCase(std::string test, std::string expect) {
//     if (testNumber++)
//         std::cout << DARK_GREY_B << "\n---\n" << RESET << std::endl;
//     std::cout << BRIGHT_BLUE_B << "Test n. " << testNumber << RESET
//               << std::endl;
//     std::cout << BRIGHT_CYAN << "Testing : " << test << RESET << std::endl;
//     std::cout << CYAN << "Expected : " << expect << RESET << std::endl;
// }

int
main(void) {

    std::cout << BRIGHT_YELLOW_B << "\t### Intern test ###\n"
              << RESET << std::endl;
    Bureaucrat b1("Pippo", 1);
    std::cout << BLUE_B << "Bureaucrats list:\n" << RESET << std::endl;
    std::cout << BLUE << b1 << RESET << std::endl;
    Intern ffrau;
    std::cout << BRIGHT_BLUE_B << "Intern ffrau created" << RESET << std::endl;

    // creating forms
    std::cout << BRIGHT_BLUE_B << "Creating forms" << RESET << std::endl;
    // Intern ffrau creates "robotomy request" form
    std::cout << BRIGHT_BLUE_B
              << "Intern ffrau creates \"robotomy request\" form" << RESET
              << std::endl;
    AForm *f1 = ffrau.makeForm("robotomy request", "Valerio Pescetelli");
    // Intern ffrau creates "presidential pardon" form
    std::cout << BRIGHT_BLUE_B
              << "Intern ffrau creates \"presidential pardon\" form" << RESET
              << std::endl;
    AForm *f2 = ffrau.makeForm("presidential pardon", "Francesco Frau");
    // Intern ffrau creates "shrubbery creation" form
    std::cout << BRIGHT_BLUE_B
              << "Intern ffrau creates \"shrubbery creation\" form" << RESET
              << std::endl;
    AForm *f3 = ffrau.makeForm("shrubbery creation", "42");
    // Intern ffrau creates "nonexistent" form
    std::cout << BRIGHT_BLUE_B << "Intern ffrau creates \"nonexistent\" form"
              << RESET << std::endl;
    AForm *f4 = ffrau.makeForm("nonexistent", "42");

    // print forms
    std::cout << BRIGHT_BLUE_B << "Forms list:\n" << RESET << std::endl;
    std::cout << BRIGHT_BLUE << "f1: " << RESET << std::endl;
    if (f1)
        std::cout << *f1 << std::endl;
    else
        std::cout << "NULL" << std::endl;
    std::cout << BRIGHT_BLUE << "f2: " << RESET << std::endl;
    if (f2)
        std::cout << *f2 << std::endl;
    else
        std::cout << "NULL" << std::endl;
    std::cout << BRIGHT_BLUE << "f3: " << RESET << std::endl;
    if (f3)
        std::cout << *f3 << std::endl;
    else
        std::cout << "NULL" << std::endl;
    std::cout << BRIGHT_BLUE << "f4: " << RESET << std::endl;
    if (f4)
        std::cout << *f4 << std::endl;
    else
        std::cout << "NULL" << std::endl;

    // sign forms
    std::cout << BRIGHT_BLUE_B << "Signing forms" << RESET << std::endl;
    // Bureaucrat Pippo signs f1
    std::cout << BRIGHT_BLUE_B << "Bureaucrat Pippo signs f1" << RESET
              << std::endl;
    b1.signForm(*f1);
    // Bureaucrat Pippo signs f2
    std::cout << BRIGHT_BLUE_B << "Bureaucrat Pippo signs f2" << RESET
              << std::endl;
    b1.signForm(*f2);
    // Bureaucrat Pippo signs f3
    std::cout << BRIGHT_BLUE_B << "Bureaucrat Pippo signs f3" << RESET
              << std::endl;
    b1.signForm(*f3);

    // execute forms
    std::cout << BRIGHT_BLUE_B << "Executing forms" << RESET << std::endl;
    // Bureaucrat Pippo executes f1
    std::cout << BRIGHT_BLUE_B << "Bureaucrat Pippo executes f1" << RESET
              << std::endl;
    b1.executeForm(*f1);
    // Bureaucrat Pippo executes f2
    std::cout << BRIGHT_BLUE_B << "Bureaucrat Pippo executes f2" << RESET
              << std::endl;
    b1.executeForm(*f2);
    // Bureaucrat Pippo executes f3
    std::cout << BRIGHT_BLUE_B << "Bureaucrat Pippo executes f3" << RESET
              << std::endl;
    b1.executeForm(*f3);

    // print end test
    std::cout << BRIGHT_YELLOW_B << "\n\t### End of Intern test ###\n"
              << RESET << std::endl;

    // deleting forms
    std::cout << BRIGHT_BLUE_B << "Deleting forms" << RESET << std::endl;
    if (f1)
        delete f1;
    if (f2)
        delete f2;
    if (f3)
        delete f3;
    if (f4)
        delete f4;

    return 0;
}
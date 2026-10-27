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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"

static int testNumber = 0;

static void
testCase(std::string test, std::string expect) {
    if (testNumber++)
        std::cout << DARK_GREY_B << "\n---\n" << RESET << std::endl;
    std::cout << BRIGHT_BLUE_B << "Test n. " << testNumber << RESET
              << std::endl;
    std::cout << BRIGHT_CYAN << "Testing : " << test << RESET << std::endl;
    std::cout << CYAN << "Expected : " << expect << RESET << std::endl;
}

int
main(void) {

    std::cout << BRIGHT_YELLOW_B << "\t### Derived Form test ###\n"
              << RESET << std::endl;
    Bureaucrat b1("Pippo", 1);
    Bureaucrat b2("Pluto", 150);
    Bureaucrat b3("Paperino", 50);
    std::cout << BLUE_B << "Bureaucrats list:\n" << RESET << std::endl;
    std::cout << BLUE << b1 << b2 << b3 << RESET << std::endl;
    ShrubberyCreationForm s1("42");
    RobotomyRequestForm r1("Francesco Frau");
    PresidentialPardonForm p1("Valerio Pescetelli");
    ShrubberyCreationForm s2("Villa Borghese");
    std::cout << BRIGHT_BLUE_B << "Forms list:\n" << RESET << std::endl;
    std::cout << BRIGHT_BLUE << s1 << std::endl
              << r1 << std::endl
              << p1 << std::endl
              << s2 << std::endl
              << RESET << std::endl;

    std::cout << BRIGHT_BLUE_B << "Forms signing test:\n" << RESET << std::endl;
    // test 1 - b2 signs s1
    testCase("b2 signs s1", "Sign failure");
    try {
        b2.signForm(s1);
        std::cout << s1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 2 - b1 signs s1
    testCase("b1 signs s1", "Sign success");
    try {
        b1.signForm(s1);
        std::cout << s1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 3 - b1 signs r1
    testCase("b1 signs r1", "Sign success");
    try {
        b1.signForm(r1);
        std::cout << r1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 4 - b1 signs p1
    testCase("b1 signs p1", "Sign success");
    try {
        b1.signForm(p1);
        std::cout << p1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // print current forms status
    std::cout << BRIGHT_BLUE_B << "Forms status:\n" << RESET << std::endl;
    std::cout << BRIGHT_BLUE << s1 << std::endl
              << r1 << std::endl
              << p1 << std::endl
              << s2 << std::endl
              << RESET << std::endl;

    std::cout << BRIGHT_BLUE_B << "Forms execution test:\n"
              << RESET << std::endl;

    // test 5 - b3 executes s1
    testCase("b3 executes s1", "Execution success");
    try {
        s1.execute(b3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 6 - b3 executes r1
    testCase("b3 executes r1", "Execution failure");
    try {
        r1.execute(b3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 7 - b1 executes r1
    testCase("b1 executes r1", "Execution success");
    try {
        r1.execute(b1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 8 - b1 executes p1
    testCase("b1 executes p1", "Execution success");
    try {
        p1.execute(b1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 9 - b1 executes s2
    testCase("b1 executes s2", "Execution failure (not signed exception)");
    try {
        s2.execute(b1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << PURPLE_B << "b1 signs s2" << RESET << std::endl;
    b1.signForm(s2);

    // print current forms status
    std::cout << BRIGHT_BLUE_B << "Forms status:\n" << RESET << std::endl;
    std::cout << BRIGHT_BLUE << s1 << std::endl
              << r1 << std::endl
              << p1 << std::endl
              << s2 << std::endl
              << RESET << std::endl;

    // test 10 - b1 executes s2
    testCase("b1 executes s2", "Execution success");
    try {
        s2.execute(b1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // testing RobotomyRequestForm randomness
    std::cout << BRIGHT_BLUE_B << "RobotomyRequestForm randomness test:\n"
              << RESET << std::endl;

    // test 10 - executing r1 10 times
    for (int i = 0; i < 10; i++) {
        std::cout << BRIGHT_BLUE << "Execution n. " << i + 1 << RESET
                  << std::endl;
        try {
            r1.execute(b1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    // print end test
    std::cout << BRIGHT_YELLOW_B << "\n\t### End of Derived Form test ###\n"
              << RESET << std::endl;

    return 0;
}
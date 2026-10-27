/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:21:04 by doriani           #+#    #+#             */
/*   Updated: 2024/02/28 09:44:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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

    std::cout << BRIGHT_YELLOW_B << "\t### Bureaucrat test ###\n"
              << RESET << std::endl;
    // test 1
    testCase("Bureaucrat b1;", "Youdontknowme, bureaucrat grade 150");
    try {
        Bureaucrat b1;
        std::cout << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 2
    testCase("Bureaucrat b2(\"Pippo\", 1)", "Pippo, bureaucrat grade 1");
    try {
        Bureaucrat b2("Pippo", 1);
        std::cout << b2 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 3
    testCase("Bureaucrat b3(\"Pluto\", 0)", "Grade too high");
    try {
        Bureaucrat b3("Pluto", 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 4
    testCase("Bureaucrat b4(\"Paperino\", 151)", "Grade too low");
    try {
        Bureaucrat b4("paperino", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 5
    testCase("Bureaucrat test(\"Test\", 150)", "Test, bureaucrat grade 150");
    Bureaucrat test("Test", 150);
    std::cout << test << std::endl;

    // test 6
    testCase("test.incrementGrade()", "Test, bureaucrat grade 149");
    try {
        test.incrementGrade();
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 7
    testCase("test.decrementGrade()", "Test, bureaucrat grade 150");
    try {
        test.decrementGrade();
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 8
    testCase("test.decreementGrade()", "Grade too low");
    try {
        test.decrementGrade(150);
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 9
    testCase("test.incrementGrade()", "Test, bureaucrat grade 149");
    try {
        test.incrementGrade(1);
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 10
    testCase("test.incrementGrade(148)", "Test, bureaucrat grade 1");
    try {
        test.incrementGrade(148);
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 11
    testCase("test.incrementGrade(1)", "Grade too high");
    try {
        test.incrementGrade(1);
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 12
    testCase("test.decrementGrade(1)", "Test, bureaucrat grade 2");
    try {
        test.decrementGrade(1);
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 13
    testCase("test.decrementGrade(200)", "Grade too low");
    try {
        test.decrementGrade(200);
        std::cout << test << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
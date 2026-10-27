/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:21:04 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:24:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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

    std::cout << BRIGHT_YELLOW_B << "\t### Form test ###\n"
              << RESET << std::endl;
    Bureaucrat b1("Pippo", 1);
    Bureaucrat b2("Pluto", 150);
    Bureaucrat b3("Paperino", 40);
    std::cout << BLUE_B << "Bureaucrats list:\n" << RESET << std::endl;
    std::cout << BLUE << b1 << b2 << b3 << RESET << std::endl;
    // test 1
    testCase("Basic form creation without parameters (defaults to \"Form\", "
             "150, 150)",
             "\nForm Form is not signed.\nGrade required to sign: 150\nGrade "
             "required to execute: 150");
    try {
        Form f0;
        std::cout << f0 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 2
    testCase("Form creation with parameters (\"Form1\", 1, 1)",
             "\nForm Form1 is not signed.\nGrade required to sign: 1\nGrade "
             "required to execute: 1");
    try {
        Form f1("Form1", 1, 1);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 3
    testCase("Form creation with too high grade parameters (\"Form1\", 0, 0)",
             "Grade too high");
    try {
        Form f2("Form2", 0, 0);
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 4
    testCase(
        "Form creation with too low grade parameters (\"Form1\", 151, 151)",
        "Grade too low");
    try {
        Form f3("Form3", 151, 151);
        std::cout << f3 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 5  - Form copy constructor
    testCase("Form copy constructor", "\nForm CopiedForm is not signed.\nGrade "
                                      "required to sign: 1\nGrade required to "
                                      "execute: 1");
    try {
        Form copied_form("CopiedForm", 1, 1);
        Form f4(copied_form);
        std::cout << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 6 - Form assignment operator
    testCase("Form assignment operator", "\nForm AssignedForm is not signed.\n"
                                         "Grade required to sign: 1\nGrade "
                                         "required to execute: 1");
    try {
        Form assigned_form("AssignedForm", 1, 1);
        Form f5 = assigned_form;
        std::cout << f5 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 7 - Get form name
    testCase("Get form name", "Form6");
    try {
        Form f6("Form6", 1, 1);
        std::cout << f6.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 8 - Get form signed status
    testCase("Get form signed status", "Form7 is not signed.");
    try {
        Form f7("Form7", 1, 1);
        std::cout << f7.getName() << " is "
                  << (f7.getSigned() ? "signed." : "not signed.") << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 9 - Get form grade to sign
    testCase("Get form grade to sign", "1");
    try {
        Form f8("Form8", 1, 1);
        std::cout << f8.getGradeToSign() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 10 - Get form grade to execute
    testCase("Get form grade to execute", "1");
    try {
        Form f9("Form9", 1, 1);
        std::cout << f9.getGradeToExecute() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 11 - Sign form
    testCase("Sign form", "Form10 is signed.\nGrade required to sign: 1\nGrade "
                          "required to execute: 1");
    try {
        Form f10("Form10", 1, 1);
        f10.beSigned(b1);
        std::cout << f10 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 12 - Sign form with too low grade
    testCase("Sign form with too low grade", "Grade too low");
    try {
        Form f11("Form11", 1, 1);
        f11.beSigned(b2);
        std::cout << f11 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 13 - Bureaucrat sign form
    testCase("Bureaucrat sign form",
             "Pippo signed Form12 (followed by form info)");
    try {
        Form f12("Form12", 1, 1);
        b1.signForm(f12);
        std::cout << f12 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // test 14 - Bureaucrat sign form with too low grade
    testCase("Bureaucrat sign form with too low grade",
             "Paperino couldn't "
             "sign Form13 because Grade "
             "too low");
    try {
        Form f13("Form13", 1, 1);
        b3.signForm(f13);
        std::cout << f13 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
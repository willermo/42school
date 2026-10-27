/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:37:26 by doriani           #+#    #+#             */
/*   Updated: 2024/03/23 10:44:24 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "colors.hpp"
#include <iostream>

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
main() {
    std::cout << BRIGHT_YELLOW_B << "\t### MutantStack test ###\n"
              << RESET << std::endl;

    // setting up the test
    std::cout << BLUE_B << "Setting up the test" << RESET << std::endl;
    // creating a MutantStack<int> 'ms' and pushing some values into the stack
    std::cout << BLUE
              << "Creating a MutantStack<int> 'ms' of 4 elements (1, 2, 42, 18)"
              << RESET << std::endl;
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(42);
    ms.push(18);
    std::cout << "ms: " << ms << std::endl;

    // starting tests
    std::cout << BRIGHT_YELLOW_B << "Starting tests" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1 - copying the MutantStack<int> 'ms' into a MutantStack<int> 'ms2'
    testCase("MutantStack<int> ms2 = ms;",
             "MutantStack<int> ms2 should be a copy of MutantStack<int> ms");
    MutantStack<int> ms2 = ms;
    // outputting the stacks 'ms' and 'ms2'
    std::cout << "ms: " << ms << std::endl;
    std::cout << "ms2: " << ms2 << std::endl;

    // Test 2 - getting the top element of the stack 'ms2'
    testCase("s2.top()", "18");
    std::cout << "ms2: " << ms2 << std::endl;
    std::cout << "Top element of MutantStack<int> s2: " << ms2.top()
              << std::endl;

    // Test 3 - checking if the stack 'ms2' is empty
    testCase("s2.empty()", "false");
    std::cout << "ms2: " << ms2 << std::endl;
    std::cout << "Is MutantStack<int> s2 empty? "
              << (ms2.empty() ? "true" : "false") << std::endl;

    // Test 4 - popping an element from the stack 'ms2'
    testCase("ms2.pop()", "Should pop the top element from the stack 'ms2'");
    std::cout << "ms2 before pop()" << ms2 << std::endl;
    ms2.pop();
    std::cout << "ms2 after pop()" << ms2 << std::endl;

    // Test 5 - clearing the stack 'ms2'
    testCase("Clearing 'ms2'", "ms2 should be empty");
    ms2.clear();
    std::cout << "ms2: " << ms2 << std::endl;

    // Test 6 - checking if the MutantStack<int> 'ms2' is empty
    testCase("ms2.empty()", "true");
    std::cout << "ms2: " << ms2 << std::endl;
    std::cout << "Is ms2 empty? " << (ms2.empty() ? "true" : "false")
              << std::endl;

    // Test 7 - pushing an element into the stack 'ms2'
    testCase("ms2.push(42)", "Should push 42 into the stack 'ms2'");
    std::cout << "ms2 before push(42): " << ms2 << std::endl;
    ms2.push(42);
    std::cout << "ms2 after push(42): " << ms2 << std::endl;

    // Test 8 - Creating a std::stack<int> 's' from copy constructor of
    // 'ms2'
    testCase("std::stack<int> s(ms2)",
             "Should create a std::stack<int> 's' from copy constructor of "
             "'ms2'");
    std::stack<int> s(ms2);
    std::cout << "s: ";
    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
        if (!s.empty())
            std::cout << " -> ";
    }

    std::cout << std::endl;
    std::cout << BRIGHT_YELLOW_B << "\t### Testing completed ###\n"
              << RESET << std::endl;
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:38:38 by doriani           #+#    #+#             */
/*   Updated: 2024/03/22 10:03:44 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

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
    std::cout << BRIGHT_YELLOW_B << "\t### easyfind test ###\n"
              << RESET << std::endl;
    std::cout << BLUE_B << "Defining vector 'vec' from array {1, 2, 3, 4, 5}"
              << RESET << std::endl;
    int arr1[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    std::cout << BLUE_B << "Defining list 'lst' from array {10, 20, 30, 40, 50}"
              << RESET << std::endl;
    int arr2[] = {10, 20, 30, 40, 50};
    std::list<int> lst(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    std::cout << std::endl;
    std::cout << BRIGHT_YELLOW_B << "### Testing easyfind with vector ###\n"
              << RESET << std::endl;
    // test 1
    testCase("easyfind(vec, 3)", "Found value 3 in vector");
    try {
        int vecVal = easyfind(vec, 3);
        std::cout << "Found value " << vecVal << " in vector" << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    // Test 2
    testCase("easyfind(vec, 6)", "Value not found");
    try {
        int vecVal = easyfind(vec, 6);
        std::cout << "Found value " << vecVal << " in vector" << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << BRIGHT_YELLOW_B << "### Testing easyfind with list ###\n"
              << RESET << std::endl;
    // Test 3
    testCase("easyfind(lst, 20)", "Found value 20 in list");
    try {
        int lstVal = easyfind(lst, 20);
        std::cout << "Found value " << lstVal << " in list" << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    // Test 4
    testCase("easyfind(lst, 60)", "Value not found");
    try {
        int lstVal = easyfind(lst, 60);
        std::cout << "Found value " << lstVal << " in list" << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << BRIGHT_YELLOW_B << "\t### Testing completed ###\n"
              << RESET << std::endl;
    return 0;
}
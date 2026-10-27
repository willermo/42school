/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:37:26 by doriani           #+#    #+#             */
/*   Updated: 2024/03/22 12:37:13 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
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
    std::cout << BRIGHT_YELLOW_B << "\t### Span test ###\n"
              << RESET << std::endl;
    std::cout << std::endl;
    // setting up the test
    std::cout << BLUE_B << "Setting up the test" << RESET << std::endl;
    // seeding random number generator
    std::cout << BLUE << "Seeding random number generator" << RESET
              << std::endl;
    srand(time(NULL));
    // creating a vector of 12 random numbers 'vec_small'
    std::cout
        << BLUE
        << "Creating a vector of 12 random numbers ('vec_small') ranging from "
           "-RAND_MAX and RAND_MAX"
        << RESET << std::endl;
    std::vector<int> vec_small;
    for (int i = 0; i < 12; i++) {
        vec_small.push_back(rand() * (rand() % 2 == 0 ? 1 : -1));
    }
    // creating a vector of 50.000 random numbers 'vec_big'
    std::cout << BLUE
              << "Creating a vector of 50.000 random numbers ('vec_big') "
                 "ranging from "
                 "-RAND_MAX and RAND_MAX"
              << RESET << std::endl;
    std::vector<int> vec_big;
    for (int i = 0; i < 50000; i++) {
        vec_big.push_back(rand() * (rand() % 2 == 0 ? 1 : -1));
    }
    // creating the Span object 'span' for the subject test with a size of 5
    std::cout << BLUE
              << "Creating a Span object 'span' with a size of 5 for the "
                 "subject test"
              << RESET << std::endl;
    Span span(5);
    // creating a Span object 'span_small' with a size of 10 and adding
    // vec_small to it
    std::cout << BLUE << "Creating a Span object 'span_small' with a size of 10"
              << RESET << std::endl;
    Span span_small(10);
    // creating a Span object 'span_big' with a size of 49995
    std::cout << BLUE
              << "Creating a Span object 'span_big' with a size of 49995"
              << RESET << std::endl;
    Span span_big(49995);
    // creating a Span object 'span_biggest' with a size of 50000
    std::cout << BLUE
              << "Creating a Span object 'span_biggest' with a size of 50000"
              << RESET << std::endl;
    Span span_biggest(50000);
    // creating a Span object 'span_42' with a size of 10 and adding 42 to it
    std::cout
        << BLUE
        << "Creating a Span object 'span_42' with a size of 10 and adding 42 "
           "to it"
        << RESET << std::endl;
    Span span_42(10);
    // creating a Span object 'span_empty' with a size of 5
    std::cout << BLUE
              << "Creating a Span object 'span_empty' with a size of 5 with "
                 "no numbers added to it"
              << RESET << std::endl;
    Span span_empty(5);
    std::cout << std::endl;
    // starting tests
    std::cout << BRIGHT_YELLOW_B << "Starting tests" << RESET << std::endl;
    std::cout << std::endl;
    // testing array fillings
    std::cout << BLUE_B << "Testing array fillings" << RESET << std::endl;
    // test 1 - filling 'span' with values defined in subject
    testCase("filling 'span' with values defined in subject",
             "no errors raised");
    try {
        span.addNumber(6);
        span.addNumber(3);
        span.addNumber(17);
        span.addNumber(9);
        span.addNumber(11);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 2 - filling 'span_small' with vec_small
    testCase("filling 'span_small' with vec_small",
             "Should raise error for the last 2 values");
    for (std::vector<int>::iterator it = vec_small.begin();
         it != vec_small.end(); it++) {
        try {
            span_small.addNumber(*it);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    // test 3 - filling 'span_big' with vec_big
    testCase(
        "filling 'span_big' with vec_big using range of iterators",
        "Should raise error as soon as the span is full, giving notice that "
        "the operation was rejected on standard error output");
    try {
        span_big.addNumber(vec_big.begin(), vec_big.end());
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 4 - filling 'span_biggest' with vec_big
    testCase("filling 'span_biggest' with vec_big using range of iterators",
             "Should raise no errors");
    try {
        span_biggest.addNumber(vec_big.begin(), vec_big.end());
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 5 - filling 'span_42' with 42
    testCase("filling 'span_42' with 42", "Should raise no errors");
    try {
        span_42.addNumber(42);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 6 - finding shortest span in 'span'
    testCase("finding shortest span in 'span'", "Should return 2");
    try {
        std::cout << "Shortest span in 'span' is: " << span.shortestSpan()
                  << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 7 - finding longest span in 'span'
    testCase("finding longest span in 'span'", "Should return 14");
    try {
        std::cout << "Longest span in 'span' is: " << span.longestSpan()
                  << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 8 - finding shortest span in 'span_small'
    testCase("finding shortest span in 'span_small'",
             "<can't predict as span_small is randomly generated>");
    try {
        std::cout << "Shortest span in 'span_small' is: "
                  << span_small.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 9 - finding longest span in 'span_small'
    testCase("finding longest span in 'span_small'",
             "<can't predict as span_small is randomly generated>");
    try {
        std::cout << "Longest span in 'span_small' is: "
                  << span_small.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 10 - finding shortest span in 'span_big'
    testCase(
        "finding shortest span in 'span_big'",
        "Should raise an error because  the span filling process was rejected");
    try {
        std::cout << "Shortest span in 'span_big' is: "
                  << span_big.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 11 - finding longest span in 'span_big'
    testCase(
        "finding longest span in 'span_big'",
        "Should raise an error because  the span filling process was rejected");
    try {
        std::cout << "Longest span in 'span_big' is: " << span_big.longestSpan()
                  << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 12 - finding shortest span in 'span_biggest'
    testCase("finding shortest span in 'span_biggest'",
             "<can't predict as span_biggest is randomly generated>");
    try {
        std::cout << "Shortest span in 'span_biggest' is: "
                  << span_biggest.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 13 - finding longest span in 'span_biggest'
    testCase("finding longest span in 'span_biggest'",
             "<can't predict as span_biggest is randomly generated>");
    try {
        std::cout << "Longest span in 'span_biggest' is: "
                  << span_biggest.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 14 - finding shortest span in 'span_42'
    testCase("finding shortest span in 'span_42'",
             "Should raise an error as there is only one number in the span");
    try {
        std::cout << "Shortest span in 'span_42' is: " << span_42.shortestSpan()
                  << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 15 - finding longest span in 'span_42'
    testCase("finding longest span in 'span_42'",
             "Should raise an error as there is only one number in the span");
    try {
        std::cout << "Longest span in 'span_42' is: " << span_42.longestSpan()
                  << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 16 - finding shortest span in 'span_empty'
    testCase("finding shortest span in 'span_empty'",
             "Should raise an error as there are no numbers in the span");
    try {
        std::cout << "Shortest span in 'span_empty' is: "
                  << span_empty.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // test 17 - finding longest span in 'span_empty'
    testCase("finding longest span in 'span_empty'",
             "Should raise an error as there are no numbers in the span");
    try {
        std::cout << "Longest span in 'span_empty' is: "
                  << span_empty.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << BRIGHT_YELLOW_B << "\t### Testing completed ###\n"
              << RESET << std::endl;
    return 0;
}
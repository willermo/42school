/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:09:56 by doriani           #+#    #+#             */
/*   Updated: 2024/07/23 16:14:07 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "iter.hpp"
#include <iostream>

template <typename T>
void
print(T &x) {
    std::cout << x << std::endl;
}
template <typename T>
void
print(const T &x) {
    std::cout << x << std::endl;
}

template <typename T>
void
increment(T &x) {
    x++;
}

template <typename T>
void
toUpper(T &x) {
    if (x >= 'a' && x <= 'z')
        x -= 32;
}

int
main() {
    std::cout << BLUE_B << "\t### Iter test ###" << RESET << std::endl;
    std::cout << BLUE << "Defining int array: int arr[] = {1, 2, 3, 4, 5}"
              << RESET << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << BLUE << "Executing print function" << RESET << std::endl;
    iter(arr, 5, print);
    std::cout << std::endl;
    std::cout << BLUE << "Executing increment function" << RESET << std::endl;
    iter(arr, 5, increment);
    iter(arr, 5, print);
    std::cout << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << BLUE
              << "Defining char array: char arr[] = {'a', 'b', 'c', 'd', 'e'}"
              << RESET << std::endl;
    char arr2[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << BLUE << "Executing print function" << RESET << std::endl;
    iter(arr2, 5, print);
    std::cout << std::endl;
    std::cout << BLUE << "Executing increment function" << RESET << std::endl;
    iter(arr2, 5, increment);
    iter(arr2, 5, print);
    std::cout << std::endl;
    std::cout << BLUE << "Executing toUpper function" << RESET << std::endl;
    iter(arr2, 5, toUpper);
    iter(arr2, 5, print);
    std::cout << std::endl << std::endl;
    std::cout
        << BLUE
        << "Defining string array: std::string arr[] = {\"one\", \"two\", "
           "\"three\", \"four\", \"five\"}"
        << RESET << std::endl;
    std::string arr3[] = {"one", "two", "three", "four", "five"};
    std::cout << BLUE << "Executing print function" << RESET << std::endl;
    iter(arr3, 5, print);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << BLUE
              << "Defining float array: float arr[] = {1.1, 2.2, 3.3, 4.4, "
                 "5.5}"
              << RESET << std::endl;
    float arr4[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << BLUE << "Executing print function" << RESET << std::endl;
    iter(arr4, 5, print);
    std::cout << std::endl;
    std::cout << BLUE << "Executing increment function" << RESET << std::endl;
    iter(arr4, 5, increment);
    iter(arr4, 5, print);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout
        << BLUE
        << "Defining double array: double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5}"
        << RESET << std::endl;
    double arr5[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << BLUE << "Executing print function" << RESET << std::endl;
    iter(arr5, 5, print);
    std::cout << std::endl;
    std::cout << BLUE << "Executing increment function" << RESET << std::endl;
    iter(arr5, 5, increment);
    iter(arr5, 5, print);
    std::cout << std::endl;
    std::cout << BLUE_B << "End of test" << RESET << std::endl;
    return 0;
}
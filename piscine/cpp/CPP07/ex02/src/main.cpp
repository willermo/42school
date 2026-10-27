/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:55:13 by doriani           #+#    #+#             */
/*   Updated: 2024/03/20 16:55:06 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "colors.hpp"
#include <iostream>
#define SIZE 5

int
main() {
    std::cout << BLUE_B << "\t### ARRAY TEST ###" << RESET << std::endl;
    std::cout << std::endl;
    std::cout << BLUE_B << "Setup" << RESET << std::endl;
    std::cout << BLUE << "SIZE is defined to value: " << SIZE << RESET
              << std::endl;
    std::cout << BLUE << "Creating int array: Array<int> int_array(SIZE)"
              << RESET << std::endl;
    Array<int> int_array(SIZE);
    std::cout << BLUE << "Creating float array: Array<float> float_array(SIZE)"
              << RESET << std::endl;
    Array<float> float_array(SIZE);
    std::cout << BLUE << "Creating char array: Array<char> char_array(SIZE)"
              << RESET << std::endl;
    Array<char> char_array(SIZE);
    std::cout << std::endl;

    std::cout << BLUE_B << "Printing arrays" << RESET << std::endl;
    std::cout << BLUE << "int_array: " << RESET;
    for (unsigned int i = 0; i < int_array.size(); i++) {
        std::cout << int_array[i];
        i < int_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "float_array: " << RESET;
    for (unsigned int i = 0; i < float_array.size(); i++) {
        std::cout << float_array[i];
        i < float_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "char_array: " << RESET;
    for (unsigned int i = 0; i < char_array.size(); i++) {
        std::cout << char_array[i];
        i < char_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << BLUE_B << "Filling arrays" << RESET << std::endl;
    std::cout << BLUE << "Filling int_array" << RESET << std::endl;
    for (unsigned int i = 0; i < int_array.size(); i++) {
        int_array[i] = i;
    }
    std::cout << BLUE << "Filling float_array" << RESET << std::endl;
    for (unsigned int i = 0; i < float_array.size(); i++) {
        float_array[i] = i * 1.15;
    }
    std::cout << BLUE << "Filling char_array" << RESET << std::endl;
    for (unsigned int i = 0; i < char_array.size(); i++) {
        char_array[i] = i + 'a';
    }
    std::cout << std::endl;

    std::cout << BLUE_B << "Printing arrays" << RESET << std::endl;
    std::cout << BLUE << "int_array: " << RESET;
    for (unsigned int i = 0; i < int_array.size(); i++) {
        std::cout << int_array[i];
        i < int_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "float_array: " << RESET;
    for (unsigned int i = 0; i < float_array.size(); i++) {
        std::cout << float_array[i];
        i < float_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "char_array: " << RESET;
    for (unsigned int i = 0; i < char_array.size(); i++) {
        std::cout << char_array[i];
        i < char_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << BLUE_B << "Testing array copy" << RESET << std::endl;
    std::cout << BLUE << "Creating int_array2: Array<int> int_array2(int_array)"
              << RESET << std::endl;
    Array<int> int_array2(int_array);
    std::cout << BLUE
              << "Creating float_array2: Array<float> float_array2(float_array)"
              << RESET << std::endl;
    Array<float> float_array2(float_array);
    std::cout << BLUE
              << "Creating char_array2: Array<char> char_array2(char_array)"
              << RESET << std::endl;
    Array<char> char_array2(char_array);
    std::cout << std::endl;

    std::cout << BLUE_B << "Printing arrays" << RESET << std::endl;
    std::cout << BLUE << "int_array: " << RESET;
    for (unsigned int i = 0; i < int_array.size(); i++) {
        std::cout << int_array[i];
        i < int_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "float_array: " << RESET;
    for (unsigned int i = 0; i < float_array.size(); i++) {
        std::cout << float_array[i];
        i < float_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "char_array: " << RESET;
    for (unsigned int i = 0; i < char_array.size(); i++) {
        std::cout << char_array[i];
        i < char_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "int_array2: " << RESET;
    for (unsigned int i = 0; i < int_array2.size(); i++) {
        std::cout << int_array2[i];
        i < int_array2.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "float_array2: " << RESET;
    for (unsigned int i = 0; i < float_array2.size(); i++) {
        std::cout << float_array2[i];
        i < float_array2.size() - 1 ? std::cout << ", "
                                    : std::cout << std::endl;
    }
    std::cout << BLUE << "char_array2: " << RESET;
    for (unsigned int i = 0; i < char_array2.size(); i++) {
        std::cout << char_array2[i];
        i < char_array2.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << BLUE_B << "Testing array assignment" << RESET << std::endl;
    std::cout << BLUE
              << "Creating int_array3: Array<int> int_array3 = int_array"
              << RESET << std::endl;
    Array<int> int_array3 = int_array;
    std::cout
        << BLUE
        << "Creating float_array3: Array<float> float_array3 = float_array"
        << RESET << std::endl;
    Array<float> float_array3 = float_array;
    std::cout << BLUE
              << "Creating char_array3: Array<char> char_array3 = char_array"
              << RESET << std::endl;
    Array<char> char_array3 = char_array;
    std::cout << std::endl;

    std::cout << BLUE_B << "Printing arrays" << RESET << std::endl;
    std::cout << BLUE << "int_array: " << RESET;
    for (unsigned int i = 0; i < int_array.size(); i++) {
        std::cout << int_array[i];
        i < int_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "float_array: " << RESET;
    for (unsigned int i = 0; i < float_array.size(); i++) {
        std::cout << float_array[i];
        i < float_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "char_array: " << RESET;
    for (unsigned int i = 0; i < char_array.size(); i++) {
        std::cout << char_array[i];
        i < char_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "int_array3: " << RESET;
    for (unsigned int i = 0; i < int_array3.size(); i++) {
        std::cout << int_array3[i];
        i < int_array3.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "float_array3: " << RESET;
    for (unsigned int i = 0; i < float_array3.size(); i++) {
        std::cout << float_array3[i];
        i < float_array3.size() - 1 ? std::cout << ", "
                                    : std::cout << std::endl;
    }
    std::cout << BLUE << "char_array3: " << RESET;
    for (unsigned int i = 0; i < char_array3.size(); i++) {
        std::cout << char_array3[i];
        i < char_array3.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << BLUE_B << "Modifying arrays (set 2 and set 3)" << RESET
              << std::endl;
    std::cout << BLUE << "Setting int_array2[0] = 42" << RESET << std::endl;
    int_array2[0] = 42;
    std::cout << BLUE << "Setting int_array3[1] = 21" << RESET << std::endl;
    int_array3[1] = 21;
    std::cout << BLUE << "Setting float_array2[0] = 42.42" << RESET
              << std::endl;
    float_array2[0] = 42.42;
    std::cout << BLUE << "Setting float_array3[1] = 21.21" << RESET
              << std::endl;
    float_array3[1] = 21.21;
    std::cout << BLUE << "Setting char_array2[0] = 'z'" << RESET << std::endl;
    char_array2[0] = 'z';
    std::cout << BLUE << "Setting char_array3[1] = 'y'" << RESET << std::endl;
    char_array3[1] = 'y';
    std::cout << std::endl;

    std::cout << BLUE_B << "Printing arrays" << RESET << std::endl;
    std::cout << BLUE << "int_array: " << RESET;
    for (unsigned int i = 0; i < int_array.size(); i++) {
        std::cout << int_array[i];
        i < int_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "float_array: " << RESET;
    for (unsigned int i = 0; i < float_array.size(); i++) {
        std::cout << float_array[i];
        i < float_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "char_array: " << RESET;
    for (unsigned int i = 0; i < char_array.size(); i++) {
        std::cout << char_array[i];
        i < char_array.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "int_array2: " << RESET;
    for (unsigned int i = 0; i < int_array2.size(); i++) {
        std::cout << int_array2[i];
        i < int_array2.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "float_array2: " << RESET;
    for (unsigned int i = 0; i < float_array2.size(); i++) {
        std::cout << float_array2[i];
        i < float_array2.size() - 1 ? std::cout << ", "
                                    : std::cout << std::endl;
    }
    std::cout << BLUE << "char_array2: " << RESET;
    for (unsigned int i = 0; i < char_array2.size(); i++) {
        std::cout << char_array2[i];
        i < char_array2.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "int_array3: " << RESET;
    for (unsigned int i = 0; i < int_array3.size(); i++) {
        std::cout << int_array3[i];
        i < int_array3.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << BLUE << "float_array3: " << RESET;
    for (unsigned int i = 0; i < float_array3.size(); i++) {
        std::cout << float_array3[i];
        i < float_array3.size() - 1 ? std::cout << ", "
                                    : std::cout << std::endl;
    }
    std::cout << BLUE << "char_array3: " << RESET;
    for (unsigned int i = 0; i < char_array3.size(); i++) {
        std::cout << char_array3[i];
        i < char_array3.size() - 1 ? std::cout << ", " : std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << BLUE_B << "Testing out of range: int_array[5] = 42" << RESET
              << std::endl;
    try {
        int_array[5] = 42;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << BLUE_B << "END OF TEST" << RESET << std::endl;

    return 0;
}
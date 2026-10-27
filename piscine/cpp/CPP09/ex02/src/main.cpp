/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 07:25:07 by doriani           #+#    #+#             */
/*   Updated: 2024/07/23 10:17:12 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>

int
main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe [number1] [number2] ... [numberN]"
                  << std::endl;
        return 1;
    }

    PmergeMe vector_sorter, deque_sorter;
    std::clock_t start, end;
    double elapsed_time;
    try {
        vector_sorter.storeSequenceVector(argv + 1);
        deque_sorter.storeSequenceDeque(argv + 1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << "## Sorting elemnts using vector container ##" << std::endl;
    std::cout << "Before: ";
    vector_sorter.displayElementsVector();
    std::cout << "After: ";
    try {
        start = std::clock();
        vector_sorter.sortAndDisplayVector();
        end = std::clock();
        elapsed_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of: " << argc - 1
                  << " elements with std::vector : " << elapsed_time << " us"
                  << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << std::endl;
    std::cout << "## Sorting elemnts using deque container ##" << std::endl;
    std::cout << "Before: ";
    deque_sorter.displayElementsDeque();
    std::cout << "After: ";
    try {
        start = std::clock();
        deque_sorter.sortAndDisplayDeque();
        end = std::clock();
        elapsed_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of: " << argc - 1
                  << " elements with std::deque : " << elapsed_time << " us"
                  << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
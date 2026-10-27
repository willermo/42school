/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:08:44 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 17:37:44 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int
main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

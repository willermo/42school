/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:57:29 by doriani           #+#    #+#             */
/*   Updated: 2024/03/24 06:43:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int
main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./rpn \"<expression in reverse polish notation>\""
                  << std::endl;
        return 1;
    }
    RPN rpn;
    std::string expression(argv[1]);
    try {
        rpn.calculate(expression);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
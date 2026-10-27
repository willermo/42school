/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:45:50 by doriani           #+#    #+#             */
/*   Updated: 2023/11/30 02:06:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int
usage() {
    std::cout << "Usage: ./harlFilter <level> (DEBUG, INFO, WARNING, ERROR)"
              << std::endl;
    return 1;
}

int
main(int argc, char *argv[]) {

    if (argc != 2)
        return usage();

    std::string complainLevel = argv[1];
    Harl harl;

    harl.complain(complainLevel);
    return 0;
}
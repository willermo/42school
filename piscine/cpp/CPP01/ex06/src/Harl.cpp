/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:45:47 by doriani           #+#    #+#             */
/*   Updated: 2023/11/30 02:21:17 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void
Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << DEBUG_COLOR << DEBUG_MESSAGE << RESET_COLOR << std::endl
              << std::endl;
}

void
Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << INFO_COLOR << INFO_MESSAGE << RESET_COLOR << std::endl
              << std::endl;
}

void
Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << WARNING_COLOR << WARNING_MESSAGE << RESET_COLOR << std::endl
              << std::endl;
}

void
Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << ERROR_COLOR << ERROR_MESSAGE << RESET_COLOR << std::endl
              << std::endl;
}

void
invalidComplain() {
    std::cout << INVALID_COLOR << INVALID_MESSAGE << RESET_COLOR << std::endl
              << std::endl;
}

/* Although this exercise seems designed to use fallthroughs, the mandatory
 * request to use -Wall -Wextra -Werror as compile flags forces us to duplicate
 * the necessary calls for higher level complains.
 * An option would be to add the -Wno-implicit-fallthrough removing redundant
 * calls and subsequent breaks on cases 0, 1 and 2. But for sake of mandatory
 * compliance I will stick to an ugly code...
 */
void
Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;
    for (i = 0; i < LEVELS_NUMBER && levels[i].compare(level); i++)
        ;
    switch (i) {
    case 0:
        debug();
        info();
        warning();
        error();
        break;
    case 1:
        info();
        warning();
        error();
        break;
    case 2:
        warning();
        error();
        break;
    case 3:
        error();
        break;
    default:
        invalidComplain();
    }
}
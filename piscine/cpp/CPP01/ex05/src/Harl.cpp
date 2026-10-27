/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:45:47 by doriani           #+#    #+#             */
/*   Updated: 2023/11/30 00:46:33 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void
Harl::debug(void) {
    std::cout << DEBUG_COLOR << DEBUG_MESSAGE << RESET_COLOR << std::endl;
}

void
Harl::info(void) {
    std::cout << INFO_COLOR << INFO_MESSAGE << RESET_COLOR << std::endl;
}

void
Harl::warning(void) {
    std::cout << WARNING_COLOR << WARNING_MESSAGE << RESET_COLOR << std::endl;
}

void
Harl::error(void) {
    std::cout << ERROR_COLOR << ERROR_MESSAGE << RESET_COLOR << std::endl;
}

void
invalidComplainLevel(std::string level) {
    std::cout << INVALID_COMPLAIN_LEVEL_COLOR << "\"" << level << "\""
              << " is no fucking complain level! How should I complain "
                 "about that?"
              << RESET_COLOR << std::endl;
}

void
Harl::complain(std::string level) {
    funp functions[] = {&Harl::debug, &Harl::info, &Harl::warning,
                        &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < LEVELS_NUMBER; i++)
        if (!levels[i].compare(level))
            return (this->*functions[i])();
    invalidComplainLevel(level);
}
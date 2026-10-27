/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:45:50 by doriani           #+#    #+#             */
/*   Updated: 2023/11/30 00:43:21 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <limits>
int
main(void) {
    std::string complain;
    Harl harl;

    do {
        std::cout << "Enter a complain level (DEBUG, INFO, WARNING, ERROR) or "
                     "QUIT to leave: ";
        std::cin >> complain;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!complain.compare("QUIT"))
            break;
        harl.complain(complain);
    } while (true);
    return 0;
}
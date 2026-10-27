/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:52:33 by doriani           #+#    #+#             */
/*   Updated: 2024/03/23 18:37:15 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int
main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./bitcoin [database file]" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange("data.csv");
        exchange.printTransactions(std::string(argv[1]));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:53:53 by doriani           #+#    #+#             */
/*   Updated: 2024/03/20 12:22:19 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "colors.hpp"

int
main(void) {
    std::cout << BLUE_B << "Generating 9 random Base objects" << RESET
              << std::endl;
    std::cout << CYAN << "Base 1: " << RESET << std::endl;
    Base *base1 = Base::generate();
    std::cout << CYAN << "Base 2: " << RESET << std::endl;
    Base *base2 = Base::generate();
    std::cout << CYAN << "Base 3: " << RESET << std::endl;
    Base *base3 = Base::generate();
    std::cout << CYAN << "Base 4: " << RESET << std::endl;
    Base *base4 = Base::generate();
    std::cout << CYAN << "Base 5: " << RESET << std::endl;
    Base *base5 = Base::generate();
    std::cout << CYAN << "Base 6: " << RESET << std::endl;
    Base *base6 = Base::generate();
    std::cout << CYAN << "Base 7: " << RESET << std::endl;
    Base *base7 = Base::generate();
    std::cout << CYAN << "Base 8: " << RESET << std::endl;
    Base *base8 = Base::generate();
    std::cout << CYAN << "Base 9: " << RESET << std::endl;
    Base *base9 = Base::generate();
    std::cout << std::endl;
    std::cout << BLUE_B << "Identify bases by pointer" << RESET << std::endl;
    std::cout << CYAN << "Base 1: " << RESET << std::endl;
    Base::identify(base1);
    std::cout << CYAN << "Base 2: " << RESET << std::endl;
    Base::identify(base2);
    std::cout << CYAN << "Base 3: " << RESET << std::endl;
    Base::identify(base3);
    std::cout << CYAN << "Base 4: " << RESET << std::endl;
    Base::identify(base4);
    std::cout << CYAN << "Base 5: " << RESET << std::endl;
    Base::identify(base5);
    std::cout << CYAN << "Base 6: " << RESET << std::endl;
    Base::identify(base6);
    std::cout << CYAN << "Base 7: " << RESET << std::endl;
    Base::identify(base7);
    std::cout << CYAN << "Base 8: " << RESET << std::endl;
    Base::identify(base8);
    std::cout << CYAN << "Base 9: " << RESET << std::endl;
    Base::identify(base9);

    std::cout << std::endl;
    std::cout << BLUE_B << "Identify bases by reference" << RESET << std::endl;
    std::cout << CYAN << "Base 1: " << RESET << std::endl;
    Base::identify(*base1);
    std::cout << CYAN << "Base 2: " << RESET << std::endl;
    Base::identify(*base2);
    std::cout << CYAN << "Base 3: " << RESET << std::endl;
    Base::identify(*base3);
    std::cout << CYAN << "Base 4: " << RESET << std::endl;
    Base::identify(*base4);
    std::cout << CYAN << "Base 5: " << RESET << std::endl;
    Base::identify(*base5);
    std::cout << CYAN << "Base 6: " << RESET << std::endl;
    Base::identify(*base6);
    std::cout << CYAN << "Base 7: " << RESET << std::endl;
    Base::identify(*base7);
    std::cout << CYAN << "Base 8: " << RESET << std::endl;
    Base::identify(*base8);
    std::cout << CYAN << "Base 9: " << RESET << std::endl;
    Base::identify(*base9);

    std::cout << std::endl;
    std::cout << BLUE_B << "Deleting bases" << RESET << std::endl;
    delete base1;
    delete base2;
    delete base3;
    delete base4;
    delete base5;
    delete base6;
    delete base7;
    delete base8;
    delete base9;

    std::cout << std::endl;
    std::cout << BLUE_B << "End of the program" << RESET << std::endl;
    return 0;
}
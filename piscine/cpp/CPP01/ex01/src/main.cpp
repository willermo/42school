/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:15:18 by doriani           #+#    #+#             */
/*   Updated: 2023/11/28 21:01:55 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int usage( int error )
{
    switch (error)
    {
        case 1:
            std::cout << "Usage: ./horde <N> <name>"
                      << std::endl;
            break ;
        case 2:
            std::cout << "Number of zombie horde must be greater than 0"
                      << std::endl;
            break ;
    }
    return 1;
}

long argIsNumber(char *arg)
{
    char *p;
    std::string str(arg);
    long n = std::strtol(str.c_str(), &p, 10);
    if (*p)
        return 0;
    return n;
}

int main( int argc, char *argv[] )
{
    long nZombies;
    std::string name;
    Zombie* horde;

    if (argc < 3)
        return usage(1);
    nZombies = argIsNumber(argv[1]);
    if (nZombies < 1)
        return usage(2);
    name = std::string(argv[2]);    
    horde = zombieHorde(nZombies, name);
    for (int i = 0; i < nZombies; i++)
        horde[i].announce();
    delete []horde;
}
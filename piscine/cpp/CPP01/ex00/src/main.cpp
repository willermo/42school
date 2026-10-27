/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:15:18 by doriani           #+#    #+#             */
/*   Updated: 2023/11/28 19:03:02 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
    Zombie* zombie = newZombie("Pippo");
    Zombie* zombie2 = new Zombie();

    zombie->announce();
    zombie2->announce();
    randomChump( "Pluto" );
    delete zombie;
    delete zombie2;
}
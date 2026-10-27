/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:15:14 by doriani           #+#    #+#             */
/*   Updated: 2023/11/28 19:00:40 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
    name = "unnamed";
}

Zombie::~Zombie( void )
{
    std::cout << name << " Zombie has been destroyed" << std::endl;
}

Zombie::Zombie( std::string name )
{
    Zombie::name = name;
}

void    Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:35:27 by doriani           #+#    #+#             */
/*   Updated: 2023/11/29 11:13:52 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack( void )
{
    std::cout << _name << " attacks with their " 
              << _weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon& weapon)
{
    _weapon = &weapon;
}

HumanB::HumanB( std::string name ) : _name(name) {}

HumanB::~HumanB(void) {}
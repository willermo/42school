/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:35:32 by doriani           #+#    #+#             */
/*   Updated: 2023/11/29 11:13:41 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon )
    : _name(name), _weapon(weapon){}

HumanA::~HumanA(void) {}

void HumanA::attack( void )
{
    std::cout << _name << " attacks with their " 
              << _weapon.getType() << std::endl;
}
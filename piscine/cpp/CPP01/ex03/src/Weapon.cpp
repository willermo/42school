/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:35:30 by doriani           #+#    #+#             */
/*   Updated: 2023/11/29 10:32:34 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType( void )
{
    return type;
}
void Weapon::setType(std::string newType)
{
    type = newType;
}

//Weapon::Weapon( void ) {}

Weapon::Weapon( std::string type )
{
    setType(type);
}
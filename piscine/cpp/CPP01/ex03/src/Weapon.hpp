/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:35:21 by doriani           #+#    #+#             */
/*   Updated: 2023/11/29 10:33:26 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
private:
    std::string type;
public:
    const std::string& getType( void );
    void setType(std::string newType);
    //Weapon( void );
    Weapon( std::string type );
};

#endif
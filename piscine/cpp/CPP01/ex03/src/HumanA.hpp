/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:35:25 by doriani           #+#    #+#             */
/*   Updated: 2023/11/29 11:12:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon& _weapon;
public:
    HumanA( std::string name, Weapon& weapon );
    ~HumanA(void);
    void attack( void );
};

#endif
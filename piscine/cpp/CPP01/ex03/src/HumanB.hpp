/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:36:03 by doriani           #+#    #+#             */
/*   Updated: 2023/11/29 20:48:37 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
  private:
    Weapon *_weapon;
    std::string _name;

  public:
    HumanB(std::string name);
    ~HumanB(void);
    void attack(void);
    void setWeapon(Weapon &weapon);
};

#endif
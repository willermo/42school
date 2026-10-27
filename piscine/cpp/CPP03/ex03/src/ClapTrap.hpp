/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:41:51 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 13:42:58 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "colors.hpp"
#include <iostream>
#include <string>

class ClapTrap {
  protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

    ClapTrap(void);

  public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &arg);
    ClapTrap &operator=(const ClapTrap &player);
    ~ClapTrap(void);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName(void);
    int getHitPoints(void);
    int getEnergyPoints(void);
    unsigned int getAttackDamage(void);
};

std::ostream &operator<<(std::ostream &stream, ClapTrap &player);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:41:51 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 12:50:58 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "colors.hpp"
#include <iostream>
#include <string>
#define ARENA_SLOTS 2

class ClapTrap {
  private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
    static ClapTrap *playerArray[ARENA_SLOTS];

    ClapTrap(void);

  public:
    ClapTrap(std::string name);
    ClapTrap(std::string name, int hitPoints, int energyPoints,
             int attackDamage);
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
    void setAttackDamage(int amount);
    bool isInArena(ClapTrap *player);
    void addToCtArray(ClapTrap *player);
    bool isDead(void);
    static ClapTrap *getPlayer(std::string name);
    static ClapTrap *getPlayer(int index);
};

std::ostream &operator<<(std::ostream &stream, ClapTrap &player);

#endif
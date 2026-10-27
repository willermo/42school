/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:41:53 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 13:43:25 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(10) {
    std::cout << LIGHT_GRAY << "ClapTrap " << this->getName()
              << " has been created." << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &player) {
    *this = player;
    std::cout << LIGHT_GRAY << "ClapTrap " << name
              << " has been created. (copy constructor)" << RESET << std::endl;
}

ClapTrap &
ClapTrap::operator=(const ClapTrap &player) {
    name = player.name;
    hitPoints = player.hitPoints;
    energyPoints = player.energyPoints;
    attackDamage = player.attackDamage;
    std::cout << LIGHT_GRAY << "ClapTrap " << name << " has been copied"
              << RESET << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << DARK_GREY << "ClapTrap " << this->getName()
              << " has been destroyed" << RESET << std::endl;
}

void
ClapTrap::attack(const std::string &target) {
    if (!energyPoints) {
        std::cout << RED_B << "ClapTrap " << this->getName()
                  << " is too weak to attack!" << RESET << std::endl;
        return;
    }
    if (getHitPoints() <= 0) {
        std::cout << RED_B << "ClapTrap " << this->getName()
                  << " is dead and cannot attack!" << RESET << std::endl;
        return;
    }
    std::cout << YELLOW << "ClapTrap " << this->getName() << " attacks "
              << target << ", causing " << getAttackDamage()
              << " points of damage!" << RESET << std::endl;
    energyPoints--;
}

void
ClapTrap::takeDamage(unsigned int amount) {
    std::cout << YELLOW << "ClapTrap " << this->getName() << " takes " << amount
              << " points of damage!" << RESET << std::endl;
    hitPoints -= amount;
    if (getHitPoints() <= 0)
        std::cout << PURPLE_B << "ClapTrap " << this->getName() << " is dead!"
                  << RESET << std::endl;
}

void
ClapTrap::beRepaired(unsigned int amount) {
    if (getHitPoints() <= 0) {
        std::cout << RED_B << "ClapTrap " << this->getName()
                  << " is dead and cannot be repaired!" << RESET << std::endl;
        return;
    }
    if (energyPoints) {
        std::cout << GREEN << "ClapTrap " << this->getName() << " recovers "
                  << amount << " hit points!" << GREEN << std::endl;
        hitPoints += amount;
        energyPoints--;
    } else
        std::cout << RED_B << "ClapTrap " << this->getName()
                  << " is too weak to repair itself!" << RESET << std::endl;
}

std::string
ClapTrap::getName(void) {
    return name;
}

int
ClapTrap::getHitPoints(void) {
    return hitPoints;
}
int
ClapTrap::getEnergyPoints(void) {
    return energyPoints;
}
unsigned int
ClapTrap::getAttackDamage(void) {
    return attackDamage;
}

std::ostream &
operator<<(std::ostream &stream, ClapTrap &player) {
    stream << player.getName();
    return (stream);
}
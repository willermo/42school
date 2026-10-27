/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:57:37 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 13:56:59 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << DARK_GREY << this->getName()
              << " has been created." << RESET << std::endl;
}

FragTrap &
FragTrap::operator=(const FragTrap &player) {
    name = player.name;
    hitPoints = player.hitPoints;
    energyPoints = player.energyPoints;
    attackDamage = player.attackDamage;
    std::cout << GREY << "FragTrap " << name << " has been copied" << RESET
              << std::endl;
    return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << DARK_GREY << "FragTrap " << this->getName()
              << " has been destroyed" << RESET << std::endl;
}

void
FragTrap::attack(const std::string &target) {
    if (!this->getEnergyPoints()) {
        std::cout << RED_B << "FragTrap " << this->getName()
                  << " is too weak to attack!" << RESET << std::endl;
        return;
    }
    std::cout << YELLOW << "FragTrap " << this->getName() << " attacks "
              << target << ", causing " << getAttackDamage()
              << " points of damage!" << RESET << std::endl;
    energyPoints--;
}

void
FragTrap::highFiveGuys(void) {
    std::cout << BLUE_B << "FragTrap " << this->getName() << " gives High Five!"
              << RESET << std::endl;
}
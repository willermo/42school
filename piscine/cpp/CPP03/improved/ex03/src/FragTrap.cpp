/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:57:37 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 12:04:06 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap " << DARK_GREY << this->getName()
              << " has been created." << RESET << std::endl;
    addToCtArray(this);
}

FragTrap::FragTrap(std::string name, int hitPoints, int energyPoints,
                   int attackDamage)
    : ClapTrap(name, hitPoints, energyPoints, attackDamage) {
    std::cout << "FragTrap " << DARK_GREY << this->getName()
              << " has been created." << RESET << std::endl;
    addToCtArray(this);
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
    ClapTrap *enemy = getPlayer(target);
    if (!enemy)
        std::cout << RED_B << "FragTrap " << target << " is not in the Arena! "
                  << this->getName() << " has just wasted his attack!" << RESET
                  << std::endl;
    else {
        std::cout << YELLOW << "FragTrap " << this->getName() << " attacks "
                  << target << ", causing " << getAttackDamage()
                  << " points of damage!" << RESET << std::endl;
        enemy->takeDamage(getAttackDamage());
    }
    energyPoints--;
}

void
FragTrap::highFive(void) {
    std::cout << BLUE_B << "FragTrap " << this->getName() << " gives High Five!"
              << RESET << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:33:19 by doriani           #+#    #+#             */
/*   Updated: 2023/12/15 21:49:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
    std::cout << "ScavTrap " << GRAY << this->getName() << " has been created."
              << RESET << std::endl;
    gateKeeperMode = false;
    addToCtArray(this);
}

ScavTrap::ScavTrap(std::string name, int hitPoints, int energyPoints,
                   int attackDamage)
    : ClapTrap(name, hitPoints, energyPoints, attackDamage) {
    std::cout << "ScavTrap " << GRAY << this->getName() << " has been created."
              << RESET << std::endl;
    gateKeeperMode = false;
    addToCtArray(this);
}

ScavTrap &
ScavTrap::operator=(const ScavTrap &player) {
    name = player.name;
    hitPoints = player.hitPoints;
    energyPoints = player.energyPoints;
    attackDamage = player.attackDamage;
    gateKeeperMode = player.gateKeeperMode;
    std::cout << GRAY << "ScavTrap " << name << " has been copied" << RESET
              << std::endl;
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << DARK_GREY << "ScavTrap " << this->getName()
              << " has been destroyed" << RESET << std::endl;
}

void
ScavTrap::attack(const std::string &target) {
    if (!this->getEnergyPoints()) {
        std::cout << RED_B << "ScavTrap " << this->getName()
                  << " is too weak to attack!" << RESET << std::endl;
        return;
    }
    ClapTrap *enemy = getPlayer(target);
    if (!enemy)
        std::cout << RED_B << "ScavTrap " << target << " is not in the Arena! "
                  << this->getName() << " has just wasted his attack!" << RESET
                  << std::endl;
    else {
        std::cout << YELLOW << "ScavTrap " << this->getName() << " attacks "
                  << target << ", causing " << getAttackDamage()
                  << " points of damage!" << RESET << std::endl;
        enemy->takeDamage(getAttackDamage());
    }
    energyPoints--;
}

void
ScavTrap::guardGate(void) {
    gateKeeperMode = !gateKeeperMode;
    if (gateKeeperMode)
        std::cout << "ScavTrap " << this->getName()
                  << " has entered in Gate keeper mode." << std::endl;
    else

        std::cout << "ScavTrap " << this->getName()
                  << " has exited from Gate keeper mode." << std::endl;
}

std::string
ScavTrap::getMode(void) {
    return gateKeeperMode ? "ON" : "OFF";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:33:19 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 13:56:37 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << GREY << this->getName() << " has been created."
              << RESET << std::endl;
    gateKeeperMode = false;
}

ScavTrap &
ScavTrap::operator=(const ScavTrap &player) {
    name = player.name;
    hitPoints = player.hitPoints;
    energyPoints = player.energyPoints;
    attackDamage = player.attackDamage;
    gateKeeperMode = player.gateKeeperMode;
    std::cout << GREY << "ScavTrap " << name << " has been copied" << RESET
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
    std::cout << YELLOW << "ScavTrap " << this->getName() << " attacks "
              << target << ", causing " << getAttackDamage()
              << " points of damage!" << RESET << std::endl;
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
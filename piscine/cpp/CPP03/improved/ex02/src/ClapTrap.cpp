/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:41:53 by doriani           #+#    #+#             */
/*   Updated: 2023/12/15 21:46:51 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap *ClapTrap::playerArray[ARENA_SLOTS] = {NULL};

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(10) {
    std::cout << "ClapTrap " << LIGHT_GRAY << this->getName()
              << " has been created." << RESET << std::endl;
    addToCtArray(this);
}

ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints,
                   int attackDamage)
    : name(name), hitPoints(hitPoints), energyPoints(energyPoints),
      attackDamage(attackDamage) {
    std::cout << "ClapTrap " << LIGHT_GRAY << this->getName()
              << " has been created." << RESET << std::endl;
    addToCtArray(this);
}

ClapTrap::ClapTrap(const ClapTrap &player) {
    *this = player;
    std::cout << LIGHT_GRAY << "ClapTrap " << name
              << " has been created. (copy constructor)" << RESET << std::endl;
    addToCtArray(this);
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
    ClapTrap *enemy = getPlayer(target);
    if (!enemy)
        std::cout << RED_B << "ClapTrap " << target << " is not in the Arena! "
                  << this->getName() << " has just wasted his attack!" << RESET
                  << std::endl;
    else {
        std::cout << YELLOW << "ClapTrap " << this->getName() << " attacks "
                  << target << ", causing " << getAttackDamage()
                  << " points of damage!" << RESET << std::endl;
        enemy->takeDamage(getAttackDamage());
    }
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
void
ClapTrap::setAttackDamage(int amount) {
    attackDamage = amount;
}

bool
ClapTrap::isInArena(ClapTrap *player) {
    int i = 0;
    while (playerArray[i] && ++i <= ARENA_SLOTS)
        if (playerArray[i - 1]->getName() == player->getName())
            return true;
    return false;
}

bool
ClapTrap::isDead(void) {
    return hitPoints <= 0;
}

ClapTrap *
ClapTrap::getPlayer(std::string name) {
    int i = 0;
    while (playerArray[i] && ++i <= ARENA_SLOTS)
        if (playerArray[i - 1]->getName() == name)
            return playerArray[i - 1];
    return NULL;
}

ClapTrap *
ClapTrap::getPlayer(int index) {
    if (index > ARENA_SLOTS || index < 0)
        return NULL;
    return playerArray[index];
}

void
ClapTrap::addToCtArray(ClapTrap *player) {
    if (isInArena(player)) {
        std::cout << RED_B << "Sorry " << player->getName()
                  << ", There is already another player with your name "
                     "registered in the Arena!"
                  << RESET << std::endl;
        return;
    }
    int i = 0;
    while (playerArray[i] && ++i <= ARENA_SLOTS)
        ;
    if (i - ARENA_SLOTS) {
        playerArray[i] = player;
        std::cout << RED_K << "Welcome to the Arena " << player->getName()
                  << "!" << RESET << std::endl;
    } else {
        std::cout << RED_B << "Sorry " << player->getName()
                  << ", You cannot enter. Arena is full!" << RESET << std::endl;
        player = NULL;
    }
}

std::ostream &
operator<<(std::ostream &stream, ClapTrap &player) {
    stream << player.getName();
    return (stream);
}
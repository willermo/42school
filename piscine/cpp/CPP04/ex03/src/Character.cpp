/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:53:53 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 11:38:29 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "colors.hpp"

Character::Character(void) : _name("No Name") {
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    this->_discardedMaterias = new AMateriaList();
    return;
}

Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    this->_discardedMaterias = new AMateriaList();
    return;
}

Character::Character(const Character &other) : _name("No Name") {
    std::cout << PURPLE_K << "Character " << this->_name
              << " is going to be copied from " << other._name << RESET
              << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    this->_discardedMaterias = new AMateriaList();
    *this = other;
    return;
}

Character &
Character::operator=(const Character &other) {
    if (this != &other) {
        std::cout << PURPLE_K << "Character " << this->_name
                  << " has been replaced by a " << other._name << "'s copy"
                  << RESET << std::endl;
        this->_name = other._name;
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
        delete this->_discardedMaterias;
        this->_discardedMaterias = new AMateriaList();
        *(this->_discardedMaterias) = *(other._discardedMaterias);
    }
    return (*this);
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        if (this->_inventory[i])
            delete this->_inventory[i];
    this->_discardedMaterias->deleteMateriaList();
    delete this->_discardedMaterias;
}

std::string const &
Character::getName() const {
    return (this->_name);
}

void
Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++)
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            return;
        }
    std::cout << RED << getName() << "'s inventory is full! Materia " << RED_B
              << m->getType() << RESET << RED
              << " has been dropped to the floor!" << RESET << std::endl;
    this->_discardedMaterias->addMateria(m);
}

void
Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        this->_discardedMaterias->addMateria(this->_inventory[idx]);
        this->_inventory[idx] = NULL;
    }
}

void
Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
    else
        std::cout << RED << getName() << " has no materia in slot #" << idx
                  << RESET << std::endl;
}

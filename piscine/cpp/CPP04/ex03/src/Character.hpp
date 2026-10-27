/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:52:08 by doriani           #+#    #+#             */
/*   Updated: 2023/12/19 21:15:55 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "AMateriaList.hpp"
#include <iostream>
#include <string>

class ICharacter {
  public:
    virtual ~ICharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};

class Character : public ICharacter {
  private:
    std::string _name;
    AMateria *_inventory[4];
    AMateriaList *_discardedMaterias;

  public:
    Character(/* args */);
    Character(std::string const &name);
    Character(Character const &other);
    Character &operator=(Character const &other);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif
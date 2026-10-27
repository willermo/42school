/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:54:26 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 11:20:37 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "AMateriaList.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int
main() {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp->clone());
    me->equip(tmp->clone());
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("cure"));
    bob->equip(src->createMateria("cure"));

    me->use(0, *bob);
    me->use(1, *bob);

    bob->use(0, *me);
    bob->use(2, *me);
    bob->unequip(2);
    bob->use(2, *me);

    Character *jim = new Character("jim");
    *jim = *dynamic_cast<Character *>(bob);
    jim->use(1, *me);
    jim->use(2, *me);
    jim->unequip(0);

    Character *john = new Character(*jim);
    john->use(0, *me);
    john->equip(src->createMateria("ice"));
    john->use(0, *me);
    john->unequip(0);
    john->unequip(1);

    delete jim;
    delete me;
    delete bob;
    delete john;
    delete src;

    return 0;
}
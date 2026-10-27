/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:41:55 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 14:03:06 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int
main(void) {

    ClapTrap pippo("Pippo");
    ScavTrap pluto("Pluto");
    ScavTrap plutoAO("PlutoAO");
    ScavTrap plutoCC(pluto);
    plutoAO = pluto;
    FragTrap paperino("Paperino");
    FragTrap paperinoAO("PaperinoAO");
    paperinoAO = paperino;
    DiamondTrap topolino("Topolino");
    DiamondTrap topolinoAO("TopolinoAO");
    topolinoAO = topolino;

    pippo.attack("Pluto");
    pluto.takeDamage(pippo.getAttackDamage());
    pluto.attack("Pippo");
    pippo.takeDamage(pluto.getAttackDamage());
    pluto.guardGate();
    plutoAO.guardGate();
    plutoAO.attack("Pluto");
    pluto.takeDamage(plutoAO.getAttackDamage());
    pluto.guardGate();
    plutoAO.guardGate();
    plutoAO.beRepaired(10);
    paperino.attack("Pluto");
    pluto.takeDamage(paperino.getAttackDamage());
    paperinoAO.highFiveGuys();
    topolino.attack("Pluto");
    pluto.takeDamage(topolino.getAttackDamage());
    topolino.whoAmI();
    topolinoAO.whoAmI();
    topolinoAO.highFiveGuys();
    topolinoAO.attack("Pluto");
    pluto.takeDamage(topolinoAO.getAttackDamage());
    topolinoAO.guardGate();
    topolinoAO.beRepaired(10);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:41:55 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 13:10:00 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int
main(void) {

    ClapTrap pippo("Pippo");
    ClapTrap pippoCC(pippo);
    ClapTrap pluto("Pluto");
    ClapTrap plutoAO("PlutoAO");
    plutoAO = pluto;

    pippo.attack("Pluto");
    pluto.takeDamage(pippo.getAttackDamage());
    pluto.attack("Pippo");
    plutoAO.beRepaired(10);
}
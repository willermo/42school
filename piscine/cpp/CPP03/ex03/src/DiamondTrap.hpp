/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:21:02 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 13:58:51 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
  private:
    std::string name;
    DiamondTrap(void);

  public:
    DiamondTrap(std::string name);
    DiamondTrap(std::string name, int hitPoints, int energyPoints,
                int attackDamage);
    ~DiamondTrap(void);
    DiamondTrap &operator=(const DiamondTrap &player);

    std::string getName(void);
    void attack(const std::string &target);
    void whoAmI(void);
};

#endif
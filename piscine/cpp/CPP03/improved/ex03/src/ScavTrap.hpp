/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:33:05 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 12:17:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
  private:
    ScavTrap(void);
    bool gateKeeperMode;

  public:
    ScavTrap(std::string name);
    ScavTrap(std::string name, int hitPoints, int energyPoints,
             int attackDamage);
    ~ScavTrap(void);
    virtual ScavTrap &operator=(const ScavTrap &player);

    void attack(const std::string &target);
    void guardGate(void);
    std::string getMode(void);
};

#endif
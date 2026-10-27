/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:57:35 by doriani           #+#    #+#             */
/*   Updated: 2023/12/15 22:03:55 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  private:
    FragTrap(void);

  public:
    FragTrap(std::string name);
    FragTrap(std::string name, int hitPoints, int energyPoints,
             int attackDamage);
    ~FragTrap(void);
    virtual FragTrap &operator=(const FragTrap &player);

    void attack(const std::string &target);
    void highFive(void);
};

#endif
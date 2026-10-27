/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:57:35 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 14:01:01 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
  private:
    FragTrap(void);

  public:
    FragTrap(std::string name);
    ~FragTrap(void);
    virtual FragTrap &operator=(const FragTrap &player);

    void attack(const std::string &target);
    void highFiveGuys(void);
};

#endif
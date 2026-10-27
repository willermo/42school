/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:53:11 by doriani           #+#    #+#             */
/*   Updated: 2023/12/19 19:54:13 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria {
  public:
    Ice();
    ~Ice();
    Ice(Ice const &other);
    Ice &operator=(Ice const &other);

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:51:34 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 00:17:48 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Character.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria {
  protected:
    std::string _type;

  public:
    AMateria();
    AMateria(std::string const &type);
    virtual ~AMateria();
    AMateria(AMateria const &other);
    // AMateria &operator=(AMateria const &other);

    std::string const &getType() const;   // Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif
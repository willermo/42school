/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:52:25 by doriani           #+#    #+#             */
/*   Updated: 2023/12/19 19:44:53 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria {
  public:
    Cure();
    ~Cure();
    Cure(Cure const &other);
    Cure &operator=(Cure const &other);

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:54:02 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 10:55:54 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") { return; }

Cure::Cure(Cure const &other) : AMateria(other.getType()) { return; }

Cure::~Cure(void) { return; }

Cure &
Cure::operator=(Cure const &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    return (*this);
}

AMateria *
Cure::clone(void) const {
    return (new Cure(*this));
}

void
Cure::use(ICharacter &target) {
    std::cout << GREEN << "* heals " << target.getName() << "'s wounds *"
              << RESET << std::endl;
    return;
}

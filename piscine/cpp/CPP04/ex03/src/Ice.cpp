/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:54:09 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 10:55:55 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") { return; }

Ice::Ice(Ice const &other) : AMateria(other.getType()) { return; }

Ice::~Ice(void) { return; }

Ice &
Ice::operator=(Ice const &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    return (*this);
}

AMateria *
Ice::clone(void) const {
    return (new Ice(*this));
}

void
Ice::use(ICharacter &target) {
    std::cout << YELLOW << "* shoots an ice bolt at " << target.getName()
              << " *" << RESET << std::endl;
    return;
}

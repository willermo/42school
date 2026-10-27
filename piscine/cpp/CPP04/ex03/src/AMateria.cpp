/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:53:43 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 10:52:14 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria::~AMateria() {}

// AMateria &
// AMateria::operator=(const AMateria &other) {
//     if (this != &other)
//         this->_type = other._type;
//     return (*this);
// }

std::string const &
AMateria::getType() const {
    return (this->_type);
}

void
AMateria::use(ICharacter &target) {
    std::cout << "Amateria " << getType() << "used on " << target.getName()
              << std::endl;
}
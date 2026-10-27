/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:54:17 by doriani           #+#    #+#             */
/*   Updated: 2023/12/19 21:34:48 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "colors.hpp"

MateriaSource::MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        _materia[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const &other) { *this = other; }

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        if (_materia[i] != NULL) {
            delete _materia[i];
        }
    }
}

MateriaSource &
MateriaSource::operator=(MateriaSource const &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (_materia[i] != NULL) {
                delete _materia[i];
            }
            _materia[i] = other._materia[i]->clone();
        }
    }
    return (*this);
}

void
MateriaSource::learnMateria(AMateria *m) {
    int i;
    for (i = 0; i < 4; i++) {
        if (_materia[i] == NULL) {
            _materia[i] = m;
            break;
        }
    }
    if (i == 4) {
        std::cout << RED << "MateriaSource is full" << RESET << std::endl;
        delete m;
    }
}

AMateria *
MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_materia[i] != NULL && _materia[i]->getType() == type) {
            return (_materia[i]->clone());
        }
    }
    return (NULL);
}

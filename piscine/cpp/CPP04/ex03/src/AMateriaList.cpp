/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:09:47 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 11:14:54 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateriaList.hpp"
#include "AMateria.hpp"

AMateriaList::AMateriaList(void) : _materia(NULL), _next(NULL) { return; }

AMateriaList::AMateriaList(AMateria *materia) : _materia(materia), _next(NULL) {
    return;
}

AMateriaList::AMateriaList(AMateriaList const &other) {
    *this = other;
    return;
}

AMateriaList::~AMateriaList(void) { return; }

AMateriaList &
AMateriaList::operator=(AMateriaList const &other) {
    if (this != &other) {
        // delete all the _materia in the list
        this->deleteMateriaList();

        // create a new AMateria object if other._materia is not NULL
        if (other._materia)
            this->_materia = other._materia->clone();
        else
            this->_materia = NULL;

        // create a new AMateriaList object if other._next is not NULL
        if (other._next) {

            // copy the first node of the list
            this->_next = new AMateriaList(other._next->_materia->clone());
            AMateriaList *current = this->_next;
            AMateriaList *otherCurrent = other._next;

            // copy the rest of the list
            while (otherCurrent->_next) {
                current->_next =
                    new AMateriaList(otherCurrent->_next->_materia->clone());
                current = current->_next;
                otherCurrent = otherCurrent->_next;
            }
        } else {
            this->_next = NULL;
        }
    }
    return (*this);
}

void
AMateriaList::addMateria(AMateria *materia) {
    AMateriaList *tmp = this;

    if (!materia)
        return;
    if (!tmp->_materia) {
        tmp->_materia = materia;
        return;
    }
    while (tmp->_next)
        tmp = tmp->_next;
    tmp->_next = new AMateriaList(materia);
    return;
}

void
AMateriaList::deleteMateriaList(void) {
    AMateriaList *tmp = this->_next;
    AMateriaList *next = NULL;

    while (tmp && tmp->_materia) {
        delete tmp->_materia;
        next = tmp->_next;
        delete tmp;
        tmp = next;
    }
    if (tmp)
        delete tmp;
    if (this->_materia) {
        delete this->_materia;
        this->_materia = NULL;
    }
    return;
}

void
AMateriaList::printAMaterialList(void) {
    AMateriaList *tmp = this;
    while (tmp) {
        if (tmp->_materia)
            std::cout << tmp->_materia->getType();
        else
            std::cout << "NULL";
        if (tmp->_next)
            std::cout << " -> ";
        else
            std::cout << std::endl;
        tmp = tmp->_next;
    }
}

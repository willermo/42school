/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:20:33 by doriani           #+#    #+#             */
/*   Updated: 2024/01/04 18:15:29 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = NULL;
    *this = other;
}

Cat &
Cat::operator=(const Cat &other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        this->Animal::operator=(other);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void
Cat::makeSound(void) const {
    std::cout << "Miao Miao" << std::endl;
}

void
Cat::setIdea(int idx, std::string idea) const {
    this->brain->setIdea(idx, idea);
}

std::string
Cat::getIdea(int idx) const {
    return this->brain->getIdea(idx);
}
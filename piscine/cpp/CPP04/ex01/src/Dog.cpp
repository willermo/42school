/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:20:36 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 18:40:24 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog &
Dog::operator=(const Dog &other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        this->Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void
Dog::makeSound(void) const {
    std::cout << "Bau Bau!" << std::endl;
}

void
Dog::setIdea(int idx, std::string idea) const {
    this->brain->setIdea(idx, idea);
}

std::string
Dog::getIdea(int idx) const {
    return this->brain->getIdea(idx);
}
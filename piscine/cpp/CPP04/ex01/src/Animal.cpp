/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:20:26 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 16:29:58 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animalo Ecceziunalo") {
    std::cout << LIGHT_GREY << "I just created an " << GREY_B << getType()
              << RESET << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << LIGHT_GREY << "I just created a " << GREY_B << getType()
              << RESET << std::endl;
}

Animal::~Animal() {
    std::cout << LIGHT_GREY << "I just destroyed a " << GREY_B << getType()
              << RESET << std::endl;
}

Animal::Animal(const Animal &other) {
    std::cout << LIGHT_GREY << "Animal copy constructor called" << RESET
              << std::endl;
    *this = other;
}

Animal &
Animal::operator=(const Animal &other) {
    std::cout << LIGHT_GREY << "Animal assignment operator called" << RESET
              << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string
Animal::getType() const {
    return (this->type);
}

void
Animal::makeSound() const {
    std::cout << CYAN_B << "So' un animalo veramente ecceziunalo" << RESET
              << std::endl;
}
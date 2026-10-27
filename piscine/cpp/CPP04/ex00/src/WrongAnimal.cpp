/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:20:29 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 17:02:47 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Juventino") {
    std::cout << LIGHT_GREY << "I just created an " << GREY_B << getType()
              << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << LIGHT_GREY << "I just created a " << GREY_B << getType()
              << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << LIGHT_GREY << "I just destroyed a " << GREY_B << getType()
              << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << LIGHT_GREY << "WrongAnimal copy constructor called" << RESET
              << std::endl;
    *this = other;
}

WrongAnimal &
WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << LIGHT_GREY << "WrongAnimal assignment operator called" << RESET
              << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string
WrongAnimal::getType() const {
    return (this->type);
}

void
WrongAnimal::makeSound() const {
    std::cout << CYAN_B << "So' un WrongAnimalo veramente ecceziunalo" << RESET
              << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:26:50 by doriani           #+#    #+#             */
/*   Updated: 2023/12/10 19:06:12 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    number = 0;
}

Fixed::Fixed(const Fixed &arg) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(arg.getRawBits());
}

Fixed &
Fixed::operator=(const Fixed &arg) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->number = arg.number;
    this->setRawBits(arg.getRawBits());
    return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int
Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return number;
}

void
Fixed::setRawBits(int const raw) {
    number = raw;
}
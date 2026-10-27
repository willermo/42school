/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:26:50 by doriani           #+#    #+#             */
/*   Updated: 2023/12/11 00:53:40 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    number = 0;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    number = n << bits;
}

Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    number = roundf(n * (1 << bits));
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

std::ostream &
operator<<(std::ostream &stream, const Fixed &arg) {
    stream << arg.toFloat();
    return (stream);
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int
Fixed::getRawBits(void) const {
    return number;
}

void
Fixed::setRawBits(int const raw) {
    number = raw;
}

float
Fixed::toFloat(void) const {
    return (getRawBits() / (float) (1 << bits));
}

int
Fixed::toInt(void) const {
    return number >> bits;
}
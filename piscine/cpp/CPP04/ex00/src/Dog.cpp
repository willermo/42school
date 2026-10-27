/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:20:36 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 16:58:09 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void) { std::cout << "Dog destructor called" << std::endl; }

void
Dog::makeSound(void) const {
    std::cout << "Bau Bau!" << std::endl;
}
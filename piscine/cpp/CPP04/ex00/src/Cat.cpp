/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:20:33 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 16:50:10 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl; }

void
Cat::makeSound(void) const {
    std::cout << "Miao Miao" << std::endl;
}
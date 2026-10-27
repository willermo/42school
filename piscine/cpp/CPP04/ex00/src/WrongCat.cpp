/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:22:49 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 17:08:21 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Gatto Juventino") {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destructor called" << std::endl;
}

void
WrongCat::makeSound(void) const {
    std::cout << "Rubo i campionati e qiando non li rubo piango!" << std::endl;
}
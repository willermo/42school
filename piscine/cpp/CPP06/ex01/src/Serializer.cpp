/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:07:22 by doriani           #+#    #+#             */
/*   Updated: 2024/03/20 11:48:46 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer const &src) { *this = src; }

Serializer &
Serializer::operator=(Serializer const &src) {
    if (this != &src) {
        *this = src;
    }
    return (*this);
}

uintptr_t
Serializer::serialize(Data *data) {
    return (reinterpret_cast<uintptr_t>(data));
}

Data *
Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:58:50 by doriani           #+#    #+#             */
/*   Updated: 2024/03/20 11:51:33 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include "colors.hpp"
#include <iostream>

static bool
compareData(Data *data1, Data *data2) {
    if (data1->module != data2->module)
        return false;
    if (data1->chapter != data2->chapter)
        return false;
    if (data1->exercise != data2->exercise)
        return false;
    return true;
}

int
main(void) {
    Data *data = new Data;

    data->module = "CPP06";
    data->chapter = "V";
    data->exercise = 1;

    uintptr_t raw = Serializer::serialize(data);
    Data *data2 = Serializer::deserialize(raw);
    std::cout << "Module: " << data2->module << std::endl;
    std::cout << "Chapter: " << data2->chapter << std::endl;
    std::cout << "Exercise: " << data2->exercise << std::endl;
    std::cout << std::endl;
    if (compareData(data, data2))
        std::cout << GREEN_B << "Data is the same" << RESET << std::endl;
    else
        std::cout << RED_B << "Data is different" << RESET << std::endl;
    delete data;

    return 0;
}
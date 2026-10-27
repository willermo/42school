/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:26:52 by doriani           #+#    #+#             */
/*   Updated: 2023/12/14 00:36:05 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int
main(void) {
    float xA, yA, xB, yB, xC, yC, xP, yP;

    std::cout << "Insert triangle vertex A x coordinate: ";
    std::cin >> xA;
    std::cout << "Insert triangle vertex A y coordinate: ";
    std::cin >> yA;

    std::cout << "Insert triangle vertex B x coordinate: ";
    std::cin >> xB;
    std::cout << "Insert triangle vertex B y coordinate: ";
    std::cin >> yB;

    std::cout << "Insert triangle vertex C x coordinate: ";
    std::cin >> xC;
    std::cout << "Insert triangle vertex C y coordinate: ";
    std::cin >> yC;

    std::cout << "Insert point P x coordinate: ";
    std::cin >> xP;
    std::cout << "Insert point P y coordinate: ";
    std::cin >> yP;

    Point a = Point(xA, yA);
    Point b = Point(xB, yB);
    Point c = Point(xC, yC);
    Point point = Point(xP, yP);
    // uncomment the code to test the uncorrectness of defining an operator=
    // that tries to modify const private members
    // Point d; d = a; std::cout << "Point d: " << d
    // << std::endl; std::cout << "Point a: " << a << std::endl;

    std::cout << "Point " << point << " is ";
    if (!bsp(a, b, c, point))
        std::cout << "not ";
    std::cout << "inside the triangle" << std::endl;

    return 0;
}
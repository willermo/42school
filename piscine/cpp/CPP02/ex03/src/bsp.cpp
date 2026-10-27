/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:48:40 by doriani           #+#    #+#             */
/*   Updated: 2023/12/14 00:21:41 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Algorithm reference:
// https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

static Fixed
ft_abs(Fixed number) {
    return number < 0 ? number * -1 : number;
}

static Fixed
getArea(Point const p1, Point const p2, Point const p3) {

    Fixed x1 = p1.getX();
    Fixed y1 = p1.getY();
    Fixed x2 = p2.getX();
    Fixed y2 = p2.getY();
    Fixed x3 = p3.getX();
    Fixed y3 = p3.getY();

    return ft_abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) /
                  Fixed(2.0f));
}

bool
bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed triangleArea = getArea(a, b, c);
    Fixed pbcArea = getArea(point, b, c);
    Fixed pacArea = getArea(point, a, c);
    Fixed pabArea = getArea(point, a, b);

    // Check if the point is a vertex or lies on an edge of the triangle
    if (pbcArea == 0 || pacArea == 0 || pabArea == 0)
        return false;

    return (triangleArea == pbcArea + pacArea + pabArea);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:49:03 by doriani           #+#    #+#             */
/*   Updated: 2023/12/14 00:34:59 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const Point &point) : x(point.x), y(point.y) {}

// This would compile but it would assign a new value to a const value...
// Point &
// Point::operator=(const Point &point) {
//     (Fixed) this->x = point.x;   // compiles but it is inherently incorrect
//     (Fixed) this->y = point.y;
//     return *this;
// }

Point::~Point(void) {}

Fixed
Point::getX(void) const {
    return x;
}
Fixed
Point::getY(void) const {
    return y;
}

std::ostream &
operator<<(std::ostream &stream, const Point &point) {
    stream << "(" << point.getX() << ", " << point.getY() << ")";
    return (stream);
}
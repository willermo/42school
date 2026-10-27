/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:49:18 by doriani           #+#    #+#             */
/*   Updated: 2023/12/14 00:35:24 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
  private:
    Fixed const x;
    Fixed const y;

  public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point &point);
    // Point &operator=(const Point &point);
    // Point &operator=(const Point &point) = delete; // std=c++11
    ~Point(void);

    Fixed getX(void) const;
    Fixed getY(void) const;
};

std::ostream &operator<<(std::ostream &stream, const Point &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
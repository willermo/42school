/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:26:47 by doriani           #+#    #+#             */
/*   Updated: 2023/12/11 00:53:39 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED__HPP
#define FIXED__HPP

#include <cmath>
#include <iostream>

class Fixed {
  private:
    int number;
    static const int bits = 8;

  public:
    Fixed(void);
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &arg);
    Fixed &operator=(const Fixed &arg);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &arg);

#endif
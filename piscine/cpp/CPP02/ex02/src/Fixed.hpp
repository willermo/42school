/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:26:47 by doriani           #+#    #+#             */
/*   Updated: 2023/12/13 19:30:08 by doriani          ###   ########.fr       */
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

    bool operator==(const Fixed &arg) const;
    bool operator!=(const Fixed &arg) const;
    bool operator>(const Fixed &arg) const;
    bool operator<(const Fixed &arg) const;
    bool operator>=(const Fixed &arg) const;
    bool operator<=(const Fixed &arg) const;
    Fixed operator+(const Fixed &arg) const;
    Fixed operator-(const Fixed &arg) const;
    Fixed operator*(const Fixed &arg) const;
    Fixed operator/(const Fixed &arg) const;
    Fixed &operator++(void);   // pre
    Fixed operator++(int);     // post
    Fixed &operator--(void);
    Fixed operator--(int);

    static Fixed &min(Fixed &f1, Fixed &f2);
    static const Fixed &min(const Fixed &f1, const Fixed &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    static const Fixed &max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &arg);

#endif
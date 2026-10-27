/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:26:47 by doriani           #+#    #+#             */
/*   Updated: 2023/12/10 14:14:34 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED__HPP
#define FIXED__HPP

#include <iostream>

class Fixed {
  private:
    int number;
    static const int bits = 8;

  public:
    Fixed(void);
    Fixed(const Fixed &arg);
    Fixed &operator=(const Fixed &arg);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
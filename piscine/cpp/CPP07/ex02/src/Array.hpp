/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:55:07 by doriani           #+#    #+#             */
/*   Updated: 2024/03/20 16:23:20 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array {
  private:
    T *_array;
    unsigned int _size;

  public:
    Array();
    Array(unsigned int n);
    Array(const Array &src);
    ~Array();

    Array &operator=(const Array &src);

    T &operator[](unsigned int i);

    unsigned int size() const;
};

#include "Array.tpp"

#endif
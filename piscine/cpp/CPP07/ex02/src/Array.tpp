/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:55:10 by doriani           #+#    #+#             */
/*   Updated: 2024/03/20 16:49:51 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <cstddef>
#include <stdexcept>

template <typename T> Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &src) : _array(new T[src._size]), _size(src._size) {
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = src._array[i];
}

template <typename T> Array<T>::~Array() {
    if (_array)
        delete[] _array;
}

template <typename T>
Array<T> &
Array<T>::operator=(const Array &src) {
    if (this == &src)
        return *this;
    if (_array)
        delete[] _array;
    _array = new T[src._size];
    _size = src._size;
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = src._array[i];
    return *this;
}

template <typename T>
T &
Array<T>::operator[](unsigned int i) {
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return _array[i];
}

template <typename T>
unsigned int
Array<T>::size() const {
    return _size;
}

#endif
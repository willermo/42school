/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:39:14 by doriani           #+#    #+#             */
/*   Updated: 2024/03/22 12:31:58 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &other) {
    _n = other._n;
    _vec = other._vec;
}

Span &
Span::operator=(Span const &other) {
    if (this != &other) {
        _n = other._n;
        _vec = other._vec;
    }
    return *this;
}

Span::~Span() {}

void
Span::addNumber(int n) {
    if (_vec.size() < _n) {
        _vec.push_back(n);
    } else {
        std::stringstream ss;
        ss << "No more room to add number " << n << " in span";
        throw std::runtime_error(ss.str());
    }
}

void
Span::addNumber(std::vector<int>::iterator begin,
                std::vector<int>::iterator end) {
    if (_vec.size() + std::distance(begin, end) <= _n) {
        _vec.insert(_vec.end(), begin, end);
    } else {
        std::stringstream ss;
        ss << "No more room to add number " << *begin
           << " in span, rejecting operation";
        throw std::runtime_error(ss.str());
    }
}

unsigned int
Span::shortestSpan() {
    if (_vec.size() < 2) {
        throw std::runtime_error("Vector size is less than 2");
    }
    std::sort(_vec.begin(), _vec.end());
    unsigned int min = std::abs(_vec[1] - _vec[0]);
    for (size_t i = 2; i < _vec.size(); i++) {
        if (std::abs(_vec[i] - _vec[i - 1]) < min) {
            min = _vec[i] - _vec[i - 1];
        }
    }
    return min;
}

unsigned int
Span::longestSpan() {
    if (_vec.size() < 2) {
        throw std::runtime_error("Vector size is less than 2");
    }
    std::sort(_vec.begin(), _vec.end());
    return std::abs(_vec[_vec.size() - 1] - _vec[0]);
}
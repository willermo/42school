/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:39:11 by doriani           #+#    #+#             */
/*   Updated: 2024/03/22 12:22:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Span {
  private:
    unsigned int _n;
    std::vector<int> _vec;

  public:
    Span(unsigned int n);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void addNumber(int n);
    void addNumber(std::vector<int>::iterator begin,
                   std::vector<int>::iterator end);
    unsigned int shortestSpan();
    unsigned int longestSpan();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:23:35 by doriani           #+#    #+#             */
/*   Updated: 2024/03/23 10:28:53 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <iterator>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
  public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &src) : std::stack<T>(src) { *this = src; }
    ~MutantStack() {}

    MutantStack &operator=(const MutantStack &src) {
        if (this == &src) {
            return *this;
        }
        std::stack<T>::operator=(src);
        return *this;
    }

    void clear() {
        while (!std::stack<T>::empty()) {
            std::stack<T>::pop();
        }
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }

    typedef
        typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator begin() const { return std::stack<T>::c.begin(); }
    const_iterator end() const { return std::stack<T>::c.end(); }
};

template <typename T>
std::ostream &
operator<<(std::ostream &out, const MutantStack<T> &ms) {
    typename MutantStack<T>::const_iterator it = ms.begin();
    typename MutantStack<T>::const_iterator ite = ms.end();
    if (it == ite) {
        out << "<Empty stack>";
        return out;
    }
    while (it != ite) {
        out << *it;
        if (++it != ite)
            out << " -> ";
    }
    return out;
}

#endif
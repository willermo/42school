/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:07:40 by doriani           #+#    #+#             */
/*   Updated: 2024/03/20 12:10:57 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base {

  public:
    virtual ~Base() {}
    static Base *generate(void);
    static void identify(Base *p);
    static void identify(Base &p);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
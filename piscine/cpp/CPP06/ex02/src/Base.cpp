/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:53:57 by doriani           #+#    #+#             */
/*   Updated: 2024/03/20 12:18:52 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *
Base::generate(void) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    int i = rand() % 3;
    if (i == 0) {
        std::cout << "A class generated" << std::endl;
        return new A;
    } else if (i == 1) {
        std::cout << "B class generated" << std::endl;
        return new B;
    } else {
        std::cout << "C class generated" << std::endl;
        return new C;
    }
}

void
Base::identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown class" << std::endl;
}

void
Base::identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void) a;
        std::cout << "A" << std::endl;
    } catch (std::exception &bad_cast) {
        try {
            B &b = dynamic_cast<B &>(p);
            (void) b;
            std::cout << "B" << std::endl;
        } catch (std::exception &bad_cast) {
            try {
                C &c = dynamic_cast<C &>(p);
                (void) c;
                std::cout << "C" << std::endl;
            } catch (std::exception &bad_cast) {
                std::cout << "Unknown class" << std::endl;
            }
        }
    }
}
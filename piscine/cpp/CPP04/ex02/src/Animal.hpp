/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:20:11 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 20:31:30 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "colors.hpp"
#include <iostream>

class Animal {
  protected:
    std::string type;

  public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const = 0;
    virtual void setIdea(int idx, std::string idea) const = 0;
    virtual std::string getIdea(int idx) const = 0;
};

#endif

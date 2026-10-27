/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:02:02 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 17:02:04 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAnimal_HPP
#define WRONGAnimal_HPP

#include "colors.hpp"
#include <iostream>

class WrongAnimal {
  protected:
    std::string type;

  public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);
    virtual ~WrongAnimal();

    std::string getType() const;
    virtual void makeSound() const;
};

#endif
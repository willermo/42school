/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:20:22 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 18:30:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
  private:
    Brain *brain;

  public:
    Dog(void);
    ~Dog(void);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);

    void makeSound() const;
    void setIdea(int idx, std::string idea) const;
    std::string getIdea(int idx) const;
};

#endif

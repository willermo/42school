/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:20:18 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 18:30:21 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
  private:
    Brain *brain;

  public:
    Cat(void);
    ~Cat(void);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);

    void makeSound() const;
    void setIdea(int idx, std::string idea) const;
    std::string getIdea(int idx) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:53:27 by doriani           #+#    #+#             */
/*   Updated: 2023/12/19 20:34:18 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include <iostream>
#include <string>

class IMateriaSource {
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource {
  private:
    AMateria *_materia[4];

  public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &other);

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif
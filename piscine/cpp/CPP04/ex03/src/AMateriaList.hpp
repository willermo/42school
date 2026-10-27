/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:09:44 by doriani           #+#    #+#             */
/*   Updated: 2023/12/20 01:44:27 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIALIST_HPP
#define AMATERIALIST_HPP

#include <string>

class AMateria;

class AMateriaList {
  private:
    AMateria *_materia;
    AMateriaList *_next;

  public:
    AMateriaList();
    ~AMateriaList();
    AMateriaList(AMateria *materia);
    AMateriaList(AMateriaList const &other);
    AMateriaList &operator=(AMateriaList const &other);

    void addMateria(AMateria *materia);
    void deleteMateriaList();
    void printAMaterialList();
};

#endif
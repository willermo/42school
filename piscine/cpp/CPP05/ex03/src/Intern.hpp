/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:28:57 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 15:46:47 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern {
  public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();
    Intern &operator=(const Intern &copy);

    AForm *makeForm(std::string formName, std::string target);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:29:00 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 15:46:06 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) { *this = copy; }

Intern::~Intern() {}

Intern &
Intern::operator=(const Intern &copy) {
    (void) copy;
    return *this;
}

AForm *
Intern::makeForm(std::string form_name, std::string target) {
    std::string form_names[] = {"robotomy request", "presidential pardon",
                                "shrubbery creation"};
    int form_idx;

    for (form_idx = 0; form_idx < 3; form_idx++)
        if (form_names[form_idx] == form_name)
            break;
    switch (form_idx) {
    case 0:
        std::cout << "Intern creates " << form_name << std::endl;
        return new RobotomyRequestForm(target);
    case 1:
        std::cout << "Intern creates " << form_name << std::endl;
        return new PresidentialPardonForm(target);
    case 2:
        std::cout << "Intern creates " << form_name << std::endl;
        return new ShrubberyCreationForm(target);
    default:
        std::cout << "Intern can't create " << form_name
                  << " because it doesn't exist" << std::endl;
        return NULL;
    }
}
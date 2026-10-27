/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:44:40 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:17:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    if (this == &other)
        return *this;
    AForm::operator=(other);
    _target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void
PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zafod Beeblebrox"
              << std::endl;
}

std::string
PresidentialPardonForm::getTarget() const {
    return _target;
}

std::ostream &
operator<<(std::ostream &out, PresidentialPardonForm const &form) {
    out << "Form " << form.getName() << " is ";
    out << (form.getSigned() ? "signed." : "not signed.") << std::endl;
    out << "Grade required to sign: " << form.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << form.getGradeToExecute()
        << std::endl;
    out << "Target: " << form.getTarget() << std::endl;
    return out;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:49:58 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:16:38 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    if (this == &other)
        return *this;
    AForm::operator=(other);
    _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void
ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::ofstream file;
    file.open((_target + "_shrubbery").c_str(), std::ios_base::out);
    file << "        *                " << std::endl;
    file << "       ***               " << std::endl;
    file << "      *****              " << std::endl;
    file << "     *******             " << std::endl;
    file << "    *********        *   " << std::endl;
    file << "   ***********      ***  " << std::endl;
    file << "  *************    ***** " << std::endl;
    file << "       | |        *******" << std::endl;
    file << "       | |          | |  " << std::endl;
    file << "       | |          | |  " << std::endl;
    file << std::endl;
    file.close();
}

std::string
ShrubberyCreationForm::getTarget() const {
    return _target;
}

std::ostream &
operator<<(std::ostream &out, ShrubberyCreationForm const &form) {
    out << "Form " << form.getName() << " is ";
    out << (form.getSigned() ? "signed." : "not signed.") << std::endl;
    out << "Grade required to sign: " << form.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << form.getGradeToExecute()
        << std::endl;
    out << "Target: " << form.getTarget() << std::endl;
    return out;
}
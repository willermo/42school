/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:13:23 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:24:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute)
    : _name(name), _signed(false), _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute) {
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _signed(copy._signed),
      _grade_to_sign(copy._grade_to_sign),
      _grade_to_execute(copy._grade_to_execute) {
    if (copy._grade_to_sign < 1 || copy._grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    if (copy._grade_to_sign > 150 || copy._grade_to_execute > 150)
        throw AForm::GradeTooLowException();
}

AForm &
AForm::operator=(const AForm &copy) {
    if (this == &copy)
        return *this;
    _signed = copy._signed;
    return *this;
}

AForm::~AForm() {}

std::string
AForm::getName() const {
    return _name;
}

bool
AForm::getSigned() const {
    return _signed;
}

int
AForm::getGradeToSign() const {
    return _grade_to_sign;
}

int
AForm::getGradeToExecute() const {
    return _grade_to_execute;
}

void
AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _grade_to_sign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

void
AForm::execute(Bureaucrat const &executor) const {
    if (!_signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _grade_to_execute)
        throw AForm::GradeTooLowException();
}

const char *
AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *
AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *
AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream &
operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() << " is ";
    out << (form.getSigned() ? "signed." : "not signed.") << std::endl;
    out << "Grade required to sign: " << form.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << form.getGradeToExecute()
        << std::endl;
    return out;
}
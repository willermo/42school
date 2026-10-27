/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:51:51 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:24:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
    : _name("Form"), _signed(false), _grade_to_sign(150),
      _grade_to_execute(150) {}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute)
    : _name(name), _signed(false), _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute) {
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy)
    : _name(copy._name), _signed(copy._signed),
      _grade_to_sign(copy._grade_to_sign),
      _grade_to_execute(copy._grade_to_execute) {
    if (copy._grade_to_sign < 1 || copy._grade_to_execute < 1)
        throw Form::GradeTooHighException();
    if (copy._grade_to_sign > 150 || copy._grade_to_execute > 150)
        throw Form::GradeTooLowException();
}

Form &
Form::operator=(const Form &copy) {
    if (this == &copy)
        return *this;
    _signed = copy._signed;
    return *this;
}

Form::~Form() {}

std::string
Form::getName() const {
    return _name;
}

bool
Form::getSigned() const {
    return _signed;
}

int
Form::getGradeToSign() const {
    return _grade_to_sign;
}

int
Form::getGradeToExecute() const {
    return _grade_to_execute;
}

void
Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _grade_to_sign)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char *
Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *
Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &
operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " is ";
    out << (form.getSigned() ? "signed." : "not signed.") << std::endl;
    out << "Grade required to sign: " << form.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << form.getGradeToExecute()
        << std::endl;
    return out;
}
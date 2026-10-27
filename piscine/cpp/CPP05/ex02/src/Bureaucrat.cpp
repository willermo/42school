/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:21:10 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:24:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Youdontknowme"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
    : _name(copy._name), _grade(copy._grade) {
    if (copy._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (copy._grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &
Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this == &copy)
        return *this;
    _grade = copy._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string
Bureaucrat::getName() const {
    return _name;
}

int
Bureaucrat::getGrade() const {
    return _grade;
}

void
Bureaucrat::incrementGrade(int n) {
    if (_grade - n < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade -= n;
}

void
Bureaucrat::decrementGrade(int n) {
    if (_grade + n > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade += n;
}

void
Bureaucrat::incrementGrade() {
    incrementGrade(1);
}

void
Bureaucrat::decrementGrade() {
    decrementGrade(1);
}

void
Bureaucrat::signForm(AForm &form) {
    if (_grade > form.getGradeToSign()) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because ";
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << _name << " signed " << form.getName() << std::endl;
    form.beSigned(*this);
}

void
Bureaucrat::executeForm(AForm const &form) {
    if (_grade > form.getGradeToExecute()) {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because ";
        throw Bureaucrat::GradeTooLowException();
    }
    if (!form.getSigned()) {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because ";
        throw AForm::FormNotSignedException();
    }
    form.execute(*this);
    std::cout << _name << " executed " << form.getName() << std::endl;
}

const char *
Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *
Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &
operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getGrade() << std::endl;
    return out;
}

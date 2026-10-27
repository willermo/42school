/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:23:52 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:17:48 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

static int dummy_random_seeder = (std::srand(time(0)), 0);

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    if (this == &other)
        return *this;
    AForm::operator=(other);
    _target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void
RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    if (rand() % 2)
        std::cout << "\a\aBEEP! " << _target << " has not been robotomized."
                  << std::endl;
    else
        std::cout << "\a\aBEEP! " << _target
                  << " has been robotomized successfully." << std::endl;
}

std::string
RobotomyRequestForm::getTarget() const {
    return _target;
}

std::ostream &
operator<<(std::ostream &out, RobotomyRequestForm const &form) {
    out << "Form " << form.getName() << " is ";
    out << (form.getSigned() ? "signed." : "not signed.") << std::endl;
    out << "Grade required to sign: " << form.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << form.getGradeToExecute()
        << std::endl;
    out << "Target: " << form.getTarget() << std::endl;
    return out;
}
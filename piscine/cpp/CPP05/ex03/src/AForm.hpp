/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:13:25 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:24:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string _name;
    bool _signed;
    const int _grade_to_sign;
    const int _grade_to_execute;

  public:
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm();
    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const;
    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif
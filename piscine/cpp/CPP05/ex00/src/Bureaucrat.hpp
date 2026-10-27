/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:21:15 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:24:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
  private:
    std::string const _name;
    int _grade;

  public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void incrementGrade(int n);
    void decrementGrade();
    void decrementGrade(int n);
    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
#endif

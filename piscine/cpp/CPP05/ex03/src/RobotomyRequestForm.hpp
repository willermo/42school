/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:21:24 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:40:49 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  private:
    std::string _target;

  public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const &executor) const;
    std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif
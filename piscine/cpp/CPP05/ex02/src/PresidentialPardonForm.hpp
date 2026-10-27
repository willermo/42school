/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:44:15 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 12:41:00 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
    std::string _target;

  public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const &executor) const;
    std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &form);

#endif
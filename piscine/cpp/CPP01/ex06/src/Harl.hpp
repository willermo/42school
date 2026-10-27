/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:45:45 by doriani           #+#    #+#             */
/*   Updated: 2023/11/30 01:59:23 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define LEVELS_NUMBER 4
#define DEBUG_MESSAGE                                                          \
    "I love having extra bacon for my "                                        \
    "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO_MESSAGE                                                           \
    "I cannot believe adding extra bacon costs more money. You didn’t put "  \
    "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING_MESSAGE                                                        \
    "I think I deserve to have some extra bacon for free. I’ve been coming " \
    "for years whereas you started working here since last month."
#define ERROR_MESSAGE                                                          \
    "This is unacceptable! I want to speak to the manager now."
#define INVALID_MESSAGE "[ Probably complaining about insignificant problems ]"

#define DEBUG_COLOR   "\033[36m"
#define INFO_COLOR    "\033[0m"
#define WARNING_COLOR "\033[33m"
#define ERROR_COLOR   "\033[1;31m"
#define RESET_COLOR   "\033[0m"
#define INVALID_COLOR "\033[7m"

class Harl {
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

  public:
    Harl();
    ~Harl();
    void complain(std::string level);
};

#endif
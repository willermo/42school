/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:33:19 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 18:00:03 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <sstream>
#include <string>

class Brain {
  private:
    std::string ideas[100];

  public:
    Brain(void);
    ~Brain(void);
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);

    void setIdea(int idx, std::string idea);
    std::string getIdea(int idx) const;
    void resetIdeas(void);
    void copyIdeas(const Brain &other);
};

#endif
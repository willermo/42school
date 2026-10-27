/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:33:10 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 18:06:30 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain constructor called" << std::endl;
    resetIdeas();
}

Brain::~Brain(void) { std::cout << "Brain destructor called" << std::endl; }

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain &
Brain::operator=(const Brain &other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        copyIdeas(other);
    }
    return (*this);
}

void
Brain::setIdea(int idx, std::string idea) {
    if (idx >= 0 && idx < 100)
        this->ideas[idx] = idea;
}

std::string
Brain::getIdea(int idx) const {
    if (idx >= 0 && idx < 100)
        return (this->ideas[idx]);
    return ("");
}

void
Brain::resetIdeas(void) {
    for (int i = 0; i < 100; i++) {
        std::stringstream ss;
        ss << i;
        this->setIdea(i, "Idea #" + ss.str());
    }
}

void
Brain::copyIdeas(const Brain &other) {
    for (int i = 0; i < 100; i++)
        this->setIdea(i, other.getIdea(i));
}
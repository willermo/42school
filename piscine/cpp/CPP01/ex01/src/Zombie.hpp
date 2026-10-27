/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:15:22 by doriani           #+#    #+#             */
/*   Updated: 2023/11/28 20:57:28 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
private:
    std::string name;
public:
    void    announce( void );
    void    setName(std::string name);
    Zombie(std::string name);
    Zombie( void );
    ~Zombie( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif
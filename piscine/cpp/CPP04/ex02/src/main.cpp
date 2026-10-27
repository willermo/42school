/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:18:40 by doriani           #+#    #+#             */
/*   Updated: 2024/01/04 17:59:18 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int
main(void) {

    const Animal *animals[10];
    std::cout << WHITE_K "Calling constructors" << RESET << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << std::endl
                  << GREEN_B << "Constructing animal " << i << RESET
                  << std::endl;
        animals[i] = new Dog();
    }
    for (int i = 5; i < 10; i++) {
        std::cout << std::endl
                  << GREEN_B << "Constructing animal " << i << RESET
                  << std::endl;
        animals[i] = new Cat();
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl;
        std::cout << WHITE_K "Testing Animal " << i << RESET << std::endl;
        std::cout << BLUE << "Animal " << i << " getType(): " << RESET;
        std::cout << animals[i]->getType() << std::endl;
        std::cout << BLUE << "Animal " << i << " makeSound(): " << RESET;
        animals[i]->makeSound();
        std::cout << BLUE << "First three ideas of animal " << i << ": "
                  << RESET << std::endl;
        for (int j = 0; j < 3; j++) {
            if (i < 5)
                std::cout << "\t" << WHITE_B << animals[i]->getIdea(j) << RESET
                          << std::endl;
            else
                std::cout << "\t" << WHITE_B << animals[i]->getIdea(j) << RESET
                          << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << YELLOW_B
              << "Setting idea #1 of animal 0 to \"Idea #1 modified\"" << RESET
              << std::endl;
    ((Dog *) animals[0])->setIdea(1, "Idea #1 modified");
    std::cout << BLUE << "First three ideas of animal 0: " << RESET
              << std::endl;
    for (int j = 0; j < 3; j++) {
        std::cout << "\t" << WHITE_B << ((Dog *) animals[0])->getIdea(j)
                  << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << WHITE_K "Calling destructors" << RESET << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl
                  << RED_B << "Deleting animal " << i << RESET << std::endl;
        delete animals[i];
    }
    std::cout << std::endl;

    std::cout << WHITE_K "Further tests" << RESET << std::endl;
    std::cout << std::endl
              << GREEN_B << "Constructing Dog \"Dog\"" << RESET << std::endl;
    Dog *dog = new Dog();
    std::cout << std::endl
              << GREEN_B << "Constructing Cat \"Cat\"" << RESET << std::endl;
    Cat *cat = new Cat();
    std::cout << std::endl
              << GREEN_B << "Constructing Dog \"Dog2\" with cc" << RESET
              << std::endl;
    Dog dog2(*dog);
    std::cout << std::endl
              << GREEN_B << "Constructing Cat \"Cat2\" with cc" << RESET
              << std::endl;
    Cat cat2(*cat);
    std::cout << std::endl
              << GREEN_B << "Constructing Cat \"strayCat\" with ao" << RESET
              << std::endl;
    Cat strayCat;
    strayCat = *cat;
    std::cout << std::endl
              << RED_B << "Deleting Dog \"Dog\"" << RESET << std::endl;
    delete dog;
    std::cout << std::endl
              << RED_B << "Deleting Cat \"Cat\"" << RESET << std::endl;
    delete cat;
    std::cout << std::endl
              << RED_B << "Autodeleting animals on stack" << RESET << std::endl;

    /*
     * INVALID TESTS (UNCOMMENT TO CHECK)
     */
    // Animal animal0;
    // Animal animal1 = Animal();
    // Animal animal2 = Animal("Can't do this");

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:18:40 by doriani           #+#    #+#             */
/*   Updated: 2023/12/17 17:06:43 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int
main(void) {

    // TEST ANIMAL
    std::cout << std::endl
              << WHITE_K << "* Test Animal * " << RESET << std::endl
              << std::endl;
    std::cout << BLUE_U << "Executing command:" << RESET << BRIGHT_BLUE
              << " Animal animal = new Animal()" << RESET << std::endl;
    Animal *animal = new Animal();

    std::cout << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << animal->getType() << std::endl" << RESET
              << std::endl;
    std::cout << animal->getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "animal->makeSound()" << RESET << std::endl;
    animal->makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "delete animal" << RESET << std::endl;
    delete animal;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "Animal b = new Animal(\"Sucantropo\")" << RESET << std::endl;
    Animal *b = new Animal("Sucantropo");

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << b->getType() << std::endl" << RESET << std::endl;
    std::cout << b->getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "b->makeSound()" << RESET << std::endl;
    b->makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "Animal c(*b)" << RESET << std::endl;
    Animal *c = new Animal(*b);

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << c->getType() << std::endl" << RESET << std::endl;
    std::cout << c->getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "c->makeSound()" << RESET << std::endl;
    c->makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "Animal c2" << RESET << std::endl;
    Animal c2;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "c2 = *c" << RESET << std::endl;
    c2 = *c;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << c2.getType() << std::endl" << RESET << std::endl;
    std::cout << c2.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "c2.makeSound()" << RESET << std::endl;
    c2.makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "delete c" << RESET << std::endl;
    delete c;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "delete b" << RESET << std::endl;
    delete b;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "Animal *d = new Animal()" << RESET << std::endl;
    Animal *d = new Animal();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << d->getType() << std::endl" << RESET << std::endl;
    std::cout << d->getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "d->makeSound()" << RESET << std::endl;
    d->makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "delete d" << RESET << std::endl;
    delete d;

    // TEST CAT
    std::cout << std::endl
              << WHITE_K << "* Test Cat * " << RESET << std::endl
              << std::endl;
    std::cout << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "Cat cat" << RESET << std::endl;
    Cat cat;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << cat.getType() << std::endl" << RESET
              << std::endl;
    std::cout << cat.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "cat.makeSound()" << RESET << std::endl;
    cat.makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "Cat cat2(cat)" << RESET << std::endl;
    Cat cat2(cat);

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << cat2.getType() << std::endl" << RESET
              << std::endl;
    std::cout << cat2.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "cat2.makeSound()" << RESET << std::endl;
    cat2.makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "Cat cat3" << RESET << std::endl;
    Cat cat3;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "cat3 = cat2" << RESET << std::endl;
    cat3 = cat2;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << cat3.getType() << std::endl" << RESET
              << std::endl;
    std::cout << cat3.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "cat3.makeSound()" << RESET << std::endl;
    cat3.makeSound();

    // TEST DOG
    std::cout << std::endl
              << WHITE_K << "* Test Dog * " << RESET << std::endl
              << std::endl;
    std::cout << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "Dog dog" << RESET << std::endl;
    Dog dog;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << dog.getType() << std::endl" << RESET
              << std::endl;
    std::cout << dog.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "dog.makeSound()" << RESET << std::endl;
    dog.makeSound();

    // TEST WRONGANIMAL
    std::cout << std::endl
              << WHITE_K << "* Test WrongAnimal * " << RESET << std::endl
              << std::endl;
    std::cout << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "WrongAnimal wrongAnimal" << RESET << std::endl;
    WrongAnimal wrongAnimal;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << wrongAnimal.getType() << std::endl" << RESET
              << std::endl;
    std::cout << wrongAnimal.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "wrongAnimal.makeSound()" << RESET << std::endl;
    wrongAnimal.makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "WrongAnimal wrongAnimal2(wrongAnimal)" << RESET << std::endl;
    WrongAnimal wrongAnimal2(wrongAnimal);

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << wrongAnimal2.getType() << std::endl" << RESET
              << std::endl;
    std::cout << wrongAnimal2.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "wrongAnimal2.makeSound()" << RESET << std::endl;
    wrongAnimal2.makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "WrongAnimal wrongAnimal3" << RESET << std::endl;
    WrongAnimal wrongAnimal3;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "wrongAnimal3 = wrongAnimal2" << RESET << std::endl;
    wrongAnimal3 = wrongAnimal2;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << wrongAnimal3.getType() << std::endl" << RESET
              << std::endl;
    std::cout << wrongAnimal3.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "wrongAnimal3.makeSound()" << RESET << std::endl;
    wrongAnimal3.makeSound();

    // TEST WRONGCAT
    std::cout << std::endl
              << WHITE_K << "* Test WrongCat * " << RESET << std::endl
              << std::endl;
    std::cout << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "WrongCat wrongCat" << RESET << std::endl;
    WrongCat wrongCat;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << wrongCat.getType() << std::endl" << RESET
              << std::endl;
    std::cout << wrongCat.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "wrongCat.makeSound()" << RESET << std::endl;
    wrongCat.makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "WrongCat wrongCat2(wrongCat)" << RESET << std::endl;
    WrongCat wrongCat2(wrongCat);

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << wrongCat2.getType() << std::endl" << RESET
              << std::endl;
    std::cout << wrongCat2.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "wrongCat2.makeSound()" << RESET << std::endl;
    wrongCat2.makeSound();

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "WrongCat wrongCat3" << RESET << std::endl;
    WrongCat wrongCat3;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "wrongCat3 = wrongCat2" << RESET << std::endl;
    wrongCat3 = wrongCat2;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "std::cout << wrongCat3.getType() << std::endl" << RESET
              << std::endl;
    std::cout << wrongCat3.getType() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE_U << "Executing command: " << BRIGHT_BLUE
              << "wrongCat3.makeSound()" << RESET << std::endl;
    wrongCat3.makeSound();

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:41:55 by doriani           #+#    #+#             */
/*   Updated: 2023/12/15 15:17:33 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>

void
printSeparator(std::string left, std::string mid, std::string right) {
    std::cout << left;
    // Player name
    for (int i = 0; i < 18; i++)
        std::cout << "─";
    std::cout << mid;
    // HP
    for (int i = 0; i < 4; i++)
        std::cout << "─";
    std::cout << mid;
    // Energy
    for (int i = 0; i < 8; i++)
        std::cout << "─";
    std::cout << right << std::endl;
}

void
printHeader() {
    std::cout << "│"
              << "   Player name    "
              << "│"
              << " HP "
              << "│"
              << " Energy "
              << "│" << std::endl;
}

void
printPlayer(ClapTrap *player) {
    std::cout << "│" << std::setw(18) << player->getName() << "│"
              << std::setw(4) << player->getHitPoints() << "│" << std::setw(8)
              << player->getEnergyPoints() << "│" << std::endl;
}

void
printArena(void) {
    std::cout << std::endl;
    std::cout << CYAN_K << "Arena stats" << RESET << std::endl;
    printSeparator("┌", "┬", "┐");
    printHeader();
    printSeparator("├", "┼", "┤");
    for (int i = 0; i < ARENA_SLOTS; i++) {
        ClapTrap *player = ClapTrap::getPlayer(i);
        if (!player)
            break;
        printPlayer(player);
        if (i + 1 < ARENA_SLOTS && ClapTrap::getPlayer(i + 1))
            printSeparator("├", "┼", "┤");
    }
    printSeparator("└", "┴", "┘");
    std::cout << std::endl;
}

bool
checkVictory() {
    int i = 0;
    int dead_players = 0;
    ClapTrap *winner;
    while (i < ARENA_SLOTS) {
        if (ClapTrap::getPlayer(i++)->isDead())
            dead_players++;
        else
            winner = ClapTrap::getPlayer(i - 1);
    }
    if (dead_players == ARENA_SLOTS - 1) {
        std::cout << GREEN << "There is only one player left! "
                  << winner->getName() << " wins!" << RESET << std::endl;
        return true;
    }
    return false;
}

int
rollDices(int times, int min, int max) {
    int result = 0;
    for (int i = 0; i < times; i++)
        result += std::rand() % (max - min + 1) + min;
    return result;
}

int
main(void) {
    std::srand(std::time(NULL));

    ClapTrap player1("Pippo", rollDices(3, 1, 6), rollDices(2, 1, 6),
                     rollDices(1, 1, 4));
    ClapTrap player2(player1);
    ClapTrap player3("Pluto");
    player2 = player3;
    ClapTrap player4("Paperino");
    printArena();
    int i = 0;
    std::string action;
    while (true) {
        if (checkVictory())
            break;
        ClapTrap *player = ClapTrap::getPlayer(i++ % ARENA_SLOTS);
        if (!player)
            continue;
        std::cout << std::endl;
        std::cout << BLUE_U << "It's " << player->getName() << "'s turn!"
                  << RESET << std::endl;
        std::cout << "What do you want to do? (attack, repair, exit): ";
        std::cin >> action;
        if (!action.compare("attack")) {
            std::string target;
            std::cout << "Who do you want to attack? ";
            std::cin >> target;
            player->attack(target);
        } else if (!action.compare("repair")) {
            player->beRepaired(10);
        } else if (!action.compare("exit")) {
            std::cout << "Bye!" << std::endl;
            break;
        } else {
            std::cout << "Bad request." << std::endl;
            i--;
            continue;
        }
        printArena();
    }
}
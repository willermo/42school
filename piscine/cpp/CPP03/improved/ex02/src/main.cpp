/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:41:55 by doriani           #+#    #+#             */
/*   Updated: 2023/12/15 22:15:38 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
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
    std::cout << mid;
    // GK mode
    for (int i = 0; i < 9; i++)
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
              << "│"
              << " GK mode "
              << "│" << std::endl;
}

void
printPlayer(ClapTrap *player) {
    if (dynamic_cast<ScavTrap *>(player) != NULL) {
        std::cout << "│" << std::setw(18) << player->getName() << "│"
                  << std::setw(4) << player->getHitPoints() << "│"
                  << std::setw(8) << player->getEnergyPoints() << "│"
                  << std::setw(9) << dynamic_cast<ScavTrap *>(player)->getMode()
                  << "│" << std::endl;
    } else
        std::cout << "│" << std::setw(18) << player->getName() << "│"
                  << std::setw(4) << player->getHitPoints() << "│"
                  << std::setw(8) << player->getEnergyPoints() << "│"
                  << std::setw(9) << "N/A"
                  << "│" << std::endl;
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

    ClapTrap player1("Pippo");
    ScavTrap player2("Pluto");
    FragTrap player3("Paperino");
    ClapTrap player4("Topolino");
    printArena();
    int i = 0;
    std::string action;
    while (true) {
        if (checkVictory())
            break;
        ClapTrap *player = ClapTrap::getPlayer(i++ % ARENA_SLOTS);
        if (!player || player->isDead())
            continue;
        std::cout << std::endl;
        std::cout << BLUE_U << "It's " << player->getName() << "'s turn!"
                  << RESET << std::endl;
        if (dynamic_cast<ScavTrap *>(player) != NULL)
            std::cout
                << "What do you want to do? (attack, repair, guard, exit): ";
        else if (dynamic_cast<FragTrap *>(player) != NULL)
            std::cout
                << "What do you want to do? (attack, repair, highfive, exit): ";
        else
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
        } else if (!action.compare("guard")) {
            if (dynamic_cast<ScavTrap *>(player) != NULL)
                dynamic_cast<ScavTrap *>(player)->guardGate();
            else {
                std::cout << PURPLE
                          << "Don't cheat! You cannot enter in Gate "
                             "Keeper mode!"
                          << RESET << std::endl;
                i--;
                continue;
            }
        } else if (!action.compare("highfive")) {
            if (dynamic_cast<FragTrap *>(player) != NULL)
                dynamic_cast<FragTrap *>(player)->highFive();
            else {
                std::cout << PURPLE << "Don't cheat! You cannot give High Five!"
                          << RESET << std::endl;
                i--;
                continue;
            }
        } else {
            std::cout << "Bad request." << std::endl;
            i--;
            continue;
        }
        printArena();
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:52:10 by doriani           #+#    #+#             */
/*   Updated: 2024/03/23 20:44:19 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
  public:
    BitcoinExchange(std::string dbfile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &src);

    float getValueOfNearestDate(const std::string &date) const;
    float getConvertedAmount(const std::string &date, float amount) const;
    std::string transctionToString(const std::string &date, float amount,
                                   std::string linestring) const;
    void printTransactions(const std::string &transaction_file) const;

  private:
    /* data */
    std::map<std::string, float> db;
};

bool isValidLine(std::string line);
bool isValidFloat(std::string str);
bool isLeapYear(int year);
bool isValidDate(const std::string &date);
std::string floatToString(float value);
std::string trim(const std::string &str);

#endif
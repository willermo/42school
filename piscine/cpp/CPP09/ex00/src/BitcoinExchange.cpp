/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:52:24 by doriani           #+#    #+#             */
/*   Updated: 2024/03/23 20:54:24 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string dbfile) {
    std::ifstream file(dbfile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file");
    }

    std::istringstream value_stream;
    std::string line;
    std::string key;
    float value;
    std::getline(file, line);   // Skip the first line
    while (std::getline(file, line)) {
        key = line.substr(0, line.find(","));
        value_stream.clear();
        value_stream.str(line.substr(line.find(",") + 1));
        value_stream >> value;
        db[key] = value;
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &
BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src) {
        this->db = src.db;
    }
    return *this;
}

float
BitcoinExchange::getValueOfNearestDate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = db.lower_bound(date);

    if (db.empty())
        throw std::runtime_error("Error: Database is empty");

    if (it == db.end())
        return (--it)->second;

    if (it->first == date)
        return it->second;
    else if (it == db.begin())
        throw std::runtime_error("Error: No valid records for the given date");
    else
        return (--it)->second;
}

float
BitcoinExchange::getConvertedAmount(const std::string &date,
                                    float amount) const {
    if (!isValidDate(date))
        throw std::runtime_error("Error: Invalid date: " + date);
    return BitcoinExchange::getValueOfNearestDate(date) * amount;
}

std::string
floatToString(float value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string
BitcoinExchange::transctionToString(const std::string &date, float amount,
                                    std::string linestring) const {
    if (!isValidDate(date))
        return "\e[38;5;1mError on line " + linestring +
               ": Invalid date.\e[0m (Date given: " + date + ")";
    if (amount < 0)
        return "\e[38;5;1mError on line " + linestring +
               ": Amount must be positive.\e[0m (Amount "
               "given: " +
               floatToString(amount) + ")";
    if (amount > 1000)
        return "\e[38;5;1mError on line " + linestring +
               ": Amount can't exceed 1000.\e[0m (Amount "
               "given: " +
               floatToString(amount) + ")";
    return date + " => " + floatToString(amount) + " = " +
           floatToString(getConvertedAmount(date, amount));
}

void
BitcoinExchange::printTransactions(const std::string &transactions_file) const {
    std::ifstream transactions(transactions_file.c_str());
    if (!transactions.is_open()) {
        throw std::runtime_error("Error: could not open file");
    }
    std::string date;
    float amount;
    std::string line;
    unsigned int line_number = 0;
    std::stringstream ss;
    std::string linestring;
    std::istringstream value_stream;
    while (std::getline(transactions, line)) {
        line_number++;
        ss.str("");
        ss << line_number;
        linestring = ss.str();
        if (line.empty()) {
            std::cout << "\e[38;5;3mWarning: line " + linestring +
                             " is empty.\e[0m (Skipping line)"
                      << std::endl;
            continue;
        }
        if (!isValidLine(line)) {
            std::cout << "\e[38;5;1mError: bad input on line " + linestring +
                             ".\e[0m (Input given: " + line + ")"
                      << std::endl;
            continue;
        }
        date = trim(line.substr(0, line.find("|")));
        if (date == "date")
            continue;
        value_stream.clear();
        value_stream.str(trim(line.substr(line.find("|") + 1)));
        value_stream >> amount;
        std::cout << transctionToString(date, amount, linestring) << std::endl;
    }
}

bool
isValidFloat(std::string str) {
    int dotCount = 0;
    bool negative = false;
    for (std::string::size_type i = 0; i < str.size(); ++i) {
        if (!std::isdigit(str[i])) {
            if (str[i] == '.' && dotCount == 0 && i != str.size() - 1) {
                dotCount++;
            } else if (str[i] == '-' && i == 0 && !negative) {
                negative = true;

            } else {
                return false;
            }
        }
    }
    return true;
}

bool
isValidLine(std::string line) {
    std::string::size_type delimiter = line.find("|");
    if (delimiter == std::string::npos)
        return false;
    std::string date = trim(line.substr(0, delimiter));
    std::string amount = trim(line.substr(delimiter + 1));
    if (date == "date" || amount == "value")
        return true;
    if (!isValidFloat(amount))
        return false;
    return true;
}

bool
isLeapYear(int year) {
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

bool
isValidDate(const std::string &date) {
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    std::istringstream value_stream;
    int year;
    int month;
    int day;
    value_stream.clear();
    value_stream.str(date.substr(0, 4));
    value_stream >> year;
    value_stream.clear();
    value_stream.str(date.substr(5, 2));
    value_stream >> month;
    value_stream.clear();
    value_stream.str(date.substr(8, 2));
    value_stream >> day;
    switch (month) {
    case 2:
        if (isLeapYear(year))
            return day <= 29;
        else
            return day <= 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return day <= 30;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return day <= 31;
    default:
        return false;
    }

    return true;
}

std::string
trim(const std::string &str) {
    std::string::size_type start = 0;
    std::string::size_type end = str.size();
    while (start < end && std::isspace(str[start])) {
        ++start;
    }
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }
    return str.substr(start, end - start);
}
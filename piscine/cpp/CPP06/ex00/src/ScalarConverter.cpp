/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:12:36 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 20:47:26 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }

ScalarConverter &
ScalarConverter::operator=(const ScalarConverter &src) {
    if (this == &src)
        return *this;
    return *this;
}

int
ScalarConverter::detectLiteralType(const std::string &str) {
    // string ending with a dot
    if (str[str.size() - 1] == '.')
        return 0;
    // single character enclosed in quotes
    if (str.size() == 3 && str[0] == '"' && str[2] == '"')
        return CHAR_LITERAL;
    // single character without quotes
    if (str.size() == 1 && std::isprint(str[0]))
        return CHAR_LITERAL;
    // integer
    bool isInt = true;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (it == str.begin() && *it == '-')
            continue;
        if (!std::isdigit(*it)) {
            isInt = false;
            break;
        }
    }
    if (isInt)
        return INT_LITERAL;
    // check double dot
    std::string::size_type dot_pos = str.find('.');
    for (size_t i = dot_pos + 1; i < str.size() - 1; i++)
        if (str[i] == '.')
            return 0;
    // float
    if (str[str.size() - 1] == 'f') {
        for (size_t i = 0; i < str.size() - 1; i++) {
            if (i == 0 && str[i] == '-')
                continue;
            if (!(std::isdigit(str[i]) || str[i] == '.'))
                return 0;
        }
        if (str[str.size() - 2] == '.')
            return 0;
        return FLOAT_LITERAL;
    }
    // double
    if (dot_pos != std::string::npos) {
        for (size_t i = 0; i < str.size(); i++) {
            if (i == 0 && str[i] == '-')
                continue;
            if (!(std::isdigit(str[i]) || str[i] == '.'))
                return 0;
        }
        if (str[str.size() - 1] == '.')
            return 0;
        return DOUBLE_LITERAL;
    }
    // string is not a literal
    return 0;
}

int
ScalarConverter::_isSpecialCase(std::string str) {
    if (str == "-inf")
        return MINUS_INF;
    if (str == "+inf")
        return PLUS_INF;
    if (str == "-inff")
        return MINUS_INFF;
    if (str == "+inff")
        return PLUS_INFF;
    if (str == "nan")
        return NOT_A_NUMBER;
    if (str == "nanf")
        return NOT_A_NUMBER_FLOAT;

    return 0;
}

void
ScalarConverter::_printChar(int literal, int special_case, std::string str) {
    std::cout << "char: ";
    try {
        int i;
        std::istringstream iss(str);
        iss >> i;
        char c = static_cast<char>(i);
        if (!literal || special_case || i < 0 || i > 127)
            throw std::exception();
        if (literal == CHAR_LITERAL)
            std::cout << "'" << str << "'" << std::endl;
        else if (std::isprint(c))
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

void
ScalarConverter::_printInt(int literal, int special_case, std::string str) {
    std::cout << "int: ";
    try {
        if (!literal || special_case)
            throw std::exception();
        int i;
        if (literal == CHAR_LITERAL && (str[0] < '0' || str[0] > '9')) {
            i = static_cast<int>(str[0]);
            std::cout << i << " (ASCII)" << std::endl;
        } else {
            if (str.find('.') != std::string::npos)
                str = str.substr(0, str.find('.'));
            std::istringstream iss(str);
            iss >> i;
            std::cout << i << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

void
ScalarConverter::_printFloat(int literal, int special_case, std::string str) {
    std::cout << "float: ";
    try {
        float f;
        std::istringstream iss(str);
        iss >> f;
        switch (special_case) {
        case MINUS_INFF:
        case MINUS_INF:
            std::cout << "-inff" << std::endl;
            return;
        case PLUS_INFF:
        case PLUS_INF:
            std::cout << "+inff" << std::endl;
            return;
        case NOT_A_NUMBER:
        case NOT_A_NUMBER_FLOAT:
            std::cout << "nanf" << std::endl;
            return;
        default:
            if (!literal)
                throw std::exception();
            std::string::size_type dot_pos = str.find('.');
            if (str[str.size() - 1] == 'f')
                str = str.substr(0, str.size() - 1);
            size_t precision =
                dot_pos != std::string::npos ? str.size() - dot_pos - 1 : 1;
            precision = precision < 1 ? 1 : precision;
            std::ostringstream oss;
            oss << f;
            std::string float_str = oss.str();
            dot_pos = float_str.find('.');
            if (dot_pos != std::string::npos &&
                float_str.size() - dot_pos - 1 > precision) {
                float_str = float_str.substr(0, dot_pos + precision + 1);
            }
            if (float_str.find('.') == std::string::npos)
                float_str += ".0";
            std::cout << float_str << "f" << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

void
ScalarConverter::_printDouble(int literal, int special_case, std::string str) {
    std::cout << "double: ";
    try {
        double d;
        std::istringstream iss(str);
        iss >> d;
        switch (special_case) {
        case MINUS_INF:
        case MINUS_INFF:
            std::cout << "-inf" << std::endl;
            return;
        case PLUS_INF:
        case PLUS_INFF:
            std::cout << "+inf" << std::endl;
            return;
        case NOT_A_NUMBER:
        case NOT_A_NUMBER_FLOAT:
            std::cout << "nan" << std::endl;
            return;
        default:
            if (!literal)
                throw std::exception();
            std::string::size_type dot_pos = str.find('.');
            size_t precision =
                dot_pos != std::string::npos ? str.size() - dot_pos - 1 : 1;
            precision = precision < 1 ? 1 : precision;
            std::ostringstream oss;
            oss << d;
            std::string double_str = oss.str();
            dot_pos = double_str.find('.');
            if (dot_pos != std::string::npos &&
                double_str.size() - dot_pos - 1 > precision) {
                double_str = double_str.substr(0, dot_pos + precision + 1);
            }
            if (double_str.find('.') == std::string::npos)
                double_str += ".0";
            std::cout << double_str << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

void
ScalarConverter::convert(std::string str) {
    int special_case_number = _isSpecialCase(str);
    int literal = detectLiteralType(str);
    _printChar(literal, special_case_number, str);
    _printInt(literal, special_case_number, str);
    _printFloat(literal, special_case_number, str);
    _printDouble(literal, special_case_number, str);
}

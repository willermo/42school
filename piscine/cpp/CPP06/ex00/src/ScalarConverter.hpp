/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:12:33 by doriani           #+#    #+#             */
/*   Updated: 2024/03/19 18:38:43 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
  private:
    enum special_cases {
        MINUS_INF = 1,
        PLUS_INF,
        MINUS_INFF,
        PLUS_INFF,
        NOT_A_NUMBER,
        NOT_A_NUMBER_FLOAT,
        PARSE_ERROR
    };
    enum literals {
        CHAR_LITERAL = 1,
        INT_LITERAL,
        FLOAT_LITERAL,
        DOUBLE_LITERAL
    };
    static int detectLiteralType(const std::string &str);
    static int _isSpecialCase(std::string str);
    static void _printChar(int literal, int special_case, std::string str);
    static void _printInt(int literal, int special_case, std::string str);
    static void _printFloat(int literal, int special_case, std::string str);
    static void _printDouble(int literal, int special_case, std::string str);

  public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &src);
    static void convert(std::string str);
};

#endif

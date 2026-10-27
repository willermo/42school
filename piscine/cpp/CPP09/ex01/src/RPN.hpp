/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:56:48 by doriani           #+#    #+#             */
/*   Updated: 2024/03/24 07:16:43 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {

  private:
    std::stack<double> _operands;
    double _result;
    const std::string _operators;

  public:
    RPN();
    RPN(const RPN &src);
    ~RPN();
    RPN &operator=(const RPN &src);

    void calculate(std::string &str);
    void performOperation(const std::string &op);
    void printResult();
    bool isOperator(const std::string &str) const;
    bool isValidOperand(const std::string &str) const;
};

double stod_98compliant(const std::string &token);

#endif
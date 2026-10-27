/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:57:08 by doriani           #+#    #+#             */
/*   Updated: 2024/03/24 07:20:38 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _operators("+-*/") { _result = 0; }

RPN::RPN(const RPN &src) { *this = src; }

RPN::~RPN() {}

RPN &
RPN::operator=(const RPN &src) {
    if (this != &src) {
        _operands = src._operands;
        _result = src._result;
    }
    return *this;
}

void
RPN::performOperation(const std::string &op) {
    if (_operands.size() < 2) {
        throw std::runtime_error("Invalid expression");
    }
    double right_operand = _operands.top();
    _operands.pop();
    double left_operand = _operands.top();
    _operands.pop();
    double result;
    switch (op[0]) {
    case '+':
        result = left_operand + right_operand;
        break;
    case '-':
        result = left_operand - right_operand;
        break;
    case '*':
        result = left_operand * right_operand;
        break;
    case '/':
        if (right_operand == 0)
            throw std::runtime_error("Division by zero");
        result = left_operand / right_operand;
        break;
    default:
        throw std::runtime_error("Invalid operator: " + op +
                                 " (this should never happen)");
    }
    _operands.push(result);
}

void
RPN::calculate(std::string &str) {
    std::istringstream iss(str);
    std::string token;

    if (str.empty()) {
        printResult();
        return;
    }
    while (iss >> token) {
        if (isOperator(token))
            performOperation(token);
        else if (isValidOperand(token)) {
            _operands.push(stod_98compliant(token));
        } else
            throw std::runtime_error("Invalid token: " + token);
        iss.clear();
    }
    if (_operands.size() != 1)
        throw std::runtime_error("Invalid expression: " + _operands.size());
    _result = _operands.top();
    _operands.pop();
    printResult();
}

void
RPN::printResult() {
    std::cout << "Result: " << _result << std::endl;
}

bool
RPN::isOperator(const std::string &str) const {
    if (str.size() != 1) {
        return false;
    }
    return _operators.find(str) != std::string::npos;
}

bool
RPN::isValidOperand(const std::string &str) const {
    if (str.empty()) {
        return false;
    }
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

double
stod_98compliant(const std::string &token) {

    std::istringstream iss(token);
    double value;
    iss >> value;
    if (!iss.fail()) {
        return value;
    } else {
        throw std::runtime_error("Invalid operand: " + token);
    }
}
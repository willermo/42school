/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 07:24:46 by doriani           #+#    #+#             */
/*   Updated: 2024/07/23 10:27:41 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector< int > &data) { storeSequenceVector(data); }

PmergeMe::PmergeMe(std::deque< int > &data) { storeSequenceDeque(data); }

PmergeMe::PmergeMe(char **data) { storeSequenceVector(data); }

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &
PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        this->_elements_v = src._elements_v;
        this->_elements_d = src._elements_d;
        buildPairsVector(_elements_v);
        buildPairsDeque(_elements_d);
    }
    return *this;
}

// VECTOR LOGIC

void
PmergeMe::displayElementsVector() const {
    for (std::vector< int >::const_iterator it = this->_elements_v.begin();
         it != this->_elements_v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void
PmergeMe::storeSequenceVector(char **argv) {
    for (size_t i = 0; argv[i]; i++) {
        if (!isValidInt(argv[i])) {
            throw std::invalid_argument("Invalid or negative argument");
        }
        int num = atoi(argv[i]);
        for (size_t i = 0; i < this->_elements_v.size(); i++) {
            if (this->_elements_v[i] == num) {
                throw std::invalid_argument("Duplicate argument");
            }
        }
        this->_elements_v.push_back(num);
    }
    buildPairsVector(_elements_v);
}

void
PmergeMe::storeSequenceVector(std::vector< int > &data) {
    this->_elements_v = data;
    buildPairsVector(_elements_v);
}

void
PmergeMe::buildPairsVector(std::vector< int > &data) {
    stray_element = (data.size() % 2) ? data.back() : -1;
    std::vector< int >::iterator it = data.begin();
    while (it != data.end() && (it + 1) != data.end()) {
        if (*it > *(it + 1)) {
            _pairs_v.push_back(std::make_pair(*it, *(it + 1)));
        } else {
            _pairs_v.push_back(std::make_pair(*(it + 1), *it));
        }
        it += 2;
    }
}

void
PmergeMe::sortAndDisplayVector() {
    std::vector< int > vec = this->sortVector();
    this->displayVector(vec);
}

std::vector< int >
PmergeMe::sortVector() {
    switch (_elements_v.size()) {
    case 1:
        return std::vector< int >(_elements_v);
    case 2:
        if (_elements_v[0] < _elements_v[1])
            return std::vector< int >(_elements_v);
        else {
            std::vector< int > sorted;
            sorted.push_back(_elements_v[1]);
            sorted.push_back(_elements_v[0]);
            return sorted;
        }
    }
    buildMainChainVector();
    return mergeInsertVector();
}

void
PmergeMe::displayVector(std::vector< int > &vec) const {
    for (std::vector< int >::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void
PmergeMe::buildMainChainVector() {
    if (_pairs_v.size() == 1) {
        _main_chain_v.push_back(_pairs_v.back());
        return;
    }
    std::vector< int > sorted_top = getSortedTopVector();
    for (std::vector< int >::iterator it = sorted_top.begin();
         it < sorted_top.end(); it++) {
        for (std::vector< std::pair< int, int > >::iterator pair =
                 _pairs_v.begin();
             pair < _pairs_v.end(); pair++) {
            if (pair->first == *it) {
                _main_chain_v.push_back(std::make_pair(*it, pair->second));
                _pairs_v.erase(pair);
                break;
            }
        }
    }
}

std::vector< int >
PmergeMe::getSortedTopVector() {
    std::vector< int > top_elements_v;
    for (std::vector< std::pair< int, int > >::iterator it = _pairs_v.begin();
         it != _pairs_v.end(); it++)
        top_elements_v.push_back(it->first);
    std::vector< int > sorted;
    if (top_elements_v.size() == 1)
        sorted.push_back(top_elements_v.back());
    else
        sorted = (PmergeMe(top_elements_v)).sortVector();
    return sorted;
}

std::vector< int >
PmergeMe::mergeInsertVector() {
    std::vector< int > sorted;
    int inserted = 0;
    sorted.push_back(_main_chain_v.begin()->second);
    inserted++;
    for (std::vector< std::pair< int, int > >::iterator it =
             _main_chain_v.begin();
         it < _main_chain_v.end(); it++) {
        sorted.push_back(it->first);
        inserted++;
    }
    int step = 1;
    size_t js_begin = JACOBSTAHL(step);
    size_t js_end = JACOBSTAHL(step + 1);
    if (_main_chain_v.size() < js_end)
        js_end = _main_chain_v.size();
    while (_main_chain_v.size() > js_begin) {
        while (js_begin < js_end) {
            binaryInsertVector(sorted, _main_chain_v[--js_end].second,
                               sorted.begin(), sorted.begin() + inserted++);
        }
        step++;
        js_begin = JACOBSTAHL(step);
        js_end = JACOBSTAHL(step + 1);
        if (_main_chain_v.size() < js_end)
            js_end = _main_chain_v.size();
    }
    if (stray_element > 0)
        binaryInsertVector(sorted, stray_element, sorted.begin(), sorted.end());
    return sorted;
}

void
PmergeMe::binaryInsertVector(std::vector< int > &vec, const int &value,
                             std::vector< int >::iterator start,
                             std::vector< int >::iterator end) {
    std::vector< int >::iterator insert_pos =
        std::lower_bound(start, end, value);
    vec.insert(insert_pos, value);
}

// DEQUE LOGIC

void
PmergeMe::displayElementsDeque() const {
    for (std::deque< int >::const_iterator it = this->_elements_d.begin();
         it != this->_elements_d.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void
PmergeMe::storeSequenceDeque(char **argv) {
    for (size_t i = 0; argv[i]; i++) {
        if (!isValidInt(argv[i])) {
            throw std::invalid_argument("Invalid or negative argument");
        }
        int num = atoi(argv[i]);
        for (size_t i = 0; i < this->_elements_d.size(); i++) {
            if (this->_elements_d[i] == num) {
                throw std::invalid_argument("Duplicate argument");
            }
        }
        this->_elements_d.push_back(num);
    }
    buildPairsDeque(_elements_d);
}

void
PmergeMe::storeSequenceDeque(std::deque< int > &data) {
    this->_elements_d = data;
    buildPairsDeque(_elements_d);
}

void
PmergeMe::buildPairsDeque(std::deque< int > &data) {
    stray_element = (data.size() % 2) ? data.back() : -1;
    std::deque< int >::iterator it = data.begin();
    while (it != data.end() && (it + 1) != data.end()) {
        if (*it > *(it + 1)) {
            _pairs_d.push_back(std::make_pair(*it, *(it + 1)));
        } else {
            _pairs_d.push_back(std::make_pair(*(it + 1), *it));
        }
        it += 2;
    }
}

void
PmergeMe::sortAndDisplayDeque() {
    std::deque< int > vec = this->sortDeque();
    this->displayDeque(vec);
}

std::deque< int >
PmergeMe::sortDeque() {
    switch (_elements_d.size()) {
    case 1:
        return std::deque< int >(_elements_d);
    case 2:
        if (_elements_d[0] < _elements_d[1])
            return std::deque< int >(_elements_d);
        else {
            std::deque< int > sorted;
            sorted.push_back(_elements_d[1]);
            sorted.push_back(_elements_d[0]);
            return sorted;
        }
    }
    buildMainChainDeque();
    return mergeInsertDeque();
}

void
PmergeMe::displayDeque(std::deque< int > &vec) const {
    for (std::deque< int >::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void
PmergeMe::buildMainChainDeque() {
    if (_pairs_d.size() == 1) {
        _main_chain_d.push_back(_pairs_d.back());
        return;
    }
    std::deque< int > sorted_top = getSortedTopDeque();
    for (std::deque< int >::iterator it = sorted_top.begin();
         it < sorted_top.end(); it++) {
        for (std::deque< std::pair< int, int > >::iterator pair =
                 _pairs_d.begin();
             pair < _pairs_d.end(); pair++) {
            if (pair->first == *it) {
                _main_chain_d.push_back(std::make_pair(*it, pair->second));
                _pairs_d.erase(pair);
                break;
            }
        }
    }
}

std::deque< int >
PmergeMe::getSortedTopDeque() {
    std::deque< int > top_elements_d;
    for (std::deque< std::pair< int, int > >::iterator it = _pairs_d.begin();
         it != _pairs_d.end(); it++)
        top_elements_d.push_back(it->first);
    std::deque< int > sorted;
    if (top_elements_d.size() == 1)
        sorted.push_back(top_elements_d.back());
    else
        sorted = (PmergeMe(top_elements_d)).sortDeque();
    return sorted;
}

std::deque< int >
PmergeMe::mergeInsertDeque() {
    std::deque< int > sorted;
    int inserted = 0;
    sorted.push_back(_main_chain_d.begin()->second);
    inserted++;
    for (std::deque< std::pair< int, int > >::iterator it =
             _main_chain_d.begin();
         it < _main_chain_d.end(); it++) {
        sorted.push_back(it->first);
        inserted++;
    }
    int step = 1;
    size_t js_begin = JACOBSTAHL(step);
    size_t js_end = JACOBSTAHL(step + 1);
    if (_main_chain_d.size() < js_end)
        js_end = _main_chain_d.size();
    while (_main_chain_d.size() > js_begin) {
        while (js_begin < js_end) {
            binaryInsertDeque(sorted, _main_chain_d[--js_end].second,
                              sorted.begin(), sorted.begin() + inserted++);
        }
        step++;
        js_begin = JACOBSTAHL(step);
        js_end = JACOBSTAHL(step + 1);
        if (_main_chain_d.size() < js_end)
            js_end = _main_chain_d.size();
    }
    if (stray_element > 0)
        binaryInsertDeque(sorted, stray_element, sorted.begin(), sorted.end());
    return sorted;
}

void
PmergeMe::binaryInsertDeque(std::deque< int > &vec, const int &value,
                            std::deque< int >::iterator start,
                            std::deque< int >::iterator end) {
    std::deque< int >::iterator insert_pos =
        std::lower_bound(start, end, value);
    vec.insert(insert_pos, value);
}

// UTILS

bool
isValidInt(const char *str) {
    if (!str || !*str || *str == '-') {
        return false;
    }
    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        ++str;
    }
    return true;
}
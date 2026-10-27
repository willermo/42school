/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 07:24:33 by doriani           #+#    #+#             */
/*   Updated: 2024/07/23 10:27:40 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <set>
#include <sstream>
#include <stdint.h>
#include <sys/time.h>
#include <vector>

#define JACOBSTAHL(n) (((1ull << (n)) - (((n) % 2) ? -1 : 1)) / 3)

class PmergeMe {
  private:
    int stray_element;
    // VECTOR LOGIC
    std::vector< int > _elements_v;
    std::vector< std::pair< int, int > > _pairs_v;
    std::vector< int > _sorted_top_v;
    std::vector< std::pair< int, int > > _main_chain_v;

    // DEQUE LOGIC
    std::deque< int > _elements_d;
    std::deque< std::pair< int, int > > _pairs_d;
    std::deque< int > _sorted_top_d;
    std::deque< std::pair< int, int > > _main_chain_d;

  public:
    PmergeMe();
    PmergeMe(std::vector< int > &data);
    PmergeMe(std::deque< int > &data);
    PmergeMe(char **data);
    ~PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    
    // VECTOR LOGIC
    void displayElementsVector() const;
    void storeSequenceVector(char **argv);
    void storeSequenceVector(std::vector< int > &data);
    void buildPairsVector(std::vector< int > &data);
    void sortAndDisplayVector();
    std::vector< int > sortVector();
    void displayVector(std::vector< int > &vec) const;
    void buildMainChainVector();
    std::vector< int > getSortedTopVector();
    std::vector< int > mergeInsertVector();
    void binaryInsertVector(std::vector< int > &vec, const int &value,
                      std::vector< int >::iterator start,
                      std::vector< int >::iterator end);

    // DEQUE LOGIC
    void displayElementsDeque() const;
    void storeSequenceDeque(char **argv);
    void storeSequenceDeque(std::deque< int > &data);
    void buildPairsDeque(std::deque< int > &data);
    void sortAndDisplayDeque();
    std::deque< int > sortDeque();
    void displayDeque(std::deque< int > &vec) const;
    void buildMainChainDeque();
    std::deque< int > getSortedTopDeque();
    std::deque< int > mergeInsertDeque();
    void binaryInsertDeque(std::deque< int > &vec, const int &value,
                      std::deque< int >::iterator start,
                      std::deque< int >::iterator end);

};

bool isValidInt(const char *str);

#endif
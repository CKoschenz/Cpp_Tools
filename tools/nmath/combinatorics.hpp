// *****************************************************************************
//
//  Purpose/Goal:
//
//  Details/Discussion:
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    Day Month year
//
//  Author:
//
//  References:
//
// *****************************************************************************

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Include Guards
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef COMBINATORICS_HPP
#define COMBINATORICS_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

/**
 * @brief Class calculation the complete set  of binomial coefficients up to 
 * given order or one coefficient or given (n,k)
 * 
 */
class Binomial {
    public:
        static std::vector<unsigned int> getKCoefficients(
            unsigned int n, 
            unsigned int k
        );
        static unsigned int getCoefficient(unsigned int n, unsigned int k);
        static std::vector<unsigned int> getAllCoefficients(unsigned int n);
};

/**
 * @brief Function return the factorial of positive integer n
 * 
 * @param n 
 * @return long int 
 */
long unsigned int factorial(unsigned int n);

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// End Include Guards
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif
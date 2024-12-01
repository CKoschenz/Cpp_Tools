// *****************************************************************************
//
//  Purpose/Goal:
//      Numerical differentiation by finite sums
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
#ifndef FINITE_DIFFERENTIATION_HPP
#define FINITE_DIFFERENTIATION_HPP

#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>

#include <vanderwaals/nmath/combinatorics.hpp>

/**
 * 
 */
class Finite_Differentiation {
public:
    std::vector<double> finite_diff(
        unsigned int n,
        double h,
        std::vector<double> fct_values
    );

    std::vector<double> enhanced_first_order_diff(
        double h,
        std::vector<double> fct_values
    );

    std::vector<double> forward_diff(
        unsigned int n,
        double h,
        std::vector<double> fct_values
    );

    /**
     * @brief enhanced first order forward differentiation
     * 
     * enhanced by the inclusion of second order, approximates f´(x) up to a 
     * term of order h^2. 
     * @param h 
     * @param fct_values 
     * @return std::vector<double> 
     */
    std::vector<double> forward_diff_enhanced_first_order(
        double h,
        std::vector<double> fct_values
    );

    std::vector<double> backward_diff(
        unsigned int n,
        double h,
        std::vector<double> fct_values
    );

    std::vector<double> backward_diff_enhanced_first_order(
        double h,
        std::vector<double> fct_values
    );

    std::vector<double> central_diff(
        unsigned int n,
        double h,
        std::vector<double> fct_values
    );
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// End Include Guards
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif
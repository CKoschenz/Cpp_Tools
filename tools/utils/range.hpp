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
#ifndef RANGE_HPP
#define RANGE_HPP

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Libraries
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <vector>
#include <numeric>
#include <algorithm>

namespace op{
    typedef unsigned int uint;

    template <typename T>
    struct IncGenerator {
        T current;
        T stepWidth;
        IncGenerator (const T& start, const T& stepWidth): 
            current{start-stepWidth}, stepWidth{stepWidth} {}
        T operator() () {
            current += stepWidth; 
            return current; 
        }
    };

    /**
     * @brief Fills the range [start, end) or [start, end] with end point flag
     * with values
     * 
     */
    template <typename T>
    std::vector<T> range
    ( const T start, const T end, const uint steps, bool endpoint=true, 
      const T factor = 1.0, const T offset = 0.0 ) {

        std::vector<T> vec(endpoint ? steps+1: steps, 0.0);
        const T stepWidth = (end - start)/steps;
        IncGenerator<T> increment (start, stepWidth);

        std::generate( vec.begin(), vec.end(), increment);

        std::transform( vec.begin(), vec.end(), 
                        vec.begin(),
                        std::bind(  std::multiplies<T>(), 
                                    std::placeholders::_1, factor
                        ));

        std::transform( vec.begin(), vec.end(), 
                        vec.begin(),
                        std::bind(  std::plus<T>(), 
                                    std::placeholders::_1, offset
                        ));

        return vec;
    }
}
#endif
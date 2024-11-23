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
#ifndef INDEXER_HPP
#define INDEXER_HPP

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Libraries
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

namespace op{
  class Indexer {
    public:
      Indexer(std::initializer_list<size_t> il);
      size_t operator()(std::initializer_list<size_t> args);

    private:
      std::vector<size_t> factors;
  };
}
#endif
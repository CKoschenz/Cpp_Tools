#include <tools/utils/indexer.hpp>

namespace op{

  Indexer::Indexer(std::initializer_list<size_t> il) {

    std::list<size_t> sl(il);
    sl.reverse();

    std::list<size_t> f;

    size_t temp = 1;
    for(const size_t& size : sl){
      f.push_front(temp);
      temp *= size;
    }

    factors.reserve(f.size());
    std::copy(std::begin(f), std::end(f), std::back_inserter(factors));
  }

  size_t
  Indexer::operator()(std::initializer_list<size_t> args){
    std::vector<size_t> v;
    std::transform( args.begin(), args.end(),
                    factors.begin(), std::back_inserter(v),
                    std::multiplies<size_t>() );

    return std::reduce(v.begin(), v.end());
  }
}
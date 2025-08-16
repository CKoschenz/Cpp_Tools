#include <iostream>
#include <unordered_set>
#include <tuple>

#include <tools/hash/hash.hpp>

int main(int argc, char *argv[]) {

  std::unordered_set<std::tuple<double, int>, hash_tuple::hash<std::tuple<double, int>>> test2;

  return EXIT_SUCCESS;
}

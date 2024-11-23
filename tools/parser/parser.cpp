#include <parser.hpp>

#include <cassert>
#include <string>

int parse_arguments(int argc, char *argv[]) {
  assert(argc == 2 && "program called with wrong number of arguments");

  return std::stoi(argv[1]);
}

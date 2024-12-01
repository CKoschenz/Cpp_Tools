#include <iostream>
#include <tools/factorial/factorial.hpp>
#include <tools/greeting/greeting.hpp>
#include <tools/io/io.hpp>
#include <tools/parser/parser.hpp>

int main(int argc, char *argv[]) {
  say_hello();

  int number = parse_arguments(argc, argv);
  print(number);
  print(factorial(number));

  return EXIT_SUCCESS;
}

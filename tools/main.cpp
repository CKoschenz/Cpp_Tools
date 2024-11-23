#include <tools/greeting/greeting.hpp>
#include <tools/factorial/factorial.hpp>
#include <tools/io/io.hpp>
#include <tools/parser/parser.hpp>

#include <iostream>

int main(int argc, char *argv[]) {

  say_hello();

  int number = parse_arguments(argc, argv);
  print(number);
  print(factorial(number));

  return EXIT_SUCCESS;
}

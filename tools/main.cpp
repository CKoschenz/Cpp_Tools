#include <projectname/greeting/greeting.hpp>
#include <projectname/factorial/factorial.hpp>
#include <projectname/io/io.hpp>
#include <projectname/parser/parser.hpp>

#include <iostream>

int main(int argc, char *argv[]) {

  say_hello();

  int number = parse_arguments(argc, argv);
  print(number);
  print(factorial(number));

  return EXIT_SUCCESS;
}

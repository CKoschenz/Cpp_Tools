// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Include Guards
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>
#include <tools/dependency_injection/dependency.hpp>

struct logger_interface {
  virtual void log(std::string) = 0;
  virtual ~logger_interface() = default;
};

struct some_service_interface {
  virtual void serve() = 0;
  virtual ~some_service_interface() = default;
};

struct logger_with_id : logger_interface {
  static int counter;
  int id = ++counter;
  void log(std::string s) { std::cout << id << ") " << s << std::endl; }
};
int logger_with_id::counter = 0;

struct some_service : some_service_interface {
  di<logger_interface> logger;

  some_service(di<logger_interface> logger = di<logger_interface>::instance())
      : logger(logger) {}

  void serve() { logger->log("serving..."); }
};

struct decorated_logger : logger_interface {
  di<logger_interface> logger;
  decorated_logger(
      di<logger_interface> logger = di<logger_interface>::instance())
      : logger(logger) {}
  void log(std::string s) {
    logger->log("decorating...");
    logger->log(s);
  }
};

struct mock_logger : logger_interface {
  void log(std::string) { std::cout << "mock_logger" << std::endl; }
};

struct mock_some_service : some_service_interface {
  void serve() { std::cout << "mock_some_service" << std::endl; }
};

struct my_s {
  int i;
  my_s(int i) : i(i) {}
  my_s() : i(0) {}
};

#endif
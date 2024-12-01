// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Include Guards
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef DEPENDENCY_HPP
#define DEPENDENCY_HPP

#include <iostream>
#include <memory>
#include <system_error>

template <typename T>
class di : public std::shared_ptr<T> {
  static std::shared_ptr<T> ptr;

 public:
  static void reset() { di<T>::ptr.reset(); }

  static std::shared_ptr<T> replace(std::shared_ptr<T> ptr) {
    di<T>::ptr = ptr;
    return di<T>::ptr;
  }

  template <typename... args_t>
  static std::shared_ptr<T> emplace(args_t&&... args) {
    return di<T>::replace(std::make_shared<T>(std::forward<args_t>(args)...));
  }

  bool is_linked() const { return *this && di<T>::ptr.get() == this->get(); }

  static di<T> instance() requires std::is_abstract<T>::value {
    return di<T>::ptr;
  }

  template <typename... args_t>
  static di<T> instance(args_t&&... args) requires(
      !std::is_abstract<T>::value) {
    if (!di<T>::ptr) {
      di<T>::emplace(std::forward<args_t>(args)...);
    }
    return di<T>::ptr;
  }

  template <typename... args_t>
  di(args_t&&... ptr) : std::shared_ptr<T>(std::forward<args_t>(ptr)...) {}

  ~di() {
    if (this->is_linked() && di<T>::ptr.use_count() <= 2) {
      di<T>::ptr.reset();
    }
  }
};

template <typename T>
std::shared_ptr<T> di<T>::ptr{};

#endif
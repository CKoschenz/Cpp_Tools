
#include <tools/dependency_injection/dependency.hpp>
#include <tools/dependency_injection/logger.hpp>

int main() {
  std::error_condition app = []() {
    di<logger_interface>::replace(di<logger_with_id>::emplace());
    di<some_service_interface>::replace(di<some_service>::emplace());
    std::cout << "running app" << std::endl;
    di<logger_interface>::instance()->log("app");
    di<some_service_interface>::instance()->serve();
    std::cout << std::endl;
    return std::error_condition{};
  }();

  std::error_condition app_with_custom_logger_on_service =
      [](di<logger_interface> logger, di<some_service_interface> service) {
        std::cout << "running app_with_custom_logger_on_service" << std::endl;
        logger->log("app");
        service->serve();
        std::cout << std::endl;
        return std::error_condition{};
      }(di<logger_interface>::replace(std::make_shared<logger_with_id>()),
        di<some_service_interface>::replace(
            std::make_shared<some_service>(std::make_shared<decorated_logger>(
                std::make_shared<logger_with_id>()))));

  std::error_condition test =
      [](di<logger_interface> logger, di<some_service_interface> service) {
        std::cout << "running test" << std::endl;
        logger->log("app");
        service->serve();
        std::cout << std::endl;
        return std::error_condition{};
      }(di<logger_interface>::replace(std::make_shared<mock_logger>()),
        di<some_service_interface>::replace(
            std::make_shared<mock_some_service>()));

  std::error_condition test2 = []() {
    std::cout << "running test2" << std::endl;
    di<logger_interface>::replace(di<logger_with_id>::emplace());
    di<some_service_interface>::replace(di<some_service>::emplace());
    di<logger_interface>::instance()->log("app");
    di<some_service_interface>::instance()->serve();
    std::cout << std::endl;
    return std::error_condition{};
  }();

  int test3 = []() {
    di<my_s>::emplace();
    std::cout << "running test3" << std::endl;
    std::cout << "!! " << di<my_s>::instance().is_linked() << " "
              << di<my_s>::instance().get() << std::endl;
    std::cout << std::endl;
    return 0;
  }();
}
from conan import ConanFile

class ProjectRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    requires = ("gtest/cci.20210126", "blaze/3.8.2", "nlopt/2.7.1", "swig/4.2.1", "nlohmann_json/3.11.3", "gsl/2.7.1")
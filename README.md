# C++ Tools

Code examples and explanations of design pattern and best practices

## Required libraries and programs

- CMake 3.>16
- Conan 2.>=0.5
- GNU Scientific Library, gsl >= 2.7.1, in particular `gsl-devel`

    ```shell
    dnf install gsl-devel
    ```

## Quickstart

### Build Default

```shell
$> conan install . --output-folder=build --build=missing
$> cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
$> cmake --build build
```

### Tracking Build Time

```shell
cmake -E time cmake --build .
```

### Call Main

```shell
./build/tools/tools.x
```

### Build Debugging

```shell
$> conan install . --output-folder=build --build=missing -s build_type=Debug
```

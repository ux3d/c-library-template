
# Minimum required version of CMake
cmake_minimum_required(VERSION 3.15)

# Enable compile_commands.json for clang-based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Project name and language
project(c_library_template C CXX)

# -------------------------------
# VCPKG Integration
# -------------------------------
# If you use VCPKG, CMake will automatically use it if VCPKG_ROOT is set.
# If not, you can specify the toolchain file manually when configuring:
#   cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
# No extra code is needed here for basic usage.
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")


# -------------------------------
# C Standard
# -------------------------------
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# -------------------------------
# Source Files
# -------------------------------
add_library(c_library_template SHARED
    src/main.c                # Main source file
    # src/another_source.c    # <-- Add more source files here as needed
)

# Windows DLL export/import macros
# Define C_LIBRARY_TEMPLATE_EXPORTS when building the DLL so the header uses dllexport (not dllimport).
if(WIN32)
    target_compile_definitions(c_library_template PUBLIC C_LIBRARY_TEMPLATE_DLL)
    target_compile_definitions(c_library_template PRIVATE C_LIBRARY_TEMPLATE_EXPORTS)
endif()

# -------------------------------
# Include Directories
# -------------------------------
target_include_directories(c_library_template PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include   # Public headers
)

# -------------------------------
# VCPKG Dependencies
# -------------------------------
# To add additional libraries using vcpkg:
# 1. Install the library with: vcpkg add <port>
#    Example: vcpkg add zlib
# 2. In your CMakeLists.txt, use find_package to locate the library:
#      find_package(<LibraryName> REQUIRED)
#    Example: find_package(ZLIB REQUIRED)
# 3. Link the library to your target with target_link_libraries:
#      target_link_libraries(c_library_template PRIVATE <LibraryName>::<LibraryName>)
#    Example: target_link_libraries(c_library_template PRIVATE ZLIB::ZLIB)
#
# Repeat these steps for each additional library you want to add.


# -------------------------------
# Installation Rules
# -------------------------------
# These rules allow 'cmake --install' to copy the library and headers to a standard location.
install(TARGETS c_library_template
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
install(FILES include/c_library_template.h DESTINATION include)


# -------------------------------
# Unit Tests
# -------------------------------
enable_testing()

find_package(GTest CONFIG REQUIRED)


add_executable(unit_tests test/test_main.cpp)
set_target_properties(unit_tests PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(unit_tests PRIVATE cxx_std_17)
target_link_libraries(unit_tests PRIVATE c_library_template GTest::gmock_main)
target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(unit_tests PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    BUILD_RPATH "${CMAKE_BINARY_DIR};${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/lib"
    INSTALL_RPATH "${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/lib"
)

add_test(AllTestsInMain unit_tests)

# -------------------------------
# Notes
# -------------------------------
# - To add more source files: list them in add_library above.
# - To add more header files: put them in the include directory.
# - To add dependencies: use find_package and target_link_libraries as shown above.
# - To build and install (for GitHub Actions artifact):
#     cmake -B build -S .
#     cmake --build build --config Release
#     cmake --install build --prefix install
#   The built library and headers will be in the 'install' directory.



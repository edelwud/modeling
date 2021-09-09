cmake_minimum_required(VERSION 3.5)

set(CLANG_TIDY YES)
set(CMAKE_CXX_STANDARD 20)

include(cmake/main.cmake)

project(${ADDON_APP}
        VERSION 0.0.1
        DESCRIPTION "Modeling my own random function"
        HOMEPAGE_URL "https://github.com/edelwud/modeling"
        LANGUAGES CXX)

conan_cmake_run(REQUIRES gtest/cci.20210126 BASIC_SETUP CMAKE_TARGETS)

initialize_project()
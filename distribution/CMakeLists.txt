cmake_minimum_required(VERSION 3.5)

set(CLANG_TIDY YES)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_TOOLCHAIN_FILE ~/.local/vcpkg/scripts/buildsystems/vcpkg.cmake)

include(cmake/main.cmake)

project(${ADDON_APP}
        VERSION 0.0.1
        DESCRIPTION "Modeling my own random function"
        HOMEPAGE_URL "https://github.com/edelwud/modeling"
        LANGUAGES CXX)

find_package(GTest CONFIG REQUIRED)

initialize_project()
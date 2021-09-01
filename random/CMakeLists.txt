cmake_minimum_required(VERSION 3.5)

set(CLANG_TIDY YES)
set(CMAKE_CXX_STANDARD 17)

include(cmake/main.cmake)

project(${ADDON_APP}
        VERSION 0.0.1
        DESCRIPTION "Modeling my own random function"
        HOMEPAGE_URL "https://github.com/edelwud/modeling"
        LANGUAGES CXX)

initialize_project()
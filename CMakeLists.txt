cmake_minimum_required(VERSION 3.17)

project(SpaceSim CXX)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

set(CMAKE_BUILD_TYPE Debug)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)
FetchContent_MakeAvailable(raylib)

include(FindCURL)

include_directories(include)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/downloader.cpp)
target_link_libraries(${PROJECT_NAME} raylib CURL::libcurl)
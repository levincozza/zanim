cmake_minimum_required(VERSION 3.14)
project(zanim C)

# get raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

# define executable
add_executable(${PROJECT_NAME} main.c)
# link raylib
target_link_libraries(${PROJECT_NAME} raylib)

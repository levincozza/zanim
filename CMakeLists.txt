cmake_minimum_required(VERSION 3.12)
project(zanim C)

# --- Platform-Specific Paths ---
if(APPLE)
    set(RAYLIB_INCLUDE_DIR "/opt/homebrew/Cellar/raylib/5.5/include")
    set(RAYLIB_LIB_DIR "/opt/homebrew/Cellar/raylib/5.5/lib")
elseif(WIN32)
    set(RAYLIB_INCLUDE_DIR "C:/raylib/include")
    set(RAYLIB_LIB_DIR "C:/raylib/lib")
endif()

# Add the include directory
include_directories(${RAYLIB_INCLUDE_DIR})

# --- Build Executable ---
set(SOURCE_FILES main.c)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# --- Link Libraries ---
if(APPLE)
    target_link_libraries(${PROJECT_NAME} 
        ${RAYLIB_LIB_DIR}/libraylib.a
        "-framework OpenGL" 
        "-framework Cocoa" 
        "-framework IOKit" 
        "-framework CoreVideo"
    )
elseif(WIN32)
    target_link_libraries(${PROJECT_NAME} 
        ${RAYLIB_LIB_DIR}/libraylib.a
        opengl32 
        gdi32 
        winmm
    )
endif()

# --- Generate LSP Configuration ---
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


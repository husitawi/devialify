cmake_minimum_required(VERSION 3.23.1)

project(Devialify)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the include directory to the search path for headers
include_directories(include)

# Add subdirectories for each module
add_subdirectory(src/audio_player)

# Set the build directory to "build/"
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
# Set the runtime output directory to "bin/"
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create the main executable
add_executable(${PROJECT_NAME} src/main.cpp)
# Link the main executable with the module libraries
target_link_libraries(${PROJECT_NAME} audio_player)
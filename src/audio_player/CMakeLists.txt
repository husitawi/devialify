# Set the module name
set(MODULE_NAME audio_player)

# Set the source files for the module
set(SOURCES
    track.cpp
    playlist.cpp
    mediaPlayer.cpp
)

# Add the library for the module
add_library(${MODULE_NAME} ${SOURCES})

# Set the include directory for the module
target_include_directories(${MODULE_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/${MODULE_NAME})

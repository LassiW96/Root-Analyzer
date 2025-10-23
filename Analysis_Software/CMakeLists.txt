cmake_minimum_required(VERSION 3.10)
project(FileHandler LANGUAGES CXX)

# --- Find ROOT ---
find_package(ROOT REQUIRED COMPONENTS RIO Tree Hist)
include(${ROOT_USE_FILE})

# --- Include headers ---
include_directories(${CMAKE_SOURCE_DIR}/include)

# --- Dictionary generation ---
set(LINKDEF ${CMAKE_SOURCE_DIR}/include/LinkDef.h)
set(HEADERS ${CMAKE_SOURCE_DIR}/include/FileHandler.h)

# This will generate G__FileHandler.cxx in your build directory
ROOT_GENERATE_DICTIONARY(G__FileHandler ${HEADERS} LINKDEF ${LINKDEF})

# --- Shared library (include generated dictionary source) ---
add_library(FileHandler SHARED src/FileHandler.cpp ${CMAKE_CURRENT_BINARY_DIR}/G__FileHandler.cxx)
target_link_libraries(FileHandler ${ROOT_LIBRARIES})

# Ensure PCM file is copied to the same folder as the library
add_custom_command(TARGET FileHandler POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/libFileHandler_rdict.pcm
        ${CMAKE_BINARY_DIR}/lib/
)

# Define output paths
set_target_properties(FileHandler PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)


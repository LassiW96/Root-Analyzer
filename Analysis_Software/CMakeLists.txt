cmake_minimum_required(VERSION 3.10)
project(RootAnalyzer LANGUAGES CXX)

# --- Find ROOT ---
find_package(ROOT REQUIRED COMPONENTS RIO Tree Hist)
include(${ROOT_USE_FILE})

# --- Include headers ---
include_directories(${CMAKE_SOURCE_DIR}/include)

# --- Dictionary generation ---
set(LINKDEF ${CMAKE_SOURCE_DIR}/include/LinkDef.h)
set(HEADERS ${CMAKE_SOURCE_DIR}/include/RootAnalyzer.h)

# This will generate G__RootAnalyzer.cxx in your build directory
ROOT_GENERATE_DICTIONARY(G__RootAnalyzer ${HEADERS} LINKDEF ${LINKDEF})

# --- Shared library (include generated dictionary source) ---
add_library(RootAnalyzer SHARED src/RootAnalyzer.cpp ${CMAKE_CURRENT_BINARY_DIR}/G__RootAnalyzer.cxx)
target_link_libraries(RootAnalyzer ${ROOT_LIBRARIES})

# Ensure PCM file is copied to the same folder as the library
add_custom_command(TARGET RootAnalyzer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/libRootAnalyzer_rdict.pcm
        ${CMAKE_BINARY_DIR}/lib/
)

# Define output paths
set_target_properties(RootAnalyzer PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)


cmake_minimum_required(VERSION 3.10)
project(AnalysisSoftware LANGUAGES CXX)

# --- Find ROOT ---
find_package(ROOT REQUIRED COMPONENTS RIO Tree Hist)
include(${ROOT_USE_FILE})

# --- Include directories ---
include_directories(${CMAKE_SOURCE_DIR}/include)

# --- Source and header files ---
set(HEADERS
    ${CMAKE_SOURCE_DIR}/include/FileHandler.h
    ${CMAKE_SOURCE_DIR}/include/AnalysisManager.h
    ${CMAKE_SOURCE_DIR}/include/GeneratePlots.h
)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/FileHandler.cpp
    ${CMAKE_SOURCE_DIR}/src/AnalysisManager.cpp
    ${CMAKE_SOURCE_DIR}/src/GeneratePlots.cpp
)

set(LINKDEF ${CMAKE_SOURCE_DIR}/include/LinkDef.h)

# --- Generate ROOT dictionary ---
ROOT_GENERATE_DICTIONARY(G__AnalysisSoftware ${HEADERS} LINKDEF ${LINKDEF})

# --- Build shared library including dictionary ---
add_library(AnalysisSoftware SHARED ${SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/G__AnalysisSoftware.cxx)
target_link_libraries(AnalysisSoftware ${ROOT_LIBRARIES})

# --- Copy PCM file to lib directory ---
add_custom_command(TARGET AnalysisSoftware POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/libAnalysisSoftware_rdict.pcm
        ${CMAKE_BINARY_DIR}/lib/
)

# --- Output path for the library ---
set_target_properties(AnalysisSoftware PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

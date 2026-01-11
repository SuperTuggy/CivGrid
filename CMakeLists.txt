cmake_minimum_required(VERSION 3.28)
project(CivGrid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Dependencies ---
add_subdirectory(external/nativefiledialog)

# --- Executable ---
add_executable(CivGrid
    main.cpp
    DataExtraction/DataExtraction.cpp
)

# --- Includes ---
target_include_directories(CivGrid PRIVATE
    ${LIBOSMIUM_INCLUDE_DIR}
)

# --- Linking ---
target_link_libraries(CivGrid PRIVATE
    bz2
    z
    expat
    nfd
)

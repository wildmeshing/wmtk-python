################################################################################
# Check required CMake version
set(REQUIRED_CMAKE_VERSION "3.14.0")
cmake_minimum_required(VERSION ${REQUIRED_CMAKE_VERSION})

if(INPUT_WMTKPY_DATA_ROOT)
    set(WMTKPY_DATA_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/${INPUT_WMTKPY_DATA_ROOT}/")
else()
    set(WMTKPY_DATA_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/data/")
endif()
if(NOT EXISTS ${WMTKPY_DATA_ROOT})
    file(MAKE_DIRECTORY ${WMTKPY_DATA_ROOT})
endif()

project(wmtkpy)
################################################################################

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/recipes/")

# Color output
include(UseColors)

# Prepend function
include(PrependCurrentPath)

# Extra warnings
include(Warnings)

# Use C++11/14
include(CXXFeatures)

# Sort projects inside the solution
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Generate position independent code by default
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

################################################################################
# Wmtk library
################################################################################

# dependencies
include(wmtk)
include(pybind11)
include(pybind11_json)

#for testing purpose
include(wmtk_data)

################################################################################
# Subdirectories
################################################################################
add_library(wmtkpy MODULE src/binding.cpp src/raster.cpp)
target_link_libraries(wmtkpy PRIVATE wmtk::wmtk pybind11::module pybind11::json)

set_target_properties(wmtkpy PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX "${PYTHON_MODULE_EXTENSION}")





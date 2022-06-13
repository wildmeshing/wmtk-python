# data
# License: MIT

message(STATUS "Third-party: fetching 'wmtk data'")

include(FetchContent)
FetchContent_Declare(
    wmtk_data
    GIT_REPOSITORY https://github.com/wmtk/wmtk-data
    GIT_TAG 56e70d2d7199fe4822b259c47fada97f70e32a72
    GIT_SHALLOW FALSE
    SOURCE_DIR ${WMTKPY_DATA_ROOT}/data
)
FetchContent_GetProperties(wmtk_data)
if(NOT wmtk_data_POPULATED)
  FetchContent_Populate(wmtk_data)
  # SET(WMTK_DATA_DIR ${wmtk_data_SOURCE_DIR})
endif()
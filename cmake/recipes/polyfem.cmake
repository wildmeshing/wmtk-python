# Wmtk
# License: MIT

if(TARGET wmtk::wmtk)
    return()
endif()

message(STATUS "Third-party: creating target 'wmtk::wmtk'")

include(FetchContent)
FetchContent_Declare(
    wmtk
    GIT_REPOSITORY https://github.com/wmtk/wmtk.git
    GIT_TAG ffb1d130e70fc913ec4546c8683d6d22bd58a700
    GIT_SHALLOW FALSE
)
FetchContent_MakeAvailable(wmtk)



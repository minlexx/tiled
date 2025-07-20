project(tolualib)

find_package(Lua REQUIRED)

add_library(tolualib STATIC)

target_sources(tolualib PRIVATE
    tolua_event.h
    ../include/tolua.h
    tolua_to.c
    tolua_push.c
    tolua_map.c
    tolua_is.c
    tolua_event.c
)

if (WIN32)
    target_compile_definitions(tolualib PRIVATE TOLUA5_DLL)
elseif (UNIX)
    # on Linux instead use visibility
    set_target_properties(tolualib
        PROPERTIES
            CXX_VISIBILITY_PRESET default
    )
endif()

target_include_directories(tolualib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>
        $<INSTALL_INTERFACE:include/libtolua>  # <prefix>/include/libtolua
        ${LUA_INCLUDE_DIR} # comes from find_package(Lua)
)

target_link_libraries(tolualib PUBLIC
    ${LUA_LIBRARIES} # comes from find_package(Lua)
)

set_target_properties(tolualib PROPERTIES POSITION_INDEPENDENT_CODE ON)


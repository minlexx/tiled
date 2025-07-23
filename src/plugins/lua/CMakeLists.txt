project(lua)

set(CMAKE_AUTOMOC ON)

add_library(lua MODULE)

target_compile_definitions(lua PRIVATE
    -DLUA_LIBRARY
    -DQT_PLUGIN
    -DQT_SHARED
)

target_include_directories(lua PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
)

set(lua_SRCS
    lua_global.h
    luaplugin.h
    luaplugin.cpp
    luatablewriter.h
    luatablewriter.cpp
)

target_sources(lua PRIVATE ${lua_SRCS})

target_link_libraries(lua PRIVATE tiled Qt::Core Qt::Gui)

INSTALL(TARGETS lua
    RUNTIME DESTINATION plugins/tiled
    LIBRARY DESTINATION plugins/tiled
)


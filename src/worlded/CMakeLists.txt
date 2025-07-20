project(worlded)

set(CMAKE_AUTOMOC ON)

add_library(worlded SHARED)

target_sources(worlded PUBLIC
    properties.cpp
    road.h
    road.cpp
    world.h
    world.cpp
    worldcell.h
    worldcell.cpp
    worldcellobject.cpp
    worlded_global.h
    worldedmgr.h
    worldedmgr.cpp
    worldproperties.h
    worldreader.h
    worldreader.cpp
)

target_compile_definitions(worlded PRIVATE
    -DQT_NO_CAST_FROM_ASCII
    -DQT_NO_CAST_TO_ASCII
    -DZOMBOID
    -DWORLDED
    -DWORLDED_LIBRARY
)

target_link_libraries(worlded PUBLIC Qt::Core Qt::Widgets tiled)

target_include_directories(worlded
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include/worldded>  # <prefix>/include/worldded
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../tiled
)


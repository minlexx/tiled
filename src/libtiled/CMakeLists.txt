project(libtiled)

set(CMAKE_AUTOMOC ON)

find_package(ZLIB REQUIRED)

add_library(tiled SHARED)

target_compile_definitions(tiled PRIVATE -DTILED_LIBRARY)

target_sources(tiled PRIVATE
    compression.h
    compression.cpp
    imagelayer.h
    imagelayer.cpp
    isometricrenderer.h
    isometricrenderer.cpp
    layer.h
    layer.cpp
    map.h
    map.cpp
    mapobject.h
    mapobject.cpp
    mapreader.h
    mapreader.cpp
    maprenderer.h
    maprenderer.cpp
    mapwriter.h
    mapwriter.cpp
    object.h
    objectgroup.h
    objectgroup.cpp
    orthogonalrenderer.h
    orthogonalrenderer.cpp
    properties.h
    properties.cpp
    staggeredrenderer.h
    staggeredrenderer.cpp
    tile.h
    tile.cpp
    tiled_global.h
    tilelayer.h
    tilelayer.cpp
    tileset.cpp
    tileset.h
    gidmapper.h
    gidmapper.cpp
    zlevelrenderer.h
    zlevelrenderer.cpp
    ztilelayergroup.h
    ztilelayergroup.cpp
)

target_link_libraries(tiled PUBLIC Qt::Core Qt::Gui ZLIB::ZLIB qtlockedfile)

target_include_directories(tiled PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/libtiled>  # <prefix>/include/libtiled
)

INSTALL(TARGETS tiled RUNTIME DESTINATION "." LIBRARY DESTINATION ".")

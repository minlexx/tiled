project(replicaisland)

add_library(replicaisland MODULE)

target_compile_definitions(replicaisland PRIVATE -DREPLICAISLAND_LIBRARY)

target_include_directories(replicaisland PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
)

set(replicaisland_SRCS
    replicaisland_global.h
    replicaislandplugin.cpp
    replicaisland.qrc
    replicaislandplugin.h
)

qt_add_resources(replicaisland_SRCS replicaisland.qrc)

target_sources(replicaisland PRIVATE ${replicaisland_SRCS})

target_link_libraries(replicaisland tiled Qt::Core Qt::Gui)


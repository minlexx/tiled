project(flare)

set(CMAKE_AUTOMOC ON)

add_library(flare MODULE)

target_compile_definitions(flare PRIVATE
    -DFLARE_LIBRARY
    -DQT_PLUGIN
    -DQT_SHARED
)

target_include_directories(flare PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
)

target_link_libraries(flare PRIVATE tiled Qt::Core Qt::Gui)

set(flare_SRCS
    flare_global.h
    flareplugin.h
    flareplugin.cpp
)

target_sources(flare PRIVATE ${flare_SRCS})

INSTALL(TARGETS flare
    RUNTIME DESTINATION plugins/tiled
    LIBRARY DESTINATION plugins/tiled
)

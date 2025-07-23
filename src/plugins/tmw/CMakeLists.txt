project(tmw)

add_library(tmw MODULE)

target_compile_definitions(tmw PRIVATE
    -DTMW_LIBRARY
    -DQT_PLUGIN
    -DQT_SHARED
)

target_include_directories(tmw PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
)

set(tmw_SRCS
    tmw_global.h
    tmwplugin.cpp
    tmwplugin.h
)

target_sources(tmw PRIVATE ${tmw_SRCS})

target_link_libraries(tmw PRIVATE tiled Qt::Core Qt::Gui)

INSTALL(TARGETS tmw
    RUNTIME DESTINATION plugins/tiled
    LIBRARY DESTINATION plugins/tiled
)

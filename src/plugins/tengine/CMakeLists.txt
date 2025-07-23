project(tengine)

add_library(tengine MODULE)

target_compile_definitions(tengine PRIVATE
    -DTENGINE_LIBRARY
    -DQT_PLUGIN
    -DQT_SHARED
)

target_include_directories(tengine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
)

set(tengine_SRCS
    tengine_global.h
    tengineplugin.cpp
    tengineplugin.h
)

target_sources(tengine PRIVATE ${tengine_SRCS})

target_link_libraries(tengine PRIVATE tiled Qt::Core Qt::Gui Qt::Widgets)

INSTALL(TARGETS tengine
    RUNTIME DESTINATION plugins/tiled
    LIBRARY DESTINATION plugins/tiled
)


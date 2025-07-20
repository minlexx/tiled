project(droidcraft)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_library(droidcraft MODULE ${droidcraft_SRCS})

target_compile_definitions(droidcraft PRIVATE
    -DDROIDCRAFT_LIBRARY
    -DQT_PLUGIN
    -DQT_SHARED
)

set(droidcraft_SRCS
    droidcraft_global.h
    droidcraftplugin.h
    droidcraftplugin.cpp
    droidcraft.qrc
)

qt_add_resources(droidcraft_SRCS droidcraft.qrc)

target_sources(droidcraft PRIVATE
    ${droidcraft_SRCS}
)

target_include_directories(droidcraft PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../../tiled
)

target_link_libraries(droidcraft PRIVATE tiled Qt::Core Qt::Gui)

INSTALL(TARGETS droidcraft
    RUNTIME DESTINATION plugins/tiled
    LIBRARY DESTINATION plugins/tiled
)

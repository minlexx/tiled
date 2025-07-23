project(lot)

set(CMAKE_AUTOMOC ON)

add_library(lot MODULE)

target_compile_definitions(lot PRIVATE
    -DLOT_LIBRARY
    -DQT_PLUGIN
    -DQT_SHARED
)

target_include_directories(lot PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
)

set(lot_SRCS
    lot_global.h
    lotplugin.cpp
    lotplugin.h
)

target_sources(lot PRIVATE ${lot_SRCS})

target_link_libraries(lot PRIVATE tiled Qt::Core Qt::Gui)

INSTALL(TARGETS lot
    RUNTIME DESTINATION plugins/tiled
    LIBRARY DESTINATION plugins/tiled
)

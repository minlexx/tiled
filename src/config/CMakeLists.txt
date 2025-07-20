project(config)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(config)

target_compile_definitions(config PRIVATE
    -DQT_NO_CAST_FROM_ASCII
    -DQT_NO_CAST_TO_ASCII
)

target_link_libraries(config PRIVATE Qt::Gui Qt::Widgets)

target_sources(config PRIVATE
    main.cpp
    configdialog.cpp
    configdialog.h
    configdialog.ui
)

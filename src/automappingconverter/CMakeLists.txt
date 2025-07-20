project(automappingconverter)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(automappingconverter
    convertercontrol.h
    main.cpp
    converterdatamodel.h
    converterdatamodel.cpp
    convertercontrol.cpp
    converterwindow.h
    converterwindow.cpp
    converterwindow.ui
)

target_link_libraries(automappingconverter PUBLIC tiled Qt::Core Qt::Gui Qt::Widgets)

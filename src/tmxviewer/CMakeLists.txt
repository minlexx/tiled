project(tmxviewer)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(tmxviewer
    main.cpp
    tmxviewer.cpp
    tmxviewer.h
)

target_link_libraries(tmxviewer PRIVATE tiled Qt::Core Qt::Gui Qt::Widgets)

INSTALL(TARGETS tmxviewer DESTINATION ".")

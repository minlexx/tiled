project(qtsingleapplication)

add_library(qtsingleapplication SHARED)

target_sources(qtsingleapplication PUBLIC
    qtlocalpeer.h
    qtlocalpeer.cpp
    qtsingleapplication.h
    qtsingleapplication.cpp
)

target_link_libraries(qtsingleapplication PUBLIC Qt::Core Qt::Network Qt::Widgets qtlockedfile)

target_include_directories(qtsingleapplication PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/qtsingleapplication>  # <prefix>/include/qtsingleapplication
)


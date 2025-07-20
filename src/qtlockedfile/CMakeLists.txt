project(qtlockedfile)

add_library(qtlockedfile SHARED)

target_sources(qtlockedfile PUBLIC
    qtlockedfile.h
    qtlockedfile.cpp
)

if (WIN32)
    target_sources(qtlockedfile PUBLIC
        qtlockedfile_win.cpp
    )
elseif(UNIX)
    target_sources(qtlockedfile PUBLIC
        qtlockedfile_unix.cpp
    )
endif()

target_link_libraries(qtlockedfile PUBLIC Qt::Core)

target_include_directories(qtlockedfile PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/qtlockedfile>  # <prefix>/include/qtlockedfile
)


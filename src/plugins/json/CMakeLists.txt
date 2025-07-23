project(json)

set(CMAKE_AUTOMOC ON)

add_library(json MODULE)

target_compile_definitions(json PRIVATE -DJSON_LIBRARY)

target_include_directories(json PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../tiled
)

set(json_SRCS
    json_global.h
    jsonplugin.cpp
    jsonplugin.h
    maptovariantconverter.cpp
    maptovariantconverter.h
    qjsonparser/json.cpp
    qjsonparser/json.h
    varianttomapconverter.cpp
    varianttomapconverter.h
)

target_sources(json PRIVATE ${json_SRCS})

target_link_libraries(json PRIVATE tiled Qt::Core Qt::Gui)

INSTALL(TARGETS json
    RUNTIME DESTINATION plugins/tiled
    LIBRARY DESTINATION plugins/tiled
)

project(tolua)

find_package(Lua REQUIRED)

add_executable(tolua
    tolua.c
    toluabind.c
)

set_target_properties(tolua PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_compile_definitions(tolua PRIVATE
    LUA_SOURCE
    LUA_SOURCE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/lua/"
)

target_include_directories(tolua
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${LUA_INCLUDE_DIR} # comes from find_package(Lua)
)

target_link_libraries(tolua PUBLIC
    tolualib
    ${LUA_LIBRARIES} # comes from find_package(Lua)
)

# other Lua sources

target_sources(tolua PRIVATE
    lua/verbatim.lua
    lua/variable.lua
    lua/typedef.lua
    lua/package.lua
    lua/operator.lua
    lua/namespace.lua
    lua/module.lua
    lua/feature.lua
    lua/enumerate.lua
    lua/doit.lua
    lua/define.lua
    lua/declaration.lua
    lua/container.lua
    lua/compat.lua
    lua/code.lua
    lua/clean.lua
    lua/class.lua
    lua/basic.lua
    lua/array.lua
    lua/all.lua
    lua/function.lua
)

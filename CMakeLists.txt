cmake_minimum_required(VERSION 3.20)

project(TileZed
    VERSION 0.8.1
    DESCRIPTION "Project Zomboid Map Tiles Editor"
    HOMEPAGE_URL "https://theindiestone.com"
    LANGUAGES CXX
)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Network Widgets)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG            ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL       ${CMAKE_BINARY_DIR}/MinSizeRel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE          ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO   ${CMAKE_BINARY_DIR}/RelWithDebInfo)

add_compile_definitions(-DZOMBOID)

add_subdirectory(src)
#add_subdirectory(translations)

install(FILES AUTHORS DESTINATION . RENAME AUTHORS.txt)
install(FILES COPYING DESTINATION . RENAME COPYING.txt)
install(FILES LICENSE.BSD DESTINATION . RENAME LICENSE.BSD.txt)
install(FILES LICENSE.GPL DESTINATION . RENAME LICENSE.GPL.txt)
install(FILES NEWS DESTINATION . RENAME NEWS.txt)
install(FILES README.md DESTINATION . RENAME README.txt)

#install(FILES docs/map.dtd docs/map.xsd DESTINATION docs)
#install ( DIRECTORY docs/TileProperties DESTINATION docs/ )
#install(DIRECTORY examples DESTINATION .)

#--------------------------------------------------------------------------------
# install a qt.conf file
# this inserts some cmake code into the install script to write the file
#INSTALL(CODE "
#    file(WRITE \"\${CMAKE_INSTALL_PREFIX}/${qtconf_dest_dir}/qt.conf\" \"[Paths]
#Plugins = plugins
#Translations = translations\")
#    " COMPONENT Runtime)

#--------------------------------------------------------------------------------
file(COPY
    src/tiled/BuildingEditor/BuildingFurniture.txt
    src/tiled/BuildingEditor/BuildingTemplates.txt
    src/tiled/BuildingEditor/BuildingTiles.txt
    src/tiled/BuildingEditor/TMXConfig.txt

    LuaTools.txt
    Rearrange.txt
    TileProperties.txt
    Tilesets.txt
    DESTINATION ${CMAKE_BINARY_DIR}/share/tilezed/config
)

install(FILES TileProperties.txt Tilesets.txt DESTINATION .)


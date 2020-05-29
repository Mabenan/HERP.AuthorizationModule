cmake_minimum_required(VERSION 3.5)
if(NOT CMAKE_PROJECT_NAME)
project(${target} LANGUAGES CXX)
endif()
include(../../QxOrm/QxOrm.cmake)
set(target "HERP.AuthorizationModule.Client")
add_definitions(-D_BUILDING_HERP_AUTHORIZATION_MODULE)
add_definitions(-D_APP_CLIENT)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugins/client)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SRC
    "*.cpp"
)
file(GLOB HEADER
    "*.h"
    "*.hpp"
    )
add_subdirectory(../data ${CMAKE_BINARY_DIR}/../HERP.AuthorizationModule.Client.data)
add_subdirectory(../dataService ${CMAKE_BINARY_DIR}/../HERP.AuthorizationModule.Client.dataService)

add_library(${target} SHARED ${SRC} qml.qrc)
target_precompile_headers(${target}
 PUBLIC
  "../HERP.AuthorizationModule.Precompiled.h"
 )
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
if(${PACKAGE})
find_package(ApplicationClient)
endif()
qt5_use_modules(${target} Core Gui Widgets Network)

target_include_directories(${target} PUBLIC
 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${INCLUDE_FOLDER}>
)
target_link_libraries(${target} ApplicationClientInterface QxOrm QxOrmHelperMacros)
install(TARGETS ${target}
LIBRARY DESTINATION "${LIB_FOLDER}"
    ARCHIVE DESTINATION "${LIB_FOLDER}"
    RUNTIME DESTINATION "${PLUGIN_FOLDER}/client"
    INCLUDES DESTINATION "${INCLUDE_FOLDER}")
install(FILES ${HEADER} DESTINATION ${INCLUDE_FOLDER})

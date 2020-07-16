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
if(UNIX)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugins/client)
endif()

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

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
if(${PACKAGE})
find_package(ApplicationClient)
endif()
find_package(Qt5QuickCompiler)
qtquick_compiler_add_resources(${RSC} herpAuthorizationModule.qrc)
add_library(${target} SHARED ${SRC} herpAuthorizationModule.qrc)
if(COMMAND target_precompile_headers)
target_precompile_headers(${target}
 PUBLIC
  "../export.h"
  "../HERP.AuthorizationModule.Precompiled.h"
 )
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

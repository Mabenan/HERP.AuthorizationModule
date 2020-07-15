cmake_minimum_required(VERSION 3.5)
if(NOT CMAKE_PROJECT_NAME)
project(${target} LANGUAGES CXX)
endif()
include(../QxOrm/QxOrm.cmake)
if(${_HRP_BUILD_SERVER})
set(target "HERP.AuthorizationModule.Server")
add_definitions(-D_BUILDING_HERP_AUTHORIZATION_MODULE)
add_definitions(-D_QX_ENABLE_QT_NETWORK)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugins/server)
if(UNIX)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugins/server)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SRC
    "*.cpp"
)
file(GLOB HEADER
    "*.h"
    "*.hpp"
    )
add_subdirectory(data)
add_subdirectory(dataService)
add_subdirectory(command)
add_subdirectory(webServices)
add_library(${target} SHARED ${SRC})
if(COMMAND target_precompile_headers)
target_precompile_headers(${target}
 PUBLIC
  "HERP.AuthorizationModule.Precompiled.h"
 )
 endif()
find_package(Qt5Core REQUIRED)
if(${PACKAGE})
find_package(ApplicationServer)
endif()
qt5_use_modules(${target} Core)

target_include_directories(${target} PUBLIC
 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${INCLUDE_FOLDER}>
)
target_link_libraries(${target} ApplicationServerInterface QxOrm QxOrmHelperMacros)
install(TARGETS ${target}
LIBRARY DESTINATION "${LIB_FOLDER}"
    ARCHIVE DESTINATION "${LIB_FOLDER}"
    RUNTIME DESTINATION "${PLUGIN_FOLDER}/server"
    INCLUDES DESTINATION "${INCLUDE_FOLDER}")
install(FILES ${HEADER} DESTINATION ${INCLUDE_FOLDER})
else()
add_subdirectory(client)
endif()

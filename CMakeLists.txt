cmake_minimum_required(VERSION 3.5)
if(NOT CMAKE_PROJECT_NAME)
project(${target} LANGUAGES CXX)
endif()
set(target "HERP.AuthorizationModule")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SRC
    "*.cpp"
)
file(GLOB HEADER
    "*.h"
    "*.hpp"
)
add_library(${target} SHARED ${SRC})
find_package(Qt5Core REQUIRED)
find_package(Qt5HttpServer REQUIRED)
if(${PACKAGE})
find_package(ApplicationServer)
endif()
qt5_use_modules(${target} Core HttpServer)

target_include_directories(${target} PUBLIC 
 PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${INCLUDE_FOLDER}>
)    
target_link_libraries(${target} ApplicationServerInterface ApplicationServerCore QxOrm)

install(TARGETS ${target} EXPORT ${target} 
LIBRARY DESTINATION "${LIB_FOLDER}"
    ARCHIVE DESTINATION "${LIB_FOLDER}"
    RUNTIME DESTINATION "${PLUGIN_FOLDER}"
    INCLUDES DESTINATION "${INCLUDE_FOLDER}")
install(
  EXPORT ${target} 
  DESTINATION ${LIB_FOLDER}
  )
install(FILES ${HEADER} DESTINATION ${INCLUDE_FOLDER})
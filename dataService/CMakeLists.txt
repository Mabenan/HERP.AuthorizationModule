
add_definitions(-D_BUILDING_HERP_AUTHORIZATION_MODULE)
add_definitions(-D_QX_ENABLE_QT_NETWORK)
file(GLOB SRCl
    "*.cpp"
)
file(GLOB HEADERl
    "*.h"
    "*.hpp"
)
set(SRC ${SRC} ${SRCl} PARENT_SCOPE)
set(HEADER ${HEADER} ${HEADERl} PARENT_SCOPE)
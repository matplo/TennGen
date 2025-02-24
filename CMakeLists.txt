# add_compile_options(${FASTJET_CXXFLAGS})
include(GNUInstallDirs)

set(MODULE_NAME TennGen)
set(MODULE ${PROJECT_NAME}_${MODULE_NAME})
set(NAME_LIB ${MODULE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
add_definitions(${ROOT_CXX_FLAGS})
file(GLOB SOURCES_LIB ${CMAKE_CURRENT_SOURCE_DIR}/*.cxx)
message(STATUS "SOURCES: ${SOURCES_LIB}")
string(REPLACE ".cxx" ".h" HEADERS_LIB "${SOURCES_LIB}")
# string(REPLACE ".cxx" "_wrap.c" SWIG_HEADERS_LIB "${SOURCES_LIB}")

# generate ROOT dictionaries
set(DICT ${NAME_LIB}_Dict )
set(LINKDEFS "${NAME_LIB}_LinkDef.h" )
ROOT_GENERATE_DICTIONARY(${DICT} ${HEADERS_LIB} LINKDEF ${LINKDEFS})
add_library(${NAME_LIB} SHARED ${SOURCES_LIB} ${DICT})

target_link_libraries(${NAME_LIB} PUBLIC ${ROOT_LIBRARIES})

install(TARGETS ${NAME_LIB} LIBRARY DESTINATION lib COMPONENT library)

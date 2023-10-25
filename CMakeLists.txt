cmake_minimum_required(VERSION 3.3)

project(Graphs)

if(TARGET SCIP::SCIP)
  # find package by SCIP PATH
  find_package(SCIP CONFIG PATHS ${SCIP_BINARY_DIR} REQUIRED)
else()
  find_package(SCIP REQUIRED)
endif()

include_directories(${SCIP_INCLUDE_DIRS})

add_executable(graphs
   src/graphs.cpp
   src/graphs_main.cpp
   
   )

target_link_libraries(graphs ${SCIP_LIBRARIES})

if( TARGET examples )
    add_dependencies( examples graphs )
endif()

message(STATUS "SCIP_INCLUDE_DIRS: ${SCIP_INCLUDE_DIRS}")
message(STATUS "SCIP_LIBRARIES: ${SCIP_LIBRARIES}")
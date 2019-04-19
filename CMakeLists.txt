cmake_minimum_required(VERSION 3.3)
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../${PROJECT_SOURCE_DIR})

project(expert_system)
set(EXPERT_SYSTEM_EXEC
    main.cpp 
    source/ExceptionExpSys.cpp 
    source/Reading.cpp 
    source/Checker.cpp 
    source/Expert_System.cpp 
    source/Fact.cpp 
    source/Rule.cpp 
)

   
# Executble
add_executable(expert_system ${EXPERT_SYSTEM_EXEC})

cmake_minimum_required (VERSION 3.5)

project (GreatWallProblem)

set(CMAKE_CXX_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(doTests 
        GreatWallTests.cpp 
        GreatWall.h
        GreatWall.cpp
        BinarySearchTree
        BinarySearchTree.cpp)

    add_executable(main 
        main.cpp
        GreatWall.h
        GreatWall.cpp
        BinarySearchTree
        BinarySearchTree.cpp)
endif()

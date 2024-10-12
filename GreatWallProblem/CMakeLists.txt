cmake_minimum_required (VERSION 3.5)

project (GreatWallProblem)

set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(doTests 
        tests/GreatWallTests.cpp 
        tests/TestHelper.h
        tests/TestHelper.cpp
        GreatWall.h
        GreatWall.cpp)

    target_link_libraries(doTests Boost::unit_test_framework)
endif()

add_executable(main 
    main.cpp
    GreatWall.h
    GreatWall.cpp)

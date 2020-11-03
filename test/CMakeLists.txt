cmake_minimum_required(VERSION 3.17)
project(fileDiCalcolo)

set(CMAKE_CXX_STANDARD 11)
find_package(Qt5Widgets REQUIRED)
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Test REQUIRED )

add_subdirectory(/home/mirko25/CLionProjects/fileDiCalcolo/test/lib/googletest)
set(gtest_SOURCE_DIR, /home/mirko25/CLionProjects/fileDiCalcolo/test/lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp test.cpp)
add_executable(test runAllTest.cpp ${SOURCE_FILES} test.cpp)

target_link_libraries(test gtest gtest_main core Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Test)

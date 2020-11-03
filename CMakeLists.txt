cmake_minimum_required(VERSION 3.17)
project(fileDiCalcolo)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

set (CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )

add_executable(fileDiCalcolo main.cpp Functions.cpp Functions.h Max.cpp Max.h Min.cpp Min.h Sum.cpp Sum.h Media.cpp Media.h Cells.cpp Window.cpp Window.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(fileDiCalcolo Qt5::Core Qt5::Widgets Qt5::Gui)

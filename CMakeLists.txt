cmake_minimum_required(VERSION 3.6)

#Configuration du projet
set(PROJECT_NAME Pacman)
project(${PROJECT_NAME})
set(EXECUTABLE_NAME ${PROJECT_NAME})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libgcc -Wall")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libgcc -static-libstdc++ -Wall")

#set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++ ${CMAKE_SHARED_LINKER_FLAGS}")

#include_directories("${PROJECT_SOURCE_DIR}/Libs")

set(SFMLDIR "D:/Mes Documents/Desktop/SFML-2.4.0")
set(SFML_ROOT "D:/Mes Documents/Desktop/SFML-2.4.0")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SFMLDIR}/cmake/Modules/")
set(SFML_LIBRARIES "${SFMLDIR}/lib")
set(SFML_INCLUDE_DIR "${SFMLDIR}/include")


set(SOURCE_FILES src/main.cpp
		src/model/Model.cpp src/model/Model.h
		src/view/View.cpp src/view/View.h
		src/controller/Controller.cpp src/controller/Controller.h
		src/util/Gameobject.cpp src/util/Gameobject.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)

include_directories( ${SFML_INCLUDE_DIR} )

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
if (OPENGL_FOUND)
	target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
	# or: target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_gl_LIBRARY})
	target_link_libraries(${EXECUTABLE_NAME} m)  # if you use maths.h
endif()
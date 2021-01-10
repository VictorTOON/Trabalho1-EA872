# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

#Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# Nome do meu projeto
project(VingancasArvores)

#
add_executable(VingancasArvores src/main.cpp)

# Especificar onde estao os header files
include_directories(include/)

# Bibliotecas locais (estaticas)
add_library(axeController src/axeController.cpp)
add_library(axeModel src/axeModel.cpp)
add_library(bodyModel src/bodyModel.cpp)
add_library(characterController src/characterController.cpp)
add_library(characterModel src/characterModel.cpp)
add_library(gameController src/gameController.cpp)
add_library(gameModel src/gameModel.cpp)
add_library(projectileModel src/projectileModel.cpp)
add_library(zombieController src/zombieController.cpp)
add_library(zombieModel src/zombieModel.cpp)
add_library(keyboard src/sdl_keyboard_handler.cpp)

target_link_libraries(zombieModel bodyModel)
target_link_libraries(zombieModel zombieController)
target_link_libraries(characterModel bodyModel)
target_link_libraries(characterModel characterController)

target_link_libraries(VingancasArvores axeController)
target_link_libraries(VingancasArvores axeModel)
target_link_libraries(VingancasArvores bodyModel)
target_link_libraries(VingancasArvores characterController)
target_link_libraries(VingancasArvores characterModel)
target_link_libraries(VingancasArvores gameController)
target_link_libraries(VingancasArvores gameModel)
target_link_libraries(VingancasArvores projectileModel)
target_link_libraries(VingancasArvores keyboard)
target_link_libraries(VingancasArvores zombieController)
target_link_libraries(VingancasArvores zombieModel)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#find_package(SDL2_image REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(VingancasArvores ${SDL2_LIBRARIES})#${SDL2_IMAGE_LIBRARIES})

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# Bibliotecas linkadas externamente
#target_link_libraries(VingancasArvores ${SDL2_LIBRARIES})

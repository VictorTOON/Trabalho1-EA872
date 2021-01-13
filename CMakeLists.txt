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
add_library(axeView src/axeView.cpp)
add_library(bodyModel src/bodyModel.cpp)
add_library(bodyView src/bodyView.cpp)
add_library(characterController src/characterController.cpp)
add_library(characterModel src/characterModel.cpp)
add_library(characterView src/characterView.cpp)
add_library(gameController src/gameController.cpp)
add_library(gameModel src/gameModel.cpp)
add_library(gameView src/gameView.cpp)
add_library(projectileModel src/projectileModel.cpp)
add_library(projectileView src/projectileView.cpp)
add_library(keyboard src/sdl_keyboard_handler.cpp)
add_library(zombieController src/zombieController.cpp)
add_library(zombieModel src/zombieModel.cpp)
add_library(zombieView src/zombieView.cpp)
add_library(clientController src/clientController.cpp)
add_library(sender src/sender.cpp)
add_library(receiver src/receiver.cpp)

target_link_libraries(axeModel projectileModel)
target_link_libraries(axeView projectileView)
target_link_libraries(axeController axeModel)
target_link_libraries(axeController axeView)
target_link_libraries(characterController axeController)
target_link_libraries(gameController axeController)

target_link_libraries(zombieModel bodyModel)
target_link_libraries(zombieView bodyView)
target_link_libraries(zombieController zombieModel)
target_link_libraries(zombieController zombieView)
target_link_libraries(characterModel bodyModel)
target_link_libraries(characterView bodyView)
target_link_libraries(characterController characterModel)
target_link_libraries(characterController characterView)
target_link_libraries(characterController keyboard)
target_link_libraries(gameController gameModel)
target_link_libraries(gameController gameView)
target_link_libraries(gameController characterController)
target_link_libraries(gameController zombieController)
target_link_libraries(sender clientController)
target_link_libraries(receiver clientController)
target_link_libraries(axeController axeModel)
target_link_libraries(axeController axeView)
target_link_libraries(characterController axeController)
target_link_libraries(gameController axeController)

target_link_libraries(VingancasArvores axeController)
target_link_libraries(VingancasArvores axeModel)
target_link_libraries(VingancasArvores axeView)
target_link_libraries(VingancasArvores bodyModel)
target_link_libraries(VingancasArvores bodyView)
target_link_libraries(VingancasArvores characterController)
target_link_libraries(VingancasArvores characterModel)
target_link_libraries(VingancasArvores characterView)
target_link_libraries(VingancasArvores gameController)
target_link_libraries(VingancasArvores gameModel)
target_link_libraries(VingancasArvores gameView)
target_link_libraries(VingancasArvores projectileModel)
target_link_libraries(VingancasArvores projectileView)
target_link_libraries(VingancasArvores keyboard)
target_link_libraries(VingancasArvores zombieController)
target_link_libraries(VingancasArvores zombieModel)
target_link_libraries(VingancasArvores zombieView)
target_link_libraries(VingancasArvores receiver)
target_link_libraries(VingancasArvores sender)
target_link_libraries(VingancasArvores clientController)

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system)

include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(VingancasArvores ${Boost_LIBRARIES})
target_link_libraries(sender ${Boost_LIBRARIES})
target_link_libraries(receiver ${Boost_LIBRARIES})


# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(VingancasArvores ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# Bibliotecas linkadas externamente
#target_link_libraries(VingancasArvores ${SDL2_LIBRARIES})
#target_link_libraries(VingancasArvores ${SDL2_IMAGE_LIBRARIES})


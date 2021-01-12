# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

#Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# Nome do meu projeto
project(ClientVingancasArvores)

#
add_executable(ClientVingancasArvores src/main.cpp)

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
add_library(client src/client.cpp)
add_library(clientController src/clientController.cpp)
add_library(json src/json.cpp)
add_library(receiver src/receiver.cpp)
add_library(sender src/sender.cpp)

target_link_libraries(zombieModel bodyModel)
target_link_libraries(zombieView bodyView)
target_link_libraries(zombieModel zombieController)
target_link_libraries(zombieView zombieController)
target_link_libraries(characterModel bodyModel)
target_link_libraries(characterView bodyView)
target_link_libraries(characterModel characterController)
target_link_libraries(characterView characterController)

target_link_libraries(ClientVingancasArvores axeController)
target_link_libraries(ClientVingancasArvores axeModel)
target_link_libraries(ClientVingancasArvores axeView)
target_link_libraries(ClientVingancasArvores bodyModel)
target_link_libraries(ClientVingancasArvores bodyView)
target_link_libraries(ClientVingancasArvores characterController)
target_link_libraries(ClientVingancasArvores characterModel)
target_link_libraries(ClientVingancasArvores characterView)
target_link_libraries(ClientVingancasArvores gameController)
target_link_libraries(ClientVingancasArvores gameModel)
target_link_libraries(ClientVingancasArvores gameView)
target_link_libraries(ClientVingancasArvores projectileModel)
target_link_libraries(ClientVingancasArvores projectileView)
target_link_libraries(ClientVingancasArvores keyboard)
target_link_libraries(ClientVingancasArvores zombieController)
target_link_libraries(ClientVingancasArvores zombieModel)
target_link_libraries(ClientVingancasArvores zombieView)
target_link_libraries(ClientVingancasArvores client)
target_link_libraries(ClientVingancasArvores clientController)
target_link_libraries(ClientVingancasArvores json)
target_link_libraries(ClientVingancasArvores receiver)
target_link_libraries(ClientVingancasArvores sender)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(ClientVingancasArvores ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# Bibliotecas linkadas externamente
#target_link_libraries(ClientVingancasArvores ${SDL2_LIBRARIES})
#target_link_libraries(ClientVingancasArvores ${SDL2_IMAGE_LIBRARIES})
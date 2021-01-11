# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(ClienteVingancaArvore)

#
add_executable(ClienteVingancaArvore src/main.cpp)

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
add_library(json src/json.cpp)
add_library(receiver src/receiver.cpp)
add_library(sender src/sender.cpp)

target_link_libraries(ClienteVingancaArvore axeController)
target_link_libraries(ClienteVingancaArvore axeModel)
target_link_libraries(ClienteVingancaArvore axeView)
target_link_libraries(ClienteVingancaArvore bodyModel)
target_link_libraries(ClienteVingancaArvore bodyView)
target_link_libraries(ClienteVingancaArvore characterController)
target_link_libraries(ClienteVingancaArvore characterModel)
target_link_libraries(ClienteVingancaArvore characterView)
target_link_libraries(ClienteVingancaArvore gameController)
target_link_libraries(ClienteVingancaArvore gameModel)
target_link_libraries(ClienteVingancaArvore gameView)
target_link_libraries(ClienteVingancaArvore projectileModel)
target_link_libraries(ClienteVingancaArvore projectileView)
target_link_libraries(ClienteVingancaArvore zombieController)
target_link_libraries(ClienteVingancaArvore zombieModel)
target_link_libraries(ClienteVingancaArvore zombieView)
target_link_libraries(ClienteVingancaArvore keyboard)
target_link_libraries(ClienteVingancaArvore client)
target_link_libraries(ClienteVingancaArvore json)
target_link_libraries(ClienteVingancaArvore receiver)
target_link_libraries(ClienteVingancaArvore sender)



# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(ClienteVingancaArvore ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# Bibliotecas linkadas externamente
#target_link_libraries(ClienteVingancaArvore ${SDL2_LIBRARIES})
#target_link_libraries(ClienteVingancaArvore ${SDL2_IMAGE_LIBRARIES})
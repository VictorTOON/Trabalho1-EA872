# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(MeuJogo)

#
add_executable(MeuJogo ../src/main.cpp)

# Especificar onde estao os header files
include_directories(../include)

# Bibliotecas locais (estaticas)
add_library(massamola ../src/massa-mola-amortecimento.cpp)
add_library(keyboard ../src/sdl_keyboard_handler.cpp)
add_library(renderer ../src/sdl_renderer.cpp)

target_link_libraries(MeuJogo massamola)
target_link_libraries(MeuJogo keyboard)
target_link_libraries(MeuJogo renderer)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(MeuJogo ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# Bibliotecas linkadas externamente
#target_link_libraries(MeuJogo ${SDL2_LIBRARIES})
#target_link_libraries(MeuJogo ${SDL2_IMAGE_LIBRARIES})
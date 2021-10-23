cmake_minimum_required(VERSION 3.21)
project(RPGGame)

find_package(PkgConfig REQUIRED)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_image REQUIRED SDL2_image)
PKG_SEARCH_MODULE(SDL2_ttf REQUIRED SDL2_ttf)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_image_INCLUDE_DIRS} ${SDL2_ttf_INCLUDE_DIRS})

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES} ${SDL2_ttf_LIBRARIES})
add_subdirectory(src)

file(COPY resources DESTINATION .)

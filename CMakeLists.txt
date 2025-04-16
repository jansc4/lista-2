cmake_minimum_required(VERSION 3.30)
project(lista2)

set(CMAKE_CXX_STANDARD 20)


include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(Catch2)


enable_testing()

# Dodajemy podprojekty
add_subdirectory(zad1)
#add_subdirectory(zad2)

cmake_minimum_required(VERSION 3.16)
project(SFML_plus_ImGui_example_project CXX) ## rename "SFML_plus_ImGui_example_project" to your project name

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS OFF)
set(THREADS_PREFER_PTHREAD_FLAG ON)

add_compile_definitions(ImDrawIdx=unsigned)
add_compile_definitions(IMGUI_DISABLE_OBSOLETE_FUNCTIONS)

## getting the libraries is in ./external folder
add_subdirectory(external)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
    add_compile_options(-Werror -Wall -Wextra -Wpedantic -Wshadow)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/WX /W3 /permissive-)
    add_compile_options(/MP)
endif()

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp)

    ## add "sfml-audio" if you need additional SFML funcitons like audio
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics ImGui-SFML::ImGui-SFML Threads::Threads) 
cmake_minimum_required(VERSION 3.22)
project(heat_equation_solver LANGUAGES CXX)
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/solution_steps.cpp src/tools.cpp src/fem_functions.cpp src/main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

include(FetchContent)
FetchContent_Declare(
  Eigen_lib
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.3.9)
FetchContent_MakeAvailable(Eigen_lib)

include(FetchContent)
FetchContent_Declare(
  matplot_plusplus
  GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus.git
  GIT_TAG v1.2.2)
FetchContent_MakeAvailable(matplot_plusplus)

target_link_libraries(${PROJECT_NAME} PRIVATE eigen)
target_link_libraries(${PROJECT_NAME} PRIVATE matplot)

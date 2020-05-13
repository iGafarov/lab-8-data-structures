cmake_minimum_required(VERSION 3.8)
add_executable(lab-8-data_structures OrderedVector.h UnorderedSet.h AVLTree.h Clock.h main.cpp)
target_link_libraries(lab-8-data_structures utils_static)
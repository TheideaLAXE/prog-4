cmake_minimum_required(VERSION 4.4)
project(BFS_DFS)

set(CMAKE_CXX_STANDARD 14)

add_executable(BFS_DFS
        BFS-AdjList/main.cpp
        DFS-AdjList/main.cpp
        BFS-AdjMatrix/main.cpp)

#include <gtest/gtest.h>

#include "../core/controller/controller.h"

namespace ps {

    TEST(Searcher, Test_1) {
        MazeModel maze_model;
        Controller controller(&maze_model);
        controller.OpenFile("../../data/maze_4x4.txt");
        controller.SearchShortestPath(0, 0, 3, 3);
        Maze res = maze_model.GetMaze();
//        for (const auto& row : res) {
//            for (const int& elem : row) {
//                std::cout << elem << " ";
//            }
//            std::cout << "\n";
//        }
        Maze expected_res = {{6,4,6,5}, {1,0,3,5}, {2,3,4,7}, {2,2,6,7}};
        ASSERT_EQ(res, expected_res);
    }
} // ps
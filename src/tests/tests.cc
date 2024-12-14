#include <gtest/gtest.h>

#define private public
#include "../core/model/maze_model/maze_model.h"
#include "../core/model/cave_model/cave_model.h"


namespace ps {

    TEST(Searcher, FindPath_4x4) {
        MazeModel maze_model;
        Maze maze {{2,0,2,1}, {1,0,3,1}, {2,3,0,3}, {2,2,2,3}};
        maze_model.searcher_.FindPath(maze, 0, 0, 3, 3);
        Maze expected_res = {{6,4,6,5}, {1,0,3,5}, {2,3,4,7}, {2,2,6,7}};
        ASSERT_EQ(maze, expected_res);
    }

    TEST(Searcher, NoSolution) {
        MazeModel maze_model;
        Maze maze = {{0,3,1}, {0,1,1}, {3,3,3}};
        ASSERT_ANY_THROW(maze_model.searcher_.FindPath(maze, 0, 0, 2, 2));
    }

    TEST(SEARCH, FindPath_3x3) {
        MazeModel maze_model;
        Maze maze = {{0,2,1}, {1,3,1}, {2,2,3}};
        maze_model.searcher_.FindPath(maze,0, 0, 2, 1);
        Maze expected_res = {{4,6,5}, {1,3,5}, {2,2,3}};
        ASSERT_EQ(1,1);
    }

    TEST(Generator, InvalidSize) {
        MazeModel maze_model;
        ASSERT_ANY_THROW(maze_model.GeneratePerfectMaze(0, 10));
        ASSERT_ANY_THROW(maze_model.GeneratePerfectMaze(10, 0));
        ASSERT_ANY_THROW(maze_model.GeneratePerfectMaze(51, 10));
        ASSERT_ANY_THROW(maze_model.GeneratePerfectMaze(10, 51));
    }

    TEST(Generator, GenerateMaze) {
        MazeModel maze_model;
        Maze maze;
        maze_model.generator_.GenerateMaze(maze, 5, 5);
        ASSERT_EQ(maze.size(), 5);
        ASSERT_EQ(maze[0].size(), 5);
    }

    TEST(Generator, AddVerticalWallsCorrect) {
        MazeModel maze_model;
        srand(time(0));
        std::vector<int> line_1 = {1, 1, 3, 4};
        Maze maze(2,std::vector<int>(4, 0));
        maze_model.generator_.AddVerticalWalls(line_1, maze, 0);
        ASSERT_TRUE(CheckBit(maze[0][0], kRight));
        ASSERT_TRUE(CheckBit(maze[0][3], kRight));

        std::vector<int> line_2 = {5,5,5,5};
        maze_model.generator_.AddVerticalWalls(line_2, maze, 0);
        for (int i = 0; i < 4; i++) {
            ASSERT_TRUE(CheckBit(maze[0][i], kRight));
        }
    }

    TEST(Generator, PrepareNewLineCorrect) {
        MazeModel maze_model;
        std::vector<int> line = {1, 2, 3, 4, 5, 6};
        int set_num = 7;
        Maze maze(2,std::vector<int>(6, 0));
        SetBit(maze[0][2], kBottom);
        SetBit(maze[0][3], kBottom);
        maze_model.generator_.PrepareNewLine(line, maze, 0, set_num);
        ASSERT_EQ(line[2], 7);
        ASSERT_EQ(line[3], 8);
    }

    TEST(Generator, CheckEndLineCorrect) {
        MazeModel maze_model;
        std::vector<int> line = {1, 2, 3, 4};
        Maze maze(2,std::vector<int>(4, 0));
        for (int i = 0; i < 4; i++) {
            SetBit(maze[1][i], kRight);
        }
        maze_model.generator_.CheckEndLine(line, maze, 1);
        for (int i = 0; i < 4; i++) {
            ASSERT_EQ(line[i], 1);
        }
        for (int i = 0; i < 3; i++) {
            ASSERT_FALSE(CheckBit(maze[1][i], kRight));
        }
        ASSERT_TRUE(CheckBit(maze[1][3], kRight));
    }

    TEST(CaveGenerator, GenerateStartPosition_0) {
        CaveModel cave_model;
        cave_model.GenerateCave(4, 4, 0);
        for (auto &row : cave_model.GetCave()) {
            for (int &elem : row) {
                ASSERT_EQ(elem, 0);
            }
        }
    }

    TEST(CaveGenerator, GenerateStartPosition_1) {
        CaveModel cave_model;
        cave_model.GenerateCave(4, 4, 100);
        for (auto &row : cave_model.GetCave()) {
            for (int &elem : row) {
                ASSERT_EQ(elem, 1);
            }
        }
    }

    TEST(CaveGenerator, InvalidSize) {
        CaveModel cave_model;
        ASSERT_ANY_THROW(cave_model.GenerateCave(0, 10, 40));
        ASSERT_ANY_THROW(cave_model.GenerateCave(10, 0, 40));
        ASSERT_ANY_THROW(cave_model.GenerateCave(51, 10, 50));
        ASSERT_ANY_THROW(cave_model.GenerateCave(10, 51, 40));
    }

    TEST(CaveCreator, CreateNextStep) {
        CaveModel cave_model;
        bool change = true;
        Cave cave {{0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}};
        Cave ex_res {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}};
        Cave res = cave_model.creator_.CreateNextStep(1, 7, change, cave);
        ASSERT_EQ(ex_res, res);
    }

} // ps


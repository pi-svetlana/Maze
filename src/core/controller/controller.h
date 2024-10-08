#ifndef MAZE_CONTROLLER_H
#define MAZE_CONTROLLER_H

#include <iostream>
//#include "../model/m
#include <model/maze_model.h>

namespace ps {

    class Controller {
    public:
        Controller(MazeModel* model) : maze_model_(model){}
        ~Controller() {}
        Maze& OpenFile(const std::string& file_path);
        void CreateFile(const std::string& file_path);
        Maze& GeneratePerfectMaze(const size_t rows, const size_t cols);
        Maze& SearchShortestPath(int start_x, int start_y, int finish_x, int finish_y);
        Maze& ClearPath();

    private:
        MazeModel* maze_model_;
    };

} // ps

#endif //MAZE_CONTROLLER_H

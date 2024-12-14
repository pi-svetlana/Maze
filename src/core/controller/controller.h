#ifndef MAZE_CONTROLLER_H
#define MAZE_CONTROLLER_H

#include <iostream>
#include <model/maze_model/maze_model.h>
#include <model/cave_model/cave_model.h>

namespace ps {

    class Controller {
    public:
        Controller(MazeModel* maze_model, CaveModel* cave_model) : maze_model_(maze_model), cave_model_(cave_model){}
        ~Controller() {}
        Maze& OpenFile(const std::string& file_path);
        void CreateFile(const std::string& file_path);
        Maze& GeneratePerfectMaze(const size_t rows, const size_t cols);
        Maze& SearchShortestPath(int start_x, int start_y, int finish_x, int finish_y);
        Maze& ClearPath();

        Cave& GenerateCave(const size_t rows, const size_t cols, const size_t chance);
        Cave& OpenCave(const std::string& file_path);
        void CreateCaveFile(const std::string& file_path);

        Cave& CreateNextStep(const size_t birth_limit, const size_t death_limit, bool& change);

    private:
        MazeModel* maze_model_;
        CaveModel* cave_model_;
    };

} // ps

#endif //MAZE_CONTROLLER_H

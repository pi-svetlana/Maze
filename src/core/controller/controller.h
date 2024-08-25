#ifndef MAZE_CONTROLLER_H
#define MAZE_CONTROLLER_H

#include <iostream>

namespace ps {

    class controller {
    public:
        void OpenFile(std::string file_path);
        void CreateFile();
        void GeneratePerfectMaze(const int rows, const int cols);
        void SearchShortestPath();

    private:
//        MazeModel maze_model_;
    };

} // ps

#endif //MAZE_CONTROLLER_H

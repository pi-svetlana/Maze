#ifndef MAZE_MAZE_MODEL_H
#define MAZE_MAZE_MODEL_H

#include "../utils/utils.h"
#include "generator.h"
#include "reader.h"
#include "writer.h"

namespace ps {

    class MazeModel {
    public:
        MazeModel() {};
        ~MazeModel() {};

        void OpenFile(const std::string& file_path);
        void CreateFile(const std::string& file_path);
        void GeneratePerfectMaze(size_t rows, size_t cols);
        void SearchShortestPath();
        Maze& GetMaze();

    private:
        Generator generator_;
        Reader reader_;
        Writer writer_;
        Maze maze_;
    };

} // ps

#endif //MAZE_MAZE_MODEL_H

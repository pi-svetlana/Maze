#include "maze_model.h"

namespace ps {
    void MazeModel::OpenFile(const std::string& file_path) {
        reader_.ReadFile(file_path, maze_);
    }

    void MazeModel::CreateFile(const std::string& file_path) {
        writer_.WriteFile(file_path, maze_);
    }

    void MazeModel::GeneratePerfectMaze(const size_t rows, const size_t cols) {
        generator_.GenerateMaze(maze_, rows, cols);
    }

    void MazeModel::SearchShortestPath() {

    }

    Maze& MazeModel::GetMaze() {
        return maze_;
    }

} // ps
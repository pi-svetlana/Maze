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

    void MazeModel::SearchShortestPath(const int start_x, const int start_y, const int finish_x, const int finish_y) {
        searcher_.FindPath(maze_, start_x, start_y, finish_x, finish_y);
    }

    void MazeModel::ClearPathInMaze() {
        ClearPath(maze_);
    }

    Maze& MazeModel::GetMaze() {
        return maze_;
    }

} // ps
#include "controller.h"

namespace ps {
    Maze& Controller::OpenFile(const std::string& file_path) {
        maze_model_->OpenFile(file_path);
        return maze_model_->GetMaze();
    }

    void Controller::CreateFile(const std::string& file_path) {
        maze_model_->CreateFile(file_path);
    }

    Maze& Controller::GeneratePerfectMaze(const size_t rows, const size_t cols) {
        maze_model_->GeneratePerfectMaze(rows, cols);
        return maze_model_->GetMaze();
    }

    Maze& Controller::SearchShortestPath(const int start_x, const int start_y, const int finish_x, const int finish_y) {
        maze_model_->SearchShortestPath(start_x, start_y, finish_x, finish_y);
        return maze_model_->GetMaze();
    }

} // ps

//int main() {
//    ps::Maze maze;
//    ps::Reader reader;
//    ps::Controller controller;
//    reader.ReadFile("maze_4x4.txt");
//    maze = reader.GetData();
//    for(auto& row : maze) {
//        for (int& elem : row) {
//            std::cout << elem << " ";
//        }
//        std::cout << "\n";
//    }
//}
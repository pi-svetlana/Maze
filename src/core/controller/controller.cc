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

    void Controller::SearchShortestPath() {

    }

} // ps

//int main() {
//    ps::Maze maze;
//    ps::Reader reader;
//    ps::Controller controller;
//    reader.ReadFile("matrix.txt");
//    maze = reader.GetData();
//    for(auto& row : maze) {
//        for (int& elem : row) {
//            std::cout << elem << " ";
//        }
//        std::cout << "\n";
//    }
//}
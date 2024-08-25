#include "reader.h"

#include <iostream>

namespace ps {
void Reader::ReadFile(const std::string &file_path) {
  std::ifstream stream(file_path);
  if (!stream.is_open()) throw std::runtime_error("Invalid file");
  size_t rows, cols;
  char ch;
  if (!(stream >> rows >> cols) || rows < 2 || cols < 2)
    throw std::runtime_error("Invalid file");
  maze_.resize(rows, std::vector<int>(cols, 0));

//  maze_->vertical_walls.resize(rows, std::vector<int>(cols, 0));
//  maze_->horizontal_walls.resize(rows, std::vector<int>(cols, 0));
  ReadMatrix(stream, kRight);
  ReadMatrix(stream, kBottom);
  if (stream >> ch) throw std::runtime_error("Invalid file");
}

void Reader::ReadMatrix(std::ifstream &stream, Blocks type) {
    for (auto &row : maze_) {
        for (int &elem : row) {
            if(!(stream >> elem && (elem == 1 || elem == 0)))
                throw std::runtime_error("Invalid file");
            if (elem == 1) SetBit(elem, type);
        }
    }

//  for (auto & i : matrix) {
//    for (int & j : i) {
//      if (!(stream >> j && (j == 1 || j == 0)))
//        throw std::runtime_error("Invalid file");
//      if (j == 1) setBit(j, type);
//    }
//  }
}

}  // namespace ps

//int main() {
//    ps::Maze maze;
//    ps::Reader reader(maze);
//    reader.ReadFile("matrix.txt");
//    std::cout << "ok\n";
//}
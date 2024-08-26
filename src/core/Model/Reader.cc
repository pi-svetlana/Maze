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

  ReadMatrix(stream, kRight);
  ReadMatrix(stream, kBottom);
  if (stream >> ch) throw std::runtime_error("Invalid file");
}

void Reader::ReadMatrix(std::ifstream &stream, Blocks type) {
    int tmp = 0;
    for(auto& row : maze_) {
        for (int& elem : row) {
            if(!(stream >> tmp && (tmp == 1 || tmp == 0)))
                throw std::runtime_error("Invalid file");
            if (tmp == 1) SetBit(elem, type);
        }
    }
}

Maze& Reader::GetData() {
    return maze_;
}

}  // namespace ps
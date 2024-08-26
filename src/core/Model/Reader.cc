#include "reader.h"

#include <iostream>

namespace ps {
void Reader::ReadFile(const std::string &file_path, Maze& maze) {
  maze.clear();
  std::ifstream stream(file_path);
  if (!stream.is_open()) throw std::runtime_error("Не удалось открыть файл");
  size_t rows, cols;
  char ch;
  if (!(stream >> rows >> cols) || rows < 2 || cols < 2)
    throw std::runtime_error("Invalid file");
  maze.resize(rows, std::vector<int>(cols, 0));
  ReadMatrix(stream, maze, kRight);
  ReadMatrix(stream, maze, kBottom);
  if (stream >> ch) throw std::runtime_error("Не удалось открыть файл");
}

void Reader::ReadMatrix(std::ifstream &stream,  Maze& maze, Blocks type) {
    int tmp = 0;
    for(auto& row : maze) {
        for (int& elem : row) {
            if(!(stream >> tmp && (tmp == 1 || tmp == 0)))
                throw std::runtime_error("Не удалось открыть файл");
            if (tmp == 1) SetBit(elem, type);
        }
    }
}
}  // namespace ps

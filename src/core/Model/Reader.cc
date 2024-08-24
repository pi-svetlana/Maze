#include "reader.h"

#include <iostream>

namespace ps {
void Reader::ReadFile(std::string &file_path) {
  std::ifstream stream(file_path);
  if (!stream.is_open()) throw std::runtime_error("Invalid file");
  size_t rows, cols;
  char ch;
  if (!(stream >> rows >> cols) || rows < 2 || cols < 2)
    throw std::runtime_error("Invalid file");
  maze_->vertical_walls.resize(rows, std::vector<int>(cols, 0));
  maze_->horizontal_walls.resize(rows, std::vector<int>(cols, 0));
  ReadMatrix(stream, maze_->vertical_walls, rows, cols);
  ReadMatrix(stream, maze_->horizontal_walls, rows, cols);
  if (stream >> ch) throw std::runtime_error("Invalid file");
}

void Reader::ReadMatrix(std::ifstream &stream,
                        std::vector<std::vector<int> > &matrix, size_t rows,
                        size_t cols) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (!(stream >> matrix[i][j] && (matrix[i][j] == 1 || matrix[i][j] == 0)))
        throw std::runtime_error("Invalid file");
    }
  }
}

}  // namespace ps
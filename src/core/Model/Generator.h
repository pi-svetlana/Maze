#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <iostream>

#include "../utils/utils.h"

namespace ps {
class Generator {
 public:
  explicit Generator(Maze& maze) : maze_(maze){};
  ~Generator(){};
  void GenerateMaze(size_t rows, size_t cols);

 private:
    Maze maze_;
  void AddVerticalWalls(std::vector<int>& line, size_t row);
  void AddHorizontalWalls(std::vector<int>& line, size_t row);
  void PrepareNewLine(std::vector<int>& line, size_t row, int& set_num);
  void CheckEndLine(std::vector<int>& line, size_t row);
};
}  // namespace ps

#endif  // MAZE_GENERATOR_H

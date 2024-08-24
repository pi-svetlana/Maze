#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <iostream>

#include "../utils/utils.h"

namespace ps {
class Generator {
 public:
  Generator(){};
  ~Generator(){};
  Maze* GenerateMaze(size_t rows, size_t cols);

 private:
  static void AddVerticalWalls(std::vector<int>& line,
                               std::vector<std::vector<int> >& vertical_walls,
                               size_t row);
  static void AddHorizontalWalls(
      std::vector<int>& line, std::vector<std::vector<int> >& horizontal_walls,
      size_t row);
  static void PrepareNewLine(std::vector<int>& line,
                             std::vector<std::vector<int> >& horizontal_walls,
                             size_t row, int& set_num);
  static void CheckEndLine(std::vector<int>& line,
                           std::vector<std::vector<int> >& vertical_walls,
                           size_t row);
};
}  // namespace ps

#endif  // MAZE_GENERATOR_H

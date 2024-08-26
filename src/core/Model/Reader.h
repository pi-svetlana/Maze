#ifndef MAZE_READER_H
#define MAZE_READER_H

#include <fstream>

#include "../utils/utils.h"

namespace ps {
class Reader {
 public:
  Reader() {}
  ~Reader() {}
  void ReadFile(const std::string &file_path, Maze& maze);

 private:
  void ReadMatrix(std::ifstream &stream,  Maze& maze, Blocks type);
};
}  // namespace ps

#endif  // MAZE_READER_H

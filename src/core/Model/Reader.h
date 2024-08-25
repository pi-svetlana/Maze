#ifndef MAZE_READER_H
#define MAZE_READER_H

#include <fstream>
#include <regex>

#include "../utils/utils.h"

namespace ps {
class Reader {
 public:
  explicit Reader(Maze &maze) : maze_(maze){}
  ~Reader() {}
  void ReadFile(const std::string &file_path);

 private:
  Maze maze_;
  void ReadMatrix(std::ifstream &stream,  Blocks type);
};
}  // namespace ps

#endif  // MAZE_READER_H

#ifndef MAZE_READER_H
#define MAZE_READER_H

#include <fstream>
#include <regex>

#include "../utils/utils.h"

namespace ps {
class Reader {
 public:
  Reader() {}
  ~Reader() {}
  void ReadFile(const std::string &file_path);
  ps::Maze& GetData();

 private:
  ps::Maze maze_;
  void ReadMatrix(std::ifstream &stream,  ps::Blocks type);
};
}  // namespace ps

#endif  // MAZE_READER_H

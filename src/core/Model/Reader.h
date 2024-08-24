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
  void ReadFile(std::string &file_path);

 private:
  Maze *maze_;
  static void ReadMatrix(std::ifstream &stream,
                         std::vector<std::vector<int> > &matrix, size_t rows,
                         size_t cols);
  //        std::ifstream stream_;
  //        std::regex number_("^[01]");
};
}  // namespace ps

#endif  // MAZE_READER_H

#include "generator.h"

namespace ps {
Maze* Generator::GenerateMaze(size_t rows, size_t cols) {
  Maze* res = new Maze();
  res->vertical_walls.resize(rows, std::vector<int>(cols, 0));
  res->horizontal_walls.resize(rows, std::vector<int>(cols, 0));
  int set_num = 1;
  std::vector<int> line;
  for (size_t i = 0; i < cols; ++i) {
    line.push_back(set_num++);
  }
  srand(time(0));
  for (size_t i = 0; i < rows - 1; ++i) {
    AddVerticalWalls(line, res->vertical_walls, i);
    AddHorizontalWalls(line, res->horizontal_walls, i);
    PrepareNewLine(line, res->horizontal_walls, i, set_num);
  }
  AddVerticalWalls(line, res->vertical_walls, rows - 1);
  for (size_t i = 0; i < cols; ++i) {
    res->horizontal_walls[rows - 1][i] = 1;
  }
  CheckEndLine(line, res->vertical_walls, rows - 1);
  return res;
}

void Generator::AddVerticalWalls(std::vector<int>& line,
                                 std::vector<std::vector<int> >& vertical_walls,
                                 const size_t row) {
  for (size_t i = 0; i < line.size() - 1; ++i) {
    int choice = rand() % 2;
    if (line[i] == line[i + 1] || choice == 1) {
      vertical_walls[row][i] = 1;
    } else {
      const int element = line[i + 1];
      for (size_t j = 0; j < line.size(); ++j) {
        if (line[j] == element) {
          line[j] = line[i];
        }
      }
    }
  }
  vertical_walls[row][line.size() - 1] = 1;
}

void Generator::AddHorizontalWalls(
    std::vector<int>& line, std::vector<std::vector<int> >& horizontal_walls,
    const size_t row) {
  for (size_t i = 0; i < line.size(); ++i) {
    int choice = rand() % 2;
    if (choice == 1) {
      const int element = line[i];
      int count_elements = 0;
      for (size_t j = 0; j < line.size(); ++j) {
        if (line[j] == element && horizontal_walls[row][j] == 0)
          count_elements++;
      }
      if (count_elements > 1) horizontal_walls[row][i] = 1;
    }
  }
}

void Generator::PrepareNewLine(std::vector<int>& line,
                               std::vector<std::vector<int> >& horizontal_walls,
                               const size_t row, int& set_num) {
  for (size_t i = 0; i < line.size(); ++i) {
    if (horizontal_walls[row][i] == 1) line[i] = set_num++;
  }
}

void Generator::CheckEndLine(std::vector<int>& line,
                             std::vector<std::vector<int> >& vertical_walls,
                             const size_t row) {
  for (size_t i = 0; i < line.size() - 1; ++i) {
    if (line[i] != line[i + 1] && vertical_walls[row][i] == 1) {
      vertical_walls[row][i] = 0;
      const int element = line[i + 1];
      for (size_t j = 0; j < line.size(); ++j) {
        if (line[j] == element) line[j] = line[i];
      }
    }
  }
}

}  // namespace ps

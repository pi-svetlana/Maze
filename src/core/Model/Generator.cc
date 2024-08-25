#include "generator.h"

namespace ps {
void Generator::GenerateMaze(size_t rows, size_t cols) {
//  Maze* res = new Maze();
//  res->vertical_walls.resize(rows, std::vector<int>(cols, 0));
//  res->horizontal_walls.resize(rows, std::vector<int>(cols, 0));
    maze_.resize(rows, std::vector<int>(cols, 0));
  int set_num = 1;
  std::vector<int> line;
  for (size_t i = 0; i < cols; ++i) {
    line.push_back(set_num++);
  }
  srand(time(0));
  for (size_t i = 0; i < rows - 1; ++i) {
    AddVerticalWalls(line, i);
    AddHorizontalWalls(line, i);
    PrepareNewLine(line, i, set_num);
  }
  AddVerticalWalls(line, rows - 1);
  for (size_t i = 0; i < cols; ++i) {
      SetBit(maze_[rows - 1][i], kBottom);
  }
  CheckEndLine(line, rows - 1);
}

void Generator::AddVerticalWalls(std::vector<int>& line, const size_t row) {
  for (size_t i = 0; i < line.size() - 1; ++i) {
    int choice = rand() % 2;
    if (line[i] == line[i + 1] || choice == 1) {
        SetBit(maze_[row][i], kRight);
    } else {
      const int element = line[i + 1];
      for (size_t j = 0; j < line.size(); ++j) {
        if (line[j] == element) {
          line[j] = line[i];
        }
      }
    }
  }
  SetBit(maze_[row][line.size() - 1], kRight);
}

void Generator::AddHorizontalWalls(std::vector<int>& line, const size_t row) {
  for (size_t i = 0; i < line.size(); ++i) {
    int choice = rand() % 2;
    if (choice == 1) {
      const int element = line[i];
      int count_elements = 0;
      for (size_t j = 0; j < line.size(); ++j) {
        if (line[j] == element && !CheckBit(maze_[row][j], kBottom))
          count_elements++;
      }
      if (count_elements > 1) SetBit(maze_[row][i], kBottom);
    }
  }
}

void Generator::PrepareNewLine(std::vector<int>& line, const size_t row, int& set_num) {
  for (size_t i = 0; i < line.size(); ++i) {
    if (CheckBit(maze_[row][i], kBottom)) line[i] = set_num++;
  }
}

void Generator::CheckEndLine(std::vector<int>& line, const size_t row) {
  for (size_t i = 0; i < line.size() - 1; ++i) {
    if (line[i] != line[i + 1] && CheckBit(maze_[row][i], kRight)) {
        ClearBit(maze_[row][i], kRight);
      const int element = line[i + 1];
      for (size_t j = 0; j < line.size(); ++j) {
        if (line[j] == element) line[j] = line[i];
      }
    }
  }
}

}  // namespace ps

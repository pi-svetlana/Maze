#include "generator.h"

namespace ps {
void Generator::GenerateMaze(Maze& maze, size_t rows, size_t cols) {
  maze.clear();
  if (rows > max_maze_size || cols > max_maze_size || rows < min_maze_size || cols < min_maze_size)
      throw std::runtime_error("Недопустимые размеры лабиринта");
  maze.resize(rows, std::vector<int>(cols, 0));
  int set_num = 1;
  std::vector<int> line;
  for (size_t i = 0; i < cols; ++i) {
    line.push_back(set_num++);
  }
  srand(time(0));
  for (size_t i = 0; i < rows - 1; ++i) {
    AddVerticalWalls(line, maze,i);
    AddHorizontalWalls(line, maze, i);
    PrepareNewLine(line, maze, i, set_num);
  }
  AddVerticalWalls(line, maze, rows - 1);
  for (size_t i = 0; i < cols; ++i) {
      SetBit(maze[rows - 1][i], kBottom);
  }
  CheckEndLine(line,maze, rows - 1);
}

void Generator::AddVerticalWalls(std::vector<int>& line, Maze& maze, const size_t row) {
  for (size_t i = 0; i < line.size() - 1; ++i) {
    int choice = rand() % 2;
    if (line[i] == line[i + 1] || choice == 1) {
        SetBit(maze[row][i], kRight);
    } else {
      const int element = line[i + 1];
      for (size_t j = 0; j < line.size(); ++j) {
        if (line[j] == element) {
          line[j] = line[i];
        }
      }
    }
  }
  SetBit(maze[row][line.size() - 1], kRight);
}

void Generator::AddHorizontalWalls(std::vector<int>& line, Maze& maze, const size_t row) {
  for (size_t i = 0; i < line.size(); ++i) {
    int choice = rand() % 2;
    if (choice == 1) {
      const int element = line[i];
      int count_elements = 0;
      for (size_t j = 0; j < line.size(); ++j) {
        if (line[j] == element && !CheckBit(maze[row][j], kBottom))
          count_elements++;
      }
      if (count_elements > 1) SetBit(maze[row][i], kBottom);
    }
  }
}

void Generator::PrepareNewLine(std::vector<int>& line, Maze& maze, const size_t row, int& set_num) {
  for (size_t i = 0; i < line.size(); ++i) {
    if (CheckBit(maze[row][i], kBottom)) line[i] = set_num++;
  }
}

void Generator::CheckEndLine(std::vector<int>& line, Maze& maze, const size_t row) {
  for (size_t i = 0; i < line.size() - 1; ++i) {
    if (line[i] != line[i + 1] && CheckBit(maze[row][i], kRight)) {
        ClearBit(maze[row][i], kRight);
      const int element = line[i + 1];
      for (size_t j = 0; j < line.size(); ++j) {
        if (line[j] == element) line[j] = line[i];
      }
    }
  }
}

}  // namespace ps

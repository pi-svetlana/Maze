#include "searcher.h"

#include <queue>

namespace ps {

void Searcher::FindPath(Maze& maze, const int start_x, const int start_y, const int finish_x, const int finish_y) {
  if (!maze.empty()) {
      int start = start_y * maze[0].size() + start_x;
      int finish = finish_y * maze[0].size() + finish_x;
      Maze adjacency_list;
      CreateAdjacencyList(maze, adjacency_list);
      std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
      std::vector<int> distances(adjacency_list.size(), std::numeric_limits<int>::max());
      std::vector<int> prev_top(adjacency_list.size(), std::numeric_limits<int>::min());
      distances[start] = 0;
      prev_top[start] = -1;
      pq.emplace(0, start);
      while (!pq.empty()) {
          int cur_distance = pq.top().first;
          int cur_node = pq.top().second;
          pq.pop();
          if (cur_distance > distances[cur_node]) continue;
          for (const int &elem: adjacency_list[cur_node]) {
              int new_distance = cur_distance + 1;
              if (new_distance < distances[elem]) {
                  distances[elem] = new_distance;
                  prev_top[elem] = cur_node;
                  pq.emplace(new_distance, elem);
              }
          }
      }
      if(distances[finish] ==std::numeric_limits<int>::max())
          throw std::runtime_error("Решения нет!");
      AddPathToMaze(maze, prev_top, start, finish);
  }
}

void Searcher::CreateAdjacencyList(const Maze& maze, Maze& adjacency_list) {
  int rows = (int)maze.size();
  int cols = (int)maze[0].size();
  adjacency_list.resize(rows * cols);
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      int current_idx = r * cols + c;
      if (c < cols - 1 && !CheckBit(maze[r][c], kRight)) {
        int right_idx = r * cols + c + 1;
        adjacency_list[current_idx].push_back(right_idx);
          adjacency_list[right_idx].push_back(current_idx);
      }
      if (r < rows - 1 && !CheckBit(maze[r][c], kBottom)) {
        int bottom_idx = (r + 1) * cols + c;
        adjacency_list[current_idx].push_back(bottom_idx);
          adjacency_list[bottom_idx].push_back(current_idx);
      }
    }
  }
}

void Searcher::AddPathToMaze(Maze& maze, const std::vector<int>& prev_top, const int start, const int finish) {
    std::vector<int> path;
    size_t rows = maze.size();
    size_t cols = maze[0].size();
    for (int i = finish; i != -1; i = prev_top[i]) {
        path.push_back(i);
    }
    for(const int& elem : path) {
        SetBit(maze[elem / cols][elem % cols], kPath);
    }
//    for(const int& elem : path) std::cout << elem << " ";
//    for (const auto& row : maze) {
//        for (const int& elem : row) {
//            std::cout << elem << " ";
//        }
//        std::cout << "\n";
//    }
}

}  // namespace ps


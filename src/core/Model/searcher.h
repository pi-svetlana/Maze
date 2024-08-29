#ifndef MAZE_SEARCHER_H
#define MAZE_SEARCHER_H

#include "../utils/utils.h"

namespace ps {
class Searcher {
 public:
  void FindPath(Maze& maze, int start_x, int start_y, int finish_x, int finish_y);

 private:
    void CreateAdjacencyList(const Maze& maze, Maze& adjacency_list);
    void AddPathToMaze(Maze& maze, const std::vector<int>& prev_top, int start, int finish);
};

}  // namespace ps

#endif  // MAZE_SEARCHER_H

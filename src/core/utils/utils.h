#ifndef MAZE_UTILS_H
#define MAZE_UTILS_H
#include <vector>

namespace ps {
struct Maze {
    Maze() {}
    ~Maze() {}
    std::vector<std::vector<int> > vertical_walls;
    std::vector<std::vector<int> > horizontal_walls;
};

} // ps

#endif //MAZE_UTILS_H

#ifndef MAZE_UTILS_H
#define MAZE_UTILS_H
#include <vector>

namespace ps {
    typedef std::vector<std::vector<int> > Maze;
    const int max_maze_size = 50;
    const int min_maze_size = 2;
    enum Blocks { kRight, kBottom, kPath };
    void SetBit(int &element, Blocks type);
    void ClearBit(int &element, Blocks type);
    bool CheckBit(const int &element, Blocks type);
    void ClearPath(Maze &maze);

//class Maze {
//public:
//    Maze() {}
//    ~Maze() {}
//    enum Blocks { kRight, kBottom, kPath };
//    void SetBit(int &element, Blocks type);
//    void ClearBit(int &element, Blocks type);
//    bool CheckBit(const int &element, Blocks type);
//    void ClearPath();
//    std::vector<std::vector<int> > maze_;
//};
} // ps

#endif //MAZE_UTILS_H

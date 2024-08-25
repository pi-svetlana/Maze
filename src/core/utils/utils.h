#ifndef MAZE_UTILS_H
#define MAZE_UTILS_H
#include <vector>

namespace ps {
//class Maze {
//public:
//    Maze() {}
//    ~Maze() {}
//    enum Blocks { kRight, kBottom, kPath };
//    void setBit(int &element, Blocks type);
//    bool checkBit(const int &element, Blocks type);
//private:
//    std::vector<std::vector<int> > maze;
//};
typedef std::vector<std::vector<int> > Maze;

enum Blocks { kRight, kBottom, kPath };
void SetBit(int &element, Blocks type);
void ClearBit(int &element, Blocks type);
bool CheckBit(const int &element, Blocks type);


//void setBit(std::vector<std::vector<int> >& maze, Blocks type, size_t row, size_t col);
//bool checkBit(std::vector<std::vector<int> >& maze, Blocks type, size_t row, size_t col);

} // ps

#endif //MAZE_UTILS_H

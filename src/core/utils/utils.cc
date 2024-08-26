#include "utils.h"
#include <vector>
#include <iostream>

namespace ps {
    void SetBit(int &element, const Blocks type) {
        element |= 1 << type;
    }

    void ClearBit(int &element, const Blocks type) {
        element &= ~(1 << type);
    }

    bool CheckBit(const int &element, const Blocks type) {
        return ((element >> type) & 1) == 1;
    }

    void ClearPath(Maze &maze) {
        for (auto &row : maze) {
            for (int &elem : row) {
                ClearBit(elem, kPath);
            }
        }
    }
} // ps

//int main() {
//    std::vector<std::vector<int> > maze;
//    size_t rows = 4, cols = 3;
//    maze.resize(rows, std::vector<int>(cols, 0));
//    setBit(maze[2][0], kBottom);
//    setBit(maze[2][0], kRight);
//    setBit(maze[3][2], kBottom);
//    setBit(maze[0][0], kRight);
//    if (checkBit(maze[2][0], kBottom)) std::cout << "Bottom!!!\n";
//    if (!checkBit(maze[0][0], kBottom)) std::cout << "No bottom!!!\n";
//    for (size_t i = 0; i < rows; ++i) {
//        for (size_t j = 0; j < cols; ++j) {
//            std::cout << maze[i][j] << " ";
//        }
//        std::cout << "\n";
//    }
//}

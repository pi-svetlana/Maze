#include "writer.h"

#include <iostream>
#include <fstream>

namespace ps {
    void Writer::WriteFile(const std::string &file_path, const Maze& maze) {
        std::ofstream stream(file_path);
        if(!stream || maze.empty()) throw std::runtime_error("Не удалось создать файл");
        stream << maze.size() << " " << maze[0].size() << "\n";
        for(const auto& row : maze) {
            for(const int& elem : row) {
                if (CheckBit(elem, kRight)) stream << "1 ";
                else stream << "0 ";
            }
            stream << "\n";
        }
        stream << "\n";
        for(const auto& row : maze) {
            for(const int& elem : row) {
                if (CheckBit(elem, kBottom)) stream << "1 ";
                else stream << "0 ";
            }
            stream << "\n";
        }
    }
}  // namespace ps

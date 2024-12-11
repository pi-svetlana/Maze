//
// Created by Светлана Пислякова on 25.11.2024.
//

#include "cave_generator.h"

namespace ps {
    void CaveGenerator::GenerateCave(Cave& cave, size_t rows, size_t cols, size_t chance) {
        cave.clear();
        if (rows > max_cave_size || cols > max_cave_size || rows < min_cave_size || cols < min_cave_size)
            throw std::runtime_error("Недопустимые размеры лабиринта");
        cave.resize(rows, std::vector<int>(cols, 0));
        srand(time(0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(rand() % 100 < chance) cave[i][j] = 1;
            }
        }
    }
} // ps
//
// Created by Светлана Пислякова on 11.12.2024.
//

#include "cave_creator.h"

namespace ps {
    Cave& CaveCreator::CreateNextStep(const size_t birth_limit, const size_t death_limit, bool& change, Cave& cave) {
        change = false;
        Cave temp = cave;
        for (int i = 0; i < cave.size(); ++i) {
            for (int j = 0; j < cave[i].size(); ++j) {
                int count = CountNeighbours(i, j, temp);
                if (temp[i][j] == 1 && count < death_limit) {
                    cave[i][j] = 0;
                    change = true;
                }
                if (temp[i][j] == 0 && count > birth_limit) {
                    cave[i][j] = 1;
                    change = true;
                }
            }
        }
        return cave;
    }

    int CaveCreator::CountNeighbours(const size_t row, const size_t col, Cave& cave) {
        int count = 0;
        size_t rows = cave.size();
        size_t cols = cave[0].size();
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int neighborRow = row + i;
                int neighborCol = col + j;
                if(neighborRow < 0 || neighborCol < 0 || neighborRow >= rows || neighborCol >= cols) count++;
                else if (cave[neighborRow][neighborCol] == 1) count++;
            }
        }
        return count;
    }


} // ps

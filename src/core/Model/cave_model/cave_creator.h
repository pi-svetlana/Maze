//
// Created by Светлана Пислякова on 11.12.2024.
//

#ifndef MAZE_CAVE_CREATOR_H
#define MAZE_CAVE_CREATOR_H

#include "../../utils/utils.h"

namespace ps {

    class CaveCreator {
    public:
        Cave& CreateNextStep(const size_t birth_limit, const size_t death_limit, bool& change, Cave& cave);
    private:
        int CountNeighbours(const size_t row, const size_t col, Cave& cave);
    };

} // ps

#endif //MAZE_CAVE_CREATOR_H

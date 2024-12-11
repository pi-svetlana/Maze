//
// Created by Светлана Пислякова on 25.11.2024.
//

#ifndef MAZE_CAVE_GENERATOR_H
#define MAZE_CAVE_GENERATOR_H

#include "../../utils/utils.h"

namespace ps {

    class CaveGenerator {
    public:
        CaveGenerator() {};
        ~CaveGenerator(){};
        void GenerateCave(Cave& cave, size_t rows, size_t cols, size_t chance);

    private:

    };

} // ps

#endif //MAZE_CAVE_GENERATOR_H

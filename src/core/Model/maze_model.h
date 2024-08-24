#ifndef MAZE_MAZE_MODEL_H
#define MAZE_MAZE_MODEL_H

#include "../utils//utils.h"
#include "generator.h"

namespace ps {

    class MazeModel {
    public:
        MazeModel() {};
        ~MazeModel() {};

    private:
        Generator generator_;
        std::unique_ptr<Maze> maze_;
    };

} // ps

#endif //MAZE_MAZE_MODEL_H

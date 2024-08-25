#ifndef MAZE_MAZE_MODEL_H
#define MAZE_MAZE_MODEL_H

#include "../utils//utils.h"
#include "generator.h"
#include "reader.h"

namespace ps {

    class MazeModel {
    public:
        MazeModel() : reader_(maze_), generator_(maze_){};
        ~MazeModel() {};

    private:
        Generator generator_;
        Reader reader_;
        Maze maze_;
//        std::unique_ptr<Maze> maze_;
    };

} // ps

#endif //MAZE_MAZE_MODEL_H

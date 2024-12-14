#ifndef MAZE_CAVE_MODEL_H
#define MAZE_CAVE_MODEL_H

#include "../../utils/utils.h"

#include "cave_generator.h"
#include "cave_reader.h"
#include "cave_writer.h"
#include "cave_creator.h"
//#include "searcher.h"

namespace ps {

    class CaveModel {
    public:
        CaveModel() {};
        ~CaveModel() {};

        void OpenFile(const std::string& file_path);
        void CreateFile(const std::string& file_path);
        void GenerateCave(const size_t rows, const size_t cols, const size_t chance);
        Cave& CreateNextStep(const size_t birth_limit, const size_t death_limit, bool& change);
        Cave& GetCave();

    private:
        CaveGenerator generator_;
        CaveReader reader_;
        CaveWriter writer_;
        CaveCreator creator_;
        Cave cave_;
    };

} // ps

#endif //MAZE_CAVE_MODEL_H

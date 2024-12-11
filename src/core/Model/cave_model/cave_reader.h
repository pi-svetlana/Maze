//
// Created by Светлана Пислякова on 26.11.2024.
//

#ifndef MAZE_CAVE_READER_H
#define MAZE_CAVE_READER_H

#include <fstream>

#include "../../utils/utils.h"

namespace ps {

    class CaveReader {
    public:
        CaveReader() {}
        ~CaveReader() {}
        void ReadFile(const std::string &file_path, Cave& cave);

    private:
        void ReadMatrix(std::ifstream &stream,  Cave& cave);
    };

} // ps

#endif //MAZE_CAVE_READER_H

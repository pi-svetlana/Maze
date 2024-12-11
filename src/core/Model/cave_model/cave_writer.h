//
// Created by Светлана Пислякова on 03.12.2024.
//

#ifndef MAZE_CAVE_WRITER_H
#define MAZE_CAVE_WRITER_H

#include <fstream>

#include "../../utils/utils.h"

namespace ps {

    class CaveWriter {
    public:
        CaveWriter() {}
        ~CaveWriter() {}
        void WriteFile(const std::string &file_path, const Cave& cave);

    private:
    };

} // ps

#endif //MAZE_CAVE_WRITER_H

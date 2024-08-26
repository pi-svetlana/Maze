#ifndef MAZE_WRITER_H
#define MAZE_WRITER_H

#include <fstream>

#include "../utils/utils.h"

namespace ps {
    class Writer {
    public:
        Writer() {}
        ~Writer() {}
        void WriteFile(const std::string &file_path, const Maze& maze);

    private:

    };
}  // namespace ps

#endif  // MAZE_WRITER_H
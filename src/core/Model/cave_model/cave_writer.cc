//
// Created by Светлана Пислякова on 03.12.2024.
//

#include "cave_writer.h"

#include <iostream>
#include <fstream>

namespace ps {
    void CaveWriter::WriteFile(const std::string &file_path, const Cave& cave) {
        std::ofstream stream(file_path);
        if(!stream || cave.empty()) throw std::runtime_error("Не удалось создать файл");
        stream << cave.size() << " " << cave[0].size() << "\n";
        for(const auto& row : cave) {
            for(const int& elem : row) {
                stream << elem << " ";
            }
            stream << "\n";
        }
        stream << "\n";
    }
} // ps
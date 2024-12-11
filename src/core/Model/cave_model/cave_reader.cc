//
// Created by Светлана Пислякова on 26.11.2024.
//

#include "cave_reader.h"

#include <iostream>

namespace ps {
    void CaveReader::ReadFile(const std::string &file_path, Cave& cave) {
        cave.clear();
        std::ifstream stream(file_path);
        if (!stream.is_open()) throw std::runtime_error("Не удалось открыть файл");
        size_t rows, cols;
        char ch;
        if (!(stream >> rows >> cols) || rows < 2 || cols < 2)
            throw std::runtime_error("Не удалось открыть файл");
        cave.resize(rows, std::vector<int>(cols, 0));
        ReadMatrix(stream, cave);
        if (stream >> ch) throw std::runtime_error("Не удалось открыть файл");
    }

    void CaveReader::ReadMatrix(std::ifstream &stream,  Cave& cave) {
        int tmp = 0;
        for(auto& row : cave) {
            for (int& elem : row) {
                if(!(stream >> tmp && (tmp == 1 || tmp == 0)))
                    throw std::runtime_error("Не удалось открыть файл");
                if (tmp == 1) elem = 1;
            }
        }
    }
} // ps
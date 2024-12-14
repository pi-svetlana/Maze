#include "cave_model.h"

namespace ps {

    void CaveModel::GenerateCave(const size_t rows, const size_t cols, const size_t chance) {
        generator_.GenerateCave(cave_, rows, cols, chance);
    }

    void CaveModel::OpenFile(const std::string& file_path) {
        reader_.ReadFile(file_path, cave_);
    }

    void CaveModel::CreateFile(const std::string& file_path) {
        writer_.WriteFile(file_path, cave_);
    }

    Cave& CaveModel::GetCave() {
        return cave_;
    }

    Cave& CaveModel::CreateNextStep(const size_t birth_limit, const size_t death_limit, bool& change) {
        return creator_.CreateNextStep(birth_limit, death_limit, change, cave_);
    }

} // ps

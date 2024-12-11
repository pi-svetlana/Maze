#include "cave.h"


Cave::Cave(QWidget *parent)
    : QWidget{parent}
{

}

void Cave::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    painter.setBrush(bg_color_);
    painter.drawRect(rect());

    if (!cave_.empty()) {
        float cell_width = (float)width() / cave_[0].size();
        float cell_height = (float)height() / cave_.size();
        painter.setPen(QPen(wall_color_, 2));
        painter.drawLine(1, 1, 1, height());
        painter.drawLine(1, 1, width(), 1);
        painter.drawLine(width() - 1, 1, width() - 1, height());
        painter.drawLine(1, height() - 1, width(), height() - 1);
        painter.setBrush(wall_color_);
        for (int i = 0; i < cave_.size(); ++i) {
            for (int j = 0; j < cave_[i].size(); ++j) {
                if (cave_[i][j] == 1) {
                    painter.drawRect(j * cell_width, i * cell_height, cell_width, cell_height);
                }
            }
        }
    }
}

void Cave::setCave(std::vector<std::vector<int>> cave) { cave_ = cave; }
void Cave::setBgColor(QColor color) { bg_color_ = color; }
void Cave::setWallColor(QColor color) { wall_color_ = color; }
ps::Cave& Cave::getCave() { return cave_; }
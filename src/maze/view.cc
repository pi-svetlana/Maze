#include "view.h"

View::View(QWidget *parent)
    : QWidget{parent}
{

}

void View::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    QBrush brush(bg_color_);
    painter.setBrush(brush);
    painter.drawRect(rect());

    painter.setPen(QPen(wall_color_, 2));
//    right_walls_ = {{1, 0, 1}, {0, 1, 1}, {0, 0, 1}};
//    bottom_walls_ = {{0, 0, 0}, {0, 1, 1}, {1, 1, 1}};

    if (!right_walls_.empty() && !bottom_walls_.empty()) {
    float cellWidth = (float)width() / right_walls_[0].size();
    float cellHeight = (float)height() / right_walls_.size();
    painter.drawLine(1, 1, 1, height());
    painter.drawLine(1, 1, width(), 1);
    painter.drawLine(width() - 1, 1, width() - 1, height());
    painter.drawLine(1, height() - 1, width(), height() - 1);
    for (int i = 0; i < right_walls_.size(); ++i) {
        for (int j = 0; j < right_walls_[0].size(); ++j) {
            if (right_walls_[i][j]) {
                painter.drawLine(j * cellWidth + cellWidth, i * cellHeight, j * cellWidth + cellWidth, i * cellHeight + cellHeight);
            }
            if (bottom_walls_[i][j]) {
                painter.drawLine(j * cellWidth, i * cellHeight + cellHeight, j * cellWidth + cellWidth, i * cellHeight + cellHeight);
            }
        }
    }
    }
}

void View::setBgColor(QColor color) { bg_color_ = color; }
void View::setWallColor(QColor color) { wall_color_ = color; }
void View::setPathColor(QColor color) { path_color_ = color; }
void View::setRightWalls(std::vector<std::vector<int>> vertical) { right_walls_ = vertical; }
void View::setBottomWalls(std::vector<std::vector<int>> horizontal) { bottom_walls_ = horizontal; }


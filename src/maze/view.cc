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
    QVector<QVector<bool>> rightWalls_ = {{1, 0, 1}, {0, 1, 1}, {0, 0, 1}};
    QVector<QVector<bool>> bottomWalls_ = {{0, 0, 0}, {0, 1, 1}, {1, 1, 1}};

    int cellWidth = width() / rightWalls_[0].size();
    int cellHeight = height() / rightWalls_.size();


    for (int i = 0; i < rightWalls_.size(); ++i) {
        for (int j = 0; j < rightWalls_[0].size(); ++j) {
            if (rightWalls_[i][j]) {
                painter.drawLine(j * cellWidth + cellWidth, i * cellHeight, j * cellWidth + cellWidth, i * cellHeight + cellHeight);
            }
            if (bottomWalls_[i][j]) {
                painter.drawLine(j * cellWidth, i * cellHeight + cellHeight, j * cellWidth + cellWidth, i * cellHeight + cellHeight);
            }
        }
    }
}

void View::setBgColor(QColor color) { bg_color_ = color; }
void View::setWallColor(QColor color) { wall_color_ = color; }
void View::setPathColor(QColor color) { path_color_ = color; }


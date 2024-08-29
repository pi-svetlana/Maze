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


    if (!maze_.empty()) {
    float cell_width = (float)width() / maze_[0].size();
    float cell_height = (float)height() / maze_.size();
    painter.drawLine(1, 1, 1, height());
    painter.drawLine(1, 1, width(), 1);
    painter.drawLine(width() - 1, 1, width() - 1, height());
    painter.drawLine(1, height() - 1, width(), height() - 1);
    for (int i = 0; i < maze_.size(); ++i) {
        for (int j = 0; j < maze_[i].size(); ++j) {
            if (ps::CheckBit(maze_[i][j], ps::kRight)) {
                painter.setPen(QPen(wall_color_, 2));
                painter.drawLine(j * cell_width + cell_width, i * cell_height, j * cell_width + cell_width, i * cell_height + cell_height);
            }
            if (ps::CheckBit(maze_[i][j], ps::kBottom)) {
                painter.setPen(QPen(wall_color_, 2));
                painter.drawLine(j * cell_width, i * cell_height + cell_height, j * cell_width + cell_width, i * cell_height + cell_height);
            }
            if(ps::CheckBit(maze_[i][j], ps::kPath)) {
                painter.setPen(QPen(path_color_, 2));
                if (i + 1 < maze_.size() && ps::CheckBit(maze_[i + 1][j], ps::kPath) && !ps::CheckBit(maze_[i][j], ps::kBottom)) { // вертикальная
                    painter.drawLine(j * cell_width + cell_width / 2, i * cell_height + cell_height/ 2, j * cell_width + cell_width / 2, i * cell_height + 1.5 * cell_height);
                }
                if (j + 1 < maze_[i].size() && ps::CheckBit(maze_[i][j + 1], ps::kPath) && !ps::CheckBit(maze_[i][j], ps::kRight)) { // горизонтальная
                    painter.drawLine(j * cell_width + cell_width / 2, i * cell_height + cell_height/ 2, j * cell_width + 1.5 * cell_width, i * cell_height + cell_height/ 2);
                }

            }
        }
    }
    if(start_selected_) { // вынести в отдельную функцию
        painter.setBrush(path_color_);
        painter.setPen(Qt::NoPen);
        float center_x = start_x_ * cell_width + cell_width / 2;
        float center_y = start_y_ * cell_height + cell_height / 2;
        int radius = cell_width > cell_height ? 0.25 * cell_height : 0.25 * cell_width;
        QPointF center = {center_x, center_y};
        painter.drawEllipse(center, radius, radius);
    }

    if(finish_selected_) { // вынести в отдельную функцию
        painter.setBrush(path_color_);
        painter.setPen(Qt::NoPen);
        float center_x = finish_x_ * cell_width + cell_width / 2;
        float center_y = finish_y_ * cell_height + cell_height / 2;
        int radius = cell_width > cell_height ? 0.25 * cell_height : 0.25 * cell_width;
        QPointF center = {center_x, center_y};
        painter.drawEllipse(center, radius, radius);
    }
    }
}

void View::setDrawMode(DrawMode mode) {
    draw_mode_ = mode;
}

void View::setStartSelected(bool enable) {
    start_selected_ = enable;
}

void View::setFinishSelected(bool enable) {
    finish_selected_ = enable;
}

void View::mousePressEvent(QMouseEvent *event) {
    if ((draw_mode_ == kStart || draw_mode_ == kFinish) && !maze_.empty()) {
        float cell_width = (float)width() / maze_[0].size();
        float cell_height = (float)height() / maze_.size();
        if (draw_mode_ == kStart) {
            start_x_ = floor(event->position().x() / cell_width);
            start_y_ = floor(event->position().y() / cell_height);
            start_selected_ = true;
        }
        if (draw_mode_ == kFinish) {
            finish_x_ = floor(event->position().x() / cell_width);
            finish_y_ = floor(event->position().y() / cell_height);
            finish_selected_ = true;
        }
        update();
        draw_mode_ = kNone;
    }
}

void View::setBgColor(QColor color) { bg_color_ = color; }
void View::setWallColor(QColor color) { wall_color_ = color; }
void View::setPathColor(QColor color) { path_color_ = color; }
void View::setMaze(std::vector<std::vector<int>> maze) { maze_ = maze; }

int View::getStartX() const { return start_x_; }
int View::getStartY() const { return start_y_; }
int View::getFinishX() const { return finish_x_; }
int View::getFinishY() const { return finish_y_; }


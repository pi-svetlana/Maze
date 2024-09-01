#ifndef VIEW_H
#define VIEW_H

#include <QPainter>
#include <QPen>
#include <QWidget>
#include <QMouseEvent>
#include <../core/utils/utils.h>
#include <../core/controller/controller.h>

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);
    enum DrawMode {kNone, kStart, kFinish};
    enum PainterMode {kMaze, kCave};
    void drawPoint(const int& x, const int&, const float& cell_width, const float& cell_height, QPainter& painter);
//    void drawMaze(QPainter& painter);
    void setBgColor(QColor);
    void setWallColor(QColor);
    void setPathColor(QColor);
    void setMaze(std::vector<std::vector<int>>);
    void setDrawMode(DrawMode mode);
//    void setPainterMode(PainterMode mode);
    void setStartSelected(bool enable);
    void setFinishSelected(bool enable);
    bool getStartSelected();
    bool getFinishSelected();
    ps::Maze& getMaze();
    int getStartX() const;
    int getStartY() const;
    int getFinishX() const;
    int getFinishY() const;

signals:

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QColor bg_color_ = Qt::gray;
    QColor wall_color_ = Qt::black;
    QColor path_color_ = Qt::red;
    DrawMode draw_mode_ = kNone;
    PainterMode painter_mode_ = kMaze;
    bool start_selected_ = false;
    bool finish_selected_ = false;
    int start_x_;
    int start_y_;
    int finish_x_;
    int finish_y_;
    ps::Maze maze_;
};

#endif // VIEW_H

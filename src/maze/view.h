#ifndef VIEW_H
#define VIEW_H

#include <QPainter>
#include <QPen>
#include <QWidget>

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);
    void setBgColor(QColor);
    void setWallColor(QColor);
    void setPathColor(QColor);
    void setRightWalls(std::vector<std::vector<int>>);
    void setBottomWalls(std::vector<std::vector<int>>);
signals:

protected:
    void paintEvent(QPaintEvent* event) override;
private:
    QColor bg_color_ = Qt::gray;
    QColor wall_color_ = Qt::black;
    QColor path_color_ = Qt::red;

    std::vector<std::vector<int>> right_walls_{};
    std::vector<std::vector<int>> bottom_walls_{};
};

#endif // VIEW_H

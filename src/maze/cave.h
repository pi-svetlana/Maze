#ifndef CAVE_H
#define CAVE_H

#include <QPainter>
#include <QPen>
#include <QWidget>
#include <../core/utils/utils.h>
#include <../core/controller/controller.h>


class Cave : public QWidget
{
    Q_OBJECT
public:
    explicit Cave(QWidget *parent = nullptr);
    void setCave(std::vector<std::vector<int>>);
    void setBgColor(QColor color);
    void setWallColor(QColor color);
    ps::Cave& getCave();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QColor bg_color_ = Qt::gray;
    QColor wall_color_ = Qt::black;

    ps::Cave cave_;
};

#endif // CAVE_H

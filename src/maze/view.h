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
signals:

protected:
    void paintEvent(QPaintEvent* event) override;
private:
    QColor bg_color_ = Qt::gray;
    QColor wall_color_ = Qt::black;
    QColor path_color_ = Qt::red;
    //    QVector<QVector<bool>> rightWalls_;
    //    QVector<QVector<bool>> bottomWalls_;
};

#endif // VIEW_H

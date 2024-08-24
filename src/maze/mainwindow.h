#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../core/utils/utils.h"
#include "../core/model/generator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bg_color_btn_clicked();

    void on_wall_color_btn_clicked();

    void on_path_color_btn_clicked();

    void on_generate_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

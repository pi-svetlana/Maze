#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../core/utils/utils.h"
#include <../core/controller/controller.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(ps::Controller* c, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bg_color_btn_clicked();
    void on_wall_color_btn_clicked();
    void on_path_color_btn_clicked();
    void on_generate_btn_clicked();
    void on_open_file_btn_clicked();
    void on_save_file_btn_clicked();
    void on_solve_btn_clicked();
    void on_choose_start_clicked();
    void on_choose_finish_clicked();
    void delete_points();

//    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    ps::Controller* controller_;
};
#endif // MAINWINDOW_H

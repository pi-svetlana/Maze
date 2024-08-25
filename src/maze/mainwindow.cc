#include <QColorDialog>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../core/utils/utils.h"
#include "../core/model/generator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bg_color_btn_clicked()
{
    QColor new_bg_color = QColorDialog::getColor(Qt::white, this);
      if (new_bg_color.isValid()) {
        ui->maze_window->setBgColor(new_bg_color);
        ui->maze_window->update();

        QString color = QString("background-color: %1;").arg(new_bg_color.name());
        ui->bg_color->setStyleSheet(color);
      }
}


void MainWindow::on_wall_color_btn_clicked()
{
    QColor new_wall_color = QColorDialog::getColor(Qt::white, this);
      if (new_wall_color.isValid()) {
        ui->maze_window->setWallColor(new_wall_color);
        ui->maze_window->update();

        QString color = QString("background-color: %1;").arg(new_wall_color.name());
        ui->wall_color->setStyleSheet(color);
      }
}


void MainWindow::on_path_color_btn_clicked()
{
    QColor new_path_color = QColorDialog::getColor(Qt::white, this);
      if (new_path_color.isValid()) {
        ui->maze_window->setPathColor(new_path_color);
        ui->maze_window->update();

        QString color = QString("background-color: %1;").arg(new_path_color.name());
        ui->path_color->setStyleSheet(color);
      }
}


void MainWindow::on_generate_btn_clicked()
{
//    ps::Generator gen;
//    size_t rows = ui->rows->value();
//    size_t cols = ui->cols->value();
//    ps::Maze* res = gen.GenerateMaze(rows, cols);
//    ui->maze_window->setRightWalls(res->vertical_walls);
//    ui->maze_window->setBottomWalls(res->horizontal_walls);
//    ui->maze_window->update();
}


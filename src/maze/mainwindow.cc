#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../core/utils/utils.h"
#include "../core/model/generator.h"
#include "../core/controller/controller.h"

MainWindow::MainWindow(ps::Controller* c, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), controller_(c)
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
    delete_points();
    size_t rows = ui->rows->value();
    size_t cols = ui->cols->value();
    ui->maze_window->setMaze(controller_->GeneratePerfectMaze(rows, cols));
    ui->maze_window->update();
}


void MainWindow::on_open_file_btn_clicked()
{
    delete_points();
    QString file = QFileDialog::getOpenFileName(
        this, "Выбрать файл", QDir::homePath(), "Txt files (*.txt)");
    if (!file.isEmpty()) {
        std::string file_name = file.toUtf8().toStdString();
        try {
            ui->maze_window->setMaze(controller_->OpenFile(file_name));
            ui->maze_window->update();
        } catch (std::exception &e) {
            QMessageBox::warning(this, "Ошибка!", e.what());
        }
    }
}


void MainWindow::on_save_file_btn_clicked()
{
    if(ui->maze_window->getMaze().empty()) {
        QMessageBox::warning(this, "Ошибка!", "Нужно сначала сгенерировать лабиринт!");
        return;
    }
    QString initial_path = QDir::homePath() + "/Downloads";
    QString file = QFileDialog::getSaveFileName(this, "Сохранить файл", initial_path + "/file.txt",
          "Text files (*.txt)");
    if (file.isEmpty()) {
            return;
        }
    try{
        controller_->CreateFile(file.toUtf8().toStdString());
    } catch (std::exception &e) {
        QMessageBox::warning(this, "Ошибка!", e.what());
    }
}


void MainWindow::on_solve_btn_clicked()
{
    if(!ui->maze_window->getStartSelected()) {
        QMessageBox::warning(this, "Ошибка!", "Нужно выбрать начальную точку!");
        return;
    }
    if(!ui->maze_window->getFinishSelected()) {
        QMessageBox::warning(this, "Ошибка!", "Нужно выбрать конечную точку!");
        return;
    }
    int start_x = ui->maze_window->getStartX();
    int start_y = ui->maze_window->getStartY();
    int finish_x = ui->maze_window->getFinishX();
    int finish_y = ui->maze_window->getFinishY();
    try{
        ui->maze_window->setMaze(controller_->SearchShortestPath(start_x, start_y, finish_x, finish_y));
        ui->maze_window->update();
    } catch (std::exception &e) {
        QMessageBox::warning(this, "Ошибка!", e.what());
    }
}


void MainWindow::on_choose_start_clicked()
{
    ui->maze_window->setMaze(controller_->ClearPath());
    ui->maze_window->setStartSelected(false);
    ui->maze_window->update();
    ui->maze_window->setDrawMode(ui->maze_window->kStart);
}


void MainWindow::on_choose_finish_clicked()
{
    ui->maze_window->setMaze(controller_->ClearPath());
    ui->maze_window->setFinishSelected(false);
    ui->maze_window->update();
    ui->maze_window->setDrawMode(ui->maze_window->kFinish);
}

void MainWindow::delete_points()
{
    ui->maze_window->setStartSelected(false);
    ui->maze_window->setFinishSelected(false);
}

//void MainWindow::on_tabWidget_currentChanged(int index)
//{
//    if(index == 0) ui->maze_window->setPainterMode(ui->maze_window->kMaze);
//    if(index == 1) ui->maze_window->setPainterMode(ui->maze_window->kCave);
//}


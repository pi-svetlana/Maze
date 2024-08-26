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

    size_t rows = ui->rows->value();
    size_t cols = ui->cols->value();
    ui->maze_window->setMaze(controller_->GeneratePerfectMaze(rows, cols));
    ui->maze_window->update();
}


void MainWindow::on_open_file_btn_clicked()
{
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
    QString initial_path = QDir::homePath() + "/Downloads";
    QString file = QFileDialog::getSaveFileName(this, "Сохранить файл", initial_path + "/file.txt",
          "Text files (*.txt)");
    try{
        controller_->CreateFile(file.toUtf8().toStdString());
    } catch (std::exception &e) {
        QMessageBox::warning(this, "Ошибка!", e.what());
    }
}


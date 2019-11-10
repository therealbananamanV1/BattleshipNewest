#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "second_form.h"
#include "third_form.h"
#include <QPushButton>

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

//button "start" is clicked
void MainWindow::on_button_start_clicked()
{
    second_form form2;
    form2.setModal(true);
    form2.exec();
}

void MainWindow::on_actionNew_Game_triggered()
{

    second_form form2;
    form2.setModal(true);
    form2.exec();
}

void MainWindow::on_button_instructions_clicked()
{
    third_form form3;
    form3.setModal(true);
    form3.exec();
}
void MainWindow::on_actionInstructions_triggered()
{
    third_form form3;
    form3.setModal(true);
    form3.exec();
}

void MainWindow::on_button_quit_clicked()
{
   close();
}


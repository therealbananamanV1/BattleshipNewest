#include "third_form.h"
#include "ui_third_form.h"

third_form::third_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::third_form)
{
    ui->setupUi(this);
    ui->label3->setText("Each player hides their ships in any position");
    ui->label4->setText("and orientation on their grid. Each turn the");
    ui->label5->setText("player calls out a shot at any coordinate on");
    ui->label6->setText("the grid. Hits and misses will be marked. Once");
    ui->label7->setText("a ship has all its hits, It is considered sunk.");
    ui->label8->setText("First player to sink the others entire fleat wins.");
}

third_form::~third_form()
{
    delete ui;
}

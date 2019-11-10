#include "second_form.h"
#include "ui_second_form.h"
#include <iostream>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QInputDialog>
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

//sets second form UI
second_form::second_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::second_form)
{
    ui->setupUi(this);
    ui->label_top->setText("You Have 30 Tries To Destroy All Enemy Ships");
    ui->label_bottom->setText("Enter A Coordinate To Fire At");
    q_num = 0;
}


second_form::~second_form()
{
    delete ui;
}

//getters
bool second_form::get_valid(){
    return valid;
}
int second_form::get_letter_side(){
    return letter_side;
}
int second_form::get_number_side(){
    return number_side;
}
int second_form::get_q_num(){
    return q_num;
}
QString second_form::get_qLetters(int l){
    QString q;
    q = qLetters[l];
    return q;
}
QString second_form::get_qNumbers(int n){
    QString q;
    q = qNumbers[n];
    return q;
}
//setters
void second_form::set_valid(bool v){
    valid = v;
}
void second_form::set_letter_side(int l){
    letter_side = l;
}
void second_form::set_number_side(int n){
    number_side = n;
}
void second_form::set_q_num(int q){
    q_num = q;
}
//11111111111111111111111111111111111111111111111
//gets user input and sets to variables in header
void second_form::set_player_input(QString raw)
{
    //used for parsed user input
    QString x = "";
    QString y = "";
    QString ql = "";
    bool a;
    bool b;
    //tries to parse user input into individual characters
    try {
        x = raw.at(0);
        y = raw.at(1);
        set_valid(true);
    }
    catch (...) {
        ui->label_bottom->setText("Please Enter Valid Coordinate");
        //input invalid
        set_valid(false);
    }
    //if user input parses successfully
    if (get_valid() != false) {
        a = false;
        b = false;
        set_valid(false);
        //compares input to data arrays
        for (int i=0; i<10; i++){
            //if input is a-j
            if (x == get_qLetters(i)){
                set_letter_side(i);
                a = true;
                valid = true;
            }
            //if input is 0-9
            if (y == get_qNumbers(i)){
                set_number_side(i);
                b = true;
                valid = true;
            }
        }
        //if user input is within a-j / 0-9
        if (a == false || b == false){
            set_valid(false);
        }
    }
    //if user input is invalid
    //if (get_valid() == false) {
    //    ui->label_top->setText("Enter Starting Coordinate");
    //    ui->label_bottom->setText("Please enter a valid coordinate :)");
    //    ui->command_line->setText("");
    //}
}


//sets the coordinates of the computer ships
void second_form::set_ship1(){
    int x;
    int y;
    int d;
    bool ship1_set;

    ship1_set = false;

    for (int z=0; z<10; z++){
        for (int t=0; t<10; t++){
            shipGrid[z][t] = false;
        }
    }
    ui->a1->setText("");
    ui->a2->setText("");
    ui->a3->setText("");
    ui->a4->setText("");
    ui->a5->setText("");
    ui->a6->setText("");
    ui->a7->setText("");
    ui->a8->setText("");
    ui->a9->setText("");
    ui->a0->setText("");

    ui->b1->setText("");
    ui->b2->setText("");
    ui->b3->setText("");
    ui->b4->setText("");
    ui->b5->setText("");
    ui->b6->setText("");
    ui->b7->setText("");
    ui->b8->setText("");
    ui->b9->setText("");
    ui->b0->setText("");

    ui->c1->setText("");
    ui->c2->setText("");
    ui->c3->setText("");
    ui->c4->setText("");
    ui->c5->setText("");
    ui->c6->setText("");
    ui->c7->setText("");
    ui->c8->setText("");
    ui->c9->setText("");
    ui->c0->setText("");

    ui->d1->setText("");
    ui->d2->setText("");
    ui->d3->setText("");
    ui->d4->setText("");
    ui->d5->setText("");
    ui->d6->setText("");
    ui->d7->setText("");
    ui->d8->setText("");
    ui->d9->setText("");
    ui->d0->setText("");

    ui->e1->setText("");
    ui->e2->setText("");
    ui->e3->setText("");
    ui->e4->setText("");
    ui->e5->setText("");
    ui->e6->setText("");
    ui->e7->setText("");
    ui->e8->setText("");
    ui->e9->setText("");
    ui->e0->setText("");

    ui->f1->setText("");
    ui->f2->setText("");
    ui->f3->setText("");
    ui->f4->setText("");
    ui->f5->setText("");
    ui->f6->setText("");
    ui->f7->setText("");
    ui->f8->setText("");
    ui->f9->setText("");
    ui->f0->setText("");

    ui->g1->setText("");
    ui->g2->setText("");
    ui->g3->setText("");
    ui->g4->setText("");
    ui->g5->setText("");
    ui->g6->setText("");
    ui->g7->setText("");
    ui->g8->setText("");
    ui->g9->setText("");
    ui->g0->setText("");

    ui->h1->setText("");
    ui->h2->setText("");
    ui->h3->setText("");
    ui->h4->setText("");
    ui->h5->setText("");
    ui->h6->setText("");
    ui->h7->setText("");
    ui->h8->setText("");
    ui->h9->setText("");
    ui->h0->setText("");

    ui->i1->setText("");
    ui->i2->setText("");
    ui->i3->setText("");
    ui->i4->setText("");
    ui->i5->setText("");
    ui->i6->setText("");
    ui->i7->setText("");
    ui->i8->setText("");
    ui->i9->setText("");
    ui->i0->setText("");

    ui->j1->setText("");
    ui->j2->setText("");
    ui->j3->setText("");
    ui->j4->setText("");
    ui->j5->setText("");
    ui->j6->setText("");
    ui->j7->setText("");
    ui->j8->setText("");
    ui->j9->setText("");
    ui->j0->setText("");

    //loops until ships is set properly
    while (ship1_set != true){
        x = get_randNum();
        y = get_randNum();
        d = get_randDirection();
        if (shipGrid[x][y] == false){
            //direction left
            if(d == 0){
                if (shipGrid[x][y-1] == false){
                    if (x == 0){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->a1->setText("S1");
                            ui->a0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->a2->setText("S1");
                            ui->a1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->a3->setText("S1");
                            ui->a2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->a4->setText("S1");
                            ui->a3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->a5->setText("S1");
                            ui->a4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->a6->setText("S1");
                            ui->a5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->a7->setText("S1");
                            ui->a6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->a8->setText("S1");
                            ui->a7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->a9->setText("S1");
                            ui->a8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                    if (x == 1){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->b1->setText("S1");
                            ui->b0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->b2->setText("S1");
                            ui->b1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->b3->setText("S1");
                            ui->b2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->b4->setText("S1");
                            ui->b3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->b5->setText("S1");
                            ui->b4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->b6->setText("S1");
                            ui->b5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->b7->setText("S1");
                            ui->b6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->b8->setText("S1");
                            ui->b7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->b9->setText("S1");
                            ui->b8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                    if (x == 2){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->c1->setText("S1");
                            ui->c0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->c2->setText("S1");
                            ui->c1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->c3->setText("S1");
                            ui->c2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->c4->setText("S1");
                            ui->c3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->c5->setText("S1");
                            ui->c4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->c6->setText("S1");
                            ui->c5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->c7->setText("S1");
                            ui->c6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->c8->setText("S1");
                            ui->c7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->c9->setText("S1");
                            ui->c8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                    if (x == 3){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->d1->setText("S1");
                            ui->d0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->d2->setText("S1");
                            ui->d1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->d3->setText("S1");
                            ui->d2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->d4->setText("S1");
                            ui->d3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->d5->setText("S1");
                            ui->d4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->d6->setText("S1");
                            ui->d5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->d7->setText("S1");
                            ui->d6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->d8->setText("S1");
                            ui->d7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->d9->setText("S1");
                            ui->d8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                    if (x == 4){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->e1->setText("S1");
                            ui->e0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->e2->setText("S1");
                            ui->e1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->e3->setText("S1");
                            ui->e2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->e4->setText("S1");
                            ui->e3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->e5->setText("S1");
                            ui->e4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->e6->setText("S1");
                            ui->e5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->e7->setText("S1");
                            ui->e6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->e8->setText("S1");
                            ui->e7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->e9->setText("S1");
                            ui->e8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                    if (x == 5){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->f1->setText("S1");
                            ui->f0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->f2->setText("S1");
                            ui->f1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->f3->setText("S1");
                            ui->f2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->f4->setText("S1");
                            ui->f3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->f5->setText("S1");
                            ui->f4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->f6->setText("S1");
                            ui->f5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->f7->setText("S1");
                            ui->f6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->f8->setText("S1");
                            ui->f7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->f9->setText("S1");
                            ui->f8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                    if (x == 6){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->g1->setText("S1");
                            ui->g0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->g2->setText("S1");
                            ui->g1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->g3->setText("S1");
                            ui->g2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->g4->setText("S1");
                            ui->g3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->g5->setText("S1");
                            ui->g4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->g6->setText("S1");
                            ui->g5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->g7->setText("S1");
                            ui->g6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->g8->setText("S1");
                            ui->g7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->g9->setText("S1");
                            ui->g8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                    if (x == 7){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->h1->setText("S1");
                            ui->h0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->h2->setText("S1");
                            ui->h1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->h3->setText("S1");
                            ui->h2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->h4->setText("S1");
                            ui->h3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->h5->setText("S1");
                            ui->h4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->h6->setText("S1");
                            ui->h5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->h7->setText("S1");
                            ui->h6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->h8->setText("S1");
                            ui->h7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->h9->setText("S1");
                            ui->h8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                    if (x == 8){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->i1->setText("S1");
                            ui->i0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->i2->setText("S1");
                            ui->i1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->i3->setText("S1");
                            ui->i2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->i4->setText("S1");
                            ui->i3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->i5->setText("S1");
                            ui->i4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->i6->setText("S1");
                            ui->i5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->i7->setText("S1");
                            ui->i6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->i8->setText("S1");
                            ui->i7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->i9->setText("S1");
                            ui->i8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                    if (x == 9){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ui->j1->setText("S1");
                            ui->j0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 2){
                            ui->j2->setText("S1");
                            ui->j1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 3){
                            ui->j3->setText("S1");
                            ui->j2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 4){
                            ui->j4->setText("S1");
                            ui->j3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 5){
                            ui->j5->setText("S1");
                            ui->j4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 6){
                            ui->j6->setText("S1");
                            ui->j5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 7){
                            ui->j7->setText("S1");
                            ui->j6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 8){
                            ui->j8->setText("S1");
                            ui->j7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                        if (y == 9){
                            ui->j9->setText("S1");
                            ui->j8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y-1;
                        }
                    }
                }
            }
            //direction right
            if(d == 1){
                if (shipGrid[x][y+1] == false){
                    if (x == 0){
                        if (y == 0){
                            ui->a0->setText("S1");
                            ui->a1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->a1->setText("S1");
                            ui->a2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->a2->setText("S1");
                            ui->a3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->a3->setText("S1");
                            ui->a4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->a4->setText("S1");
                            ui->a5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->a5->setText("S1");
                            ui->a6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->a6->setText("S1");
                            ui->a7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->a7->setText("S1");
                            ui->a8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->a8->setText("S1");
                            ui->a9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 1){
                        if (y == 0){
                            ui->b0->setText("S1");
                            ui->b1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->b1->setText("S1");
                            ui->b2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->b2->setText("S1");
                            ui->b3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->b3->setText("S1");
                            ui->b4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->b4->setText("S1");
                            ui->b5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->b5->setText("S1");
                            ui->b6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->b6->setText("S1");
                            ui->b7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->b7->setText("S1");
                            ui->b8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->b8->setText("S1");
                            ui->b9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 2){
                        if (y == 0){
                            ui->c0->setText("S1");
                            ui->c1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->c1->setText("S1");
                            ui->c2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->c2->setText("S1");
                            ui->c3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->c3->setText("S1");
                            ui->c4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->c4->setText("S1");
                            ui->c5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->c5->setText("S1");
                            ui->c6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->c6->setText("S1");
                            ui->c7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->c7->setText("S1");
                            ui->c8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->c8->setText("S1");
                            ui->c9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 3){
                        if (y == 0){
                            ui->d0->setText("S1");
                            ui->d1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->d1->setText("S1");
                            ui->d2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->d2->setText("S1");
                            ui->d3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->d3->setText("S1");
                            ui->d4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->d4->setText("S1");
                            ui->d5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->d5->setText("S1");
                            ui->d6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->d6->setText("S1");
                            ui->d7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->d7->setText("S1");
                            ui->d8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->d8->setText("S1");
                            ui->d9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 4){
                        if (y == 0){
                            ui->e0->setText("S1");
                            ui->e1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->e1->setText("S1");
                            ui->e2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->e2->setText("S1");
                            ui->e3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->e3->setText("S1");
                            ui->e4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->e4->setText("S1");
                            ui->e5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->e5->setText("S1");
                            ui->e6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->e6->setText("S1");
                            ui->e7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->e7->setText("S1");
                            ui->e8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->e8->setText("S1");
                            ui->e9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 5){
                        if (y == 0){
                            ui->f0->setText("S1");
                            ui->f1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->f1->setText("S1");
                            ui->f2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->f2->setText("S1");
                            ui->f3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->f3->setText("S1");
                            ui->f4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->f4->setText("S1");
                            ui->f5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->f5->setText("S1");
                            ui->f6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->f6->setText("S1");
                            ui->f7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->f7->setText("S1");
                            ui->f8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->f8->setText("S1");
                            ui->f9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 6){
                        if (y == 0){
                            ui->g0->setText("S1");
                            ui->g1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->g1->setText("S1");
                            ui->g2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->g2->setText("S1");
                            ui->g3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->g3->setText("S1");
                            ui->g4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->g4->setText("S1");
                            ui->g5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->g5->setText("S1");
                            ui->g6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->g6->setText("S1");
                            ui->g7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->g7->setText("S1");
                            ui->g8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->g8->setText("S1");
                            ui->g9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 7){
                        if (y == 0){
                            ui->h0->setText("S1");
                            ui->h1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->h1->setText("S1");
                            ui->h2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->h2->setText("S1");
                            ui->h3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->h3->setText("S1");
                            ui->h4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->h4->setText("S1");
                            ui->h5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->h5->setText("S1");
                            ui->h6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->h6->setText("S1");
                            ui->h7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->h7->setText("S1");
                            ui->h8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->h8->setText("S1");
                            ui->h9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 8){
                        if (y == 0){
                            ui->i0->setText("S1");
                            ui->i1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->i1->setText("S1");
                            ui->i2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->i2->setText("S1");
                            ui->i3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->i3->setText("S1");
                            ui->i4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->i4->setText("S1");
                            ui->i5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->i5->setText("S1");
                            ui->i6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->i6->setText("S1");
                            ui->i7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->i7->setText("S1");
                            ui->i8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->i8->setText("S1");
                            ui->i9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 9){
                        if (y == 0){
                            ui->j0->setText("S1");
                            ui->j1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 1){
                            ui->j1->setText("S1");
                            ui->j2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 2){
                            ui->j2->setText("S1");
                            ui->j3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 3){
                            ui->j3->setText("S1");
                            ui->j4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 4){
                            ui->j4->setText("S1");
                            ui->j5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 5){
                            ui->j5->setText("S1");
                            ui->j6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 6){
                            ui->j6->setText("S1");
                            ui->j7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 7){
                            ui->j7->setText("S1");
                            ui->j8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 8){
                            ui->j8->setText("S1");
                            ui->j9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x;
                            ship1[3] = y+1;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                }
            }
            //direction up
            if(d == 2){
                if (shipGrid[x-1][y] == false){
                    if (x == 0){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ship1_set = false;
                        }
                        if (y == 2){
                            ship1_set = false;
                        }
                        if (y == 3){
                            ship1_set = false;
                        }
                        if (y == 4){
                            ship1_set = false;
                        }
                        if (y == 5){
                            ship1_set = false;
                        }
                        if (y == 6){
                            ship1_set = false;
                        }
                        if (y == 7){
                            ship1_set = false;
                        }
                        if (y == 8){
                            ship1_set = false;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                    if (x == 1){
                        if (y == 0){
                            ui->b0->setText("S1");
                            ui->a0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->b1->setText("S1");
                            ui->a1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->b2->setText("S1");
                            ui->a2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->b3->setText("S1");
                            ui->a3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->b4->setText("S1");
                            ui->a4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->b5->setText("S1");
                            ui->a5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->b6->setText("S1");
                            ui->a6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->b7->setText("S1");
                            ui->a7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->b8->setText("S1");
                            ui->a8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->b9->setText("S1");
                            ui->a9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 2){
                        if (y == 0){
                            ui->c0->setText("S1");
                            ui->b0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->c1->setText("S1");
                            ui->b1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->c2->setText("S1");
                            ui->b2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->c3->setText("S1");
                            ui->b3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->c4->setText("S1");
                            ui->b4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->c5->setText("S1");
                            ui->b5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->c6->setText("S1");
                            ui->b6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->c7->setText("S1");
                            ui->b7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->c8->setText("S1");
                            ui->b8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->c9->setText("S1");
                            ui->b9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 3){
                        if (y == 0){
                            ui->d0->setText("S1");
                            ui->c0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->d1->setText("S1");
                            ui->c1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->d2->setText("S1");
                            ui->c2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->d3->setText("S1");
                            ui->c3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->d4->setText("S1");
                            ui->c4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->d5->setText("S1");
                            ui->c5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->d6->setText("S1");
                            ui->c6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->d7->setText("S1");
                            ui->c7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->d8->setText("S1");
                            ui->c8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->d9->setText("S1");
                            ui->c9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 4){
                        if (y == 0){
                            ui->e0->setText("S1");
                            ui->d0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->e1->setText("S1");
                            ui->d1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->e2->setText("S1");
                            ui->d2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->e3->setText("S1");
                            ui->d3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->e4->setText("S1");
                            ui->d4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->e5->setText("S1");
                            ui->d5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->e6->setText("S1");
                            ui->d6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->e7->setText("S1");
                            ui->d7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->e8->setText("S1");
                            ui->d8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->e9->setText("S1");
                            ui->d9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 5){
                        if (y == 0){
                            ui->f0->setText("S1");
                            ui->e0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->f1->setText("S1");
                            ui->e1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->f2->setText("S1");
                            ui->e2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->f3->setText("S1");
                            ui->e3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->f4->setText("S1");
                            ui->e4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->f5->setText("S1");
                            ui->e5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->f6->setText("S1");
                            ui->e6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->f7->setText("S1");
                            ui->e7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->f8->setText("S1");
                            ui->e8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->f9->setText("S1");
                            ui->e9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 6){
                        if (y == 0){
                            ui->g0->setText("S1");
                            ui->f0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->g1->setText("S1");
                            ui->f1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->g2->setText("S1");
                            ui->f2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->g3->setText("S1");
                            ui->f3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->g4->setText("S1");
                            ui->f4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->g5->setText("S1");
                            ui->f5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->g6->setText("S1");
                            ui->f6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->g7->setText("S1");
                            ui->f7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->g8->setText("S1");
                            ui->f8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->g9->setText("S1");
                            ui->f9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 7){
                        if (y == 0){
                            ui->h0->setText("S1");
                            ui->g0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->h1->setText("S1");
                            ui->g1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->h2->setText("S1");
                            ui->g2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->h3->setText("S1");
                            ui->g3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->h4->setText("S1");
                            ui->g4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->h5->setText("S1");
                            ui->g5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->h6->setText("S1");
                            ui->g6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->h7->setText("S1");
                            ui->g7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->h8->setText("S1");
                            ui->g8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->h9->setText("S1");
                            ui->g9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 8){
                        if (y == 0){
                            ui->i0->setText("S1");
                            ui->h0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->i1->setText("S1");
                            ui->h1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->i2->setText("S1");
                            ui->h2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->i3->setText("S1");
                            ui->h3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->i4->setText("S1");
                            ui->h4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->i5->setText("S1");
                            ui->h5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->i6->setText("S1");
                            ui->h6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->i7->setText("S1");
                            ui->h7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->i8->setText("S1");
                            ui->h8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->i9->setText("S1");
                            ui->h9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 9){
                        if (y == 0){
                            ui->j0->setText("S1");
                            ui->i0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->j1->setText("S1");
                            ui->i1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->j2->setText("S1");
                            ui->i2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->j3->setText("S1");
                            ui->i3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->j4->setText("S1");
                            ui->i4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->j5->setText("S1");
                            ui->i5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->j6->setText("S1");
                            ui->i6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->j7->setText("S1");
                            ui->i7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->j8->setText("S1");
                            ui->i8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->j9->setText("S1");
                            ui->i9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                }
            }
            //direction down
            if(d == 3){
                if (shipGrid[x+1][y] == false){
                    if (x == 0){
                        if (y == 0){
                            ui->a0->setText("S1");
                            ui->b0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->a1->setText("S1");
                            ui->b1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->a2->setText("S1");
                            ui->b2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->a3->setText("S1");
                            ui->b3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->a4->setText("S1");
                            ui->b4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->a5->setText("S1");
                            ui->b5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->a6->setText("S1");
                            ui->b6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->a7->setText("S1");
                            ui->b7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->a8->setText("S1");
                            ui->b8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->a9->setText("S1");
                            ui->b9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 1){
                        if (y == 0){
                            ui->b0->setText("S1");
                            ui->c0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->b1->setText("S1");
                            ui->c1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->b2->setText("S1");
                            ui->c2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->b3->setText("S1");
                            ui->c3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->b4->setText("S1");
                            ui->c4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->b5->setText("S1");
                            ui->c5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->b6->setText("S1");
                            ui->c6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->b7->setText("S1");
                            ui->c7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->b8->setText("S1");
                            ui->c8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->b9->setText("S1");
                            ui->c9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 2){
                        if (y == 0){
                            ui->c0->setText("S1");
                            ui->d0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->c1->setText("S1");
                            ui->d1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->c2->setText("S1");
                            ui->d2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->c3->setText("S1");
                            ui->d3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->c4->setText("S1");
                            ui->d4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->c5->setText("S1");
                            ui->d5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->c6->setText("S1");
                            ui->d6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->c7->setText("S1");
                            ui->d7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->c8->setText("S1");
                            ui->d8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->c9->setText("S1");
                            ui->d9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 3){
                        if (y == 0){
                            ui->d0->setText("S1");
                            ui->e0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->d1->setText("S1");
                            ui->e1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->d2->setText("S1");
                            ui->e2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->d3->setText("S1");
                            ui->e3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->d4->setText("S1");
                            ui->e4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->d5->setText("S1");
                            ui->e5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->d6->setText("S1");
                            ui->e6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->d7->setText("S1");
                            ui->e7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->d8->setText("S1");
                            ui->e8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->d9->setText("S1");
                            ui->e9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 4){
                        if (y == 0){
                            ui->e0->setText("S1");
                            ui->f0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->e1->setText("S1");
                            ui->f1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->e2->setText("S1");
                            ui->f2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->e3->setText("S1");
                            ui->f3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->e4->setText("S1");
                            ui->f4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->e5->setText("S1");
                            ui->f5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->e6->setText("S1");
                            ui->f6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->e7->setText("S1");
                            ui->f7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->e8->setText("S1");
                            ui->f8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->e9->setText("S1");
                            ui->f9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 5){
                        if (y == 0){
                            ui->f0->setText("S1");
                            ui->g0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->f1->setText("S1");
                            ui->g1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->f2->setText("S1");
                            ui->g2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->f3->setText("S1");
                            ui->g3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->f4->setText("S1");
                            ui->g4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->f5->setText("S1");
                            ui->g5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->f6->setText("S1");
                            ui->g6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->f7->setText("S1");
                            ui->g7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->f8->setText("S1");
                            ui->g8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->f9->setText("S1");
                            ui->g9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 6){
                        if (y == 0){
                            ui->g0->setText("S1");
                            ui->h0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->g1->setText("S1");
                            ui->h1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->g2->setText("S1");
                            ui->h2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->g3->setText("S1");
                            ui->h3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->g4->setText("S1");
                            ui->h4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->g5->setText("S1");
                            ui->h5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->g6->setText("S1");
                            ui->h6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->g7->setText("S1");
                            ui->h7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->g8->setText("S1");
                            ui->h8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->g9->setText("S1");
                            ui->h9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 7){
                        if (y == 0){
                            ui->h0->setText("S1");
                            ui->i0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->h1->setText("S1");
                            ui->i1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->h2->setText("S1");
                            ui->i2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->h3->setText("S1");
                            ui->i3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->h4->setText("S1");
                            ui->i4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->h5->setText("S1");
                            ui->i5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->h6->setText("S1");
                            ui->i6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->h7->setText("S1");
                            ui->i7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->h8->setText("S1");
                            ui->i8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->h9->setText("S1");
                            ui->i9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x+1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 8){
                        if (y == 0){
                            ui->i0->setText("S1");
                            ui->j0->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 1){
                            ui->i1->setText("S1");
                            ui->j1->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 2){
                            ui->i2->setText("S1");
                            ui->j2->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 3){
                            ui->i3->setText("S1");
                            ui->j3->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 4){
                            ui->i4->setText("S1");
                            ui->j4->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 5){
                            ui->i5->setText("S1");
                            ui->j5->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 6){
                            ui->i6->setText("S1");
                            ui->j6->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 7){
                            ui->i7->setText("S1");
                            ui->j7->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 8){
                            ui->i8->setText("S1");
                            ui->j8->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                        if (y == 9){
                            ui->i9->setText("S1");
                            ui->j9->setText("S1");
                            ship1_set = true;
                            ship1[0] = x;
                            ship1[1] = y;
                            ship1[2] = x-1;
                            ship1[3] = y;
                        }
                    }
                    if (x == 9){
                        if (y == 0){
                            ship1_set = false;
                        }
                        if (y == 1){
                            ship1_set = false;
                        }
                        if (y == 2){
                            ship1_set = false;
                        }
                        if (y == 3){
                            ship1_set = false;
                        }
                        if (y == 4){
                            ship1_set = false;
                        }
                        if (y == 5){
                            ship1_set = false;
                        }
                        if (y == 6){
                            ship1_set = false;
                        }
                        if (y == 7){
                            ship1_set = false;
                        }
                        if (y == 8){
                            ship1_set = false;
                        }
                        if (y == 9){
                            ship1_set = false;
                        }
                    }
                }
            }
        }

    }
    while (ship2_set != true){
        x = get_randNum();
        y = get_randNum();
        d = get_randDirection();
        if (shipGrid[x][y] == false){
            //direction left
            if (d == 0){
                if (shipGrid[x][y-1] == false){
                    if (shipGrid[x][y-2] == false){
                        if (x == 0){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->a2->setText("S1");
                                ui->a1->setText("S1");
                                ui->a0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->a3->setText("S1");
                                ui->a2->setText("S1");
                                ui->a1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->a4->setText("S1");
                                ui->a3->setText("S1");
                                ui->a2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->a5->setText("S1");
                                ui->a4->setText("S1");
                                ui->a3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->a6->setText("S1");
                                ui->a5->setText("S1");
                                ui->a4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->a7->setText("S1");
                                ui->a6->setText("S1");
                                ui->a5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->a8->setText("S1");
                                ui->a7->setText("S1");
                                ui->a6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->a9->setText("S1");
                                ui->a8->setText("S1");
                                ui->a7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                        if (x == 1){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->b2->setText("S1");
                                ui->b1->setText("S1");
                                ui->b0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->b3->setText("S1");
                                ui->b2->setText("S1");
                                ui->b1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->b4->setText("S1");
                                ui->b3->setText("S1");
                                ui->b2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->b5->setText("S1");
                                ui->b4->setText("S1");
                                ui->b3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->b6->setText("S1");
                                ui->b5->setText("S1");
                                ui->b4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->b7->setText("S1");
                                ui->b6->setText("S1");
                                ui->b5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->b8->setText("S1");
                                ui->b7->setText("S1");
                                ui->b6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->b9->setText("S1");
                                ui->b8->setText("S1");
                                ui->b7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                        if (x == 2){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->c2->setText("S1");
                                ui->c1->setText("S1");
                                ui->c0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->c3->setText("S1");
                                ui->c2->setText("S1");
                                ui->c1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->c4->setText("S1");
                                ui->c3->setText("S1");
                                ui->c2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->c5->setText("S1");
                                ui->c4->setText("S1");
                                ui->c3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->c6->setText("S1");
                                ui->c5->setText("S1");
                                ui->c4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->c7->setText("S1");
                                ui->c6->setText("S1");
                                ui->c5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->c8->setText("S1");
                                ui->c7->setText("S1");
                                ui->c6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->c9->setText("S1");
                                ui->c8->setText("S1");
                                ui->c7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                        if (x == 3){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->d2->setText("S1");
                                ui->d1->setText("S1");
                                ui->d0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->d3->setText("S1");
                                ui->d2->setText("S1");
                                ui->d1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->d4->setText("S1");
                                ui->d3->setText("S1");
                                ui->d2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->d5->setText("S1");
                                ui->d4->setText("S1");
                                ui->d3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->d6->setText("S1");
                                ui->d5->setText("S1");
                                ui->d4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->d7->setText("S1");
                                ui->d6->setText("S1");
                                ui->d5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->d8->setText("S1");
                                ui->d7->setText("S1");
                                ui->d6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->d9->setText("S1");
                                ui->d8->setText("S1");
                                ui->d7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                        if (x == 4){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->e2->setText("S1");
                                ui->e1->setText("S1");
                                ui->e0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->e3->setText("S1");
                                ui->e2->setText("S1");
                                ui->e1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->e4->setText("S1");
                                ui->e3->setText("S1");
                                ui->e2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->e5->setText("S1");
                                ui->e4->setText("S1");
                                ui->e3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->e6->setText("S1");
                                ui->e5->setText("S1");
                                ui->e4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->e7->setText("S1");
                                ui->e6->setText("S1");
                                ui->e5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->e8->setText("S1");
                                ui->e7->setText("S1");
                                ui->e6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->e9->setText("S1");
                                ui->e8->setText("S1");
                                ui->e7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                        if (x == 5){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->f2->setText("S1");
                                ui->f1->setText("S1");
                                ui->f0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->f3->setText("S1");
                                ui->f2->setText("S1");
                                ui->f1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->f4->setText("S1");
                                ui->f3->setText("S1");
                                ui->f2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->f5->setText("S1");
                                ui->f4->setText("S1");
                                ui->f3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->f6->setText("S1");
                                ui->f5->setText("S1");
                                ui->f4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->f7->setText("S1");
                                ui->f6->setText("S1");
                                ui->f5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->f8->setText("S1");
                                ui->f7->setText("S1");
                                ui->f6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->f9->setText("S1");
                                ui->f8->setText("S1");
                                ui->f7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                        if (x == 6){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->g2->setText("S1");
                                ui->g1->setText("S1");
                                ui->g0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->g3->setText("S1");
                                ui->g2->setText("S1");
                                ui->g1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->g4->setText("S1");
                                ui->g3->setText("S1");
                                ui->g2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->g5->setText("S1");
                                ui->g4->setText("S1");
                                ui->g3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->g6->setText("S1");
                                ui->g5->setText("S1");
                                ui->g4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->g7->setText("S1");
                                ui->g6->setText("S1");
                                ui->g5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->g8->setText("S1");
                                ui->g7->setText("S1");
                                ui->g6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->g9->setText("S1");
                                ui->g8->setText("S1");
                                ui->g7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                        if (x == 7){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->h2->setText("S1");
                                ui->h1->setText("S1");
                                ui->h0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->h3->setText("S1");
                                ui->h2->setText("S1");
                                ui->h1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->h4->setText("S1");
                                ui->h3->setText("S1");
                                ui->h2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->h5->setText("S1");
                                ui->h4->setText("S1");
                                ui->h3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->h6->setText("S1");
                                ui->h5->setText("S1");
                                ui->h4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->h7->setText("S1");
                                ui->h6->setText("S1");
                                ui->h5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->h8->setText("S1");
                                ui->h7->setText("S1");
                                ui->h6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->h9->setText("S1");
                                ui->h8->setText("S1");
                                ui->h7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                        if (x == 8){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->i2->setText("S1");
                                ui->i1->setText("S1");
                                ui->i0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->i3->setText("S1");
                                ui->i2->setText("S1");
                                ui->i1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->i4->setText("S1");
                                ui->i3->setText("S1");
                                ui->i2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->i5->setText("S1");
                                ui->i4->setText("S1");
                                ui->i3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->i6->setText("S1");
                                ui->i5->setText("S1");
                                ui->i4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->i7->setText("S1");
                                ui->i6->setText("S1");
                                ui->i5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->i8->setText("S1");
                                ui->i7->setText("S1");
                                ui->i6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->i9->setText("S1");
                                ui->i8->setText("S1");
                                ui->i7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                        if (x == 9){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ui->j2->setText("S1");
                                ui->j1->setText("S1");
                                ui->j0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 3){
                                ui->j3->setText("S1");
                                ui->j2->setText("S1");
                                ui->j1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 4){
                                ui->j4->setText("S1");
                                ui->j3->setText("S1");
                                ui->j2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 5){
                                ui->j5->setText("S1");
                                ui->j4->setText("S1");
                                ui->j3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 6){
                                ui->j6->setText("S1");
                                ui->j5->setText("S1");
                                ui->j4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 7){
                                ui->j7->setText("S1");
                                ui->j6->setText("S1");
                                ui->j5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 8){
                                ui->j8->setText("S1");
                                ui->j7->setText("S1");
                                ui->j6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                            if (y == 9){
                                ui->j9->setText("S1");
                                ui->j8->setText("S1");
                                ui->j7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y-1;
                                ship2[4] = x;
                                ship2[5] = y -2;
                            }
                        }
                    }
                }
            }
            //direction right
            if (d == 1){
                if (shipGrid[x][y+1] == false){
                    if (shipGrid[x][y+2] == false){
                        if (x == 0){
                            if (y == 0){
                                ui->a0->setText("S1");
                                ui->a1->setText("S1");
                                ui->a2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->a1->setText("S1");
                                ui->a2->setText("S1");
                                ui->a3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->a2->setText("S1");
                                ui->a3->setText("S1");
                                ui->a4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->a3->setText("S1");
                                ui->a4->setText("S1");
                                ui->a5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->a4->setText("S1");
                                ui->a5->setText("S1");
                                ui->a6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->a5->setText("S1");
                                ui->a6->setText("S1");
                                ui->a7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->a6->setText("S1");
                                ui->a7->setText("S1");
                                ui->a8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->a7->setText("S1");
                                ui->a8->setText("S1");
                                ui->a9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 1){
                            if (y == 0){
                                ui->b0->setText("S1");
                                ui->b1->setText("S1");
                                ui->b2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->b1->setText("S1");
                                ui->b2->setText("S1");
                                ui->b3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->b2->setText("S1");
                                ui->b3->setText("S1");
                                ui->b4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->b3->setText("S1");
                                ui->b4->setText("S1");
                                ui->b5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->b4->setText("S1");
                                ui->b5->setText("S1");
                                ui->b6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->b5->setText("S1");
                                ui->b6->setText("S1");
                                ui->b7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->b6->setText("S1");
                                ui->b7->setText("S1");
                                ui->b8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->b7->setText("S1");
                                ui->b8->setText("S1");
                                ui->b9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 2){
                            if (y == 0){
                                ui->c0->setText("S1");
                                ui->c1->setText("S1");
                                ui->c2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->c1->setText("S1");
                                ui->c2->setText("S1");
                                ui->c3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->c2->setText("S1");
                                ui->c3->setText("S1");
                                ui->c4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->c3->setText("S1");
                                ui->c4->setText("S1");
                                ui->c5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->c4->setText("S1");
                                ui->c5->setText("S1");
                                ui->c6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->c5->setText("S1");
                                ui->c6->setText("S1");
                                ui->c7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->c6->setText("S1");
                                ui->c7->setText("S1");
                                ui->c8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->c7->setText("S1");
                                ui->c8->setText("S1");
                                ui->c9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 3){
                            if (y == 0){
                                ui->d0->setText("S1");
                                ui->d1->setText("S1");
                                ui->d2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->d1->setText("S1");
                                ui->d2->setText("S1");
                                ui->d3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->d2->setText("S1");
                                ui->d3->setText("S1");
                                ui->d4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->d3->setText("S1");
                                ui->d4->setText("S1");
                                ui->d5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->d4->setText("S1");
                                ui->d5->setText("S1");
                                ui->d6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->d5->setText("S1");
                                ui->d6->setText("S1");
                                ui->d7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->d6->setText("S1");
                                ui->d7->setText("S1");
                                ui->d8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->d7->setText("S1");
                                ui->d8->setText("S1");
                                ui->d9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 4){
                            if (y == 0){
                                ui->e0->setText("S1");
                                ui->e1->setText("S1");
                                ui->e2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->e1->setText("S1");
                                ui->e2->setText("S1");
                                ui->e3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->e2->setText("S1");
                                ui->e3->setText("S1");
                                ui->e4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->e3->setText("S1");
                                ui->e4->setText("S1");
                                ui->e5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->e4->setText("S1");
                                ui->e5->setText("S1");
                                ui->e6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->e5->setText("S1");
                                ui->e6->setText("S1");
                                ui->e7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->e6->setText("S1");
                                ui->e7->setText("S1");
                                ui->e8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->e7->setText("S1");
                                ui->e8->setText("S1");
                                ui->e9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 5){
                            if (y == 0){
                                ui->f0->setText("S1");
                                ui->f1->setText("S1");
                                ui->f2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->f1->setText("S1");
                                ui->f2->setText("S1");
                                ui->f3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->f2->setText("S1");
                                ui->f3->setText("S1");
                                ui->f4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->f3->setText("S1");
                                ui->f4->setText("S1");
                                ui->f5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->f4->setText("S1");
                                ui->f5->setText("S1");
                                ui->f6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->f5->setText("S1");
                                ui->f6->setText("S1");
                                ui->f7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->f6->setText("S1");
                                ui->f7->setText("S1");
                                ui->f8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->f7->setText("S1");
                                ui->f8->setText("S1");
                                ui->f9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 6){
                            if (y == 0){
                                ui->g0->setText("S1");
                                ui->g1->setText("S1");
                                ui->g2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->g1->setText("S1");
                                ui->g2->setText("S1");
                                ui->g3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->g2->setText("S1");
                                ui->g3->setText("S1");
                                ui->g4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->g3->setText("S1");
                                ui->g4->setText("S1");
                                ui->g5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->g4->setText("S1");
                                ui->g5->setText("S1");
                                ui->g6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->g5->setText("S1");
                                ui->g6->setText("S1");
                                ui->g7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->g6->setText("S1");
                                ui->g7->setText("S1");
                                ui->g8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->g7->setText("S1");
                                ui->g8->setText("S1");
                                ui->g9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 7){
                            if (y == 0){
                                ui->h0->setText("S1");
                                ui->h1->setText("S1");
                                ui->h2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->h1->setText("S1");
                                ui->h2->setText("S1");
                                ui->h3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->h2->setText("S1");
                                ui->h3->setText("S1");
                                ui->h4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->h3->setText("S1");
                                ui->h4->setText("S1");
                                ui->h5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->h4->setText("S1");
                                ui->h5->setText("S1");
                                ui->h6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->h5->setText("S1");
                                ui->h6->setText("S1");
                                ui->h7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->h6->setText("S1");
                                ui->h7->setText("S1");
                                ui->h8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->h7->setText("S1");
                                ui->h8->setText("S1");
                                ui->h9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 8){
                            if (y == 0){
                                ui->i0->setText("S1");
                                ui->i1->setText("S1");
                                ui->i2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->i1->setText("S1");
                                ui->i2->setText("S1");
                                ui->i3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->i2->setText("S1");
                                ui->i3->setText("S1");
                                ui->i4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->i3->setText("S1");
                                ui->i4->setText("S1");
                                ui->i5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->i4->setText("S1");
                                ui->i5->setText("S1");
                                ui->i6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->i5->setText("S1");
                                ui->i6->setText("S1");
                                ui->i7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->i6->setText("S1");
                                ui->i7->setText("S1");
                                ui->i8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->i7->setText("S1");
                                ui->i8->setText("S1");
                                ui->i9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 9){
                            if (y == 0){
                                ui->j0->setText("S1");
                                ui->j1->setText("S1");
                                ui->j2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y+1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 1){
                                ui->j1->setText("S1");
                                ui->j2->setText("S1");
                                ui->j3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 2){
                                ui->j2->setText("S1");
                                ui->j3->setText("S1");
                                ui->j4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 3){
                                ui->j3->setText("S1");
                                ui->j4->setText("S1");
                                ui->j5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 4){
                                ui->j4->setText("S1");
                                ui->j5->setText("S1");
                                ui->j6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 5){
                                ui->j5->setText("S1");
                                ui->j6->setText("S1");
                                ui->j7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 6){
                                ui->j6->setText("S1");
                                ui->j7->setText("S1");
                                ui->j8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 7){
                                ui->j7->setText("S1");
                                ui->j8->setText("S1");
                                ui->j9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x;
                                ship2[3] = y + 1;
                                ship2[4] = x;
                                ship2[5] = y + 2;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                    }
                }
            }
            //direction up
            if (d == 2){
                if (shipGrid[x-1][y] == false){
                    if (shipGrid[x-2][y] == false){
                        if (x == 0){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ship2_set = false;
                            }
                            if (y == 3){
                                ship2_set = false;
                            }
                            if (y == 4){
                                ship2_set = false;
                            }
                            if (y == 5){
                                ship2_set = false;
                            }
                            if (y == 6){
                                ship2_set = false;
                            }
                            if (y == 7){
                                ship2_set = false;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 1){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ship2_set = false;
                            }
                            if (y == 3){
                                ship2_set = false;
                            }
                            if (y == 4){
                                ship2_set = false;
                            }
                            if (y == 5){
                                ship2_set = false;
                            }
                            if (y == 6){
                                ship2_set = false;
                            }
                            if (y == 7){
                                ship2_set = false;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 2){
                            if (y == 0){
                                ui->a0->setText("S1");
                                ui->b0->setText("S1");
                                ui->c0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->a1->setText("S1");
                                ui->b1->setText("S1");
                                ui->c1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->a2->setText("S1");
                                ui->b2->setText("S1");
                                ui->c2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->a3->setText("S1");
                                ui->b3->setText("S1");
                                ui->c3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->a4->setText("S1");
                                ui->b4->setText("S1");
                                ui->c4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->a5->setText("S1");
                                ui->b5->setText("S1");
                                ui->c5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->a6->setText("S1");
                                ui->b6->setText("S1");
                                ui->c6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->a7->setText("S1");
                                ui->b7->setText("S1");
                                ui->c7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->a8->setText("S1");
                                ui->b8->setText("S1");
                                ui->c8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->a9->setText("S1");
                                ui->b9->setText("S1");
                                ui->c9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 3){
                            if (y == 0){
                                ui->b0->setText("S1");
                                ui->c0->setText("S1");
                                ui->d0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->b1->setText("S1");
                                ui->c1->setText("S1");
                                ui->d1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->b2->setText("S1");
                                ui->c2->setText("S1");
                                ui->d2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->b3->setText("S1");
                                ui->c3->setText("S1");
                                ui->d3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->b4->setText("S1");
                                ui->c4->setText("S1");
                                ui->d4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->b5->setText("S1");
                                ui->c5->setText("S1");
                                ui->d5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->b6->setText("S1");
                                ui->c6->setText("S1");
                                ui->d6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->b7->setText("S1");
                                ui->c7->setText("S1");
                                ui->d7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->b8->setText("S1");
                                ui->c8->setText("S1");
                                ui->d8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->b9->setText("S1");
                                ui->c9->setText("S1");
                                ui->d9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 4){
                            if (y == 0){
                                ui->c0->setText("S1");
                                ui->d0->setText("S1");
                                ui->e0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->c1->setText("S1");
                                ui->d1->setText("S1");
                                ui->e1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->c2->setText("S1");
                                ui->d2->setText("S1");
                                ui->e2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->c3->setText("S1");
                                ui->d3->setText("S1");
                                ui->e3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->c4->setText("S1");
                                ui->d4->setText("S1");
                                ui->e4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->c5->setText("S1");
                                ui->d5->setText("S1");
                                ui->e5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->c6->setText("S1");
                                ui->d6->setText("S1");
                                ui->e6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->c7->setText("S1");
                                ui->d7->setText("S1");
                                ui->e7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->c8->setText("S1");
                                ui->d8->setText("S1");
                                ui->e8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->c9->setText("S1");
                                ui->d9->setText("S1");
                                ui->e9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 5){
                            if (y == 0){
                                ui->d0->setText("S1");
                                ui->e0->setText("S1");
                                ui->f0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->d1->setText("S1");
                                ui->e1->setText("S1");
                                ui->f1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->d2->setText("S1");
                                ui->e2->setText("S1");
                                ui->f2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->d3->setText("S1");
                                ui->e3->setText("S1");
                                ui->f3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->d4->setText("S1");
                                ui->e4->setText("S1");
                                ui->f4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->d5->setText("S1");
                                ui->e5->setText("S1");
                                ui->f5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->d6->setText("S1");
                                ui->e6->setText("S1");
                                ui->f6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->d7->setText("S1");
                                ui->e7->setText("S1");
                                ui->f7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->d8->setText("S1");
                                ui->e8->setText("S1");
                                ui->f8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->d9->setText("S1");
                                ui->e9->setText("S1");
                                ui->f9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 6){
                            if (y == 0){
                                ui->e0->setText("S1");
                                ui->f0->setText("S1");
                                ui->g0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->e1->setText("S1");
                                ui->f1->setText("S1");
                                ui->g1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->e2->setText("S1");
                                ui->f2->setText("S1");
                                ui->g2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->e3->setText("S1");
                                ui->f3->setText("S1");
                                ui->g3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->e4->setText("S1");
                                ui->f4->setText("S1");
                                ui->g4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->e5->setText("S1");
                                ui->f5->setText("S1");
                                ui->g5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->e6->setText("S1");
                                ui->f6->setText("S1");
                                ui->g6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->e7->setText("S1");
                                ui->f7->setText("S1");
                                ui->g7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->e8->setText("S1");
                                ui->f8->setText("S1");
                                ui->g8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->e9->setText("S1");
                                ui->f9->setText("S1");
                                ui->g9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 7){
                            if (y == 0){
                                ui->f0->setText("S1");
                                ui->g0->setText("S1");
                                ui->h0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->f1->setText("S1");
                                ui->g1->setText("S1");
                                ui->h1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->f2->setText("S1");
                                ui->g2->setText("S1");
                                ui->h2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->f3->setText("S1");
                                ui->g3->setText("S1");
                                ui->h3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->f4->setText("S1");
                                ui->g4->setText("S1");
                                ui->h4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->f5->setText("S1");
                                ui->g5->setText("S1");
                                ui->h5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->f6->setText("S1");
                                ui->g6->setText("S1");
                                ui->h6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->f7->setText("S1");
                                ui->g7->setText("S1");
                                ui->h7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->f8->setText("S1");
                                ui->g8->setText("S1");
                                ui->h8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->f9->setText("S1");
                                ui->g9->setText("S1");
                                ui->h9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 8){
                            if (y == 0){
                                ui->g0->setText("S1");
                                ui->h0->setText("S1");
                                ui->i0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->g1->setText("S1");
                                ui->h1->setText("S1");
                                ui->i1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->g2->setText("S1");
                                ui->h2->setText("S1");
                                ui->i2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->g3->setText("S1");
                                ui->h3->setText("S1");
                                ui->i3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->g4->setText("S1");
                                ui->h4->setText("S1");
                                ui->i4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->g5->setText("S1");
                                ui->h5->setText("S1");
                                ui->i5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->g6->setText("S1");
                                ui->h6->setText("S1");
                                ui->i6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->g7->setText("S1");
                                ui->h7->setText("S1");
                                ui->i7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->g8->setText("S1");
                                ui->h8->setText("S1");
                                ui->i8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->g9->setText("S1");
                                ui->h9->setText("S1");
                                ui->i9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 9){
                            if (y == 0){
                                ui->h0->setText("S1");
                                ui->i0->setText("S1");
                                ui->j0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->h1->setText("S1");
                                ui->i1->setText("S1");
                                ui->j1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->h2->setText("S1");
                                ui->i2->setText("S1");
                                ui->j2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->h3->setText("S1");
                                ui->i3->setText("S1");
                                ui->j3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->h4->setText("S1");
                                ui->i4->setText("S1");
                                ui->j4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->h5->setText("S1");
                                ui->i5->setText("S1");
                                ui->j5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->h6->setText("S1");
                                ui->i6->setText("S1");
                                ui->j6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->h7->setText("S1");
                                ui->i7->setText("S1");
                                ui->j7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->h8->setText("S1");
                                ui->i8->setText("S1");
                                ui->j8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->h9->setText("S1");
                                ui->i9->setText("S1");
                                ui->j9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x - 1;
                                ship2[3] = y;
                                ship2[4] = x - 2;
                                ship2[5] = y;
                            }
                        }
                    }
                }
            }
            //direction down
            if (d == 3){
                if (shipGrid[x+1][y] == false){
                    if (shipGrid[x+2][y] == false){
                        if (x == 0){
                            if (y == 0){
                                ui->a0->setText("S1");
                                ui->b0->setText("S1");
                                ui->c0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->a1->setText("S1");
                                ui->b1->setText("S1");
                                ui->c1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->a2->setText("S1");
                                ui->b2->setText("S1");
                                ui->c2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->a3->setText("S1");
                                ui->b3->setText("S1");
                                ui->c3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->a4->setText("S1");
                                ui->b4->setText("S1");
                                ui->c4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->a5->setText("S1");
                                ui->b5->setText("S1");
                                ui->c5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->a6->setText("S1");
                                ui->b6->setText("S1");
                                ui->c6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->a7->setText("S1");
                                ui->b7->setText("S1");
                                ui->c7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->a8->setText("S1");
                                ui->b8->setText("S1");
                                ui->c8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->a9->setText("S1");
                                ui->b9->setText("S1");
                                ui->c9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 1){
                            if (y == 0){
                                ui->b0->setText("S1");
                                ui->c0->setText("S1");
                                ui->d0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->b1->setText("S1");
                                ui->c1->setText("S1");
                                ui->d1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->b2->setText("S1");
                                ui->c2->setText("S1");
                                ui->d2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->b3->setText("S1");
                                ui->c3->setText("S1");
                                ui->d3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->b4->setText("S1");
                                ui->c4->setText("S1");
                                ui->d4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->b5->setText("S1");
                                ui->c5->setText("S1");
                                ui->d5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->b6->setText("S1");
                                ui->c6->setText("S1");
                                ui->d6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->b7->setText("S1");
                                ui->c7->setText("S1");
                                ui->d7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->b8->setText("S1");
                                ui->c8->setText("S1");
                                ui->d8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->b9->setText("S1");
                                ui->c9->setText("S1");
                                ui->d9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 2){
                            if (y == 0){
                                ui->c0->setText("S1");
                                ui->d0->setText("S1");
                                ui->e0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->c1->setText("S1");
                                ui->d1->setText("S1");
                                ui->e1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->c2->setText("S1");
                                ui->d2->setText("S1");
                                ui->e2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->c3->setText("S1");
                                ui->d3->setText("S1");
                                ui->e3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->c4->setText("S1");
                                ui->d4->setText("S1");
                                ui->e4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->c5->setText("S1");
                                ui->d5->setText("S1");
                                ui->e5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->c6->setText("S1");
                                ui->d6->setText("S1");
                                ui->e6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->c7->setText("S1");
                                ui->d7->setText("S1");
                                ui->e7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->c8->setText("S1");
                                ui->d8->setText("S1");
                                ui->e8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->c9->setText("S1");
                                ui->d9->setText("S1");
                                ui->e9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 3){
                            if (y == 0){
                                ui->d0->setText("S1");
                                ui->e0->setText("S1");
                                ui->f0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->d1->setText("S1");
                                ui->e1->setText("S1");
                                ui->f1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->d2->setText("S1");
                                ui->e2->setText("S1");
                                ui->f2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->d3->setText("S1");
                                ui->e3->setText("S1");
                                ui->f3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->d4->setText("S1");
                                ui->e4->setText("S1");
                                ui->f4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->d5->setText("S1");
                                ui->e5->setText("S1");
                                ui->f5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->d6->setText("S1");
                                ui->e6->setText("S1");
                                ui->f6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->d7->setText("S1");
                                ui->e7->setText("S1");
                                ui->f7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->d8->setText("S1");
                                ui->e8->setText("S1");
                                ui->f8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->d9->setText("S1");
                                ui->e9->setText("S1");
                                ui->f9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 4){
                            if (y == 0){
                                ui->e0->setText("S1");
                                ui->f0->setText("S1");
                                ui->g0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->e1->setText("S1");
                                ui->f1->setText("S1");
                                ui->g1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->e2->setText("S1");
                                ui->f2->setText("S1");
                                ui->g2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->e3->setText("S1");
                                ui->f3->setText("S1");
                                ui->g3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->e4->setText("S1");
                                ui->f4->setText("S1");
                                ui->g4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->e5->setText("S1");
                                ui->f5->setText("S1");
                                ui->g5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->e6->setText("S1");
                                ui->f6->setText("S1");
                                ui->g6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->e7->setText("S1");
                                ui->f7->setText("S1");
                                ui->g7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->e8->setText("S1");
                                ui->f8->setText("S1");
                                ui->g8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->e9->setText("S1");
                                ui->f9->setText("S1");
                                ui->g9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 5){
                            if (y == 0){
                                ui->f0->setText("S1");
                                ui->g0->setText("S1");
                                ui->h0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->f1->setText("S1");
                                ui->g1->setText("S1");
                                ui->h1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->f2->setText("S1");
                                ui->g2->setText("S1");
                                ui->h2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->f3->setText("S1");
                                ui->g3->setText("S1");
                                ui->h3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->f4->setText("S1");
                                ui->g4->setText("S1");
                                ui->h4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->f5->setText("S1");
                                ui->g5->setText("S1");
                                ui->h5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->f6->setText("S1");
                                ui->g6->setText("S1");
                                ui->h6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->f7->setText("S1");
                                ui->g7->setText("S1");
                                ui->h7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->f8->setText("S1");
                                ui->g8->setText("S1");
                                ui->h8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->f9->setText("S1");
                                ui->g9->setText("S1");
                                ui->h9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 6){
                            if (y == 0){
                                ui->g0->setText("S1");
                                ui->h0->setText("S1");
                                ui->i0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->g1->setText("S1");
                                ui->h1->setText("S1");
                                ui->i1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->g2->setText("S1");
                                ui->h2->setText("S1");
                                ui->i2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->g3->setText("S1");
                                ui->h3->setText("S1");
                                ui->i3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->g4->setText("S1");
                                ui->h4->setText("S1");
                                ui->i4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->g5->setText("S1");
                                ui->h5->setText("S1");
                                ui->i5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->g6->setText("S1");
                                ui->h6->setText("S1");
                                ui->i6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->g7->setText("S1");
                                ui->h7->setText("S1");
                                ui->i7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->g8->setText("S1");
                                ui->h8->setText("S1");
                                ui->i8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->g9->setText("S1");
                                ui->h9->setText("S1");
                                ui->i9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 7){
                            if (y == 0){
                                ui->h0->setText("S1");
                                ui->i0->setText("S1");
                                ui->j0->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 1){
                                ui->h1->setText("S1");
                                ui->i1->setText("S1");
                                ui->j1->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 2){
                                ui->h2->setText("S1");
                                ui->i2->setText("S1");
                                ui->j2->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 3){
                                ui->h3->setText("S1");
                                ui->i3->setText("S1");
                                ui->j3->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 4){
                                ui->h4->setText("S1");
                                ui->i4->setText("S1");
                                ui->j4->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 5){
                                ui->h5->setText("S1");
                                ui->i5->setText("S1");
                                ui->j5->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 6){
                                ui->h6->setText("S1");
                                ui->i6->setText("S1");
                                ui->j6->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 7){
                                ui->h7->setText("S1");
                                ui->i7->setText("S1");
                                ui->j7->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 8){
                                ui->h8->setText("S1");
                                ui->i8->setText("S1");
                                ui->j8->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                            if (y == 9){
                                ui->h9->setText("S1");
                                ui->i9->setText("S1");
                                ui->j9->setText("S1");
                                ship2_set = true;
                                ship2[0] = x;
                                ship2[1] = y;
                                ship2[2] = x + 1;
                                ship2[3] = y;
                                ship2[4] = x + 2;
                                ship2[5] = y;
                            }
                        }
                        if (x == 8){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ship2_set = false;
                            }
                            if (y == 3){
                                ship2_set = false;
                            }
                            if (y == 4){
                                ship2_set = false;
                            }
                            if (y == 5){
                                ship2_set = false;
                            }
                            if (y == 6){
                                ship2_set = false;
                            }
                            if (y == 7){
                                ship2_set = false;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                        if (x == 9){
                            if (y == 0){
                                ship2_set = false;
                            }
                            if (y == 1){
                                ship2_set = false;
                            }
                            if (y == 2){
                                ship2_set = false;
                            }
                            if (y == 3){
                                ship2_set = false;
                            }
                            if (y == 4){
                                ship2_set = false;
                            }
                            if (y == 5){
                                ship2_set = false;
                            }
                            if (y == 6){
                                ship2_set = false;
                            }
                            if (y == 7){
                                ship2_set = false;
                            }
                            if (y == 8){
                                ship2_set = false;
                            }
                            if (y == 9){
                                ship2_set = false;
                            }
                        }
                    }
                }
            }
        }
    }
}

//gets/returns random number
int second_form::get_randNum(){
    int t;
    t = (rand() % 10);
    return t;
}
//gets/returns random number
int second_form::get_randDirection(){
    int d;
    d = (rand() % 4);
    return d;
}

//00000000000000000000000000000000000000000000000
//User presses >ENTER<
void second_form::on_command_line_returnPressed()
{
    QString userInput;

    switch (get_q_num()) {
    case 0:
        set_ship1();
        //gets text from command_line
        //userInput = ui->command_line->text();
        //sets ship 1 starting coordinate
        //set_player_input(userInput);
        break;
    case 1:
        //gets text from command_line
        //userInput = ui->command_line->text();
        //sets ship coordinate arrays (2 spaces) - Destroyer

        break;
    case 2:
        //first ship placement ui
        break;
    case 3:
        //fourth ship placement (4 spaces) - Battleship

        break;
    case 4:
        //fifth ship placement (5 spaces) - Carrier

        break;
    case 5:
        //set ships for AI(computer) - All five

        break;
    case 6:
        //Gameplay begins - user starts
        break;
    case 7:
        //...
        break;
    case 8:
        //...
        break;
    }
    if (valid == true)
    {

    }
    if (valid == false)
    {

    }

}

#ifndef SECOND_FORM_H
#define SECOND_FORM_H

#include <string>
#include <iostream>
#include <QDialog>

namespace Ui {
class second_form;
}

class second_form : public QDialog
{
    Q_OBJECT

public:
    explicit second_form(QWidget *parent = nullptr);
    ~second_form();

    bool valid;
    int question_num;
    int letter_side;
    int number_side;
    std::string direction;

    //sets the player ships
    void set_ships(QString text);


    //sets ships and ship hits for player_ships grid
    void set_player_coords(QString raw);
    //gets ship locations and ship hits for player_ships grid
    int get_player_ships(int x, int y);


    //sets player to enemy hits and misses
    void set_player_hits_misses(int x, int y, int s);
    //gets player to enemy hits and misses
    int get_player_hits_misses(int x, int y);

    //sets player to enemy hits and misses
    void set_computer_hits_ships(int x, int y, int s);
    //gets player to enemy hits and misses
    int get_computer_ships(int x, int y);

private slots:

    void on_command_line_returnPressed();

private:
    //holds data on where player ships are placed and what ships have been hit
    int player_ships[10][10];
    //holds data on where the player has hit and missed on the computers ships
    int player_hits_misses[10][10];
    //holds data on where computer ships are placed and what ships have been hit
    int computer_ships[10][10];


    Ui::second_form *ui;
};

#endif // SECOND_FORM_H

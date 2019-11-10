#ifndef DEFINE_LABELS_H
#define DEFINE_LABELS_H

#include <string>
#include <iostream>
#include <QDialog>

namespace Ui {
class define_labels;
}

class define_labels : public QDialog
{
    Q_OBJECT


public:
    explicit define_labels(QWidget *parent = nullptr);
    ~define_labels();

    int q_num;
    int let_side;
    int num_side;
    std::string direc;

    void set_ships(int q, int l, int n, std::string d)
    {
        q_num = q;
        let_side = l;
        num_side = n;
        direc = d;

    }

private slots:

    void on_command_line_returnPressed();

private:
    //holds data on where player ships are placed and what ships have been hit
    int player_ships[10][10];
    //holds data on where the player has hit and missed on the computers ships
    int player_hits_misses[10][10];
    //holds data on where computer ships are placed and what ships have been hit
    int computer_ships[10][10];




};

#endif // DEFINE_LABELS_H

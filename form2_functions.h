#ifndef FORM2_FUNCTIONS_H
#define FORM2_FUNCTIONS_H

#include <string>
#include <iostream>
#include <QDialog>

class input
{
private:
    //verifies user input is valid
    bool valid;
    //represents game setup steps
    int q_num;
    //holds user parsed coordinates
    int letter_side;
    int number_side;
    //these are used in getting and setting user input
    QString direction;
    QString userInput;
    QString qLetters[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    QString qNumbers[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

public:

    QString getQL(int l);

    //test
    void set_player_coordsTest(QString raw);

    //sets ships and ship hits for player_ships grid
    void set_player_coords(QString raw);

    //holds data on where player ships are placed and what ships have been hit
    int player_ships[10][10];

    //holds data on where the player has hit and missed on the computers ships
    int player_hits_misses[10][10];

    //holds data on where computer ships are placed and what ships have been hit
    int computer_ships[10][10];
};





//sets the player ships
void set_ships(QString text[10]);


QString getQL(int l);




//test
void set_player_coordsTest(QString raw);


//sets ships and ship hits for player_ships grid
void set_player_coords(QString raw);


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


#endif // FORM2_FUNCTIONS_H

#include "second_form.h"


void second_form::set_player_ships(int x, int y, int s)
{
    int letter_side;
    int number_size;
    if (x == "a" || x == "A"){ letter_side = 0; }
    if (x == "b" || x == "B"){ letter_side = 1; }
    if (x == "c" || x == "C"){ letter_side = 2; }
    if (x == "d" || x == "D"){ letter_side = 3; }
    if (x == "e" || x == "E"){ letter_side = 4; }
    if (x == "f" || x == "F"){ letter_side = 5; }
    if (x == "g" || x == "G"){ letter_side = 6; }
    if (x == "h" || x == "H"){ letter_side = 7; }
    if (x == "i" || x == "I"){ letter_side = 8; }
    if (x == "j" || x == "J"){ letter_side = 9; }
    number_size = std::stoi(y);
}

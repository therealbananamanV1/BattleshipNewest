#ifndef DESTROYER_H
#define DESTROYER_H

#include <string>
#include <iostream>
#include <QDialog>
#include "second_form.h"


class destroyer : public second_form
{
public:
    int get_ship(int s)
    {
        return shipSpan[s];
    }
    void set_ship();


private:
    int shipSpan[2];
    bool shipDestroyed[2];
};

#endif // DESTROYER_H

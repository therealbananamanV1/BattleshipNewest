#ifndef SHIPS_H
#define SHIPS_H

#include <string>
#include <iostream>
#include <QDialog>

namespace Ui {
class ship1;
}

class ship1 : public QDialog
{
public:
    void set_ship();
private:
    int shipSpan[2];
    bool shipDestroyed[2];
};

#endif // SHIPS_H

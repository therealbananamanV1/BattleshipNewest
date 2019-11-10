#ifndef THIRD_FORM_H
#define THIRD_FORM_H
#include <QDialog>

namespace Ui {
class third_form;
}

class third_form : public QDialog
{
    Q_OBJECT

public:
    explicit third_form(QWidget *parent = nullptr);
    ~third_form();

private:
    Ui::third_form *ui;
};
#endif // THIRD_FORM_H

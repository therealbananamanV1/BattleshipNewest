#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int x = 0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton *btn=new QPushButton(this);

private slots:
    void on_button_start_clicked();

    void on_actionNew_Game_triggered();

    void on_button_instructions_clicked();

    void on_actionInstructions_triggered();

    void on_button_quit_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define EMPLOYEE_DB_FILE "../data/employeeinfo.sqlite"

#include <QMainWindow>
#include <QPalette>
#include "database/database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_QT_triggered();
    void on_actionQuit_triggered();
    void on_action_New_Employee_triggered();

private:
    Ui::MainWindow *ui;
    Database *employee_db;
    QPalette *main_palette;
};

#endif // MAINWINDOW_H

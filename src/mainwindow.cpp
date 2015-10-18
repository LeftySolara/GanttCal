#include "../include/mainwindow.h"
#include "../include/addemployeedialog.h"
#include "ui_mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    employee_db = new Database(EMPLOYEE_DB_FILE);
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete db_file;
    delete employee_db;
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_action_New_Employee_triggered()
{
    AddEmployeeDialog add_dialog;
    add_dialog.exec();
}

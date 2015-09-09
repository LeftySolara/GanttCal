#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newemployeewidget.h"
#include "ui_newemployeewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_new_employee_triggered()
{
    NewEmployeeWidget *new_employee_widget = new NewEmployeeWidget();
    new_employee_widget->show();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newemployeedialog.h"
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
    NewEmployeeDialog *new_employee_dialog = new NewEmployeeDialog();
    new_employee_dialog->show();
}

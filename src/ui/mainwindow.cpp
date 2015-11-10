#include "mainwindow.h"
#include "addemployeedialog.h"
#include "ui_mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    employee_db = new Database(EMPLOYEE_DB_FILE);

    model = new QSqlTableModel(0, employee_db->db);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    view = new QTableView;
    view->setModel(model);
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete employee_db;
    delete model;
    delete view;
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionAdd_Employee_triggered()
{
    AddEmployeeDialog add_dialog;
    if (add_dialog.exec() == QDialog::Accepted) {
        QString first = add_dialog.get_first_name();
        QString last = add_dialog.get_last_name();
        QString color = add_dialog.get_color();
        unsigned int max_hours = add_dialog.get_max_hours();

        if (!employee_db->add_employee(first, last, color, max_hours))
            qDebug() << "Failed to add employee to database";
        else
            qDebug() << "Employee added successfully";
    }
}

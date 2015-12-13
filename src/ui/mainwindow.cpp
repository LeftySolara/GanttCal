/* Copyright (C) 2015 Jalen Adams
 *
 * Authors: Jalen Adams <leftysolara@gmail.com>
 *
 * This file is part of GanttCal.
 *
 * GanttCal is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GanttCal is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GanttCal.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "mainwindow.h"
#include "addemployeedialog.h"
#include "ui_mainwindow.h"
#include "utility/utility.h"
#include <QApplication>
#include <QSettings>
#include <QFileInfo>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize_settings();
    initialize_models();
    initialize_views();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete db;
    delete employee_model;
    delete view;
}

void MainWindow::initialize_settings()
{
    // create a settings file if none exists
    if(!utility::settings_exist()) {
      utility::apply_defaults();
    }

    QSettings settings;
    db = new Database(settings.value("database_path").toString());
}

void MainWindow::initialize_models()
{
    employee_model = new QSqlRelationalTableModel(0, db->get_db());
    employee_model->setTable("employee");
    employee_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    employee_model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    employee_model->setHeaderData(1, Qt::Horizontal, QObject::tr("Last Name"));
    employee_model->setHeaderData(2, Qt::Horizontal, QObject::tr("First Name"));
    employee_model->setHeaderData(3, Qt::Horizontal, QObject::tr("Max Hours"));
    employee_model->setHeaderData(4, Qt::Horizontal, QObject::tr("Displayed"));
    employee_model->setHeaderData(5, Qt::Horizontal, QObject::tr("Display Color"));

    employee_model->select();

    // add shift model here once employee model is shown to work
}

void MainWindow::initialize_views()
{
    view = new QTableView;
    view->setModel(employee_model);
    view->setItemDelegate(new QSqlRelationalDelegate(view));
    view->setWindowTitle("List of Employees");

    // add shift view once employee view is shown to work
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
        db->add_employee(first, last, color, max_hours);
    }
}

void MainWindow::on_actionView_Employees_triggered()
{
    view->show();
}

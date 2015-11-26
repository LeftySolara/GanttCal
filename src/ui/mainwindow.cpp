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
  setup();
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
  delete db;
}

void MainWindow::setup()
{
  // create a settings file if none exists
  if(!utility::settings_exist()) {
    utility::apply_defaults();
  }

  QSettings settings;
  db = new Database(settings.value("database_path").toString());
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

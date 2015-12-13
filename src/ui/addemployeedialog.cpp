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

#define DEFAULT_COLOR "#FFFFFF"

#include "addemployeedialog.h"
#include "ui_addemployeedialog.h"
#include <QColorDialog>

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployeeDialog)
{
    color = QColor(DEFAULT_COLOR);
    ui->setupUi(this);
}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}

// Allow user to select a display color for employee
void AddEmployeeDialog::on_buttonColorPicker_clicked()
{
    QPalette picker_palette;
    color = QColorDialog::getColor();

    // getColor() returns and invalid color if user cancels dialog
    // In that case, set color back to default
    if (!color.isValid()) {
        color = QColor(DEFAULT_COLOR);
    }

    picker_palette.setColor(QPalette::Button, color);
    ui->buttonColorPicker->setPalette(picker_palette);
}

QString AddEmployeeDialog::get_last_name()
{
    return ui->lineEditLastName->text();
}

QString AddEmployeeDialog::get_first_name()
{
    return ui->lineEditFirstName->text();
}

QString AddEmployeeDialog::get_color()
{
    return color.name();
}

unsigned int AddEmployeeDialog::get_max_hours()
{
    return ui->lineEditMaxHours->text().toInt();
}

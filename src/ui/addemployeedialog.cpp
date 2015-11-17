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

#include "addemployeedialog.h"
#include "ui_addemployeedialog.h"
#include <QColorDialog>

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployeeDialog)
{
    ui->setupUi(this);
}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}

void AddEmployeeDialog::on_buttonColorPicker_clicked()
{
    QPalette picker_palette;
    color = QColorDialog::getColor();
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

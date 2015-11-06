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

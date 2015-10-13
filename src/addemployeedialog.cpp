#include "../include/addemployeedialog.h"
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
    picker_palette.setColor(QPalette::Button, QColorDialog::getColor());
    ui->buttonColorPicker->setPalette(picker_palette);
}

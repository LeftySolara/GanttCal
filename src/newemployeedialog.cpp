#include "newemployeedialog.h"
#include "ui_newemployeedialog.h"

NewEmployeeDialog::NewEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEmployeeDialog)
{
    ui->setupUi(this);
}

NewEmployeeDialog::~NewEmployeeDialog()
{
    delete ui;
}

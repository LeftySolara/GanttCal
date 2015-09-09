#include "newemployeewidget.h"
#include "ui_newemployeewidget.h"

NewEmployeeWidget::NewEmployeeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewEmployeeWidget)
{
    ui->setupUi(this);
}

NewEmployeeWidget::~NewEmployeeWidget()
{
    delete ui;
}

void NewEmployeeWidget::on_ok_button_clicked()
{
    close();
}

void NewEmployeeWidget::on_cancel_button_clicked()
{
    close();
}

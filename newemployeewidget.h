#ifndef NEWEMPLOYEEWIDGET_H
#define NEWEMPLOYEEWIDGET_H

#include <QWidget>

namespace Ui {
class NewEmployeeWidget;
}

class NewEmployeeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewEmployeeWidget(QWidget *parent = 0);
    ~NewEmployeeWidget();

private slots:
    void on_ok_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::NewEmployeeWidget *ui;
};

#endif // NEWEMPLOYEEWIDGET_H

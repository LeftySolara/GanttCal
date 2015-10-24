#ifndef ADDEMPLOYEEDIALOG_H
#define ADDEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class AddEmployeeDialog;
}

class AddEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployeeDialog(QWidget *parent = 0);
    ~AddEmployeeDialog();
    QString get_last_name();
    QString get_first_name();
    QString get_color();
    unsigned int get_max_hours();

private slots:
    void on_buttonColorPicker_clicked();

private:
    Ui::AddEmployeeDialog *ui;
    QColor color;
};

#endif // ADDEMPLOYEEDIALOG_H

#ifndef NEWEMPLOYEEDIALOG_H
#define NEWEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class NewEmployeeDialog;
}

class NewEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewEmployeeDialog(QWidget *parent = 0);
    ~NewEmployeeDialog();

private:
    Ui::NewEmployeeDialog *ui;
};

#endif // NEWEMPLOYEEDIALOG_H

#ifndef CHANGING_EMPLOYEE_H
#define CHANGING_EMPLOYEE_H

#include <QDialog>

namespace Ui {
class changing_employee;
}

class changing_employee : public QDialog
{
    Q_OBJECT

public:
    explicit changing_employee(QWidget *parent = nullptr);
    ~changing_employee();

private:
    Ui::changing_employee *ui;
};

#endif // CHANGING_EMPLOYEE_H

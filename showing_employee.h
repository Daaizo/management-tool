#ifndef SHOWING_EMPLOYEE_H
#define SHOWING_EMPLOYEE_H

#include <QDialog>
#include "ui_showing_employee.h"
namespace Ui {
class showing_employee;
}

class showing_employee : public QDialog
{
    Q_OBJECT

public:
    explicit showing_employee(QWidget *parent = nullptr);
    ~showing_employee();

private:
    Ui::showing_employee *ui;
};

#endif // SHOWING_EMPLOYEE_H

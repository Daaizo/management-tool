#ifndef CHANGING_EMPLOYEE_H
#define CHANGING_EMPLOYEE_H

#include <QDialog>
#include <QMessageBox>
#include "employee.h"
namespace Ui {
class changing_employee;
}

class changing_employee : public QDialog
{
    Q_OBJECT

public:
    explicit changing_employee(QWidget *parent = nullptr);
    ~changing_employee();
    Employee *tab_of_employees;
    QMessageBox msg;

private slots:
    void on_search_button_clicked();

    void on_save_button_clicked();

    void on_delete_all_button_clicked();

private:
    Ui::changing_employee *ui;
};

#endif // CHANGING_EMPLOYEE_H

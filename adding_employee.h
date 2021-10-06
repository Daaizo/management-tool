#ifndef ADDING_EMPLOYEE_H
#define ADDING_EMPLOYEE_H

#include <QDialog>
#include <QMessageBox>
namespace Ui {
class Adding_employee;
}

class Adding_employee : public QDialog
{
    Q_OBJECT

public:
    explicit Adding_employee(QWidget *parent = nullptr);
    ~Adding_employee();
    QMessageBox msg;

public slots:
    void on_Save_clicked();
    void show_Error_msg();

private slots:
    void on_Clear_clicked();



private:
    Ui::Adding_employee *ui;
};

#endif // ADDING_EMPLOYEE_H

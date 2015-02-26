#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QHeaderView>
#include <QLineEdit>
#include <QString>

#include "student.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void average();

    void on_pushButton_Add_clicked();

    void on_doubleSpinBox_First_editingFinished();

    void on_doubleSpinBox_Second_editingFinished();

private:
    Ui::MainWindow *ui;
    Student* curStudent;

    List<Student> classroom;

    int id;
    QString name;
    double first;
    double second;
    double final;
    int best;
    int worst;
};

#endif // MAINWINDOW_H

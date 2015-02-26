#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    average();
    best = 0;
    worst = 10;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::average() {
    first = this->ui->doubleSpinBox_First->value();
    second = this->ui->doubleSpinBox_Second->value();
    final = (first+second)/2;
    this->ui->lineEdit_Final->setText(QString::number(final));
}

void MainWindow::on_pushButton_Add_clicked()
{
    id = this->ui->spinBox_id->value();
    name = this->ui->lineEdit_Name->text();
    first = this->ui->doubleSpinBox_First->value();
    second = this->ui->doubleSpinBox_Second->value();
    average();
    if(!name.isEmpty()) {
        // Do yout magic ;D
        Student aStudent(id, name, first, second, final);
        classroom.push(aStudent);
        if(aStudent.getGrade() >= best) best = aStudent.getGrade();
        this->ui->lineEdit_Best->setText(QString::number(best));
        if(aStudent.getGrade() <= worst) worst = aStudent.getGrade();
        this->ui->lineEdit_Worst->setText(QString::number(worst));
    }
    // Table view

}

void MainWindow::on_doubleSpinBox_First_editingFinished()
{
    average();
}

void MainWindow::on_doubleSpinBox_Second_editingFinished()
{
    average();
}

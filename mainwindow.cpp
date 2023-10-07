#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    connect(ui->N1,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->N2,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->N3,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->N4,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->N5,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->N6,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->N7,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->N8,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->N9,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->N0,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->div,SIGNAL(clicked(bool)),this,SLOT(calcClickHandler()));
    connect(ui->mul,SIGNAL(clicked(bool)),this,SLOT(calcClickHandler()));
    connect(ui->sub,SIGNAL(clicked(bool)),this,SLOT(calcClickHandler()));
    connect(ui->add,SIGNAL(clicked(bool)),this,SLOT(calcClickHandler()));
    connect(ui->clear,SIGNAL(clicked(bool)),this,SLOT(clear()));
    connect(ui->enter,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
if (!isInputLocked) {
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if(button){
        QLineEdit *currentEdit = (operand == -1) ? ui->num1 : ui->num2;
        currentEdit->setText(currentEdit->text().append(button->text()));
    }
}
}

void MainWindow::commandClickHandler()
{
    float n1 = ui->num1->text().toFloat();
    float n2 = ui->num2->text().toFloat();

    switch(operand){
    case 0:
        result = n1+n2;
        break;
    case 1:
        result = n1-n2;
        break;
    case 2:
        result = n1*n2;
        break;
    case 3:
        if (n2!=0){
        result = n1/n2;
        }
        else{
            ui->result->setText("ei voi jakaa");
            return;
        }
        break;
    default:
        ui->result->setText(" ");
        return;
    }
    ui->result->setText(QString::number(result));

    isInputLocked = true;
}

void MainWindow::calcClickHandler()
{
    if (!isInputLocked) {
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if (button->objectName()=="add"){
        operand = 0;
    }
    else if (button->objectName()=="sub"){
        operand = 1;
    }
    else if (button->objectName()=="mul"){
        operand = 2;
    }
    else if (button->objectName()=="div"){
        operand = 3;
    }
    }
}

void MainWindow::clear()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
    operand = -1;
    isInputLocked = false;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->N0,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N1,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N2,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N3,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N4,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N5,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N6,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N7,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N8,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N9,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::clearAndEnterClickHandler);
    connect(ui->enter,&QPushButton::clicked,this,&MainWindow::clearAndEnterClickHandler);
    connect(ui->add,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->sub,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->mul,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->div,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);


}

MainWindow::~MainWindow()
{
    delete ui;
    ui = Q_NULLPTR;
}

void MainWindow::numberClickedHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(!button)return;
    QString name=button->objectName();
    qDebug()<<"buttonName: "<<name;
    QString num=button->text();
    if(state==1){
        number1+=num;
        ui->num1->setText(number1);
    }
    else if(state==2){
        number2+=num;
        ui->num2->setText(number2);
    }
}

void MainWindow::clearAndEnterClickHandler()
{
    if(state==2){
        float eka = number1.toFloat();
        float toka = number2.toFloat();
        float result2 = 0.00000;
        switch(operand){
        case 1:
            result2=eka+toka;
            break;
        case 2:
            result2=eka-toka;
            break;
        case 3:
            result2=eka*toka;
            break;
        case 4:
            result2=eka/toka;
            break;
        default:
            qDebug()<<"error";
        }
        qDebug()<<"number 1 = "<<number1<<"and number 2 = "<<number2;
        ui->result->setText(QString::number(result2));

    }
    else{
        state = 1;
        resetLineEdits();
        number1.clear();
        number2.clear();
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton *lasku=qobject_cast<QPushButton*>(sender());
    if(!lasku)return;
    QString buttonText=lasku->text();
    qDebug()<<"Operand button : "<<buttonText;
    if(buttonText=="+"){
        operand=1;
    }
    else if(buttonText=="-"){
        operand=2;
    }
    else if(buttonText=="*"){
        operand=3;
    }
    else if(buttonText=="/"){
        operand=4;
    }
    state=2;
    ui->num2->setFocus();

}

void MainWindow::resetLineEdits()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}


void MainWindow::on_N1_clicked()
{

}


void MainWindow::on_N2_clicked()
{

}


void MainWindow::on_N3_clicked()
{

}


void MainWindow::on_N4_clicked()
{

}


void MainWindow::on_N5_clicked()
{

}


void MainWindow::on_N6_clicked()
{

}


void MainWindow::on_N7_clicked()
{

}


void MainWindow::on_N8_clicked()
{

}


void MainWindow::on_N9_clicked()
{

}


void MainWindow::on_N0_clicked()
{

}



void MainWindow::on_add_clicked()
{

}


void MainWindow::on_sub_clicked()
{

}


void MainWindow::on_mul_clicked()
{

}


void MainWindow::on_div_clicked()
{

}


void MainWindow::on_clear_clicked()
{
    state=1;
}


void MainWindow::on_enter_clicked()
{
    state = 2;

}


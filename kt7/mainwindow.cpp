#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Alustetaan
    counter = 0;

    ui->lineEdit->setText(QString::number(counter));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_count_clicked()
{
    // Kasvatetaan laskuria yhdellä ja päivitetään näyttö
    counter++;
    ui->lineEdit->setText(QString::number(counter));
}

void MainWindow::on_reset_clicked()
{
    // Nollataan laskuri ja päivitetään näyttö
    counter = 0;
    ui->lineEdit->setText(QString::number(counter));
}

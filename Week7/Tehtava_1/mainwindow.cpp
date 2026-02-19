#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->naytto->setText(QString::number(luku));

    connect(ui->countButton,&QPushButton::clicked,
           this,&MainWindow::handleClick);

    connect(ui->resetButton,&QPushButton::clicked,
            this,&MainWindow::handleReset);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleClick()
{
    luku++;
    ui->naytto->setText(QString::number(luku));
}

void MainWindow::handleReset()
{
    luku = 0;
    ui->naytto->setText(QString::number(luku));
}


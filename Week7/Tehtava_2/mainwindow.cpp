#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for (int i = 0; i <= 9; ++i) {
        QString nimenAlku = "N" + QString::number(i);
        QPushButton* nappi = findChild<QPushButton*>(nimenAlku);

        if (nappi) {
            connect(nappi, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
        }
    }

    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button ->objectName();
    qDebug() << "Button name:" << name[1];
    if (state == 3)
    {
        resetLineEdits();
        state = 1;
    }
    if (state == 1)
    {
        number1 += name[1];
        qDebug() << "Number1:" << number1;
        ui->num1->setText(number1);
    }
    else
    {
        number2 += name[1];
        qDebug() << "Number2:" << number2;
        ui->num2->setText(number2);
    }
}

void MainWindow::clearAndEnterClickHandler()
{
    // 1. Otetaan kiinni se nappi, jota juuri nyt painettiin
    QPushButton * painettuNappi = qobject_cast<QPushButton*>(sender());

    // 2. Haetaan napin nimi (jonka annoit Qt Designerissa)
    QString nimi = painettuNappi->objectName();
    if (nimi == "enter")
    {
    float n1 = number1.toFloat();
    float n2 = number2.toFloat();
    switch (operand) {
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
        result = n1/n2;
        break;

    }
    qDebug() << result;
    state = 3;
    number1="";
    number2="";
    ui->result->setText(QString::number(result));
    }
    else
    {
        this->resetLineEdits();
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    // 1. Otetaan kiinni se nappi, jota juuri nyt painettiin
    QPushButton * painettuNappi = qobject_cast<QPushButton*>(sender());

    // 2. Haetaan napin nimi (jonka annoit Qt Designerissa)
    QString nimi = painettuNappi->objectName();

    // 3. Tehdään päätös nimen perusteella
    if (nimi == "add") {
        operand = 0;
        state = 2;
    }
    else if (nimi == "sub") {
        operand = 1;
        state = 2;
    }
    else if (nimi == "mul") {
        operand = 2;
        state = 2;
    }
    else if (nimi == "div") {
        operand = 3;
        state = 2;
    }

}

void MainWindow::resetLineEdits()
{
    state = 1;
    number1="";
    number2="";
    ui->result->setText("");
    ui->num1->setText("");
    ui->num2->setText("");
}


#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    pQTimer(new QTimer(this))


{
    ui->setupUi(this);
    setGameInfoText("Select playtime and press start game!",13);
    connect(ui->min2, &QPushButton::clicked, this, &MainWindow::min2ClickHandler);
    connect(ui->min5, &QPushButton::clicked, this, &MainWindow::min5ClickHandler);
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::startClickHandler);
    connect(ui->stop, &QPushButton::clicked, this, &MainWindow::stopClickHandler);
    connect(ui->switchPlayer, &QPushButton::clicked, this, &MainWindow::switchPlayerClickHandler);
    connect(ui->switchPlayer2, &QPushButton::clicked, this, &MainWindow::switchPlayer2ClickHandler);

    connect(pQTimer, &QTimer::timeout, this, &MainWindow::updateProgressBar);

    ui->progressBar->setValue(00);
    ui->progressBar_2->setValue(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateProgressBar()
{
    if (currentPlayer == 1)
    {
        player1Time -= 1;
        int p1Prosentti = (static_cast<float>(player1Time) / gameTime) * 100;
        ui->progressBar->setValue(p1Prosentti);
    }
    else
    {
        player2Time -= 1;
        int p2Prosentti = (static_cast<float>(player2Time) / gameTime) * 100;
        ui->progressBar_2->setValue(p2Prosentti);
    }

    if (player1Time <= 0 || player2Time <= 0)
    {
        pQTimer->stop();
        setGameInfoText("GAME OVER! Winner is Player " + QString::number(currentPlayer == 1 ? 2 : 1), 15);
    }
}

void MainWindow::setGameInfoText(QString teksti, short fontti)
{
    ui->textEdit->setFont(QFont("Arial", fontti));
    ui->textEdit->setText(teksti);
}

void MainWindow::min2ClickHandler()
{
    gameTime = 1200;
    player1Time = gameTime;
    player2Time = gameTime;
    setGameInfoText("ready to play 120 s game ",13);
    ui->progressBar->setValue(100);
    ui->progressBar_2->setValue(100);
}

void MainWindow::min5ClickHandler()
{
    gameTime = 3000;
    player1Time = gameTime;
    player2Time = gameTime;
    setGameInfoText("ready to play 5 min game",13);
    ui->progressBar->setValue(100);
    ui->progressBar_2->setValue(100);
}

void MainWindow::startClickHandler()
{
    if (gameTime == 0) {
        setGameInfoText("Select time first!", 13);
        return;
    }

    currentPlayer = 1;
    pQTimer->start(100);
    setGameInfoText("Game ongoing",13);
}
void MainWindow::stopClickHandler()
{
    pQTimer->stop();
    ui->progressBar->setValue(100);
    ui->progressBar_2->setValue(100);
    gameTime = 0;
}

void MainWindow::switchPlayerClickHandler()
{   if (currentPlayer == 1)
    {
    currentPlayer = 2;
    }
}
void MainWindow::switchPlayer2ClickHandler()
{
    if (currentPlayer == 2)
    {
    currentPlayer = 1;
    }
}

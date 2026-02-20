#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;

    QTimer *pQTimer;
    Ui::MainWindow *ui;


    void setGameInfoText(QString,short);


private slots:
    void updateProgressBar();
    void min2ClickHandler();
    void min5ClickHandler();
    void startClickHandler();
    void stopClickHandler();
    void switchPlayerClickHandler();
    void switchPlayer2ClickHandler();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeout();


};
#endif // MAINWINDOW_H

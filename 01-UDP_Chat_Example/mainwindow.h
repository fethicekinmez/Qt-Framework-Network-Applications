#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "network.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Send_clicked();

    void upcoming(QString value);

    void on_pushButton_SetName_clicked();

private:
    Ui::MainWindow *ui;

    Network *network;
};
#endif // MAINWINDOW_H

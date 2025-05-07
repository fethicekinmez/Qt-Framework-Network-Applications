#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMetaEnum>
#include <QNetworkProxy>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTcpSocket socket;
    QString host = "127.0.0.1";
    quint16 port = 80;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void connectToHost();
    void disconnect();

private slots:
    void on_pushButton_Send_clicked();

    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError socketError);
    void stateChanged(QAbstractSocket::SocketState socketState);
    void readyRead();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

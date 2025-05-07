#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(&socket,&QTcpSocket::connected,this,&MainWindow::connected);
    QObject::connect(&socket,&QTcpSocket::disconnected,this,&MainWindow::disconnected);

    QObject::connect(&socket,&QTcpSocket::stateChanged,this,&MainWindow::stateChanged);
    QObject::connect(&socket,&QTcpSocket::readyRead,this,&MainWindow::readyRead);
    QObject::connect(&socket,&QTcpSocket::errorOccurred,this,&MainWindow::error);

    this->connectToHost();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::connectToHost(){

    if(socket.isOpen()){
        disconnect();
    }

    qInfo() << "Connecting to server " << host << " on port " << port;
    socket.connectToHost(host, port);
}

void MainWindow::disconnect(){

    socket.close();
    socket.waitForDisconnected();
}

void MainWindow::on_pushButton_Send_clicked(){

    QString message = ui->lineEdit_Message->text();
    ui->listWidget_Conversation->addItem(message);
    QByteArray byteArray = message.toUtf8();
    qInfo() << "Sending...";
    socket.write(byteArray);

}

void MainWindow::connected(){

    qInfo() << "Connected!";

}

void MainWindow::disconnected(){

    qInfo() << "Disconnected";
}

void MainWindow::stateChanged(QAbstractSocket::SocketState socketState){

    qInfo() << "State: " << socketState;
}

void MainWindow::readyRead(){

    QByteArray byteArray = socket.readAll();
    QString message = byteArray.data();
    qInfo() << message;
    ui->listWidget_Conversation->addItem(message);

}

void MainWindow::error(QAbstractSocket::SocketError socketError){

    qInfo() << socketError << " : " << socket.errorString();
}





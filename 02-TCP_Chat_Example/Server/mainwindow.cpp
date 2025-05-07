#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);

    server = new QTcpServer(this);

    QObject::connect(server, &QTcpServer::newConnection, this, &MainWindow::newConnection);

    if (!server->listen(QHostAddress::Any, 80)) {
        qDebug() << "Server failed to start";
    } else {
        qDebug() << "Server listening on port " << port;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete server;
}



void MainWindow::newConnection(){

    clientSocket = server->nextPendingConnection();

    QObject::connect(clientSocket, &QTcpSocket::readyRead, this, &MainWindow::readyRead);

    QObject::connect(clientSocket, &QTcpSocket::disconnected, this, &MainWindow::disconnected);

    qDebug() << "Client connected";
    ui->listWidget_Clients->addItem("Client");
}



void MainWindow::readyRead(){

    QByteArray data = clientSocket->readAll();
    QString message = data.data();

    clientSocket->write("Hello from server!");
}

void MainWindow::disconnected(){
    qDebug() << "Client disconnected";
    clientSocket->deleteLater();
}


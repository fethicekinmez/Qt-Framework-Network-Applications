#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    network = new Network(this);

    QObject::connect(network, &Network::upcoming, this, &MainWindow::upcoming);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete network;
}


void MainWindow::on_pushButton_Send_clicked(){

    QString message = ui->lineEdit_Message->text();
    network->send(message);

}

void MainWindow::upcoming(QString value){
    ui->listWidget_Conversation->addItem(value);
}

void MainWindow::on_pushButton_SetName_clicked()
{
    network->setName(ui->lineEdit_Message_2->text());
}


#include "network.h"



Network::Network(QObject *parent) : QObject{parent}{

    if(!socket.bind(port, QUdpSocket::ShareAddress)){
        qDebug() << socket.errorString();
    }
    else{
        qInfo() << "Started UDP on " << socket.localAddress() << " : " << socket.localPort();
        QObject::connect(&socket, &QUdpSocket::readyRead, this, &Network::readyRead);
    }
}

void Network::readyRead(){

    while(socket.hasPendingDatagrams()){
        QNetworkDatagram datagram = socket.receiveDatagram();
        qInfo() << "\tRead: " << datagram.data();
        emit upcoming(datagram.data());
    }
}

void Network::send(QString message){

    message = name + " : " + message;
    QByteArray data = message.toLatin1();

    qint64 bytesWritten = socket.writeDatagram(data.data(), data.size(), QHostAddress::LocalHost, port);
    if (bytesWritten == -1) {
        qDebug() << "Failed to send datagram:" << socket.errorString();
    } else {
        qInfo() << "\tSend: " << data;
    }
}

void Network::setName(const QString &newName)
{
    name = newName;
}

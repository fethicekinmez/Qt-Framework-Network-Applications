#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QDebug>
#include <QUdpSocket>
#include <QNetworkDatagram>

class Network : public QObject
{
    Q_OBJECT

    QString name = "Unknown";
    QUdpSocket socket;
    quint64 port = 2020;

public:
    explicit Network(QObject *parent = nullptr);

    void setName(const QString &newName);

signals:
    void upcoming(QString value);

public slots:
    void readyRead();

    void send(QString message);
};

#endif // NETWORK_H

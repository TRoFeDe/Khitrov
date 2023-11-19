#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QDataStream>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

#include <QString>
#include <QMap>

class MyTcpServer : public QObject
                    @@ -23,9 +23,19 @@ public slots:
                                         void slotServerRead();
//void slotReadClient();
private:
QByteArray Data;
QTcpServer * mTcpServer;
QMap <int, QTcpSocket*> mTcpSocket;
int server_status;
void SendToClient(QString str, QTcpSocket* curr_mTcpSocket);
QString parsing(QString str);
std::string task1();
std::string task2();
std::string task3();
std::string task4();
std::string autor();
std::string reg();
std::string stat();
};
#endif // MYTCPSERVER_H

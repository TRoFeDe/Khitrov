/**
 * @file mytcpclient.h
 * @brief Содержит объявление класса MyClient.
 */

#include <QtWidgets>
#include <QWidget>
#include <QDebug>
#include <QApplication>

/**
 * @class MyClient
 * @brief Представляет клиент для TCP-сервера.
 */
class MyClient : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор для MyClient.
     * @param strHost Адрес хоста.
     * @param nPort Номер порта.
     * @param pwgt Родительский виджет.
     */
    MyClient(const QString& strHost, int nPort, QWidget* pwgt /*=0*/);

public slots:
    void slotReadyRead(); /**< Слот для обработки сигнала о готовности чтения. */
    void slotError(QAbstractSocket::SocketError err); /**< Слот для обработки ошибки сокета. */
    void slotSendToServer(); /**< Слот для отправки данных на сервер. */
    void slotConnected(); /**< Слот для обработки подключения к серверу. */
};

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @file mainwindow.h
 * @brief Этот файл содержит объявление класса MyClient.
 */

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QtNetwork>
#include <QByteArray>

class QTextEdit;
class QLineEdit;

/**
 * @class MyClient
 * @brief Класс MyClient представляет клиент для TCP-сервера.
 */
class MyClient : public QWidget
{
    Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket; /**< Указатель на TCP-сокет. */
    QTextEdit* m_ptxtInfo; /**< Указатель на текстовое поле для отображения информации. */
    QLineEdit* m_ptxtInput; /**< Указатель на поле ввода. */
    quint16 m_nNextBlockSize; /**< Следующий размер блока для обработки данных. */

public:
    /**
     * @brief Конструктор для MyClient.
     * @param strHost Адрес хоста.
     * @param nPort Номер порта.
     * @param pwgt Родительский виджет.
     */
    MyClient(const QString& strHost, int nPort, QWidget *pwgt = 0);

private slots:
    void slotReadyRead (); /**< Слот для обработки сигнала о готовности чтения. */
    void slotError (QAbstractSocket::SocketError); /**< Слот для обработки ошибки сокета. */
    void slotSendToServer (); /**< Слот для отправки данных на сервер. */
    void slotConnected (); /**< Слот для обработки подключения к серверу. */
};

#endif // MAINWINDOW_H

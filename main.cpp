/**
 * @file main.cpp
 * @brief Главный файл приложения.
 */

#include "mytcpserver.h"
#include <QtWidgets>
#include "mytcpclient.h"
#include <QApplication>

/**
 * @brief Точка входа в приложение.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код завершения приложения.
 */
int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    MyServer server(2323); /**< Создание объекта сервера. */
    server.show(); /**< Отображение сервера. */

    MyClient client("localhost", 2323); /**< Создание объекта клиента. */
    client.show(); /**< Отображение клиента. */

    return a.exec(); /**< Запуск цикла обработки событий приложения. */
}

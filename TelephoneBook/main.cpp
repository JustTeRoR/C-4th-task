// 12. Разработать приложение "Записная книжка". Список функциональности:
//     а) Хранение контактов, ФИО, телефоны, группы контактов
//     б) Хранение напоминаний: Время события, название, пояснение, связь с контактом или группой контактов.


#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

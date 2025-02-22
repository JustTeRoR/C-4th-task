#ifndef LOGGER_H
#define LOGGER_H

#include <QTimer>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

const QString INFOFILE = "/Users/just_terror/TeleBook/TelephoneBook/info.log";

class Logger
{
public:
    Logger();
    void saveToFile(const QString message, const uchar importance);
};

#endif // LOGGER_H

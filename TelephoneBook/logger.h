#ifndef LOGGER_H
#define LOGGER_H

#include <QTimer>
#include <QFile>
#include <QDateTime>
#include <QTextStream>


const int ROWLIMIT = 40;
const QString INFOFILE = "info.log";

class Logger
{
public:
    Logger();
    void saveToFile(const QString message, const uchar importance);
};

#endif // LOGGER_H

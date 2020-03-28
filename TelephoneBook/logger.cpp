#include "logger.h"

Logger::Logger()
{
    QFile file(INFOFILE);
    file.resize(0);
}

void Logger::saveToFile(const QString message, const uchar importance)
{
    QFile file(INFOFILE);
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << message << " importance: " << importance << " time: " << QDateTime::currentDateTime().toString() << '\n';
        file.close();
    }
}

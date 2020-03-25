#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <ctime>
#include <string>
#include "logger.h"

class Notification : Logger
{
protected:
    time_t date_;
    std::string notificationName_;
    std::string notificationDetails_;

    //TODO:: Придумать как связать напоминания с контактом(группой контактов)

public:
    Notification();
};

#endif // NOTIFICATION_H

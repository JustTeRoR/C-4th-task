#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <ctime>
#include <string>
#include "logger.h"
#include "contact.h"

class Notification : Logger
{
protected:
    time_t date_;
    std::string notificationName_;
    std::string notificationDetails_;
    bool isGroupNotification_;
    Contact *relatedToContact_;
    contactGroup relatedToGroup_;

public:
    Notification(time_t date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, Contact *relatedContact);
    Notification(time_t date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup);
};

#endif // NOTIFICATION_H

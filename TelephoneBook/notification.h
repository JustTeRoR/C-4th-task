#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <ctime>
#include <string>
#include "logger.h"
#include "contact.h"

class Notification
{
protected:
    QDateTime date_;
    std::string notificationName_;
    std::string notificationDetails_;
    bool isGroupNotification_;
    Contact *relatedToContact_;
    contactGroup relatedToGroup_;

public:
    Notification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, Contact *relatedContact);
    Notification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup);
    std::string getNameNotification();
    std::string getDetailsNotification();
    std::string getRelatedContactNotificationStringRepresentance();
    std::string getNotificationGroupStringRepresentance();
    QDateTime getDateNotification();
};

#endif // NOTIFICATION_H

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
    static bool createValidNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, std::string relatedContactPhone,
                                        std::string &errorMessage, std::vector<Notification> &notificationList, std::vector<Contact> &contactList);
    static bool createValidGroupNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup,
                                             std::string &errorMessage, std::vector<Notification> &notificationList);
    std::string getNameNotification();
    std::string getDetailsNotification();
    std::string getRelatedContactNotificationStringRepresentance();
    std::string getNotificationGroupStringRepresentance();
    std::string getIsGroupNotificationStringRepresentance();
    QDateTime getDateNotification();
private:
    Notification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, Contact *relatedContact);
    Notification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup);
};

#endif // NOTIFICATION_H

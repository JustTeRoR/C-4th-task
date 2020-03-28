#include "notification.h"

Notification::Notification(time_t date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup)
{
    this->date_ = date;
    this->notificationName_ = notificationName;
    this->notificationDetails_ = notificationDetails;
    this->isGroupNotification_ = isGroupNotification;
    this->relatedToGroup_ = relatedGroup;
}

Notification::Notification(time_t date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, Contact *relatedContact)
{
    this->date_ = date;
    this->notificationName_ = notificationName;
    this->notificationDetails_ = notificationDetails;
    this->isGroupNotification_ = isGroupNotification;
    this->relatedToContact_ = relatedContact;
}

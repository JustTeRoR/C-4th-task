#include "notification.h"

Notification::Notification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup)
{
    this->date_ = date;
    this->notificationName_ = notificationName;
    this->notificationDetails_ = notificationDetails;
    this->isGroupNotification_ = isGroupNotification;
    this->relatedToGroup_ = relatedGroup;
    this->relatedToContact_ = nullptr;
}

Notification::Notification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, Contact *relatedContact)
{
    this->date_ = date;
    this->notificationName_ = notificationName;
    this->notificationDetails_ = notificationDetails;
    this->isGroupNotification_ = isGroupNotification;
    this->relatedToContact_ = relatedContact;
}

std::string Notification::getNameNotification()
{
    return this->notificationName_;
}

 std::string Notification::getNotificationGroupStringRepresentance()
 {
        if (this->relatedToGroup_ == contactGroup::WORK)
         {
             return "WORK";
         }
         else if (this->relatedToGroup_ == contactGroup::FAMILY)
         {
             return "FAMILY";
         }
         else if (this->relatedToGroup_ == contactGroup::FRIENDS)
         {
             return "FRIENDS";
         }
         else if (this->relatedToGroup_ == contactGroup::FAVOURITES)
         {
             return "FAVOURITES";
         }
         else
             return "Not in group";
 }

 std::string Notification::getDetailsNotification()
 {
    return this->notificationDetails_;
 }

 std::string Notification::getRelatedContactNotificationStringRepresentance()
 {
     std::string result;
     if (relatedToContact_ != nullptr)
     {
         result = this->relatedToContact_->getContactPhoneNumber();
     }
     else
     {
         result = "групповое напоминание";
     }
     return result;
 }

 QDateTime Notification::getDateNotification()
 {
    return this->date_;
 }

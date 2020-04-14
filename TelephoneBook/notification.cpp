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


 bool Notification::createValidNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, std::string relatedContactPhone,
                                     std::string &errorMessage, std::vector<Notification> &notificationList, std::vector<Contact> &contactList)
 {
     if (notificationName == "")
     {
         errorMessage = "Введите, пожалуйста, название напоминания";
         return false;
     }

     if (relatedContactPhone == "")
     {
         errorMessage = "Для негруппового напоминания номер обязательно должен быть заполнен";
         return false;
     }

     if (relatedContactPhone == "")
     {
         errorMessage = "Для негруппового напоминания номер обязательно должен быть заполнен";
         return false;
     }


     Contact *relatedContact  = nullptr;
     for (int i = 0; i < contactList.size(); i++)
     {
         if (contactList[i].getContactPhoneNumber() == relatedContactPhone)
             relatedContact = &contactList[i];
     }

     if (relatedContact == nullptr)
     {
         errorMessage = "Указан номер, которого не существует в списке контактов";
         return false;
     }
     notificationList.push_back(Notification{date,notificationName,notificationDetails,isGroupNotification, relatedContact });
     return true;
 }
 bool Notification::createValidGroupNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup,
                                          std::string &errorMessage, std::vector<Notification> &notificationList)
 {
     if (notificationName == "")
     {
         errorMessage = "Введите, пожалуйста, название напоминания";
         return false;
     }

     if (relatedGroup == contactGroup::NOTINGROUP)
     {
         errorMessage = "Для группового напоминания обязательно должна быть выбрана группа";
         return false;
     }

     notificationList.push_back(Notification{date,notificationName,notificationDetails,isGroupNotification, relatedGroup });
     return true;

 }

 std::string Notification::getIsGroupNotificationStringRepresentance()
 {
    if(isGroupNotification_)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
 }

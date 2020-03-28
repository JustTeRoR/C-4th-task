#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.h"
#include "notification.h"
#include <vector>

const int RUSSIAN_PHONE_NUMBER_LENGTH = 12; //with + sign

class PhoneBook : Logger
{
protected:
    std::vector <Contact> contactList_;
    std::vector <Notification> notificationList_;
public:
    PhoneBook();
    bool CreateNewContact(std::string name, std::string surname, std::string fathersName,std::string tepephoneNumber, contactGroup contactGroup,  std::string &errorMessage);
    bool CreateNewNotification(time_t date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup, std::string &errorMessage);
    bool CreateNewNotification(time_t date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, std::string relatedContactPhone, std::string &errorMessage);
};

#endif // PHONEBOOK_H

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
    bool CreateNewNotification();

};

#endif // PHONEBOOK_H

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.h"
#include "notification.h"
#include <vector>

class PhoneBook
{
protected:
    std::vector <Contact> contactList_;
    std::vector <Notification> notificationList_;
public:
    PhoneBook();
    bool CreateNewContact(std::string name, std::string surname, std::string fathersName,std::string telephoneNumber, contactGroup contactGroup,  std::string &errorMessage);
    bool CreateNewNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup, std::string &errorMessage);
    bool CreateNewNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, std::string relatedContactPhone, std::string &errorMessage);

    std::vector<Contact>& getContactList();
    std::vector<Notification>& getNotificationList();
    void deleteContact(std::string telephoneNumber);
    void deleteNotification(std::string notificationName);

};

#endif // PHONEBOOK_H

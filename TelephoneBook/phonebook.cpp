#include "phonebook.h"

PhoneBook::PhoneBook()
{
    this->contactList_.clear();
    this->notificationList_.clear();

}

bool PhoneBook::CreateNewContact(std::string name, std::string surname, std::string fathersName,std::string telephoneNumber, contactGroup contactGroup, std::string &errorMessage)
{
    return (Contact::createValidContact(name, surname, fathersName, telephoneNumber, contactGroup, errorMessage, this->contactList_));
}

bool PhoneBook::CreateNewNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup, std::string &errorMessage)
{
    return (Notification::createValidGroupNotification(date, notificationName, notificationDetails, isGroupNotification, relatedGroup, errorMessage, notificationList_));
}

bool PhoneBook::CreateNewNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, std::string relatedContactPhone, std::string &errorMessage)
{
    return (Notification::createValidNotification(date, notificationName, notificationDetails, isGroupNotification, relatedContactPhone, errorMessage, notificationList_, contactList_));
}

std::vector<Contact>& PhoneBook::getContactList()
{
    return contactList_;
}

std::vector<Notification>& PhoneBook::getNotificationList()
{
    return notificationList_;
}

void PhoneBook::deleteContact(std::string telephoneNumber)
{
    uint contactId = 0;
    for (auto &contact : contactList_) {
        if (contact.getContactPhoneNumber() == telephoneNumber) {
                 contactList_.erase(contactList_.begin() + contactId);
        }
        ++contactId;
    }
}

void PhoneBook::deleteNotification(std::string notificationName)
{
    uint notificationId = 0;
    for (auto &notification : notificationList_) {
        if (notification.getNameNotification() == notificationName) {
                 notificationList_.erase(notificationList_.begin() + notificationId);
        }
        ++notificationId;
    }
}


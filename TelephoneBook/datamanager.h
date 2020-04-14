#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include "phonebook.h"

const QString CONTACTFILE = "/Users/just_terror/TeleBook/TelephoneBook/contacts.txt";
const QString NOTIFICATIONSFILE = "/Users/just_terror/TeleBook/TelephoneBook/notifications.txt";

class DataManager
{
public:
    DataManager();
    void saveDataToFile(const char separator, PhoneBook &phonebook);
    void getDataFromFile(std::vector<Contact> &contactList, std::vector<Notification> &notificationList);
};

#endif // DATAMANAGER_H

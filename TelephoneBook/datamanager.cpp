#include "datamanager.h"

DataManager::DataManager()
{

}

void DataManager::saveDataToFile(const char separator, PhoneBook &phonebook)
{
    QFile contactFile(CONTACTFILE);
    QFile notificationsFile(NOTIFICATIONSFILE);
    contactFile.resize(0);
    notificationsFile.resize(0);


    QString contactData = "";
    QString notificationData = "";

    for (int i = 0; i < phonebook.getContactList().size(); i++)
    {
        QString formatQstring = QString::fromStdString(phonebook.getContactList()[i].getContactFullName() + " "+ phonebook.getContactList()[i].getContactPhoneNumber() +
                                                       " " + phonebook.getContactList()[i].getContactGroupStringRepresentance() + separator);
        contactData.append(formatQstring);
    }

    for (int i = 0; i < phonebook.getNotificationList().size(); i++)
    {
        QString formatQstring = QString::fromStdString(phonebook.getNotificationList()[i].getDateNotification().toString().toStdString()  + " "+ phonebook.getNotificationList()[i].getNameNotification() + " " + phonebook.getNotificationList()[i].getDetailsNotification() +
                                                       " " + phonebook.getNotificationList()[i].getIsGroupNotificationStringRepresentance() + " " + phonebook.getNotificationList()[i].getRelatedContactNotificationStringRepresentance()
                                                       + " " + phonebook.getNotificationList()[i].getNotificationGroupStringRepresentance() + separator);
        notificationData.append(formatQstring);
    }


    if(contactFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&contactFile);
        stream << contactData;
        contactFile.close();
    }

    if(notificationsFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&notificationsFile);
        stream << notificationData;
        notificationsFile.close();
    }
}
void DataManager::getDataFromFile(std::vector<Contact> &contactList, std::vector<Notification> &notificationList)
{
    QFile contactFile(CONTACTFILE);
    QFile notificationsFile(NOTIFICATIONSFILE);


    if (contactFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&contactFile);
        while(!stream.atEnd())
        {
            QString line = stream.readLine();
            QStringList lineParts = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
            std::string errors = "";
            contactGroup groupOfContact;
            if (lineParts[4].toStdString() == "WORK")
            {
                groupOfContact =  contactGroup::WORK;
            }
            else if (lineParts[4].toStdString() == "FAMILY")
            {
                groupOfContact =  contactGroup::FAMILY;
            }
            else if (lineParts[4].toStdString() == "FRIENDS")
            {
                groupOfContact =  contactGroup::FRIENDS;
            }
            else if (lineParts[4].toStdString() == "FAVOURITES")
            {
                groupOfContact =  contactGroup::FAVOURITES;
            }
            else
                groupOfContact =  contactGroup::NOTINGROUP;

            Contact::createValidContact(lineParts[0].toStdString(), lineParts[1].toStdString(), lineParts[2].toStdString(), lineParts[3].toStdString(),
                    groupOfContact, errors, contactList);

        }
    }
}

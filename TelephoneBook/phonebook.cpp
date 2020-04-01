#include "phonebook.h"

PhoneBook::PhoneBook()
{
    this->contactList_.clear();
    this->notificationList_.clear();

}

bool PhoneBook::CreateNewContact(std::string name, std::string surname, std::string fathersName,std::string telephoneNumber, contactGroup contactGroup, std::string &errorMessage)
{
    if (name == "")
    {
        errorMessage = "Пустое имя контакта";
        return false;
    }

    if (surname == "")
    {
        errorMessage = "Пустая фамилия контакта";
        return false;
    }

    if (fathersName == "")
    {
        errorMessage = "Пустое отчество контакта";
        return false;
    }
    if (telephoneNumber[0] == '+' and telephoneNumber[1] != '7')
    {
        errorMessage = "Неверное начало номера, номер должен начинаться с \"+7\" или \"8\"";
        return false;
    }
    if (telephoneNumber[0] != '+' and telephoneNumber[0] != '8')
    {
        errorMessage = "Неверное начало номера, номер должен начинаться с \"+7\" или \"8\"";
        return false;
    }

    if (telephoneNumber[0] == '+' and telephoneNumber.length() != RUSSIAN_PHONE_NUMBER_LENGTH)
    {
        errorMessage = "Неверный формат телефонного номера, если используете + длина должна быть 12 символов";
        return false;
    }
    if (telephoneNumber[0] != '+' and telephoneNumber.length() != RUSSIAN_PHONE_NUMBER_LENGTH - 1)
    {
        errorMessage = "Неверный формат телефонного номера, если используете + длина должна быть 11 символов";
        return false;
    }
/*
    if (contactGroup != contactGroup::WORK and contactGroup != contactGroup::FAMILY and contactGroup != contactGroup::FAVOURITES and contactGroup != contactGroup::FRIENDS)
    {
        errorMessage = "Пожалуйста, утрочните группу контакта";
        return false;
    }
*/
    contactList_.push_back(Contact {name, surname, fathersName, telephoneNumber, contactGroup });
    return  true;

}

bool PhoneBook::CreateNewNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, contactGroup relatedGroup, std::string &errorMessage)
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

    notificationList_.push_back(Notification{date,notificationName,notificationDetails,isGroupNotification, relatedGroup });
    return true;
}

bool PhoneBook::CreateNewNotification(QDateTime date, std::string notificationName, std::string notificationDetails, bool isGroupNotification, std::string relatedContactPhone, std::string &errorMessage)
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

    //Здесь проьлема с null
    Contact *relatedContact  = nullptr;
    for (int i = 0; i < this->contactList_.size(); i++)
    {
        if (this->contactList_[i].getContactPhoneNumber() == relatedContactPhone)
            relatedContact = &this->contactList_[i];
    }

    if (relatedContact == nullptr)
    {
        errorMessage = "Указан номер, которого не существует в списке контактов";
        return false;
    }
    notificationList_.push_back(Notification{date,notificationName,notificationDetails,isGroupNotification, relatedContact });
    return true;
}

std::vector<Contact> PhoneBook::getContactList()
{
    return contactList_;
}

std::vector<Notification> PhoneBook::getNotificationList()
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


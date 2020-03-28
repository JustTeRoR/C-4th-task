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
bool PhoneBook::CreateNewNotification()
{

}

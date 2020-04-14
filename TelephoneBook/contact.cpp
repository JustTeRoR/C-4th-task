#include "contact.h"

Contact::Contact(std::string name, std::string surname, std::string fathersName,std::string telephoneNumber, contactGroup contactGroup)
{
    this->name_ = name;
    this->surname_ = surname;
    this->fathersName_ = fathersName;
    this->telephoneNum_ = telephoneNumber;
    this->contactGroup_ = contactGroup;
}

std::string Contact::getContactPhoneNumber()
{
    return this->telephoneNum_;
}

std::string Contact::getContactFullName()
{
    return this->name_ + " " + this->surname_ + " " + this->fathersName_;
}

 std::string Contact::getContactGroupStringRepresentance()
 {
    if (this->contactGroup_ == contactGroup::WORK)
    {
        return "WORK";
    }
    else if (this->contactGroup_ == contactGroup::FAMILY)
    {
        return "FAMILY";
    }
    else if (this->contactGroup_ == contactGroup::FRIENDS)
    {
        return "FRIENDS";
    }
    else if (this->contactGroup_ == contactGroup::FAVOURITES)
    {
        return "FAVOURITES";
    }
    else
        return "NOTINGROUP";
 }

 bool Contact::createValidContact(std::string name, std::string surname, std::string fathersName,std::string telephoneNumber, contactGroup contactGroup,  std::string &errorMessage,  std::vector<Contact> &contactList)
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
     if (verifyForDuplicateNumber(telephoneNumber,contactList))
     {
        errorMessage = "Контакт с указанным номером уже существует";
        return false;
     }

     contactList.push_back(Contact {name, surname, fathersName, telephoneNumber, contactGroup });
     return  true;
 }

 bool Contact::verifyForDuplicateNumber(std::string number, std::vector<Contact> &contactList)
 {
     for (int i = 0; i < contactList.size(); i++)
     {
        if (contactList[i].getContactPhoneNumber() == number)
        {
            return true;
        }
     }
     return false;
 }

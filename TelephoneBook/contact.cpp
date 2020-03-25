#include "contact.h"

Contact::Contact(std::string name, std::string surname, std::string fathersName,std::string telephoneNumber, contactGroup contactGroup)
{
    //TODO:: Возмонжо добавить доп проверки для сохранения номеров в корректном виде
    this->name_ = name;
    this->surname_ = surname;
    this->fathersName_ = fathersName;
    this->tepephoneNum_ = telephoneNumber;
    this->contactGroup_ = contactGroup;
}

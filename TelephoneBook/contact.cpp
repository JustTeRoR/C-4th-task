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
        return "Not in group";
 }

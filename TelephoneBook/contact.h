#ifndef CONTACT_H
#define CONTACT_H

#include "logger.h"
#include<string>

enum class contactGroup { FAMILY, WORK, FRIENDS, FAVOURITES, NOTINGROUP};
const int RUSSIAN_PHONE_NUMBER_LENGTH = 12; //with + sign

class Contact
{
protected:
    std::string name_;
    std::string surname_;
    std::string fathersName_;
    std::string telephoneNum_;
    contactGroup contactGroup_;

public:
    static bool createValidContact(std::string name, std::string surname, std::string fathersName,std::string telephoneNumber, contactGroup contactGroup,  std::string &errorMessage, std::vector<Contact> &contactList);
    std::string getContactPhoneNumber();
    std::string getContactFullName();
    std::string getContactGroupStringRepresentance();

private:
    Contact(std::string name, std::string surname, std::string fathersName,std::string telephoneNumber, contactGroup contactGroup);
    static bool verifyForDuplicateNumber(std::string number, std::vector<Contact> &contactList);
};

#endif // CONTACT_H

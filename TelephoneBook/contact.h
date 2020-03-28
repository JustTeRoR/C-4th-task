#ifndef CONTACT_H
#define CONTACT_H

#include "logger.h"
#include<string>

enum class contactGroup { FAMILY, WORK, FRIENDS, FAVOURITES, NOTINGROUP};

class Contact : Logger
{
protected:
    std::string name_;
    std::string surname_;
    std::string fathersName_;
    std::string tepephoneNum_;
    contactGroup contactGroup_;

public:
    Contact(std::string name, std::string surname, std::string fathersName,std::string telephoneNumber, contactGroup contactGroup);

};

#endif // CONTACT_H

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.h"
#include "notification.h"
#include <vector>

class PhoneBook
{
protected:
    std::vector <Contact> contactList_;
    std::vector <Notification> notificationList_;
public:
    PhoneBook();
};

#endif // PHONEBOOK_H

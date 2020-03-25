#ifndef CREATECONTACT_H
#define CREATECONTACT_H

#include <QWidget>

namespace Ui {
class createContact;
}

class createContact : public QWidget
{
    Q_OBJECT

public:
    explicit createContact(QWidget *parent = nullptr);
    ~createContact();

private:
    Ui::createContact *ui;
};

#endif // CREATECONTACT_H

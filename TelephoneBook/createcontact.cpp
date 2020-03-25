#include "createcontact.h"
#include "ui_createcontact.h"

createContact::createContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createContact)
{
    ui->setupUi(this);
}

createContact::~createContact()
{
    delete ui;
}

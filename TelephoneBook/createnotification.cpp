#include "createnotification.h"
#include "ui_createnotification.h"

createNotification::createNotification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createNotification)
{
    ui->setupUi(this);
}

void createNotification::on_pushButtonAddNotificationButton_clicked()
{
    contactGroup newContactGroup = contactGroup::NOTINGROUP;
    if (ui->work_rb->isChecked())
        newContactGroup = contactGroup::WORK;
    if (ui->family_rb->isChecked())
        newContactGroup = contactGroup::FAMILY;
    if (ui->friends_rb->isChecked())
        newContactGroup = contactGroup::FRIENDS;
    if (ui -> friends_rb-> isChecked())
        newContactGroup = contactGroup::FAVOURITES;

    std::string errorMessage;

}

createNotification::~createNotification()
{
    delete ui;
}

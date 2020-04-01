#include "createnotification.h"
#include "ui_createnotification.h"

createNotification::createNotification(QWidget *parent,Logger *logger, PhoneBook *phonebook) :
    QWidget(parent),
    ui(new Ui::createNotification)
{
    ui->setupUi(this);
    logger_ = logger;
    phoneBook_ = phonebook;
}

void createNotification::on_AddNotificationButton_clicked()
{
    contactGroup newContactGroup = contactGroup::NOTINGROUP;
    if (ui->work_rb->isChecked())
        newContactGroup = contactGroup::WORK;
    if (ui->family_rb->isChecked())
        newContactGroup = contactGroup::FAMILY;
    if (ui->friends_rb->isChecked())
        newContactGroup = contactGroup::FRIENDS;
    if (ui -> favourite_rb-> isChecked())
        newContactGroup = contactGroup::FAVOURITES;
    std::string errorMessage;
    if (ui->isGroupNotification_cb->isChecked())
    {
        if (!phoneBook_->CreateNewNotification(
                    ui->notificationDate_de->dateTime(),
                    ui->notificationName_le->text().toStdString(),
                    ui->notificationDetails_te->toPlainText().toStdString(),
                    ui->isGroupNotification_cb->isChecked(),
                    newContactGroup,
                    errorMessage))
        {
            QMessageBox messageBox(this);
            messageBox.setText(errorMessage.c_str());
            messageBox.exec();
            return;
        }
    }
    else
    {
         if (!phoneBook_->CreateNewNotification(
                  ui->notificationDate_de->dateTime(),
                  ui->notificationName_le->text().toStdString(),
                  ui->notificationDetails_te->toPlainText().toStdString(),
                  ui->isGroupNotification_cb->isChecked(),
                  ui->phoneNumOfNotificatonContact_le->text().toStdString(),
                  errorMessage))
        {
            QMessageBox messageBox(this);
            messageBox.setText(errorMessage.c_str());
            messageBox.exec();
            return;
        }
    }

    logger_->saveToFile("Add notification: " + ui->notificationName_le->text() + " " + ui->notificationDetails_te->toPlainText() + " " + ui->phoneNumOfNotificatonContact_le->text(), 5);
}

createNotification::~createNotification()
{
    delete ui;
}

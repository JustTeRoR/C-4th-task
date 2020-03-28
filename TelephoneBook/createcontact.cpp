#include "createcontact.h"
#include "ui_createcontact.h"
#include "logger.h"

createContact::createContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createContact)
{
    ui->setupUi(this);
    Logger logger = Logger();
}

void createContact::on_pushButtonAddContact_clicked()
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
    if (!phoneBook.CreateNewContact(
                ui->name_le->text().toStdString(),
                ui->surname_le->text().toStdString(),
                ui->fatrhersName_le->text().toStdString(),
                ui->phoneNumber_le->text().toStdString(),
                newContactGroup,
                errorMessage)) {
        QMessageBox messageBox(this);
        messageBox.setText(errorMessage.c_str());
        messageBox.exec();
        return;
    }
    //saveToFile("Add student: " + ui->lineEdit->text(), 5);

}

createContact::~createContact()
{
    delete ui;
}

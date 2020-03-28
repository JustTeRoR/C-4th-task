#ifndef CREATECONTACT_H
#define CREATECONTACT_H

#include <QWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QComboBox>
#include <QTextBrowser>
#include <QMessageBox>
#include "phonebook.h"
#include "logger.h"

QT_BEGIN_NAMESPACE
namespace Ui { class createContact; }
QT_END_NAMESPACE


class createContact : public QWidget
{
    Q_OBJECT

public:
    //, Logger *logger = nullptr, PhoneBook *phonebook = nullptr
    explicit createContact(QWidget *parent = nullptr);
    ~createContact();
private slots:
    void on_pushButtonAddContact_clicked();

private:
    Ui::createContact *ui;
    Logger logger_;
    PhoneBook phoneBook_;
};

#endif // CREATECONTACT_H

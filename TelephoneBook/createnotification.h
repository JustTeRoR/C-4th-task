#ifndef CREATENOTIFICATION_H
#define CREATENOTIFICATION_H

#include <QWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QComboBox>
#include <QTextBrowser>
#include <QMessageBox>
#include "phonebook.h"
#include "logger.h"

QT_BEGIN_NAMESPACE
namespace Ui { class createNotification; }
QT_END_NAMESPACE

class createNotification : public QWidget
{
    Q_OBJECT

public:
    explicit createNotification(QWidget *parent = nullptr,Logger *logger = nullptr, PhoneBook *phonebook = nullptr);
    ~createNotification();

private slots:
    void on_AddNotificationButton_clicked();

private:
    Ui::createNotification *ui;
    Logger *logger_;
    PhoneBook *phoneBook_;
};

#endif // CREATENOTIFICATION_H

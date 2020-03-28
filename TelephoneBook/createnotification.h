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
    explicit createNotification(QWidget *parent = nullptr);
    ~createNotification();

private slots:
    void on_pushButtonAddNotificationButton_clicked();

private:
    Ui::createNotification *ui;
};

#endif // CREATENOTIFICATION_H

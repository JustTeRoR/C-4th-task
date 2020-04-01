#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QStackedLayout>
#include <QPushButton>
#include <QTextBrowser>
#include <QCheckBox>
#include <QComboBox>
#include <QStandardItemModel>
#include<QDate>
#include "phonebook.h"
#include <createcontact.h>
#include <createnotification.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const int ROWLIMIT = 40;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update();

    void on_AddContactButton_clicked();
    void on_AddNotificationButton_clicked();
    void on_DeleteContactButton_clicked();
    void on_DeleteNotificationButton_clicked();

private:
    Ui::MainWindow *ui;
    createContact *createContactWindow_;
    createNotification *createNotificationWindow_;
    PhoneBook *phonebook_;
    Logger *logger_;
    QStandardItemModel *m_model_contacts = nullptr;
    QStandardItemModel *m_model_notifications = nullptr;
    std::vector<std::pair<std::string, std::string>> contactAndNumbers;
};
#endif // MAINWINDOW_H

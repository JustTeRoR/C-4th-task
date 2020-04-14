#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->logger_ = new Logger();
    this->phonebook_ = new PhoneBook();
    this->dataManager = new DataManager();

    this->createContactWindow_ = new createContact(nullptr, logger_,phonebook_);
    this->createNotificationWindow_ = new createNotification(nullptr, logger_,phonebook_);

    m_model_contacts = new QStandardItemModel();

    QStringList horizontalHeader;
    horizontalHeader.append("ФИО");
    horizontalHeader.append("Номер телефона");
    horizontalHeader.append("Группа контакта");
    m_model_contacts->setHorizontalHeaderLabels(horizontalHeader);

    m_model_contacts->setRowCount(ROWLIMIT);
    for (int col = 0; col < 3; ++col)
        for (int row = 0; row < ROWLIMIT; ++row)
            m_model_contacts->setItem(row, col, new QStandardItem());

    ui->tableView->setModel(m_model_contacts);

    m_model_notifications = new QStandardItemModel();

    QStringList horizontalHeader_2;
    horizontalHeader_2.append("Название напоминания");
    horizontalHeader_2.append("Дата");
    horizontalHeader_2.append("Описание");
    horizontalHeader_2.append("Группа напоминания");
    horizontalHeader_2.append("Контакт к которому относится");
    m_model_notifications->setHorizontalHeaderLabels(horizontalHeader_2);

    m_model_notifications->setRowCount(ROWLIMIT);
    for (int col = 0; col < 5; ++col)
        for (int row = 0; row < ROWLIMIT; ++row)
            m_model_notifications->setItem(row, col, new QStandardItem());

    ui->tableView_2->setModel(m_model_notifications);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();

    dataManager->getDataFromFile(phonebook_->getContactList(), phonebook_->getNotificationList());
}

void MainWindow::update()
{
    int row_contact = 0;
    int row_notification = 0;

    for (Contact &contract : phonebook_->getContactList()) {
        m_model_contacts->item(row_contact, 0)->setText(QString(contract.getContactFullName().c_str()));
        m_model_contacts->item(row_contact, 1)->setText(QString(contract.getContactPhoneNumber().c_str()));
        m_model_contacts->item(row_contact,2)->setText(QString(contract.getContactGroupStringRepresentance().c_str()));
        ++row_contact;

        if (row_contact == ROWLIMIT)
            return;
    }

    while (row_contact < ROWLIMIT) {
        m_model_contacts->item(row_contact, 0)->clearData();
        m_model_contacts->item(row_contact, 1)->clearData();
        m_model_contacts->item(row_contact, 2)->clearData();
        ++row_contact;
    }

    for (Notification &notification : phonebook_->getNotificationList()) {
        m_model_notifications->item(row_notification, 0)->setText(QString(notification.getNameNotification().c_str()));
        m_model_notifications->item(row_notification, 1)->setText(notification.getDateNotification().toString("yyyy-MM-dd") + " " +notification.getDateNotification().toString("hh:mm"));
        m_model_notifications->item(row_notification,2)->setText(QString(notification.getDetailsNotification().c_str()));
        m_model_notifications->item(row_notification,3)->setText(QString(notification.getNotificationGroupStringRepresentance().c_str()));
        m_model_notifications->item(row_notification,4)->setText(QString(notification.getRelatedContactNotificationStringRepresentance().c_str()));
        ++row_notification;

        if (row_notification == ROWLIMIT)
            return;
    }

    while (row_notification < ROWLIMIT) {
        m_model_notifications->item(row_notification, 0)->clearData();
        m_model_notifications->item(row_notification, 1)->clearData();
        m_model_notifications->item(row_notification, 2)->clearData();
        m_model_notifications->item(row_notification, 3)->clearData();
        m_model_notifications->item(row_notification, 4)->clearData();
        ++row_notification;
    }
}

void MainWindow::on_AddContactButton_clicked()
{
    createContactWindow_->show();
}
void MainWindow::on_AddNotificationButton_clicked()
{
    createNotificationWindow_->show();
}

void MainWindow::on_DeleteContactButton_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    if (!selectionModel->hasSelection())
        return;

    QModelIndexList selectedRows = selectionModel->selectedRows();
    std::vector< std::string> stringsForRemoving;
    for (const auto &model_contact : selectedRows)
        if (static_cast<uint>(model_contact.row()) < phonebook_->getContactList().size())
            stringsForRemoving.push_back(phonebook_->getContactList()[model_contact.row()].getContactPhoneNumber());

    for (const auto &string : stringsForRemoving) {
        phonebook_->deleteContact(string);
        logger_->saveToFile("Deleted contact with phone number : " + QString(string.c_str()), 5);
    }
}
void MainWindow::on_DeleteNotificationButton_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView_2->selectionModel();
    if (!selectionModel->hasSelection())
        return;

    QModelIndexList selectedRows = selectionModel->selectedRows();
    std::vector< std::string> stringsForRemoving;
    for (const auto &model : selectedRows)
        if (static_cast<uint>(model.row()) < phonebook_->getNotificationList().size())
            stringsForRemoving.push_back(phonebook_->getNotificationList()[model.row()].getNameNotification());

    for (const auto &string : stringsForRemoving) {
        phonebook_->deleteNotification(string);
        logger_->saveToFile("Deleted notification with name : " + QString(string.c_str()), 5);
    }
}

MainWindow::~MainWindow()
{
    dataManager->saveDataToFile('\n',*phonebook_);
    delete ui;
    delete logger_;
    delete phonebook_;
    delete createContactWindow_;
    delete createNotificationWindow_;
}


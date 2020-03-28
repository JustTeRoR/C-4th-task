#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <createcontact.h>
#include <createnotification.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    createContact createContactWindow;
    createNotification createNotificationWindow;
};
#endif // MAINWINDOW_H

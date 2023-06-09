#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void closeSlot();
    void close();

private slots:
    void on_lock_clicked();

    void on_shutdown_clicked();

    void on_logout_clicked();

    void on_reboot_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

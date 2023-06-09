#include "dialog.h"
#include "./ui_dialog.h"
#include "exec.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::on_lock_clicked() {
    ::exec(3);
}


void Dialog::on_shutdown_clicked() {
    ::exec(0);
}


void Dialog::on_logout_clicked() {
    ::exec(2);
}


void Dialog::on_reboot_clicked()
{
    ::exec(1);
}


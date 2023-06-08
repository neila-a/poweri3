#include "dialog.h"
#include "./ui_dialog.h"
#include <stdlib.h>
#include "readConfig.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lock_clicked()
{
    system(readConfig(3));
}


void Dialog::on_shutdown_clicked()
{
    system(readConfig(0));
}


void Dialog::on_logout_clicked()
{
    system(readConfig(2));
}


void Dialog::on_reboot_clicked()
{
    system(readConfig(1));
}


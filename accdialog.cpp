#include "accdialog.h"
#include "ui_accdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

accdialog::accdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accdialog)
{
    ui->setupUi(this);

    ui->nameLabel->setText(ownerName);
    ui->balanceLabel->setText(balance);
    ui->accNoLabel->setText(accnumber);
}

accdialog::~accdialog()
{
    delete ui;
}

void accdialog::setText()
{
    ui->balanceLabel->setText(balance);
    ui->nameLabel->setText(ownerName);
    ui->accNoLabel->setText(accnumber);
}

void accdialog::on_depositPB_clicked()
{
    //adds the deposited amount to the form

    //open database




    //execute query
    QString depositQuery;

    depositQuery = "SELECT    ";
}

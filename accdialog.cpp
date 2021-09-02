#include "accdialog.h"
#include "ui_accdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
accdialog::accdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accdialog)
{
    ui->setupUi(this);

    ui->nameLabel->setText(ownerName);
    ui->balanceLabel->setText(balance);
    ui->accNoLabel->setText(accnumber);

    db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("C:/apple/db.sqlite");

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
    if(!db1.open()){
        qDebug() << "Database NOT opened successfully";
    }

    else
        qDebug() << "Database opened successfully";



    //execute query
    QString depositQuery = "UPDATE Accounts SET Balance = Balance + ? WHERE ID = ?;";

    QSqlQuery dQuery;
    dQuery.prepare(depositQuery);
    dQuery.addBindValue(ui->amountLE->text());
    dQuery.addBindValue(accnumber);
    dQuery.exec();

    db1.close();
}

void accdialog::on_withdrawPB_clicked()
{
    if(!db1.open()){
        qDebug() << "Database NOT opened successfully";
    }

    else
        qDebug() << "Database opened successfully";


    QString withQuery = "UPDATE Accounts SET Balance = Balance - ? WHERE ID = ?;";

    QSqlQuery wQuery;
    wQuery.prepare(withQuery);
    wQuery.addBindValue(ui->amountLE->text());
    wQuery.addBindValue(accnumber);
    wQuery.exec();

    db1.close();
}

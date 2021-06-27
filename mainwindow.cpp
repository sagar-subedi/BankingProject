#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inside.h"
#include "ui_inside.h"
#include "accdialog.h"
#include "ui_accdialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/apple/db.sqlite");


    //link to the database file



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_signUpPB_clicked()
{
    QString accNo = ui->accountNoLE->text();
    QString password1,password2;
    password1 = ui->password1LE->text();
    password2 = ui->confirmPasswordLE->text();

    //now let's query the Accounts database of the accNo


    if(password1==password2)

    {


        if(!db.open()){
            qDebug() << "Database NOT opened successfully";
        }

        else
            qDebug() << "Database opened successfully";


        QString qryString = "SELECT ID FROM Accounts WHERE ID=";
        qryString.append(accNo);
        QSqlQuery query(qryString);

        //query.first();
        while(query.next())
        {
            QString name = query.value(0).toString();
            qDebug() << name;

            //now lets make arrangements for insertion;
             qryString = "INSERT INTO Users(ID, password) VALUES"
                         "(?,?) ";
             query.prepare(qryString);
             query.addBindValue(accNo);
             query.addBindValue(password1);
             query.exec();



        }
        db.close();
    }




}

void MainWindow::on_signInPB_clicked()
{
    //now I need match the entered password with the entered
    //password of the database
    QString useridEnt = ui->userIDLE->text();
    QString passEnt = ui->passwordLE->text();

    //new I need ot retrieve the password for the entered ID

    QSqlQuery passQuery;
    QString passQueryString("SELECT password, ID FROM Users WHERE UserID =");
    passQueryString.append(useridEnt);
    qDebug() << passQueryString;
    db.open();
    passQuery.exec(passQueryString);
    passQuery.next();


    bool signIn = (passQuery.value(0).toString() == passEnt);
    if(signIn){

        QString dataQueryString("SELECT ID, Name, Balance FROM Accounts WHERE ID=");
        QString accNumber = passQuery.value(1).toString();
        dataQueryString.append(accNumber);

        //now find out required information and assign to required variable
        QSqlQuery dataQuery(dataQueryString);
        dataQuery.exec();
        dataQuery.next();








    accdialog signedin(this);
    signedin.ownerName = dataQuery.value(1).toString();
    signedin.balance = dataQuery.value(2).toString();
    signedin.accnumber = dataQuery.value(0).toString();
    qDebug() << signedin.balance << signedin.ownerName;

    signedin.setText();
    signedin.exec();




    db.close();
    }

}

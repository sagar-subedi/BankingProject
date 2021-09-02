#ifndef ACCDIALOG_H
#define ACCDIALOG_H

#include <QDialog>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QtSql>

namespace Ui {
class accdialog;
}

class accdialog : public QDialog
{
    Q_OBJECT

public:
    explicit accdialog(QWidget *parent = nullptr);
    ~accdialog();
    QString accnumber;
    QString ownerName;
    QString balance;
    void setText();
    QSqlDatabase db1;

private slots:
    void on_depositPB_clicked();

    void on_withdrawPB_clicked();

private:
    Ui::accdialog *ui;
};

#endif // ACCDIALOG_H

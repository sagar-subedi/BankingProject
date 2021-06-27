#ifndef ACCDIALOG_H
#define ACCDIALOG_H

#include <QDialog>

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


private slots:
    void on_depositPB_clicked();

private:
    Ui::accdialog *ui;
};

#endif // ACCDIALOG_H

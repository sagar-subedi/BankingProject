#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QtSql>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlDatabase db;



private slots:
    void on_signUpPB_clicked();

    void on_signInPB_clicked();

    void on_createPB_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#include "inside.h"
#include "ui_inside.h"

inside::inside(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inside)
{
    ui->setupUi(this);
}

inside::~inside()
{
    delete ui;
}

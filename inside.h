#ifndef INSIDE_H
#define INSIDE_H

#include <QWidget>

namespace Ui {
class inside;
}

class inside : public QWidget
{
    Q_OBJECT

public:
    explicit inside(QWidget *parent = nullptr);
    ~inside();

private:
    Ui::inside *ui;
};

#endif // INSIDE_H

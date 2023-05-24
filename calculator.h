#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class Calculator : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *mFirstVal;
    QLineEdit *mSecVal;
    QLabel *mResultLabel;
//    const QString result = "Your result is: ";
    const int operationType;

public:
    explicit Calculator(QWidget *parent = nullptr, int type = 0);
    void calculate();

signals:

};

#endif // CALCULATOR_H

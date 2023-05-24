#include "calculator.h"
#include <QGridLayout>
#include <QValidator>
#include <QPushButton>

Calculator::Calculator(QWidget *parent, int type)
    : QWidget{parent}, operationType(type)
{
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(20);



    QLabel *operationLabel= new QLabel(this);
    operationLabel->setAlignment(Qt::AlignHCenter);
    QLabel *firstNumLabel= new QLabel("Enter frist value", this);
    firstNumLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *secondNumLabel= new QLabel("Enter second value", this);
    secondNumLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    mResultLabel = new QLabel(this);
    mResultLabel->setAlignment(Qt::AlignBottom);

    mFirstVal = new QLineEdit(this);
    mFirstVal->setValidator( new QDoubleValidator(this)); //Разобраться с double
    mSecVal = new QLineEdit(this);
    mSecVal->setValidator( new QDoubleValidator(this));

    QPushButton *calcButton = new QPushButton("Calculate", this);

    if (operationType == 0){
        operationLabel->setText("Addition calculator");
    } else {
        operationLabel->setText("Multiplication calculator");
    }

    grid->addWidget(operationLabel, 0, 0, -1, 0);
    grid->addWidget(firstNumLabel, 1 , 0);
    grid->addWidget(mFirstVal, 1, 1);
    grid->addWidget(secondNumLabel, 2, 0);
    grid->addWidget(mSecVal, 2 , 1);
    grid->addWidget(calcButton, 3, 0, -1, 0);
    grid->addWidget(mResultLabel, 4, 0, -1, 0);

    connect(calcButton, &QPushButton::clicked, this, &Calculator::calculate);

    setLayout(grid);
}

void Calculator::calculate()
{
    QString x = mFirstVal->text().replace(",", ".");
    QString y = mSecVal->text().replace(",", ".");
    double result;

    if (operationType == 0) {
       result = x.toDouble() + y.toDouble();
    }

    mResultLabel->setText("Your result is " + QString::number(result));
//    qDebug() << QString::number(result);
}

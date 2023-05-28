#include "calculator.h"
#include "filedirector.h"

#include <QGridLayout>
#include <QValidator>
#include <QPushButton>
#include <QMessageBox>

Calculator::Calculator(QWidget *parent, int type)
    : QWidget{parent}, operationType(type)
{
    QGridLayout *mainLayout = new QGridLayout(this);

    QLabel *operationLabel= new QLabel(this);
    operationLabel->setAlignment(Qt::AlignHCenter);
    QLabel *firstNumLabel= new QLabel("Enter frist value", this);
    firstNumLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *secondNumLabel= new QLabel("Enter second value", this);
    secondNumLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    mResultLabel = new QLabel(this);
    mResultLabel->setAlignment(Qt::AlignCenter);

    mFirstVal = new QLineEdit(this);
    mFirstVal->setValidator( new QDoubleValidator(this));
    mSecVal = new QLineEdit(this);
    mSecVal->setValidator( new QDoubleValidator(this));

    QPushButton *calcButton = new QPushButton("Calculate", this);

    if (operationType == 0){
        operationLabel->setText("Addition calculator");
    } else {
        operationLabel->setText("Multiplication calculator");
    }

    mainLayout->addWidget(operationLabel, 0, 0, -1, 0);
    mainLayout->addWidget(firstNumLabel, 1 , 0);
    mainLayout->addWidget(mFirstVal, 1, 1);
    mainLayout->addWidget(secondNumLabel, 2, 0);
    mainLayout->addWidget(mSecVal, 2 , 1);
    mainLayout->addWidget(calcButton, 3, 0, -1, 0, Qt::AlignTop);
    mainLayout->addWidget(mResultLabel, 4, 0, -1, 0);

    mainLayout->setRowMinimumHeight(0, 30);
    mainLayout->setRowMinimumHeight(1, 30);
    mainLayout->setRowMinimumHeight(2, 30);
    mainLayout->setRowMinimumHeight(3, 30);
    mainLayout->setRowMinimumHeight(4, 30);

    connect(calcButton, &QPushButton::clicked, this, &Calculator::calculate);

    setLayout(mainLayout);
}

void Calculator::calculate()
{
    if(!(mFirstVal->text().isEmpty()) && !(mSecVal->text().isEmpty())){

        QString x = mFirstVal->text().replace(",", ".");
        QString y = mSecVal->text().replace(",", ".");
        QString toHistoryStr;
        QString resultStr;
        double resultVal;

        if (operationType == 0) {
            resultVal = x.toDouble() + y.toDouble();
            toHistoryStr = mFirstVal->text() + " + " + mSecVal->text();
        } else {
            toHistoryStr = mFirstVal->text() + " * " + mSecVal->text();
            resultVal = x.toDouble() * y.toDouble();
        }

        resultStr = QString::number(resultVal).replace(".", ",");
        toHistoryStr.append(" = " + resultStr);
        mResultLabel->setText("Your result is " + resultStr);

        FileDirector::saveHistroy(&toHistoryStr);
    } else {
        QMessageBox *info = new QMessageBox();
        info->setText("Please fill both numbers");
        info->exec();
    }

}

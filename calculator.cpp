#include "calculator.h"
#include "filedirector.h"

#include <QGridLayout>
#include <QValidator>
#include <QPushButton>
#include <QMessageBox>

Calculator::Calculator(QWidget *parent, int type)
    : QWidget{parent}, operationType(type)
{
    QGridLayout *grid = new QGridLayout(this);
    //grid->setSpacing(20);


    QLabel *operationLabel= new QLabel(this);
    operationLabel->setAlignment(Qt::AlignHCenter);
    QLabel *firstNumLabel= new QLabel("Enter frist value", this);
    firstNumLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *secondNumLabel= new QLabel("Enter second value", this);
    secondNumLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    mResultLabel = new QLabel(this);
    mResultLabel->setAlignment(Qt::AlignCenter);

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
    grid->addWidget(calcButton, 3, 0, -1, 0, Qt::AlignTop);
    grid->addWidget(mResultLabel, 4, 0, -1, 0);

    grid->setRowMinimumHeight(0, 30);
    grid->setRowMinimumHeight(1, 30);
    grid->setRowMinimumHeight(2, 30);
    grid->setRowMinimumHeight(3, 30);
    grid->setRowMinimumHeight(4, 30);

    connect(calcButton, &QPushButton::clicked, this, &Calculator::calculate);

    setLayout(grid);
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
    //    qDebug() << toHistoryStr;

    } else {
        QMessageBox *info = new QMessageBox();
        info->setText("Please fill both numbers");
        info->exec();
    }

}

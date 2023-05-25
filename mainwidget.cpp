#include "mainwidget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>

void MainWidget::setMode(int mode)
{
    switch (mode) {
    case 0:
        goBack->hide();
        stackedWidget->setCurrentIndex(mode);
        break;
    case 1:
        goBack->show();
        stackedWidget->setCurrentIndex(mode);
        break;
    case 2:
        goBack->show();
        stackedWidget->setCurrentIndex(mode);
        break;

    case 3:
        goBack->show();
        break;
    default:
        break;
    }
}

void MainWidget::drawWidgets()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    stackedWidget = new QStackedWidget(this);
    goBack = new QPushButton("< Return to main menu", this);
    menu = new MainMenu;
    addOper = new Calculator(nullptr, ADD);
    multiplyOper = new Calculator (nullptr, MULTIPLY);

    stackedWidget->addWidget(menu);
    stackedWidget->addWidget(addOper);
    stackedWidget->addWidget(multiplyOper);

    mainLayout->addWidget(stackedWidget, 0 , Qt::AlignCenter);
    mainLayout->addWidget(goBack, 0, Qt::AlignBottom | Qt::AlignLeft);
}

MainWidget::MainWidget(QWidget *parent, int mode)
    : QWidget(parent)
{
     //Реализовать connect

    drawWidgets();
    setMode(mode);

    connect(goBack, &QPushButton::clicked, this, [this]{setMode(0);});
    connect(menu->getAddBttn(), &QPushButton::clicked, this, [this]{setMode(1);});
    connect(menu->getMltplyBttn(), &QPushButton::clicked, this, [this]{setMode(2);});
    connect(menu->getHistoryBttn(), &QPushButton::clicked, this, [this]{setMode(3);});
}

MainWidget::~MainWidget()
{
}


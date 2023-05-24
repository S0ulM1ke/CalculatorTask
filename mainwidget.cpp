#include "mainwidget.h"
#include "mainmenu.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>

void MainWidget::setMode(int mode)
{
    if (currWidgetPtr != nullptr){
        currWidgetPtr->hide();
    }

    switch (mode) {
    case 0:
        currWidgetPtr = menu;
        goBack->hide();
        menu->show();
        break;
    case 1:
        goBack->show();
        break;
    case 2:
        goBack->show();
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
    QVBoxLayout *backButtonLayout = new QVBoxLayout;
    QVBoxLayout *menuLayout = new QVBoxLayout;


    mainLayout->addLayout(backButtonLayout);
    mainLayout->addLayout(menuLayout);

    menu = new MainMenu(this);
    goBack = new QPushButton("< Return to main menu", this);

    backButtonLayout->addWidget(goBack, 0, Qt::AlignBottom | Qt::AlignLeft);
    menuLayout->addWidget(menu, 0, Qt::AlignCenter);
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


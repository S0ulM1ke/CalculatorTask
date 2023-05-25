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
        history->updateHistory();
        stackedWidget->setCurrentIndex(mode);
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
    history = new History;

    stackedWidget->addWidget(menu);
    stackedWidget->addWidget(addOper);
    stackedWidget->addWidget(multiplyOper);
    stackedWidget->addWidget(history);

    mainLayout->addWidget(stackedWidget, 0 , Qt::AlignCenter);
    mainLayout->addWidget(goBack, 0, Qt::AlignBottom | Qt::AlignLeft);
}

MainWidget::MainWidget(QWidget *parent, int mode)
    : QWidget(parent)
{
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


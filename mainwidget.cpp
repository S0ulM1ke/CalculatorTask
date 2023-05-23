#include "mainwidget.h"
#include "mainmenu.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout(this);
    MainMenu *menu = new MainMenu(this);
    menu->show();
    vbox->addWidget(menu, 0, Qt::AlignCenter); //Реализовать connect


//    QVBoxLayout *vbox = new QVBoxLayout(this);
//      vbox->setSpacing(5);

//      QPushButton *quitBtn = new QPushButton("Quit", this);
//      vbox->addWidget(quitBtn, 0, Qt::AlignCenter);

//      connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

MainWidget::~MainWidget()
{
}


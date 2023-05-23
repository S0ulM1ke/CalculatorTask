#include "mainmenu.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QLabel>

MainMenu::MainMenu(QWidget *parent)
    : QWidget{parent}
{
      QVBoxLayout *vbox = new QVBoxLayout(this);
      vbox->setSpacing(5);

      QLabel *label = new QLabel("Please choose the operation", this);
      QPushButton *quitBtn = new QPushButton("Add", this);
//      QPushButton *multiply = new QPushButton("Multiply", this);
      mMultiply = new QPushButton("Multiply", this);

      vbox->addWidget(label, 0);
      vbox->addWidget(quitBtn, 1);
      vbox->addWidget(mMultiply, 2);

      connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

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
      label->setAlignment(Qt::AlignCenter);
      mAdd = new QPushButton("Add", this);
      mMultiply = new QPushButton("Multiply", this);
      mHistory = new QPushButton("History", this);

      vbox->addWidget(label, 0);
      vbox->addWidget(mAdd, 1);
      vbox->addWidget(mMultiply, 2);
      vbox->addWidget(mHistory, 3);

}

QPushButton *MainMenu::getAddBttn()
{
      return mAdd;
}

QPushButton *MainMenu::getMltplyBttn()
{
      return mMultiply;
}

QPushButton *MainMenu::getHistoryBttn()
{
      return mHistory;
}

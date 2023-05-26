#include "mainmenu.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QLabel>

MainMenu::MainMenu(QWidget *parent)
    : QWidget{parent}
{
      QVBoxLayout *mainLayout = new QVBoxLayout(this);
      mainLayout->setSpacing(5);

      QLabel *label = new QLabel("Please choose the operation", this);
      label->setAlignment(Qt::AlignCenter);
      mAdd = new QPushButton("Add", this);
      mMultiply = new QPushButton("Multiply", this);
      mHistory = new QPushButton("History", this);

      mainLayout->addWidget(label, 0);
      mainLayout->addWidget(mAdd, 1);
      mainLayout->addWidget(mMultiply, 2);
      mainLayout->addWidget(mHistory, 3);

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

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = nullptr);
    QPushButton *mMultiply;

signals:

};

#endif // MAINMENU_H

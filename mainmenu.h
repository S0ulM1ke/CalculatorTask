#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>

class MainMenu : public QWidget
{
    Q_OBJECT
private:
    QPushButton *mAdd;
    QPushButton *mMultiply;
    QPushButton *mHistory;
public:
    explicit MainMenu(QWidget *parent = nullptr);
    QPushButton *getAddBttn();
    QPushButton *getMltplyBttn();
    QPushButton *getHistoryBttn();
};

#endif // MAINMENU_H

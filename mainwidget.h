#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "mainmenu.h"
#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT
private:
    void setMode(int mode);
    void drawWidgets();

    QWidget* currWidgetPtr = nullptr;
    MainMenu* menu;
    QPushButton* goBack;

public:
    MainWidget(QWidget *parent = nullptr, int mode = 0);
    ~MainWidget();
};
#endif // MAINWIDGET_H

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "mainmenu.h"
#include "calculator.h"
#include <QWidget>
#include <QStackedWidget>

class MainWidget : public QWidget
{
    Q_OBJECT
private:
    void setMode(int mode);
    void drawWidgets();

    enum operationType {
        ADD = 0,
        MULTIPLY = 1
    };

    MainMenu* menu;
    QStackedWidget* stackedWidget;
    Calculator* addOper;
    Calculator* multiplyOper;
    QPushButton* goBack;

public:
    MainWidget(QWidget *parent = nullptr, int mode = 0);
    ~MainWidget();
};
#endif // MAINWIDGET_H

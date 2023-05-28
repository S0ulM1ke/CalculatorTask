#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class History : public QWidget
{
    Q_OBJECT
private:
    QLabel *noResults;
    QVBoxLayout *mainLayout;
    QVBoxLayout *resultsLayout;
public:
    explicit History(QWidget *parent = nullptr);
    void updateHistory();
};

#endif // HISTORY_H

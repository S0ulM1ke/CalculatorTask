#include "history.h"
#include "filedirector.h"


History::History(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout;
    resultsLayout = new QVBoxLayout;

    QLabel *title = new QLabel("History of operations", this);
    title->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    noResults = new QLabel("There no operations in history", this);
    noResults->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    mainLayout->addWidget(title);
    mainLayout->addLayout(resultsLayout);
    updateHistory();

    setLayout(mainLayout);
}

void History::updateHistory()
{
    if (!FileDirector::checkHistoryExistance()){
        mainLayout->addWidget(noResults);
        noResults->show();
    } else {
        mainLayout->removeWidget(noResults);
        noResults->hide();

        for (int i = 0; i < resultsLayout->count(); ++i) {
            if (resultsLayout->itemAt(i)->widget()) {
                resultsLayout->itemAt(i)->widget()->deleteLater();
            }
        }

        for (int i = 0; i < FileDirector::getMaxHistorySize(); ++i) {
            QString historyOutput = FileDirector::getHistory(i);
            if (historyOutput != nullptr) {
                QLabel* out = new QLabel(historyOutput, this);

                out->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
                resultsLayout->addWidget(out);
            }

        }
    }
}

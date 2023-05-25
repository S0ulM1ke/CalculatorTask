#include "history.h"
#include "filedirector.h"


History::History(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout;
    resultsLayout = new QVBoxLayout;

    QLabel* title = new QLabel("History of operations", this);
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

        for (int var = 0; var < resultsLayout->count(); ++var) {
            if (resultsLayout->itemAt(var)->widget()) {
                resultsLayout->itemAt(var)->widget()->deleteLater();
            }
        }


        for (int var = 0; var < FileDirector::getMaxHistorySize(); ++var) {
            QString historyOutput = FileDirector::getHistory(var);
            if (historyOutput != nullptr) {
                QLabel* out = new QLabel(historyOutput, this);

                out->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
                resultsLayout->addWidget(out);
            }

        }
    }
}

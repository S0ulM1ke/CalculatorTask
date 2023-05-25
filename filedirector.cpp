#include "filedirector.h"

#include <QDate>

const int FileDirector::maxHistorySize = 5;
QFile FileDirector::historyFile = QDir::toNativeSeparators(QDir::currentPath() + + "/history.ini");
QTextStream FileDirector::out = QTextStream(stdout);
QSettings* FileDirector::historyIni = new QSettings(QDir::currentPath() + "/history.ini", QSettings::IniFormat);

int FileDirector::getMaxHistorySize()
{
    return maxHistorySize;
}

bool FileDirector::saveHistroy(QString *resultExpression)
{
    QDateTime cdt = QDateTime::currentDateTime();

    QString newItem = *(resultExpression) + " | " + cdt.date().toString("d-MMMM-yyyy") + " " + cdt.time().toString();
    QString oldItem;

    if (resultExpression != 0) {
        for (int var = 0; var < maxHistorySize; ++var) {
            if (historyIni->value(QString::number(var)).toString() == nullptr){
                historyIni->setValue(QString::number(var), newItem);
                return true;
            } else {
                oldItem = historyIni->value(QString::number(var)).toString();
                historyIni->setValue(QString::number(var), newItem);
                newItem = oldItem;
            }
        }
        return true;
    } else {
        return false;
    }
}

QString FileDirector::getHistory(int index)
{
    return historyIni->value(QString::number(index)).toString();
}

bool FileDirector::checkHistoryExistance()
{
    return historyFile.exists();
}

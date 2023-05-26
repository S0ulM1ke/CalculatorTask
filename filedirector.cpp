#include "filedirector.h"

#include <QDate>

const int FileDirector::maxHistorySize = 5;
const QString FileDirector::historyDir = QDir::currentPath() + + "/history.ini";
QFile FileDirector::historyFile = historyDir;
QSettings *FileDirector::historyIni = new QSettings(historyDir, QSettings::IniFormat);

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
        for (int i = 0; i < maxHistorySize; ++i) {
            if (historyIni->value(QString::number(i)).toString() == nullptr){
                historyIni->setValue(QString::number(i), newItem);
                return true;
            } else {
                oldItem = historyIni->value(QString::number(i)).toString();
                historyIni->setValue(QString::number(i), newItem);
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

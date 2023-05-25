#include "filedirector.h"

const int FileDirector::maxHistorySize = 5;
QFile FileDirector::historyFile = QDir::toNativeSeparators(QDir::currentPath());
QTextStream FileDirector::out = QTextStream(stdout);
QSettings* FileDirector::historyIni = new QSettings(QDir::currentPath() + "/history.ini", QSettings::IniFormat);

FileDirector::FileDirector()
{
}

void FileDirector::createHistroryFile()
{
//    historyIni->setValue("test", "value");
//    historyIni->sync();





    if (historyFile.open(QIODevice::WriteOnly)) {
        out << "Something" << Qt::endl;
        qDebug() << "Write";
    }
}

bool FileDirector::saveHistroy(QString *resultExpression)
{
    QString *newItem = resultExpression;
    QString oldItem;

    if (historyIni->contains("0")) {
        for (int var = 0; var < maxHistorySize; ++var) {
            if (historyIni->value(QString::number(var)).toString() == nullptr){
                historyIni->setValue(QString::number(var), *(newItem));
                return true;
            } else {
                oldItem = historyIni->value(QString::number(var)).toString();
                historyIni->setValue(QString::number(var), *(newItem));
                newItem = &oldItem;
            }
            //qDebug() << QString::number(var) + *(newItem);

            //qDebug() << *(newItem);
        }
    } else {
        historyIni->setValue(QString::number(0), *(newItem));
    }

    return true;
}

bool FileDirector::checkHistoryExistance()
{
    return historyFile.exists();
}

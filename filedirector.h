#ifndef FILEDIRECTOR_H
#define FILEDIRECTOR_H
#include <QFile>
#include <QDir>
#include <QSettings>


class FileDirector
{
private:
    static const int maxHistorySize;
    static QFile historyFile;
    static QSettings* historyIni;
    static const QString historyDir;
public:
    FileDirector();
    static bool checkHistoryExistance();
    static bool saveHistroy(QString* resultExpression);
    static QString getHistory(int index);
    static int getMaxHistorySize();
};

#endif // FILEDIRECTOR_H

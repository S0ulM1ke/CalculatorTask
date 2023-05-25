#ifndef FILEDIRECTOR_H
#define FILEDIRECTOR_H
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QSettings>


class FileDirector
{
private:
 //   const QString historyFilePath = QDir::toNativeSeparators(QDir::currentPath()) + "\\history.ini";
//    QFile historyFile = QDir::toNativeSeparators(QDir::currentPath()) + "\\history.ini";
    static const int maxHistorySize;
    static QFile historyFile;
//    QTextStream out = QTextStream(stdout);
    static QTextStream out;
    static QSettings* historyIni;
public:
    FileDirector();
    virtual bool checkHistoryExistance() = 0;
    static bool saveHistroy(QString* resultExpression);
    static void createHistroryFile();
};

#endif // FILEDIRECTOR_H

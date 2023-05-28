#include "mainwidget.h"
#include <QApplication>
#include <QtGlobal>
#include <QSettings>
#include <QDir>

#ifdef Q_OS_LINUX
#include <QFile>
#endif

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    int mode = 0;

    if (QCoreApplication::arguments().size() > 1) {
        QString argument = QCoreApplication::arguments().at(1);
        QChar argChar = argument.back();
        if (1 <= argChar.digitValue() && argChar.digitValue() <= 3) {
            mode = argument.back().digitValue();
        }
    }

    const QString path = QDir::toNativeSeparators(qApp->applicationFilePath());
    const QString URLSchemeName = "calc";

#ifdef Q_OS_WIN
    QSettings set("HKEY_CURRENT_USER\\Software\\Classes", QSettings::NativeFormat);    
    set.beginGroup(URLSchemeName);
    set.setValue("Default", "URL:" + URLSchemeName + " Protocol");
    set.setValue("DefaultIcon/Default", path);
    set.setValue("URL Protocol", "");
    set.setValue("shell/open/command/Default", QString("\"%1\"").arg(path) + " \"%1\"");
    set.endGroup();   
#endif

#ifdef Q_OS_LINUX
    const QString appsFolder = "~/.local/share/applications/";
    QSettings set("~/.local/share/applications/", QSettings::IniFormat);
    set.beginGroup("Desktop Entry");
    set.setValue("Name", URLSchemeName);
    set.setValue("Exec", path + " %u");
    set.setValue("Type", "Application");
    set.setValue("Terminal", "true");
    set.setValue("MimeType", "x-scheme-handler/calc");
    set.endGroup();
    QFile schemeFile = appsFolder + URLSchemeName + ".ini";
    schemeFile.rename(appsFolder + URLSchemeName + ".desktop");
#endif

    MainWidget w(nullptr, mode);

    w.resize(450, 300);
    w.show();
    return a.exec();
}

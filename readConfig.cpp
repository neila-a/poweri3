#include "readConfig.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

using namespace std;

const char* readConfig(int line) {
    const char* defaultConfig[4] = {
        "systemctl poweroff",
        "systemctl reboot",
        "i3-msg exit",
        "i3lock"
    };
    /*
     * Shutdown
     * Reboot
     * Logout
     * Lock
    */
    QString configPath(QDir::homePath() + "/.config/poweri3");
    QFile config(configPath);
    if (!config.exists()) {
        qWarning("[poweri3] Config not exists. Now creating.");
        bool isok = config.open(QIODevice::WriteOnly | QIODevice::Text);
        if (isok == true) {
            QTextStream stream(&config);
            stream << QString(defaultConfig[0]) << "\n";
            stream << QString(defaultConfig[1]) << "\n";
            stream << QString(defaultConfig[2]) << "\n";
            stream << QString(defaultConfig[3]) << "\n";
        }
        config.close();
        return defaultConfig[line];
    } else {
        qDebug("[poweri3] Config exists. Now Reading.");
        bool isok = config.open(QIODevice::ReadOnly);
        if(isok == true) {
            QTextStream stream(&config);
            //读取数据时 按照写入的顺序读取
            int id = 0;
            while (!stream.atEnd()) {
                QString lineStr = stream.readLine();
                if (line == id) {
                    QByteArray arrayData = lineStr.toLatin1();
                    const char* charData = arrayData.data();
                    config.close();
                    qDebug("[poweri3] Execute command: %s", charData);
                    return charData;
                }
                id = id + 1;
            }
            config.close();
            return defaultConfig[line];
        } else {
            config.close();
            return defaultConfig[line];
        }
    }
}

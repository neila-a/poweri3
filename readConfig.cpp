#include "readConfig.h"
#include <QFile>
#include <QTextStream>
#include <iostream>

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
    QFile config("~/.config/i3exit");
    if (!config.exists()) {
        cout << "[i3exit] Config not exists. Now creating." << endl;
        bool isok = config.open(QIODevice::WriteOnly);
        if (isok == true) {
            QTextStream stream(&config);
            stream << QString(defaultConfig[0]);
            stream << QString(defaultConfig[1]);
            stream << QString(defaultConfig[2]);
            stream << QString(defaultConfig[3]);
        }
        config.close();
        return defaultConfig[line];
    } else {
        cout << "[i3exit] Config exists. Now Reading." << endl;
        bool isok = config.open(QIODevice::ReadOnly);
        if(isok == true) {
            QTextStream stream(&config);
            //读取数据时 按照写入的顺序读取
            QString data = stream.readLine(line);
            config.close();
            QByteArray latin1 = data.toLatin1();
            const char* charData = latin1.data();
            cout << charData << endl;
            return charData;
        } else {
            config.close();
            return defaultConfig[line];
        }
    }
}

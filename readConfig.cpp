#include "readConfig.h"
#include <string>
#include <iostream>
#include <fstream>
#include <strstream>
#include <vector>

using namespace std;

const char* readConfig(int line) {
    const char* fname = "config";
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

    fstream fs;
    fs.open(fname, ios::in);

    if (!fs) {
        cout << "[i3exit] Config file is not exist. Now create." << endl;

        //创建文件
        ofstream fout(fname);
        if (fout) {
            // 如果创建成功
            fout << defaultConfig[0] << endl;
            fout << defaultConfig[1] << endl;
            fout << defaultConfig[2] << endl;
            fout << defaultConfig[3] << endl;

            // 执行完操作后关闭文件句柄
            fout.close();
            return defaultConfig[line];
        }
    } else {
        cout << "[i3exit] Config file is existing. Now reading." << endl;
        char buff[1024] = { 0 };
        int id = 0;
        while (fs.getline(buff, sizeof(buff))) {
            if (id == line) {
                cout << buff << endl;
                return buff;
            }
        }
    }

    fs.close();
}

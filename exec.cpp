#include "exec.h"
#include "qapplication.h"
#include "readConfig.h"
#include <QDebug>
#include <stdlib.h>

void exec(int line) {
    system(readConfig(line));
    QApplication* app;
    qDebug("[poweri3] The button has been clicked and the program is exiting.");
    app->exit(0);
}

#include "musicApplication.h"
#include "musicWidget.h"

#include <QFile>

int main(int argc, char *argv[])
{
    MusicApplication a(argc, argv);
    if (a.isRunning())
        return 0;

    QFile qss("://resource/qss/style.qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    MusicWidget w;
    w.show();
    w.creatrWinThumbnail();

    return a.exec();
}

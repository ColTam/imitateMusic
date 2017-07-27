#ifndef MUSICAPPLICATION_H
#define MUSICAPPLICATION_H

#include <QApplication>
#include <QSharedMemory>

class MusicApplication : public QApplication
{
public:
    MusicApplication(int argc, char **argv);
    ~MusicApplication();

public:
    bool isRunning() const;

private:
    bool m_isRun;
    QSharedMemory m_shareMemory;
};

#endif // MUSICAPPLICATION_H

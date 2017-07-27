#include "musicApplication.h"

#include <QMessageBox>

MusicApplication::MusicApplication(int argc, char **argv)
    : QApplication(argc, argv)
    ,m_isRun(0)
{
    m_shareMemory.setKey("JsontMusic");

    if (m_shareMemory.attach()) {
        m_isRun = true;
    } else {
        m_isRun = false;
        if (!m_shareMemory.create(1)) {
            QMessageBox msgBox(QMessageBox::Warning, tr("Error"),
                               tr("Unable to create single instance\nerror: %1").arg(m_shareMemory.errorString()));
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setButtonText(QMessageBox::Ok, tr("ok"));

            msgBox.exec();
        }
    }
}

MusicApplication::~MusicApplication()
{

}

bool MusicApplication::isRunning() const
{
    return m_isRun;
}

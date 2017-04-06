#ifndef _MAIN_H_
#define _MAIN_H_

#include "QLayout"
#include <QSpacerItem>
#include <QObject>
#include "QTimer"
#include <QProcess>

#include <qapplication.h>
#include <qmainwindow.h>

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow( QWidget * = NULL );

protected:
    QTimer *timer;

private Q_SLOTS:
    void Set_I8R(void);
};


#endif

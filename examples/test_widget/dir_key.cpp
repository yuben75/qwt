#include "dir_key.h"
#include "arrow_button.h"

QwtDirKey::QwtDirKey ( QWidget *parent, CDATATYPE *pModel ) : QWidget(parent)
{
    int x = 10, y=10, w=40, h=40;


    QwtArrowButton *d_upArrowBotton = new QwtArrowButton( 1, Qt::UpArrow, this, pModel );
    QwtArrowButton *d_downArrowBotton = new QwtArrowButton( 1, Qt::DownArrow, this, pModel );
    QwtArrowButton *d_leftwnArrowBotton = new QwtArrowButton( 1, Qt::LeftArrow, this, NULL );
    QwtArrowButton *d_rightwnArrowBotton = new QwtArrowButton( 1, Qt::RightArrow, this, NULL );

    d_upArrowBotton->setGeometry(50, 10, w, h);
    d_leftwnArrowBotton->setGeometry(10, 50, w, h);
    d_rightwnArrowBotton->setGeometry(90, 50, w, h);
    d_downArrowBotton->setGeometry(50, 90, w, h);

    d_upArrowBotton->setStyleSheet("background-color:pink;");
    d_downArrowBotton->setStyleSheet("background-color:pink;");
    d_leftwnArrowBotton->setStyleSheet("background-color:Orange");
    d_rightwnArrowBotton->setStyleSheet("background-color:Orange;");

}


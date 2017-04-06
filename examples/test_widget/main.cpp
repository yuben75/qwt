#include "main.h"

#include "arrow_button.h"
#include "dir_key.h"


#include <string>
using std::string;
#include "Chr_DataType_I8R.h"
#include <QDebug>


static int cb_test(WM_MESSAGE *pWMMsg)
{
    qDebug("[%s-%i]%x", __FILE__, __LINE__, pWMMsg);

}

static string str[] = {"0", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                            "A", "B", "C", "D", "E", "F", "G", "H", "I", "J" };
static CDATAATTR_RING i8RAttr(0, 20, str);
static I8R i8RPara_1 = 0;
static CDATATYPE_I8R i8rDType_1(&i8RPara_1, &i8RAttr, cb_test);
static I8R i8RPara_2 = 0;
static CDATATYPE_I8R i8rDType_2(&i8RPara_2, &i8RAttr);




//======================================================================================
//
//======================================================================================
void MainWindow::Set_I8R(void)
{
    I8R val = 6;
    i8rDType_1.set_val(&val);


    i8rDType_2.set_val("15");
    timer->start(2000);
    qDebug("[%s-%i]", __FILE__, __LINE__);

}


MainWindow::MainWindow( QWidget *parent ):

    QMainWindow( parent )
{


    {   //example 1
        int x = 10, y=10, w=100, h=20;
        QWidget *window = new QWidget(this);

        QPushButton *button1 = new QPushButton("One", window);
        QPushButton *button2 = new QPushButton("Two", window);
        QwtArrowButton *d_upArrowBotton = new QwtArrowButton( 2, Qt::UpArrow, window );
        QwtArrowButton *d_downArrowBotton = new QwtArrowButton( 2, Qt::DownArrow, window );
        QwtArrowButton *d_leftArrowBotton = new QwtArrowButton( 1, Qt::LeftArrow, window );
        QwtArrowButton *d_rightArrowBotton = new QwtArrowButton( 3, Qt::RightArrow, window );


        button1->setGeometry(x, y, w, h); y += h+5;
        button2->setGeometry(x, y, w, h); y += h+5;
        d_upArrowBotton->setGeometry(x, y, w, h); y += h+5;
        d_downArrowBotton->setGeometry(x, y, w, h); y += h+5;
        d_leftArrowBotton->setGeometry(x, y, w, h); y += h+5;
        d_rightArrowBotton->setGeometry(x, y, w, h); y += h+5;



        y += h+5; y += h+5; y += h+5;
        #if 1
        {
            QwtArrowButton *d_numberArrowBotton = new QwtArrowButton( 3, Qt::RightArrow, window, &i8rDType_1);
            d_numberArrowBotton->setGeometry(x, y, w, h); y += h+5;
            i8rDType_1.set_val("3");
        }
        {

            QwtArrowButton *d_numberArrowBotton = new QwtArrowButton( 3, Qt::LeftArrow, window, &i8rDType_2);
            d_numberArrowBotton->setGeometry(x, y, w, h); y += h+5;
            i8rDType_2.set_val("13");

        }
        #endif

        window->setGeometry( 0, 0, 160, 800 );
    }
#if 1
    {   //example 2
        QWidget *window = new QWidget(this);
        QPushButton *button1 = new QPushButton("One");
        QPushButton *button2 = new QPushButton("Two");
        QPushButton *button3 = new QPushButton("Three");
        QPushButton *button4 = new QPushButton("Four");
        QPushButton *button5 = new QPushButton("Five");

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->addWidget(button4);
        layout->addWidget(button5);

        QPalette pal = palette();
        pal.setColor(QPalette::Background, Qt::blue);
        window->setAutoFillBackground(true);
        window->setPalette(pal);


        window->setGeometry( 200, 0, 100, 800 );
        window->setLayout(layout);
    }

    {   //example 3
        QWidget *window = new QWidget(this);
        QPushButton *button1 = new QPushButton("One");
        QPushButton *button2 = new QPushButton("Two");
        QPushButton *button3 = new QPushButton("Three");
        QPushButton *button4 = new QPushButton("Four");
        QPushButton *button5 = new QPushButton("Five");
        QwtArrowButton *d_upArrowBotton = new QwtArrowButton( 2, Qt::UpArrow, window );
        QwtArrowButton *d_downArrowBotton = new QwtArrowButton( 2, Qt::DownArrow, window );
        QwtArrowButton *d_leftwnArrowBotton = new QwtArrowButton( 1, Qt::LeftArrow, window );
        QwtArrowButton *d_rightwnArrowBotton = new QwtArrowButton( 3, Qt::RightArrow, window );

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->addWidget(button4);
        layout->addWidget(button5);
        layout->addWidget(d_upArrowBotton);
        layout->addWidget(d_downArrowBotton);
        layout->addWidget(d_leftwnArrowBotton);
        layout->addWidget(d_rightwnArrowBotton);

        layout->addItem(new QSpacerItem(0,10, QSizePolicy::Expanding, QSizePolicy::Expanding));


        window->setGeometry( 300, 0, 100, 800 );
        window->setLayout(layout);
    }

    {   //example 4
        QWidget *window = new QWidget(this);
        QPushButton *button1 = new QPushButton("One");
        QPushButton *button2 = new QPushButton("Two");
        QPushButton *button3 = new QPushButton("Three");
        QPushButton *button4 = new QPushButton("Four");
        QPushButton *button5 = new QPushButton("Five");
        QwtArrowButton *d_upArrowBotton = new QwtArrowButton( 2, Qt::UpArrow, window );
        QwtArrowButton *d_downArrowBotton = new QwtArrowButton( 2, Qt::DownArrow, window );
        QwtArrowButton *d_leftwnArrowBotton = new QwtArrowButton( 1, Qt::LeftArrow, window );
        QwtArrowButton *d_rightwnArrowBotton = new QwtArrowButton( 5, Qt::RightArrow, window );

        d_upArrowBotton->setMinimumSize(60, 20);
        d_upArrowBotton->setMaximumSize(100, 20);
        d_downArrowBotton->setMinimumSize(60, 20);
        d_downArrowBotton->setMaximumSize(100, 20);
        d_leftwnArrowBotton->setMinimumSize(60, 20);
        d_leftwnArrowBotton->setMaximumSize(100, 20);
        d_rightwnArrowBotton->setMinimumSize(60, 20);
        d_rightwnArrowBotton->setMaximumSize(100, 20);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->addWidget(button4);
        layout->addWidget(button5);
        layout->addWidget(d_upArrowBotton);
        layout->addWidget(d_downArrowBotton);
        layout->addWidget(d_leftwnArrowBotton);
        layout->addWidget(d_rightwnArrowBotton);


        layout->addItem(new QSpacerItem(0,10, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));

        window->setGeometry( 400, 0, 100, 800 );
        window->setLayout(layout);
    }

    {   //example 5
        QWidget *window = new QWidget(this);
        QPushButton *button1 = new QPushButton("One");
        QPushButton *button2 = new QPushButton("Two");
        QPushButton *button3 = new QPushButton("Three");
        QPushButton *button4 = new QPushButton("Four");
        QPushButton *button5 = new QPushButton("Five");
        QwtArrowButton *d_upArrowBotton = new QwtArrowButton( 1, Qt::UpArrow, window );
        QwtArrowButton *d_downArrowBotton = new QwtArrowButton( 1, Qt::DownArrow, window );
        QwtArrowButton *d_leftwnArrowBotton = new QwtArrowButton( 2, Qt::LeftArrow, window );
        QwtArrowButton *d_rightwnArrowBotton = new QwtArrowButton( 2, Qt::RightArrow, window );


        d_upArrowBotton->setMinimumSize(60, 20);
        d_upArrowBotton->setMaximumSize(100, 30);
        d_downArrowBotton->setMinimumSize(60, 20);
        d_downArrowBotton->setMaximumSize(100, 30);
        d_leftwnArrowBotton->setMinimumSize(60, 20);
        d_leftwnArrowBotton->setMaximumSize(100, 20);
        d_rightwnArrowBotton->setMinimumSize(60, 20);
        d_rightwnArrowBotton->setMaximumSize(100, 20);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->addWidget(button4);
        layout->addWidget(button5);
        layout->addWidget(d_leftwnArrowBotton);
        layout->addWidget(d_rightwnArrowBotton);
        layout->addWidget(d_upArrowBotton);
        layout->addWidget(d_downArrowBotton);

        layout->addItem(new QSpacerItem(0,10, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));


        window->setGeometry( 500, 0, 100, 800 );
        window->setLayout(layout);
    }


    {   //example 6
        QWidget *window = new QWidget(this);
        {
            int x = 10, y=10, w=40, h=40;

            QwtArrowButton *d_upArrowBotton = new QwtArrowButton( 2, Qt::UpArrow, window );
            QwtArrowButton *d_downArrowBotton = new QwtArrowButton( 2, Qt::DownArrow, window );
            QwtArrowButton *d_leftwnArrowBotton = new QwtArrowButton( 2, Qt::LeftArrow, window );
            QwtArrowButton *d_rightwnArrowBotton = new QwtArrowButton( 2, Qt::RightArrow, window );

            d_upArrowBotton->setGeometry(50, 10, w, h);
            d_leftwnArrowBotton->setGeometry(10, 50, w, h);
            d_rightwnArrowBotton->setGeometry(90, 50, w, h);
            d_downArrowBotton->setGeometry(50, 90, w, h);


            d_upArrowBotton->setStyleSheet("background-color:red;");
            d_downArrowBotton->setStyleSheet("background-color:red;");
            d_leftwnArrowBotton->setStyleSheet("background-color:blue;");
            d_rightwnArrowBotton->setStyleSheet("background-color:blue; border-width: 3px; border-color: darkkhaki; border-style: solid; border-radius: 5; padding: 3px; min-width: 4ex; min-height: 2.5ex;");
            window->setGeometry( 600, 0, 160, 800 );
        }
        {
            QwtDirKey *dirKey_1= new QwtDirKey(window);
            dirKey_1->setGeometry( 0, 200, 140, 140 );

            QwtDirKey *dirKey_2= new QwtDirKey(window, &i8rDType_2);
            dirKey_2->setGeometry( 0, 400, 140, 140 );
        }
    }
#endif
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Set_I8R()), Qt::DirectConnection);
    timer->start(2000);

}

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    MainWindow mainWindow;

    mainWindow.resize( 800, 800 );
    mainWindow.show();

    return a.exec();
}

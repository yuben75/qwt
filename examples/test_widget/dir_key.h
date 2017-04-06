#ifndef QWTDIRKEY_H
#define QWTDIRKEY_H

#include "qwt_global.h"
#include "QWidget"
#include "Chr_DataType.h"

class QwtDirKey : public QWidget
{
public:
       explicit QwtDirKey ( QWidget *parent = NULL, CDATATYPE *pModel= NULL );

};

#endif

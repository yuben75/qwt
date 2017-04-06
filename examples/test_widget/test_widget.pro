################################################################
# Qwt Widget Library
# Copyright (C) 1997   Josef Wilgen
# Copyright (C) 2002   Uwe Rathmann
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the Qwt License, Version 1.0
################################################################

include( $${PWD}/../examples.pri )

TARGET   = test_widget

message("TARGET=" $$TARGET)

INCLUDEPATH += \
    QDataType \
    N:\sdk\qwt\src

SOURCES = \
    arrow_button.cpp \
    QDataType/Chr_DataAttr.cpp \
    QDataType/Chr_DataAttr_Num.cpp \
    QDataType/Chr_DataAttr_Ring.cpp \
    QDataType/Chr_DataAttr_Float.cpp \
    QDataType/Chr_DataAttr_IP.cpp \
    QDataType/Chr_DataType.cpp \
    QDataType/Chr_DataType_I8.cpp \
    QDataType/Chr_DataType_U8.cpp \
    QDataType/Chr_DataType_I8R.cpp \
    QDataType/Chr_DataType_U16.cpp \
    QDataType/Chr_DataType_I32.cpp \
    QDataType/Chr_DataType_F32.cpp \
    QDataType/Chr_DataType_IP.cpp \
    dir_key.cpp \
    main.cpp

HEADERS = \
    arrow_button.h \
    QDataType/Def_Type.h \
    QDataType/Chr_DataAttr.h \
    QDataType/Chr_DataAttr_Num.h \
    QDataType/Chr_DataAttr_Ring.h \
    QDataType/Chr_DataAttr_Float.h \
    QDataType/Chr_DataAttr_IP.h \
    QDataType/Chr_DataType.h \
    QDataType/Chr_DataType_I8.h \
    QDataType/Chr_DataType_U8.h \
    QDataType/Chr_DataType_I8R.h \
    QDataType/Chr_DataType_U16.h \
    QDataType/Chr_DataType_I32.h \
    QDataType/Chr_DataType_F32.h \
    QDataType/Chr_DataType_IP.h \
    dir_key.h \
    main.h



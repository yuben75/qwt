#ifndef  CHR_DATATYPE_I8_H
#define  CHR_DATATYPE_I8_H

#include "Chr_DataType_I32.h"
#include "Chr_DataAttr_Num.h"

class CDATATYPE_I8 : public CDATATYPE_I32{
	typedef CDATATYPE_I8 ThisClass;
public:
	CDATATYPE_I8(I8 *pData, CDATAATTR *p_DAttr=0, FP_DATATYPE fp_DType=0);

public:

	virtual int Can_Set(I32 *pData);
	virtual int set_val(I32 *pData);
	virtual int Can_Set(char *pData);
	virtual int set_val(char *pData);
	//===================================================
	virtual int Init_KeyStr(char *p, int size);
	virtual int gain_valStr(char *p, int size);
};


extern void test_CDATATYPE_I8(void);

#endif

#ifndef  CHR_DATATYPE_U8_H
#define  CHR_DATATYPE_U8_H

#include "Chr_DataType_I32.h"
#include "Chr_DataAttr_Num.h"

class CDATATYPE_U8 : public CDATATYPE_I32{
	typedef CDATATYPE_U8 ThisClass;
public:
	CDATATYPE_U8(U8 *pData, CDATAATTR *p_DAttr=0, FP_DATATYPE fp_DType=0);

public:

	virtual int Can_Set(I32 *pData);
	virtual int set_val(I32 *pData);
	virtual int Can_Set(char *pData);
	virtual int set_val(char *pData);

		//===================================================
	virtual int Init_KeyStr(char *p, int size);
	virtual int gain_valStr(char *p, int size);
};


extern void test_CDATATYPE_U8(void);

#endif

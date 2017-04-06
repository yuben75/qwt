#ifndef  CHR_DATATYPE_U16_H
#define  CHR_DATATYPE_U168_H

#include "Chr_DataType_I32.h"
#include "Chr_DataAttr_Num.h"

class CDATATYPE_U16 : public CDATATYPE_I32{
	typedef CDATATYPE_U16 ThisClass;
public:
	CDATATYPE_U16(U16 *pData, CDATAATTR *p_DAttr=0, FP_DATATYPE fp_DType=0);

public:

	virtual int Can_Set(U16 *pData);
	virtual int set_val(U16 *pData);
	virtual int Can_Set(char *pData);
	virtual int set_val(char *pData);

		//===================================================
	virtual int Init_KeyStr(char *p, int size);
	virtual int gain_valStr(char *p, int size);
};


extern void test_CDATATYPE_U16(void);

#endif

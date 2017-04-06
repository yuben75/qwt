#ifndef  CHR_DATATYPE_F32_H
#define  CHR_DATATYPE_F32_H

#include "Chr_DataType.h"
#include "Chr_DataAttr_Float.h"

class CDATATYPE_F32 : public CDATATYPE{
	typedef CDATATYPE_F32 ThisClass;
public:
	CDATATYPE_F32(F32 *pData, CDATAATTR *p_DAttr=0, FP_DATATYPE fp_DType=0);

public:

	virtual int Can_Set(F32 *pData);
	virtual int set_val(F32 *pData);
	virtual int Can_Set(char *pData);
	virtual int set_val(char *pData);

	//===================================================
	virtual int Init_KeyStr(char *p, int size);
	virtual int KinStr_To_EditStr(char *pSrc, char *p, int size);
	virtual int KinStr_Inc(char *p, int size, I8 idx=0);
	virtual int KinStr_Dec(char *p, int size, I8 idx=0);
	//===================================================
	virtual int IsValidKey(int key, int pressedCnt=1);
	virtual int Get_InfoStr(char *p, int size);
	#if (SCPI_EN==1)
		virtual U8 scpi_set_val(struct tagPROGDATA *_pProgData, int &DataIdx, int DataCnt=1);
		//virtual int scpi_get_val(char *p, struct tagPROGDATA *_pProgData, int &DataIdx, int DataCnt=1);
	#endif
	virtual int gain_valStr(char *p, int size);
	virtual int gain_val(void *pData=NULL);
private:
	F32 tmp;
};


extern void test_CDATATYPE_F32(void);

#endif

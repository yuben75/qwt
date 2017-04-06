#ifndef  CHR_DATATYPE_I32_H
#define  CHR_DATATYPE_I32_H


#include "Chr_DataType.h"
#include "Chr_DataAttr_Num.h"


class CDATATYPE_I32 : public CDATATYPE{
	typedef CDATATYPE_I32 ThisClass;
public:
	CDATATYPE_I32(I32 *pData, CDATAATTR *p_DAttr=0, FP_DATATYPE fp_DType=0);
	CDATATYPE_I32(void *pData, CDATAATTR *p_DAttr, FP_DATATYPE fp_DType, int mem_Size = 1);
public:

	virtual int Can_Set(I32 *pData);
	virtual int set_val(I32 *pData);
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
	#endif
	virtual int gain_valStr(char *p, int size);
	virtual int gain_val(void *pData=NULL);

protected:
    int AddDotPoint(char *p, int size, I32 value, I8 APrecision, I8 AWidth=0);

private:
	I32 tmp;

};



extern void test_CDATATYPE_I32(void);


#endif

#ifndef  CHR_DATATYPE_I8R_H
#define  CHR_DATATYPE_I8R_H

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "Def_Type.h"
#include "Chr_DataType.h"
#include "Chr_DataAttr_Ring.h"


class CDATATYPE_I8R : public CDATATYPE{
	typedef CDATATYPE_I8R ThisClass;
public:
	CDATATYPE_I8R(I8R *pData, CDATAATTR *p_DAttr=0, FP_DATATYPE fp_DType=0);

public:

	virtual int Can_Set(I8R *pData);
	virtual int set_val(I8R *pData);
	virtual int Can_Set(char *pData);
	virtual int set_val(char *pData);
	virtual int gain_valStr(char *p, int size);
	virtual int gain_val(void *pData=NULL);
	virtual void set_IncVal(I8 idx=0, char KeyinStr[]="");
	virtual void set_DecVal(I8 idx=0, char KeyinStr[]="");
	virtual I8R gain_valStrAll(vector <string> &svec, char KeyinStr[]=NULL);

	//===================================================
	virtual int Init_KeyStr(char *p, int size);
	virtual int KinStr_To_EditStr(char *pSrc, char *p, int size);
	virtual int KinStr_Inc(char *p, int size, I8 idx=0);
	virtual int KinStr_Dec(char *p, int size, I8 idx=0);
	virtual int RingStr_To_NumStr(char *pSrc, char *p, int size);
	virtual int NumStr_To_RingStr(char *pSrc, char *p, int size);
	//===================================================
	virtual int IsInvalidKey(int key, int pressedCnt=1);

	#if (SCPI_EN==1)
		virtual U8 scpi_set_val(struct tagPROGDATA *_pProgData, int &DataIdx, int DataCnt=1);
		virtual int scpi_get_val(char *p, struct tagPROGDATA *pProgData, int &DataIdx, int DataCnt=1, int ResponsesMode=0);
		virtual int ScpiDataType_To_NumStr(int ScpiDataType, char *p, int size);

	#endif
private:
	I8R tmp;
};

extern void test_CDATATYPE_I8R(void);

#endif
















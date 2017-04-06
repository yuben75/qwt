#ifndef  CHR_DATATYPE_IP_H
#define  CHR_DATATYPE_IP_H

#include "Chr_DataType.h"
#include "Chr_DataAttr_Num.h"

class CDATATYPE_IP : public CDATATYPE{
	typedef CDATATYPE_IP ThisClass;
public:
public:
	CDATATYPE_IP(IP4 *pData, CDATAATTR *p_DAttr=0, FP_DATATYPE fp_DType=0);
public:



	//===================================================



	virtual int Can_Set(IP_X *pData);
	virtual int set_val(IP_X *pData);
	virtual int Can_Set(char *pData);
	virtual int set_val(char *pData);
	virtual int gain_valStr(char *p, int size);
	virtual int gain_val(void *pData=NULL);
	//virtual void set_IncVal(I8 idx=0, char KeyinStr[]="");
	//virtual void set_DecVal(I8 idx=0, char KeyinStr[]="");

	//===================================================
	virtual int Init_KeyStr(char *p, int size);
	virtual int KinStr_To_EditStr(char *pSrc, char *p, int size);
	virtual int KinStr_Inc(char *p, int size, I8 idx=0);
	virtual int KinStr_Dec(char *p, int size, I8 idx=0);
	//===================================================
	virtual int IsValidKey(int key, int pressedCnt=1);
	virtual int Get_InfoStr(char *p, int size);

private:
	IP4 tmp;
};


#endif

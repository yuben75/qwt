#ifndef  CHR_DATAATTR_H
#define  CHR_DATAATTR_H

#include "Def_Type.h"


typedef int (*FP_CAN_SET)(WM_MESSAGE *pWMMsg);

typedef int (*FP_CAN_SET_NUM)(I32 _val);
typedef int (*FP_CAN_SET_I8R)(I8R _val);
typedef int (*FP_CAN_SET_FLOAT)(F32 _val);
typedef int (*FP_CAN_SET_IP)(IP_X _val);

class CDATAATTR {
	typedef CDATAATTR ThisClass;
public:
	CDATAATTR(void);
	void Set_Callback(FP_CAN_SET _cb);
	FP_CAN_SET m_cb;

public:
	void SetFP_Can_Set(FP_CAN_SET_NUM _fp);
	void SetFP_Can_Set(FP_CAN_SET_I8R _fp);
	void SetFP_Can_Set(FP_CAN_SET_FLOAT _fp);
	void SetFP_Can_Set(FP_CAN_SET_IP _fp);
	virtual int Can_Set(I8R _val);
	virtual int Can_Set(I32 _val);
	virtual int Can_Set(F32 _val);
	virtual int Can_Set(IP_X _val);
	virtual char *gain_Str(int idx=0);
	virtual void MoveLeft_Digit(I8 &_dig, char *s);
	virtual void MoveRight_Digit(I8 &_dig, char *s);
public:
	I8 Get_MaxChar(void);
	I8 m_MaxChar;
};


#endif


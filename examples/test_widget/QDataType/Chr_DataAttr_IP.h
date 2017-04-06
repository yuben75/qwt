#ifndef  CHR_DATAATTR_IP_H
#define  CHR_DATAATTR_IP_H

#include <string>
#include <vector>
using std::string;
using std::vector;
#include "Chr_DataAttr.h"




class CDATAATTR_IP : public CDATAATTR{
	typedef CDATAATTR_IP ThisClass;
public:
	CDATAATTR_IP(I32 _min=0, I32 _max=255, I8 _MaxChar = 3);
	void SetFP_Can_Set(FP_CAN_SET_IP _fp);
	virtual int Can_Set(IP_X _val);
	virtual I32 Get_Max(void);
	virtual I32 Get_Min(void);
public:
	I32 m_Max, m_Min;
	FP_CAN_SET_IP fp_Can_Set;
};



#endif


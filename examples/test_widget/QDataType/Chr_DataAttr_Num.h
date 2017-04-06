#ifndef  CHR_DATAATTR_NUM_H
#define  CHR_DATAATTR_NUM_H

#include <string>
#include <vector>
using std::string;
using std::vector;
#include "Chr_DataAttr.h"


class CDATAATTR_NUM : public CDATAATTR{
	typedef CDATAATTR_NUM ThisClass;
public:
	CDATAATTR_NUM(I32 _min, I32 _max, I8 _MaxChar = 7, I8 _NumDecs = 0);
	void SetFP_Can_Set(FP_CAN_SET_NUM _fp);
	virtual int Can_Set(I32 _val);
	virtual I32 Get_Max(void);
	virtual I32 Get_Min(void);
public:
	I32 m_Max, m_Min;
	I8 m_NumDecs;              /* Number of decimals */
	FP_CAN_SET_NUM fp_Can_Set;
};



#endif


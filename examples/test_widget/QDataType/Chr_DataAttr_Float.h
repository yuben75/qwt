#ifndef  CHR_DATAATTR_FLOAT_H
#define  CHR_DATAATTR_FLOAT_H

#include <string>
#include <vector>
using std::string;
using std::vector;
#include "Chr_DataAttr.h"


class CDATAATTR_FLOAT : public CDATAATTR{
	typedef CDATAATTR_FLOAT ThisClass;
public:
	CDATAATTR_FLOAT(F32 _min, F32 _max, I8 _NumDecs = 0, I8 _MaxChar = 7);
	void SetFP_Can_Set(FP_CAN_SET_FLOAT _fp);
	virtual int Can_Set(F32 _val);
	virtual void MoveLeft_Digit(I8 &_gig, char *s);
	virtual void MoveRight_Digit(I8 &_gig, char *s);
    void SetSpecification(F32 _min, F32 _max, I8 _NumDecs = 0, I8 _MaxChar = 7);

public:
	F32 m_Max, m_Min;
	I8 m_NumDecs;              /* Number of decimals */
	FP_CAN_SET_FLOAT fp_Can_Set;
};



#endif


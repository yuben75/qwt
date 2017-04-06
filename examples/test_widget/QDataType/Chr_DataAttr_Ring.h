#ifndef  CHR_DATAATTR_RING_H
#define  CHR_DATAATTR_RING_H

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "Chr_DataAttr_Num.h"

#include "Config.h"
#if (SCPI_EN==1)
	#include "Scpiopt.h"
	#include "mSCPI.h"
#endif

class CDATAATTR_RING : public CDATAATTR_NUM
{
	typedef CDATAATTR_RING ThisClass;
public:
	CDATAATTR_RING(I32 _min, I32 _max, string str[]=NULL);
#if (SCPI_EN==1)
	CDATAATTR_RING(I32 _min, I32 _max, string str[], int *pScpiRing);
	virtual int ScpiDataType_To_NumStr(int ScpiDataType, char *p, int size);
#endif
	void SetFP_Can_Set(FP_CAN_SET_I8R _fp);
	virtual int Can_Set(I8R _val);
	virtual char *gain_Str(int idx);
	vector <string> Get_svec(void);
	virtual int RingStr_To_NumStr(string str, char *p, int size);

protected:
	vector <string> m_svec;
	vector <U8> 	m_en;
#if (SCPI_EN==1)
	vector <int>	m_scpi_ring;
#endif
	FP_CAN_SET_I8R fp_Can_Set;
};


#endif

#include "Chr_DataAttr_IP.h"



CDATAATTR_IP::CDATAATTR_IP(I32 _min, I32 _max, I8 _MaxChar) : CDATAATTR()
{
	m_Max = _max;
	m_Min = _min;
	m_MaxChar = _MaxChar;
	fp_Can_Set = (FP_CAN_SET_IP)NULL;
}
void CDATAATTR_IP::SetFP_Can_Set(FP_CAN_SET_IP _fp)
{
	fp_Can_Set = _fp;
}
int CDATAATTR_IP::Can_Set(IP_X _val)
{
	if (fp_Can_Set != NULL)
		return fp_Can_Set(_val);
	WM_MESSAGE Msg = {0};
    //Msg.Data.p = &_val;
	if (m_cb){
		return m_cb(&Msg);
	}

	if ( (_val.v[0] >= m_Min &&  _val.v[0] <= m_Max) &&
		 (_val.v[1] >= m_Min &&  _val.v[1] <= m_Max) &&
		 (_val.v[2] >= m_Min &&  _val.v[2] <= m_Max) &&
		 (_val.v[3] >= m_Min &&  _val.v[3] <= m_Max) ){
		return 1;
	}
	return 0;
}
I32 CDATAATTR_IP::Get_Max(void)
{
	return m_Max;
}
I32 CDATAATTR_IP::Get_Min(void)
{
	return m_Min;
}


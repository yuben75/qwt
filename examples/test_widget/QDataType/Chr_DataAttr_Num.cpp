#include "Chr_DataAttr_Num.h"



CDATAATTR_NUM::CDATAATTR_NUM(I32 _min, I32 _max, I8 _MaxChar, I8 _NumDecs) : CDATAATTR()
{
	m_Max = _max;
	m_Min = _min;
    m_NumDecs = _NumDecs;
	m_MaxChar = _MaxChar;
	fp_Can_Set = (FP_CAN_SET_NUM)NULL;
}
void CDATAATTR_NUM::SetFP_Can_Set(FP_CAN_SET_NUM _fp)
{
	fp_Can_Set = _fp;
}
int CDATAATTR_NUM::Can_Set(I32 _val)
{
	if (fp_Can_Set != NULL)
		return fp_Can_Set(_val);
	WM_MESSAGE Msg = {0};
    Msg.Data.v = _val;
	if (m_cb){
		return m_cb(&Msg);
	}

	if (_val >= m_Min &&  _val <= m_Max)
		return 1;

	return 0;
}
I32 CDATAATTR_NUM::Get_Max(void)
{
	return m_Max;
}
I32 CDATAATTR_NUM::Get_Min(void)
{
	return m_Min;
}


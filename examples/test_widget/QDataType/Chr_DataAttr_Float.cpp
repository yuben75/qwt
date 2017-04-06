#include "Chr_DataAttr_Float.h"



CDATAATTR_FLOAT::CDATAATTR_FLOAT(F32 _min, F32 _max, I8 _NumDecs, I8 _MaxChar) : CDATAATTR()
{
	m_Max = _max;
	m_Min = _min;
	m_NumDecs = _NumDecs;
	m_MaxChar = _MaxChar;
	#if _UCGUI_398
	fp_Can_Set = (FP_CAN_SET_FLOAT)0;
	#else
	fp_Can_Set = (FP_CAN_SET_FLOAT)NULL;
	#endif
}
void CDATAATTR_FLOAT::SetFP_Can_Set(FP_CAN_SET_FLOAT _fp)
{
	fp_Can_Set = _fp;
}
int CDATAATTR_FLOAT::Can_Set(F32 _val)
{
	if (fp_Can_Set != NULL)
		return fp_Can_Set(_val);
	WM_MESSAGE Msg = {0};
    //Msg.Data.p = &_val;
	if (m_cb){
		return m_cb(&Msg);
	}
	if (_val >= m_Min &&  _val <= m_Max){
		//debug
        //PlayMusic(SOUND_NUM_LIMIT);
		return 1;
    }

	return 0;
}

void CDATAATTR_FLOAT::MoveLeft_Digit(I8 &_dig, char *s)
{
	if (_dig <= 1 )
		return;
	_dig--;
	if (s[_dig-1] == '.')
		_dig--;
}
void CDATAATTR_FLOAT::MoveRight_Digit(I8 &_dig, char *s)
{
	if (_dig >= m_MaxChar )
		return;
	_dig++;
	if (s[_dig-1] == '.')
		_dig++;
}
void CDATAATTR_FLOAT::SetSpecification(F32 _min, F32 _max, I8 _NumDecs, I8 _MaxChar)
{
	m_Max = _max;
	m_Min = _min;
	m_NumDecs = _NumDecs;
	m_MaxChar = _MaxChar;
}

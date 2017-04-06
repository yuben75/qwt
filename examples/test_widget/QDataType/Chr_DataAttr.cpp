#include "Chr_DataAttr.h"



CDATAATTR::CDATAATTR(void)
{
	m_MaxChar = 0;
}


void CDATAATTR::Set_Callback(FP_CAN_SET _cb)
{
	m_cb = _cb;
}


int CDATAATTR::Can_Set(I8R _val)
{
	return 0;
}

int CDATAATTR::Can_Set(I32 _val)
{
	return 0;
}

int CDATAATTR::Can_Set(F32 _val)
{
	return 0;
}

int CDATAATTR::Can_Set(IP_X _val)
{

	return 0;
}

char *CDATAATTR::gain_Str(int idx)
{
	return "";
}

I8 CDATAATTR::Get_MaxChar(void)
{
	return m_MaxChar;
}

void CDATAATTR::MoveLeft_Digit(I8 &_dig, char *s)
{
	if (_dig <= 1 )
		return;
	_dig--;
}
void CDATAATTR::MoveRight_Digit(I8 &_dig, char *s)
{
	if (_dig >= m_MaxChar )
		return;
	_dig++;
}

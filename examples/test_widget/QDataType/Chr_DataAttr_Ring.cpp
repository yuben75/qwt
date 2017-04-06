
#include "Chr_DataAttr_Ring.h"
#include "stdio.h"
#if 0   //debug dikey
#include <algorithm>
#endif

CDATAATTR_RING::CDATAATTR_RING(I32 _min, I32 _max, string str[])
: CDATAATTR_NUM(_min, _max)
{
	int idx = 0;
	int len = _max - _min + 1;
	if (str!=NULL){
		while (idx<len){
			m_svec.push_back(str[idx]);
			if (str[idx] != "")	m_en.push_back(true);
			else				m_en.push_back(false);
			idx++;
		}
	}
}

#if (SCPI_EN==1)
CDATAATTR_RING::CDATAATTR_RING(I32 _min, I32 _max, string str[], int *pScpiRing)
: CDATAATTR_NUM(_min, _max)
{

	int idx = 0;
	int len = _max - _min + 1;
	if (str!=NULL){
		while (idx<len){
			m_svec.push_back(str[idx]);
			if (str[idx] != "")	m_en.push_back(true);
			else				m_en.push_back(false);
			idx++;
		}
	}

	idx=0;
	while (pScpiRing[idx]!=GP__MAX){
		m_scpi_ring.push_back(pScpiRing[idx++]);
	}

}
int CDATAATTR_RING::ScpiDataType_To_NumStr(int ScpiDataType, char *p, int size)
{
	CDATAATTR_RING *_pAttr = dynamic_cast<CDATAATTR_RING *>(this);

	if ( _pAttr ){
		if (ScpiDataType == GP_MAX){
			return snprintf(p, size, "%i", m_Max);
		} else if (ScpiDataType == GP_MIN) {
			return snprintf(p, size, "%i", m_Min);
		}
		for (unsigned int i=0;  i<_pAttr->m_scpi_ring.size(); i++){
			if (ScpiDataType == m_scpi_ring[i]){
				return snprintf(p, size, "%i", i);
			}
		}
	}
	return snprintf(p, size, "");

}
#endif


void CDATAATTR_RING::SetFP_Can_Set(FP_CAN_SET_I8R _fp)
{
	fp_Can_Set = _fp;
}

int CDATAATTR_RING::Can_Set(I8R _val)
{
	if (fp_Can_Set != NULL)
		return fp_Can_Set(_val);
	WM_MESSAGE Msg = {0};
    Msg.Data.v = _val;
	if (m_cb){
		return m_cb(&Msg);
	}
	U8 idx = _val-m_Min;
	if (_val >= m_Min &&  _val <= m_Max){
		if (m_en[idx])
			return 1;
	}
	return 0;
}

char *CDATAATTR_RING::gain_Str(int idx)
{
	CDATAATTR_RING *_pAttr = dynamic_cast<CDATAATTR_RING *>(this);

	if ( _pAttr && idx>=0 && idx<=_pAttr->m_svec.size() ){
		return (char *)_pAttr->m_svec[idx].c_str();
	}
	return "";
}

vector <string> CDATAATTR_RING::Get_svec(void)
{
	return m_svec;
}

int CDATAATTR_RING::RingStr_To_NumStr(string str, char *p, int size)
{
	CDATAATTR_RING *_pAttr = dynamic_cast<CDATAATTR_RING *>(this);

	//transform(s.begin(), s.end(), s.begin(), toupper);
	string s1(str);
#if 0   //debug dikey    
	transform(s1.begin(), s1.end(), s1.begin(), toupper);
	if ( _pAttr ){
		for (unsigned int i=0;  i<_pAttr->m_svec.size(); i++){
			string s2( _pAttr->m_svec[i] );
			transform(s2.begin(), s2.end(), s2.begin(), toupper);
			if (s2 == s1){
				return snprintf(p, size, "%i", i);
			}
		}
	}
#endif    
	return snprintf(p, size, "");
}

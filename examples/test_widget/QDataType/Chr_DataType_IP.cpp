#include "Chr_DataType_I32.h"
#include "Chr_DataType_IP.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


CDATATYPE_IP::CDATATYPE_IP(IP4 *pData, CDATAATTR *p_DAttr, FP_DATATYPE fp_DType)
: CDATATYPE((void *)pData, sizeof(IP4), p_DAttr, fp_DType)
{


}


int CDATATYPE_IP::Can_Set(IP_X *pData)
{
	if (m_pDAttr){
		return m_pDAttr->Can_Set(*pData);
	}
	return 1;
}


int CDATATYPE_IP::set_val(IP_X *pData)
{
	IP4 *pVal = (IP4 *)m_pData;
	WM_MESSAGE Msg = {0};
    //Msg.Data.p = (void *)this;

	if (Can_Set(pData)){
		//memcpy(m_pData, pData, m_memSize);
        //Msg.MsgId = WMCHR_SET_DATA;
		pVal->v[0] = pData->v[0];
		pVal->v[1] = pData->v[1];
		pVal->v[2] = pData->v[2];
		pVal->v[3] = pData->v[3];
        Invalidate();
		if (m_fp_DType){
			m_fp_DType(&Msg);
		}
		return 1;
	}
	return 0;
}

int CDATATYPE_IP::Can_Set(char *p)
{
	IP_X ipx;
	char *str = p;
	ipx.v[0] = atoi(str);
	str = strstr(str, ".");		str++;
	ipx.v[1] = atoi(str);
	str = strstr(str, ".");		str++;
	ipx.v[2] = atoi(str);
	str = strstr(str, ".");		str++;
	ipx.v[3] = atoi(str);
	return Can_Set(&ipx);
}
int CDATATYPE_IP::set_val(char *p)
{
	IP_X ipx;
	char *str = p;
	ipx.v[0] = atoi(str);
	str = strstr(str, ".");		str++;
	ipx.v[1] = atoi(str);
	str = strstr(str, ".");		str++;
	ipx.v[2] = atoi(str);
	str = strstr(str, ".");		str++;
	ipx.v[3] = atoi(str);
	return set_val(&ipx);
}

int CDATATYPE_IP::gain_valStr(char *p, int size)
{
	IP4 _IP = *(IP4 *)m_pData;
	return snprintf (p, size, "%03u.%03u.%03u.%03u", _IP.v[0], _IP.v[1], _IP.v[2], _IP.v[3] );

}
int CDATATYPE_IP::gain_val(void *pData)
{
	if (pData)
		pData = m_pData;
	return 1;
}

//===================================================
int CDATATYPE_IP::Init_KeyStr(char *p, int size)
{
	tmp = *(IP4 *)m_pData;
	return snprintf (p, size, "%03u.%03u.%03u.%03u", tmp.v[0], tmp.v[1], tmp.v[2], tmp.v[3] );
}
//
int CDATATYPE_IP::KinStr_To_EditStr(char *pSrc, char *p, int size)
{

	#if 0
	//sscanf((char *)pSrc ,"%u.%u.%u.%u", &tmp.v[0], &tmp.v[1], &tmp.v[2], &tmp.v[3]);
	char *str = pSrc;
	tmp.v[0] = atoi(str);
	str = strstr(str, ".");		str++;
	tmp.v[1] = atoi(str);
	str = strstr(str, ".");		str++;
	tmp.v[2] = atoi(str);
	str = strstr(str, ".");		str++;
	tmp.v[3] = atoi(str);
	return snprintf (p, size, "%03u.%03u.%03u.%03u", tmp.v[0], tmp.v[1], tmp.v[2], tmp.v[3] );
	#else

	int ip1, ip2, ip3, ip4;
	char *str = pSrc;
	ip1 = atoi(str);
	str = strstr(str, ".");		str++;
	ip2 = atoi(str);
	str = strstr(str, ".");		str++;
	ip3 = atoi(str);
	str = strstr(str, ".");		str++;
	ip4 = atoi(str);
	return snprintf (p, size, "%03u.%03u.%03u.%03u", ip1, ip2, ip3, ip4 );

	#endif


}
int CDATATYPE_IP::KinStr_Inc(char *p, int size, I8 idx)
{
	sscanf((char *)p ,"%0i", &tmp.v[idx]);
	if (tmp.v[idx] < 255)
		tmp.v[idx]++;

	return snprintf (p, size, "%03u.%03u.%03u.%03u", tmp.v[0], tmp.v[1], tmp.v[2], tmp.v[3] );
}
int CDATATYPE_IP::KinStr_Dec(char *p, int size, I8 idx)
{
	sscanf((char *)p ,"%0i", &tmp.v[idx]);
	if (tmp.v[idx] != 0)
		tmp.v[idx]--;

	return snprintf (p, size, "%03u.%03u.%03u.%03u", tmp.v[0], tmp.v[1], tmp.v[2], tmp.v[3] );
}
//===================================================
int CDATATYPE_IP::IsValidKey(int key, int pressedCnt)
{
    switch (key) {
        //case GUI_KEY_ENTER:
    		return 1;
        //case GUI_KEY_UP:
        //case GUI_KEY_DOWN:
        //case GUI_KEY_LEFT:
        //case GUI_KEY_RIGHT:
    		return 1;
    	case '0':
    	case '1':
    	case '2':
    	case '3':
    	case '4':
    	case '5':
    	case '6':
    	case '7':
    	case '8':
    	case '9':
    		return 1;
    }
	return 0;
}


int CDATATYPE_IP::Get_InfoStr(char *p, int size)
{
	return snprintf(p, size, "000 - 255");
}











//===================================================









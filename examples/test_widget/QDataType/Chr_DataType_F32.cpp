#include "Chr_DataType_F32.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#if (SCPI_EN==1)
	#include "Scpiopt.h"
	#include "mSCPI.h"
#endif
#if (CHR_GUI_EN==1)
    //#include "Gui.h"
#endif

CDATATYPE_F32::CDATATYPE_F32(F32 *pData, CDATAATTR *p_DAttr, FP_DATATYPE fp_DType)
: CDATATYPE((void *)pData, sizeof(F32), p_DAttr, fp_DType)
{


}

int CDATATYPE_F32::Can_Set(F32 *pData)
{
	if (m_pDAttr){
		return m_pDAttr->Can_Set(*pData);
	}
	return 1;
}


int CDATATYPE_F32::set_val(F32 *pData)
{
	WM_MESSAGE Msg = {0};
    //Msg.Data.p = (void *)this;
	if (Can_Set(pData)){
        //Msg.MsgId = WMCHR_SET_DATA;
		//memcpy(m_pData, pData, m_memSize);
		*(F32 *)m_pData = *pData;
        Invalidate();
		if (m_fp_DType){
			m_fp_DType(&Msg);
		}
		return 1;
	}
	return 0;
}

int CDATATYPE_F32::Can_Set(char *p)
{
	F32 val;
	sscanf((char *)p ,"%f", &val);

	return Can_Set(&val);
}
int CDATATYPE_F32::set_val(char *p)
{
	CDATAATTR_FLOAT *pAttr = dynamic_cast<CDATAATTR_FLOAT *>(m_pDAttr);
	F32 val;

	if (pAttr){
		char *s = strchr(p, '.');
		if (s){
			s+=(1+pAttr->m_NumDecs);
			if ( s < p+strlen(p) )
				*s = '\0';
		}
		sscanf((char *)p ,"%f", &val);
	}
	else
		sscanf((char *)p ,"%f", &val);
	return set_val(&val);
}

#if (SCPI_EN==1)
U8 CDATATYPE_F32::scpi_set_val(struct tagPROGDATA *_pProgData, int &DataIdx, int DataCnt)
{
	tagPROGDATA *pProgData = _pProgData;
	pProgData+=DataIdx++;


	if (pProgData->byDataType == GP_MAX){

	} else if (pProgData->byDataType == GP_MIN){

	} else if (pProgData->byDataType != NR1 && pProgData->byDataType != NR2 && pProgData->byDataType != NRF){
		return IB_FAIL;
	}
	if ( !set_val( (char *)pProgData->byBuffer ) ){
		PutErrMsg(MSG_DATA_OUT_RANGE);
		return IB_FAIL;
	}

	return IB_SUCCESS;
}

#endif

int CDATATYPE_F32::gain_valStr(char *p, int size)
{
	CDATAATTR_FLOAT *pAttr = dynamic_cast<CDATAATTR_FLOAT *>(m_pDAttr);

	if (pAttr)
		return snprintf (p, size, "%.*f", pAttr->m_NumDecs, *(F32 *)m_pData  );
	return snprintf (p, size, "%.*f", 3, *(F32 *)m_pData  );
}
int CDATATYPE_F32::gain_val(void *pData)
{
	if (pData)
		pData = m_pData;
	return 1;
}
//===================================================
int CDATATYPE_F32::Init_KeyStr(char *p, int size)
{
	CDATAATTR_FLOAT *pAttr = dynamic_cast<CDATAATTR_FLOAT *>(m_pDAttr);
	if (pAttr)
		return snprintf (p, size, "%0*.*f", pAttr->m_MaxChar, pAttr->m_NumDecs, *(F32 *)m_pData  );
	return snprintf (p, size, "%.*f", 3, *(F32 *)m_pData  );
}
int CDATATYPE_F32::KinStr_To_EditStr(char *pSrc, char *p, int size)
{
	return snprintf (p, size, "%s", pSrc  );
}
int CDATATYPE_F32::KinStr_Inc(char *p, int size, I8 idx)
{
	I8 n = 0;
	char *s = strchr(p, '.');
	if (s){
		n = s - (p+idx);
		if (n<0) n++;
	} else {
		int len = strlen(p);
		n = (p+len) - (p+idx);
	}
	//CHRUI_Err1("CDATATYPE_F32::KinStr_Inc", n);
	F32 _val = pow(10, F32(n));
	sscanf((char *)p ,"%f", &tmp);

	CDATAATTR_FLOAT *pAttr = dynamic_cast<CDATAATTR_FLOAT *>(m_pDAttr);
	if (pAttr){
		tmp += _val;
		if ( !Can_Set(&tmp) ) tmp = pAttr->m_Max;
		return snprintf (p, size, "%0*.*f", pAttr->Get_MaxChar(), pAttr->m_NumDecs, tmp  );
	}
	return 0;
}
int CDATATYPE_F32::KinStr_Dec(char *p, int size, I8 idx)
{
	I8 n = 0;
	char *s = strchr(p, '.');
	if (s){
		n = s - (p+idx);
		if (n<0) n++;
	} else {
		int len = strlen(p);
		n = (p+len) - (p+idx);
	}
	//CHRUI_Err1("CDATATYPE_F32::KinStr_Dec", n);
	F32 _val = pow(10, F32(n));
	sscanf((char *)p ,"%f", &tmp);
	CDATAATTR_FLOAT *pAttr = dynamic_cast<CDATAATTR_FLOAT *>(m_pDAttr);

	if (pAttr){
		tmp -= _val;
		if ( !Can_Set(&tmp) ) tmp = pAttr->m_Min;
		return snprintf (p, size, "%0*.*f", pAttr->Get_MaxChar(), pAttr->m_NumDecs, tmp  );
	}
	return 0;
}
//===================================================
int CDATATYPE_F32::IsValidKey(int key, int pressedCnt)
{
    switch (key) {
        //case GUI_KEY_ENTER:
    		return 1;
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
    	case '.':
    		return 1;
    }
	return 0;
}
int CDATATYPE_F32::Get_InfoStr(char *p, int size)
{
	CDATAATTR_FLOAT *pAttr = dynamic_cast<CDATAATTR_FLOAT *>(m_pDAttr);
	if (pAttr)
		return snprintf(p, size, "%.*f - %.*f", pAttr->m_NumDecs, pAttr->m_Min, pAttr->m_NumDecs, pAttr->m_Max );
	return 0;
}
/*********************************************************************
*
*
*
**********************************************************************/
#include "Chr_DataType_U8.h"
#include "Chr_DataType_I8.h"
#include "Chr_DataType_I8R.h"
#include "Chr_DataType_I32.h"


static I8R i8RPara = 1;
static string str[] = {"A123", "B0", "C99"};
static CDATAATTR_RING i8RAttr(0, 2, str);
static CDATATYPE_I8R i8rDType(&i8RPara, &i8RAttr);


static I32 i32Para = 1;
static CDATAATTR_NUM i32Attr(1, 10);
static CDATATYPE_I32 i32DType(&i32Para, &i32Attr);


static F32 f32Para = (F32)1.23;
static CDATAATTR_FLOAT f32Attr(1.0, 10.0, 2);
static CDATATYPE_F32 f32DType(&f32Para, &f32Attr);
void test_CDATATYPE_F32(void)
{
	f32DType.set_val("5.02");
	f32DType.set_val("11");
	f32DType.set_val("2.34");


	CDATATYPE *p_DType;

	p_DType = &i8rDType;
	p_DType->set_val("2");
	p_DType->set_val("11");
	p_DType->set_val("0");

	p_DType = &i32DType;
	p_DType->set_val("9");
	p_DType->set_val("11");
	p_DType->set_val("2");

	p_DType = &f32DType;
	p_DType->set_val("3.88");
	p_DType->set_val("11");
	p_DType->set_val("2.15");

}


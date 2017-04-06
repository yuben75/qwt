#include "Chr_DataType_I8R.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#if (SCPI_EN==1)
	#include "Scpiopt.h"
	#include "mSCPI.h"
#endif


CDATATYPE_I8R::CDATATYPE_I8R(I8R *pData, CDATAATTR *p_DAttr, FP_DATATYPE fp_DType)
: CDATATYPE((void *)pData, sizeof(I8R), p_DAttr, fp_DType)
{


}

int CDATATYPE_I8R::Can_Set(I8R *pData)
{
	if (m_pDAttr){
		return m_pDAttr->Can_Set(*pData);
	}
	return 1;
}


int CDATATYPE_I8R::set_val(I8R *pData)
{
	WM_MESSAGE Msg = {0};
    //Msg.Data.p = (void *)this;
	if (Can_Set(pData)){
		//memcpy(m_pData, pData, m_memSize);
        //Msg.MsgId = WMCHR_SET_DATA;
		*(I8R *)m_pData = *pData;
        Invalidate();
		if (m_fp_DType){
			m_fp_DType(&Msg);
		}
		return 1;
	}
	return 0;
}

int CDATATYPE_I8R::Can_Set(char *p)
{
	sscanf((char *)p ,"%i", &tmp);
	return Can_Set(&tmp);
}
int CDATATYPE_I8R::set_val(char *p)
{
	sscanf((char *)p ,"%i", &tmp);
	return set_val(&tmp);
}

int CDATATYPE_I8R::gain_valStr(char *p, int size)
{
	int idx = *(I8R *)m_pData;
	return snprintf (p, size, "%s", m_pDAttr->gain_Str(idx)  );
}
int CDATATYPE_I8R::gain_val(void *pData)
{
	if (pData)
		pData = m_pData;
	return *(I8R *)m_pData;
}
void CDATATYPE_I8R::set_IncVal(I8 idx, char KeyinStr[])
{
	I8R Val = *(I8R *)m_pData;
	Val++;
	set_val(&Val);
}
void CDATATYPE_I8R::set_DecVal(I8 idx, char KeyinStr[])
{
	I8R Val = *(I8R *)m_pData;
	Val--;
	set_val(&Val);
}




#if (SCPI_EN==1)
U8 CDATATYPE_I8R::scpi_set_val(struct tagPROGDATA *_pProgData, int &DataIdx, int DataCnt)
{
	tagPROGDATA *pProgData = _pProgData;
	pProgData+=DataIdx++;

	if (pProgData->byDataType == NR1){
		if ( !set_val( (char *)pProgData->byBuffer ) ){
			PutErrMsg(MSG_DATA_OUT_RANGE);
			return IB_FAIL;
		}
	} else {
		if (!m_pDAttr)
			return IB_FAIL;

		char numStr[16];
		#if 0
		RingStr_To_NumStr((char *)pProgData->byBuffer, numStr, sizeof(numStr));
		#else
		ScpiDataType_To_NumStr(pProgData->byDataType, numStr, sizeof(numStr));
		#endif

		if ( !set_val( numStr ) ){
			PutErrMsg(MSG_DATA_OUT_RANGE);
			return IB_FAIL;
		}

	}

	return IB_SUCCESS;
}

int CDATATYPE_I8R::scpi_get_val(char *p, struct tagPROGDATA *_pProgData, int &DataIdx, int DataCnt, int ResponsesMode)
{
	if (ResponsesMode){
		int idx = *(I8R *)m_pData;
		return snprintf (p, (sizeof(g_pExecOutBuf) - g_u16ExecOutCnt), "%i", idx );
	}

	return gain_valStr( p, (sizeof(g_pExecOutBuf) - g_u16ExecOutCnt) );
}

int CDATATYPE_I8R::ScpiDataType_To_NumStr(int ScpiDataType , char *p, int size)
{
	CDATAATTR_RING *pAttr = dynamic_cast<CDATAATTR_RING *>(m_pDAttr);
	if (pAttr){

		return pAttr->ScpiDataType_To_NumStr(ScpiDataType, p, size);
	}
	return 0;

}

#endif

I8R CDATATYPE_I8R::gain_valStrAll(vector <string> &svec, char KeyinStr[])
{
	//m_pDAttr
	if (m_pDAttr){
		CDATAATTR_RING *pDAttr_Ring = dynamic_cast<CDATAATTR_RING *>(m_pDAttr);
		if (pDAttr_Ring)
			svec = pDAttr_Ring->Get_svec();
	}
	if (KeyinStr == NULL)
		return *(I8R *)m_pData;

	sscanf((char *)KeyinStr ,"%i", &tmp);
	return tmp;
}

//===================================================
int CDATATYPE_I8R::Init_KeyStr(char *p, int size)
{
	return snprintf (p, size, "%i", *(I8R *)m_pData  );
}

int CDATATYPE_I8R::KinStr_To_EditStr(char *pSrc, char *p, int size)
{
	sscanf((char *)pSrc ,"%i", &tmp);
	return snprintf (p, size, "%s", m_pDAttr->gain_Str(tmp)  );
}
int CDATATYPE_I8R::KinStr_Inc(char *p, int size, I8 idx)
{
	sscanf((char *)p ,"%i", &tmp);
	tmp++;
	if (Can_Set(&tmp)){
		return snprintf (p, size, "%i",  tmp );
	}
	return 0;
}
int CDATATYPE_I8R::KinStr_Dec(char *p, int size, I8 idx)
{
	sscanf((char *)p ,"%i", &tmp);
	tmp--;
	if (Can_Set(&tmp)){
		snprintf (p, size, "%i",  tmp );
	}
	return 0;
}
int CDATATYPE_I8R::RingStr_To_NumStr(char *pSrc, char *p, int size)
{
	CDATAATTR_RING *pAttr = dynamic_cast<CDATAATTR_RING *>(m_pDAttr);
	if (pAttr){
		string str(pSrc);
		if (str.size () > 0)  str.resize (str.size () - 1);
		return pAttr->RingStr_To_NumStr(str, p, size);
	}
	return 0;
}
int CDATATYPE_I8R::NumStr_To_RingStr(char *pSrc, char *p, int size)
{
	sscanf((char *)pSrc ,"%i", &tmp);
	return snprintf (p, size, "%s", m_pDAttr->gain_Str(tmp)  );
}



//===================================================
int CDATATYPE_I8R::IsInvalidKey(int key, int pressedCnt)
{
    switch (key) {
        //case GUI_KEY_ENTER:
    		return 0;
        //case GUI_KEY_LEFT:
        //case GUI_KEY_RIGHT:
    		return 0;

    }
	return 1;
}

/*********************************************************************
*
*
*
**********************************************************************/
#include <string>
using std::string;

static I8R i8RPara = 8;
static string str[] = {"A123", "B0", "C99"};
static CDATAATTR_RING i8RAttr(1, 3, str);
static CDATATYPE_I8R i8rDType(&i8RPara, &i8RAttr);

void test_CDATATYPE_I8R(void)
{

	CDATATYPE *p_DType;

	p_DType = &i8rDType;

	p_DType->set_val("0");
	p_DType->set_val("1");
	p_DType->set_val("2");
	p_DType->set_val("3");
	p_DType->set_val("4");


	i8rDType.set_val("2");
	i8rDType.set_val("12");
	i8rDType.set_val("4");
	i8rDType.set_val("1");


}


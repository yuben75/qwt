#include "Chr_DataType_I32.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include <algorithm>
using std::max;

#include <cmath>
using std::pow;

#if (SCPI_EN==1)
	#include "Scpiopt.h"
	#include "mSCPI.h"
#endif
#if (CHR_GUI_EN==1)
    //#include "Gui.h"
#endif

CDATATYPE_I32::CDATATYPE_I32(I32 *pData, CDATAATTR *p_DAttr, FP_DATATYPE fp_DType)
: CDATATYPE((void *)pData, sizeof(I32), p_DAttr, fp_DType)
{


}
CDATATYPE_I32::CDATATYPE_I32(void *pData, CDATAATTR *p_DAttr, FP_DATATYPE fp_DType, int mem_Size)
: CDATATYPE((void *)pData, mem_Size, p_DAttr, fp_DType)
{


}
int CDATATYPE_I32::Can_Set(I32 *pData)
{

	if (m_pDAttr){
		return m_pDAttr->Can_Set(*pData);
	}
	return 1;
}

int CDATATYPE_I32::set_val(I32 *pData)
{
	WM_MESSAGE Msg = {0};
    //Msg.Data.p = (void *)this;
	if (Can_Set(pData)){
        //Msg.MsgId = WMCHR_SET_DATA;
		//memcpy(m_pData, pData, m_memSize);
		*(I32 *)m_pData = *pData;
        Invalidate();
		if (m_fp_DType){
			m_fp_DType(&Msg);
		}
		return 1;
	}
	return 0;
}

int CDATATYPE_I32::Can_Set(char *p)
{
	I32 val;
	val = atoi(p);
	return Can_Set(&val);
}
int CDATATYPE_I32::set_val(char *p)
{
	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);
    I32 val;

	if (pAttr && pAttr->m_NumDecs>0){
		char *s = strchr(p, '.');
		if (s){
			s+=(1+pAttr->m_NumDecs);
			if ( s < p+strlen(p) )
				*s = '\0';
		}
        double dtmp =atof(p);
        dtmp*=pow(10.0, pAttr->m_NumDecs);
        val=(dtmp+0.5);
	}
	else
        val = atoi(p);
	return set_val(&val);
}





#if (SCPI_EN==1)
U8 CDATATYPE_I32::scpi_set_val(struct tagPROGDATA *_pProgData, int &DataIdx, int DataCnt)
{
	tagPROGDATA *pProgData = _pProgData;
	pProgData+=DataIdx++;

	if (pProgData->byDataType == GP_MAX){

	} else if (pProgData->byDataType == GP_MIN){

	} else if (pProgData->byDataType != NR1){
		return IB_FAIL;
	}
	if ( !set_val( (char *)pProgData->byBuffer ) ){
		PutErrMsg(MSG_DATA_OUT_RANGE);
		return IB_FAIL;
	}

	return IB_SUCCESS;
}

#endif

//------------------------------------------------------------------------------
int CDATATYPE_I32::AddDotPoint(char *p, int size, I32 value, I8 APrecision, I8 AWidth)
{
    if (APrecision>0 && size>=(APrecision+2)) {
        int width=max(APrecision+1, AWidth-1);
        int len=snprintf(p, size-1, "%0*i",width, value);
        p[len+1]='\0';
        for (int i=0; i<APrecision; i++) p[len-i]=p[len-i-1];
        p[len-APrecision]='.';
        len++;
        return len;
    }
    return 0;
}

//------------------------------------------------------------------------------
int CDATATYPE_I32::gain_valStr(char *p, int size)
{

	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);

    if (pAttr) {
        int len=AddDotPoint(p, size, *(I32 *)m_pData, pAttr->m_NumDecs);
        if (len>0) return len;
    }

	return snprintf (p, size, "%i", *(I32 *)m_pData  );
}

int CDATATYPE_I32::gain_val(void *pData)
{
	if (pData)
		pData = m_pData;
	return *(I32 *)m_pData;
}
//===================================================
int CDATATYPE_I32::Init_KeyStr(char *p, int size)
{
	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);

    if (pAttr) {
        int len=AddDotPoint(p, size, *(I32 *)m_pData, pAttr->m_NumDecs, pAttr->Get_MaxChar());
        if (len>0) return len;
//        return snprintf (p, size, "%0*i", pAttr->Get_MaxChar(), *(I32 *)m_pData  );
    }

	return snprintf (p, size, "%i", *(I32 *)m_pData  );

}
int CDATATYPE_I32::KinStr_To_EditStr(char *pSrc, char *p, int size)
{

	return snprintf (p, size, "%s", pSrc  );
}
int CDATATYPE_I32::KinStr_Inc(char *p, int size, I8 idx)
{
	I8 n = 0;

	int len = strlen(p);
	n = (p+len) - (p+idx);

	//CHRUI_Err1("CDATATYPE_F32::KinStr_Inc", n);
	I32 _val = 1;
	for (int i=0; i<n; i++){
		_val *= 10;
	}

	tmp = atoi(p);
	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);

	if (pAttr){
		tmp += _val;
		if ( !Can_Set(&tmp) ) tmp = pAttr->m_Max;
        return AddDotPoint(p, size, tmp, pAttr->m_NumDecs, pAttr->Get_MaxChar());
	}
	return 0;
}
int CDATATYPE_I32::KinStr_Dec(char *p, int size, I8 idx)
{
	I8 n = 0;

	int len = strlen(p);
	n = (p+len) - (p+idx);

	//CHRUI_Err1("CDATATYPE_F32::KinStr_Dec", n);
	I32 _val = 1;
	for (int i=0; i<n; i++){
		_val *= 10;
	}
	tmp = atoi(p);
	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);

	if (pAttr){
		tmp -= _val;
		if ( !Can_Set(&tmp) ) tmp = pAttr->m_Min;
        return AddDotPoint(p, size, tmp, pAttr->m_NumDecs, pAttr->Get_MaxChar());
	}
	return 0;
}
//===================================================
int CDATATYPE_I32::IsValidKey(int key, int pressedCnt)
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
    		return 1;
    }
	return 0;
}


int CDATATYPE_I32::Get_InfoStr(char *p, int size)
{
	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);
	if (pAttr) {
        int len=AddDotPoint(p, size, pAttr->m_Min, pAttr->m_NumDecs);
        if (len>0) {
            len+=snprintf(&(p[len]), size-len, " - ");
            int mslen=AddDotPoint(&(p[len]), size-len, pAttr->m_Max, pAttr->m_NumDecs);
            if (mslen>0) return len+mslen;
        }
        return snprintf(p, size, "%i - %i", pAttr->m_Min, pAttr->m_Max);
    }
	return 0;
}




/*********************************************************************
*
*
*
**********************************************************************/

/*
#include "Chr_DataType_U8.h"
#include "Chr_DataType_I8.h"
#include "Chr_DataType_I8R.h"


#include <string>
using std::string;



static U8 u8Para = 1;
static CDATAATTR_NUM u8Attr(1, 10);
static CDATATYPE_U8 u8DType(&u8Para, &u8Attr);

static I8 i8Para = 1;
static CDATAATTR_NUM i8Attr(-2, 10);
static CDATATYPE_I8 i8DType(&i8Para, &i8Attr);


static I8R i8RPara = 1;
static string str[] = {"A123", "B0", "C99"};
static CDATAATTR_RING i8RAttr(1, 3, str);
static CDATATYPE_I8R i8rDType(&i8RPara, &i8RAttr);

static I32 i32Para = 1;
static CDATAATTR_NUM i32Attr(1, 10);
static CDATATYPE_I32 i32DType(&i32Para, &i32Attr);

void test_CDATATYPE_I32(void)
{
	CDATATYPE *p_DType;
	int id = -1;

	p_DType = &u8DType;
	id = p_DType->GetUniqueID();
	p_DType->set_val("9");
	p_DType->set_val("11");
	p_DType->set_val("2");


	p_DType = &i8DType;
	id = p_DType->GetUniqueID();
	p_DType->set_val("9");
	p_DType->set_val("11");
	p_DType->set_val("-2");

	p_DType = &i8rDType;
	p_DType->set_val("2");
	p_DType->set_val("11");
	p_DType->set_val("1");
	p_DType->set_val("0");
	p_DType->set_val("3");
	p_DType->set_val("4");

	p_DType = &i32DType;
	p_DType->set_val("9");
	p_DType->set_val("11");
	p_DType->set_val("2");
}
*/

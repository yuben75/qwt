#include "Chr_DataType_U16.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

CDATATYPE_U16::CDATATYPE_U16(U16 *pData, CDATAATTR *p_DAttr, FP_DATATYPE fp_DType)
: CDATATYPE_I32((void *)pData, p_DAttr, fp_DType, sizeof(U8))
{


}

int CDATATYPE_U16::Can_Set(U16 *pData)
{
	if (m_pDAttr){
		return m_pDAttr->Can_Set(*pData);
	}
	return 1;
}


int CDATATYPE_U16::set_val(U16 *pData)
{
	WM_MESSAGE Msg = {0};
    //Msg.Data.p = (void *)this;
	if (Can_Set(pData)){
		//memcpy(m_pData, pData, m_memSize);
        //Msg.MsgId = WMCHR_SET_DATA;
		*(U16 *)m_pData = *(U16 *)pData;
        Invalidate();
		if (m_fp_DType){
			m_fp_DType(&Msg);
		}
		return 1;
	}
	return 0;
}

int CDATATYPE_U16::Can_Set(char *p)
{
	U16 val;
	/*#ifdef WIN32
		sscanf_s((char *)p ,"%u", &val);
	#else
		sscanf((char *)p ,"%u", &val);
	#endif*/
	val = atoi(p);
	return Can_Set(&val);
}
int CDATATYPE_U16::set_val(char *p)
{
	U16 val;
	/*#ifdef WIN32
		sscanf_s((char *)p ,"%u", &val);
	#else
		sscanf((char *)p ,"%u", &val);
	#endif*/
	val = atoi(p);
	return set_val(&val);
}

//===================================================
int CDATATYPE_U16::Init_KeyStr(char *p, int size)
{
	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);

	if (pAttr)
		return snprintf (p, size, "%0*i", pAttr->Get_MaxChar(), *(U8 *)m_pData  );
	return snprintf (p, size, "%i", *(U16 *)m_pData  );

}

int CDATATYPE_U16::gain_valStr(char *p, int size)
{
	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);

	return snprintf (p, size, "%u", *(U16 *)m_pData  );
}

/*********************************************************************
*
*
*
**********************************************************************/
static U16 u16Para = 1;
static CDATAATTR_NUM u8Attr(1, 10);
static CDATATYPE_U16 u16DType(&u16Para, &u8Attr);
void test_CDATATYPE_U16(void)
{
    u16DType.set_val("5");
    u16DType.set_val("11");
    u16DType.set_val("2");
}

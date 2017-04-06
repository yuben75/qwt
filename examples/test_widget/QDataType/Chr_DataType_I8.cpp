#include "Chr_DataType_I8.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

CDATATYPE_I8::CDATATYPE_I8(I8 *pData, CDATAATTR *p_DAttr, FP_DATATYPE fp_DType)
: CDATATYPE_I32((void *)pData, p_DAttr, fp_DType, sizeof(I8))
{


}

int CDATATYPE_I8::Can_Set(I32 *pData)
{
	if (m_pDAttr){
		return m_pDAttr->Can_Set(*pData);
	}
	return 1;
}


int CDATATYPE_I8::set_val(I32 *pData)
{
	WM_MESSAGE Msg = {0};
    //Msg.Data.p = (void *)this;
	if (Can_Set(pData)){
		//memcpy(m_pData, pData, m_memSize);
        //Msg.MsgId = WMCHR_SET_DATA;
        *(I8 *)m_pData = *(I8 *)pData;
        Invalidate();
		if (m_fp_DType){
			m_fp_DType(&Msg);
		}
		return 1;
	}
	return 0;
}

int CDATATYPE_I8::Can_Set(char *p)
{
	I32 val;
	/*#ifdef WIN32
		sscanf_s((char *)p ,"%i", &val);
	#else
		sscanf((char *)p ,"%i", &val);
	#endif*/
	val = atoi(p);
	return Can_Set(&val);
}
int CDATATYPE_I8::set_val(char *p)
{
	I32 val;
	/*#ifdef WIN32
		sscanf_s((char *)p ,"%i", &val);
	#else
		sscanf((char *)p ,"%i", &val);
	#endif*/
	val = atoi(p);
	return set_val(&val);
}

//===================================================
int CDATATYPE_I8::Init_KeyStr(char *p, int size)
{
	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);

	if (pAttr)
		return snprintf (p, size, "%0*i", pAttr->Get_MaxChar(), *(I8 *)m_pData  );
	return snprintf (p, size, "%i", *(I8 *)m_pData  );

}
int CDATATYPE_I8::gain_valStr(char *p, int size)
{
	CDATAATTR_NUM *pAttr = dynamic_cast<CDATAATTR_NUM *>(m_pDAttr);

	return snprintf (p, size, "%i", *(I8 *)m_pData  );
}


/*********************************************************************
*
*
*
**********************************************************************/

static I8 i8Para = 1;
static CDATAATTR_NUM i8Attr(1, 10);
static CDATATYPE_I8 i8DType(&i8Para, &i8Attr);
void test_CDATATYPE_I8(void)
{
	i8DType.set_val("5");
	i8DType.set_val("11");
	i8DType.set_val("2");
}

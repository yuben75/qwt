#include "Chr_DataType.h"
#include "QWidget"

#if (SCPI_EN==1)
	#include "Scpiopt.h"
#endif
#include "stdio.h"




CDATATYPE::CDATATYPE(void *pData, int memSize, CDATAATTR *p_DAttr, FP_DATATYPE fp_DType)
{
	m_pData = pData;
	m_memSize = memSize;
	m_pDAttr = p_DAttr;
	m_fp_DType = fp_DType;
	m_binCmd = 0;
	m_fp_BinTxCmd = NULL;
}
/*
void CDATATYPE::remove_parent(WM_HMEM hObj)
{
    WM_HMEM hMem;
	for (vector<WM_HMEM>::iterator it=Parent.begin(); it!=Parent.end(); it++){
		hMem = *it;
		if (hMem == hObj){
			it = Parent.erase(it);
			break;
		}
	}
}*/

/*
void CDATATYPE::remove_parent(CWObj *pWObj)
{
	WM_HMEM hObj= WObjTO_Handle(pWObj);

	WM_HMEM hMem;
	for (vector<WM_HMEM>::iterator it=Parent.begin(); it!=Parent.end(); it++){
		hMem = *it;
		if (hMem == hObj){
			it = Parent.erase(it);
			break;
		}
	}
}
*/

void CDATATYPE::push_parent(WM_HMEM hMem)
{
	Parent.push_back(hMem);
}
void CDATATYPE::Invalidate(void)
{
	for (vector<WM_HMEM>::size_type ix=0; ix<Parent.size(); ix++){
        QWidget * pWidget = (QWidget *)Parent[ix];
        pWidget->update();
	}
}

void CDATATYPE::Set_PData(void *pData, CDATAATTR *p_DAttr)
{
	m_pData = pData;
	if (p_DAttr != NULL){
		m_pDAttr = p_DAttr;
	}
	Invalidate();
}

void CDATATYPE::Set_PDAttr(CDATAATTR *p_DAttr)
{
	m_pDAttr = p_DAttr;
	Invalidate();
}

void CDATATYPE::Set_BinCmd(int binCmd,FP_BINCMDTX fp)
{
	m_binCmd = binCmd;
	m_fp_BinTxCmd = fp;
}
int CDATATYPE::Get_BinCmd(void)
{
	return m_binCmd;
}

int CDATATYPE::TxBinCmd(void)
{
	if (!m_fp_BinTxCmd)
		return -1;
	return m_fp_BinTxCmd(m_binCmd, m_pData, m_memSize);
}

int CDATATYPE::Can_Set(char *p)
{
	return 0;
}
int CDATATYPE::set_val(char *p)
{
	return 0;
}

int CDATATYPE::get_val(char *p)
{
	return 0;
}
int CDATATYPE::gain_valStr(char *p, int size)
{
	return snprintf (p, size, "" );
}
int CDATATYPE::gain_val(void *pData)
{
	if (pData)
		pData = m_pData;
	return 1;
}
void CDATATYPE::set_IncVal(I8 idx, char KeyinStr[])
{

}
void CDATATYPE::set_DecVal(I8 idx, char KeyinStr[])
{

}
//===================================================
int CDATATYPE::Init_KeyStr(char *p, int size)
{
	return 0;
}
int CDATATYPE::KinStr_To_EditStr(char *pSrc, char *p, int size)
{
	return 0;
}
int CDATATYPE::KinStr_Inc(char *p, int size, I8 idx)
{
	return 0;
}
int CDATATYPE::KinStr_Dec(char *p, int size, I8 idx)
{
	return 0;
}

//===================================================
int CDATATYPE::IsValidKey(int key, int pressedCnt)
{
    //if (key == GUI_KEY_ENTER)
        //return 1;
	return 0;
}
int CDATATYPE::Get_InfoStr(char *p, int size)
{
	return 0;
}


#if (SCPI_EN==1)
U8 CDATATYPE::scpi_set_val(struct tagPROGDATA *pProgData, int &DataIdx, int DataCnt)
{
	return IB_FAIL;
}
U8 CDATATYPE::scpi_set_arrVal(vector <CDATATYPE *> apDType, struct tagPROGDATA *pProgData, int &DataIdx, int DataCnt)
{
	U8 result;

	for (vector<CDATATYPE *>::size_type ix=0; ix<apDType.size(); ix++){
		result = apDType[ix]->scpi_set_val(pProgData, DataIdx, DataCnt);
		if (result == IB_FAIL)
			break;
	}
	return result;
}

int CDATATYPE::scpi_get_val(char *p, struct tagPROGDATA *_pProgData, int &DataIdx, int DataCnt)
{
	if (DataCnt>0)
		return gain_valStr( p, (sizeof(g_pExecOutBuf) - g_u16ExecOutCnt) );
	return gain_valStr( p, (sizeof(g_pExecOutBuf) - g_u16ExecOutCnt) );
}
#endif

//===================================================
CDATAATTR *CDATATYPE::GetP_DAttr(void)
{
	return m_pDAttr;
}


#ifndef  CHR_DATATYPE_H
#define  CHR_DATATYPE_H

#include "Def_Type.h"
#include "Config.h"
//#include "Chr_WOBJ.h"
#include "Chr_DataAttr.h"

#include <vector>
using std::vector;

#if (SCPI_EN==1)
	#include "I4882.h"
	#include "ibArg.h"
	//#include "Scpiopt.h"
	//#include "mSCPI.h"
#endif

//typedef bool (*FP_DATATYPE)(CWObj *pWObj);
typedef int (*FP_DATATYPE)(WM_MESSAGE *pWMMsg);
typedef int (*FP_BINCMDTX)(int Cmd, void *pvoid, int Len);


class CDATATYPE {
	typedef CDATATYPE ThisClass;
public:
	CDATATYPE(void *pData, int memSize=0, CDATAATTR *p_DAttr=NULL, FP_DATATYPE fp_DType=NULL);

//	void remove_parent(CWObj *pWObj);
    void remove_parent(WM_HMEM hObj);
	void push_parent(WM_HMEM hMem);
	void Invalidate(void);

	virtual void Set_PData(void *pData, CDATAATTR *p_DAttr=NULL);
	virtual void Set_PDAttr(CDATAATTR *p_DAttr);
	virtual void Set_BinCmd(int binCmd, FP_BINCMDTX fp);
	virtual int Get_BinCmd(void);
	virtual int TxBinCmd(void);


	virtual int Can_Set(char *p);
	virtual int set_val(char *p);
	virtual int get_val(char *p);
	virtual int gain_valStr(char *p, int size);
	virtual int gain_val(void *pData=NULL);
	virtual void set_IncVal(I8 idx=0, char KeyinStr[]="");
	virtual void set_DecVal(I8 idx=0, char KeyinStr[]="");
	//===================================================
	virtual int Init_KeyStr(char *p, int size);
	virtual int KinStr_To_EditStr(char *pSrc, char *p, int size);
	virtual int KinStr_Inc(char *p, int size, I8 idx=0);
	virtual int KinStr_Dec(char *p, int size, I8 idx=0);
	//===================================================
	virtual int IsValidKey(int key, int pressedCnt=1);
	virtual int Get_InfoStr(char *p, int size);


	#if (SCPI_EN==1)
		virtual U8 scpi_set_val(struct tagPROGDATA *pProgData, int &DataIdx, int DataCnt=1);
		U8 scpi_set_arrVal(vector <CDATATYPE *> apDType, struct tagPROGDATA *pProgData, int &DataIdx, int DataCnt=1);
		virtual int scpi_get_val(char *p, struct tagPROGDATA *pProgData, int &DataIdx, int DataCnt=1);
	#endif

	CDATAATTR *GetP_DAttr(void);
protected:
	vector <WM_HMEM> Parent;
	void *m_pData;
	int m_memSize;
	CDATAATTR *m_pDAttr;
	FP_DATATYPE m_fp_DType;
	int m_binCmd;
	FP_BINCMDTX m_fp_BinTxCmd;
private:

};




#endif


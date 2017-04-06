#ifndef _DEF_TYPE_H
#define _DEF_TYPE_H

#if defined(__cplusplus)
#else
	#ifndef bool
		#define bool		I8
	#endif

	#ifndef NULL
		#define NULL		((void *)0)
	#endif
#endif


#ifndef ZERO_RTN
#define ZERO_RTN(x) { int __result__ = (x); if (__result__ == 0) return __result__; }
#endif
#ifndef NOZERO_RTN
#define NOZERO_RTN(x) { int __result__ = (x); if (__result__!= 0) return __result__; }
#endif

#ifndef RINOK
#define RINOK(x) { int __result__ = (x); if (__result__ != 0) return __result__; }
//RINOK(call_func(p, limit2, bufLimit));
#endif

typedef void * WM_HMEM;
//typedef char WM_MESSAGE;
struct WM_MESSAGE {
  int MsgId;            /* type of message */
  int hWin;         /* Destination window */
  int hWinSrc;      /* Source window  */
  union {
    const void * p;            /* Some messages need more info ... Pointer is declared "const" because some systems (M16C) have 4 byte const, byte 2 byte default ptrs */
    int v;
    int Color;
  } Data;
};

#ifndef NULL
    #define NULL		0
#endif


typedef double						F64;
typedef float							F32;
typedef unsigned long			U40;
typedef unsigned int			U32;
typedef unsigned short		U16;
typedef char							U8;
typedef unsigned char			BOOL;
typedef signed long       I40;
typedef signed int				I32;
typedef signed short			I16;
typedef signed char				I8;
typedef char              C8;
typedef I8								I8R;
typedef struct{
	U8	v[4];
}IP4;
typedef struct{
	int	v[4];
}IP_X;



typedef volatile unsigned long *        U40Ptr;
typedef volatile unsigned int *         U32Ptr;
typedef volatile unsigned short * 			U16Ptr;
typedef volatile signed char *	 		 		U8Ptr;
typedef volatile signed long *			 		I40Ptr;
typedef volatile signed int *			 			I32Ptr;
typedef volatile signed short *         I16Ptr;
typedef volatile signed char *	 		 		C8Ptr;
typedef volatile float *                F32Ptr;
typedef volatile double *			 	 				F64Ptr;


//---------------------------------------------------------------------------------------------
/* Gobal typedef */
//---------------------------------------------------------------------------------------------
typedef U16 (*BYFP)(void);
typedef I16 (*INTFP_INT)(I16);
typedef void (*FnPtr)(void);//Function Pointer define

typedef union{
	U16 u16;
	U8 au8[2];
}TpU16;

typedef union{
	I16 i16;
	I8 ai8[2];
}TpI16;

typedef union{
	U32 u32;
	U8 au8[4];
}TpU32;

typedef union{
	I32 i32;
	I8 ai8[4];
}TpI32;

typedef union{
	F32 f32;
	U8 au8[4];
}TpF32;

typedef union{
	U32	u32Flags;
	struct{
		int isDUAL		:1;//bit 31
		int isLOAD_XV	:1;//bit 30
		int isLOAD_XIV	:1;//bit 29
		int isLOAD_XIII	:1;//bit 28
		int isLOAD_XII	:1;//bit 27
		int isLOAD_XI	:1;//bit 26
		int isLOAD_X	:1;//bit 25
		int isLOAD_IX	:1;//bit 24
		int isLOAD_VIII	:1;//bit 23
		int isLOAD_VII	:1;//bit 22
		int isLOAD_VI	:1;//bit 21
		int isLOAD_V	:1;//bit 20
		int isLOAD_IV	:1;//bit 19
		int isLOAD_III	:1;//bit 18
		int isLOAD_II	:1;//bit 17
		int isLOAD_I	:1;//bit 16
	}ModBits;
	struct{
		int isRSV15		:1;//bit 15
		int isRSV14		:1;//bit 14
		int isRSV13		:1;//bit 13
		int isRSV12		:1;//bit 12
		int isRSV11		:1;//bit 11
		int isRSV10		:1;//bit 10
		int isPOTE		:1;//bit 9
		int isRMTE		:1;//bit 8
	}SysBits;
	struct{
		int isRSV7		:1;//bit 7
		int isRSV6		:1;//bit 6
		int isRSV5		:1;//bit 5
		int isSAVE		:1;//bit 4
		int isFOCS		:1;//bit 3
		int isHIDE		:1;//bit 2
		int isBLNK		:1;//bit 1
		int isLOCK		:1;//bit 0
	}EdtBits;
}TpFlags;

/* EDIT typedef */
typedef struct{
	U8	 u8Font;
	char *pu8Str;
}TpStr;

typedef struct{
	U8	u8Font,u8Bit,u8Mask;
	void *pNext;
}TpLed;

typedef struct{
	TpStr	*pUnit;
	U8		u8Dot;//dot for display
	U8		decDot;//dot for power of 10
	I32		i32Min,i32Max,i32Rsl;
}TpNum;
/*
typedef struct{
	U8		u8Type;
	U8		u8Range;
	U8		*pu8VarSel;
	
	TpStr	*pUnit;
	U8		u8Dot;
	I32		i32Min,i32Max,i32Rsl;
}TpNum;
*/
/*
typedef struct{
	TpNum Ary[13][3];
}TpNum1;
*/
typedef struct{
	U8 *pVarSel;
	U8 *pRngSel;
	TpNum Rng[3];
}TpNum1;

typedef struct{
	I32	i32Cond;
	TpNum tpNum;
}TpNum2;

typedef struct{
	TpNum2 Ary[13];
}TpNum3;

typedef struct{
	TpNum tpNum;
}TpHex;

typedef struct{
	U8 *pu8Sign;
	TpStr *AryUnit[5];
}TpBdy;

typedef struct{
	TpBdy Model[14];
}TpBdy1;

typedef struct{
	struct{
		TpBdy Range[3];
	}Model[14];
}TpBdy2;

typedef struct{
	U8 u8SelNum;
	TpLed **pLed;
}TpLedSel;

typedef struct{
	U8		u8Max;
	TpStr	**pSel;	//array Selectors pointer
}TpRing;

typedef struct{
	U8		Type,Font,Field,VarLen;
	U8		*pVar;
	void	*pLabel;
	void	(*CallBack)(U8 ch, U8 type, void *pItemRMT, U32 val);
	void	*pSub;
	U16		CmdId;
}ITEM_T;

typedef struct{
	I32 (*GetVarValue)(U8 ch, ITEM_T *pItem);
	U8* (*SetVarValue)(U8 ch, I32 val, ITEM_T *pItem);
	void* (*GetSub)(ITEM_T *pItem);
	void (*SetCursor)(U16 x, U16 y, U8 pos, U8 size, U8 type, ITEM_T *pItem, U8 idx);
	void (*EraseLabel)(U16 x, U16 y, ITEM_T *pItem, U16 flag);
	void (*DrawLabel)(U16 x, U16 y, ITEM_T *pItem, U16 flag);
	void (*EraseValue)(U16 x, U16 y, ITEM_T *pItem, U16 flag);
	void (*DrawValue)(U16 x, U16 y, ITEM_T *pItem, U16 flag);
	void (*KeyEdit)(U8 event, ITEM_T *pItem, U16 flag);
}FUNC_T;

typedef struct{
	U16		X,Y;
	U16		*pFlag;
	ITEM_T	*pItem;
}ITEM_ATTR_T;

typedef struct{
	FnPtr		PageFn;
	U8			ItemNum;
	ITEM_ATTR_T	*pItemList;
}PAGE_T;

typedef PAGE_T FORM_T;

typedef struct{
	U16		RootX;
	U16		RootY;
	U8		RootItemType;
	U16		RootItemFlag;
	I32		RootItemVal;
	I32		RootEditVal;
	ITEM_T	*pRootItem;//Root eidt item
	FUNC_T	*pRootFunc;//Root eidt item

	U8		ItemNo;
	U8		EditMode;
	U8		DataChange;

	U16		X;
	U16		Y;
	U8		ItemType;
	U16		ItemFlag;
	I8		i8EditPos;
	I32		i32ItemVal;
	I32		i32EditVal;
	TpNum	Bdy;
	ITEM_T	*pItem;//Current eidt item
	FUNC_T	*pFunc;//Current eidt item
}TpEditInfo;

typedef struct{
	PAGE_T *hPAGE;
}TpPageInfo;

typedef struct{
	struct{
		U8	u8State;//Parallel state
		U8	u8ChMA;//Master channel
		U16 u16ChMA;//Master channel bits field
		U16 u16ChSL;//Slave channel bits field
	}PARA;
	struct{
		U8	u8State;//Sync. state
		U8	u8ChMA;//Master channel 0 ~ 9
		U16 u16ChMA;//Master channel bits field
		U16 u16ChSL;//Slave channel bits field
	}SYNC;
	struct{
		U8	u8ChMA;//Master channel 0 ~ 9
		U16 u16ChMA;//Master channel bits field
		U16 u16ChSL;//Slave channel bits field
	}MASL;
	struct{
		U8	u8Remote;	//Local | Remote
		U8	u8ChMax;
		U8	u8ChNow;	//CH_L | CH_R
		U8	u8ChSel;	//CH_L | CH_R
		U8	u8ChType;	//Single | Dual;
		U16 u16ChSel;	//Selected channel bits field
		U16 ChAliveBF;
		U16 ChActiveBF;
		U16 ChAllRunBF;//All_Run channel bits field
		U16	ChProtect;//Protection
		FORM_T	*pFORM;
		//
//		U8	u8RmtInhibit;//Remote Inhibit
//		U8	u8ExtOnOff;//External load on/off
//		U8	u8EnExtOnOff;//External load on/off enable/disable
		U8	u8CanAddr;
		U8	u8FrameMASL;//Master
		U8	u8SyncMASL;//Master
		U8	CrossFrameList[10+1];
		U8	CrossFrameCnt[10+1];
		U32	CrossFrameBits,FileReadyBits;
		U16 u16MaxWindT;//The Maximun window time in Frame
		U16 u16SyncInit;
	}SYS;
	struct{
		U8	u8PageIDNow;
		U8	u8PageIDPrev;
	}CH[3];//L|R|LR
}TpSysInfo;

typedef struct{
	U8		u8In,u8Out;
	U8		u8No,u8Data1,u8Data2;//current event information
	void	*pData3;
	struct{//event buffer
		U8		u8No,u8Data1,u8Data2;
		void	*pData3;
	}buf[32];
}TpEventG;

/* KEY typedef */
typedef struct{
	U16 keyCode;
	U8 keyId;
}TpKeyMap;
typedef struct{
	FnPtr PressFunc;
	FnPtr ConfirmFunc;
	FnPtr ReleaseFunc;
}TpKeyFunc;
typedef struct{
	U8 fgGetKey;
	U16 deBounCnt;
	U16 keyConfirmCnt,keyConfirmCntChk;
	U16 keyCode;
	U8 keyId,fgKeyRls,keyState;
	FnPtr keyFunc;
}TpKeyInfo;

typedef struct{
	U16		XOfs;
	U16		YOfs;
	U16		*pFlag;
	ITEM_T	*pItem;
}TpMenu;

typedef struct{
	U8		u8RowSize;
	U8		u8Max;
	U8		u8Rsl;
	U16		Flag;
	TpMenu	*pSel;
}TpMenuSel;

typedef struct VFM_CursorArea{
	U8 u8CurState;
	U8 u8Toggle;
	U8 u8Font,u8X,u8Y;
	U8 u8Pos;
	U8 u8Size;
	U8 u8Type;
	U8 Active;
}TpCursorArea;

typedef struct{
	U8 u8Len;
	U8 *pu8Var;
	U32 u32Val;
}TpInitTbl;

typedef union{
	U8	au8Version[45];
	struct{
		U8	au8Ver1[9];
		U8	au8Ver2[9];
		U8	au8Ver3[9];
		U8	au8Ver4[9];
		U8	au8Rsv[9];
	}SubVer;
}TpVerStr;

typedef struct{
	U8	unit;
	U8	dot;
	I32	val;
}TpDynaDigi;

typedef struct{
	U8 u8Id;
	U8 u8Action;
	U8 u8Data;
}TpKeyCmd;

typedef struct{
	U8 len;
	U8 type;
	struct{
		U8 ascii;
		U8 null;
	}sn[12];
}TpUSBsn;

typedef struct{
	U8	fgState;
	U8	CmdId;
	U16	ChQryWho;
	U16	ChCmdIn;
}TpModuleReply;

//DEBUG.REMOTE.FUNCTION
//typedef struct{
//	U8	Min;
//	U8	Max;
//	I8  Radix;
//	I8	decDot;//dot for power of 10
//}tagSpecU8;
typedef struct{
	U16	Min;
	U16	Max;
	I8  Radix;
	I8	decDot;//dot for power of 10
}tagSpecU16;
//typedef struct{
//	U32	Min;
//	U32	Max;
//	I8  Radix;
//	I8	decDot;//dot for power of 10
//}tagSpecU32;
//typedef struct{
//	I8	Min;
//	I8	Max;
//	I8  Radix;
//	I8	decDot;//dot for power of 10
//}tagSpecI8;
typedef struct{
	I16	Min;
	I16	Max;
	I8  Radix;
	I8	decDot;//dot for power of 10
}tagSpecI16;
typedef struct{
	I32	Min;
	I32	Max;
	I32	Rsl;
	I8  Radix;
	I8	decDot;//dot for power of 10
}tagSpecI32;
typedef struct tagFUNCDATA{
	U8	u8DataType;
//	U8	u8Data;
	U16	u16Data;
//	U32	u32Data;
//	I8	i8Data;
	I16	i16Data;
	I32	i32Data;
}FUNCDATA;

typedef struct{
	U16 x,y;
}TpPoint;

//*******************************************//
#define		WRITE_PORT_16(addr,data)        *(U16Ptr)(addr) = (U16)(data)
#define		READ_PORT_16(addr)              (*(U16Ptr)(addr))
#define		WRITE_PORT_32(addr,data)        *(U32Ptr)(addr) = (U32)(data)
#define		READ_PORT_32(addr)              (*(U32Ptr)(addr))
#define		WRITE_PORT_8(addr,data)	        *(U32Ptr)(addr) = (U8)(data)
#define		READ_PORT_8(addr)               (*(U8Ptr)(addr))

#define SIZE(ary)	(sizeof(ary)/sizeof(ary[0]))


#endif



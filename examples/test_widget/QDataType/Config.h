#ifndef  _CONFIG_H
#define  _CONFIG_H

#define SCPI_EN     0
#define CHR_GUI_EN	1

#define KEIL_C      0
#if KEIL_C
#define IDATA			idata
#define PDATA			pdata
#define XDATA			xdata
#define RDATA			code
#define XFAR
#else
#define IDATA
#define PDATA
#define XDATA
#define RDATA			const
#define XFAR
//#define code
#endif


#endif

/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#define __FF7FILE__ "C:\\FF7\\chocobo\\ch_app.cpp"

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
extern struct t_chocobo_48 D_0096E8D8[];//HIRES
extern struct t_chocobo_48 D_0096E968[];//HIRES
extern struct t_chocobo_48 D_0096E9F8[];//LORES
extern struct t_chocobo_48 D_0096EA88[];//LORES

extern struct t_chocobo_48 D_0097A4F8[];//HIRES
extern struct t_chocobo_48 D_0097A810[];//HIRES
extern struct t_chocobo_48 D_0097AB28[];//HIRES
extern struct t_chocobo_48 D_0097ACD8[];//LORES
extern struct t_chocobo_48 D_0097AFA8[];//LORES
extern struct t_chocobo_48 D_0097B2C0[];//LORES

extern struct t_chocobo_48 D_0097B800[];//HIRES
extern struct t_chocobo_48 D_0097B9B0[];//LORES

extern struct t_chocobo_48 D_0097BC98[];//HIRES
extern struct t_chocobo_48 D_0097BF20[];//LORES
extern struct t_chocobo_48 D_0097C1A8[];//HIRES
extern struct t_chocobo_48 D_0097C478[];//LORES
////////////////////////////////////////
//=== ===
LARGE_INTEGER D_00E3BA30;
LARGE_INTEGER D_00E3BA38;
struct t_sound_related_24 D_00E3BA40;
struct tScreenInfo D_00E3BA68;
int D_00E3BA8C;
int D_00E3BA90;
int D_00E3BA94;
float D_00E3BA98;
struct t_chocobo_48 *D_00E3BA9C;
struct t_chocobo_48 *D_00E3BAA0;
struct t_chocobo_48 *D_00E3BAA4;
struct t_chocobo_48 *D_00E3BAA8;
struct t_chocobo_48 *D_00E3BAAC;
struct t_chocobo_48 *D_00E3BAB0;
struct t_chocobo_48 *D_00E3BAB4;
struct t_chocobo_48 *D_00E3BAB8;
void (*D_00E3BABC)(unsigned, int, int);//render integer(callback)
double D_00E3BAC0;
int D_00E3BAC8;
int D_00E3BAD0;//endgame flag?
int D_00E3BAD4;
//=== ===
////////////////////////////////////////
void C_0076D4E6(int, int, int, int);//chocobo:set viewport

//ch_app:set screen info
void C_0076D320(int dwSWRenderer/*bp08*/, int dwGrMode/*bp0c*/) {
	D_00E3BA68.dwSWRenderer = dwSWRenderer;
	D_00E3BA68.dwGrMode = dwGrMode;
	if(dwGrMode == 2) {
		//===========
		//== HIRES ==
		//===========
		C_0076D4E6(0, 8, 640, 464);//chocobo:set viewport
		D_00E3BA68.f_18 = 2;
		D_00E3BA98 = 232.0f;
		D_00E3BA68.dwScrXOfs = 0;
		D_00E3BA68.dwScrYOfs = 0;
		D_00E3BA8C = 8;
		D_00E3BA9C = D_0097A4F8;
		D_00E3BAA0 = D_0097A810;
		D_00E3BAA4 = D_0097C1A8;
		D_00E3BAA8 = D_0097BC98;
		D_00E3BAAC = D_0097AB28;
		D_00E3BAB4 = D_0096E8D8;
		D_00E3BAB8 = D_0096E968;
		D_00E3BA90 = 0xb;
		D_00E3BABC = C_00776D2B;
		D_00E3BAB0 = D_0097B800;
		D_00E3BA94 = 0x20;
	} else {
		//===========
		//== LORES ==
		//===========
		D_00E3BA9C = D_0097ACD8;
		D_00E3BAA0 = D_0097AFA8;
		D_00E3BAA4 = D_0097C478;
		D_00E3BAA8 = D_0097BF20;
		D_00E3BAAC = D_0097B2C0;
		D_00E3BAB4 = D_0096E9F8;
		D_00E3BAB8 = D_0096EA88;
		D_00E3BA90 = 0xa;
		D_00E3BABC = C_00776B8C;
		D_00E3BAB0 = D_0097B9B0;
		D_00E3BA94 = 0x10;
		D_00E3BA68.f_18 = 1;
		D_00E3BA98 = 232.0f;
		D_00E3BA8C = 4;
		if(dwGrMode == 0) {
			C_0076D4E6(0, 4, 320, 232);//chocobo:set viewport
			D_00E3BA68.dwScrXOfs = 0;
			D_00E3BA68.dwScrYOfs = 0;
		} else {
			C_0076D4E6(160, 124, 320, 232);//chocobo:set viewport
			D_00E3BA68.dwScrXOfs = 160;
			D_00E3BA68.dwScrYOfs = 120;
		}
	}
}

//chocobo:set viewport
void C_0076D4E6(int dwX/*bp08*/, int dwY/*bp0c*/, int dwWidth/*bp10*/, int dwHeight/*bp14*/) {
	D_00E3BA68.f_08 = dwX;
	D_00E3BA68.f_10 = dwWidth;
	D_00E3BA68.f_0c = dwY;
	D_00E3BA68.f_14 = dwHeight;
}

//ch_app:release "struct t_rsd_unused_10"[unused]
void __0076D50D(struct t_rsd_unused_10 *bp08, struct t_aa0 *bp0c) {
	if(bp08) {
		C_0067466D(bp08->f_0c, bp0c);//rsd:release some object
		mem_free(bp08, __FF7FILE__, 0xab);
	}
}

//ch_app:alloc "struct t_rsd_unused_10"[unused]
struct t_rsd_unused_10 *__0076D541() {
	struct t_rsd_unused_10 *local_1;

	local_1 = (struct t_rsd_unused_10 *)mem_calloc(1, sizeof(struct t_rsd_unused_10), __FF7FILE__, 0xb3);
	if(local_1) {
		local_1->f_00 = 1;
		local_1->f_04 = 1;
		local_1->f_08 = 4;
	}

	return local_1;
}

//chocobo:set snd related object
void C_0076D588() {
	D_00E71664 = &D_00E3BA40;
}

void C_0076D6DF(void);

//chocobo[BEGIN][callback]
void C_0076D597(struct t_aa0 *bp08) {
	struct {
		int local_66;
		int _ocal_65[0x20];
		int local_33;
		int _ocal_32[0x20];
	}lolo;

	lolo.local_33 = 0;
	D_00972174 = 1;//set release mode
	D_00E3BAC8 = 0;
	if(1) {
		bp08->f_9a0 = 100.0f;
		bp08->f_9a4 = 80000.0f;
		bp08->f_984 = 1;//Direct3D2 flag?
		C_006619AA(D_00E3BA98);//psx:D_0090AAF0->f_08 = (double)?
		C_006833D0(&lolo.local_66);//anm:get some default flags?
		lolo.local_66 = 0x8000|0x40|0x10|1;//0x8051
		C_006833DE(&lolo.local_66);//anm:set some flags?
		C_00661966(0);//psx:set LH/RH flag?
		lolo.local_33 = 1;
		D_00E3BAD0 = 0;
		C_00674551(RSD_00100000);//rsd:set "RSD" flags
		C_00660E95(0, bp08);//G_DRV_84:change_layer?
		C_007794F0(bp08);//ch_ddraw:init
		C_00779850();//chocobo:init palettes[unused]
		C_0076D588();//chocobo:set snd related object
		C_00747BE3(0x7f);//sound:volume[all channels]
		D_00E3BAC0 = bp08->f_030 / 30.0;
		C_00779585(bp08);//ch_ddraw:init(2)
		g_drv_viewport(D_00E3BA68.f_08, D_00E3BA68.f_0c, D_00E3BA68.f_10, D_00E3BA68.f_14, bp08);
		D_00E3BAD4 = 1;
		C_0076D6DF();
	}
}

void C_0076D6DF() {
	struct {
		struct SVECTOR local_37;
		struct VECTOR local_35;
		struct t_rsd_74 *local_31;
		struct t_aa0 *local_30;
		struct t_rsd_74 local_29;
	}lolo;

	lolo.local_30 = C_00676578();

	lolo.local_31 = &lolo.local_29;
	C_0067455E(lolo.local_31);//rsd:init with blend mode 4?
	lolo.local_31->dwRSDFlags |= RSD_00100000;
	C_00674659(4, lolo.local_31);//rsd:set blend mode?
	C_0077C430(lolo.local_30, lolo.local_31);

	C_00661B68(0, 0);//psx:set view x,y?
	lolo.local_37.f_00 = 0;
	lolo.local_37.f_02 = 0;
	lolo.local_37.f_04 = 0x800;
	psx_RotMatrixXYZ(&lolo.local_37, &D_00E73DB0);
	lolo.local_35.f_00 = 320;
	lolo.local_35.f_04 = 0xf0;
	lolo.local_35.f_08 = 0x384;
	psx_TransMatrix(&D_00E73DB0, &lolo.local_35);
	psx_SetRotMatrix(&D_00E73DB0);
	psx_SetTransMatrix(&D_00E73DB0);
	C_006611FB(&D_00E73DB0, &D_00E72E18);//psx:transformation to D3DMATRIX(1)
	C_0077B9A9(lolo.local_30);
}

void C_0076D7D8() {
	if(D_00E7112C) {
		if(D_00972174 == 0) {//else 0076D997
			//===========
			//== DEVEL ==
			//===========
			if(D_00E7112C->f_08) {
				mem_free(D_00E7112C->f_08, __FF7FILE__, 0x179);
				D_00E7112C->f_08 = 0;
			}
			if(D_00E7112C->pDG4) {
				mem_free(D_00E7112C->pDG4, __FF7FILE__, 0x17e);
				D_00E7112C->pDG4 = 0;
			}
			if(D_00E7112C->pDG3) {
				mem_free(D_00E7112C->pDG3, __FF7FILE__, 0x183);
				D_00E7112C->pDG3 = 0;
			}
			if(D_00E7112C->pMAPPOINTER) {
				mem_free(D_00E7112C->pMAPPOINTER, __FF7FILE__, 0x188);
				D_00E7112C->pMAPPOINTER = 0;
			}
			if(D_00E7112C->pMAPTABLE) {
				mem_free(D_00E7112C->pMAPTABLE, __FF7FILE__, 0x18d);
				D_00E7112C->pMAPTABLE = 0;
			}
			if(D_00E7112C->pDOMEG3) {
				mem_free(D_00E7112C->pDOMEG3, __FF7FILE__, 0x192);
				D_00E7112C->pDOMEG3 = 0;
			}
			if(D_00E7112C->pSPRITE) {
				mem_free(D_00E7112C->pSPRITE, __FF7FILE__, 0x197);
				D_00E7112C->pSPRITE = 0;
			}
			if(D_00E7112C->pGUIDE) {
				mem_free(D_00E7112C->pGUIDE, __FF7FILE__, 0x19c);
				D_00E7112C->pGUIDE = 0;
			}
		} else {
			//=============
			//== RELEASE ==
			//=============
			if(D_00E3BA28) {
				mem_free(D_00E3BA28, __FF7FILE__, 0x1a3);
				D_00E3BA28 = 0;
			}
		}

		if(D_00E7112C->pFloatDG4) {
			mem_free(D_00E7112C->pFloatDG4, __FF7FILE__, 0x1a9);
			D_00E7112C->pFloatDG4 = 0;
		}
		if(D_00E7112C->pFloatDG3) {
			mem_free(D_00E7112C->pFloatDG3, __FF7FILE__, 0x1ae);
			D_00E7112C->pFloatDG3 = 0;
		}
		if(D_00E7112C->pFloatDOMEG3) {
			mem_free(D_00E7112C->pFloatDOMEG3, __FF7FILE__, 0x1b3);
			D_00E7112C->pFloatDOMEG3 = 0;
		}
		mem_free(D_00E7112C, __FF7FILE__, 0x1b7);
		D_00E7112C = 0;
	}
	C_0076E26C();//chocobo:free SFX
}

//chocobo[END][callback]
void C_0076DA88(struct t_aa0 *_p08) {
	C_0076EFF0();//ch_chr:clean(1)?
	C_007714E9();//[release this module]
	C_0076D7D8();
	if(D_00E3B754) {
		mem_free(D_00E3B754, __FF7FILE__, 0x1ca);
		D_00E3B754 = 0;
	}
	C_0076FD68();//ch_chr:clean(2)?
	C_007700D9();//chocobo:clean this module
	D_00E73C20 = 0;
	D_00E73C24 = 0;
	D_00E3BAD0 = 1;
}

void __0076DAEF(int dwX/*bp08*/, int dwY/*bp0c*/, const char *szText/*bp10*/, HDC hdc/*bp14*/) {
	SetBkColor(hdc, 0xff0000);
	SetTextColor(hdc, 0x00ffff);
	TextOut(hdc, dwX, dwY, szText, lstrlen(szText));
}

void C_0076DB33(struct t_aa0 *bp08) {
	struct {
		struct tMainCallbacks local_11;
		struct fBGRA local_4;
	}lolo;

	if(D_00E3BAD0) {
		lolo.local_4.r = 0; lolo.local_4.g = 0; lolo.local_4.b = 0; lolo.local_4.a = 1.0f;
		g_drv_clearColor(&lolo.local_4, bp08);
		g_drv_clearAll(bp08);
		D_00CC0D84 = 0x07;
		D_00CBF9DC = 0x01;
		lolo.local_11.f_10 = C_004090E6;//MainDispatcher[UPDATE][callback]
		lolo.local_11.f_14 = C_00409DF1;//MainDispatcher[ONMOUSE][callback]
		lolo.local_11.f_18 = C_00409E39;//MainDispatcher[ONKEY][callback]
		lolo.local_11.f_08 = C_00408FA6;//MainDispatcher[BEGIN][callback]
		lolo.local_11.f_0c = C_004090C7;//MainDispatcher[END][callback]
		C_00666CF2(&lolo.local_11, bp08);//set main loop callbacks?
		D_00E3BAD0 = 0;
	}
}

//chocobo[UPDATE][callback]
void C_0076DBD1(struct t_aa0 *bp08) {
	struct {
		int local_6;
		int local_5;
		struct fBGRA local_4;
	}lolo;

	lolo.local_5 = 0;
	lolo.local_6 = 1;
	TS_getCPUTimeStamp(&D_00E3BA38);
	lolo.local_4.r = 0; lolo.local_4.g = 0; lolo.local_4.b = 0; lolo.local_4.a = 1.0f;
	g_drv_clearColor(&lolo.local_4, bp08);
	g_drv_clearAll(bp08);

	C_0076DF8C();//chocobo:refresh input
	C_0077C462();//chocobo:refresh
	if(D_00E3BAD0 == 0)
		C_00779E14(bp08);
	else
		C_0076DB33(bp08);
}

void C_0076DC5B(struct t_aa0 *bp08) {
	struct {
		int local_6;
		int local_5;
		struct fBGRA _ocal_4;
	}lolo;

	lolo.local_5 = 0;
	lolo.local_6 = 1;
	TS_getCPUTimeStamp(&D_00E3BA38);

	C_0076DF8C();//chocobo:refresh input
	C_0077C462();//chocobo:refresh
	if(D_00E3BAD0 == 0)
		C_00779E14(bp08);
	C_0076DB33(bp08);
}

//chocobo[ONMOUSE][callback]
void C_0076DCAB(int uMsg/*_p08*/, int wParam/*_p0c*/, int lParam/*_p10*/, struct t_aa0 *_p14) {
	char _dummy_[0xc];
}

//chocobo[ONKEY][callback]
void C_0076DCB5(int uMsg/*_p08*/, int wParam/*_p0c*/, int lParam/*_p10*/, struct t_aa0 *_p14) {
	char _dummy_[0xc];
}

//ch_app:unused init?
void C_0076DCBF(int _p08, int _p0c) {
	struct {
		const char *local_3;
		int local_2;
		struct t_aa0 *local_1;
	}lolo;

	C_006602C1(0);//mem:set debug on/off?
	lolo.local_1 = C_00676E7E();//init some game object?
	if(lolo.local_1) {
		lolo.local_1->f_95c = 16;//request 16bpp
		lolo.local_1->f_964 = 1;
		lolo.local_1->f_968 = 1;
		lolo.local_1->f_96c = 0;
		lolo.local_1->f_988 = 1;
		if(lolo.local_1->f_988)
			lolo.local_1->f_994 = 1;
		lolo.local_1->f_948 = 0;
		lolo.local_1->f_974 = 1;//hide cursor
		lolo.local_1->f_9a0 = 100.0f;
		lolo.local_1->f_9a4 = 80000.0f;
		lolo.local_1->f_984 = 1;//Direct3D2 flag?
		C_006619AA(D_00E3BA98);//psx:D_0090AAF0->f_08 = (double)?
		C_006833D0(&lolo.local_2);//anm:get some default flags?
		lolo.local_2 = 0x8000|0x40|0x10|1;//0x8051
		C_006833DE(&lolo.local_2);//anm:set some flags?
		lolo.local_3 = /*0096E50C*/"APP.CFG";
		C_0069B660(lolo.local_3, lolo.local_1);//parse ".CFG" file?
		C_0067656B(lolo.local_1);//directx:set some game object?
	}
}

//ch_app:debug<empty>?
void C_0076DDD6(struct t_aa0 *_p08) {
	struct {
		HDC local_53;
		int local_52;
		int local_51;
		char local_50[200];
	}lolo;
}

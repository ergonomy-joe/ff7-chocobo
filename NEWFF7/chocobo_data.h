/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __CHOCOBO_DATA_H__
#define __CHOCOBO_DATA_H__

#include "loadmenu.h"

#define CH_KEY_CAMERA 0
#define CH_KEY_TARGET 1
#define CH_KEY_PGUP   2
#define CH_KEY_PGDN   3
#define CH_KEY_MENU   4
#define CH_KEY_OK     5
#define CH_KEY_CANCEL 6
#define CH_KEY_SWITCH 7
#define CH_KEY_ASSIST 8
//9
//10
#define CH_KEY_START  11
#define CH_KEY_UP     12
#define CH_KEY_RIGHT  13
#define CH_KEY_DOWN   14
#define CH_KEY_LEFT   15

////////////////////////////////////////
struct t_chocobo_a4 {//size 0xa4
	short f_00;//00E71158
	short f_02;//00E7115A
	short f_04;//00E7115C
	short f_06;//00E7115E
	char __08[2];
	short f_0a;
	char __0c[4];
	struct SVECTOR f_10;
	int f_18;
	char __1c[4];
	int f_20;
	char __24[4];
	struct SVECTOR f_28;
	struct SVECTOR f_30;
	struct SVECTOR f_38;
	struct SVECTOR f_40;
	short f_48;//_00E711A0
	short f_4a;//_00E711A2
	short f_4c;//_00E711A4
	short f_4e;//_00E711A6
	short f_50;//_00E711A8
	short f_52;//_00E711AA
	short f_54;//_00E711AC
	short f_56;//_00E711AE
	/*58*/short wTopSpeed;//_00E711B0
	short f_5a;//_00E711B2
	short f_5c;//_00E711B4
	short f_5e;//_00E711B6
	/*60*/short wIsAutomatic;//_00E711B8
	short f_62;//_00E711BA
	short f_64;//_00E711BC
	short f_66;//_00E711BE
	/*68*/int dwStamina,dwMaxStamina;//_00E711C0/_00E711C4
	short f_70;//_00E711C8
	/*72*/short wAnimationCounter;//_00E711CA
	/*74*/short f_74;//unused counter//_00E711CC
	/*76*/short wAnimationCounterIncr;//_00E711CE
	/*78*/short wPrevAnmNum;//_00E711D0
	char __7a[2];
	short f_7c;//xpos on track?//_00E711D4
	short f_7e;//_00E711D6
	/*80*/short wAnmNum;//_00E711D8
	short f_82;//_00E711DA
	short f_84;//_00E711DC
	short f_86;//_00E711DE
	unsigned char f_88[8];//_00E711E0
	short f_90,f_92;//chocobo/jockey//_00E711E8,_00E711EA
	short f_94;//counter to next noise//_00E711EC
	short f_96;//_00E711EE
	short f_98;//_00E711F0
	short f_9a;//_00E711F2
	short f_9c;//_00E711F4
	short f_9e;//_00E711F6
	short f_a0;//_00E711F8
	short f_a2;//_00E711FA
};

struct t_chocobo_cameraInfo {//size 0x14
	/*00*/char bType;
	/*01*/char f_01;
	/*02*/short f_02;
	/*04*/struct SVECTOR f_04;
	/*0c*/struct SVECTOR f_0c;
};

struct t_chocobo_local_1c {//size 0x1c
	/*00*/struct t_dx_sfx_e0 *f_00;//_00E72990
	/*04*/char __04[8];//_00E72994
	/*0c*/int f_0c;//flag[parallell quad]?//_00E7299C
	/*10*/int f_10;//_00E729A0
	/*14*/int f_14;//_00E729A4
	/*18*/int dwIsTransparent;//_00E729A8
};

struct t_chocobo_48 {//size 0x48
	/*00*/int f_00;//index to D_00E72990//00E3B758
	/*04*/tRGBA f_04;//00E3B75C
	/*08*/unsigned short wU,wV;//00E3B760,00E3B762
	/*0c*/float fU,fV;//00E3B764,00E3B768
	/*14*/struct {
		unsigned short wX,wY;
	}f_14[4];
	/*24*/float fZ;//00E3B77C
	/*28*/int dwWidth,dwHeight;//00E3B780,00E3B784
	/*30*/int f_30;//0x20000(flip)|0x10000(flip)|palette?
	/*34*/float fTexWidth,fTexHeight;
	/*3c*/float fWidth,fHeight;
	/*44*/int f_44;
};

struct t_chocobo_unknown_54 {//size 0x54
	tRGBA f_00;
	struct {
		unsigned short wX,wY;
	}f_04[4];
	struct {
		float fU,fV;
	}f_14[4];
	/*34*/float fZ;
	/*38*/int f_38,f_3c;
	/*40*/int f_40;//palette?
	/*44*/int dwIsTransparent;
	/*48*/struct t_dx_sfx_e0 *f_48;
	/*4c*/int f_4c;
	/*50*/int f_50;
};

struct t_chocobo_local_10_xxx {
	short f_00,f_02,f_04;
	/*06*/short wFlags;
	/*08*/short wAnimtionIncr;
	/*0a*/short wAnimationFrame;
	unsigned char f_0c,f_0d,f_0e;//rotation?
	unsigned char f_0f;
};

struct t_chocobo_data_GUIDE {//size 8
	unsigned char f_00[4];
	char f_04[4];
};

struct t_chocobo_data_SPRITE {//size 0x16
	/*00*/struct SVECTOR f_00;
	/*08*/short __08;//always 0x0026?
	/*0a*/short wWidth,wHeight;
	/*0e*/short __0e,__10,__12,__14;//(__0e - __12) is always 0x1e or -0x20?(__10 - __14) is always 0x1f or -0x1f?
};

struct t_chocobo_data_SoundEventInfo {//size 0x10
	/*00*/short f_00;
	/*02*/unsigned short f_02[6];
	/*0e*/char __0e[2];
};

struct t_chocobo_TrackInfo {//size 0x54
	/*00*/int f_00;//#obj in f_08/pGUIDE
	/*04*/int f_04;//track length?
	/*09*/struct t_chocobo_data_18 *f_08;
	//-- --
	/*0c*/int dwNumDG4;
	/*10*/struct t_chocobo_data_DG4 *pDG4;
	//-- --
	/*14*/int dwNumDG3;
	/*18*/struct t_chocobo_data_DG3 *pDG3;
	//-- --
	/*1c*/short *pMAPPOINTER;
	/*20*/int *pMAPTABLE;
	//-- --
	/*24*/short wNumDOMEG3; char __26[2];
	/*28*/struct t_chocobo_data_DOMEG3 *pDOMEG3;
	//-- --
	/*2c*/short wNumSPRITE; char __2e[2];
	/*30*/struct t_chocobo_data_SPRITE *pSPRITE;
	//-- --
	/*34*/struct t_chocobo_data_GUIDE *pGUIDE;
	/*38*/struct t_chocobo_cameraInfo *f_38;
	/*3c*/int f_3c;
	/*40*/struct t_chocobo_local_10_xxx *f_40;
	/*44*/struct t_chocobo_data_SoundEventInfo *pSoundEvent;
	/*48*/struct t_chocobo_data_floatDG3 *pFloatDOMEG3;
	/*4c*/struct t_chocobo_data_floatDG3 *pFloatDG3;
	/*50*/struct t_chocobo_data_floatDG4 *pFloatDG4;
};

//aka struct t_chocobo_unknown_2 {
struct t_chocobo_3c {//size 0x3c
	/*00*/short f_00,f_02,f_04;//pos
	/*06*/unsigned char f_06,f_07,f_08;//color
	/*09*/unsigned char f_09,f_0a,f_0b;//rot
	/*0c*/short f_0c;
	/*0e*/char __0e[2];
	/*10*/char f_10;//some index?
	/*11*/char __11[1];
	/*12*/unsigned short wMaxAnmNum;//# elements in f_38
	/*14*/int dwMaxAnimationFrame,dwAnimationFrame;
	/*1c*/int dwIsTransparent;
	/*20*/int f_20;//a flag?
	/*24*/int f_24;//a flag(LH/RH)?
	/*28*/int f_28;//a flag(active)?
	/*2c*/int dwAdjustYPos;
	/*30*/unsigned short wAnmNum,wPrevAnmNum;
	/*34*/struct t_plytopd_e4 *f_34;
	/*38*/struct t_animationHeader **f_38;
};

struct t_chocobo_data_18 {//size 0x18
	/*00*/struct SVECTOR f_00;
	/*08*/struct SVECTOR f_08;
	/*10*/char f_10;
	/*11*/char f_11;
	/*12*/unsigned char f_12;
	/*13*/char f_13;
	/*14*/tRGBA f_14;
};

struct t_chocobo_data_DOMEG3 {//size 0x24
	struct SVECTOR f_00;
	struct SVECTOR f_08;
	struct SVECTOR f_10;
	unsigned f_18;
	unsigned f_1c;
	unsigned f_20;
};

struct t_chocobo_data_DG3 {//size 0x1c
	struct SVECTOR f_00;
	struct SVECTOR f_08;
	struct SVECTOR f_10;
	tRGBA f_18;
};

struct t_chocobo_data_DG4 {//size 0x28
	struct SVECTOR f_00;
	struct SVECTOR f_08;
	struct SVECTOR f_10;
	struct SVECTOR f_18;
	tRGBA f_20;
	tRGBA f_24;
};

struct t_chocobo_data_floatDG3 {//size 0x30
	struct t_g_drv_0c f_00;
	struct t_g_drv_0c f_0c;
	struct t_g_drv_0c f_18;
	tRGBA f_24;
	tRGBA f_28;
	tRGBA f_2c;
};

struct t_chocobo_data_floatDG4 {//size 0x40
	struct t_g_drv_0c f_00;
	struct t_g_drv_0c f_0c;
	struct t_g_drv_0c f_18;
	struct t_g_drv_0c f_24;
	tRGBA f_30;
	tRGBA f_34;
	tRGBA f_38;
	tRGBA f_3c;
};

struct t_chocobo_ranking_8 {
	short f_00;//0E71068
	char f_02;//0E7106A
	char f_03;//0E7106B
	char f_04;//0E7106C
	char f_05;//0E7106D
	unsigned char f_06;//0E7106E
	char f_07;//0E7106F
};
////////////////////////////////////////
extern int D_00972174;

extern char D_00E3B640[];
extern int D_00E3B740;
extern int D_00E3B744;
extern int D_00E3B74C;//long/short courseflag
extern void *D_00E3B754;
extern struct t_chocobo_48 D_00E3B758[/*6*/];
extern char *D_00E3BA28;
extern struct tScreenInfo D_00E3BA68;
extern int D_00E3BA94;
extern int D_00E71100;//previous input mask
extern int D_00E71104;
extern int D_00E71108;
extern int D_00E71124;
extern int D_00E71128;
extern struct t_chocobo_TrackInfo *D_00E7112C;
extern struct t_chocobo_a4 D_00E71158[/*6*/];
extern struct t_chocobo_a4 D_00E71530;
//-- C_0076DDF0.cpp[input] --
extern unsigned D_00E71620;
extern int D_00E71624;
//extern int D_00E71628[/*15*/];
//-- --
extern struct t_sound_related_24 *D_00E71664;
extern struct t_chocobo_3c *D_00E719E8;
extern unsigned short D_00E719EC;
extern unsigned short D_00E719EE;
extern struct t_chocobo_local_1c D_00E71BD4;
extern struct t_chocobo_local_1c D_00E71BF0;
extern struct t_chocobo_local_1c D_00E71C0C;
extern struct t_chocobo_local_1c D_00E71C28;
extern struct t_chocobo_local_1c D_00E71C44;
extern struct t_chocobo_unknown_54 D_00E71C60[];
extern struct t_chocobo_local_1c D_00E72990[];
extern int D_00E72E0C;
extern D3DMATRIX D_00E72E18;
extern D3DMATRIX D_00E72E60;
extern LPDIRECTDRAW D_00E73C20;
extern LPDIRECTDRAWSURFACE D_00E73C24;
extern struct MATRIX D_00E73DB0;
////////////////////////////////////////
extern void C_0076B850(const char *path);//chocobo:set path
extern void C_0076B87E(void);
extern void C_0076BA66(void);
extern void C_0076BAFD(struct t_aa0 *, struct t_rsd_74 *);
extern void C_0076D320(int, int);//ch_app:...
extern void C_0076DC5B(struct t_aa0 *);
extern void C_0076DCBF(int, int);
extern void C_0076DDD6(struct t_aa0 *);//<empty>
extern void C_0076DDF0(void);//chobobo.input.reset?
extern void C_0076DF8C(void);//chocobo:refresh input
extern void C_0076E149(void);//chocobo:compute input mask
extern struct t_chocobo_data_SoundEventInfo *C_0076E1F0(int);//chocobo:get sounds info?
extern void C_0076E22F(void);//chocobo:load/prepare SFX
extern void C_0076E26C(void);//chocobo:free SFX
extern void C_0076E2B0(void);//refresh race 2D stuff
extern void C_0076EEB9(void);
extern int C_0076EFF0(void);//ch_chr:clean(1)?
extern int C_0076F1B0(struct t_rsd_74 *, struct t_aa0 *, int);//ch_chr:init(1)?
extern void C_0076F920(struct t_rsd_74 *, struct t_aa0 *, int);//ch_chr:init(2)?
extern void C_0076FD68(void);//ch_chr:clean(2)?
extern void C_0076FDD3(void);//ch_chr:reset?
extern void C_0076FE41(struct t_aa0 *);//ch_chr:render(solid)?
extern void C_0076FECC(struct t_aa0 *);//ch_chr:render(transparent)?
extern void C_0076FF60(struct t_aa0 *, struct t_rsd_74 *);//chocobo:init this module
extern void C_007700D9(void);//chocobo:clean this module
extern void C_00770159(void);//chocobo:render this module
extern void C_00770206(void);//render skydome
extern void C_00770291(void);//render track?
extern void C_00770800(struct t_aa0 *, struct t_rsd_74 *, int, int);
extern void C_007714E9(void);
extern void C_007715A4(void);//[reset this module]
extern struct t_chocobo_local_10_xxx *C_00771660(int);
extern struct t_chocobo_cameraInfo *C_00771680(int);
extern void C_00771697(short, short);//chocobo:set camera info?
extern void C_007718B0(void);//chocobo:refresh camera?
extern void C_007722F6(short);//set animation increment?
extern int C_00772340(int);
extern void C_00772357(void);
extern void C_00773668(void);
extern void C_0077554D(int);
extern void C_007757CE(int, int, int);
extern void C_00776375(void);
extern void C_00776452(void);//refresh "bet menu"
extern void C_00776B8C(unsigned, int, int);//render integer(callback)[LORES]
extern void C_00776D2B(unsigned, int, int);//render integer(callback)[HIRES]
extern void C_00778A3C(void);
extern void C_00778C5D(void);//refresh "bet results"
extern void C_0077946A(void);//refresh fade in/out
extern void C_007794F0(struct t_aa0 *);//ch_ddraw:init
extern int C_00779585(struct t_aa0 *);//ch_ddraw:init(2)
extern void C_00779850(void);
extern void C_00779E14(struct t_aa0 *);
extern struct t_animationHeader *C_0077A150(struct t_rsd_74 *, const char *);
extern struct t_plytopd_e4 *C_0077A2E9(int, struct t_animationHeader *, struct t_rsd_74 *, struct t_aa0 *, const char *, const char *);
extern int C_0077A339(struct t_chocobo_3c *, int);//set animation #
extern void C_0077A3A2(struct t_chocobo_48 *);
extern void C_0077A469(struct t_chocobo_48 *);//draw sprite?
extern void C_0077A7D0(struct t_chocobo_48 *);//draw a color rectangle?
extern void C_0077A89F(struct t_chocobo_48 *);
extern void C_0077AC35(struct t_chocobo_48 *);
extern void C_0077AD89(struct t_chocobo_unknown_54 *);
extern void C_0077B1CE(struct t_chocobo_48 *);
extern void C_0077B2CA(void);//chocobo:renderer?
extern void C_0077B7E2(struct t_chocobo_3c *);//refresh rotation[3D model]?
extern void C_0077B9A9(struct t_aa0 *);
extern void C_0077BB50(LPD3DMATRIX, struct t_dx_sfx_e0 *, struct t_chocobo_data_floatDG3 *);//render triangle?
extern void C_0077BE95(LPD3DMATRIX, struct t_dx_sfx_e0 *, struct t_chocobo_data_floatDG4 *);//render quad?
extern float C_0077C2AC(struct SVECTOR *, LPD3DMATRIX);
extern void C_0077C430(struct t_aa0 *, struct t_rsd_74 *);
extern void C_0077C462(void);//chocobo:refresh
extern short C_0077CF40(short, short);
extern short C_0077CFBF(struct SVECTOR *, struct SVECTOR *);
////////////////////////////////////////

#endif

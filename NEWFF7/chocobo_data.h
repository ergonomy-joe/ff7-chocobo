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
struct t_chocobo_ChocoboInfo {//size 0xa4
	/*00*/short wPathT_cur;//00E71158
	/*02*/short wPathT_next;//00E7115A
	/*04*/short wSpeed;//00E7115C
	/*06*/short wType;//00E7115E
	/*08*/struct SVECTOR sPos_prev;//(only y used)
	/*10*/struct SVECTOR sPos_cur;
	/*18*/struct VECTOR vSpeed_dec;
	/*28*/struct SVECTOR sPos_next;
	/*30*/struct SVECTOR sRot_cur;
	/*38*/struct SVECTOR sRot_next;
	/*40*/struct SVECTOR sPos_orig;//for finish line
	/*48*/short f_48;//_00E711A0
	/*4a*/short f_4a;//set but not used?//_00E711A2
	/*4c*/short f_4c;//_00E711A4
	/*4e*/short f_4e;//_00E711A6
	/*50*/short f_50;//always 0[never set]?//_00E711A8
	/*52*/short f_52;//index in pGUIDE//_00E711AA
	/*54*/short f_54;//_00E711AC
	/*56*/short f_56;//_00E711AE
	/*58*/short wTopSpeed;//_00E711B0
	/*5a*/short wAcceleration;//_00E711B2
	/*5c*/short f_5c;//set, not used?//_00E711B4
	/*5e*/short f_5e;//_00E711B6
	/*60*/short wIsAutomatic;//_00E711B8
	/*62*/short f_62;//docility?//_00E711BA
	/*64*/short f_64;//_00E711BC
	/*66*/short f_66;//_00E711BE
	/*68*/int dwStamina,dwMaxStamina;//_00E711C0/_00E711C4
	/*70*/short wPosition;//in race//_00E711C8
	/*72*/short wAnimationCounter;//_00E711CA
	/*74*/short f_74;//unused animation counter//_00E711CC
	/*76*/short wAnimationCounterIncr;//_00E711CE
	/*78*/short wPrevAnimationId;//_00E711D0
	/*7a*/char __7a[2];
	/*7c*/short f_7c;//xpos on track?//_00E711D4
	/*7e*/short wFinished;//_00E711D6
	/*80*/short wAnimationId;//_00E711D8
	/*82*/short wRankPos;//_00E711DA
	/*84*/short f_84;//_00E711DC
	/*86*/short wTerrainMask;//_00E711DE
	/*88*/unsigned char aName[8];//_00E711E0
	/*90*/short wChocoboId,wJockeyId;//_00E711E8,_00E711EA
	/*94*/short wSFXCounter;//counter to next noise//_00E711EC
	/*96*/short f_96;//original struct t_chocobo_ChocoboInfo::f_7c//_00E711EE
	/*98*/short wLastSprint;//_00E711F0
	/*9a*/short f_9a;//flag:some special ability?//_00E711F2
	/*9c*/short f_9c;//[unused]flag:some special ability?//_00E711F4
	/*9e*/short f_9e;//[unused]set to 0//_00E711F6
	/*a0*/short f_a0;//flag:some special ability?//_00E711F8
	/*a2*/short f_a2;//flag:some special ability?//_00E711FA
};

struct t_chocobo_cameraInfo {//size 0x14
	/*00*/char bType;
	/*01*/char bParam;//(bType 1/2)
	/*02*/short wHeight;//(bType 2)
	/*04*/struct SVECTOR sPos;//.f_06 may hold extra info
	/*0c*/struct SVECTOR sLookAt;//.f_06 may hold extra info//(bType 1)
};

//"renderer" for polygon?
struct t_chocobo_local_1c {//size 0x1c
	/*00*/struct t_dx_sfx_e0 *f_00;//_00E72990
	/*04*/char __04[8];//_00E72994
	/*0c*/int f_0c;//flag for rendering method?//_00E7299C
	/*10*/int dwActive;//_00E729A0
	/*14*/int dwDoRender;//_00E729A4
	/*18*/int dwIsTransparent;//_00E729A8
};

struct t_chocobo_SpriteUI {//size 0x48
	/*00*/int dwRenderId;//index to D_00E72990[]//00E3B758
	/*04*/tRGBA f_04;//00E3B75C
	/*08*/unsigned short wU,wV;//00E3B760,00E3B762
	/*0c*/float fU,fV;//00E3B764,00E3B768
	/*14*/unsigned short wX0,wY0;
	/*18*/unsigned short wX1,wY1;
	/*1c*/unsigned short wX2,wY2;
	/*20*/unsigned short wX3,wY3;
	/*24*/float fZ;//00E3B77C
	/*28*/int dwWidth,dwHeight;//00E3B780,00E3B784
	/*30*/int dwPalette;//0x20000(flip)|0x10000(flip)|palette?
	/*34*/float fTexWidth,fTexHeight;
	/*3c*/float fWidth,fHeight;
	/*44*/int f_44;//flag/set but unused?
};

struct t_chocobo_SpriteBillboard {//size 0x54
	/*00*/tRGBA f_00;
	/*04*/unsigned short wX0,wY0;
	/*08*/unsigned short wX1,wY1;
	/*0c*/unsigned short wX2,wY2;
	/*10*/unsigned short wX3,wY3;
	/*14*/float fU0,fV0;
	/*1c*/float fU1,fV1;
	/*24*/float fU2,fV2;
	/*2c*/float fU3,fV3;
	/*34*/float fZ;
	/*38*/int dwWidth,dwHeight;//set but never read
	/*40*/int f_40;//palette?
	/*44*/int dwIsTransparent;
	/*48*/struct t_dx_sfx_e0 *f_48;
	/*4c*/int dwActive;
	/*50*/int dwDoRender;
};

//data to initialize "struct t_chocobo_Model3D"
//(sPos.f_06 contains flags)
struct t_chocobo_data_ScenaryModelInfo {//size 0x10
	/*00*/struct SVECTOR sPos;
	/*08*/short wAnimationIncr;
	/*0a*/short wAnimationFrame;
	/*0c*/unsigned char bRotX,bRotY,bRotZ;
	/*0f*/unsigned char bModelId;//index in D_00E719E8[]
};

struct t_chocobo_data_GUIDE {//size 8
	/*00*/unsigned char f_00[4];
	/*04*/char f_04[4];
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

//sVect_Left.f_06 has animation info
//sVect_Right.f_06 has sfx info
struct t_chocobo_data_TrackElement {//size 0x18
	/*00*/struct SVECTOR sVect_Left,sVect_Right;
	/*10*/char bCameraEvent;
	/*11*/char f_11;//(index + 1) in struct t_chocobo_TrackInfo::pScenaryModel
	/*12*/unsigned char bCullDistance;
	/*13*/char bTerrainFlags;//speed related
	/*14*/tRGBA f_14;
};

//looks like struct "t_coaster_Triangle"
struct t_chocobo_data_DOMEG3 {//size 0x24
	/*00*/struct SVECTOR svect0,svect1,svect2;
	/*18*/tRGBA color0,color1,color2;
};

struct t_chocobo_data_DG3 {//size 0x1c
	/*00*/struct SVECTOR svect0,svect1,svect2;
	/*18*/tRGBA color0;
	//color1 and color2 are "hidden" in svect0.pad, svect1.pad, svect2.pad
};

//same size as "struct t_coaster_Quad"
struct t_chocobo_data_DG4 {//size 0x28
	/*00*/struct SVECTOR svect0,svect1,svect2,svect3;
	/*20*/tRGBA color0,color1;
	//color2 and color3 are "hidden" in svect1.pad, svect2.pad, svect3.pad, color0.c.a
};

struct t_chocobo_data_floatDG3 {//size 0x30
	/*00*/D3DVECTOR fvect0,fvect1,fvect2;
	/*24*/tBGRA color0,color1,color2;
};

struct t_chocobo_data_floatDG4 {//size 0x40
	/*00*/D3DVECTOR fvect0,fvect1,fvect2,fvect3;
	/*30*/tBGRA color0,color1,color2,color3;
};

struct t_chocobo_TrackInfo {//size 0x54
	/*00*/int dwTrackLength;//# elements in pTrackElement/pGUIDE
	/*04*/int dwLastSprintPoint;
	/*08*/struct t_chocobo_data_TrackElement *pTrackElement;
	//-- --
	/*0c*/int dwCountDG4;
	/*10*/struct t_chocobo_data_DG4 *pDG4;
	//-- --
	/*14*/int dwCountDG3;
	/*18*/struct t_chocobo_data_DG3 *pDG3;
	//-- --
	/*1c*/short *pMAPPOINTER;
	/*20*/int *pMAPTABLE;
	//-- --
	/*24*/short wCountDOMEG3; char __26[2];
	/*28*/struct t_chocobo_data_DOMEG3 *pDOMEG3;
	//-- --
	/*2c*/short wCountSPRITE; char __2e[2];
	/*30*/struct t_chocobo_data_SPRITE *pSPRITE;
	//-- --
	/*34*/struct t_chocobo_data_GUIDE *pGUIDE;
	/*38*/struct t_chocobo_cameraInfo *pCameraInfo;
	/*3c*/int dwScenaryModelCount;//set but not used
	/*40*/struct t_chocobo_data_ScenaryModelInfo *pScenaryModel;
	/*44*/struct t_chocobo_data_SoundEventInfo *pSoundEvent;
	/*48*/struct t_chocobo_data_floatDG3 *pFloatDOMEG3;
	/*4c*/struct t_chocobo_data_floatDG3 *pFloatDG3;
	/*50*/struct t_chocobo_data_floatDG4 *pFloatDG4;
};

struct t_chocobo_Model3D {//size 0x3c
	/*00*/short wX,wY,wZ;//pos
	/*06*/unsigned char bR,bG,bB;//color
	/*09*/unsigned char bRotX,bRotY,bRotZ;//rot
	/*0c*/short wScaling;
	/*0e*/char __0e[2];
	/*10*/char f_10;//index in D_0096FA80[]/D_0096FB78[](set/not used)?
	/*11*/char __11;
	/*12*/unsigned short wAnimationCount;//# elements in ppANM
	/*14*/int dwMaxAnimationFrame,dwAnimationFrame;
	/*1c*/int dwIsTransparent;
	/*20*/int dwDoRender;
	/*24*/int dwPatchRotY;
	/*28*/int dwActive;
	/*2c*/int dwAdjustYPos;
	/*30*/unsigned short wAnimationId,wPrevAnimationId;
	/*34*/struct t_plytopd_e4 *pHRC;
	/*38*/struct t_animationHeader **ppANM;
};

struct t_chocobo_Ranking {//size 8
	/*00*/short wState;//0E71068
	/*02*/char bCounter;//0E7106A
	/*03*/char bDisplayPrize;//0E7106B
	/*04*/char bCurrentSide;//0E7106C
	/*05*/char bFlipAction;//0E7106D
	/*06*/unsigned char bPrizeId;//0E7106E
	/*07*/char bPrizeIndex;//{0,1,2}//0E7106F
};
////////////////////////////////////////
extern int D_00972174;//{devel,fs}/{release,archive} flag

extern char D_00E3B640[/*256*/];
extern int D_00E3B740;
extern int D_00E3B744;
extern int D_00E3B74C;//flag:long/short course
extern void *D_00E3B754;
extern struct t_chocobo_SpriteUI D_00E3B758[/*0xa*/];//squares for map
	//[0~5]squares for map
	//[6]transparent color layer[underwater effect]
	//[7]map
	//[8]for stamina gauge
	//[9]for stamina gauge
extern char *D_00E3BA28;
extern struct tScreenInfo D_00E3BA68;
extern int D_00E3BA94;

extern struct t_chocobo_SpriteUI *D_00E3BA9C[8];
	//[0]
	//[1]
	//[2]for "bet menu"
	//[3]for "bet results"
	//[4]
	//[5]
	//[6][crown #1]/[crown #2]
	//[7][manual]/[automatic]

extern int D_00E3BAF4;//camera height[bType -1]?
extern int D_00E70FE8;//camera related:render last track[culling]
extern int D_00E71018;//frame counter
extern unsigned D_00E71100;//previous input mask
extern int D_00E71104;
extern int D_00E71108;//# polygons rendered(stat)?
extern int D_00E71124;//camera related:render first track[culling]
extern int D_00E71128;
extern struct t_chocobo_TrackInfo *D_00E7112C;
extern struct t_chocobo_ChocoboInfo D_00E71158[/*7*/];
	#define TARGET_CHOCOBO (D_00E71158[D_00E71624])
	//(for camera)
	#define TRACKER_CHOCOBO (D_00E71158[6])
//-- C_0076DDF0.cpp[input] --
extern unsigned D_00E71620;//input mask
extern int D_00E71624;//1st/tracked chocobo
//extern int D_00E71628[/*15*/];
//-- --
extern struct t_sound_related_24 *D_00E71664;
extern struct t_chocobo_Model3D *D_00E719E8;
	extern unsigned short D_00E719EC;//models count
	extern unsigned short D_00E719EE;//[set|not used]
extern struct t_chocobo_local_1c D_00E71BD4[/*5*/];
	//[0]renderer for skydome
	//[1]renderer for solid quad
	//[2]renderer for transparent quad
	//[3]renderer for solid triangle
	//[4]renderer for transparent triangle
extern struct t_chocobo_SpriteBillboard D_00E71C60[/*0x28*/];//3D sprite/billboard
//-- C_00770800.cpp --
extern struct t_chocobo_local_1c D_00E72990[/*0x28*/];//renderers for UI?
extern struct t_chocobo_local_1c D_00E72DF0;//[for SW patch]
//-- C_00771680.cpp --
extern D3DMATRIX D_00E72E18;//transformation matrix[for animated models]?
extern D3DMATRIX D_00E72E60;//transformation x perspective[for static models]?
//-- ch_ddraw.cpp --
extern LPDIRECTDRAW D_00E73C20;
extern LPDIRECTDRAWSURFACE D_00E73C24;
//-- C_00779C90.cpp --
extern struct MATRIX D_00E73DB0;
////////////////////////////////////////
//-- ch_init.cpp --
extern void C_0076B850(const char *path);//chocobo:set path
extern void C_0076B87E(void);//ch_init:...
extern void C_0076BA66(void);//ch_init:reset snd channels?
extern void C_0076BAFD(struct t_aa0 *, struct t_rsd_74 *);//ch_init:...
//-- ch_app.cpp --
extern void C_0076D320(int, int);//ch_app:set screen info
extern void C_0076DC5B(struct t_aa0 *);//ch_app:similar to "chocobo[UPDATE][callback]"
extern void C_0076DCBF(int, int);//ch_app:unused init?
extern void C_0076DDD6(struct t_aa0 *);//ch_app:debug<empty>?
//-- C_0076DDF0.cpp --
extern void C_0076DDF0(void);//chobobo:input.reset
extern void C_0076DF8C(void);//chocobo:input.refresh
extern void C_0076E149(void);//chocobo:input.compute_mask
//-- C_0076E1F0.cpp --
extern struct t_chocobo_data_SoundEventInfo *C_0076E1F0(int);//chocobo:get sounds info
extern void C_0076E22F(void);//chocobo:load/prepare SFX
extern void C_0076E26C(void);//chocobo:free SFX
//-- C_0076E2B0.cpp --
extern void C_0076E2B0(void);//chocobo:refresh race 2D stuff
extern void C_0076EEB9(void);//chocobo:set chocobos'palette
//-- ch_chr.cpp --
extern int C_0076EFF0(void);//ch_chr:clean(1)?
extern int C_0076F1B0(struct t_rsd_74 *, struct t_aa0 *, int);//ch_chr:init(1)?
extern void C_0076F920(struct t_rsd_74 *, struct t_aa0 *, int);//ch_chr:init(2)?
extern void C_0076FD68(void);//ch_chr:clean(2)?
extern void C_0076FDD3(void);//ch_chr:reset
extern void C_0076FE41(struct t_aa0 *);//ch_chr:render(solid)?
extern void C_0076FECC(struct t_aa0 *);//ch_chr:render(transparent)?
//-- C_0076FF60.cpp --
extern void C_0076FF60(struct t_aa0 *, struct t_rsd_74 *);//chocobo:terrain/scenery.init
extern void C_007700D9(void);//chocobo:terrain/scenery.clean
extern void C_00770159(void);//chocobo:terrain/scenery.reset
extern void C_00770206(void);//chocobo:render skydome
extern void C_00770291(void);//chocobo:render track/scenery
//-- C_00770800.cpp --
extern void C_00770800(struct t_aa0 *, struct t_rsd_74 *, int, int);//chocobo:2D elements.init
extern void C_007714E9(void);//chocobo:2D elements.clean
extern void C_007715A4(void);//chocobo:2D elements.reset
//-- C_00771660.cpp --
extern struct t_chocobo_data_ScenaryModelInfo *C_00771660(int);//chocobo:get scenery models array?
//-- C_00771680.cpp --
extern struct t_chocobo_cameraInfo *C_00771680(int);//chocobo:get camera info array
extern void C_00771697(short, short);//chocobo:set camera event
extern void C_007718B0(void);//chocobo:refresh camera?
extern void C_007722F6(short);//chocobo:set animation event?
//-- C_00772340.cpp --
extern int C_00772340(int);//chocobo:get track's "last sprint" point?
extern void C_00772357(void);//chocobo:init 6 chocobos info?
extern void C_00773668(void);//chocobo:refresh 6 chocobos info?
extern void C_0077554D(int);//chocobo:for camera:track chocobo?
extern void C_007757CE(int, int, int);//chocobo:for camera(bType 2):track chocobo?
//-- C_00776370.cpp --
extern void C_00776375(void);//chocobo:before "bet menu"
extern void C_00776452(void);//chocobo:refresh "bet menu"
extern void C_00776B8C(unsigned, int, int);//chocobo:draw integer(callback)[LORES]
extern void C_00776D2B(unsigned, int, int);//chocobo:draw integer(callback)[HIRES]
extern void C_00778A3C(void);//chocobo:before "bet results"
extern void C_00778C5D(void);//chocobo:refresh "bet results"
extern void C_0077946A(void);//chocobo:refresh fade in/out
//-- ch_ddraw.cpp --
extern void C_007794F0(struct t_aa0 *);//ch_ddraw:init
extern int C_00779585(struct t_aa0 *);//ch_ddraw:init(2)
//-- C_00779850.cpp --
extern void C_00779850(void);//chocobo:init palettes[unused]
//-- C_00779C90.cpp --
extern void C_00779E14(struct t_aa0 *);//chocobo:reset+tempo+frameskip
extern struct t_animationHeader *C_0077A150(struct t_rsd_74 *, const char *);//chocobo:load ".anm" file(renamed ".a")?
extern struct t_plytopd_e4 *C_0077A2E9(int, struct t_animationHeader *, struct t_rsd_74 *, struct t_aa0 *, const char *, const char *);//chocobo:load ".HRC" file?
extern int C_0077A339(struct t_chocobo_Model3D *, int);//chocobo:set animation id
extern void C_0077A3A2(struct t_chocobo_SpriteUI *);//chocobo:draw quad[background]
extern void C_0077A469(struct t_chocobo_SpriteUI *);//chocobo:draw sprite[UI]
extern void C_0077A7D0(struct t_chocobo_SpriteUI *);//chocobo:draw quad[plain color]
extern void C_0077A89F(struct t_chocobo_SpriteUI *);//chocobo:draw sprite[bet square]
extern void C_0077AC35(struct t_chocobo_SpriteUI *);//chocobo:[for sw patch]
extern void C_0077AD89(struct t_chocobo_SpriteBillboard *);//chocobo:draw sprite[billboard]
extern void C_0077B1CE(struct t_chocobo_SpriteUI *);//chocobo:draw quad[for fade in/out]
extern void C_0077B2CA(void);//chocobo:renderer?
extern void C_0077B7E2(struct t_chocobo_Model3D *);//chocobo:refresh position/rotation[3D model]?
extern void C_0077B9A9(struct t_aa0 *);//chocobo:set transformation matrix[3D models]?
extern void C_0077BB50(LPD3DMATRIX, struct t_dx_sfx_e0 *, struct t_chocobo_data_floatDG3 *);//chocobo:draw triangle[3D]
extern void C_0077BE95(LPD3DMATRIX, struct t_dx_sfx_e0 *, struct t_chocobo_data_floatDG4 *);//chocobo:draw quad[3D]
extern float C_0077C2AC(struct SVECTOR *, LPD3DMATRIX);//chocobo:projected Z?
extern void C_0077C430(struct t_aa0 *, struct t_rsd_74 *);//chocobo:init
extern void C_0077C462(void);//chocobo:refresh
//-- C_0077CF40.cpp --
extern short C_0077CF40(short, short);//chocobo:atan2?
extern short C_0077CFBF(struct SVECTOR *, struct SVECTOR *);//chocobo:make dir angle?
////////////////////////////////////////

#endif

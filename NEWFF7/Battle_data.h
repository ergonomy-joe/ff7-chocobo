#ifndef __Battle_data_h__
#define __Battle_data_h__

//for "struct t_menu_temp_1c" definition
//for "struct t_battle_menuEntryInfo" definition
#include "menu_data.h"
////////////////////////////////////////
#define STATIC_INIT(t, a, func, tmp) \
	if(!(tmp & 1)) {\
		tmp |= 1; \
		a = (t)func; \
	}
////////////////////////////////////////
#define RAND_RANGE(mn, mx) ((0)?(mx):(rand() % ((mx) - (mn)) + (mn)))
////////////////////////////////////////
//unused stuff(remains from psx)?
struct t_battle_40f4 {//size 0x40f4
	char __0000[0x70];
	//-- --
	char f_0070[0x1000 * 4];//0xc
	char f_4070[2 * 4];//1
	char f_4078[2 * 4];//1
	char __4080[4];
	char f_4084[8 * 4];//3
	char f_40a4[0x10 * 4];//4
	char f_40e4[4 * 4];//2?
};

//for riva only?
struct t_battle_dontKnowYet {
	/*00*/unsigned char *f_00;
	/*04*/int f_04;
	/*08*/char __08[2];
	/*0a*/short f_0a;
	/*0c*/short f_0c;
	/*0e*/char __0e[2];
	/*10*/void *f_10;
};

struct t_battle_temp_test_1 {//size 0x10?
	/*00*/struct t_rsd_0c *f_00;//struct t_dx_sfx_e0 *f_00;
	/*04*/int f_04;
	/*08*/short f_08;
	/*0a*/short f_0a;
	/*0c*/short f_0c;
	/*0e*/short f_0e;
};

struct t_battle_temp_hitmark {//size 0x10
	/*00*/struct t_shp_30 *f_00;
	/*04*/struct t_dx_sfx_e0 *f_04;
	/*08*/unsigned char f_08,f_09,f_0a,f_0b;//r0,g0,b0,code
	/*0c*/unsigned short f_0c;//current animation frame in shape?
	/*0e*/unsigned short f_0e;//clut?
};

#define t_battle_temp_hitmark_init(ss,a,b,c,d,e,f) \
	(ss).f_00 = a; (ss).f_04 = b; \
	(ss).f_08 = c; \
	(ss).f_09 = d; \
	(ss).f_0a = e; \
	(ss).f_0b = f; \
	memset(&(ss).f_0c, 0, 4)

#define t_battle_temp_hitmark_init_bis(ss,a,b,c,d,e,f,g) \
	(ss).f_00 = a; \
	(ss).f_04 = b; \
	(ss).f_08 = c; (ss).f_09 = d; (ss).f_0a = e; \
	(ss).f_0b = f; \
	(ss).f_0c = g; \
	memset(&((ss).f_0e), 0, 2)

struct t_battle_temp_must_move {//size 0x14?
	/*00*/short f_00,f_02;//x,y
	/*04*/unsigned char f_04,f_05;//texX,texY
	/*06*/unsigned char f_06,f_07;//width,height
	/*08*/unsigned char f_08,f_09,f_0a,f_0b;//r0,g0,b0,code
	/*0c*/short f_0c;
	/*0e*/short f_0e;//clut?
	/*10*/struct t_dx_sfx_e0 *f_10;
};

#define t_battle_temp_must_move_init(ss,a,b,c,d,e,f,g,h,i,j,k,l) \
	(ss).f_00 = a; (ss).f_02 = b; \
	(ss).f_04 = c; (ss).f_05 = d; \
	(ss).f_06 = e; (ss).f_07 = f; \
	(ss).f_08 = g; (ss).f_09 = h; (ss).f_0a = i; \
	(ss).f_0b = j; \
	(ss).f_0c = k; \
	(ss).f_0e = l; \
	memset(&((ss).f_10), 0, 4)

//item info
struct t_battle_menu_06_B {//size 6
	/*00*/unsigned short f_00;//item type
	/*02*/unsigned char f_02;//quantity
	/*03*/unsigned char bTargetFlags;
	/*04*/unsigned char f_04;//restriction flags
	/*05*/char __05[1];
};

struct t_battle_local_6_JJJJ {//size 6
	/*00*/short wStringId;
	/*02*/short wSFX;
	/*04*/unsigned char bDelay;
	/*05*/unsigned char bCount;
};

struct t_battle_cam_0e {//size 0xe
	/*00*/struct SVECTOR f_00;
	/*08*/unsigned short f_08;//script index?
	/*0a*/unsigned short f_0a;
	/*0c*/unsigned char f_0c;
	/*0d*/unsigned char f_0d;
};

struct t_unk_0c_1 {//size 0xc
	/*00*/char bSourceId;//009AAD70
	/*01*/char f_01;//009AAD71
	/*02*/unsigned char f_02;//009AAD72
	/*03*/char f_03;//009AAD73
	/*04*/char f_04;//009AAD74
	/*05*/char f_05;//009AAD75
	/*06*/short f_06;//009AAD76
	/*08*/short wCamScript;//009AAD78
	/*0a*/short wLink;//to D_009ACB98[]//009AAD7A
};

struct t_battle_graphicalDamage_0e {//size 0xe
	/*00*/short f_00;//009ABA08
	/*02*/short wDamage;//009ABA0A
	/*04*/short f_04;//009ABA0C
	/*06*/unsigned short wHP;//009ABA0E
	/*08*/unsigned short wMP;//009ABA10
	/*0a*/short wSoundId;//009ABA12
	/*0c*/short f_0c;//009ABA14
};

struct t_battle_yet_another_0c {//size 0xc
	/*00*/char f_00;//target id?//009ACB98
	/*01*/char f_01;//attacker id?//009ACB99
	/*02*/char f_02;//009ACB9A
	/*03*/char bLink;//to D_009ABA08[]//009ACB9B
	/*04*/unsigned short f_04;//009ACB9C
	/*06*/char __06[2];//009ACB9E
	/*08*/int f_08;//009ACBA0
};

struct t_battle_ScriptContext {//size 0x1e?
	/*00*/char bScriptActive;
	/*01*/unsigned char bOpcode;
	/*02*/char __02[2];//pad
	/*04*/unsigned char *pScriptData;
	/*08*/short f_08;
	/*0a*/short f_0a;
	//-- --
	/*0c*/short f_0c;
	/*0e*/short f_0e;
	/*10*/short f_10;
	/*12*/short f_12;
	/*14*/char f_14;
	/*15*/char f_15;
	/*16*/struct SVECTOR f_16;
	//-- --
	/*1e*/
};

struct t_battle_temp_0c {//size 0xc
	/*00*/short f_00;//00BF2054
	/*02*/short f_02;//00BF2056
	/*04*/short f_04;//00BF2058
	/*06*/short f_06;//00BF205A
	/*08*/int f_08;//00BF205C
};

struct t_battle_local_34 {//size 0x34
	/*00*/struct MATRIX f_00;//00BF2168
	/*1e*/struct SVECTOR f_1e;//sRot//00BF2186/00BF2188/00BF218A
	/*26*/struct SVECTOR f_26;//sPos//00BF218E/00BF2190/00BF2192
	/*2e*/char __2e[2];//00BF2196
	/*30*/struct MATRIX *f_30;//00BF2198
};

struct t_battle_still_another_8 {
	/*00*/char f_00;//00BFCB70
	/*01*/char __01[1];//00BFCB71
	/*02*/unsigned short f_02;//00BFCB72
	/*04*/int f_04;//00BFCB74
};

struct t_battle_14 {//size 0x14
	/*00*/short f_00;//target
	/*02*/char __02[2];
	/*04*/struct SVECTOR f_04;
	/*0c*/int f_0c;
	/*10*/short f_10;
	/*12*/char __12[2];
};

struct t_battle_path_cc {//size 0xcc
	/*00*/int f_00;
	/*04*/char f_04[0xc8];
};

struct t_tmd_38_bis {//size 0x38
	/*00*/int f_00;
	/*04*/int dwClut;
	/*08*/int dwTpage;
	//-- --
	/*0c*/float fU0,fU1;
	/*14*/float fV0,fV1;
	//-- --
	/*1c*/float f_1c,f_20;//texW,texH
	/*24*/int dwTextureIndex;
	/*28*/float f_28,f_2c;//U,V
	/*30*/float f_30,f_34;//texW,texH[power of 2]
};

struct t_lmd_1618 {//size 0x1618
	/*0000*/int f_0000;
	/*0004*/const char *f_0004;//file name
	/*0008*/struct t_list_List *f_0008;
	/*000c*/struct t_tmd_38_bis f_000c[0x64];
	/*15ec*/int f_15ec;
	/*15f0*/int dwMinClutX,dwMinClutY;
	/*15f8*/int dwMaxClutX,dwMaxClutY;
	/*1600*/int dwMinTpageX,dwMinTpageY;
	/*1608*/int dwMaxTpageX,dwMaxTpageY;
	/*1610*/int f_1610;//check
	/*1614*/struct t_rsd_74 *f_1614;
};

struct t_combat_static_38 {//size 0x38
	/*00*/unsigned char f_00[8];//0099ce10
	/*08*/unsigned char f_08;//0099ce18
	/*09*/char __09;//0099ce19
	/*0a*/unsigned char f_0a;//0099ce1a
	/*0b*/char __0b;//0099ce1b
	/*0c*/unsigned char abLimitId[4][3];//0099ce1c
	/*18*/unsigned short f_18[2];//LIMIT required kill-count//0099ce28
	/*1c*/unsigned short f_1c[3][2];//LIMIT required use//0099ce2c
	/*28*/int f_28[4];//0099ce38
};

//kernel.bin/section 2
struct t_combat_static_f94 {//size 0xf94
	/*000*/struct t_combat_static_38 f_000[9];//0099CE10
	/*1f8*/unsigned char f_1f8[0xc];//0099d008
	/*204*/unsigned char f_204[0xc];//0099d014
	/*210*/unsigned char f_210[0xc];//0099d020
	/*21c*/struct {
		unsigned char f_00;
		char f_01;
	}f_21c[0x40][8];//0099d02c
	/*61c*/unsigned short f_61c[0x800/2];//some script content?//0099d42c
	/*e1c*/unsigned char f_e1c[0x100];//random table//0099dc2c
	/*f1c*/unsigned char f_f1c[0x40];//0099dd2c
	/*f5c*/unsigned char f_f5c[0x36];//0099dd6c
	/*f92*/char __f92[2];//0099dda2
};

struct t_battle_progress_info {//size 0x48
	/*00*/int dwGainedEXP;//0099E2C0
	/*04*/int dwGainedAP;//0099E2C4
	/*08*/int dwGaineGIL;//0099E2C8
	/*0c*/struct {//size 0xc
		/*00*/int dwNextLvlEXP;//0099E2CC
		/*04*/int dwEXP;//0099E2D0
		/*08*/unsigned char cNextLvlGauge;//progress related//0099E2D4
		/*09*/unsigned char cLevel;//0099E2D5
		/*0a*/unsigned short wNewLimitMask;//0099E2D6
	}aCharaProgress[3];//0099E2CC
	/*30*/struct {//size 6
		/*00*/short wType;//0099E2F0
		/*02*/short wQuantity;//0099E2F2
		/*04*/unsigned short wTookIt;//0099E2F4
	}aGainedItems[4];//0099E2F0
};

struct t_combat_178 {//size 0x178
	/*000*/short f_000[4];//f_000[3] is always -1 and never read?//009A874E
	//-- --
	struct t_stageInfo {//size 0x14
		/*00*/unsigned short dwStageType;//009A8750
		/*02*/unsigned short f_02;//009A8752
		/*04*/unsigned short f_04;//009A8754
		/*06*/short __06;//always -1?//009A8756
		/*08*/unsigned short f_08[4];//009A8758
		/*10*/unsigned short f_10;//009A8760
		/*12*/unsigned char f_12;//009A8762
		/*13*/unsigned char f_13;//009A8763
	}f_008;
	//-- --
	/*01c*/struct t_battle_cam_0c {//size 0xc
		/*00*/short wPosX,wPosY,wPosZ;//009A8764,009A8766,009A8768
		/*06*/short wTargetX,wTargetY,wTargetZ;//009A876A,009A876C,009A876E
	}f_01c[4];//009A8764
	//-- --
	/*04c*/struct t_temp_010_too {//size 0x10
		short f_00;//009A8794
		short f_02;//009A8796
		short f_04;//009A8798
		short f_06;//009A879A
		unsigned char f_08;//009A879C
		char __09[1];//009A879D
		unsigned short f_0a;//009A879E
		int f_0c;//009A87A0
	}f_04c[6];//009A8794
	//-- --
	/*0ac*/struct t_temp_010 {//009A87F4
		/*00*/char f_00;//009A87F4
		/*01*/unsigned char f_01;//009A87F5
		/*02*/unsigned char bDoomCounter;//009A87F6
		/*03*/unsigned char bSlowNumbCounter;//009A87F7
		/*04*/unsigned char f_04;//009A87F8
		/*05*/char __05[1];//009A87F9
		/*06*/unsigned short f_06;//009A87FA
		/*08*/int f_08;//009A87FC
		/*0c*/int f_0c;//009A8800
	}f_0ac[0xa];
	//-- --
	/*14c*/unsigned short f_14c;//009A8894
	/*14e*/unsigned short f_14e;//009A8896
	/*150*/unsigned short f_150;//009A8898
	/*152*/unsigned short f_152;//009A889A
	/*154*/char __154[2];//009A889C
	/*156*/unsigned short f_156;//009A889E
	/*158*/char __158[2];//009A88A0
	/*15a*/unsigned short f_15a;//009A88A2
	/*15c*/unsigned short f_15c;//009A88A4
	/*15e*/unsigned short f_15e;//009A88A6
	/*160*/unsigned short f_160;//009A88A8
	//-- --
	/*162*/unsigned short f_162[3];//009A88AA
	/*168*/unsigned char f_168[3+1];//cait sith slots//009A88B0//check count
	/*16c*/unsigned char f_16c[7+1];//tifa slots//009A88B4//check count
	//-- --
	/*174*/unsigned short f_174;//009A88BC
	/*176*/char __176[2];//009A88BE
};

struct t_temp_044 {//size 0x44
	/*00*/unsigned short wDelta1;//009A8B10
	/*02*/unsigned short wWaitIncr;//009A8B12
	/*04*/unsigned short wWait;//009A8B14
	/*06*/short f_06;//009A8B16
	/*08*/unsigned short f_08;//009A8B18
	/*0a*/unsigned short wDelta3;//009A8B1A
	/*0c*/unsigned char f_0c;//009A8B1C
	/*0d*/unsigned char f_0d;//009A8B1D
	/*0e*/unsigned char f_0e;//009A8B1E
	/*0f*/unsigned char f_0f;//009A8B1F
	/*10*/unsigned char f_10[0x10];//009A8B20
	/*20*/char f_20[8];//009A8B30
	/*28*/unsigned char f_28;//009A8B38
	/*29*/unsigned char f_29;//009A8B39
	/*2a*/unsigned char f_2a;//009A8B3A
	/*2b*/unsigned char f_2b;//009A8B3B
	/*2c*/int f_2c;//009A8B3C
	/*30*/int f_30;//009A8B40
	/*34*/int dwStatus;//009A8B44
	/*38*/struct t_battle_enemyInfo_b8 *f_38;//009A8B48
	/*3c*/unsigned short wHP;//009A8B4C
	/*3e*/unsigned short wMP;//009A8B4E
	/*40*/char __40[4];//009A8B50
};

struct t_temp_034 {//size 0x34
	/*00*/struct t_loadmenu_charaInfo *f_00;//009A8DB8
	/*04*/unsigned char bLIMITCount;//009A8DBC
	/*05*/unsigned char f_05;//009A8DBD
	/*06*/unsigned char bManipulating;//009A8DBE
	/*07*/unsigned char bKillCount;//009A8DBF
	/*08*/unsigned short wLimit;//009A8DC0
	/*0a*/unsigned short f_0a;//LIMIT value?//009A8DC2
	/*0c*/unsigned short wMP;//009A8DC4
	/*0e*/short wHP;//[not used?]//009A8DC6
	/*10*/short wMPMax;//[not used?]//009A8DC8
	/*12*/unsigned short wHPMax;//009A8DCA
	/*14*/unsigned short wMaxMPDamage;//009A8DCC
	/*16*/unsigned short wMaxHPDamage;//009A8DCE
	/*18*/unsigned short f_18[2];//009A8DD0
	/*1c*/int f_1c;//009A8DD4
	/*20*/int dwStatus;//009A8DD8
	/*24*/int f_24;//009A8DDC
	/*28*/int f_28;//009A8DE0
	/*2c*/char __2c[8];//009A8DE4
};

struct t_battle_enemyInfo_b8 {//size 0xb8
	/*00*/unsigned char aName[0x20];//009A8E9C
	/*20*/unsigned char f_20;//009A8EBC
	/*21*/unsigned char f_21;//009A8EBD
	/*22*/unsigned char f_22;//009A8EBE
	/*23*/unsigned char f_23;//009A8EBF
	/*24*/unsigned char f_24;//009A8EC0
	/*25*/unsigned char f_25;//009A8EC1
	/*26*/unsigned char f_26;//009A8EC2
	/*27*/unsigned char f_27;//009A8EC3
	/*28*/unsigned char f_28[8];
	/*30*/unsigned char f_30[8];
	/*38*/unsigned char f_38[0x10];
	/*48*/unsigned short f_48[0x10];
	/*68*/unsigned short f_68[0x10];
	/*88*/unsigned char f_88[4];
	/*8c*/unsigned short f_8c[4];
	/*94*/unsigned short f_94[4];
	/*9c*/unsigned short dwMP;
	/*9e*/unsigned short dwAPGain;
	/*a0*/unsigned short f_a0;
	/*a2*/unsigned char f_a2;//009A8F3E
	/*a3*/char __a3[1];
	/*a4*/int dwHP;//009A8F40
	/*a8*/int dwEXPGain;//009A8F44
	/*ac*/int dwGILGain;//009A8F48
	/*b0*/int f_b0;//009A8F4C
	/*b4*/char __b4[4];
};

struct t_battle_local_08_HHHH {//size 8
	/*00*/unsigned char f_00;
	/*01*/unsigned char f_01;
	/*02*/char f_02;
	/*03*/char f_03;
	/*04*/short f_04;
	/*06*/unsigned short f_06;
};

struct t_temp_battle_18 {//size 0x18
	/*00*/unsigned char bTargetFlags;
	/*01*/unsigned char f_01;
	/*02*/unsigned char f_02;
	/*03*/unsigned char f_03;
	/*04*/unsigned char f_04;
	/*05*/unsigned char f_05;
	/*06*/char __06[2];
	/*08*/short awSoundId[3];
	/*0e*/unsigned short f_0e;
	/*10*/unsigned short f_10;
	/*12*/unsigned short f_12;
	/*14*/int f_14;
};

struct t_battle_resolution {//size unknown
	//-- --
	int f_000;
	int f_004;
	int f_008;
	int f_00c;
	int f_010;
	int f_014;
	int f_018;
	int f_01c;
	int f_020;
	int f_024;
	int f_028;
	int f_02c;
	int f_030;
	int __034;
	int f_038;
	int f_03c;
	int f_040;
	int f_044;
	int f_048;
	int f_04c;
	int f_050;
	int f_054[3];
	int f_060;
	int f_064;
	int f_068;
	int f_06c;
	int __070;
	int __074;
	int f_078;
	int f_07c;
	int f_080[3];
	int f_08c;
	int f_090;
	int f_094;
	int f_098;
	int __09c;
	int f_0a0;
	int f_0a4;
	int f_0a8;
	int f_0ac;
	int f_0b0;
	int f_0b4;
	int f_0b8;
	int f_0bc;
	int f_0c0;
	int f_0c4;
	int f_0c8;
	int f_0cc;
	unsigned char f_0d0[8];
	int f_0d8;
	int f_0dc;
	int f_0e0;
	int f_0e4;
	int f_0e8;
	int f_0ec;
	int f_0f0;
	int f_0f4;
	int f_0f8;
	int f_0fc;
	//-- --
	char __100[0x100];
	//-- --
	struct t_temp_044 *f_200;
	struct t_temp_034 *f_204;
	int f_208;//target id
	int f_20c;
	int f_210;
	int f_214;//attack damage?
	int f_218;
	int f_21c;
	int f_220;
	int f_224;
	int f_228;
	int f_22c;
	int f_230;
	int f_234;
	int f_238[3];
	int f_244;
	int f_248;
	int f_24c;
	int f_250;//damage related?
	int f_254;
	int f_258;//target HP
	int f_25c;//target MP
	int f_260;
};

struct t_battle_222c {//size 0x222c
	/*0000*/struct t_temp_044 f_0000[0xa];//009A8B10
	/*02a8*/struct t_temp_034 f_02a8[3];//009A8DB8
	/*0344*/struct t_temp_battle_18 f_0344[3];//009A8E54
	/*038c*/struct t_battle_enemyInfo_b8 f_038c[3];//009A8E9C
	/*05b4*/struct t_menu_temp_1c f_05b4[0x20];//009A90C4
	/*0934*/unsigned short f_0934[0x20];//009A9444
	/*0974*/unsigned char f_0974[0x20][0x20];//009A9484
	/*0d74*/struct t_battle_local_08_HHHH f_0d74;//009A9884
	/*0d7c*/struct t_battle_local_08_HHHH f_0d7c[0x40];//009A988C
	/*0f7c*/struct t_battle_local_08_HHHH f_0f7c[0xa];//009A9A8C
	/*0fcc*/struct t_battle_local_08_HHHH f_0fcc[2];//009A9ADC
	/*0fdc*/unsigned char f_0fdc[7];//009A9AEC
	/*0fe3*/unsigned char f_0fe3[7];//009A9AF3
	/*0fea*/char __0fea[2];//009A9AFA
	//-- --
	/*0fec*/unsigned short f_0fec[0x200/2];//enemy own scripts?//009A9AFC
	/*11ec*/unsigned short f_11ec[0x1000/2];//main chara own scripts?//009A9CFC
	//-- --
	/*21ec*/char __21ec[2];//009AACFC
	/*21ee*/unsigned short f_21ee;//battle speed related?//009AACFE
	/*21f0*/unsigned short f_21f0;//009AAD00
	/*21f2*/unsigned short f_21f2;//009AAD02
	/*21f4*/unsigned short f_21f4;//009AAD04
	/*21f6*/unsigned short f_21f6;//009AAD06
	/*21f8*/unsigned short f_21f8;//009AAD08
	/*21fa*/unsigned short f_21fa;//009AAD0A
	/*21fc*/unsigned short f_21fc;//009AAD0C
	/*21fe*/unsigned short f_21fe;//009AAD0E
	/*2200*/unsigned short f_2200;//009AAD10
	/*2202*/unsigned short f_2202;//009AAD12
	/*2204*/unsigned short f_2204;//009AAD14
	/*2206*/unsigned short f_2206;//009AAD16
	/*2208*/unsigned short f_2208;//009AAD18
	/*220a*/unsigned short f_220a;//009AAD1A
	/*220c*/unsigned short f_220c;//009AAD1C
	/*220e*/unsigned short f_220e;//009AAD1E
	/*2210*/unsigned short f_2210;//009AAD20
	/*2212*/unsigned short f_2212;//009AAD22
	/*2214*/unsigned short f_2214;//009AAD24
	/*2216*/unsigned short f_2216;//009AAD26
	/*2218*/unsigned short f_2218;//009AAD28
	/*221a*/unsigned short f_221a;//009AAD2A
	/*221c*/unsigned char f_221c[3];//009AAD2C
	/*221f*/char __221f[1];//009AAD2F
	/*2220*/unsigned short f_2220;//009AAD30
	/*2222*/unsigned short f_2222[2];//009AAD32
	/*2226*/short f_2226;//009AAD36
	/*2228*/unsigned short f_2228;//009AAD38
	/*222a*/unsigned short f_222a;//lucky 7s counter//009AAD3A
};

struct t_battle_local_68 {//size 0x68
	/*00*/int dwStatus;//[0x4000]//009AB0DC
	/*04*/int f_04;//[0x4020]//009AB0E0
	/*08*/char f_08;//[0x4040]//009AB0E4
	/*09*/unsigned char f_09;//[0x4048]//009AB0E5
	/*0a*/char __0a[1];//009AB0E6
	/*0b*/unsigned char f_0b;//[0x4058]//009AB0E7
	/*0c*/unsigned char f_0c;//[0x4060]//009AB0E8
	/*0d*/unsigned char f_0d;//[0x4068]//009AB0E9
	/*0e*/unsigned char f_0e;//[0x4070]//009AB0EA
	/*0f*/unsigned char f_0f;//[0x4078]//009AB0EB
	/*10*/char f_10;//[0x4080]//009AB0EC
	/*11*/unsigned char f_11;//[0x4088]//009AB0ED
	/*12*/unsigned char f_12;//[0x4090]//009AB0EE
	/*13*/unsigned char f_13;//[0x4098]//009AB0EF
	/*14*/unsigned char f_14;//[0x40a0]//009AB0F0
	/*15*/unsigned char f_15;//[0x40a8]//009AB0F1
	/*16*/unsigned char f_16;//[0x40b0]//009AB0F2
	/*17*/unsigned char f_17;//[0x40b8]//009AB0F3
	/*18*/unsigned short f_18;//[0x40c0]//009AB0F4
	/*1a*/unsigned short f_1a;//[0x40d0]//009AB0F6
	/*1c*/unsigned short f_1c;//[0x40e0]//009AB0F8
	/*1e*/unsigned short f_1e;//[0x40f0]//009AB0FA
	/*20*/unsigned short f_20;//[0x4100]//009AB0FC
	/*22*/unsigned short f_22;//[0x4110]//009AB0FE
	/*24*/unsigned short f_24;//[0x4120]//009AB100
	/*26*/unsigned short f_26;//[0x4130]//009AB102
	/*28*/unsigned short wMP,wMPMax;//[0x4140][0x4150]//009AB104,009AB106
	/*2c*/unsigned dwHP,dwHPMax;//[0x4160][0x4180]009AB108,009AB10C
	/*34*/char __34[0x10];//009AB110
	/*44*/int f_44;//[0x4220]//009AB120
	/*48*/char __48[4];//009AB124
	/*4c*/unsigned char f_4c;//[0x4260]//009AB128
	/*4d*/unsigned char f_4d;//[0x4268]//009AB129
	/*4e*/unsigned char f_4e;//[0x4270]//009AB12A
	/*4f*/unsigned char f_4f;//[0x4278]//009AB12B
	/*50*/unsigned short f_50;//[0x4280]//009AB12C
	/*52*/unsigned short f_52;//[0x4290]//009AB12E
	/*54*/unsigned short f_54;//[0x42a0]//009AB130
	/*56*/unsigned char f_56;//[0x42b0]//009AB132
	/*57*/char __57[1];//009AB133
	/*58*/int dwGILGain;//[0x42c0]//009AB134
	/*5c*/int dwEXPGain;//[0x42e0]//009AB138
	/*60*/char __60[8];//009AB13C
};

struct t_battle_94c {//size 0x94c
	//-- script address 0x2000~ --
	char f_000;//[0x2000]//009AB0A0
	char f_001;//[0x2008]//009AB0A1
	char f_002;//[0x2010]//009AB0A2
	char __003[1];//009AB0A3
	char f_004;//[0x2020]//009AB0A4
	char __005[2];//009AB0A5
	char f_007;//[0x2038]//009AB0A7
	char __008[2];//009AB0A8
	unsigned short f_00a;//[0x2050]//009AB0AA
	unsigned short f_00c;//[0x2060]//009AB0AC
	unsigned short f_00e;//[0x2070]//009AB0AE
	unsigned short f_010;//[0x2080]//009AB0B0
	unsigned short f_012;//[0x2090]//009AB0B2
	unsigned short f_014;//[0x20a0]//009AB0B4
	unsigned short f_016;//[0x20b0]//009AB0B6
	unsigned short f_018;//[0x20c0]//009AB0B8
	unsigned short f_01a;//[0x20d0]//009AB0BA
	unsigned short f_01c;//[0x20e0]//009AB0BC
	char __01e[4];//009AB0BE
	unsigned short f_022;//[0x2110]//009AB0C2
	short f_024;//[0x2120]//009AB0C4
	char __026[2];//009AB0C6
	unsigned short f_028;//[0x2140]//009AB0C8
	unsigned short f_02a;//[0x2150]//009AB0CA
	unsigned short f_02c;//[0x2160]//009AB0CC
	unsigned short f_02e;//[0x2170]//009AB0CE
	unsigned short f_030;//[0x2180]//009AB0D0
	char __032[2];//009AB0D2
	unsigned short f_034[2];//[0x21a0]//009AB0D4
	int f_038;//[0x21c0]//009AB0D8
	//-- script address 0x4000~ --
	struct t_battle_local_68 f_03c[0xa];//009AB0DC
	//-- script address 0x0000~ --
	int f_44c[0xa][0x20];//009ab4ec
};

struct t_battle_06 {//size 6
	short wX,wY,wZ;//00BFD0A0,00BFD0A2,00BFD0A4
};

struct t_battle_74 {//size 0x74
	/*00*/unsigned f_00;//00BF23C0
	/*04*/short f_04[4];//00BF23C4
	/*0c*/unsigned short f_0c;//00BF23CC
	/*0e*/short f_0e[2][6];//00BF23CE
	/*26*/short f_26;//00BF23E6
	/*28*/short f_28;//00BF23E8
	/*2a*/short f_2a;//00BF23EA
	/*2c*/short f_2c;//00BF23EC
	/*2e*/short wTexAnimUV;//00BF23EE
	/*30*/short f_30;//00BF23F0
	/*32*/char f_32;//00BF23F2
	/*33*/unsigned char bAnimSpeed;//00BF23F3
	/*34*/unsigned char f_34;//00BF23F4
	/*35*/unsigned char f_35;//00BF23F5
	/*36*/unsigned char f_36;//00BF23F6
	/*37*/unsigned char bHasTexAnim;//00BF23F7
	/*38*/short f_38,f_3a,f_3c;//00BF23F8,00BF23FA,00BF23FC
	/*3e*/short f_3e;//00BF23FE
	/*40*/struct t_battle_local_34 f_40;//00BF2400
};

struct t_battle_DAT_Header {//size 0x34
	/*00*/int f_00;
	/*04*/int f_04;//has "B" file
	/*08*/int f_08;
	/*0c*/int f_0c;
	/*10*/int f_10;
	/*14*/int dwPartsCount;
	/*18*/int dwTexCount;
	/*1c*/int f_1c;
	/*20*/int f_20;
	/*24*/int f_24;
	/*28*/int f_28;
	/*2c*/int f_2c;
	/*30*/struct t_char_local_0c *f_30;
};

struct t_battle_B_Header {
	/*00*/short f_00;
	/*02*/short f_02;
	/*04*/short f_04;
	/*06*/short f_06;
	/*08*/short f_08;
	/*0a*/short f_0a;
	/*0c*/short f_0c;
	/*0e*/short f_0e;
	/*10*/short f_10;
	/*12*/char f_12[0x10];
	/*22*/char __22[2];
	/*24*/int f_24[8];
	/*44*/short f_44[4];
	/*4c*/short f_4c[6];
	/*58*/short f_58[6];
	/*64*/short f_64;
	/*66*/char __66[2];
	/*68*/unsigned char *f_68[1];//actualy 0x20~0x4a?
	//...
};

struct t_b3ddata_0c {//size 0xc
	int f_00;
	void *f_04;
	struct tListOfRSD *f_08;
};

struct t_b3ddata_4f4 {//size 0x4f4
	/*00*/struct t_b3ddata_0c *f_00;
	//-- --
	/*04*/struct t_rsd_0c *f_04;//"KAGE"
	/*08*/struct t_rsd_0c *f_08;//"KAGE"
	/*0c*/struct t_rsd_0c *f_0c;//"MARK"
	//-- --
	/*10*/struct t_dx_sfx_e0 *f_10;//"SEFFECT1.TIM"[3D]
	/*14*/struct t_dx_sfx_e0 *f_14;//"SEFFECT2.TIM"[3D]
	/*18*/struct t_dx_sfx_e0 *f_18;//"SEFFECT3.TIM"[3D]
	/*1c*/struct t_dx_sfx_e0 *f_1c;//"SEFFECT1.TIM"[2D]
	/*20*/struct t_dx_sfx_e0 *f_20;//"SEFFECT2.TIM"[2D]
	/*24*/struct t_dx_sfx_e0 *f_24;//"SEFFECT3.TIM"[2D]
	//-- --
	/*28*/struct t_dx_sfx_e0 *f_28[8];
	//-- --
	/*48*/struct t_dx_sfx_e0 *f_48;//"RAIN7.TIM"
	//-- --
	/*4c*/struct t_render_local_2c *f_4c;
	//-- --
	/*50*/struct t_battle3d_char_94 *f_50;//from battle3d.char
	/*54*/struct t_swirl_124 f_54[4];
	/*4e4*/char __4e4[0x10];
};

struct t_battle_char_44 {//size 0x44
	/*00*/int f_00;
	/*04*/int f_04;
	/*08*/int dwFlipY;
	/*0c*/int f_0c;
	/*10*/int f_10;
	/*14*/int f_14;
	/*18*/char __18[4];
	/*1c*/int f_1c;
	/*20*/int f_20;
	/*24*/int f_24;
	/*28*/int f_28;//dwDoConversion
	/*2c*/int f_2c;
	/*30*/int f_30;
	/*34*/int f_34;
	/*38*/int f_38;//dwTexCount
	/*3c*/int f_3c;
	/*40*/int dwSWRendering;
};

struct t_battle3d_char_94 {//size 0x94
	/*00*/struct t_battle_B_Header *f_00;
	/*04*/struct tSkeleton *f_04;
	/*08*/int dwAnimCount;
	/*0c*/struct t_animationHeader **f_0c;
	/*10*/int dwAltAnimCount;
	/*14*/struct t_animationHeader **f_14;
	/*18*/int f_18;
	/*1c*/struct tSkeleton **f_1c;
	/*20*/struct t_plytopd_74 f_20;
};

struct t_battle_40 {//size 0x40
	/*00*/int f_00;//00BE0E28
	/*04*/char __04[4];//00BE0E2C
	/*08*/struct t_battle_local_34 f_08;//00BE0E30
	//-- start of a struct? --
	/*3c*/short f_3c;//00BE0E64
	/*3e*/char f_3e[1];//00BE0E66
	/*3f*/char __3f[1];//00BE0E67
};

//GraphicalDamage?
struct t_battle_0c_1 {//size 0xc
	/*00*/short wDamage;//00BF2A40
	/*02*/short f_02;//00BF2A42
	/*04*/short wSoundId;//00BF2A44
	/*06*/short f_06;//00BF2A46
	/*08*/short f_08;//00BF2A48
	/*0a*/short f_0a;//00BF2A4A
};

struct t_battle_cam_type1_28 {//size 0x28
	short f_00;//status?//00BFCE08
	short f_02;//counter?//00BFCE0A
	//-- --
	short f_04;//00BFCE0C
	short f_06;//00BFCE0E
	short f_08;//00BFCE10
	short f_0a;//00BFCE12
	short f_0c;//00BFCE14
	short f_0e;//00BFCE16
	int f_10;//00BFCE18;//sometimes cast as short?
	char __14[4];//00BFCE1C
	char f_18;//00BFCE20
	char __19[0xf];//00BFCE21
};

typedef struct {
	/*00*/short f_00;//status?
	/*02*/short f_02;//counter?
} t_battle_task_header;

struct t_battle_20_1: t_battle_task_header {//size 0x20
	/*04*/short f_04;//00BF2E74
	/*06*/short f_06;//00BF2E76
	/*08*/short f_08;//00BF2E78
	/*0a*/short f_0a;//00BF2E7A
	/*0c*/short f_0c;//00BF2E7C
	/*0e*/short f_0e;//00BF2E7E
	/*10*/int f_10;//00BF2E80
	/*14*/int f_14;//00BF2E84
	/*18*/char f_18;//00BF2E88
	/*19*/char f_19;//00BF2E89
	/*1a*/char f_1a;//00BF2E8A
	/*1b*/char __1b[5];//00BF2E8B
};
struct t_battle_20_2: t_battle_task_header {//size 0x20
	/*04*/short f_04;//00BFB71C
	/*06*/short f_06;//00BFB71E
	/*08*/short f_08;//00BFB720
	/*0a*/short wDamage;//00BFB722
	/*0c*/short f_0c;//00BFB724
	/*0e*/short f_0e;//00BFB726
	/*10*/int dwSoundId;//00BFB728
	/*14*/int f_14;//00BFB72C
	/*18*/char f_18;//00BFB730
	/*19*/char f_19;//00BFB731
	/*1a*/char __1a[6];//00BFB732
};
struct t_battle_20_3: t_battle_task_header {//size 0x20
	/*04*/short f_04;//00BFC3A4
	/*06*/short f_06;//00BFC3A6
	/*08*/short f_08;//00BFC3A8
	/*0a*/short f_0a;//00BFC3AA
	/*0c*/short f_0c;//00BFC3AC
	/*0e*/short wDamage;//00BFC3AE
	/*10*/unsigned f_10;//00BFC3B0
	/*14*/unsigned f_14;//00BFC3B4
	/*18*/char f_18;//00BFC3B8
	/*19*/char __19[7];//00BFC3B9
};
struct t_battle_task_local_20_B: t_battle_task_header {//size 0x20
	/*04*/short f_04;
	/*06*/short f_06;
	/*08*/short f_08;
	/*0a*/char __0a[2];
	/*0c*/void (*f_0c)(int, int);
	/*10*/char __10[0x10];
};
////////////////////////////////////////
#define CURTASK    D_00BFB718[D_00BF23B8]
#define CURCAMTASK D_00BFCE08[D_00BE10B8]
#define CURCTASK   D_00BF2E70[D_00C05EC0]
#define CURETASK   D_00BFC3A0[D_00BF2DF4]
////////////////////////////////////////

//aka struct t_battle_1aec
struct t_b3ddata_1aec {//size 0x1aec
	/*0000*/short f_0000;//00BE1178
	/*0002*/short wCurScriptId;//00BE117A
	/*0004*/short f_0004;//00BE117C
	/*0006*/short f_0006;//00BE117E
	/*0008*/unsigned short f_0008;//00BE1180
	/*000a*/unsigned short f_000a;//00BE1182
	/*000c*/short f_000c;//00BE1184
	/*000e*/short wNewAnim;//00BE1186
	/*0010*/short wBoneCount;//00BE1188
	/*0012*/short f_0012;//00BE118A
	/*0014*/short f_0014;//wBlackness//00BE118C
	/*0016*/short f_0016;//00BE118E
	/*0018*/short f_0018;//00BE1190
	/*001a*/short f_001a[2];//00BE1192//TODO
	/*001e*/char __001e[4];//00BE1196
	/*0022*/unsigned char cLimitBreakId;//00BE119A
	/*0023*/unsigned char f_0023;//00BE119B
	/*0024*/char f_0024;//00BE119C
	/*0025*/unsigned char f_0025;//00BE119D
	/*0026*/unsigned char f_0026;//00BE119E
	/*0027*/unsigned char f_0027;//00BE119F
	/*0028*/unsigned char f_0028,f_0029,f_002a;//00BE11A0,00BE11A1,00BE11A2//far color related?
	/*002b*/char f_002b[0x10];//00BE11A3
	/*003b*/unsigned char bAnimEnded;//00BE11B3
	/*003c*/unsigned char bScriptPC;//00BE11B4
	/*003d*/unsigned char f_003d;//00BE11B5
	/*003e*/unsigned char f_003e;//00BE11B6
	/*003f*/char f_003f[0x32];//bones flag(8:transparent)[only f_003f[0] used]//00BE11B7
	/*0040*/char __0071[3];//00BE11E9
	/*0074*/int f_0074;//00BE11EC
	/*0078*/char __0078[0xc8];//00BE11F0
	//-- --
	/*0140*/struct t_battle_local_34 f_0140;//00BE12B8
		//f_0140.f_1e//00BE12D6
		//f_0140.f_20//00BE12D8
		//f_0140.f_22//00BE12DA
		//f_0140.f_26/f_0140.f_28/f_0140.f_2a//00BE12DE,00BE12E0,00BE12E2
		//f_0140.f_30//00BE12E8
	//-- --
	/*0174*/struct t_battle_local_34 f_0174[0x32];//00BE12EC
	//	short _00BE1312;f_0174[0].f_26
	//	short _00BE1314;f_0174[0].f_28
	//	short _00BE1316;f_0174[0].f_2a
	//	f_0174[0x31]//00BE1CE0
	//	0BE1CE0 f_0174[0x31].f_00
	//	0BE1CFE f_0174[0x31].f_1e
	//	0BE1D00 f_0174[0x31].f_1e.f_02
	//	0BE1D08 f_0174[0x31].f_26.f_02
	/*0b9c*/int dwCurFrame;//00BE1D14
	/*0ba0*/int f_0ba0;//00BE1D18
	/*0ba4*/int dwCurAnim;//00BE1D1C
	/*0ba8*/struct t_battle3d_char_94 *f_0ba8;//00BE1D20
	/*0bac*/struct t_g_drv_0c f_0bac[0x32];//bones/joint related?//00BE1D24
	/*0e04*/D3DMATRIX f_0e04;//00BE1F7C
	/*0e44*/D3DMATRIX f_0e44[0x32];//00BE1FBC
	/*1ac4*/int dwUseAltAnim;//00BE2C3C
	/*1ac8*/struct t_plytopd_dunno f_1ac8;//00BE2C40
	/*1ae4*/int f_1ae4;//00BE2C5C
	/*1ae8*/int f_1ae8;//00BE2C60
};

//union {
struct t_battle_someScratchpad_1 {//size 0xe0
	/*00*/int f_00;//00C06640
	/*04*/int f_04;//00C06644
	/*08*/int f_08[9][6];//00C06648
};
struct t_battle_someScratchpad_2 {//size 0xe0
	/*00*/unsigned f_00[4];//EXP//00C06640
	/*10*/unsigned f_10[4];//new EXP//00C06650
	/*20*/int f_20[4][0xc];//00C06660
};
//};

struct t_CharaScreenCoords {//size 8
	/*00*/short wX,wY;
	/*04*/short wNextX,wNextY;
};
////////////////////////////////////////
extern void C_0041FA70(void);
extern void C_0041FA91(void *, int, short);
extern void C_0041FAE0(void *, int, short);
extern void C_0041FBA4(short, unsigned char **, int, int);
extern void C_004254E8(void);
extern void C_00425FC4(void);//(callback)
extern void C_0042782A(void);//(callback)
extern void C_00427A01(void);//battle:wait magic thread end?
extern void C_00427A1E(void);//battle:calls "check magic thread ended"
extern void C_00427A28(char);//<almost empty>
extern void C_00427A4A(char);//<almost empty>
extern void C_00427C22(char);
extern struct t_dx_sfx_e0 *C_00428500(int, struct t_b3ddata_4f4 *);//b3ddata:...
extern struct t_dx_sfx_e0 *C_004285A0(int, struct t_b3ddata_4f4 *);
extern void C_00428920(struct t_b3ddata_4f4 *);//b3ddata:...
extern void C_00428985(struct t_b3ddata_4f4 *);//b3ddata:...
extern struct t_b3ddata_4f4 *C_00428B12(void);//b3ddata:create "struct t_b3ddata_4f4 *"?
extern int C_00428D96(struct t_b3ddata_4f4 *);//b3ddata:...
extern void *C_00428DCE(struct t_b3ddata_4f4 *);//b3ddata:...
extern void C_00428DF7(int, int, struct t_b3ddata_4f4 *);//b3ddata:...
extern void C_00428F59(void);//b3ddata:clean
extern void C_00429064(void);//b3ddata:reset something?
extern void C_0042908C(int, int);//b3ddata:...
extern void C_00429322(void);//b3ddata:reset render list?
extern int C_00429343(int);//b3ddata:...
extern void C_00429398(struct t_battle3d_char_94 *, struct t_b3ddata_4f4 *);
extern void C_004293B8(int, int, struct MATRIX *);//b3ddata:get some matrix?
extern int C_0042940D(int);//b3ddata:...
extern void C_004297B9(int);//b3ddata:...
extern void C_004297D3(int);//b3ddata:...
extern void C_004297FD(int, int, int);//b3ddata:...
extern void C_004298F8(int);//b3ddata:...
extern struct t_swirl_118 *C_0042992E(void);
extern struct t_dx_sfx_e0 *C_004299B4(int);//b3ddata:...
extern void C_004299F1(void);//b3ddata:...
extern void C_00429A12(int, int, struct t_battle_char_44 *, struct t_rsd_74 *);//b3ddata:...
extern void C_00429AC0(void);
extern void C_00429D8A(void);
extern struct t_battle3d_char_94 *C_0042A330(int, int, int, const char *);
extern void C_0042B66A(char);
extern void C_0042BC15(char);
extern void C_0042C0A7(char);
extern void C_0042C1B4(int);
extern void C_0042C21B(int);
extern void C_0042C2D7(short);
extern void C_0042C31C(short);
extern void C_0042CBF9(void);
extern void C_0042D971(void);
extern short C_0042DE25(int);
extern void C_0042E219(char);
extern void C_0042E34A(int, int, struct t_battle_B_Header *);
extern void C_0042F3E8(int);
extern void C_004302E8(struct t_battle_local_34 *);
extern void C_004303CC(int);
extern void C_0043076B(int);
extern void C_00430981(short, int, int);
extern void C_00430A99(struct t_battle_local_34 *, struct t_battle_local_34 *);
extern void C_00430AA7(void);
extern void C_00430C9F(void);
extern void C_00430CB0(void);
extern void C_00430CBF(void);
extern void C_00430CFA(unsigned short);
extern void C_00430D14(unsigned short);
extern void C_00430D32(unsigned short, short, int);
//-- C_00430DD0.cpp --
extern void C_00430DD0(void);
extern int C_00431890(void);//coloss:...
extern void C_00431C80(int);
extern int C_00431CA6(void);
extern int C_00431E49(void);//Battle:...
extern void C_00432040(void);
extern int C_00432077(int);
extern void C_004320AC(void);
extern void C_0043258A(struct t_battle_local_08_HHHH *);
extern void C_00432687(int, int, int, int, int);
extern void C_004326BF(void);
extern void C_00432AA2(short, short, short, short);//add attack command?
extern void C_00432BA0(void);
extern int C_00432BF6(int);
extern void C_00432C60(void);
//-- C_00433020.cpp --
extern void C_00433020(void);//cancellable_items:init/reset
extern void C_0043305C(short, short);//cancellable_items:remove
extern void C_004330C0(short, short);//cancellable_items:add
extern void C_00433112(short);//cancellable_items:cancel items for charId
extern void C_004331AC(void);//cancellable_items:get cancelled items back
extern unsigned short C_004333C4(void);
//-- --
extern int C_00433510(int, int, int);
extern void C_004337F3(int, int, int);
extern void C_00433887(void);
extern void C_004339C2(int);
extern int C_00434347(void);
extern void C_004350CB(void);
extern void C_00435139(int, int, int, int);
extern void C_004351BD(int);
extern int C_00434568(int, int, int);
extern int C_00435250(int);
extern void C_0043526A(void);
extern void C_0043553F(void);
extern void C_004355F0(void);
extern void C_00435770(int);
extern int C_00435789(int);
extern void C_00436B1B(void);
extern void C_00436B84(void);
//-- C_00436C30.cpp --
extern void C_00436C30(void);
extern void C_00436C4B(void);
extern struct t_unk_0c_1 *C_00436C66(void);
extern struct t_battle_yet_another_0c *C_00436CB5(void);
extern void C_00436CF2(void);
extern struct t_battle_graphicalDamage_0e *C_00436DA7(struct t_battle_yet_another_0c *);
extern void C_00436DFF(void);
extern void C_00436E15(int, int, int, int);
extern void C_00436E5C(int, int);
extern void C_00436E92(void);
extern void C_00436EB4(void);
extern void C_00436EEF(int);
extern void C_00436F6A(void);//(callback)
extern void C_00437092(void);
extern void C_00437131(int);
extern void C_00437185(int, int, int, int);
extern void C_004371FC(short, short);
extern int C_004372B0(void);
extern void C_004372FC(int, int);
extern int C_00437331(int, int);
extern void C_00437370(int);
extern int C_0043740B(int);
extern void C_00437420(int);
extern int C_00437481(int);
extern short C_00437506(void);
extern void C_0043758A(void);
extern void C_004375CE(int);
extern void C_0043763A(int);
extern void C_00437679(int, int);
extern void C_00437D4E(int, int);
extern void C_00437DB0(int);
extern void C_004381D5(int);
//-- C_00438610.cpp --
extern void C_00438610(void);//(callback)"EFFECT/HITMARK"
extern void C_00438BE4(int, int, int);
extern void C_00438C36(int, int);//do "EFFECT/HITMARK"[1](callback)
extern void C_00438C55(struct SVECTOR *, int, int);//do "EFFECT/HITMARK"[2](callback)
//-- C_00438C80.cpp --
extern void C_00438D10(int);//do "EFFECT/S_BARIA"[0](callback)
extern void C_004390A0(int);//do "EFFECT/S_BARIA"[1](callback)
extern void C_004390C2(int);//do "EFFECT/S_BARIA"[2](callback)
//-- --
extern void C_005B9B30(char);
extern void C_005B9EC2(char);
extern void C_005BB37A(char);
extern void C_005BCD42(void);//(callback)
extern void C_005BCF9D(void);//(callback)
extern void *C_005BD436(unsigned char, unsigned char, unsigned char);
extern void C_005BD96D(void);//(callback)
extern void C_005BDA0F(void);//(callback)
extern void C_005BDACF(void);
extern void C_005BDC4F(void);
extern void C_005BDF85(void);
extern void C_005BDFB6(short, char, unsigned char, short);
extern void C_005BE052(void);
extern void C_005BE20B(void);
extern int C_005BE475(void);
extern void  C_005BE487(void);//<empty>
//-- C_005BE490 --
extern void C_005BE490(int);
extern void C_005BE716(struct SVECTOR *, short, short);
extern void C_005BE844(int, struct SVECTOR *, short, short, short);
//-- C_005BE9F0 --
extern void C_005BE9F0(int, int, int);
extern void C_005BEB27(int, int);
//-- C_005BEC50/task.cpp --
extern short C_005BEC50(void (*)(void));
extern short C_005BECF1(void (*)(void));
extern short C_005BED92(void (*)(void));
extern short C_005BEE33(void (*)(void));
extern void C_005BEEC6(void);
extern void C_005BEFC8(void);
extern void C_005BF01F(void);
extern void C_005BF107(void);
extern void C_005BF1C2(void);
extern void C_005BF27D(void);
//-- C_005BF340 --
extern void C_005BF388(int, int, int, unsigned, int, int);//blade trail FX?
//-- C_005BFAA0 --
extern struct t_battle_14 *C_005BFAA0(int);
extern int C_005BFADC(struct t_battle_14 **);
extern void C_005BFB47(int);
extern void C_005BFC3C(int);
extern void C_005BFC65(int, int);
extern void C_005BFD3E(int, int, int, void (*)(int, int));
extern int C_005BFE7F(int);
extern struct SVECTOR *C_005BFEC9(int, struct SVECTOR *);
extern int C_005BFFB4(int);
extern void C_005BFFF3(int, int, int);
extern int C_005C00C5(struct SVECTOR *);
extern int C_005C0132(int);
extern struct t_battle_14 *C_005C0158(int);
//-- MAGIC/LIMIT? --
extern void C_005C01A0(void);//MAGIC/LIMIT:init
extern void C_005C0230(int, int);//MAGIC/LIMIT:"halo"?
//-- summon.cpp --
extern void C_005C0E39(void);//summon(special?) menu
extern void C_005C18BC(void);//(callback)
extern void C_005C1B81(void);//(callback)
extern void C_005C2070(short, short);
extern void C_005C20CE(short);//CameraSet
//-- --
extern void C_005C68B7(struct MATRIX *, struct SVECTOR *, struct SVECTOR *, struct VECTOR *);
extern void C_005C6B60(int, int);
extern void C_005C6DB5(struct t_loadmenu_charaInfo *, int);
extern void C_005C6E7B(int);
extern void C_005C6F9C(void);
extern int C_005C7090(struct t_loadmenu_charaInfo *, int, int);
extern void C_005C7260(struct t_loadmenu_charaInfo *, int, int);
extern void C_005C7336(struct t_loadmenu_charaInfo *);
extern int C_005C7C50(int);
extern unsigned short C_005C7CAE(struct t_battle_enemyInfo_b8 *, int, int, int);
extern void C_005C7D59(int, int, int, unsigned short *);
extern void C_005C7D99(int);
extern void C_005C7DB0(int);
extern int C_005C7DC7(int);
extern void C_005C7DEA(int, int, int, int, int, int, int);
extern int C_005C7E7A(int);
extern int C_005C7EB3(int, int, int);
extern void C_005C7EE5(int, int, int);
extern int C_005C7F60(void);
extern void C_005C7F94(int, int);
extern void C_005C8000(void *, const void *, int);//some memcpy?
extern int C_005C8041(unsigned);
extern int C_005C8080(unsigned);
extern int C_005C80B5(unsigned);
extern int C_005C8126(unsigned, int, unsigned, int);
extern int C_005C8180(int);
extern int C_005C81A3(int);
extern void C_005C84ED(void);
extern int C_005C8684(int, int);
extern void C_005C86E0(int, int, int);
extern void C_005C8931(void);
extern void C_005C89E2(int, int, int);
extern void C_005C8B65(int, int);
extern void C_005C8B80(void);//Battle.random:refresh?
extern unsigned char C_005C8BA1(void);//Battle.random:get unsigned char?
extern unsigned char C_005C8BDC(int);//Battle.random:get unsigned char(with max)?
extern int C_005C8BF2(void);//Battle.random:get 16bit value?
extern void C_005C8C42(int);//Battle.random:reset?
extern void C_005C8CFA(int, int);
extern void C_005CA807(void);
extern void C_005CA811(int);
extern void C_005CA860(void);
extern void C_005CA9D0(int);
extern void C_005CAA86(int);
extern void C_005CAB7C(int);
extern int C_005CABBA(void);
extern void C_005CAC07(int);
extern void C_005CAC55(void);
extern void C_005CAD70(short, short);
extern void C_005CB127(void);//Combat:compute encounter/combat related vars?
extern void C_005CB2CC(char);//Combat:equiped materia related?
extern void C_005CD078(unsigned);
extern void C_005CF650(void);
extern void C_005CFBF5(void);
extern void C_005CFE10(void);
extern void C_005D0097(int);
extern void C_005D0690(void);
extern void C_005D0BDF(void);
extern void C_005D0CA0(void);
extern void C_005D1050(int, void (*)(void));//Battle.yama.inits:...
extern void C_005D1520(void);
extern void C_005D16D0(void);
extern void C_005D173F(void);
extern void C_005D17C7(void);
extern unsigned short C_005D191A(void);//...:16 bit random?
extern int C_005D1924(void);//...:get random percentage?
extern int C_005D1960(unsigned short);//...:bit count
extern unsigned short C_005D19A4(unsigned short);
extern void C_005D1B1B(float, float, float);
extern void C_005D1B44(int, float);
extern void C_005D1B64(int, float);
extern void C_005D1B7A(struct t_dx_sfx_e0 *);//set complex blend state 5
extern void *C_005D1BA4(struct t_battle_temp_test_1 *, void *, int, void *);
extern void *C_005D1FFB(struct t_battle_temp_hitmark *, void *, int, void *);
extern void *C_005D25C2(struct t_battle_temp_must_move *, void *, int, void *);
extern void C_005D2A30(struct MATRIX *, struct MATRIX *, struct MATRIX *);
extern struct MATRIX *C_005D2AA5(struct SVECTOR *, int, struct MATRIX *);
extern struct MATRIX *C_005D2B44(struct SVECTOR *, short, int);
extern void C_005D2C1F(struct SVECTOR *, struct MATRIX *);
extern void C_005D2D1B(struct MATRIX *);
extern void C_005D2E00(int, int, struct SVECTOR *);
extern void C_005D2ED1(struct MATRIX *, struct SVECTOR *);
extern void C_005D2F40(short, struct SVECTOR *);//make the center of a group?
extern void C_005D301C(short, short, struct SVECTOR *);
extern void C_005D30AC(struct SVECTOR *, struct SVECTOR *, short, int);
extern void C_005D317B(struct SVECTOR *, struct SVECTOR *, struct VECTOR *, int);
extern int C_005D3240(struct VECTOR *, struct VECTOR *, struct VECTOR *);
extern void C_005D32F1(int, struct MATRIX *, struct VECTOR *);
extern short C_005D354C(struct SVECTOR *, struct SVECTOR *, struct VECTOR *);
extern void C_005D3601(void);
extern struct t_battle3d_char_94 *C_005D3650(int, int, const char *);
extern void C_005D37D7(int, LPD3DMATRIX, int, struct t_battle3d_char_94 *);
extern void *C_005D38D0(struct t_battle_dontKnowYet *, void *, int, void *, struct t_dx_sfx_e0 *, struct t_dx_sfx_e0 *, struct t_dx_sfx_e0 *, struct t_dx_sfx_e0 *);//(for riva)

extern void C_005D7FE4(int, void *, int);
extern void C_005D969C(short, short, short);
extern int C_005D975B(int);
extern void C_005D9799(int, int);
extern void C_005D97D5(int, int);
extern void C_005D9550(int, int, int);

extern void C_005DC390(void);
extern int C_005DC880(int);

extern void C_005DD700(int);

extern struct t_menu_temp_1c *C_005DF080(int);
extern void C_005DF0F0(void);
extern void C_005DF30B(int, int, int, int);
extern void C_005DF3ED(void);
extern void C_005DF460(void);
extern void C_005DF5D7(void);
extern void C_005DF95A(void);
extern void C_005DFB5C(void);
extern void C_005DFBEE(void);
extern void C_005DFC52(void);
extern void C_005DFD5B(void);
//-- bdata.cpp --
extern void C_005DFDC0(struct t_battle_char_44 *);//bdata:...
extern const char *C_005DFDF1(void);//get path [D_008FF290]
extern void C_005DFDFB(const char *);//set path [008FF290]
extern void C_005DFE08(struct t_battle_path_cc *);//current dir to D_008FF290[battle]
extern void C_005DFE51(struct t_battle_path_cc *);//original current dir[battle]
extern void C_005DFEBB(const char *);//set path [008FF294]
extern void C_005DFEC8(struct t_file_10 *, struct t_battle_path_cc *);//bdata:...
extern void C_005DFF15(struct t_file_10 *, struct t_battle_path_cc *);//bdata:...
extern char *C_005DFF37(const char *, char *);//bdata:init path
extern const char *C_005DFF79(void);//bdata:get path
extern void C_005DFF83(const char *);//bdata:set path
extern struct t_rsd_0c *C_005E0154(int, int, const char *, struct t_tim_info *);
extern struct t_rsd_0c *C_005E0173(int);
//-- char.cpp --
extern void C_005E0200(struct t_battle3d_char_94 *);//battle3d.char:release something?
extern struct t_battle3d_char_94 *C_005E02E9(int, int);//char:....
extern void C_005E0D3C(int, int, int, struct t_battle3d_char_94 *);
extern void C_005E0DDE(int, int, int, int, struct t_battle3d_char_94 *);
extern void C_005E0EED(int, struct t_battle_DAT_Header *);//battle3d.char:release something?
extern void C_005E0F2D(struct t_battle_DAT_Header *);//char:...
extern struct t_battle_DAT_Header *C_005E0F67(int, int);//char:...
extern struct t_battle_DAT_Header *C_005E0FC0(int, struct t_file_10 *, const char *);//char:...
extern void C_005E10B9(struct t_battle_DAT_Header *, const char *);//char:...
extern void C_005E1155(struct t_char_local_0c *, struct tSkeleton *);//char:...
extern void C_005E1463(int, void *, const char *);//char:save buffer as ".B" file?
extern struct t_battle3d_char_94 *C_005E149A(int, int, struct t_battle_DAT_Header *, struct t_battle_char_44 *, struct t_rsd_74 *, const char *);
extern void C_005E1749(struct t_battle3d_char_94 *, struct t_battle_char_44 *, struct t_rsd_74 *, const char *);//char:...
extern struct t_battle3d_char_94 *C_005E1868(int, int, struct t_battle_char_44 *, struct t_rsd_74 *);//battle3d.char:alloc something?
extern struct t_battle3d_char_94 *C_005E1AD2(int, int, struct t_battle_char_44 *, struct t_rsd_74 *, const char *);//battle3d.char:alloc something(2)?
extern struct t_b3ddata_0c *C_005E1BC6(int, int, struct t_battle_char_44 *, struct t_rsd_74 *, const char *);//char:allocate stage?
extern void C_005E2908(const char *, char *);//char:...
//-- --limitbrk.cpp --
extern void C_005E2A10(struct t_battle3d_char_94 *);//limitbrk:release something?
extern void C_005E2A85(int, struct t_battle_char_44 *, struct t_battle3d_char_94 *, const char *);//limitbrk:...
//-- stace.cpp --
extern void C_005E2F00(struct t_b3ddata_0c *);//stage:...
extern struct t_b3ddata_0c *C_005E2F49(int, struct t_battle_char_44 *, struct t_rsd_74 *, const char *);//stage:allocate/convert?[looks like C_005E0370/C_005E3900]
extern int C_005E3592(int);//stage:V_DEPTHTEST/V_DEPTHMASK option related?
extern void C_005E35AB(tRGBA, int, struct t_b3ddata_0c *);//stage:render one model
extern struct t_rsd_0c *C_005E383E(int, struct t_b3ddata_0c *);//stage:...
extern void C_005E388D(int, struct t_b3ddata_0c *);//stage:...
//-- --
extern struct t_battle3d_char_94 *C_005E3900(struct t_battle_char_44 *, struct t_rsd_74 *, const char *);//enemy:...
//-- --
extern void C_005E4408(struct t_lmd_1618 *);//lmd:...
extern struct t_lmd_1618 *C_005E4438(int, struct t_tim_info *);//lmd:...
extern struct tPolygonData *C_005E44DF(struct t_battle_char_44 *, void *, struct t_lmd_1618 *, struct t_tim_info *);//lmd:monster function
extern void C_005E6FE8(struct t_lmd_1618 *, struct t_tim_info *);//lmd:...
extern void C_005E72FE(int, const char *, char *);//make texture extension:"Pxx"?
extern void C_005E7319(int, const char *, char *);//make texture extension:"Wxx"?
extern struct t_rsd_0c *C_005E754A(struct t_battle_char_44 *, int, const char *, struct tPolygonData *, struct t_tim_info *, struct t_rsd_74 *, struct t_lmd_1618 *, struct t_aa0 *);//lmd:load rsd data?
extern struct t_rsd_0c *C_005E75A2(struct t_battle_char_44 *, void *, struct t_tim_info *, struct t_rsd_74 *, struct t_lmd_1618 *, const char *);//lmd:...
//-- amptoanm.cpp --
extern struct t_animationHeader *C_005E806A(int *, int, int, int, void *, int, int, const char *);//amptoanm:...
extern struct t_file_18 *C_005E81FF(int, int, const char *);//amptoanm:kind of open
extern void C_005E8285(struct t_file_18 *);//amptoanm:kind of close?
extern void C_005E8296(int, int, int, void *, struct t_file_18 *);//amptoanm:kind of write?
extern void C_005E82DE(int, int, struct t_animationHeader **, struct t_file_10 *, const char *);//amptoanm:...
extern struct t_animationHeader *C_005E840D(int, int, struct t_file_10 *, const char *);//amptoanm:...
//-- mdl.cpp --
extern struct tSkeleton *C_005E8550(struct t_battle_char_44 *, int, int, void *, struct t_tim_info *, struct t_rsd_74 *, const char *);//mdl:...
////////////////////////////////////////
extern const void (*D_007B77A8[])(void);
extern const char *D_007C1098[];
extern int D_007C10D8;
extern int D_007C10DC;
extern /*const */char *D_007C27B8[];

extern struct VECTOR D_008FE110;// = {0x0000,-0x1000,0x0000,0};
extern struct VECTOR D_008FE120;// = {0x1000, 0x1000,0x1000,0};
//scratchpads?
extern void *D_008FE2AC;// = &D_00C06028;
extern void *D_008FE2B0;// = &D_00C06228;
extern void *D_008FE2B4;// = &D_00C06328;

extern void (*D_008FE398[])(int, int);
extern void (*D_008FE4B0[])(int, int);
extern void (*D_008FE588[])(int, int);
extern void (*D_008FE5E8[])(int, int);
extern int (*D_008FE860[])(int, int);
extern void (*D_008FE9A0[])(int, int);

extern void (*D_008FEE48[])(void);

extern void (*D_008FF1F8[])(void);

extern unsigned char *D_009010D0[];//in D_00900198.cpp
extern unsigned char *D_00901270[];//in D_00900198.cpp

extern short D_0091EF9C;

extern int D_0099CE08;
extern struct t_battle_resolution *D_0099CE0C;//extern int *D_0099CE0C;
extern struct t_combat_static_f94 D_0099CE10;

extern struct t_battle_progress_info D_0099E2C0;

extern unsigned char *D_009A13A8;
extern void *D_009A13AC;

extern int D_009A13B4;//???
extern int D_009A13B8;//???
extern void *D_009A13BC;//in smcdfile.cpp?C_00419360.cpp?

extern struct t_combat_178 D_009A8748;
extern char D_009A88C0[/*0x100*/];//path
extern unsigned short D_009A89C0;
extern LARGE_INTEGER D_009A89C8;
extern int D_009A89D0;
extern LARGE_INTEGER D_009A89D8;
extern int D_009A89E0;
extern int D_009A89E4;
extern LARGE_INTEGER D_009A89E8;
extern char D_009A89F8[/*0x100*/];//path
extern int D_009A8AF8;
extern int D_009A8AFC;
extern int D_009A8B00;
extern unsigned short D_009A8B04;
extern unsigned short D_009A8B08;

extern struct t_battle_222c D_009A8B10;
extern int D_009AAD3C;
extern int D_009AAD40;
extern int D_009AAD44;
extern int D_009AAD48;
extern int D_009AAD4C;//viewport x
extern int D_009AAD50;//viewport y
extern int D_009AAD58;
extern int D_009AAD5C;//viewport width
extern int D_009AAD60;
extern int D_009AAD64;
extern int D_009AAD68;
extern unsigned short D_009AAD6C;
extern struct t_unk_0c_1 D_009AAD70[/*0x40*/];
extern int D_009AB070;
extern int D_009AB074;
extern int D_009AB078;
extern LARGE_INTEGER D_009AB080;
extern LARGE_INTEGER D_009AB088;
extern double D_009AB090;
extern int D_009AB098;
extern struct t_battle_94c D_009AB0A0;
extern int D_009AB9EC;
extern int D_009AB9F0;
extern int D_009AB9F4;
extern int D_009AB9F8;
extern int D_009ABA00;
extern int D_009ABA04;
extern struct t_battle_graphicalDamage_0e D_009ABA08[/*0x80*/];
extern int D_009AC108;
//009ac10c
extern unsigned char D_009AC110,D_009AC111;
extern struct t_battle_menuEntryInfo D_009AC114[/*6*/][16];
extern struct t_battle_menu_06_B D_009AC354[/*0x140*/];//combat related?
extern struct t_loadmenu_charaInfo D_009ACAD4;
extern int D_009ACB58;
extern int D_009ACB5C;//graphic mode
extern int D_009ACB64;
extern int D_009ACB68;
extern LARGE_INTEGER D_009ACB70;
extern LARGE_INTEGER D_009ACB78;
extern int D_009ACB80;
extern int D_009ACB84;
extern int D_009ACB88;//viewport height
extern int D_009ACB8C;
extern int D_009ACB90;
extern struct t_battle_yet_another_0c D_009ACB98[/*0x80*/];
extern int D_009AD198;
extern LARGE_INTEGER D_009AD1A0;
extern int D_009AD1A8;
extern int D_009AD1AC;//pause related?
extern unsigned char D_009AD1B0[4];
extern int D_009AD1B4;
extern int D_009AD1B8;//a counter for battle?
extern void (*D_009AD1BC)(int);
extern void (*D_009AD1C0)();
extern void (*D_009AD1C4)();
extern int D_009AD1C8;
extern int D_009AD1CC;
extern int D_009AD1D0;
extern int D_009AD1D4;
extern double D_009AD1D8;
extern struct t_b3ddata_4f4 *D_009ADFD8;

extern int D_009AEA68;

extern int D_009AEA78;

extern struct t_plytopd_74 D_00AED5C0[];

extern struct t_battle_40 D_00BE0E28[];

extern unsigned char D_00BE10A8[/*0xa*/];
extern unsigned char D_00BE10B4;
extern short D_00BE10B8;//current task"CAM"
extern void (*D_00BE10C0[/*0xa*/])(void);//task"C" callbacks?
extern short D_00BE10E8;//task"E" count?
extern char D_00BE10EC;
extern struct t_battle_cam_0e D_00BE10F0[4];
extern struct t_battle_40f4 *D_00BE1128;//scratchpad pointer?
extern struct t_battle_cam_0e D_00BE1130[4];

extern char D_00BE1168;

extern char D_00BE1170;
extern struct t_b3ddata_1aec D_00BE1178[];
extern char D_00BF1EB0;
extern struct t_battle_local_6_JJJJ D_00BF1EB8[/*0x40*/];

extern char D_00BF2040;//enemies types count
extern int D_00BF2044[3];//enemies types
extern char D_00BF2050;//enemie count
extern struct t_battle_temp_0c D_00BF2054[];

extern unsigned char D_00BF211C;
extern int D_00BF2120;
extern char D_00BF2128;
extern struct MATRIX D_00BF2130;
extern char D_00BF2150;
extern short D_00BF2154;
extern struct SVECTOR D_00BF2158;
extern char D_00BF2164;
extern struct t_battle_local_34 D_00BF2168[/*0xa*/];

extern char D_00BF2370;

extern void (*D_00BF2378[/*0x10*/])(void);//task"CAM" callbacks?
extern short D_00BF23B8;//current task""?
extern unsigned char D_00BF23BC;

extern struct t_battle_74 D_00BF23C0[/*0xa*/];
extern int D_00BF2848;
extern char D_00BF284C;
extern char D_00BF2850;

extern void (*D_00BF2858[/*0x64*/])(void);//task"" callbacks?

extern char D_00BF2A28;
extern char D_00BF2A2C;
extern char D_00BF2A30;
extern char D_00BF2A34;
extern char D_00BF2A38;

extern struct t_battle_0c_1 D_00BF2A40[];

extern char D_00BF2DE8;
extern char D_00BF2DEC;
extern short D_00BF2DF0;
extern short D_00BF2DF4;//current task"E"?
extern char D_00BF2DF8[/*0xa*/];
extern char D_00BF2E04;
extern unsigned short D_00BF2E08;
extern char D_00BF2E0C;
extern short D_00BF2E10[/*3*/][2];
extern char D_00BF2E1C;
extern struct t_CharaScreenCoords D_00BF2E20[/*0xa*/];
extern struct t_battle_20_1 D_00BF2E70[/*0xa*/];
extern struct t_battle_40f4 D_00BF2FB0[];//scratchpad?TODO
extern char D_00BFB198;
extern struct SVECTOR D_00BFB1A0;
extern short D_00BFB1A8;

extern void (*D_00BFB1B0[/*0x3c*/])(void);//task"E" callbacks?

extern char D_00BFB2A0;
extern int D_00BFB2A8[/*3*/];
extern struct t_battle3d_char_94 *D_00BFB2B8[/*7*/];

extern short D_00BFB2D4;
extern short D_00BFB2D8;
extern char D_00BFB2DC;
extern void *D_00BFB2E0;
extern char D_00BFB2E4;
extern short D_00BFB2E8;
extern char D_00BFB2EC;

extern char D_00BFB710;

extern struct t_battle_20_2 D_00BFB718[/*0x64*/];
extern char D_00BFC398;

extern struct t_battle_20_3 D_00BFC3A0[/*0x3c*/];

extern short D_00BFCB20;
extern char D_00BFCB28;
extern short D_00BFCB2C;
extern struct t_battle_local_34 D_00BFCB30;
extern unsigned char D_00BFCB64;
extern char D_00BFCB68;
extern struct t_battle_still_another_8 D_00BFCB70[/*0x4e*/];//unsigned char D_00BFCB70[0x270];
extern char D_00BFCDE0;
extern char D_00BFCDE4;
extern unsigned char D_00BFCDE8;
extern short D_00BFCDEC[/*2*/];
extern char D_00BFCDF0[];
extern char D_00BFCDF8;
extern char D_00BFCDFC;
extern struct SVECTOR D_00BFCE00;
extern struct t_battle_cam_type1_28 D_00BFCE08[];

extern char D_00BFD088;
extern short D_00BFD08C;
extern short D_00BFD090;
extern char D_00BFD094;

extern struct t_battle_06 D_00BFD0A0[];

extern short D_00BFD098;//task"CAM" count?

extern char D_00BFD0DC;
extern unsigned char D_00BFD0E0;
extern char D_00BFD0E4;
extern short D_00BFD0E8;//task"C" count?
extern int D_00BFD0EC;
extern char D_00BFD0F0;
extern char D_00BFD0F4;
extern short D_00BFD0F8;

extern char D_00C02204[];
extern char D_00C05A04[];
extern unsigned char D_00C05E68[/*0x4e*/];
extern short D_00C05EB8;
extern short D_00C05EBC;//task"" count?
extern short D_00C05EC0;//current task"C"
extern char D_00C05EC8[4];//maybe tRGBA?
extern short D_00C05ECC;
extern struct t_battle_local_34 D_00C05ED0[];
extern char D_00C05F6C;
extern short D_00C05F70;
extern short D_00C05F74;
extern char D_00C05F78;
extern short D_00C05F7C;
extern char D_00C05F80;

extern int &D_00C05FE8;
extern int &D_00C05FEC;
extern int &D_00C05FF0;
extern int &D_00C05FF4;
extern int &D_00C05FF8;
extern int &D_00C05FFC;
extern int &D_00C06000;
extern int &D_00C06004;

//extern char D_00C06028[0x200];
//extern char D_00C06228[0x100];
//extern char D_00C06328[0x100];

//extern char D_00C0661C;
//extern struct MATRIX D_00C06620;

extern struct t_battle_someScratchpad_1 D_00C06640_bis;
extern struct t_battle_someScratchpad_2 D_00C06640;

extern unsigned char D_00C06720[/*4 or 3*/];
extern unsigned char D_00C06724[/*4 or 3*/];

extern unsigned char D_00C068B4;
extern struct t_menu_shop_local___ *D_00C06910;
extern unsigned char D_00C06914;

extern unsigned short D_00C069B0[/*3*/];

extern int *D_00C06A60;

extern void *D_00C1EA68;

//unsigned char D_00C3F390[0x178];
//unsigned char D_00C3F508[0x178];
//unsigned char D_00C3F680[];
//int D_00C3F6DC;
//====---- ----====

#endif

/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#define __FF7FILE__ "C:\\FF7\\chocobo\\ch_init.cpp"

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
tRGBA D_0096E0F0[6] = {
	{0x00,0x50,0x00,0x00},
	{0x00,0x00,0x50,0x00},
	{0x50,0x14,0x28,0x00},
	{0x50,0xD8,0xD8,0x00},
	{0x28,0xD8,0x50,0x00},
	{0x50,0x50,0x50,0x00}
};
tRGBA D_0096E108[] = {
	/*0096E108*/{0x50,0x50,0x00,0x00},
	/*0096E10C*/{0x00,0x50,0x00,0x00},
	/*0096E110*/{0x00,0x50,0x50,0x00},
	/*0096E114*/{0xB0,0xB0,0xB0,0x00},
	/*0096E118*/{0x63,0x2F,0x8B,0x00},
	/*0096E11C*/{0x00,0x00,0x00,0x00},
	/*0096E120*/{0x50,0x50,0x00,0x00},
	/*0096E124*/{0x00,0x50,0x00,0x00},
	/*0096E128*/{0x00,0x50,0x50,0x00},
	/*0096E12C*/{0xB0,0xB0,0xB0,0x00},
	/*0096E130*/{0x33,0x09,0xE5,0x00},
	/*0096E134*/{0x00,0x00,0x00,0x00},
};
struct t_chocobo_local_xxx {
	char f_00[4];
	tRGBA f_04;
	short f_08[2];
	unsigned char f_0c[4];
	short f_10[2];
	unsigned char f_14[4];
	short f_18[2];
	unsigned char f_1c[4];
	short f_20[2];
	unsigned char f_24[4];
};
struct t_chocobo_local_xxx D_0096E138 = {
	{0x00,0x00,0x00,0x00},
	{0x80,0x80,0x80,0x00},
	{0x0FC,0x018},
	{0x00,0x00,0x00,0x00},
	{0x13C,0x018},
	{0x40,0x00,0x00,0x00},
	{0x0FC,0x038},
	{0x00,0x20,0x00,0x00},
	{0x13C,0x038},
	{0x40,0x20,0x00,0x00}
};
struct t_chocobo_local_xxx D_0096E160 = {
	{0x00,0x00,0x00,0x00},
	{0x80,0x80,0x80,0x00},
	{0x014,0x078},
	{0xEC,0x9F,0x00,0x00},
	{0x024,0x078},
	{0xFB,0x9F,0x00,0x00},
	{0x014,0x0D8},
	{0xEC,0xFF,0x00,0x00},
	{0x024,0x0D8},
	{0xFB,0xFF,0x00,0x00}
};
////////////////////////////////////////
tRGBA D_00E3B628[6];
char D_00E3B640[0x100];
int D_00E3B740;//current state(menu/race/...)
int D_00E3B744;
int D_00E3B748;
int D_00E3B74C;//long/short courseflag
int D_00E3B750;
void *D_00E3B754;
struct t_chocobo_48 D_00E3B758[6];
struct t_chocobo_48 D_00E3B908;
struct t_chocobo_48 D_00E3B950;
struct t_chocobo_48 D_00E3B998;
struct t_chocobo_48 D_00E3B9E0;
char *D_00E3BA28;
//00e3ba2c
//-- ch_app.cpp --
//D_00E3BA30~D_00E3BAD4
//-- --
//00E3BAD8~
int D_00E3BAF4;
//00E3BAF8~
int D_00E70FE8;
int D_00E70FEC;
int D_00E71000[6];//chocobo signed distance from camera
int D_00E71018;//some frame counter
int D_00E7101C;
int D_00E71020[6];//"visible chocobo" flags
int D_00E71038;
int D_00E7103C;
struct SVECTOR D_00E71040;
//00E71048
int D_00E7104C;
//00E71050
int D_00E71054;
//00E71058
struct t_chocobo_ranking_8 D_00E71068[5][3];
int D_00E710E0;
int D_00E710E4;
int D_00E710E8;
int D_00E710EC;
int D_00E710F0;
//00E710F4
int D_00E710F8;
int D_00E710FC;
int D_00E71100;//previous input mask
int D_00E71104;
int D_00E71108;//# sprites rendered(stat)?
//00E7110C
struct t_chocobo_cameraInfo D_00E71110;
int D_00E71124;
int D_00E71128;
struct t_chocobo_TrackInfo *D_00E7112C;
int D_00E71130;
int D_00E71134;
struct MATRIX D_00E71138;
struct t_chocobo_a4 D_00E71158[6];
struct t_chocobo_a4 D_00E71530;
int D_00E715D4;
int D_00E715D8;
int D_00E715DC;
//00E715E0~
struct t_chocobo_data_18 *D_00E715FC;
int D_00E71600;
//00E71604~
//-- C_0076DDF0.cpp--
//extern unsigned D_00E71620;
//extern int D_00E71624;
//extern int D_00E71628[/*15*/];
//-- --
struct t_sound_related_24 *D_00E71664;
//-- C_0076E1F0.cpp --
//int *D_00E71668;
//int D_00E7166C;
//-- C_0076E2B0.cpp --
//struct t_chocobo_48 D_00E71670[6];
//int D_00E71820[6];
//struct t_chocobo_48 D_00E71838[6];
//-- --
struct t_chocobo_3c *D_00E719E8;
	unsigned short D_00E719EC;
	unsigned short D_00E719EE;
//00E719F0~
struct t_chocobo_local_1c D_00E71BD4;
struct t_chocobo_local_1c D_00E71BF0;
struct t_chocobo_local_1c D_00E71C0C;
struct t_chocobo_local_1c D_00E71C28;
struct t_chocobo_local_1c D_00E71C44;
struct t_chocobo_unknown_54 D_00E71C60[0x28];//check
int *D_00E72980;
int D_00E72984;
int D_00E72988;
//00E7298C
struct t_chocobo_local_1c D_00E72990[0x28];//check
struct t_chocobo_local_1c D_00E72DF0;
int D_00E72E0C;
struct SVECTOR D_00E72E10;
D3DMATRIX D_00E72E18;
short D_00E72E58;
short D_00E72E5C;
D3DMATRIX D_00E72E60;
struct SVECTOR D_00E72EA0;
//00E72EA8
struct MATRIX D_00E72EB0;
struct SVECTOR D_00E72ED0;
struct SVECTOR D_00E72ED8;
int D_00E72EE0;
//00E72EE4
//-- C_00772340.cpp --
//int D_00E72EEC;
//-- C_00776370.cpp --
//D_00E72EF0~D_00E73C0C
//-- ch_ddraw.cpp --
//int D_00E73C10;
//int D_00E73C14;
//int D_00E73C18;
//int D_00E73C1C;
//LPDIRECTDRAW D_00E73C20;
//LPDIRECTDRAWSURFACE D_00E73C24;
//LPDIRECTDRAWSURFACE D_00E73C28;
//-- C_00779850.cpp --
//unsigned D_00E73C30[8];
//unsigned D_00E73C50[8];
//unsigned D_00E73C70[8];
//unsigned D_00E73C90[8];
//unsigned D_00E73CB0[8];
//unsigned D_00E73CD0[8];
//unsigned D_00E73CF0[8];
//unsigned D_00E73D10[8];
//unsigned D_00E73D30[8];
//unsigned D_00E73D50[8];
//-- --
//00E73D70~
//-- C_00779C90.cpp --
//struct MATRIX D_00E73DB0;
//unsigned char D_00E73DD0;
//00E73DD4~
//D3DMATRIX D_00E73E60;
//00E73EA0~
//double D_00E73EE0;
//int D_00E73EE8;
//int D_00E73EEC;
//struct t_chocobo_data_18 *D_00E73EF0;
//int D_00E73EF4;
//int D_00E73EF8;
//int D_00E73EFC;
//-- --
////////////////////////////////////////
//chocobo:set path
void C_0076B850(char const *bp08) {
	strcpy(D_00E3B640, bp08);
}

void C_0076B87E() {
	struct {
		int dwDevMask;//local_2
		struct t_aa0 *local_1;
	}lolo;

	lolo.local_1 = C_00676578();
	if(D_00DC0AE4)
		D_00DC0AE5 = 0xff;
	if(D_00DC0AE5)
		D_00E71128 = -1;
	else
		D_00E71128 = 0;
	D_00E3B744 = D_00E71128;
	if(D_00DC0AE3)
		D_00E3B74C = 1;
	else
		D_00E3B74C = 0;
	D_00E3B748 = D_00DC0AF3;
	D_00E3B740 = 0;
	D_00E71130 = D_00DC0AF3;
	if(D_00E3B74C == 0)
		D_00E710E4 = 0x49D;
	else
		D_00E710E4 = 0x3B1;
	D_00E71038 = 0;
	D_00E710EC = 0xff;
	D_00E715D4 = -0x10;
	D_00E71600 = (D_00DBFD38.f_0ba4[0x000] + (D_00DBFD38.f_0ba4[0x001] << 8)) >= 1000?-1:0;
	D_00E71054 = 1;
	//-- some cheat code:change jockey? --
	C_0076DF8C();//chocobo:refresh input
	C_0076E149();//chocobo:compute input mask
	lolo.dwDevMask = D_00E71620 >> 16;
	if((lolo.dwDevMask & (BIT(7)|BIT(6)|BIT(5)|BIT(4))) == (BIT(7)|BIT(6)|BIT(5)|BIT(4))) {
		if(lolo.dwDevMask & BIT(3))
			D_00DC0AE2 = 1;
		if(lolo.dwDevMask & BIT(1))
			D_00DC0AE2 = 2;
	}
	//-- --
	D_00E7101C = (D_00E71130 + 3) * 2;
	D_00E71018 = 0;
	D_00E70FEC = 0;
	D_00E71624 = 0;
	D_00E710FC = -1;
	D_00E7103C = -1;
	D_00E715D8 = 0;
	D_00E710E0 = 0;
	D_00E710F8 = 0;
	D_00E7104C = 1;
	D_00E715DC = -1;
	D_00E710E8 = 0;
	D_00E71134 = -1;
	D_00E71158[0].f_94 = 0x1e;
	D_00E71624 = 0;
}

void C_0076BA66() {
	D_00E71664->f_00 = 0x23;
	D_00E71664->f_04[0] = 0x40;
	D_00E71664->f_04[4] = 0;
	D_00E71664->f_04[3] = 0;
	D_00E71664->f_04[2] = 0;
	D_00E71664->f_04[1] = 0;
	C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], D_00E71664->f_04[1], D_00E71664->f_04[2], D_00E71664->f_04[3], D_00E71664->f_04[4], 0, 0, 0);
}

void C_0076C01F(int);
void C_0076C57E(int, int);
void C_0076D316(void);

void C_0076BAFD(struct t_aa0 *bp08, struct t_rsd_74 *bp0c) {
	struct {
		int i;//local_5
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_4 = 0;
	lolo.local_3 = 0;
	lolo.local_2 = 0x140;
	lolo.local_1 = 0x1e0;
	C_00770800(bp08, bp0c, D_00E3B744, D_00E3B748);
	C_0076F1B0(bp0c, bp08, D_00E3B74C);//ch_chr:init(1)?
	C_0067455E(bp0c);//rsd:init with blend mode 4?
	bp0c->dwRSDFlags |= RSD_02000000;
	C_00674659(4, bp0c);//rsd:set blend mode?
	C_0076FF60(bp08, bp0c);//chocobo:init this module
	C_0076F920(bp0c, bp08, D_00E3B74C);//ch_chr:init(2)?
	psx_SetGeomOffset(320 / 2, 240 / 2);
	psx_SetGeomScreen(270);
	D_00E71040.f_00 = 0;
	D_00E71040.f_02 = 0;
	D_00E71040.f_04 = 0;
	C_0076D316();//<empty>
	C_0076C57E(D_00DC0AE3, D_00DC0AF3);
	C_0076E22F();//chocobo:load/prepare SFX
	D_00E71110 = D_00E7112C->f_38[0];
	if(D_00E71128)
		D_00E71110.bType = -1;
	D_00E3B750 = D_00E7112C->f_3c;
	D_00E71110.bType = -1;
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		D_00E3B758[lolo.i].f_00 = 0x19;
		D_00E3B758[lolo.i].f_04.c.r = (lolo.i & 2)?0xff:0;
		D_00E3B758[lolo.i].f_04.c.g = (lolo.i & 4)?0xff:0;
		D_00E3B758[lolo.i].f_04.c.b = (lolo.i & 1)?0xff:0;
		D_00E3B758[lolo.i].wV = 0;
		D_00E3B758[lolo.i].wU = 0;
		D_00E3B758[lolo.i].fZ = 0.222f;
	}//end for
	D_00E3B908.f_14[0].wX = D_00E3B908.f_14[2].wX = D_00E3B908.f_14[0].wY = D_00E3B908.f_14[1].wY = 0;
	D_00E3B908.f_14[1].wX = D_00E3B908.f_14[3].wX = 0x140;
	D_00E3B908.f_14[2].wY = D_00E3B908.f_14[3].wY = 0xe8;
	D_00E3B908.dwWidth = 0x140;
	D_00E3B908.dwHeight = 0xE8;
	D_00E3B908.fZ = 0.001f;
	D_00E3B908.wU = D_00E3B908.wV = 0;
	D_00E3B908.f_44 = 1;
	//-- --
	D_00E3B908.f_00 = 0x19;
	D_00E3B950.f_04.c.r = D_0096E138.f_04.c.r; D_00E3B950.f_04.c.g = D_0096E138.f_04.c.g; D_00E3B950.f_04.c.b = D_0096E138.f_04.c.b;
	D_00E3B950.f_14[0].wX = D_0096E138.f_08[0]; D_00E3B950.f_14[0].wY = D_0096E138.f_08[1];
	D_00E3B950.f_14[1].wX = D_0096E138.f_10[0]; D_00E3B950.f_14[1].wY = D_0096E138.f_10[1];
	D_00E3B950.f_14[2].wX = D_0096E138.f_18[0]; D_00E3B950.f_14[2].wY = D_0096E138.f_18[1];
	D_00E3B950.f_14[3].wX = D_0096E138.f_20[0]; D_00E3B950.f_14[3].wY = D_0096E138.f_20[1];
	D_00E3B950.wU = D_0096E138.f_0c[0];
	D_00E3B950.wV = D_0096E138.f_0c[1];
	D_00E3B950.dwWidth = 0x40;
	D_00E3B950.dwHeight = 0x20;
	D_00E3B950.fTexWidth = 0.98f;
	D_00E3B950.fTexHeight = 0.97f;
	D_00E3B950.fZ = 0.444f;
	//-- --
	D_00E3B950.f_00 = 0x13;
	D_00E3B950.f_30 = 0;
	D_00E3B950.f_44 = 1;
	D_00E3B9E0.f_04.c.r = D_0096E160.f_04.c.r; D_00E3B9E0.f_04.c.g = D_0096E160.f_04.c.g; D_00E3B9E0.f_04.c.b = D_0096E160.f_04.c.b;
	D_00E3B9E0.f_14[0].wX = D_0096E160.f_08[0]; D_00E3B9E0.f_14[0].wY = D_0096E160.f_08[1];
	D_00E3B9E0.f_14[1].wX = D_0096E160.f_10[0]; D_00E3B9E0.f_14[1].wY = D_0096E160.f_10[1];
	D_00E3B9E0.f_14[2].wX = D_0096E160.f_18[0]; D_00E3B9E0.f_14[2].wY = D_0096E160.f_18[1];
	D_00E3B9E0.f_14[3].wX = D_0096E160.f_20[0]; D_00E3B9E0.f_14[3].wY = D_0096E160.f_20[1];
	D_00E3B9E0.wU = 0;
	D_00E3B9E0.wV = 0;
	D_00E3B9E0.fU = 0;
	D_00E3B9E0.fV = 0;
	D_00E3B9E0.dwWidth = 0x10;
	D_00E3B9E0.dwHeight = 0x60;
	D_00E3B9E0.fWidth = 16.0f;
	D_00E3B9E0.fHeight = 96.0f;
	D_00E3B9E0.fTexWidth = 0.94f;
	D_00E3B9E0.fTexHeight = 0.75f;
	D_00E3B9E0.f_00 = 0x16;
	D_00E3B9E0.f_30 = 0;
	D_00E3B9E0.f_44 = 0;
	D_00E3B998.f_14[0].wX = D_00E3B998.f_14[2].wX = 0x19;
	D_00E3B998.f_14[1].wX = D_00E3B998.f_14[3].wX = 0x1e;
	D_00E3B998.f_14[2].wY = D_00E3B998.f_14[3].wY = 0xd1;
	D_00E3B998.dwWidth = 5;
	D_00E3B998.f_04.c.r = 0xFF; D_00E3B998.f_04.c.g = 0x14; D_00E3B998.f_04.c.b = 0x14;
	//-- --
	D_00E3B998.f_00 = 0x18;
	C_0076C01F(D_00DC0AE3);
	C_0076EEB9();
}

void C_0076C01F(int bp08) {
	struct {
		int local_9;
		struct t_chocobo_3c *local_8;
		unsigned i;//local_7
		int local_6;
		struct t_aa0 *local_5;
		struct fBGRA local_4;
	}lolo;

	lolo.local_5 = C_00676578();
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		D_00E71158[lolo.i].f_92 = lolo.i;
		lolo.local_8 = &(D_00E719E8[lolo.i]);
		lolo.local_8->f_0c = 0x280;
		if(D_00DC0AF2 && lolo.i == 1) {//else 0076C0E7
			lolo.local_4.r = -(100.0f/256.0f);//0.390625f
			lolo.local_4.g = -(100.0f/256.0f);//0.390625f
			lolo.local_4.b = -(100.0f/256.0f);//0.390625f
			lolo.local_4.a = 1.0f;
			C_00684E20(&lolo.local_4, lolo.local_8->f_34->f_b4, lolo.local_5);//anm: apply add color to skeleton?
			D_00E3B628[lolo.i].c.r =
			D_00E3B628[lolo.i].c.g =
			D_00E3B628[lolo.i].c.b = 0x40;
			//goto 0076C249
		} else if(D_00E71128 && lolo.i == 0) {//else 0076C193
			lolo.local_9 = D_00DC0AED;
			D_00E3B628[lolo.i] = D_0096E108[lolo.local_9];
			lolo.local_4.r = (float)(char)D_0096E108[lolo.local_9].c.r / 256.0f;
			lolo.local_4.g = (float)(char)D_0096E108[lolo.local_9].c.g / 256.0f;
			lolo.local_4.b = (float)(char)D_0096E108[lolo.local_9].c.b / 256.0f;
			lolo.local_4.a = 1.0f;
			C_00684E20(&lolo.local_4, lolo.local_8->f_34->f_b4, lolo.local_5);//anm: apply add color to skeleton?
			//goto 0076C249
		} else {
			D_00E3B628[lolo.i] = D_0096E0F0[lolo.i];
			lolo.local_8->f_06 = D_0096E0F0[lolo.i].c.r;
			lolo.local_8->f_07 = D_0096E0F0[lolo.i].c.g;
			lolo.local_8->f_08 = D_0096E0F0[lolo.i].c.b;
			lolo.local_4.r = (float)(char)D_0096E0F0[lolo.i].c.r / 256.0f;
			lolo.local_4.g = (float)(char)D_0096E0F0[lolo.i].c.g / 256.0f;
			lolo.local_4.b = (float)(char)D_0096E0F0[lolo.i].c.b / 256.0f;
			lolo.local_4.a = 1.0f;
			C_00684E20(&lolo.local_4, lolo.local_8->f_34->f_b4, lolo.local_5);//anm: apply add color to skeleton?
		}
	}
	//-- --
	lolo.local_6 = 6;
	//-- --
	if(D_00E71128) {
		D_00E71158[0].f_90 = D_00DC0AE2 + 6;
		lolo.local_8 = &(D_00E719E8[D_00DC0AE2 + 6]);
	} else {
		D_00E71158[0].f_90 = 0xa;
		lolo.local_8 = &(D_00E719E8[0xa]);
	}
	lolo.local_8->f_0c = 0x280;
	//-- --
	if(D_00DC0AF2) {
		D_00E71158[1].f_90 = 9;
		lolo.local_8 = &(D_00E719E8[9]);
	} else {
		D_00E71158[1].f_90 = 0xb;
		lolo.local_8 = &(D_00E719E8[0xb]);
	}
	lolo.local_8->f_0c = 0x280;
	//-- --
	for(lolo.i = 0xc; lolo.i < 0x10; lolo.i ++) {
		D_00E71158[lolo.i - 0xa].f_90 = lolo.i;
		lolo.local_8 = &(D_00E719E8[lolo.i]);
		lolo.local_8->f_0c = 0x280;
	}
	//-- --
	for(lolo.i = 0x10; lolo.i < D_00E719EC; lolo.i ++) {
		lolo.local_8 = &(D_00E719E8[lolo.i]);
		lolo.local_8->f_0c = 0x280;
	}
	//-- --
	for(lolo.i = 0; lolo.i < D_00E719EC; lolo.i ++) {
		lolo.local_8 = &(D_00E719E8[lolo.i]);
		lolo.local_8->f_09 = 0xc0;
		lolo.local_8->f_0a = 0;
		lolo.local_8->f_0b = 0x80;
	}
}

char *__0076C3C1(const char *bp08) {
	struct {
		char drive[_MAX_DRIVE]; char _ocal_197;//local_197
		char dir[_MAX_DIR];//local_196
		char ext[_MAX_EXT];//local_132
		FILE *local_68;
		int local_67;
		char *local_66;
		char fname[_MAX_FNAME];//local_65
		int local_1;
	}lolo;

	lolo.local_66 = 0;
	if(D_00972174 == 0) {//else 0076C486
		//===========
		//== DEVEL ==
		//===========
		lolo.local_68 = C_00620510(bp08, /*0096E188*/"rb");//field:fopen?
		if(lolo.local_68 == 0)
			return 0;
		lolo.local_1 = C_0062057F(lolo.local_68);//filesize?
		lolo.local_66 = (char *)mem_malloc(lolo.local_1 + 2, /*0096E18C*/__FF7FILE__, 0x203);
		if(lolo.local_66 == 0)
			return 0;
		C_0062066E(lolo.local_68, lolo.local_66, lolo.local_1);//field:fread n bytes?
		lolo.local_66[lolo.local_1] = 0;
		C_0062052E(lolo.local_68);//field:fclose?
	} else {
		//=============
		//== RELEASE ==
		//=============
		_splitpath(bp08, lolo.drive, lolo.dir, lolo.fname, lolo.ext);
		strcat(lolo.fname, lolo.ext);
		lolo.local_67 = C_006759D2(lolo.fname, ARCHIVE_07);//is_lib:get entry offset?
		if(lolo.local_67) {//else 0076C56D
			lolo.local_1 = C_006762EA(lolo.local_67, ARCHIVE_07);//is_lib:get entry size
			lolo.local_66 = (char *)mem_malloc(lolo.local_1 + 2, /*0096E1A8*/__FF7FILE__, 0x215);
			if(lolo.local_66 == 0)
				return 0;
			C_0067633E(lolo.local_67, ARCHIVE_07, lolo.local_66, lolo.local_1);//is_lib:load entry
			lolo.local_66[lolo.local_1] = 0;
		} else {
			return 0;
		}
	}

	return lolo.local_66;
}

//convert DOMEG3 to float
/*<moved>*/static void C_0076CCA1() {
	struct {
		struct t_chocobo_data_floatDG3 *pDst;//local_4
		struct t_chocobo_data_DOMEG3 *pSrc;//local_3
		unsigned short i; char _ocal_2[2];//local_2
		unsigned char cTemp; char _ocal_1[3];//local_1
	}lolo;

	D_00E7112C->pFloatDOMEG3 = (struct t_chocobo_data_floatDG3 *)mem_malloc(D_00E7112C->wNumDOMEG3 * sizeof(struct t_chocobo_data_floatDG3) + 1, /*0096E1C4*/__FF7FILE__, 0x22e);
	for(lolo.i = 0; lolo.i < D_00E7112C->wNumDOMEG3; lolo.i ++) {
		lolo.pDst = &(D_00E7112C->pFloatDOMEG3[lolo.i]);
		lolo.pSrc = &(D_00E7112C->pDOMEG3[lolo.i]);

		//
		//
		//

		//

		//
		//

		//
		//
		//

		lolo.pDst->f_24.rgba = lolo.pSrc->f_18 | 0xff000000;
		SWAP(lolo.pDst->f_24.c.r, lolo.pDst->f_24.c.b, lolo.cTemp);

		lolo.pDst->f_28.rgba = lolo.pSrc->f_1c | 0xff000000;
		SWAP(lolo.pDst->f_28.c.r, lolo.pDst->f_28.c.b, lolo.cTemp);

		lolo.pDst->f_2c.rgba = lolo.pSrc->f_20 | 0xff000000;
		SWAP(lolo.pDst->f_2c.c.r, lolo.pDst->f_2c.c.b, lolo.cTemp);

		lolo.pDst->f_00.f_00 = (float)lolo.pSrc->f_00.f_00;
		lolo.pDst->f_00.f_04 = (float)lolo.pSrc->f_00.f_02;
		lolo.pDst->f_00.f_08 = (float)lolo.pSrc->f_00.f_04;

		lolo.pDst->f_0c.f_00 = (float)lolo.pSrc->f_08.f_00;
		lolo.pDst->f_0c.f_04 = (float)lolo.pSrc->f_08.f_02;
		lolo.pDst->f_0c.f_08 = (float)lolo.pSrc->f_08.f_04;

		lolo.pDst->f_18.f_00 = (float)lolo.pSrc->f_10.f_00;
		lolo.pDst->f_18.f_04 = (float)lolo.pSrc->f_10.f_02;
		lolo.pDst->f_18.f_08 = (float)lolo.pSrc->f_10.f_04;
	}
}

//convert DG3 to float
/*<moved>*/static void C_0076CE76() {
	struct {
		unsigned dwColor_0;//local_8
		struct t_chocobo_data_floatDG3 *pDst;//local_7
		struct t_chocobo_data_DG3 *pSrc;//local_6
		unsigned short i; char _ocal_5[2];//local_5
		unsigned char cTemp; char _ocal_4[3];//local_4
		unsigned dwColor_2;//local_3
		union {
			unsigned asUnsigned;
			short asShort;
			char asByte[4];
		}local_2;
		unsigned dwColor_1;//local_1
	}lolo;

	D_00E7112C->pFloatDG3 = (struct t_chocobo_data_floatDG3 *)mem_malloc(D_00E7112C->dwNumDG3 * sizeof(struct t_chocobo_data_floatDG3) + 1, /*0096E1E0*/__FF7FILE__, 0x262);
	for(lolo.i = 0; lolo.i < D_00E7112C->dwNumDG3; lolo.i ++) {
		lolo.pDst = &(D_00E7112C->pFloatDG3[lolo.i]);
		lolo.pSrc = &(D_00E7112C->pDG3[lolo.i]);

		lolo.local_2.asShort = lolo.pSrc->f_00.f_06;
		lolo.local_2.asByte[2] = lolo.pSrc->f_08.f_06 & 0xff;
		lolo.dwColor_1 = lolo.local_2.asUnsigned;

		lolo.dwColor_0 = lolo.pSrc->f_18.rgba;

		lolo.local_2.asShort = lolo.pSrc->f_00.f_06;
		lolo.local_2.asByte[2] = lolo.pSrc->f_08.f_06 & 0xff;

		lolo.local_2.asShort = lolo.pSrc->f_10.f_06;
		lolo.local_2.asByte[2] = lolo.pSrc->f_08.f_06 >> 8;
		lolo.dwColor_2 = lolo.local_2.asUnsigned;

		lolo.pDst->f_24.rgba = lolo.dwColor_0 | 0xff000000;
		SWAP(lolo.pDst->f_24.c.r, lolo.pDst->f_24.c.b, lolo.cTemp);

		lolo.pDst->f_28.rgba = lolo.dwColor_1 | 0xff000000;
		SWAP(lolo.pDst->f_28.c.r, lolo.pDst->f_28.c.b, lolo.cTemp);

		lolo.pDst->f_2c.rgba = lolo.dwColor_2 | 0xff000000;
		SWAP(lolo.pDst->f_2c.c.r, lolo.pDst->f_2c.c.b, lolo.cTemp);

		lolo.pDst->f_00.f_00 = (float)lolo.pSrc->f_00.f_00;
		lolo.pDst->f_00.f_04 = (float)lolo.pSrc->f_00.f_02;
		lolo.pDst->f_00.f_08 = (float)lolo.pSrc->f_00.f_04;

		lolo.pDst->f_0c.f_00 = (float)lolo.pSrc->f_08.f_00;
		lolo.pDst->f_0c.f_04 = (float)lolo.pSrc->f_08.f_02;
		lolo.pDst->f_0c.f_08 = (float)lolo.pSrc->f_08.f_04;

		lolo.pDst->f_18.f_00 = (float)lolo.pSrc->f_10.f_00;
		lolo.pDst->f_18.f_04 = (float)lolo.pSrc->f_10.f_02;
		lolo.pDst->f_18.f_08 = (float)lolo.pSrc->f_10.f_04;
	}
}

//convert DG4 to float
/*<moved>*/static void C_0076D09F() {
	struct {
		unsigned dwColor_0;//local_9
		struct t_chocobo_data_floatDG4 *pDst;//local_8
		struct t_chocobo_data_DG4 *pSrc;//local_7
		unsigned short i; char _ocal_6[2];//local_6
		unsigned char cTemp; char _ocal_5[3];//local_5
		unsigned dwColor_3;//local_4
		unsigned dwColor_2;//local_3
		union {
			unsigned asUnsigned;
			short asShort;
			char asByte[4];
		}local_2;
		unsigned dwColor_1;//local_1
	}lolo;

	D_00E7112C->pFloatDG4 = (struct t_chocobo_data_floatDG4 *)mem_malloc(D_00E7112C->dwNumDG4 * sizeof(struct t_chocobo_data_floatDG4) + 1, /*0096E1FC*/__FF7FILE__, 0x2a3);
	for(lolo.i = 0; lolo.i < D_00E7112C->dwNumDG4; lolo.i ++) {
		lolo.pDst = &(D_00E7112C->pFloatDG4[lolo.i]);
		lolo.pSrc = &(D_00E7112C->pDG4[lolo.i]);

		lolo.dwColor_0 = lolo.pSrc->f_24.rgba;
		lolo.dwColor_3 = lolo.pSrc->f_20.rgba;

		lolo.local_2.asByte[2] = lolo.pSrc->f_08.f_06 >> 8;
		lolo.local_2.asShort = lolo.pSrc->f_10.f_06;
		lolo.dwColor_1 = lolo.local_2.asUnsigned;

		lolo.local_2.asShort = lolo.pSrc->f_18.f_06;
		lolo.local_2.asByte[2] = lolo.pSrc->f_20.c.a;
		lolo.dwColor_2 = lolo.local_2.asUnsigned;

		lolo.pDst->f_30.rgba = lolo.dwColor_0 | 0xff000000;
		SWAP(lolo.pDst->f_30.c.r, lolo.pDst->f_30.c.b, lolo.cTemp);

		lolo.pDst->f_34.rgba = lolo.dwColor_1 | 0xff000000;
		SWAP(lolo.pDst->f_34.c.r, lolo.pDst->f_34.c.b, lolo.cTemp);

		lolo.pDst->f_38.rgba = lolo.dwColor_2 | 0xff000000;
		SWAP(lolo.pDst->f_38.c.r, lolo.pDst->f_38.c.b, lolo.cTemp);

		lolo.pDst->f_3c.rgba = lolo.dwColor_3 | 0xff000000;
		SWAP(lolo.pDst->f_3c.c.r, lolo.pDst->f_3c.c.b, lolo.cTemp);

		lolo.pDst->f_00.f_00 = (float)lolo.pSrc->f_00.f_00;
		lolo.pDst->f_00.f_04 = (float)lolo.pSrc->f_00.f_02;
		lolo.pDst->f_00.f_08 = (float)lolo.pSrc->f_00.f_04;

		lolo.pDst->f_0c.f_00 = (float)lolo.pSrc->f_08.f_00;
		lolo.pDst->f_0c.f_04 = (float)lolo.pSrc->f_08.f_02;
		lolo.pDst->f_0c.f_08 = (float)lolo.pSrc->f_08.f_04;

		lolo.pDst->f_18.f_00 = (float)lolo.pSrc->f_10.f_00;
		lolo.pDst->f_18.f_04 = (float)lolo.pSrc->f_10.f_02;
		lolo.pDst->f_18.f_08 = (float)lolo.pSrc->f_10.f_04;

		lolo.pDst->f_24.f_00 = (float)lolo.pSrc->f_18.f_00;
		lolo.pDst->f_24.f_04 = (float)lolo.pSrc->f_18.f_02;
		lolo.pDst->f_24.f_08 = (float)lolo.pSrc->f_18.f_04;
	}
}


void C_0076C57E(int bp08, int _p0c/*race rank*/) {
	struct {
		int dwNumMAPPOINTER;//local_72
		int _ocal_71;
		FILE *local_70;
		int local_69;
		int dwNumMAPTABLE;//local_68
		char *local_67;
		char local_66[0x100];
		int local_2;
		int dwBaseOffset;//local_1
	}lolo;

	D_00E7112C = (struct t_chocobo_TrackInfo *)mem_malloc(sizeof(struct t_chocobo_TrackInfo) + 1, /*0096E218*/__FF7FILE__, 0x2ed);
	if(D_00E7112C == 0)
		return;
	D_00E7112C->f_04 = C_00772340(bp08);
	D_00E7112C->f_38 = C_00771680(bp08);
	D_00E7112C->f_40 = C_00771660(bp08);
	D_00E7112C->pSoundEvent = C_0076E1F0(bp08);//chocobo:get sounds info?
	if(D_00E3B74C == 0) {
		D_00E7112C->f_00 = 0x49d;
		D_00E7112C->f_3c = 0xf;
		D_00E7112C->dwNumDG4 = 0x1269;
		D_00E7112C->dwNumDG3 = 0x2e49;
		D_00E7112C->wNumDOMEG3 = 0x19e;
		D_00E7112C->wNumSPRITE = 0xff;
		lolo.dwBaseOffset = 0;
		lolo.dwNumMAPPOINTER = 0x4a1;
		lolo.dwNumMAPTABLE = 0x3c38;
	} else {
		D_00E7112C->f_00 = 0x3b1;
		D_00E7112C->f_3c = 0x13;
		D_00E7112C->dwNumDG4 = 0x103d;
		D_00E7112C->dwNumDG3 = 0x27a2;
		D_00E7112C->wNumDOMEG3 = 0x19e;
		D_00E7112C->wNumSPRITE = 0x5a;
		lolo.dwBaseOffset = 0x9e078;//preceded by "SHORT"
		lolo.dwNumMAPPOINTER = 0x3b5;
		lolo.dwNumMAPTABLE = 0x2f8a;
	}
	strcpy(lolo.local_66, D_00E3B640);
	strcat(lolo.local_66, /*0096E234*/"chocobo.wat");
	if(D_00972174 == 0) {
		//===========
		//== DEVEL ==
		//===========
		lolo.local_70 = C_00620510(lolo.local_66, /*0096E240*/"rb");//field:fopen?
		C_00620550(lolo.local_70, lolo.dwBaseOffset, SEEK_SET);//field:fseek?

		C_00620550(lolo.local_70, 2, SEEK_CUR);//field:fseek?
		lolo.local_67 = (char *)mem_malloc(D_00E7112C->f_00 * sizeof(struct t_chocobo_data_18), /*0096E244*/__FF7FILE__, 0x31b);
		C_0062066E(lolo.local_70, lolo.local_67, D_00E7112C->f_00 * sizeof(struct t_chocobo_data_18));//field:fread n bytes?
		D_00E7112C->f_08 = (struct t_chocobo_data_18 *)lolo.local_67;

		C_00620550(lolo.local_70, 6, SEEK_CUR);//field:fseek?
		lolo.local_67 = (char *)mem_malloc(D_00E7112C->f_00 * sizeof(struct t_chocobo_data_GUIDE), /*0096E260*/__FF7FILE__, 0x321);
		C_0062066E(lolo.local_70, lolo.local_67, D_00E7112C->f_00 * sizeof(struct t_chocobo_data_GUIDE));//field:fread n bytes?
		D_00E7112C->pGUIDE = (struct t_chocobo_data_GUIDE *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(lolo.dwNumMAPPOINTER * sizeof(short), /*0096E27C*/__FF7FILE__, 0x325);
		C_00620550(lolo.local_70, 0xc, SEEK_CUR);//field:fseek?
		C_0062066E(lolo.local_70, lolo.local_67, lolo.dwNumMAPPOINTER * sizeof(short));//field:fread n bytes?
		D_00E7112C->pMAPPOINTER = (short *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(lolo.dwNumMAPTABLE * sizeof(int), /*0096E298*/__FF7FILE__, 0x32a);
		C_00620550(lolo.local_70, 0xb, SEEK_CUR);//field:fseek?
		C_0062066E(lolo.local_70, lolo.local_67, lolo.dwNumMAPTABLE * sizeof(int));//field:fread n bytes?
		D_00E7112C->pMAPTABLE = (int *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(D_00E7112C->wNumDOMEG3 * sizeof(struct t_chocobo_data_DOMEG3), /*0096E2B4*/__FF7FILE__, 0x32f);
		C_00620550(lolo.local_70, 9, SEEK_CUR);//field:fseek?
		C_0062066E(lolo.local_70, lolo.local_67, D_00E7112C->wNumDOMEG3 * sizeof(struct t_chocobo_data_DOMEG3));//field:fread n bytes?
		D_00E7112C->pDOMEG3 = (struct t_chocobo_data_DOMEG3 *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(D_00E7112C->dwNumDG3 * sizeof(struct t_chocobo_data_DG3), /*0096E2D0*/__FF7FILE__, 0x334);
		C_00620550(lolo.local_70, 6, SEEK_CUR);//field:fseek?
		C_0062066E(lolo.local_70, lolo.local_67, D_00E7112C->dwNumDG3 * sizeof(struct t_chocobo_data_DG3));//field:fread n bytes?
		D_00E7112C->pDG3 = (struct t_chocobo_data_DG3 *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(D_00E7112C->dwNumDG4 * sizeof(struct t_chocobo_data_DG4), /*0096E2EC*/__FF7FILE__, 0x339);
		C_00620550(lolo.local_70, 6, SEEK_CUR);//field:fseek?
		C_0062066E(lolo.local_70, lolo.local_67, D_00E7112C->dwNumDG4 * sizeof(struct t_chocobo_data_DG4));//field:fread n bytes?
		D_00E7112C->pDG4 = (struct t_chocobo_data_DG4 *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(D_00E7112C->wNumSPRITE * 0x28, /*0096E308*/__FF7FILE__, 0x33e);
		C_00620550(lolo.local_70, 9, SEEK_CUR);//field:fseek?
		C_0062066E(lolo.local_70, lolo.local_67, D_00E7112C->wNumSPRITE * 0x28);//field:fread n bytes?
		D_00E7112C->pSPRITE = (struct t_chocobo_data_SPRITE *)lolo.local_67;

		C_0062052E(lolo.local_70);//field:fclose?
	} else {
		//=============
		//== RELEASE ==
		//=============
		lolo.local_69 = C_006759D2(/*0096E324*/"chocobo.wat", ARCHIVE_07);//is_lib:get entry offset?
		if(lolo.local_69) {
			lolo.local_2 = C_006762EA(lolo.local_69, ARCHIVE_07);//is_lib:get entry size
			lolo.local_67 = (char *)mem_malloc(lolo.local_2 + 2, /*0096E330*/__FF7FILE__, 0x349);
			C_0067633E(lolo.local_69, ARCHIVE_07, lolo.local_67, lolo.local_2);//is_lib:load entry
			D_00E3BA28 = lolo.local_67;
			lolo.local_67[lolo.local_2] = 0;

			lolo.local_67 += lolo.dwBaseOffset + sizeof(short);//# of objects

			D_00E7112C->f_08 = (struct t_chocobo_data_18 *)lolo.local_67;
			lolo.local_67 += D_00E7112C->f_00 * sizeof(struct t_chocobo_data_18) + 6;//"{L|S}GUIDE"

			D_00E7112C->pGUIDE = (struct t_chocobo_data_GUIDE *)lolo.local_67;
			lolo.local_67 += D_00E7112C->f_00 * sizeof(struct t_chocobo_data_GUIDE) + 0xa + sizeof(short);//"{L|S}MAPPOINTE" __ # of objects

			D_00E7112C->pMAPPOINTER = (short *)lolo.local_67;
			lolo.local_67 += lolo.dwNumMAPPOINTER * sizeof(short) + 9 + sizeof(short);//"{L|S}MAPTABLE" __ # of objects

			D_00E7112C->pMAPTABLE = (int *)lolo.local_67;
			lolo.local_67 += lolo.dwNumMAPTABLE * sizeof(int) + 7 + sizeof(short);//"{L|S}DOMEG3" __ # of objects

			D_00E7112C->pDOMEG3 = (struct t_chocobo_data_DOMEG3 *)lolo.local_67;
			lolo.local_67 += D_00E7112C->wNumDOMEG3 * sizeof(struct t_chocobo_data_DOMEG3) + 4 + sizeof(short);//"{L|S}DG3" __ # of objects

			D_00E7112C->pDG3 = (struct t_chocobo_data_DG3 *)lolo.local_67;
			lolo.local_67 += D_00E7112C->dwNumDG3 * sizeof(struct t_chocobo_data_DG3) + 4 + sizeof(short);//"{L|S}DG4" __ # of objects

			D_00E7112C->pDG4 = (struct t_chocobo_data_DG4 *)lolo.local_67;
			lolo.local_67 += D_00E7112C->dwNumDG4 * sizeof(struct t_chocobo_data_DG4) + 7 + sizeof(short);//"{L|S}SPRITE" __ # of objects

			D_00E7112C->pSPRITE = (struct t_chocobo_data_SPRITE *)lolo.local_67;
		}
	}
	C_0076CCA1();//convert DOMEG3 to float
	C_0076CE76();//convert DG3 to float
	C_0076D09F();//convert DG4 to float
	D_00E715FC = D_00E7112C->f_08;
	D_00E3B754 = 0;
}

//<moved>:void C_0076CCA1() {

//<moved>:void C_0076CE76() {

//<moved>void C_0076D09F() {

//<empty>
void C_0076D316() {
}

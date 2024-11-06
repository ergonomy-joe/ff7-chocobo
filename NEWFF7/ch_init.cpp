/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#define __FF7FILE__ "C:\\FF7\\chocobo\\ch_init.cpp"

#include "ff7.h"
#include "chocobo_data.h"
#include "psx.h"
////////////////////////////////////////
//other CHOCOBOs
tRGBA D_0096E0F0[6] = {
	{0x00,0x50,0x00,0x00},
	{0x00,0x00,0x50,0x00},
	{0x50,0x14,0x28,0x00},
	{0x50,0xD8,0xD8,0x00},
	{0x28,0xD8,0x50,0x00},
	{0x50,0x50,0x50,0x00}
};
//player's CHOCOBO
tRGBA D_0096E108[5] = {
	{0x50,0x50,0x00,0x00},
	{0x00,0x50,0x00,0x00},
	{0x00,0x50,0x50,0x00},
	{0xB0,0xB0,0xB0,0x00},
	{0x63,0x2F,0x8B,0x00}
};
//0096E11C	00 00 00 00
tRGBA __0096E120[5] = {
	{0x50,0x50,0x00,0x00},
	{0x00,0x50,0x00,0x00},
	{0x00,0x50,0x50,0x00},
	{0xB0,0xB0,0xB0,0x00},
	{0x33,0x09,0xE5,0x00}
};
//0096E134	00 00 00 00
//for map
struct POLY_FT4 D_0096E138 = {
	0,
	0x80,0x80,0x80,0,
	252,24,
	0,0,0x0000,
	316,24,
	64,0,0x0000,
	252,56,
	0,32,0x0000,
	316,56,
	64,32,0x0000
};
//for stamina gauge
struct POLY_FT4 D_0096E160 = {
	0,
	0x80,0x80,0x80,0,
	20,120,
	236,159,0x0000,
	36,120,
	251,159,0x0000,
	20,216,
	236,255,0x0000,
	36,216,
	251,255,0x0000
};
////////////////////////////////////////
tRGBA D_00E3B628[6];//[set|not used]
char D_00E3B640[256];
int D_00E3B740;//current state(menu/race/...)
int D_00E3B744;//flag:
int D_00E3B748;//race class
int D_00E3B74C;//flag:long/short course
int D_00E3B750;//dwScenaryModelCount[set|not used]
void *D_00E3B754;//[set|not used]
struct t_chocobo_SpriteUI D_00E3B758[0xa];
	//[0~5]squares for map
	//[6]transparent color layer[underwater effect]
	//[7]map
	//[8]for stamina gauge
	//[9]for stamina gauge
char *D_00E3BA28;//ptr to "chocobo.wat"[set|not used]
//00E3BA2C
//-- ch_app.cpp --
//D_00E3BA30~D_00E3BAD4
//-- --
//char __00E3BAD8[0x1c];
int D_00E3BAF4;//camera height[bType -1]?
//char __00E3BAF8[0x354f0];
int D_00E70FE8;//camera related:render last track[culling]
int D_00E70FEC;
//char __00E70FF0[0x10];
int D_00E71000[6];//chocobo signed distance from camera
int D_00E71018;//frame counter
int D_00E7101C;
int D_00E71020[6];//"visible chocobo" flags
int D_00E71038;
int D_00E7103C;
struct SVECTOR D_00E71040;
//00E71048
int D_00E7104C;//index in D_0097A108[]
//00E71050
int D_00E71054;
//char __00E71058[0x10];
struct t_chocobo_Ranking D_00E71068[5][3];
int D_00E710E0;
int D_00E710E4;
int D_00E710E8;//flag:[set|not used]
int D_00E710EC;//fade:current alpha
int D_00E710F0;//(could this be related to __00E3BAF8?)
//00E710F4
int D_00E710F8;
int D_00E710FC;
unsigned D_00E71100;//previous input mask
int D_00E71104;
int D_00E71108;//# sprites rendered(stat)?
//00E7110C
struct t_chocobo_cameraInfo D_00E71110;
int D_00E71124;//camera related:render first track[culling]
int D_00E71128;
struct t_chocobo_TrackInfo *D_00E7112C;
int D_00E71130;
int D_00E71134;//first chocobo
struct MATRIX D_00E71138;
struct t_chocobo_ChocoboInfo D_00E71158[7];
int D_00E715D4;//fade:alpha increment
int D_00E715D8;
int D_00E715DC;
//char __00E715E0[0x1c];
struct t_chocobo_data_TrackElement *D_00E715FC;
int D_00E71600;//progress flag?
//char __00E71604[0x1c];
//-- C_0076DDF0.cpp--
//unsigned D_00E71620;
//int D_00E71624;
//int D_00E71628[15];
//-- --
struct t_sound_related_24 *D_00E71664;
//-- C_0076E1F0.cpp --
//int *D_00E71668;
//int D_00E7166C;
//-- C_0076E2B0.cpp --
//struct t_chocobo_SpriteUI D_00E71670[6];//face(sprite)
//int D_00E71820[6];//chocobos'palettes
//struct t_chocobo_SpriteUI D_00E71838[6];//jockey's id(sprite)
//-- --
//(start of a structure?)
struct t_chocobo_Model3D *D_00E719E8;
	unsigned short D_00E719EC;//models count
	unsigned short D_00E719EE;//[set|not used]
//char __00E719F0[0x1e4];
struct t_chocobo_local_1c D_00E71BD4[5];
	//[0]renderer for skydome
	//[1]renderer for solid quad
	//[2]renderer for transparent quad
	//[3]renderer for solid triangle
	//[4]renderer for transparent triangle
struct t_chocobo_SpriteBillboard D_00E71C60[0x28];//3D sprite/billboard//check
//-- ch_chr.cpp? --
int *D_00E72980;
int D_00E72984;//3D sprites/billboard count
//-- C_0076FF60.cpp --
int D_00E72988;//[unused]set to 1 during skydome rendering
//00E7298C
//-- C_0770800.cpp --
//struct t_chocobo_local_1c D_00E72990[0x28];//renderers for UI?//check
//struct t_chocobo_local_1c D_00E72DF0;//[for SW patch]
//int D_00E72E0C;//index in D_00E72990[] for init
//-- C_00771680.cpp --
//struct SVECTOR D_00E72E10;//camera pos[current]
//D3DMATRIX D_00E72E18;//transformation matrix[for animated models]?
//short D_00E72E58;//camera:tracking chocobo[unused]
//short D_00E72E5C;//camera:event[unused]
//D3DMATRIX D_00E72E60;//transformation x perspective[for static models]?
//struct SVECTOR D_00E72EA0;//camera LookAt[current]
//char __00E72EA8[8];
//struct MATRIX D_00E72EB0;
//struct SVECTOR D_00E72ED0;//camera pos[target]
//struct SVECTOR D_00E72ED8;//camera LookAt[target]
//int D_00E72EE0;//flag:camera event?
//char __00E72EE4[8];
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
//00E73C2C
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
//char __00E73D70[0x40];
//-- C_00779C90.cpp --
//struct MATRIX D_00E73DB0;
//unsigned char D_00E73DD0;
//char __00E73DD4[0x8c];//padding+D3DMATRIX[2]?
//D3DMATRIX D_00E73E60;
//char __00E73EA0[0x40];//D3DMATRIX?
//double D_00E73EE0;
//int D_00E73EE8;
//int D_00E73EEC;
//struct t_chocobo_data_TrackElement *D_00E73EF0;
//int D_00E73EF4;
//int D_00E73EF8;
//int D_00E73EFC;
////////////////////////////////////////
//chocobo:set path
void C_0076B850(char const *bp08) {
	strcpy(D_00E3B640, bp08);
}

//ch_init:...
void C_0076B87E() {
	struct {
		int dwDevMask;//local_2
		struct t_aa0 *local_1_unused;
	}lolo;

	lolo.local_1_unused = C_00676578();
	//-- --
	if(D_00DC0AE4)//disable bet
		D_00DC0AE5 = 0xff;
	if(D_00DC0AE5)//player as jockey
		D_00E71128 = -1;
	else
		D_00E71128 = 0;
	D_00E3B744 = D_00E71128;
	if(D_00DC0AE3)//long/short race
		D_00E3B74C = 1;
	else
		D_00E3B74C = 0;
	D_00E3B748 = D_00DC0AF3;//race class
	D_00E3B740 = 0;
	D_00E71130 = D_00DC0AF3;//race class
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
	C_0076DF8C();//chocobo:input.refresh
	C_0076E149();//chocobo:input.compute_mask
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
	D_00E71158[0].wSFXCounter = 30;
	D_00E71624 = 0;
}

//ch_init:reset snd channels?
void C_0076BA66() {
	D_00E71664->wOpCode = SOUND_OP_23;//play 4 sfx
	D_00E71664->f_04[0] = 0x40;
	D_00E71664->f_04[1] =
	D_00E71664->f_04[2] =
	D_00E71664->f_04[3] =
	D_00E71664->f_04[4] = 0;
	C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], D_00E71664->f_04[1], D_00E71664->f_04[2], D_00E71664->f_04[3], D_00E71664->f_04[4], 0, 0, 0);
}

void C_0076C01F(int);
void C_0076C57E(int, int);//load/parse "chocobo.wat"
void C_0076D316(void);

//ch_init:...
void C_0076BAFD(struct t_aa0 *bp08, struct t_rsd_74 *bp0c) {
	struct {
		int i;//local_5
		int unused_local_4[4];
	}lolo;

	//-- --
	lolo.unused_local_4[0] = 0;
	lolo.unused_local_4[1] = 0;
	lolo.unused_local_4[2] = 320;
	lolo.unused_local_4[3] = 480;
	//-- --
	C_00770800(bp08, bp0c, D_00E3B744, D_00E3B748);//chocobo:2D elements.init
	C_0076F1B0(bp0c, bp08, D_00E3B74C);//ch_chr:init(1)?
	C_0067455E(bp0c);//rsd:init with blend mode 4?
	bp0c->dwRSDFlags |= RSD_02000000;
	C_00674659(4, bp0c);//rsd:set blend mode?
	C_0076FF60(bp08, bp0c);//chocobo:terrain/scenery.init
	C_0076F920(bp0c, bp08, D_00E3B74C);//ch_chr:init(2)?
	psx_SetGeomOffset(320 / 2, 240 / 2);
	psx_SetGeomScreen(270);
	D_00E71040.vx = 0;
	D_00E71040.vy = 0;
	D_00E71040.vz = 0;
	C_0076D316();//<empty>
	C_0076C57E(D_00DC0AE3, D_00DC0AF3);//load/parse "chocobo.wat"
	C_0076E22F();//chocobo:load/prepare SFX
	D_00E71110 = D_00E7112C->pCameraInfo[0];
	if(D_00E71128)
		D_00E71110.bType = -1;
	D_00E3B750 = D_00E7112C->dwScenaryModelCount;
	D_00E71110.bType = -1;
	//-- --
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		D_00E3B758[lolo.i].dwRenderId = 0x19;
		D_00E3B758[lolo.i].f_04.c.r = (lolo.i & 2)?0xff:0;
		D_00E3B758[lolo.i].f_04.c.g = (lolo.i & 4)?0xff:0;
		D_00E3B758[lolo.i].f_04.c.b = (lolo.i & 1)?0xff:0;
		D_00E3B758[lolo.i].wU = D_00E3B758[lolo.i].wV = 0;
		D_00E3B758[lolo.i].fZ = 0.222f;
	}//end for
	//-- transparent color layer[underwater effect] --
	D_00E3B758[6].wX0 = D_00E3B758[6].wX2 = D_00E3B758[6].wY0 = D_00E3B758[6].wY1 = 0;
	D_00E3B758[6].wX1 = D_00E3B758[6].wX3 = 320;
	D_00E3B758[6].wY2 = D_00E3B758[6].wY3 = 232;
	D_00E3B758[6].dwWidth = 320; D_00E3B758[6].dwHeight = 232;
	D_00E3B758[6].fZ = 0.001f;
	D_00E3B758[6].wU = D_00E3B758[6].wV = 0;
	D_00E3B758[6].f_44 = 1;
	D_00E3B758[6].dwRenderId = 0x19;
	//-- map --
	D_00E3B758[7].f_04.c.r = D_0096E138.r0; D_00E3B758[7].f_04.c.g = D_0096E138.g0; D_00E3B758[7].f_04.c.b = D_0096E138.b0;
	D_00E3B758[7].wX0 = D_0096E138.x0; D_00E3B758[7].wY0 = D_0096E138.y0;
	D_00E3B758[7].wX1 = D_0096E138.x1; D_00E3B758[7].wY1 = D_0096E138.y1;
	D_00E3B758[7].wX2 = D_0096E138.x2; D_00E3B758[7].wY2 = D_0096E138.y2;
	D_00E3B758[7].wX3 = D_0096E138.x3; D_00E3B758[7].wY3 = D_0096E138.y3;
	D_00E3B758[7].wU = D_0096E138.u0; D_00E3B758[7].wV = D_0096E138.v0;
	D_00E3B758[7].dwWidth = 64; D_00E3B758[7].dwHeight = 32;
	D_00E3B758[7].fTexWidth = 0.98f; D_00E3B758[7].fTexHeight = 0.97f;
	D_00E3B758[7].fZ = 0.444f;
	D_00E3B758[7].dwRenderId = 0x13;
	D_00E3B758[7].dwPalette = 0;
	D_00E3B758[7].f_44 = 1;
	//-- for stamina gauge --
	D_00E3B758[9].f_04.c.r = D_0096E160.r0; D_00E3B758[9].f_04.c.g = D_0096E160.g0; D_00E3B758[9].f_04.c.b = D_0096E160.b0;
	D_00E3B758[9].wX0 = D_0096E160.x0; D_00E3B758[9].wY0 = D_0096E160.y0;
	D_00E3B758[9].wX1 = D_0096E160.x1; D_00E3B758[9].wY1 = D_0096E160.y1;
	D_00E3B758[9].wX2 = D_0096E160.x2; D_00E3B758[9].wY2 = D_0096E160.y2;
	D_00E3B758[9].wX3 = D_0096E160.x3; D_00E3B758[9].wY3 = D_0096E160.y3;
	D_00E3B758[9].wU = 0; D_00E3B758[9].wV = 0;
	D_00E3B758[9].fU = 0; D_00E3B758[9].fV = 0;
	D_00E3B758[9].dwWidth = 16; D_00E3B758[9].dwHeight = 96;
	D_00E3B758[9].fWidth = 16.0f; D_00E3B758[9].fHeight = 96.0f;
	D_00E3B758[9].fTexWidth = 0.94f; D_00E3B758[9].fTexHeight = 0.75f;
	D_00E3B758[9].dwRenderId = 0x16;
	D_00E3B758[9].dwPalette = 0;
	D_00E3B758[9].f_44 = 0;
	//-- for stamina gauge --
	D_00E3B758[8].wX0 = D_00E3B758[8].wX2 = 25;
	D_00E3B758[8].wX1 = D_00E3B758[8].wX3 = 30;
	D_00E3B758[8].wY2 = D_00E3B758[8].wY3 = 209;
	D_00E3B758[8].dwWidth = 5;
	D_00E3B758[8].f_04.c.r = 0xff; D_00E3B758[8].f_04.c.g = 0x14; D_00E3B758[8].f_04.c.b = 0x14;
	D_00E3B758[8].dwRenderId = 0x18;
	//-- --
	C_0076C01F(D_00DC0AE3);
	C_0076EEB9();//chocobo:set chocobos'palette
}

void C_0076C01F(int _p08/*long/short race*/) {
	struct {
		int local_9;
		struct t_chocobo_Model3D *pModel;//local_8
		unsigned i;//local_7
		int unused_local_6;
		struct t_aa0 *local_5;
		struct fBGRA local_4;
	}lolo;

	lolo.local_5 = C_00676578();
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		D_00E71158[lolo.i].wJockeyId = lolo.i;
		lolo.pModel = &(D_00E719E8[lolo.i]);
		lolo.pModel->wScaling = 640;
		if(D_00DC0AF2 && lolo.i == 1) {//else 0076C0E7
			//-- "TEIOH" --
			lolo.local_4.r = -(100.0f/256.0f);//0.390625f
			lolo.local_4.g = -(100.0f/256.0f);//0.390625f
			lolo.local_4.b = -(100.0f/256.0f);//0.390625f
			lolo.local_4.a = 1.0f;
			C_00684E20(&lolo.local_4, lolo.pModel->pHRC->f_b4, lolo.local_5);//anm: apply add color to skeleton?
			D_00E3B628[lolo.i].c.r =
			D_00E3B628[lolo.i].c.g =
			D_00E3B628[lolo.i].c.b = 0x40;
			//goto 0076C249
		} else if(D_00E71128 && lolo.i == 0) {//else 0076C193
			lolo.local_9 = D_00DC0AED;//chocobo type/color
			D_00E3B628[lolo.i] = D_0096E108[lolo.local_9];
			lolo.local_4.r = (float)(char)D_0096E108[lolo.local_9].c.r / 256.0f;
			lolo.local_4.g = (float)(char)D_0096E108[lolo.local_9].c.g / 256.0f;
			lolo.local_4.b = (float)(char)D_0096E108[lolo.local_9].c.b / 256.0f;
			lolo.local_4.a = 1.0f;
			C_00684E20(&lolo.local_4, lolo.pModel->pHRC->f_b4, lolo.local_5);//anm: apply add color to skeleton?
			//goto 0076C249
		} else {
			D_00E3B628[lolo.i] = D_0096E0F0[lolo.i];
			lolo.pModel->bR = D_0096E0F0[lolo.i].c.r;
			lolo.pModel->bG = D_0096E0F0[lolo.i].c.g;
			lolo.pModel->bB = D_0096E0F0[lolo.i].c.b;
			lolo.local_4.r = (float)(char)D_0096E0F0[lolo.i].c.r / 256.0f;
			lolo.local_4.g = (float)(char)D_0096E0F0[lolo.i].c.g / 256.0f;
			lolo.local_4.b = (float)(char)D_0096E0F0[lolo.i].c.b / 256.0f;
			lolo.local_4.a = 1.0f;
			C_00684E20(&lolo.local_4, lolo.pModel->pHRC->f_b4, lolo.local_5);//anm: apply add color to skeleton?
		}
	}//end for
	//-- --
	lolo.unused_local_6 = 6;
	//-- --
	if(D_00E71128) {
		D_00E71158[0].wChocoboId = D_00DC0AE2 + 6;
		lolo.pModel = &(D_00E719E8[D_00DC0AE2 + 6]);
	} else {
		D_00E71158[0].wChocoboId = 10;
		lolo.pModel = &(D_00E719E8[10]);
	}
	lolo.pModel->wScaling = 640;
	//-- --
	if(D_00DC0AF2) {
		//-- "TEIOH" --
		D_00E71158[1].wChocoboId = 9;
		lolo.pModel = &(D_00E719E8[9]);
	} else {
		D_00E71158[1].wChocoboId = 11;
		lolo.pModel = &(D_00E719E8[11]);
	}
	lolo.pModel->wScaling = 640;
	//-- --
	for(lolo.i = 12; lolo.i < 16; lolo.i ++) {
		D_00E71158[lolo.i - 10].wChocoboId = lolo.i;
		lolo.pModel = &(D_00E719E8[lolo.i]);
		lolo.pModel->wScaling = 640;
	}//end for
	//-- --
	for(lolo.i = 16; lolo.i < D_00E719EC; lolo.i ++) {
		lolo.pModel = &(D_00E719E8[lolo.i]);
		lolo.pModel->wScaling = 640;
	}//end for
	//-- --
	for(lolo.i = 0; lolo.i < D_00E719EC; lolo.i ++) {
		lolo.pModel = &(D_00E719E8[lolo.i]);
		lolo.pModel->bRotX = 0xc0;
		lolo.pModel->bRotY = 0;
		lolo.pModel->bRotZ = 0x80;
	}//end for
}

//[unused]
//.allocate buffer
//.read file's content in buffer
//.add 0 at the end(text file?)
char *__0076C3C1(const char *bp08) {
	struct {
		char drive[_MAX_DRIVE]; char _ocal_197;//local_197
		char dir[_MAX_DIR];//local_196
		char ext[_MAX_EXT];//local_132
		FILE *f;//local_68
		int dwOffset;//local_67
		char *pBuffer;//local_66
		char fname[_MAX_FNAME];//local_65
		int dwSize;//local_1
	}lolo;

	lolo.pBuffer = 0;
	if(D_00972174 == 0) {//else 0076C486
		//===========
		//== DEVEL ==
		//===========
		lolo.f = ad_fopen(bp08, /*0096E188*/"rb");
		if(lolo.f == 0)
			return 0;
		lolo.dwSize = ad_filesize(lolo.f);
		lolo.pBuffer = (char *)mem_malloc(lolo.dwSize + 2, /*0096E18C*/__FF7FILE__, 0x203);
		if(lolo.pBuffer == 0)
			return 0;
		ad_freadn(lolo.f, lolo.pBuffer, lolo.dwSize);
		lolo.pBuffer[lolo.dwSize] = 0;
		ad_fclose(lolo.f);
	} else {
		//=============
		//== RELEASE ==
		//=============
		_splitpath(bp08, lolo.drive, lolo.dir, lolo.fname, lolo.ext);
		strcat(lolo.fname, lolo.ext);
		lolo.dwOffset = C_006759D2(lolo.fname, ARCHIVE_07);//is_lib:get entry offset?
		if(lolo.dwOffset) {//else 0076C56D
			lolo.dwSize = C_006762EA(lolo.dwOffset, ARCHIVE_07);//is_lib:get entry size
			lolo.pBuffer = (char *)mem_malloc(lolo.dwSize + 2, /*0096E1A8*/__FF7FILE__, 0x215);
			if(lolo.pBuffer == 0)
				return 0;
			C_0067633E(lolo.dwOffset, ARCHIVE_07, lolo.pBuffer, lolo.dwSize);//is_lib:load entry
			lolo.pBuffer[lolo.dwSize] = 0;
		} else {
			return 0;
		}
	}

	return lolo.pBuffer;
}

//convert DOMEG3 to float
/*<moved>*/static void C_0076CCA1() {
	struct {
		struct t_chocobo_data_floatDG3 *pDst;//local_4
		struct t_chocobo_data_DOMEG3 *pSrc;//local_3
		DECL_unsigned_short(i);//local_2
		DECL_unsigned_char(cTemp);//local_1
	}lolo;

	D_00E7112C->pFloatDOMEG3 = (struct t_chocobo_data_floatDG3 *)mem_malloc(D_00E7112C->wCountDOMEG3 * sizeof(struct t_chocobo_data_floatDG3) + 1, /*0096E1C4*/__FF7FILE__, 0x22e);
	for(lolo.i = 0; lolo.i < D_00E7112C->wCountDOMEG3; lolo.i ++) {
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
		//

		lolo.pDst->color0.bgra = lolo.pSrc->color0.rgba | 0xff000000;
		SWAP(lolo.pDst->color0.c.b, lolo.pDst->color0.c.r, lolo.cTemp);

		lolo.pDst->color1.bgra = lolo.pSrc->color1.rgba | 0xff000000;
		SWAP(lolo.pDst->color1.c.b, lolo.pDst->color1.c.r, lolo.cTemp);

		lolo.pDst->color2.bgra = lolo.pSrc->color2.rgba | 0xff000000;
		SWAP(lolo.pDst->color2.c.b, lolo.pDst->color2.c.r, lolo.cTemp);

		lolo.pDst->fvect0.x = (float)lolo.pSrc->svect0.vx;
		lolo.pDst->fvect0.y = (float)lolo.pSrc->svect0.vy;
		lolo.pDst->fvect0.z = (float)lolo.pSrc->svect0.vz;

		lolo.pDst->fvect1.x = (float)lolo.pSrc->svect1.vx;
		lolo.pDst->fvect1.y = (float)lolo.pSrc->svect1.vy;
		lolo.pDst->fvect1.z = (float)lolo.pSrc->svect1.vz;

		lolo.pDst->fvect2.x = (float)lolo.pSrc->svect2.vx;
		lolo.pDst->fvect2.y = (float)lolo.pSrc->svect2.vy;
		lolo.pDst->fvect2.z = (float)lolo.pSrc->svect2.vz;
	}//end for
}

//convert DG3 to float
/*<moved>*/static void C_0076CE76() {
	struct {
		unsigned dwColor_0;//local_8
		struct t_chocobo_data_floatDG3 *pDst;//local_7
		struct t_chocobo_data_DG3 *pSrc;//local_6
		DECL_unsigned_short(i);//local_5
		DECL_unsigned_char(cTemp);//local_4
		unsigned dwColor_2;//local_3
		union {
			unsigned asUnsigned;
			short asShort;
			char asByte[4];
		}local_2;
		unsigned dwColor_1;//local_1
	}lolo;

	D_00E7112C->pFloatDG3 = (struct t_chocobo_data_floatDG3 *)mem_malloc(D_00E7112C->dwCountDG3 * sizeof(struct t_chocobo_data_floatDG3) + 1, /*0096E1E0*/__FF7FILE__, 0x262);
	for(lolo.i = 0; lolo.i < D_00E7112C->dwCountDG3; lolo.i ++) {
		lolo.pDst = &(D_00E7112C->pFloatDG3[lolo.i]);
		lolo.pSrc = &(D_00E7112C->pDG3[lolo.i]);

		lolo.local_2.asShort = lolo.pSrc->svect0.pad;
		lolo.local_2.asByte[2] = lolo.pSrc->svect1.pad & 0xff;
		lolo.dwColor_1 = lolo.local_2.asUnsigned;

		lolo.dwColor_0 = lolo.pSrc->color0.rgba;

		lolo.local_2.asShort = lolo.pSrc->svect0.pad;
		lolo.local_2.asByte[2] = lolo.pSrc->svect1.pad & 0xff;
		//same as lolo.dwColor_1/not used?

		lolo.local_2.asShort = lolo.pSrc->svect2.pad;
		lolo.local_2.asByte[2] = lolo.pSrc->svect1.pad >> 8;
		lolo.dwColor_2 = lolo.local_2.asUnsigned;

		lolo.pDst->color0.bgra = lolo.dwColor_0 | 0xff000000;
		SWAP(lolo.pDst->color0.c.b, lolo.pDst->color0.c.r, lolo.cTemp);

		lolo.pDst->color1.bgra = lolo.dwColor_1 | 0xff000000;
		SWAP(lolo.pDst->color1.c.b, lolo.pDst->color1.c.r, lolo.cTemp);

		lolo.pDst->color2.bgra = lolo.dwColor_2 | 0xff000000;
		SWAP(lolo.pDst->color2.c.b, lolo.pDst->color2.c.r, lolo.cTemp);

		lolo.pDst->fvect0.x = (float)lolo.pSrc->svect0.vx;
		lolo.pDst->fvect0.y = (float)lolo.pSrc->svect0.vy;
		lolo.pDst->fvect0.z = (float)lolo.pSrc->svect0.vz;

		lolo.pDst->fvect1.x = (float)lolo.pSrc->svect1.vx;
		lolo.pDst->fvect1.y = (float)lolo.pSrc->svect1.vy;
		lolo.pDst->fvect1.z = (float)lolo.pSrc->svect1.vz;

		lolo.pDst->fvect2.x = (float)lolo.pSrc->svect2.vx;
		lolo.pDst->fvect2.y = (float)lolo.pSrc->svect2.vy;
		lolo.pDst->fvect2.z = (float)lolo.pSrc->svect2.vz;
	}//end for
}

//convert DG4 to float
/*<moved>*/static void C_0076D09F() {
	struct {
		unsigned dwColor_0;//local_9
		struct t_chocobo_data_floatDG4 *pDst;//local_8
		struct t_chocobo_data_DG4 *pSrc;//local_7
		DECL_unsigned_short(i);//local_6
		DECL_unsigned_char(cTemp);//local_5
		unsigned dwColor_3;//local_4
		unsigned dwColor_2;//local_3
		union {
			unsigned asUnsigned;
			short asShort;
			char asByte[4];
		}local_2;
		unsigned dwColor_1;//local_1
	}lolo;

	D_00E7112C->pFloatDG4 = (struct t_chocobo_data_floatDG4 *)mem_malloc(D_00E7112C->dwCountDG4 * sizeof(struct t_chocobo_data_floatDG4) + 1, /*0096E1FC*/__FF7FILE__, 0x2a3);
	for(lolo.i = 0; lolo.i < D_00E7112C->dwCountDG4; lolo.i ++) {
		lolo.pDst = &(D_00E7112C->pFloatDG4[lolo.i]);
		lolo.pSrc = &(D_00E7112C->pDG4[lolo.i]);

		lolo.dwColor_0 = lolo.pSrc->color1.rgba;
		lolo.dwColor_3 = lolo.pSrc->color0.rgba;

		lolo.local_2.asByte[2] = lolo.pSrc->svect1.pad >> 8;
		lolo.local_2.asShort = lolo.pSrc->svect2.pad;
		lolo.dwColor_1 = lolo.local_2.asUnsigned;

		lolo.local_2.asShort = lolo.pSrc->svect3.pad;
		lolo.local_2.asByte[2] = lolo.pSrc->color0.c.a;
		lolo.dwColor_2 = lolo.local_2.asUnsigned;

		lolo.pDst->color0.bgra = lolo.dwColor_0 | 0xff000000;
		SWAP(lolo.pDst->color0.c.b, lolo.pDst->color0.c.r, lolo.cTemp);

		lolo.pDst->color1.bgra = lolo.dwColor_1 | 0xff000000;
		SWAP(lolo.pDst->color1.c.b, lolo.pDst->color1.c.r, lolo.cTemp);

		lolo.pDst->color2.bgra = lolo.dwColor_2 | 0xff000000;
		SWAP(lolo.pDst->color2.c.b, lolo.pDst->color2.c.r, lolo.cTemp);

		lolo.pDst->color3.bgra = lolo.dwColor_3 | 0xff000000;
		SWAP(lolo.pDst->color3.c.b, lolo.pDst->color3.c.r, lolo.cTemp);

		lolo.pDst->fvect0.x = (float)lolo.pSrc->svect0.vx;
		lolo.pDst->fvect0.y = (float)lolo.pSrc->svect0.vy;
		lolo.pDst->fvect0.z = (float)lolo.pSrc->svect0.vz;

		lolo.pDst->fvect1.x = (float)lolo.pSrc->svect1.vx;
		lolo.pDst->fvect1.y = (float)lolo.pSrc->svect1.vy;
		lolo.pDst->fvect1.z = (float)lolo.pSrc->svect1.vz;

		lolo.pDst->fvect2.x = (float)lolo.pSrc->svect2.vx;
		lolo.pDst->fvect2.y = (float)lolo.pSrc->svect2.vy;
		lolo.pDst->fvect2.z = (float)lolo.pSrc->svect2.vz;

		lolo.pDst->fvect3.x = (float)lolo.pSrc->svect3.vx;
		lolo.pDst->fvect3.y = (float)lolo.pSrc->svect3.vy;
		lolo.pDst->fvect3.z = (float)lolo.pSrc->svect3.vz;
	}//end for
}

/* ## structure of file "chocobo.wat" ##

000000	dw 0x49D
000002	struct t_chocobo_data_TrackElement [0x49D]
006EBA	db 'LGUIDE'
006EC0	struct t_chocobo_data_GUIDE [0x49D]
0093A8	db 'LMAPPOINTE'
0093B2	dw 0x4A1
0093B4	short [0x4A1]
009CF6	db 'LMAPTABLE'
009CFF	dw 0x3C38
009D01	unsigned [0x3C38]
018DE1	db 'LDOMEG3'
018DE8	dw 0x19E
018DEA	struct t_chocobo_data_DOMEG3 [0x19E]
01C822	db 'LDG3'
01C826	dw 0x2E49	;stops at 0x1be0?
01C828	struct t_chocobo_data_DG3 [0x2E49]	;contains garbage after 0x1be0?
06D824	db 'LDG4'
06D828	dw 0x1269
06D82A	struct t_chocobo_data_DG4 [0x1269]
09B892	db 'LSPRITE'
09B899	dw 0xFF
09B89B	0x28 [0xFF]	;contains garbage data at the end

09E073	db 'SHORT'

09E078	dw 0x3B1
09E07A	struct t_chocobo_data_TrackElement [0x3B1]
0A3912	db 'SGUIDE'
0A3918	struct t_chocobo_data_GUIDE [0x3B1]
0A56A0	db 'SMAPPOINTE'
0A56AA	dw 0x3B5
0A56AC	short [0x3B5]
0A5E16	db 'SMAPTABLE'
0A5E1F	dw 0x2F8A
0A5E21	unsigned [0x2F8A]
0B1C49	db 'SDOMEG3'
0B1C50	dw 0x19E
0B1C52	struct t_chocobo_data_DOMEG3 [0x19E]
0B568A	db 'SDG3'
0B568E	dw 0x27A2	;stops at 0x1764?
0B5690	struct t_chocobo_data_DG3 [0x27A2]	;contains garbage after 0x1764?
0FAC48	db 'SDG4'
0FAC4C	dw 0x103D
0FAC4E	struct t_chocobo_data_DG4 [0x103D]
1235D6	db 'SSPRITE'
1235DD	dw 0x5A
1235DF	0x28 [0x5A]	;contains garbage data at the end

1243EF	db 'END'
*/
//load/parse "chocobo.wat"
void C_0076C57E(int bp08/*long/short race*/, int _p0c/*race rank*/) {
	struct {
		int dwNumMAPPOINTER;//local_72
		int _ocal_71;
		FILE *f;//local_70
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
	D_00E7112C->dwLastSprintPoint = C_00772340(bp08);//chocobo:get track's "last sprint" point?
	D_00E7112C->pCameraInfo = C_00771680(bp08);//chocobo:get camera info array
	D_00E7112C->pScenaryModel = C_00771660(bp08);//chocobo:get scenery models array?
	D_00E7112C->pSoundEvent = C_0076E1F0(bp08);//chocobo:get sounds info
	if(D_00E3B74C == 0) {
		D_00E7112C->dwTrackLength = 0x49d;
		D_00E7112C->dwScenaryModelCount = 0xf;
		D_00E7112C->dwCountDG4 = 0x1269;
		D_00E7112C->dwCountDG3 = 0x2e49;
		D_00E7112C->wCountDOMEG3 = 0x19e;
		D_00E7112C->wCountSPRITE = 0xff;
		lolo.dwBaseOffset = 0;
		lolo.dwNumMAPPOINTER = 0x4a1;
		lolo.dwNumMAPTABLE = 0x3c38;
	} else {
		D_00E7112C->dwTrackLength = 0x3b1;
		D_00E7112C->dwScenaryModelCount = 0x13;
		D_00E7112C->dwCountDG4 = 0x103d;
		D_00E7112C->dwCountDG3 = 0x27a2;
		D_00E7112C->wCountDOMEG3 = 0x19e;
		D_00E7112C->wCountSPRITE = 0x5a;
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
		lolo.f = ad_fopen(lolo.local_66, /*0096E240*/"rb");
		ad_fseek(lolo.f, lolo.dwBaseOffset, SEEK_SET);

		//wTrackLength
		ad_fseek(lolo.f, 2, SEEK_CUR);
		lolo.local_67 = (char *)mem_malloc(D_00E7112C->dwTrackLength * sizeof(struct t_chocobo_data_TrackElement), /*0096E244*/__FF7FILE__, 0x31b);
		ad_freadn(lolo.f, lolo.local_67, D_00E7112C->dwTrackLength * sizeof(struct t_chocobo_data_TrackElement));
		D_00E7112C->pTrackElement = (struct t_chocobo_data_TrackElement *)lolo.local_67;

		//"{L|S}GUIDE"
		ad_fseek(lolo.f, 6, SEEK_CUR);
		lolo.local_67 = (char *)mem_malloc(D_00E7112C->dwTrackLength * sizeof(struct t_chocobo_data_GUIDE), /*0096E260*/__FF7FILE__, 0x321);
		ad_freadn(lolo.f, lolo.local_67, D_00E7112C->dwTrackLength * sizeof(struct t_chocobo_data_GUIDE));
		D_00E7112C->pGUIDE = (struct t_chocobo_data_GUIDE *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(lolo.dwNumMAPPOINTER * sizeof(short), /*0096E27C*/__FF7FILE__, 0x325);
		//"{L|S}MAPPOINTE" :: wNumMAPPOINTER
		ad_fseek(lolo.f, 0xc, SEEK_CUR);
		ad_freadn(lolo.f, lolo.local_67, lolo.dwNumMAPPOINTER * sizeof(short));
		D_00E7112C->pMAPPOINTER = (short *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(lolo.dwNumMAPTABLE * sizeof(int), /*0096E298*/__FF7FILE__, 0x32a);
		//"{L|S}MAPTABLE" :: wNumMAPTABLE
		ad_fseek(lolo.f, 0xb, SEEK_CUR);
		ad_freadn(lolo.f, lolo.local_67, lolo.dwNumMAPTABLE * sizeof(int));
		D_00E7112C->pMAPTABLE = (int *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(D_00E7112C->wCountDOMEG3 * sizeof(struct t_chocobo_data_DOMEG3), /*0096E2B4*/__FF7FILE__, 0x32f);
		//"{L|S}DOMEG3" :: wCountDOMEG3
		ad_fseek(lolo.f, 9, SEEK_CUR);
		ad_freadn(lolo.f, lolo.local_67, D_00E7112C->wCountDOMEG3 * sizeof(struct t_chocobo_data_DOMEG3));
		D_00E7112C->pDOMEG3 = (struct t_chocobo_data_DOMEG3 *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(D_00E7112C->dwCountDG3 * sizeof(struct t_chocobo_data_DG3), /*0096E2D0*/__FF7FILE__, 0x334);
		ad_fseek(lolo.f, 6, SEEK_CUR);//"{L|S}DG3" :: wCountDG3
		ad_freadn(lolo.f, lolo.local_67, D_00E7112C->dwCountDG3 * sizeof(struct t_chocobo_data_DG3));
		D_00E7112C->pDG3 = (struct t_chocobo_data_DG3 *)lolo.local_67;

		lolo.local_67 = (char *)mem_malloc(D_00E7112C->dwCountDG4 * sizeof(struct t_chocobo_data_DG4), /*0096E2EC*/__FF7FILE__, 0x339);
		//"{L|S}DG4" :: wCountDG4
		ad_fseek(lolo.f, 6, SEEK_CUR);
		ad_freadn(lolo.f, lolo.local_67, D_00E7112C->dwCountDG4 * sizeof(struct t_chocobo_data_DG4));
		D_00E7112C->pDG4 = (struct t_chocobo_data_DG4 *)lolo.local_67;

		//note: sizeof(struct t_chocobo_data_SPRITE) is 0x16,
		// and sizeof(struct t_chocobo_data_DG4) is 0x28.
		// could this be a copy/paste error?
		lolo.local_67 = (char *)mem_malloc(D_00E7112C->wCountSPRITE * 0x28, /*0096E308*/__FF7FILE__, 0x33e);
		//"{L|S}SPRITE :: wCountSPRITE
		ad_fseek(lolo.f, 9, SEEK_CUR);
		ad_freadn(lolo.f, lolo.local_67, D_00E7112C->wCountSPRITE * 0x28);
		D_00E7112C->pSPRITE = (struct t_chocobo_data_SPRITE *)lolo.local_67;

		//"SHORT" or "END"

		ad_fclose(lolo.f);
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

			D_00E7112C->pTrackElement = (struct t_chocobo_data_TrackElement *)lolo.local_67;
			lolo.local_67 += D_00E7112C->dwTrackLength * sizeof(struct t_chocobo_data_TrackElement) + 6;//"{L|S}GUIDE"

			D_00E7112C->pGUIDE = (struct t_chocobo_data_GUIDE *)lolo.local_67;
			lolo.local_67 += D_00E7112C->dwTrackLength * sizeof(struct t_chocobo_data_GUIDE) + 0xa + sizeof(short);//"{L|S}MAPPOINTE" __ # of objects

			D_00E7112C->pMAPPOINTER = (short *)lolo.local_67;
			lolo.local_67 += lolo.dwNumMAPPOINTER * sizeof(short) + 9 + sizeof(short);//"{L|S}MAPTABLE" __ # of objects

			D_00E7112C->pMAPTABLE = (int *)lolo.local_67;
			lolo.local_67 += lolo.dwNumMAPTABLE * sizeof(int) + 7 + sizeof(short);//"{L|S}DOMEG3" __ # of objects

			D_00E7112C->pDOMEG3 = (struct t_chocobo_data_DOMEG3 *)lolo.local_67;
			lolo.local_67 += D_00E7112C->wCountDOMEG3 * sizeof(struct t_chocobo_data_DOMEG3) + 4 + sizeof(short);//"{L|S}DG3" __ # of objects

			D_00E7112C->pDG3 = (struct t_chocobo_data_DG3 *)lolo.local_67;
			lolo.local_67 += D_00E7112C->dwCountDG3 * sizeof(struct t_chocobo_data_DG3) + 4 + sizeof(short);//"{L|S}DG4" __ # of objects

			D_00E7112C->pDG4 = (struct t_chocobo_data_DG4 *)lolo.local_67;
			lolo.local_67 += D_00E7112C->dwCountDG4 * sizeof(struct t_chocobo_data_DG4) + 7 + sizeof(short);//"{L|S}SPRITE" __ # of objects

			D_00E7112C->pSPRITE = (struct t_chocobo_data_SPRITE *)lolo.local_67;
		}
	}
	C_0076CCA1();//convert DOMEG3 to float
	C_0076CE76();//convert DG3 to float
	C_0076D09F();//convert DG4 to float
	D_00E715FC = D_00E7112C->pTrackElement;
	D_00E3B754 = 0;
}

//<moved>:void C_0076CCA1() {

//<moved>:void C_0076CE76() {

//<moved>void C_0076D09F() {

//<empty>
void C_0076D316() {
}

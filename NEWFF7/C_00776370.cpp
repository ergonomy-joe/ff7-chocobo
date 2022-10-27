/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- bet menu?

#include "ff7.h"
#include "chocobo_data.h"
#include "menu_data.h"
////////////////////////////////////////
int D_0097A440[][4] = {
	{0,100,200,300},//class C
	{0,200,400,600},//class B
	{0,300,600,900},//class A
	{0,500,1000,1500},//class S
};
int __0097A480[] = {0,0,320,480};
int D_0097A490 = 0x40;//displayed chocobo rot(2)
int D_0097A494 = 0x80;//displayed chocobo rot(3)
struct t_chocobo_48 D_0097A498 = {
	0x19,
	{0,0,0,0},
	0,0,
	0,
	0,
	{
		{0,0},
		{320,0},
		{0,240},
		{320,240}
	},
	0.011f,
	320,240,
	0,
	0,
	0,
	0,
	0,
	0
};
int D_0097A4E0[] = {0x38,0x59,0x78,0x95,0xB3,0xD1};
////////////////////////////////////////
extern short D_0097B470[][4];
extern struct t_chocobo_48 D_0097B4E8;
extern struct t_chocobo_48 D_0097B530;
extern struct t_chocobo_48 D_0097B578;
extern struct t_chocobo_48 D_0097B5C0;
extern struct t_chocobo_48 D_0097B608;
extern struct t_chocobo_48 D_0097B650[];
extern int D_0097BB60[];
extern struct t_chocobo_48 D_0097BBC0[];
extern struct t_chocobo_48 D_0097C1A8[];

extern char D_0097C8B0[];
extern char D_0097C910[];
extern char D_0097C968[];
extern char D_0097C9A8[];
extern unsigned char D_0097C9D0[][0x10];
////////////////////////////////////////
extern int D_00E3B748;
extern int D_00E3BA90;
extern struct t_chocobo_48 *D_00E3BA9C;
extern struct t_chocobo_48 *D_00E3BAA0;
extern struct t_chocobo_48 *D_00E3BAA4;
extern struct t_chocobo_48 *D_00E3BAA8;
extern struct t_chocobo_48 *D_00E3BAAC;
extern struct t_chocobo_48 *D_00E3BAB0;
extern void (*D_00E3BABC)(unsigned, int, int);//render integer(callback)

extern int D_00E71018;
extern struct t_chocobo_ranking_8 D_00E71068[][3];
extern int D_00E710EC;
extern int D_00E71130;
extern int D_00E715D4;

extern int D_00E71600;
////////////////////////////////////////
int D_00E72EF0;
int D_00E72EF4;
unsigned *D_00E72EF8;
struct t_chocobo_48 D_00E72F00[5][3];
int D_00E73338;
//00E7333C
int D_00E73340[3];
int D_00E7334C;//unused debug stuff?
int D_00E73350;//unused debug stuff?
int D_00E73354;//unused debug stuff?
//00E73358
struct t_chocobo_48 D_00E73360[5][3];
int D_00E73798[3];
int D_00E737A4;
//00E737A8
int D_00E737AC;
int D_00E737B0;
int D_00E737B4;//bet y
int D_00E737B8;//bet x
int D_00E737BC;
struct t_chocobo_48 D_00E737C0[5][3];
char *D_00E73BF8;
int D_00E73BFC;//displayed chocobo rot(1)
int D_00E73C00;
int D_00E73C04;
int D_00E73C08;
int D_00E73C0C;//counter for animation
////////////////////////////////////////
void __00776370() {
}

void C_0077642F(void);//reset unused debug stuff?
void C_007772AE(void);//prepare "bet grid"?

void C_00776375() {
	D_00E71664->f_00 = 0x10;
	D_00E71664->f_04[0] = 0x3d;
	C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);
	C_0077642F();//reset unused debug stuff?
	C_007772AE();//prepare "bet grid"?
	D_00E73C08 = 0;
	D_00E72EF0 = D_00E737B8 = D_00E737B4 = 0;
	D_00E737AC = 0;
	D_00E737A4 = 
	D_00E73798[0] =
	D_00E73798[1] =
	D_00E73798[2] = -1;
	D_00E73C04 = 0;
}

//reset unused debug stuff?
void C_0077642F() {
	D_00E73350 = 900;
	D_00E7334C = 240;
	D_00E73354 = 320;
}

void C_00776F0D(int);
void C_00777DF4(int);
void C_007792CD(void);//display prizes
void C_0077941B(unsigned char *, int, int, int);//draw string?

//refresh "bet menu"
void C_00776452() {
	struct {
		int bp_10;
		int bp_0c;
		int bp_08;
		int i;//bp_04
	}lolo;

	D_00E73C00 = 0;
	D_00E71108 = 0;
	C_00777DF4(1);
	if(D_00E710EC > 0xff && D_00E715D4 > 0) {
		D_00E715D4 = 0;
		*D_00E72EF8 -= D_0097A440[D_00E71130][D_00E73C08];
		D_00E3B740 = 2;
	}
	if(D_00E3B740 == 1) {//else 00776B88
		D_00E71018 ++;
		D_00E72EF0 ++;
		C_0076E149();//chocobo:compute input mask
		//-- --
		if(D_00E71620 != D_00E71100) {//else 00776844
			//-- [NUMPAD_5] --
			if(D_00E71620 & BIT(CH_KEY_START))
				D_00E715D4 = 0x10;
			//-- --
			D_00E72EF0 = 0;
			//-- [PgUp] previous chocobo --
			if(D_00E71620 & BIT(CH_KEY_PGUP)) {
				if(--D_00E71624 < 0) D_00E71624 = 5;
				D_00E73C00 = -1;
			}
			//-- [PgDn][Home] next chocobo --
			if((D_00E71620 & BIT(CH_KEY_CAMERA)) || (D_00E71620 & BIT(CH_KEY_PGDN))) {
				if(++ D_00E71624 >= 6) D_00E71624 = 0;
				D_00E73C00 = -1;
			}
			//-- [-] or [NUMPAD_ENTER] --
			if((D_00E71620 & BIT(CH_KEY_OK)) || (D_00E71620 & BIT(CH_KEY_ASSIST))) {//else 00776844
				if(D_00E71128 == 0) {//else 00776844
					D_00E73C00 = -1;
					for(lolo.bp_08 = 0; lolo.bp_08 < 3; lolo.bp_08 ++) {
						if(++D_00E737AC > 2) D_00E737AC = 0;
						if(D_00E73798[D_00E737AC] == D_00E737B8 * 10 + D_00E737B4) {
							D_00E71068[D_00E737B8][D_00E737B4].f_05 = 2;
							D_00E73798[D_00E737AC] = -1;
							break;
						}
					}//end for
					if(lolo.bp_08 == 3) {//else 007767A7
						for(lolo.bp_08 = 0; lolo.bp_08 < 3; lolo.bp_08 ++) {
							if(++D_00E737AC > 2) D_00E737AC = 0;
							if(D_00E73798[D_00E737AC] == -1 || D_00E73798[D_00E737AC] == D_00E737B8 * 10 + D_00E737B4) {
								D_00E71068[D_00E737B8][D_00E737B4].f_05 = 1;
								D_00E73798[D_00E737AC] = D_00E737B8 * 10 + D_00E737B4;
								break;
							}
						}//end for
						if(lolo.bp_08 == 3) {//else 007767A7
							if(++D_00E737AC > 2) D_00E737AC = 0;
							lolo.bp_0c = D_00E73798[D_00E737AC] / 0xa;
							lolo.bp_10 = D_00E73798[D_00E737AC] % 0xa;
							D_00E71068[lolo.bp_0c][lolo.bp_10].f_05 = 2;
							D_00E71068[D_00E737B8][D_00E737B4].f_05 = 1;
							D_00E73798[D_00E737AC] = D_00E737B8 * 10 + D_00E737B4;
						}
					}
					D_00E73C08 = 0;
					for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
						if(D_00E73798[lolo.i] != -1)
							D_00E73C08 ++;
					}//end for
					if(*D_00E72EF8 - D_0097A440[D_00E71130][D_00E73C08] > *D_00E72EF8) {//else 00776844
						D_00E71068[D_00E737B8][D_00E737B4].f_05 = 2;
						D_00E73798[D_00E737AC] = -1;
						D_00E73C08 --;
					}
				}
			}
		}
		//-- --
		if(D_00E71128 == 0 && D_00E71100 != D_00E71620) {//else 0077694E
			//-- [left] --
			if(D_00E71620 & BIT(CH_KEY_LEFT)) {
				if(--D_00E737B8 < 0) D_00E737B8 = 4;
				D_00E73C00 = -1;
			}
			//-- [right] --
			if(D_00E71620 & BIT(CH_KEY_RIGHT)) {
				if(++D_00E737B8 > 4) D_00E737B8 = 0;
				D_00E73C00 = -1;
			}
			//-- [up] --
			if(D_00E71620 & BIT(CH_KEY_UP)) {
				if(--D_00E737B4 < 0) D_00E737B4 = 2;
				D_00E73C00 = -1;
			}
			//-- [down] --
			if(D_00E71620 & BIT(CH_KEY_DOWN)) {
				if(++D_00E737B4 > 2) D_00E737B4 = 0;
				D_00E73C00 = -1;
			}
		}
		//-- set previous input mask --
		D_00E71100 = D_00E71620;
		//-- --
		if(D_00E73C00) {
			D_00E71664->f_00 = 0x20;
			D_00E71664->f_04[0] = 0x40;
			D_00E71664->f_04[1] = 1;
			C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);
			D_00E73C00 = 0;
		}
		//-- --
		C_0077A3A2(&D_0097B4E8);
		C_0077A3A2(&D_0097B530);
		C_00776F0D(D_00E71624);
		//-- some bg elements --
		for(lolo.i = 0; lolo.i < 0xa; lolo.i ++) {
			if((lolo.i == 6 || lolo.i == 7) && (D_00E3B748 == 1 || D_00E3B748 == 2))
				D_0097C1A8[lolo.i].f_00 = 0x1a;
			C_0077A469(&(D_00E3BAA4[lolo.i]));//draw sprite?
			D_00E71108 ++;
		}//end for
		//-- --
		D_00E71108 ++;
		//-- some texts --
		for(lolo.i = 0; lolo.i < D_00E3BA90; lolo.i ++) {
			C_0077A469(&(D_00E3BA9C[lolo.i]));//draw sprite?
			D_00E71108 ++;
		}//end for
		//-- chocobo # --
		C_0077A469(&(D_00E3BAAC[D_00E71624]));//draw sprite?
		D_00E71108 ++;
		//-- GIL/TOP SPEED/STAMINA --
		D_00E3BABC(*D_00E72EF8 - D_0097A440[D_00E71130][D_00E73C08], 276, 214);//render integer(callback)
		D_00E3BABC(D_00E71158[D_00E71624].wTopSpeed / 34, 284, 43);//render integer(callback)
		D_00E3BABC(D_00E71158[D_00E71624].dwStamina / 10, 284, 66);//render integer(callback)
		//-- --
		C_007792CD();//display prizes
		C_0077941B(D_00E71158[D_00E71624].f_88, 6, 240, 88);//draw string?
		C_0077946A();//refresh fade in/out
		C_0077B2CA();//chocobo:renderer?
	}
}

//render integer(callback)[LORES]
void C_00776B8C(unsigned dwVal/*bp08*/, int dwX/*bp0c*/, int dwY/*bp10*/) {
	struct {
		struct t_chocobo_48 bp_324[0xb];//local_201
		int local_3;
		int i;//local_2
		int local_1;
	}lolo;

	lolo.local_1 = 0;
	D_00E71108 ++;
	if(dwVal == 0) {
		lolo.i = 0;
		lolo.bp_324[lolo.i] = D_0097B608;
		lolo.bp_324[lolo.i].f_14[0].wX = dwX;
		lolo.bp_324[lolo.i].f_14[0].wY = dwY;
		C_0077A469(lolo.bp_324);//draw sprite?
		D_00E71108 ++;
	} else {
		for(lolo.i = 0; lolo.i < 0xb && lolo.local_1 == 0; lolo.i ++) {
			lolo.bp_324[lolo.i] = D_0097B608;
			lolo.local_3 = dwVal % 10;
			lolo.bp_324[lolo.i].f_14[0].wX = dwX - lolo.i * 0xc;
			lolo.bp_324[lolo.i].f_14[0].wY = dwY;
			if(dwVal) {
				lolo.bp_324[lolo.i].wU = lolo.local_3 * 0x10 + 8;
				lolo.bp_324[lolo.i].fU = (float)lolo.bp_324[lolo.i].wU / 256.0f;
			} else {
				lolo.local_1 = 1;
			}
			if(dwVal > 0) {
				dwVal /= 10;
				C_0077A469(&(lolo.bp_324[lolo.i]));//draw sprite?
				D_00E71108 ++;
			}
		}//end for
	}
}

//render integer(callback)[HIRES]
void C_00776D2B(unsigned dwVal/*bp08*/, int dwX/*bp0c*/, int dwY/*bp10*/) {
	struct {
		struct t_chocobo_48 bp_324[0xb];//local_201
		int local_3;
		int i;//local_2
		int local_1;
	}lolo;

	lolo.local_1 = 0;
	D_00E71108 ++;
	if(dwVal == 0) {
		lolo.i = 0;
		lolo.bp_324[lolo.i] = D_0097B578;
		lolo.bp_324[lolo.i].f_14[0].wX = dwX;
		lolo.bp_324[lolo.i].f_14[0].wY = dwY;
		C_0077A469(&(lolo.bp_324[0]));//draw sprite?
		D_00E71108 ++;
	} else {
		for(lolo.i = 0; lolo.i < 0xb && lolo.local_1 == 0; lolo.i ++) {
			lolo.local_3 = dwVal % 10;
			if(lolo.local_3 < 7)
				lolo.bp_324[lolo.i] = D_0097B578;
			else
				lolo.bp_324[lolo.i] = D_0097B5C0;
			lolo.bp_324[lolo.i].f_14[0].wX = dwX - lolo.i * 0xc;
			lolo.bp_324[lolo.i].f_14[0].wY = dwY;
			if(dwVal) {
				if(lolo.local_3 < 7)
					lolo.bp_324[lolo.i].wU = lolo.local_3 * 0x20 + 0x10;
				else
					lolo.bp_324[lolo.i].wU = (lolo.local_3 - 7) * 0x20 + 0x78;
				lolo.bp_324[lolo.i].fU = (float)lolo.bp_324[lolo.i].wU / 256.0f;
			} else {
				lolo.local_1 = 1;
			}
			if(dwVal > 0) {
				dwVal /= 10;
				C_0077A469(&(lolo.bp_324[lolo.i]));//draw sprite?
				D_00E71108 ++;
			}
		}//end for
	}
}

void C_00776F0D(int bp08) {
	struct {
		char _ocal_53[0x48];
		struct t_chocobo_3c *local_35;
		char _ocal_34[0x10];
		struct t_chocobo_3c *local_30;
		char _ocal_29[0x40];
		struct t_chocobo_a4 *local_13;
		char _ocal_12[4];
		int dwDevMask;//local_11
		char _ocal_10[4];
		int dwAnmNum;//local_9
		char _ocal_8[0x20];
	}lolo;

	lolo.local_13 = &(D_00E71158[bp08]);
	//-- dash? --
	if(lolo.local_13->f_4c == 2)
		lolo.dwAnmNum = 1;
	else
		lolo.dwAnmNum = 0;
	//-- --
	lolo.local_30 = &(D_00E719E8[lolo.local_13->f_92]);
	lolo.local_35 = &(D_00E719E8[lolo.local_13->f_90]);
	//-- [end] --
	if(D_00E71620 & BIT(CH_KEY_TARGET)) {//else 0077715B
		lolo.dwDevMask = D_00E71620 >> 16;
		//-- rotate chocobo --
		if(lolo.dwDevMask & BIT(15))
			D_00E73BFC ++;
		if(lolo.dwDevMask & BIT(13))
			D_00E73BFC --;
		//-- --
		if(lolo.dwDevMask & BIT(12))
			D_0097A490 ++;
		if(lolo.dwDevMask & BIT(14))
			D_0097A490 --;
		//-- --
		if(lolo.dwDevMask & BIT(2))
			D_0097A494 ++;
		if(lolo.dwDevMask & BIT(0))
			D_0097A494 --;
		//-- --
		if(lolo.dwDevMask & BIT(3)) {
			D_00E73350 -= 20;
			if(D_00E73350 < 150)
				D_00E73350 = 150;
		}
		if(lolo.dwDevMask & BIT(1)) {
			D_00E73350 += 20;
			if(D_00E73350 > 0x800)
				D_00E73350 = 0x800;
		}
		//-- --
		if(lolo.dwDevMask & BIT(7)) {
			D_00E73354 -= 20;
			if(D_00E73354 < -0x400)
				D_00E73354 = -0x400;
		}
		if(lolo.dwDevMask & BIT(5)) {
			D_00E73354 += 20;
			if(D_00E73354 > 0x400)
				D_00E73354 = 0x400;
		}
		//-- --
		if(lolo.dwDevMask & BIT(4)) {
			D_00E7334C -= 20;
			if(D_00E7334C < -0x400)
				D_00E7334C = -0x400;
		}
		if(lolo.dwDevMask & BIT(6)) {
			D_00E7334C += 20;
			if(D_00E7334C > 0x400)
				D_00E7334C = 0x400;
		}
		//-- --
		if(lolo.dwDevMask & BIT(8))
			C_0077642F();//reset unused debug stuff?
		//-- --
	} else {
		//-- rotate chocobo automaticaly --
		if(D_00E71018 & 2)
			D_00E73BFC ++;
	}
	lolo.local_35->f_09 = lolo.local_30->f_09 = 0x100 - D_0097A490;
	lolo.local_35->f_0a = lolo.local_30->f_0a = 0x100 - D_00E73BFC;
	lolo.local_35->f_0b = lolo.local_30->f_0b = 0x100 - D_0097A494;

	lolo.local_35->f_02 = lolo.local_30->f_02;

	lolo.local_30->f_24 = lolo.local_35->f_24 = 0;
	//-- animation counter --
	D_00E73C0C += 0x100;
	if((D_00E73C0C >> 8) >= lolo.local_30->dwMaxAnimationFrame)
		D_00E73C0C &= 0xff;
	//-- --
	lolo.local_30->wPrevAnmNum = lolo.local_30->wAnmNum;
	lolo.local_35->wPrevAnmNum = lolo.local_35->wAnmNum;
	lolo.local_30->wAnmNum = lolo.dwAnmNum; lolo.local_30->dwAnimationFrame = D_00E73C0C >> 8;
	lolo.local_35->wAnmNum = lolo.dwAnmNum; lolo.local_35->dwAnimationFrame = D_00E73C0C >> 8;
	//-- jockey --
	C_0077B7E2(lolo.local_30);//refresh rotation[3D model]?
	//-- chocobo --
	C_0077B7E2(lolo.local_35);//refresh rotation[3D model]?
}

//prepare "bet grid"?
void C_007772AE() {
	struct {
		int bp_a4;
		int bp_a0;
		int bp_9c;
		int bp_98;
		int bp_94;
		int bp_90;
		int bp_8c;
		int bp_88;
		int j;//bp_84
		int i;//bp_80
		int *bp_7c;
		int bp_78[0xf];
		int bp_3c[0xf];
	}lolo;

	lolo.j = 0;
	switch(D_00E71130) {
		case 0: D_00E73BF8 = D_0097C9A8; break;
		case 1: D_00E73BF8 = D_0097C968; break;
		case 2: D_00E73BF8 = D_0097C910; break;
		case 3: D_00E73BF8 = D_0097C8B0; break;
	}//end switch
	lolo.bp_7c = (int *)D_00E73BF8;
	lolo.bp_88 = *lolo.bp_7c;
	D_00E73BF8 += 4;

	lolo.i = 0;
	D_00E73340[0] = D_00E73340[1] = D_00E73340[2] = -1;
	lolo.bp_90 = 0;
	lolo.bp_8c = -1;
	while(lolo.i != 3) {
		//-- --
		lolo.bp_94 = rand() % lolo.bp_88;
		if(
			D_00E73BF8[lolo.bp_94 * 4 + 0] == D_00E73340[0] ||
			D_00E73BF8[lolo.bp_94 * 4 + 0] == D_00E73340[1] ||
			D_00E73BF8[lolo.bp_94 * 4 + 0] == D_00E73340[2]
		) continue;
		//-- --
		if(D_00E73BF8[lolo.bp_94 * 4 + 1]) {//else 0077746D
			if(lolo.bp_90 && D_00E73BF8[lolo.bp_94 * 4 + 3])
				continue;
			if(D_00E71600) {
				D_00E73340[lolo.i] = D_00E73BF8[lolo.bp_94 * 4 + 0];
				lolo.i ++;
			}
			if(D_00E73BF8[lolo.bp_94 * 4 + 3]) {
				lolo.bp_8c = D_00E73BF8[lolo.bp_94 * 4 + 0];
				lolo.bp_90 = -1;
			}
			//goto 007774E8
		} else {
			if(lolo.bp_90 && D_00E73BF8[lolo.bp_94 * 4 + 3])
				continue;
			D_00E73340[lolo.i] = D_00E73BF8[lolo.bp_94 * 4 + 0];
			lolo.i ++;
			if(D_00E73BF8[lolo.bp_94 * 4 + 3]) {
				lolo.bp_8c = D_00E73BF8[lolo.bp_94 * 4 + 0];
				lolo.bp_90 = -1;
			}
		}
		if(lolo.i >= 3)
			break;
	}//end while
	//-- sort --
	for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
		for(lolo.j = 0; lolo.j < 2; lolo.j ++) {
			if(D_00E73340[lolo.j] > D_00E73340[lolo.j + 1])
				SWAP(D_00E73340[lolo.j], D_00E73340[lolo.j + 1], lolo.bp_98);
		}//end for
	}//end for
	//-- --
	if(lolo.bp_8c != -1) {
		if(D_00E73340[0] == lolo.bp_8c) {
			D_00E73340[0] = D_00E73340[2];
			D_00E73340[2] = lolo.bp_8c;
		} else if(D_00E73340[1] == lolo.bp_8c) {
			D_00E73340[1] = D_00E73340[2];
			D_00E73340[2] = lolo.bp_8c;
		}
	}
	for(lolo.i = 0; lolo.i < 7; lolo.i ++) {
		lolo.bp_78[lolo.i] = D_00E73340[0];
		lolo.bp_3c[lolo.i] = 0;
	}//end for
	for(lolo.i = 7; lolo.i < 0xc; lolo.i ++) {
		lolo.bp_78[lolo.i] = D_00E73340[1];
		lolo.bp_3c[lolo.i] = 1;
	}//end for
	for(lolo.i = 0xc; lolo.i < 0xf; lolo.i ++) {
		lolo.bp_78[lolo.i] = D_00E73340[2];
		lolo.bp_3c[lolo.i] = 2;
	}//end for
	//-- scramble --
	for(lolo.i = 0; lolo.i < 100; lolo.i ++) {
		lolo.bp_a0 = rand() % 0xf;
		lolo.bp_a4 = rand() % 0xf;
		SWAP(lolo.bp_78[lolo.bp_a0], lolo.bp_78[lolo.bp_a4], lolo.bp_9c);
		SWAP(lolo.bp_3c[lolo.bp_a0], lolo.bp_3c[lolo.bp_a4], lolo.bp_9c);
	}//end for
	//-- --
	for(lolo.j = 0; lolo.j < 3; lolo.j ++) {
		for(lolo.i = 0; lolo.i < 5; lolo.i ++) {
			D_00E71068[lolo.i][lolo.j].f_00 = 0;
			D_00E71068[lolo.i][lolo.j].f_02 = 0;
			D_00E71068[lolo.i][lolo.j].f_03 = 0;
			D_00E71068[lolo.i][lolo.j].f_06 = lolo.bp_78[lolo.i + lolo.j * 5];
			D_00E71068[lolo.i][lolo.j].f_07 = lolo.bp_3c[lolo.i + lolo.j * 5];
			D_00E71068[lolo.i][lolo.j].f_05 = 2;
			//-- --
			D_00E73360[lolo.i][lolo.j].f_00 = 4;
			D_00E73360[lolo.i][lolo.j].f_04.c.r =
			D_00E73360[lolo.i][lolo.j].f_04.c.g =
			D_00E73360[lolo.i][lolo.j].f_04.c.b = 0x80;
			D_00E73360[lolo.i][lolo.j].wU =
			D_00E73360[lolo.i][lolo.j].wV = 0;
			D_00E73360[lolo.i][lolo.j].fU =
			D_00E73360[lolo.i][lolo.j].fV = 0;
			D_00E73360[lolo.i][lolo.j].fZ = 0.9555f;
			D_00E73360[lolo.i][lolo.j].f_30 = 0;
			D_00E73360[lolo.i][lolo.j].dwWidth = D_00E73360[lolo.i][lolo.j].dwHeight = 0x22;
			D_00E73360[lolo.i][lolo.j].fTexHeight = 0.53125f;
			D_00E73360[lolo.i][lolo.j].fTexWidth = 0.53125f;
			D_00E73360[lolo.i][lolo.j].fWidth = D_00E73360[lolo.i][lolo.j].fHeight = 34.0f;

			D_00E737C0[lolo.i][lolo.j].f_00 = 0xb;
			D_00E737C0[lolo.i][lolo.j].f_04.c.r =
			D_00E737C0[lolo.i][lolo.j].f_04.c.g =
			D_00E737C0[lolo.i][lolo.j].f_04.c.b = 0x80;
			D_00E737C0[lolo.i][lolo.j].wU = lolo.i * 0x22;
			D_00E737C0[lolo.i][lolo.j].wV = lolo.j * 0x22 + 0x11;
			D_00E737C0[lolo.i][lolo.j].fU = (float)D_00E737C0[lolo.i][lolo.j].wU / 256.0f;
			D_00E737C0[lolo.i][lolo.j].fV = (float)D_00E737C0[lolo.i][lolo.j].wV / 128.0f;
			D_00E737C0[lolo.i][lolo.j].fZ = 0.9444f;
			D_00E737C0[lolo.i][lolo.j].f_30 = 0;
			D_00E737C0[lolo.i][lolo.j].dwWidth = D_00E737C0[lolo.i][lolo.j].dwHeight = 0x22;
			D_00E737C0[lolo.i][lolo.j].fTexWidth = 0.13f;
			D_00E737C0[lolo.i][lolo.j].fTexHeight = 0.27f;
			D_00E737C0[lolo.i][lolo.j].fWidth = D_00E737C0[lolo.i][lolo.j].fHeight = 34.0f;

			D_00E72F00[lolo.i][lolo.j].f_00 = 9;
			D_00E72F00[lolo.i][lolo.j].f_04.c.r =
			D_00E72F00[lolo.i][lolo.j].f_04.c.g =
			D_00E72F00[lolo.i][lolo.j].f_04.c.b = 0x80;
			D_00E72F00[lolo.i][lolo.j].wU = 0;
			D_00E72F00[lolo.i][lolo.j].wV = 0;
			D_00E72F00[lolo.i][lolo.j].fU = 0;
			D_00E72F00[lolo.i][lolo.j].fV = 0;
			D_00E72F00[lolo.i][lolo.j].fZ = 0.9333f;
			D_00E72F00[lolo.i][lolo.j].f_30 = 0;
			D_00E72F00[lolo.i][lolo.j].dwWidth = D_00E72F00[lolo.i][lolo.j].dwHeight = 0x22;
			D_00E72F00[lolo.i][lolo.j].fTexWidth = 0.53f;
			D_00E72F00[lolo.i][lolo.j].fTexHeight = 0.27f;
			D_00E72F00[lolo.i][lolo.j].fWidth = D_00E72F00[lolo.i][lolo.j].fHeight = 34.0f;
		}//end for
	}//end for
	D_00E72EF8 = &D_00DBFD38.dwGIL;
	D_00E71624 = 0;
}

void C_00777DF4(int bp08) {
	struct {
		int j;//bp_08
		int i;//bp_04
	}lolo;

	for(lolo.j = 0; lolo.j < 3; lolo.j ++) {
		for(lolo.i = 0; lolo.i < 5; lolo.i ++) {
			switch(D_00E71068[lolo.i][lolo.j].f_05) {
				case -1: break;
				case 1:
					switch(D_00E71068[lolo.i][lolo.j].f_00) {
						case 0:
							D_00E71068[lolo.i][lolo.j].f_02 = 0;
							D_00E71068[lolo.i][lolo.j].f_00 = 4;
						break;
						case 1:
							D_00E71068[lolo.i][lolo.j].f_05 = -1;
						break;
						case 2:
							D_00E71068[lolo.i][lolo.j].f_02 = 0x10;
							D_00E71068[lolo.i][lolo.j].f_00 = 5;
						break;
						case 3:
							D_00E71068[lolo.i][lolo.j].f_00 = 4;
						break;
						case 6:
							D_00E71068[lolo.i][lolo.j].f_00 = 5;
						break;
					}//end switch
				break;
				case 2:
					switch(D_00E71068[lolo.i][lolo.j].f_00) {
						case 0:
							D_00E71068[lolo.i][lolo.j].f_02 = 0;
							D_00E71068[lolo.i][lolo.j].f_00 = 6;
						break;
						case 1:
							D_00E71068[lolo.i][lolo.j].f_02 = 0x10;
							D_00E71068[lolo.i][lolo.j].f_00 = 3;
						break;
						case 2:
							D_00E71068[lolo.i][lolo.j].f_05 = -1;
						break;
						case 4:
							D_00E71068[lolo.i][lolo.j].f_00 = 3;
						break;
						case 5:
							D_00E71068[lolo.i][lolo.j].f_00 = 6;
						break;
					}//end switch
				break;
			}//end switch
			switch(D_00E71068[lolo.i][lolo.j].f_00) {
				case 3:
					D_00E71068[lolo.i][lolo.j].f_04 = 0;
					D_00E71068[lolo.i][lolo.j].f_02 -= 2;
					if(D_00E71068[lolo.i][lolo.j].f_02 <= 0)
						D_00E71068[lolo.i][lolo.j].f_00 = 0;
				break;
				case 4:
					D_00E71068[lolo.i][lolo.j].f_04 = 0;
					D_00E71068[lolo.i][lolo.j].f_02 += 2;
					if(D_00E71068[lolo.i][lolo.j].f_02 >= 0x10)
						D_00E71068[lolo.i][lolo.j].f_00 = 1;
				break;
				case 5:
					D_00E71068[lolo.i][lolo.j].f_04 = -1;
					D_00E71068[lolo.i][lolo.j].f_02 -= 2;
					if(D_00E71068[lolo.i][lolo.j].f_02 <= 0)
						D_00E71068[lolo.i][lolo.j].f_00 = 0;
				break;
				case 6:
					D_00E71068[lolo.i][lolo.j].f_04 = -1;
					D_00E71068[lolo.i][lolo.j].f_02 += 2;
					if(D_00E71068[lolo.i][lolo.j].f_02 >= 0x10)
						D_00E71068[lolo.i][lolo.j].f_00 = 2;
				break;
			}//end switch
			D_00E73360[lolo.i][lolo.j].f_14[0].wX = 
			D_00E73360[lolo.i][lolo.j].f_14[2].wX = lolo.i * 0x22 + 0x17 - (D_00E71068[lolo.i][lolo.j].f_02 * 0x10) / 0x10;
			D_00E73360[lolo.i][lolo.j].f_14[1].wX = 
			D_00E73360[lolo.i][lolo.j].f_14[3].wX = lolo.i * 0x22 + 0x17 + (D_00E71068[lolo.i][lolo.j].f_02 * 0x10) / 0x10;
			if(D_00E71128 && bp08) {//else 007782A0
				if(D_0097B470[lolo.j * 5 + lolo.i][0] == 0 || D_0097B470[lolo.j * 5 + lolo.i][1] == 0)
					D_00E71068[lolo.i][lolo.j].f_05 = 1;
				//goto 00778393
			} else if(lolo.i == D_00E737B8 && lolo.j == D_00E737B4 && D_00E737A4) {//else 0077834E
				D_00E73360[lolo.i][lolo.j].f_04.c.r =
				D_00E73360[lolo.i][lolo.j].f_04.c.b =
				D_00E73360[lolo.i][lolo.j].f_04.c.g = (D_00E72EF0 & 8)?0xb0:0x50;
			} else {
				D_00E73360[lolo.i][lolo.j].f_04.c.r =
				D_00E73360[lolo.i][lolo.j].f_04.c.g =
				D_00E73360[lolo.i][lolo.j].f_04.c.b = 0x80;
			}
			if(D_00E71068[lolo.i][lolo.j].f_04 == 0) {//else 007784BF
				D_00E73360[lolo.i][lolo.j].f_00 = 5;
				D_00E73360[lolo.i][lolo.j].f_14[0].wY = lolo.j * 0x22 + 0x29 - D_00E71068[lolo.i][lolo.j].f_02 / 4 + 4;
				D_00E73360[lolo.i][lolo.j].f_14[1].wY = lolo.j * 0x22 + 0x25 + D_00E71068[lolo.i][lolo.j].f_02 / 4;
				D_00E73360[lolo.i][lolo.j].f_14[2].wY = lolo.j * 0x22 + 0x47 + D_00E71068[lolo.i][lolo.j].f_02 / 4;
				D_00E73360[lolo.i][lolo.j].f_14[3].wY = lolo.j * 0x22 + 0x4b - D_00E71068[lolo.i][lolo.j].f_02 / 4 + 4;
				//goto 007785CD
			} else {
				D_00E73360[lolo.i][lolo.j].f_00 = 4;
				D_00E73360[lolo.i][lolo.j].f_14[0].wY = lolo.j * 0x22 + 0x25 + D_00E71068[lolo.i][lolo.j].f_02 / 4;
				D_00E73360[lolo.i][lolo.j].f_14[1].wY = lolo.j * 0x22 + 0x29 - D_00E71068[lolo.i][lolo.j].f_02 / 4 + 4;
				D_00E73360[lolo.i][lolo.j].f_14[2].wY = lolo.j * 0x22 + 0x4b - D_00E71068[lolo.i][lolo.j].f_02 / 4 + 4;
				D_00E73360[lolo.i][lolo.j].f_14[3].wY = lolo.j * 0x22 + 0x47 + D_00E71068[lolo.i][lolo.j].f_02 / 4;
			}
			D_00E737C0[lolo.i][lolo.j].f_14[0].wX = D_00E73360[lolo.i][lolo.j].f_14[0].wX;
			D_00E737C0[lolo.i][lolo.j].f_14[1].wX = D_00E73360[lolo.i][lolo.j].f_14[1].wX;
			D_00E737C0[lolo.i][lolo.j].f_14[2].wX = D_00E73360[lolo.i][lolo.j].f_14[2].wX;
			D_00E737C0[lolo.i][lolo.j].f_14[3].wX = D_00E73360[lolo.i][lolo.j].f_14[3].wX;
			D_00E737C0[lolo.i][lolo.j].f_14[0].wY = D_00E73360[lolo.i][lolo.j].f_14[0].wY;
			D_00E737C0[lolo.i][lolo.j].f_14[1].wY = D_00E73360[lolo.i][lolo.j].f_14[1].wY;
			D_00E737C0[lolo.i][lolo.j].f_14[2].wY = D_00E73360[lolo.i][lolo.j].f_14[2].wY;
			D_00E737C0[lolo.i][lolo.j].f_14[3].wY = D_00E73360[lolo.i][lolo.j].f_14[3].wY;
			C_0077A89F(&(D_00E73360[lolo.i][lolo.j]));
			//-- patch for SW --
			if(D_00E3BA68.dwSWRenderer)
				C_0077AC35(&(D_00E73360[lolo.i][lolo.j]));
			//-- --
			C_0077A89F(&(D_00E737C0[lolo.i][lolo.j]));
			if(D_00E71068[lolo.i][lolo.j].f_03) {//else 007789E9
				D_00E72F00[lolo.i][lolo.j].f_14[0].wX = D_00E73360[lolo.i][lolo.j].f_14[0].wX;
				D_00E72F00[lolo.i][lolo.j].f_14[1].wX = D_00E73360[lolo.i][lolo.j].f_14[1].wX;
				D_00E72F00[lolo.i][lolo.j].f_14[2].wX = D_00E73360[lolo.i][lolo.j].f_14[2].wX;
				D_00E72F00[lolo.i][lolo.j].f_14[3].wX = D_00E73360[lolo.i][lolo.j].f_14[3].wX;
				D_00E72F00[lolo.i][lolo.j].f_14[0].wY = D_00E73360[lolo.i][lolo.j].f_14[0].wY;
				D_00E72F00[lolo.i][lolo.j].f_14[1].wY = D_00E73360[lolo.i][lolo.j].f_14[1].wY;
				D_00E72F00[lolo.i][lolo.j].f_14[2].wY = D_00E73360[lolo.i][lolo.j].f_14[2].wY;
				D_00E72F00[lolo.i][lolo.j].f_14[3].wY = D_00E73360[lolo.i][lolo.j].f_14[3].wY;
				D_00E72F00[lolo.i][lolo.j].wV = D_00E71068[lolo.i][lolo.j].f_07 * 0x22;
				switch(D_00E71068[lolo.i][lolo.j].f_07) {
					case 1: D_00E72F00[lolo.i][lolo.j].fV = 0.27f; break;
					case 2: D_00E72F00[lolo.i][lolo.j].fV = 0.53f; break;
					default:
						D_00E72F00[lolo.i][lolo.j].fV = 0;
				}//end switch
				C_0077A89F(&(D_00E72F00[lolo.i][lolo.j]));
			}
		}//end for
	}//end for
}

void C_00778A3C() {
	unsigned short i;

	D_00E737A4 = -1;
	D_00E737B0 = 0;

	D_00E71664->f_00 = 0xc1;
	D_00E71664->f_04[0] = 0x1e;
	D_00E71664->f_04[1] = 0x1e;
	C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);

	C_0076BA66();
	D_00E715D4 = -0x10;
	D_00E710EC = 0xff;
	D_00E73C04 = 0;

	D_00E71664->f_00 = 0x10;
	D_00E71664->f_04[0] = 0;
	C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);
	for(i = 0; i < 6; i ++) {
		if(D_00E71158[i].f_70 == 1)
			D_00E73338 = D_00E72EF4 = i;
		if(D_00E71158[i].f_70 == 2)
			D_00E737BC = i;
	}//end for
	if(D_00E72EF4 > D_00E737BC)
		SWAP(D_00E72EF4, D_00E737BC, i);
	for(i = 0; i < 0x10; i ++) {
		if(D_00E72EF4 == D_0097B470[i][0] && D_00E737BC == D_0097B470[i][1])
			break;
	}//end for
	if(i == 0x10)
		i = 0;
	D_00E737B8 = D_0097B470[i][2];
	D_00E737B4 = D_0097B470[i][3];
}

//refresh "bet results"
void C_00778C5D() {
	struct {
		int j_4;//bp_30
		int i_4;//bp_2c
		int j_3;//bp_28
		int i_3;//bp_24
		int j_2;//bp_20
		int i_2;//bp_1c
		int j_1;//bp_18
		int i_1;//bp_14
		int j_0;//bp_10
		char _p_0c[4];
		int i_0;//bp_08
		char _p_04[4];
	}lolo;

	D_00E71108 = 0;
	C_00777DF4(0);
	for(lolo.i_0 = 0; lolo.i_0 < 6; lolo.i_0 ++) {
		for(lolo.j_0 = 0; lolo.j_0 < 6; lolo.j_0 ++) {
			if(D_00E71158[lolo.j_0].f_70 == lolo.i_0 + 1) {//else 00778E4A
				C_0077941B(D_00E71158[lolo.j_0].f_88, 7, 0xdc, D_0097A4E0[lolo.i_0]);//draw string?
				D_0097B650[D_00E71158[lolo.j_0].f_92].f_14[2].wX = 0x12a;
				D_0097B650[D_00E71158[lolo.j_0].f_92].f_14[0].wX = 0x12a;
				D_0097B650[D_00E71158[lolo.j_0].f_92].f_14[3].wX = 0x12a + 0x10;
				D_0097B650[D_00E71158[lolo.j_0].f_92].f_14[1].wX = 0x12a + 0x10;
				D_0097B650[D_00E71158[lolo.j_0].f_92].f_14[0].wY = 
				D_0097B650[D_00E71158[lolo.j_0].f_92].f_14[2].wY = D_0097A4E0[lolo.i_0];
				D_0097B650[D_00E71158[lolo.j_0].f_92].f_14[1].wY =
				D_0097B650[D_00E71158[lolo.j_0].f_92].f_14[3].wY = D_0097A4E0[lolo.i_0] + 0x10;
				C_0077A469(&(D_0097B650[D_00E71158[lolo.j_0].f_92]));//draw sprite?
				D_00E71108 ++;
			}
		}//end for
	}//end for
	if(D_00E737B0 == 0xa) {
		D_00E71664->f_00 = 0x28;
		D_00E71664->f_04[0] = 0x40;
		D_00E71664->f_04[1] = 0x84;
		C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);
	}
	if(D_00E737B0 == 0xa) {
		for(lolo.j_1 = 0; lolo.j_1 < 3; lolo.j_1 ++) {
			for(lolo.i_1 = 0; lolo.i_1 < 5; lolo.i_1 ++)
				D_00E71068[lolo.i_1][lolo.j_1].f_05 = D_00E71068[lolo.i_1][lolo.j_1].f_04?1:2;
		}//end for
	}
	if(D_00E737B0 == 0x1e && D_00E71128 && D_00E73338 != D_00E71158[0].f_92) {
		for(lolo.j_2 = 0; lolo.j_2 < 3; lolo.j_2 ++) {
			for(lolo.i_2 = 0; lolo.i_2 < 5; lolo.i_2 ++)
				D_00E71068[lolo.i_2][lolo.j_2].f_05 = 1;
		}//end for
	}
	if(D_00E737B0 == 0x6e) {
		for(lolo.j_3 = 0; lolo.j_3 < 3; lolo.j_3 ++) {
			for(lolo.i_3 = 0; lolo.i_3 < 5; lolo.i_3 ++)
				D_00E71068[lolo.i_3][lolo.j_3].f_05 = D_00E71068[lolo.i_3][lolo.j_3].f_04?1:2;
		}//end for
	}
	if(D_00E737B0 == 0x73) {
		for(lolo.j_4 = 0; lolo.j_4 < 3; lolo.j_4 ++) {
			for(lolo.i_4 = 0; lolo.i_4 < 5; lolo.i_4 ++)
				D_00E71068[lolo.i_4][lolo.j_4].f_03 = -1;
		}//end for
		if(D_00E71068[D_00E737B8][D_00E737B4].f_04)
			D_00DC0AF8 = D_0097BB60[D_00E71068[D_00E737B8][D_00E737B4].f_06];
		//-- set player's ranking in save file --
		D_00DC0AF5 = D_00E71158[0].f_70 - 1;
	}
	D_00E737B0 ++;
	D_00E71018 ++;
	D_00E72EF0 += 2;
	//-- --
	C_0076E149();//chocobo:compute input mask
	if(D_00E71620 != D_00E71100 && (D_00E71620 & (BIT(CH_KEY_START)|BIT(CH_KEY_SWITCH)|BIT(CH_KEY_CANCEL)|BIT(CH_KEY_OK)|BIT(CH_KEY_MENU))/*0x8f0*/) && D_00E737B0 >= 0xA0)
		D_00E715D4 = 0x10;
	//-- --
	if(D_00E710EC > 0xff && D_00E715D4 > 0) {
		D_00E715D4 = 0;

		D_00E71664->f_00 = 0xc1;
		D_00E71664->f_04[0] = 0x1e;
		D_00E71664->f_04[1] = 0x1e;
		C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);
		D_00E3B740 = 6;
	}
	if(D_00E3B740 == 5) {//else 007792C9
		C_0077A3A2(&D_0097B4E8);
		C_0077A3A2(&D_0097B530);
		for(lolo.i_0 = 0; lolo.i_0 < 9; lolo.i_0 ++) {
			C_0077A469(&(D_00E3BAA8[lolo.i_0]));//draw sprite?
			D_00E71108 ++;
		}//end for
		for(lolo.i_0 = 0; lolo.i_0 < 0xb; lolo.i_0 ++) {
			C_0077A469(&(D_00E3BAA0[lolo.i_0]));//draw sprite?
			D_00E71108 ++;
		}//end for
		D_00E3BAB0[D_00E72EF4].f_14[0].wX = 213;
		D_00E3BAB0[D_00E72EF4].f_14[0].wY = 10;
		C_0077A469(&(D_00E3BAB0[D_00E72EF4]));//draw sprite?
		D_00E71108 ++;

		D_00E3BAB0[D_00E737BC].f_14[0].wX = 243;
		D_00E3BAB0[D_00E737BC].f_14[0].wY = 10;
		C_0077A469(&(D_00E3BAB0[D_00E737BC]));//draw sprite?
		D_00E71108 ++;

		D_00E71108 ++;
		C_007792CD();//display prizes
		C_0077946A();//refresh fade in/out
		C_0077B2CA();//chocobo:renderer?
	}
}

//display prizes
void C_007792CD() {
	int i;//local_1

	C_0077941B(D_0097C9D0[D_00E73340[0]], 0xe, 0x25, 0xac);//draw string?
	C_0077941B(D_0097C9D0[D_00E73340[1]], 0xe, 0x25, 0xc0);//draw string?
	C_0077941B(D_0097C9D0[D_00E73340[2]], 0xe, 0x25, 0xd4);//draw string?
	for(i = 0; i < 3; i ++) {
		D_0097BBC0[i].f_14[0].wX =
		D_0097BBC0[i].f_14[2].wX = 0xf;
		D_0097BBC0[i].f_14[0].wY =
		D_0097BBC0[i].f_14[1].wY = i * 0x15 + 0xa9;
		D_0097BBC0[i].f_14[1].wX =
		D_0097BBC0[i].f_14[3].wX = 0xf + 0x10;
		D_0097BBC0[i].f_14[2].wY =
		D_0097BBC0[i].f_14[3].wY = i * 0x15 + 0xa9 + 0x10;
		C_0077A469(&(D_0097BBC0[i]));//draw sprite?
		D_00E71108 ++;
	}//end for
}

//draw string?
void C_0077941B(unsigned char *bp08, int _p0c, int dwX/*bp10*/, int dwY/*bp14*/) {
	if(D_00E3BA68.dwGrMode == 2)
		C_006F5B03(dwX * 2, (dwY + 4) * 2, bp08, 7, 0.44f);//menu.drawString[HIRES]
	else
		C_006FAB2F(dwX, dwY + 4, bp08, 7, 0.44f);//menu.drawString[LORES]
}

//refresh fade in/out
void C_0077946A() {
	if(D_00E710EC) {
		D_0097A498.f_04.c.r =
		D_0097A498.f_04.c.g =
		D_0097A498.f_04.c.b = D_00E710EC;
		C_0077B1CE(&D_0097A498);
	}
	D_00E710EC += D_00E715D4;
	if(D_00E710EC < 0) {
		D_00E710EC = 0;
		D_00E715D4 = 0;
	} else if(D_00E710EC > 0x100) {
		D_00E710EC = 0x100;
	}
}

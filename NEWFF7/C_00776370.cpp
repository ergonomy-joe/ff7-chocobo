/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- bet menu/bet results?

#include "ff7.h"
#include "chocobo_data.h"
#include "menu_data.h"
////////////////////////////////////////
//bet price
int D_0097A440[4][4] = {
	{0,100,200,300},//class C
	{0,200,400,600},//class B
	{0,300,600,900},//class A
	{0,500,1000,1500},//class S
};
int __0097A480[] = {0,0,320,480};
int D_0097A490 = 0x40;//displayed chocobo rot(x)
int D_0097A494 = 0x80;//displayed chocobo rot(z)
//for fade in/out
struct t_chocobo_SpriteUI D_0097A498 = {
	0x19,
	{0,0,0,0},
	0,0,
	0,
	0,
	0,0,
	320,0,
	0,240,
	320,240,
	0.011f,
	320,240,
	0,
	0,
	0,
	0,
	0,
	0
};
//y pos for strings?
int D_0097A4E0[6] = {
	56,
	89,
	120,
	149,
	179,
	209
};
////////////////////////////////////////
extern short D_0097B470[][4];
extern struct t_chocobo_SpriteUI D_0097B4E8;
extern struct t_chocobo_SpriteUI D_0097B530;
extern struct t_chocobo_SpriteUI D_0097B578;
extern struct t_chocobo_SpriteUI D_0097B5C0;
extern struct t_chocobo_SpriteUI D_0097B608;
extern struct t_chocobo_SpriteUI D_0097B650[];
extern int D_0097BB60[];//id of won prize
extern struct t_chocobo_SpriteUI D_0097BBC0[];
extern struct t_chocobo_SpriteUI D_0097C1A8[];

extern char D_0097C8B0[];
extern char D_0097C910[];
extern char D_0097C968[];
extern char D_0097C9A8[];
extern unsigned char D_0097C9D0[][0x10];
////////////////////////////////////////
extern int D_00E3B748;//race class

extern int D_00E3BA90;//# of elements in D_00E3BA9C[0][]

extern void (*D_00E3BABC)(unsigned, int, int);//draw integer(callback)

extern struct t_chocobo_Ranking D_00E71068[][3];
extern int D_00E710EC;//fade:current alpha

extern int D_00E71130;//race class(2)

extern int D_00E715D4;//fade:alpha increment

extern int D_00E71600;//progress flag?
////////////////////////////////////////
int D_00E72EF0;//frame counter[for cursor]
int D_00E72EF4;//1st(or 2nd) chocobo
unsigned *D_00E72EF8;//party's gil
struct t_chocobo_SpriteUI D_00E72F00[5][3];
int D_00E73338;
//00E7333C
int D_00E73340[3];
int D_00E7334C;//240{-0x400~0x400}[unused stuff]
int D_00E73350;//900{150~0x800}[unused stuff]
int D_00E73354;//320{-0x400~0x400}[unused stuff]
//00E73358
struct t_chocobo_SpriteUI D_00E73360[5][3];
	/*coordinates meaning:
	+---+---+---+---+---+
	| 1 | 11| 21| 31| 41|
	+---+---+---+---+---+
	| 2 | 12| 22| 32| 42|
	+---+---+---+---+---+
	| 3 | 13| 23| 33| 43|
	+---+---+---+---+---+
	*/
int D_00E73798[3];//flipped cells coordinates
int D_00E737A4;//flag for "cursor"
//00E737A8
int D_00E737AC;//index in D_00E73798[]
int D_00E737B0;//frame counter["bet results"]
int D_00E737B4;//bet y
int D_00E737B8;//bet x
int D_00E737BC;//2nd(or 1st) chocobo
struct t_chocobo_SpriteUI D_00E737C0[5][3];
char *D_00E73BF8;
int D_00E73BFC;//displayed chocobo rot(y)
int D_00E73C00;//flag for sound fx
int D_00E73C04;//[set|not used]
int D_00E73C08;
int D_00E73C0C;//counter for animation
////////////////////////////////////////
void __00776370() {
}

void C_0077642F(void);//reset [unused stuff]
void C_007772AE(void);//prepare "bet grid"?

//chocobo:before "bet menu"
void C_00776375() {
	//-- start BGM --
	D_00E71664->wOpCode = SOUND_OP_10;//"MUSIC"
	D_00E71664->f_04[0] = 0x3d;
	C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);
	//-- --
	C_0077642F();//reset [unused stuff]
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

//reset [unused stuff]
void C_0077642F() {
	//--
	//looks like the parameters for the
	// transformation matrix(trans part)
	// in C_0076D6DF()
	//--
	D_00E73350 = 900;
	D_00E7334C = 240;
	D_00E73354 = 320;
}

void C_00776F0D(int);//render chocobo/jockey model
void C_00777DF4(int);//refresh "bet grid"?
void C_007792CD(void);//display prizes
void C_0077941B(unsigned char *, int, int, int);//draw string?

//chocobo:refresh "bet menu"
void C_00776452() {
	struct {
		int bp_10;
		int bp_0c;
		int bp_08;
		int i;//bp_04
	}lolo;

	D_00E73C00 = 0;
	D_00E71108 = 0;//reset "# polygons rendered"
	C_00777DF4(1);//refresh "bet grid"?
	//-- fade over->start race --
	if(D_00E710EC > 0xff && D_00E715D4 > 0) {
		D_00E715D4 = 0;

		*D_00E72EF8 -= D_0097A440[D_00E71130][D_00E73C08];
		D_00E3B740 = 2;//"start race"
	}
	//-- --
	if(D_00E3B740 == 1) {//else 00776B88
		//"bet menu"
		D_00E71018 ++;
		D_00E72EF0 ++;
		//-- manage input --
		C_0076E149();//chocobo:input.compute_mask
		if(D_00E71620 != D_00E71100) {//else 00776844
			//-- [NUMPAD_5] --
			if(D_00E71620 & BIT(CH_KEY_START))
				D_00E715D4 = 0x10;//start fade
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
					//-- is cell already flipped? --
					for(lolo.bp_08 = 0; lolo.bp_08 < 3; lolo.bp_08 ++) {
						if(++D_00E737AC > 2) D_00E737AC = 0;
						if(D_00E73798[D_00E737AC] == D_00E737B8 * 10 + D_00E737B4) {
							D_00E71068[D_00E737B8][D_00E737B4].bFlipAction = 2;//flip back
							D_00E73798[D_00E737AC] = -1;
							break;
						}
					}//end for
					if(lolo.bp_08 == 3) {//else 007767A7
						//-- is there a free slot in "flipped" array? --
						for(lolo.bp_08 = 0; lolo.bp_08 < 3; lolo.bp_08 ++) {
							if(++D_00E737AC > 2) D_00E737AC = 0;
							if(D_00E73798[D_00E737AC] == -1 || D_00E73798[D_00E737AC] == D_00E737B8 * 10 + D_00E737B4) {
								D_00E71068[D_00E737B8][D_00E737B4].bFlipAction = 1;//flip
								D_00E73798[D_00E737AC] = D_00E737B8 * 10 + D_00E737B4;
								break;
							}
						}//end for
						if(lolo.bp_08 == 3) {//else 007767A7
							//-- flip back older "flipped" item in array --
							if(++D_00E737AC > 2) D_00E737AC = 0;
							lolo.bp_0c = D_00E73798[D_00E737AC] / 10;
							lolo.bp_10 = D_00E73798[D_00E737AC] % 10;
							D_00E71068[lolo.bp_0c][lolo.bp_10].bFlipAction = 2;//flip back
							D_00E71068[D_00E737B8][D_00E737B4].bFlipAction = 1;//flip
							D_00E73798[D_00E737AC] = D_00E737B8 * 10 + D_00E737B4;
						}
					}
					D_00E73C08 = 0;
					for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
						if(D_00E73798[lolo.i] != -1)
							D_00E73C08 ++;
					}//end for
					if(*D_00E72EF8 - D_0097A440[D_00E71130][D_00E73C08] > *D_00E72EF8) {//else 00776844
						D_00E71068[D_00E737B8][D_00E737B4].bFlipAction = 2;//flip back
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
			D_00E71664->wOpCode = SOUND_OP_20;//"SOUND"
			D_00E71664->f_04[0] = 0x40;
			D_00E71664->f_04[1] = 1;
			C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);
			D_00E73C00 = 0;
		}
		//-- bg --
		C_0077A3A2(&D_0097B4E8);//chocobo:draw quad[background]
		C_0077A3A2(&D_0097B530);//chocobo:draw quad[background]
		//-- --
		C_00776F0D(D_00E71624);//render chocobo/jockey model
		//-- frame elements --
		for(lolo.i = 0; lolo.i < 10; lolo.i ++) {
			if((lolo.i == 6 || lolo.i == 7) && (D_00E3B748 == 1 || D_00E3B748 == 2))
				D_0097C1A8[lolo.i].dwRenderId = 0x1a;
			C_0077A469(&(D_00E3BA9C[2][lolo.i]));//chocobo:draw sprite[UI]
			D_00E71108 ++;
		}//end for
		//-- ? --
		D_00E71108 ++;
		//-- text elements --
		for(lolo.i = 0; lolo.i < D_00E3BA90; lolo.i ++) {
			C_0077A469(&(D_00E3BA9C[0][lolo.i]));//chocobo:draw sprite[UI]
			D_00E71108 ++;
		}//end for
		//-- chocobo # --
		C_0077A469(&(D_00E3BA9C[4][D_00E71624]));//chocobo:draw sprite[UI]
		D_00E71108 ++;
		//-- GIL/TOP SPEED/STAMINA --
		D_00E3BABC(*D_00E72EF8 - D_0097A440[D_00E71130][D_00E73C08], 276, 214);//draw integer(callback)
		D_00E3BABC(TARGET_CHOCOBO.wTopSpeed / 34, 284, 43);//draw integer(callback)
		D_00E3BABC(TARGET_CHOCOBO.dwStamina / 10, 284, 66);//draw integer(callback)
		//-- --
		C_007792CD();//display prizes
		C_0077941B(TARGET_CHOCOBO.aName, 6, 240, 88);//draw string?
		//-- --
		C_0077946A();//chocobo:refresh fade in/out
		C_0077B2CA();//chocobo:renderer?
	}
}

//chocobo:draw integer(callback)[LORES]
void C_00776B8C(unsigned dwVal/*bp08*/, int dwX/*bp0c*/, int dwY/*bp10*/) {
	struct {
		struct t_chocobo_SpriteUI bp_324[11];//local_201
		int local_3;
		int i;//local_2
		int dwStopLoop;//local_1
	}lolo;

	lolo.dwStopLoop = 0;
	D_00E71108 ++;
	if(dwVal == 0) {
		lolo.i = 0;
		lolo.bp_324[lolo.i] = D_0097B608;
		lolo.bp_324[lolo.i].wX0 = dwX;
		lolo.bp_324[lolo.i].wY0 = dwY;
		C_0077A469(&(lolo.bp_324[0]));//chocobo:draw sprite[UI]
		D_00E71108 ++;
	} else {
		for(lolo.i = 0; lolo.i < 11 && lolo.dwStopLoop == 0; lolo.i ++) {
			lolo.bp_324[lolo.i] = D_0097B608;
			lolo.local_3 = dwVal % 10;
			//
			//
			//
			//
			lolo.bp_324[lolo.i].wX0 = dwX - lolo.i * 12;
			lolo.bp_324[lolo.i].wY0 = dwY;
			if(dwVal) {
				//
				lolo.bp_324[lolo.i].wU = lolo.local_3 * 16 + 8;
				//
				//
				lolo.bp_324[lolo.i].fU = (float)lolo.bp_324[lolo.i].wU / 256.0f;
			} else {
				lolo.dwStopLoop = 1;
			}
			if(dwVal > 0) {
				dwVal /= 10;
				C_0077A469(&(lolo.bp_324[lolo.i]));//chocobo:draw sprite[UI]
				D_00E71108 ++;
			}
		}//end for
	}
}

//chocobo:draw integer(callback)[HIRES]
void C_00776D2B(unsigned dwVal/*bp08*/, int dwX/*bp0c*/, int dwY/*bp10*/) {
	struct {
		struct t_chocobo_SpriteUI bp_324[11];//local_201
		int local_3;
		int i;//local_2
		int dwStopLoop;//local_1
	}lolo;

	lolo.dwStopLoop = 0;
	D_00E71108 ++;
	if(dwVal == 0) {
		lolo.i = 0;
		lolo.bp_324[lolo.i] = D_0097B578;
		lolo.bp_324[lolo.i].wX0 = dwX;
		lolo.bp_324[lolo.i].wY0 = dwY;
		C_0077A469(&(lolo.bp_324[0]));//chocobo:draw sprite[UI]
		D_00E71108 ++;
	} else {
		for(lolo.i = 0; lolo.i < 11 && lolo.dwStopLoop == 0; lolo.i ++) {
			//
			lolo.local_3 = dwVal % 10;
			if(lolo.local_3 < 7)
				lolo.bp_324[lolo.i] = D_0097B578;
			else
				lolo.bp_324[lolo.i] = D_0097B5C0;
			lolo.bp_324[lolo.i].wX0 = dwX - lolo.i * 12;
			lolo.bp_324[lolo.i].wY0 = dwY;
			if(dwVal) {
				if(lolo.local_3 < 7)
					lolo.bp_324[lolo.i].wU = lolo.local_3 * 32 + 16;
				else
					lolo.bp_324[lolo.i].wU = (lolo.local_3 - 7) * 32 + 120;
				lolo.bp_324[lolo.i].fU = (float)lolo.bp_324[lolo.i].wU / 256.0f;
			} else {
				lolo.dwStopLoop = 1;
			}
			if(dwVal > 0) {
				dwVal /= 10;
				C_0077A469(&(lolo.bp_324[lolo.i]));//chocobo:draw sprite[UI]
				D_00E71108 ++;
			}
		}//end for
	}
}

//render chocobo/jockey model
void C_00776F0D(int bp08) {
	struct {
		char _ocal_53[0x48];
		struct t_chocobo_Model3D *pModelC;//local_35
		char _ocal_34[0x10];
		struct t_chocobo_Model3D *pModelJ;//local_30
		char _ocal_29[0x40];
		struct t_chocobo_ChocoboInfo *pChocobo;//local_13
		char _ocal_12[4];
		int dwDevMask;//local_11
		char _ocal_10[4];
		int dwAnmNum;//local_9
		char _ocal_8[0x20];
	}lolo;

	lolo.pChocobo = &(D_00E71158[bp08]);
	//-- dash? --
	if(lolo.pChocobo->f_4c == 2)
		lolo.dwAnmNum = 1;
	else
		lolo.dwAnmNum = 0;
	//-- --
	lolo.pModelJ = &(D_00E719E8[lolo.pChocobo->wJockeyId]);
	lolo.pModelC = &(D_00E719E8[lolo.pChocobo->wChocoboId]);
	//-- [end] --
	if(D_00E71620 & BIT(CH_KEY_TARGET)) {//else 0077715B
		lolo.dwDevMask = D_00E71620 >> 16;
		//-- rotate chocobo(y) --
		if(lolo.dwDevMask & BIT(15))
			D_00E73BFC ++;
		if(lolo.dwDevMask & BIT(13))
			D_00E73BFC --;
		//-- rotate chocobo(x) --
		if(lolo.dwDevMask & BIT(12))
			D_0097A490 ++;
		if(lolo.dwDevMask & BIT(14))
			D_0097A490 --;
		//-- rotate chocobo(z) --
		if(lolo.dwDevMask & BIT(2))
			D_0097A494 ++;
		if(lolo.dwDevMask & BIT(0))
			D_0097A494 --;
		//-- screen z/zoom related[unused stuff] --
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
		//-- screen x/width related[unused stuff] --
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
		//-- screen y/height related[unused stuff] --
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
			C_0077642F();//reset [unused stuff]
		//-- --
	} else {
		//-- rotate chocobo automaticaly --
		if(D_00E71018 & 2)
			D_00E73BFC ++;
	}
	lolo.pModelC->bRotX = lolo.pModelJ->bRotX = 0x100 - D_0097A490;
	lolo.pModelC->bRotY = lolo.pModelJ->bRotY = 0x100 - D_00E73BFC;
	lolo.pModelC->bRotZ = lolo.pModelJ->bRotZ = 0x100 - D_0097A494;

	lolo.pModelC->wY = lolo.pModelJ->wY;

	lolo.pModelJ->dwPatchRotY = lolo.pModelC->dwPatchRotY = 0;
	//-- animation counter --
	D_00E73C0C += 0x100;
	if((D_00E73C0C >> 8) >= lolo.pModelJ->dwMaxAnimationFrame)
		D_00E73C0C &= 0xff;
	//-- --
	lolo.pModelJ->wPrevAnimationId = lolo.pModelJ->wAnimationId;
	lolo.pModelC->wPrevAnimationId = lolo.pModelC->wAnimationId;
	lolo.pModelJ->wAnimationId = lolo.dwAnmNum; lolo.pModelJ->dwAnimationFrame = D_00E73C0C >> 8;
	lolo.pModelC->wAnimationId = lolo.dwAnmNum; lolo.pModelC->dwAnimationFrame = D_00E73C0C >> 8;
	//-- jockey --
	C_0077B7E2(lolo.pModelJ);//chocobo:refresh position/rotation[3D model]?
	//-- chocobo --
	C_0077B7E2(lolo.pModelC);//chocobo:refresh position/rotation[3D model]?
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
		int dwPrizCount;//bp_88
		int j;//bp_84
		int i;//bp_80
		int *bp_7c;
		int aPrizeId[15];//bp_78
		int aPrizeIndex[15];//bp_3c
	}lolo;

	lolo.j = 0;
	switch(D_00E71130) {
		case 0: D_00E73BF8 = D_0097C9A8; break;
		case 1: D_00E73BF8 = D_0097C968; break;
		case 2: D_00E73BF8 = D_0097C910; break;
		case 3: D_00E73BF8 = D_0097C8B0; break;
	}//end switch
	lolo.bp_7c = (int *)D_00E73BF8;
	lolo.dwPrizCount = *lolo.bp_7c;
	D_00E73BF8 += 4;

	lolo.i = 0;
	D_00E73340[0] = D_00E73340[1] = D_00E73340[2] = -1;
	lolo.bp_90 = 0;
	lolo.bp_8c = -1;
	while(lolo.i != 3) {
		//-- --
		lolo.bp_94 = rand() % lolo.dwPrizCount;
		if(
			D_00E73BF8[lolo.bp_94 * 4 + 0] == D_00E73340[0] ||
			D_00E73BF8[lolo.bp_94 * 4 + 0] == D_00E73340[1] ||
			D_00E73BF8[lolo.bp_94 * 4 + 0] == D_00E73340[2]
		) continue;
		//-- --
		if(D_00E73BF8[lolo.bp_94 * 4 + 1]) {//else 0077746D
			if(lolo.bp_90 && D_00E73BF8[lolo.bp_94 * 4 + 3])
				continue;
			//-- progress flag? --
			if(D_00E71600) {
				D_00E73340[lolo.i] = D_00E73BF8[lolo.bp_94 * 4 + 0];
				lolo.i ++;
			}
			//-- --
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
		lolo.aPrizeId[lolo.i] = D_00E73340[0];
		lolo.aPrizeIndex[lolo.i] = 0;
	}//end for
	for(lolo.i = 7; lolo.i < 12; lolo.i ++) {
		lolo.aPrizeId[lolo.i] = D_00E73340[1];
		lolo.aPrizeIndex[lolo.i] = 1;
	}//end for
	for(lolo.i = 12; lolo.i < 15; lolo.i ++) {
		lolo.aPrizeId[lolo.i] = D_00E73340[2];
		lolo.aPrizeIndex[lolo.i] = 2;
	}//end for
	//-- scramble --
	for(lolo.i = 0; lolo.i < 100; lolo.i ++) {
		lolo.bp_a0 = rand() % 15;
		lolo.bp_a4 = rand() % 15;
		SWAP(lolo.aPrizeId[lolo.bp_a0], lolo.aPrizeId[lolo.bp_a4], lolo.bp_9c);
		SWAP(lolo.aPrizeIndex[lolo.bp_a0], lolo.aPrizeIndex[lolo.bp_a4], lolo.bp_9c);
	}//end for
	//-- --
	for(lolo.j = 0; lolo.j < 3; lolo.j ++) {
		for(lolo.i = 0; lolo.i < 5; lolo.i ++) {
			D_00E71068[lolo.i][lolo.j].wState = 0;
			D_00E71068[lolo.i][lolo.j].bCounter = 0;
			D_00E71068[lolo.i][lolo.j].bDisplayPrize = 0;
			D_00E71068[lolo.i][lolo.j].bPrizeId = lolo.aPrizeId[lolo.i + lolo.j * 5];
			D_00E71068[lolo.i][lolo.j].bPrizeIndex = lolo.aPrizeIndex[lolo.i + lolo.j * 5];
			D_00E71068[lolo.i][lolo.j].bFlipAction = 2;//flip back
			//-- --
			D_00E73360[lolo.i][lolo.j].dwRenderId = 0x04;
			D_00E73360[lolo.i][lolo.j].f_04.c.r =
			D_00E73360[lolo.i][lolo.j].f_04.c.g =
			D_00E73360[lolo.i][lolo.j].f_04.c.b = 0x80;
			D_00E73360[lolo.i][lolo.j].wU =
			D_00E73360[lolo.i][lolo.j].wV = 0;
			D_00E73360[lolo.i][lolo.j].fU =
			D_00E73360[lolo.i][lolo.j].fV = 0;
			D_00E73360[lolo.i][lolo.j].fZ = 0.9555f;
			D_00E73360[lolo.i][lolo.j].dwPalette = 0;
			D_00E73360[lolo.i][lolo.j].dwWidth = D_00E73360[lolo.i][lolo.j].dwHeight = 34;
			D_00E73360[lolo.i][lolo.j].fTexHeight = 0.53125f;
			D_00E73360[lolo.i][lolo.j].fTexWidth = 0.53125f;
			D_00E73360[lolo.i][lolo.j].fWidth = D_00E73360[lolo.i][lolo.j].fHeight = 34.0f;

			D_00E737C0[lolo.i][lolo.j].dwRenderId = 0x0b;
			D_00E737C0[lolo.i][lolo.j].f_04.c.r =
			D_00E737C0[lolo.i][lolo.j].f_04.c.g =
			D_00E737C0[lolo.i][lolo.j].f_04.c.b = 0x80;
			D_00E737C0[lolo.i][lolo.j].wU = lolo.i * 34;
			D_00E737C0[lolo.i][lolo.j].wV = lolo.j * 34 + 17;
			D_00E737C0[lolo.i][lolo.j].fU = (float)D_00E737C0[lolo.i][lolo.j].wU / 256.0f;
			D_00E737C0[lolo.i][lolo.j].fV = (float)D_00E737C0[lolo.i][lolo.j].wV / 128.0f;
			D_00E737C0[lolo.i][lolo.j].fZ = 0.9444f;
			D_00E737C0[lolo.i][lolo.j].dwPalette = 0;
			D_00E737C0[lolo.i][lolo.j].dwWidth = D_00E737C0[lolo.i][lolo.j].dwHeight = 34;
			D_00E737C0[lolo.i][lolo.j].fTexWidth = 0.13f;
			D_00E737C0[lolo.i][lolo.j].fTexHeight = 0.27f;
			D_00E737C0[lolo.i][lolo.j].fWidth = D_00E737C0[lolo.i][lolo.j].fHeight = 34.0f;

			D_00E72F00[lolo.i][lolo.j].dwRenderId = 0x09;
			D_00E72F00[lolo.i][lolo.j].f_04.c.r =
			D_00E72F00[lolo.i][lolo.j].f_04.c.g =
			D_00E72F00[lolo.i][lolo.j].f_04.c.b = 0x80;
			D_00E72F00[lolo.i][lolo.j].wU = 0;
			D_00E72F00[lolo.i][lolo.j].wV = 0;
			D_00E72F00[lolo.i][lolo.j].fU = 0;
			D_00E72F00[lolo.i][lolo.j].fV = 0;
			D_00E72F00[lolo.i][lolo.j].fZ = 0.9333f;
			D_00E72F00[lolo.i][lolo.j].dwPalette = 0;
			D_00E72F00[lolo.i][lolo.j].dwWidth = D_00E72F00[lolo.i][lolo.j].dwHeight = 34;
			D_00E72F00[lolo.i][lolo.j].fTexWidth = 0.53f;
			D_00E72F00[lolo.i][lolo.j].fTexHeight = 0.27f;
			D_00E72F00[lolo.i][lolo.j].fWidth = D_00E72F00[lolo.i][lolo.j].fHeight = 34.0f;
		}//end for
	}//end for
	D_00E72EF8 = &D_00DBFD38.dwGIL;
	D_00E71624 = 0;
}

//refresh "bet grid"?
void C_00777DF4(int dwIsBetMenu/*bp08*/) {
	struct {
		int j;//bp_08
		int i;//bp_04
	}lolo;

	for(lolo.j = 0; lolo.j < 3; lolo.j ++) {
		for(lolo.i = 0; lolo.i < 5; lolo.i ++) {
			switch(D_00E71068[lolo.i][lolo.j].bFlipAction) {
				case -1: break;
				case 1://flip
					switch(D_00E71068[lolo.i][lolo.j].wState) {
						case 0:
							D_00E71068[lolo.i][lolo.j].bCounter = 0;
							D_00E71068[lolo.i][lolo.j].wState = 4;
						break;
						case 1:
							D_00E71068[lolo.i][lolo.j].bFlipAction = -1;
						break;
						case 2:
							D_00E71068[lolo.i][lolo.j].bCounter = 16;
							D_00E71068[lolo.i][lolo.j].wState = 5;
						break;
						case 3:
							D_00E71068[lolo.i][lolo.j].wState = 4;
						break;
						case 6:
							D_00E71068[lolo.i][lolo.j].wState = 5;
						break;
					}//end switch
				break;
				case 2://flip back
					switch(D_00E71068[lolo.i][lolo.j].wState) {
						case 0:
							D_00E71068[lolo.i][lolo.j].bCounter = 0;
							D_00E71068[lolo.i][lolo.j].wState = 6;
						break;
						case 1:
							D_00E71068[lolo.i][lolo.j].bCounter = 16;
							D_00E71068[lolo.i][lolo.j].wState = 3;
						break;
						case 2:
							D_00E71068[lolo.i][lolo.j].bFlipAction = -1;
						break;
						case 4:
							D_00E71068[lolo.i][lolo.j].wState = 3;
						break;
						case 5:
							D_00E71068[lolo.i][lolo.j].wState = 6;
						break;
					}//end switch
				break;
			}//end switch
			switch(D_00E71068[lolo.i][lolo.j].wState) {
				case 3:
					D_00E71068[lolo.i][lolo.j].bCurrentSide = 0;
					D_00E71068[lolo.i][lolo.j].bCounter -= 2;
					if(D_00E71068[lolo.i][lolo.j].bCounter <= 0)
						D_00E71068[lolo.i][lolo.j].wState = 0;
				break;
				case 4:
					D_00E71068[lolo.i][lolo.j].bCurrentSide = 0;
					D_00E71068[lolo.i][lolo.j].bCounter += 2;
					if(D_00E71068[lolo.i][lolo.j].bCounter >= 16)
						D_00E71068[lolo.i][lolo.j].wState = 1;
				break;
				case 5:
					D_00E71068[lolo.i][lolo.j].bCurrentSide = -1;
					D_00E71068[lolo.i][lolo.j].bCounter -= 2;
					if(D_00E71068[lolo.i][lolo.j].bCounter <= 0)
						D_00E71068[lolo.i][lolo.j].wState = 0;
				break;
				case 6:
					D_00E71068[lolo.i][lolo.j].bCurrentSide = -1;
					D_00E71068[lolo.i][lolo.j].bCounter += 2;
					if(D_00E71068[lolo.i][lolo.j].bCounter >= 16)
						D_00E71068[lolo.i][lolo.j].wState = 2;
				break;
			}//end switch
			D_00E73360[lolo.i][lolo.j].wX0 = 
			D_00E73360[lolo.i][lolo.j].wX2 = lolo.i * 34 + 23 - (D_00E71068[lolo.i][lolo.j].bCounter * 16) / 16;
			D_00E73360[lolo.i][lolo.j].wX1 = 
			D_00E73360[lolo.i][lolo.j].wX3 = lolo.i * 34 + 23 + (D_00E71068[lolo.i][lolo.j].bCounter * 16) / 16;
			if(D_00E71128 && dwIsBetMenu) {//else 007782A0
				//force flip all cells/tiles with chocobo 1
				if(D_0097B470[lolo.j * 5 + lolo.i][0] == 0 || D_0097B470[lolo.j * 5 + lolo.i][1] == 0)
					D_00E71068[lolo.i][lolo.j].bFlipAction = 1;//flip
				//goto 00778393
			} else if(lolo.i == D_00E737B8 && lolo.j == D_00E737B4 && D_00E737A4) {//else 0077834E
				//"cursor" blink
				D_00E73360[lolo.i][lolo.j].f_04.c.r =
				D_00E73360[lolo.i][lolo.j].f_04.c.b =
				D_00E73360[lolo.i][lolo.j].f_04.c.g = (D_00E72EF0 & 8)?0xb0:0x50;
			} else {
				//normal
				D_00E73360[lolo.i][lolo.j].f_04.c.r =
				D_00E73360[lolo.i][lolo.j].f_04.c.g =
				D_00E73360[lolo.i][lolo.j].f_04.c.b = 0x80;
			}
			if(D_00E71068[lolo.i][lolo.j].bCurrentSide == 0) {//else 007784BF
				D_00E73360[lolo.i][lolo.j].dwRenderId = 0x05;
				D_00E73360[lolo.i][lolo.j].wY0 = lolo.j * 34 + 41 - D_00E71068[lolo.i][lolo.j].bCounter / 4 + 4;
				D_00E73360[lolo.i][lolo.j].wY1 = lolo.j * 34 + 37 + D_00E71068[lolo.i][lolo.j].bCounter / 4;
				D_00E73360[lolo.i][lolo.j].wY2 = lolo.j * 34 + 71 + D_00E71068[lolo.i][lolo.j].bCounter / 4;
				D_00E73360[lolo.i][lolo.j].wY3 = lolo.j * 34 + 75 - D_00E71068[lolo.i][lolo.j].bCounter / 4 + 4;
				//goto 007785CD
			} else {
				D_00E73360[lolo.i][lolo.j].dwRenderId = 0x04;
				D_00E73360[lolo.i][lolo.j].wY0 = lolo.j * 34 + 37 + D_00E71068[lolo.i][lolo.j].bCounter / 4;
				D_00E73360[lolo.i][lolo.j].wY1 = lolo.j * 34 + 41 - D_00E71068[lolo.i][lolo.j].bCounter / 4 + 4;
				D_00E73360[lolo.i][lolo.j].wY2 = lolo.j * 34 + 75 - D_00E71068[lolo.i][lolo.j].bCounter / 4 + 4;
				D_00E73360[lolo.i][lolo.j].wY3 = lolo.j * 34 + 71 + D_00E71068[lolo.i][lolo.j].bCounter / 4;
			}
			D_00E737C0[lolo.i][lolo.j].wX0 = D_00E73360[lolo.i][lolo.j].wX0;
			D_00E737C0[lolo.i][lolo.j].wX1 = D_00E73360[lolo.i][lolo.j].wX1;
			D_00E737C0[lolo.i][lolo.j].wX2 = D_00E73360[lolo.i][lolo.j].wX2;
			D_00E737C0[lolo.i][lolo.j].wX3 = D_00E73360[lolo.i][lolo.j].wX3;
			D_00E737C0[lolo.i][lolo.j].wY0 = D_00E73360[lolo.i][lolo.j].wY0;
			D_00E737C0[lolo.i][lolo.j].wY1 = D_00E73360[lolo.i][lolo.j].wY1;
			D_00E737C0[lolo.i][lolo.j].wY2 = D_00E73360[lolo.i][lolo.j].wY2;
			D_00E737C0[lolo.i][lolo.j].wY3 = D_00E73360[lolo.i][lolo.j].wY3;

			C_0077A89F(&(D_00E73360[lolo.i][lolo.j]));//chocobo:draw sprite[bet square]
			//-- patch for SW --
			if(D_00E3BA68.dwSWRenderer)
				C_0077AC35(&(D_00E73360[lolo.i][lolo.j]));//chocobo:[for sw patch]
			//-- --
			C_0077A89F(&(D_00E737C0[lolo.i][lolo.j]));//chocobo:draw sprite[bet square]
			//-- --
			if(D_00E71068[lolo.i][lolo.j].bDisplayPrize) {//else 007789E9
				D_00E72F00[lolo.i][lolo.j].wX0 = D_00E73360[lolo.i][lolo.j].wX0;
				D_00E72F00[lolo.i][lolo.j].wX1 = D_00E73360[lolo.i][lolo.j].wX1;
				D_00E72F00[lolo.i][lolo.j].wX2 = D_00E73360[lolo.i][lolo.j].wX2;
				D_00E72F00[lolo.i][lolo.j].wX3 = D_00E73360[lolo.i][lolo.j].wX3;
				D_00E72F00[lolo.i][lolo.j].wY0 = D_00E73360[lolo.i][lolo.j].wY0;
				D_00E72F00[lolo.i][lolo.j].wY1 = D_00E73360[lolo.i][lolo.j].wY1;
				D_00E72F00[lolo.i][lolo.j].wY2 = D_00E73360[lolo.i][lolo.j].wY2;
				D_00E72F00[lolo.i][lolo.j].wY3 = D_00E73360[lolo.i][lolo.j].wY3;
				D_00E72F00[lolo.i][lolo.j].wV = D_00E71068[lolo.i][lolo.j].bPrizeIndex * 34;
				switch(D_00E71068[lolo.i][lolo.j].bPrizeIndex) {
					case 1: D_00E72F00[lolo.i][lolo.j].fV = 0.27f; break;//ROUND(34.0f/128.0f)
					case 2: D_00E72F00[lolo.i][lolo.j].fV = 0.53f; break;//ROUND((2.0f * 34.0f)/128.0f)
					default:
						D_00E72F00[lolo.i][lolo.j].fV = 0;
				}//end switch
				C_0077A89F(&(D_00E72F00[lolo.i][lolo.j]));//chocobo:draw sprite[bet square]
			}
		}//end for
	}//end for
}

//chocobo:before "bet results"
void C_00778A3C() {
	unsigned short i;

	D_00E737A4 = -1;
	D_00E737B0 = 0;
	//-- --
	D_00E71664->wOpCode = SOUND_OP_C1;//volume trans(music)
	D_00E71664->f_04[0] = 30;
	D_00E71664->f_04[1] = 30;
	C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);
	//-- --
	C_0076BA66();//ch_init:reset snd channels?
	//-- for fade --
	D_00E715D4 = -0x10;
	D_00E710EC = 0xff;
	//-- ?? --
	D_00E73C04 = 0;
	//-- --
	D_00E71664->wOpCode = SOUND_OP_10;//"MUSIC"
	D_00E71664->f_04[0] = 0;
	C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);
	//-- --
	for(i = 0; i < 6; i ++) {
		if(D_00E71158[i].wPosition == 1)
			D_00E73338 = D_00E72EF4 = i;
		if(D_00E71158[i].wPosition == 2)
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

//chocobo:refresh "bet results"
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

	D_00E71108 = 0;//reset "# polygons rendered"
	C_00777DF4(0);//refresh "bet grid"?
	//-- chocobos list in ranking order --
	for(lolo.i_0 = 0; lolo.i_0 < 6; lolo.i_0 ++) {
		for(lolo.j_0 = 0; lolo.j_0 < 6; lolo.j_0 ++) {
			if(D_00E71158[lolo.j_0].wPosition == lolo.i_0 + 1) {//else 00778E4A
				C_0077941B(D_00E71158[lolo.j_0].aName, 7, 220, D_0097A4E0[lolo.i_0]);//draw string?
				D_0097B650[D_00E71158[lolo.j_0].wJockeyId].wX0 =
				D_0097B650[D_00E71158[lolo.j_0].wJockeyId].wX2 = 298;
				D_0097B650[D_00E71158[lolo.j_0].wJockeyId].wX1 =
				D_0097B650[D_00E71158[lolo.j_0].wJockeyId].wX3 = 298 + 16;
				D_0097B650[D_00E71158[lolo.j_0].wJockeyId].wY0 = 
				D_0097B650[D_00E71158[lolo.j_0].wJockeyId].wY2 = D_0097A4E0[lolo.i_0];
				D_0097B650[D_00E71158[lolo.j_0].wJockeyId].wY1 =
				D_0097B650[D_00E71158[lolo.j_0].wJockeyId].wY3 = D_0097A4E0[lolo.i_0] + 16;
				C_0077A469(&(D_0097B650[D_00E71158[lolo.j_0].wJockeyId]));//chocobo:draw sprite[UI]
				D_00E71108 ++;
			}
		}//end for
	}//end for
	//-- drum roll SFX --
	if(D_00E737B0 == 10) {
		D_00E71664->wOpCode = SOUND_OP_28;//play SFX[ch 1]
		D_00E71664->f_04[0] = 0x40;
		D_00E71664->f_04[1] = 0x084;
		C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);
	}
	//-- --
	if(D_00E737B0 == 10) {
		for(lolo.j_1 = 0; lolo.j_1 < 3; lolo.j_1 ++) {
			for(lolo.i_1 = 0; lolo.i_1 < 5; lolo.i_1 ++)
				D_00E71068[lolo.i_1][lolo.j_1].bFlipAction = D_00E71068[lolo.i_1][lolo.j_1].bCurrentSide?1:2;
		}//end for
	}
	if(D_00E737B0 == 30 && D_00E71128 && D_00E73338 != D_00E71158[0].wJockeyId) {
		for(lolo.j_2 = 0; lolo.j_2 < 3; lolo.j_2 ++) {
			for(lolo.i_2 = 0; lolo.i_2 < 5; lolo.i_2 ++)
				D_00E71068[lolo.i_2][lolo.j_2].bFlipAction = 1;//flip
		}//end for
	}
	if(D_00E737B0 == 110) {
		for(lolo.j_3 = 0; lolo.j_3 < 3; lolo.j_3 ++) {
			for(lolo.i_3 = 0; lolo.i_3 < 5; lolo.i_3 ++)
				D_00E71068[lolo.i_3][lolo.j_3].bFlipAction = D_00E71068[lolo.i_3][lolo.j_3].bCurrentSide?1:2;
		}//end for
	}
	if(D_00E737B0 == 115) {
		for(lolo.j_4 = 0; lolo.j_4 < 3; lolo.j_4 ++) {
			for(lolo.i_4 = 0; lolo.i_4 < 5; lolo.i_4 ++)
				D_00E71068[lolo.i_4][lolo.j_4].bDisplayPrize = -1;
		}//end for
		//-- set won prize in save file --
		if(D_00E71068[D_00E737B8][D_00E737B4].bCurrentSide)
			D_00DC0AF8 = D_0097BB60[D_00E71068[D_00E737B8][D_00E737B4].bPrizeId];
		//-- set player's ranking in save file --
		D_00DC0AF5 = D_00E71158[0].wPosition - 1;
	}
	//-- --
	D_00E737B0 ++;
	D_00E71018 ++;
	D_00E72EF0 += 2;
	//-- manage input --
	C_0076E149();//chocobo:input.compute_mask
	if(D_00E71620 != D_00E71100) {
		if(
			(D_00E71620 & (
				BIT(CH_KEY_START)|
				BIT(CH_KEY_SWITCH)|
				BIT(CH_KEY_CANCEL)|
				BIT(CH_KEY_OK)|
				BIT(CH_KEY_MENU)
			)) && D_00E737B0 >= 160
		)
			D_00E715D4 = 0x10;//start fade
	}
	//-- fade over->end game --
	if(D_00E710EC > 0xff && D_00E715D4 > 0) {
		D_00E715D4 = 0;

		D_00E71664->wOpCode = SOUND_OP_C1;//volume trans(music)
		D_00E71664->f_04[0] = 30;
		D_00E71664->f_04[1] = 30;
		C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);

		D_00E3B740 = 6;//"transition to end"
	}
	//-- --
	if(D_00E3B740 == 5) {//else 007792C9
		//"bet results
		//-- bg --
		C_0077A3A2(&D_0097B4E8);//chocobo:draw quad[background]
		C_0077A3A2(&D_0097B530);//chocobo:draw quad[background]
		//-- frame elements --
		for(lolo.i_0 = 0; lolo.i_0 < 9; lolo.i_0 ++) {
			C_0077A469(&(D_00E3BA9C[3][lolo.i_0]));//chocobo:draw sprite[UI]
			D_00E71108 ++;
		}//end for
		//-- text elements --
		for(lolo.i_0 = 0; lolo.i_0 < 0xb; lolo.i_0 ++) {
			C_0077A469(&(D_00E3BA9C[1][lolo.i_0]));//chocobo:draw sprite[UI]
			D_00E71108 ++;
		}//end for
		//-- 1st and 2nd chocobos(big digits) --
		D_00E3BA9C[5][D_00E72EF4].wX0 = 213;
		D_00E3BA9C[5][D_00E72EF4].wY0 = 10;
		C_0077A469(&(D_00E3BA9C[5][D_00E72EF4]));//chocobo:draw sprite[UI]
		D_00E71108 ++;

		D_00E3BA9C[5][D_00E737BC].wX0 = 243;
		D_00E3BA9C[5][D_00E737BC].wY0 = 10;
		C_0077A469(&(D_00E3BA9C[5][D_00E737BC]));//chocobo:draw sprite[UI]
		D_00E71108 ++;
		//-- ? --
		D_00E71108 ++;
		//-- --
		C_007792CD();//display prizes
		//-- --
		C_0077946A();//chocobo:refresh fade in/out
		C_0077B2CA();//chocobo:renderer?
	}
}

//display prizes
void C_007792CD() {
	int i;//local_1

	C_0077941B(D_0097C9D0[D_00E73340[0]], 0xe, 37, 172);//draw string?
	C_0077941B(D_0097C9D0[D_00E73340[1]], 0xe, 37, 192);//draw string?
	C_0077941B(D_0097C9D0[D_00E73340[2]], 0xe, 37, 212);//draw string?
	for(i = 0; i < 3; i ++) {
		D_0097BBC0[i].wX0 =
		D_0097BBC0[i].wX2 = 15;
		D_0097BBC0[i].wY0 =
		D_0097BBC0[i].wY1 = i * 21 + 169;
		D_0097BBC0[i].wX1 =
		D_0097BBC0[i].wX3 = 15 + 16;
		D_0097BBC0[i].wY2 =
		D_0097BBC0[i].wY3 = i * 21 + 169 + 16;
		C_0077A469(&(D_0097BBC0[i]));//chocobo:draw sprite[UI]
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

//chocobo:refresh fade in/out
void C_0077946A() {
	if(D_00E710EC) {
		D_0097A498.f_04.c.r =
		D_0097A498.f_04.c.g =
		D_0097A498.f_04.c.b = D_00E710EC;
		C_0077B1CE(&D_0097A498);//chocobo:draw quad[for fade in/out]
	}
	D_00E710EC += D_00E715D4;
	if(D_00E710EC < 0) {
		D_00E710EC = 0;
		D_00E715D4 = 0;
	} else if(D_00E710EC > 0x100) {
		D_00E710EC = 0x100;
	}
}

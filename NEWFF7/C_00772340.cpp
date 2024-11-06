/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- motions?

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
extern int D_0096EBC0[];//frames count per animation?
extern short D_0097A3E0[][4];
extern unsigned char D_0097C8A8[];
extern unsigned char D_0097CC58[][7];//chocobo names
////////////////////////////////////////
#define CHOCOBO_TYPE_0 0
#define CHOCOBO_TYPE_1 1
#define CHOCOBO_TYPE_2 2
#define CHOCOBO_TYPE_3 3
#define CHOCOBO_TYPE_MAX 4

#define MK_TRACK_POS(v,path_t,r_left,r_right) { \
	(v).vx = (D_00E715FC[path_t].sVect_Left.vx * r_left + D_00E715FC[path_t].sVect_Right.vx * r_right) / 256; \
	(v).vy = (D_00E715FC[path_t].sVect_Left.vy * r_left + D_00E715FC[path_t].sVect_Right.vy * r_right) / 256; \
	(v).vz = (D_00E715FC[path_t].sVect_Left.vz * r_left + D_00E715FC[path_t].sVect_Right.vz * r_right) / 256; \
}

#define S_MK_TRACK_POS(v,path_t,r_left,r_right) { \
	(v).vx = (D_00E715FC[path_t].sVect_Left.vx * r_left + D_00E715FC[path_t].sVect_Right.vx * r_right) / 256; \
	(v).vy = (D_00E715FC[path_t].sVect_Left.vy * r_left + D_00E715FC[path_t].sVect_Right.vy * r_right) / 256; \
	(v).vz = (D_00E715FC[path_t].sVect_Left.vz * r_left + D_00E715FC[path_t].sVect_Right.vz * r_right) / 256; \
}
////////////////////////////////////////
extern int D_00E71000[/*6*/];//chocobo signed distance from camera
extern int D_00E7101C;
extern int D_00E71020[/*6*/];//"visible chocobo" flags
extern int D_00E71038;
extern int D_00E710E0;
extern int D_00E710E4;
extern int D_00E710E8;//flag:set, never read
extern int D_00E710F8;
extern int D_00E71134;//first chocobo
extern struct t_chocobo_ChocoboInfo D_00E71158[/*7*/];
extern int D_00E715D8;
extern int D_00E715DC;//for camera:target chocobo
extern struct t_chocobo_data_TrackElement *D_00E715FC;
////////////////////////////////////////
int D_00E72EEC;//last chocobo
////////////////////////////////////////
//chocobo:get track's "last sprint" point?
int C_00772340(int bp08/*long/short race*/) {
	if(bp08 == 0)
		return 0x3de;
	else
		return 0x320;
}

void C_00773487(int, int, int);//set some special (dis)abilities

//chocobo:init 6 chocobos info?
void C_00772357() {
	struct {
		struct t_chocobo_Model3D *pModel;//bp_134
		char _p_130[0xc];
		int j;//bp_124
		char _p_120[8];
		unsigned char *bp_118;
		char _p_114[4];
		struct SVECTOR sPos_next;//bp_110
		struct SVECTOR sPos_cur;//bp_108
		int dwTemp_0;//bp_100
		int bp_fc;
		int bp_f8;
		int bp_f4;
		int dwTemp_1;//bp_f0
		int bp_ec;
		DECL_short(i);//bp_e8
		int bp_e4;
		int bp_e0;
		struct t_chocobo_ChocoboInfo *pChocobo;//bp_dc
		struct VECTOR bp_d8;
		struct t_aa0 *bp_c8;
		int bp_c4[45];
		struct fBGRA bp_10;
	}lolo;

	lolo.bp_c8 = C_00676578();
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		lolo.pChocobo = &(D_00E71158[lolo.i]);
		lolo.pChocobo->f_7c = (lolo.i * 224) / 6 + 16;
	}//end for
	for(lolo.i = 0; lolo.i < 40; lolo.i ++) {
		lolo.bp_f8 = rand() % 6;
		lolo.bp_fc = rand() % 6;
		SWAP(D_00E71158[lolo.bp_f8].f_7c, D_00E71158[lolo.bp_fc].f_7c, lolo.dwTemp_0);
	}//end for
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		lolo.pChocobo = &(D_00E71158[lolo.i]);
		if(D_00E71128 && lolo.i == 0) {//else 00772657
			lolo.pChocobo->wTopSpeed = D_00DC0AE6 + (D_00DC0AE7 << 8);
			lolo.pChocobo->f_56 = D_00DC0AE8 + (D_00DC0AE9 << 8);
			lolo.pChocobo->f_5e = D_00DC0AEA;
			lolo.pChocobo->f_62 = D_00DC0AEB;
			lolo.pChocobo->wType = rand() % CHOCOBO_TYPE_MAX;
			lolo.pChocobo->dwStamina =
			lolo.pChocobo->dwMaxStamina = D_00DC0AF6 + (D_00DC0AF7 << 8);
			lolo.pChocobo->wIsAutomatic = 1;
			lolo.pChocobo->f_4c = D_00DC0AEE;
			//!!!lolo.pChocobo->f_64 is not set yet!!!
			lolo.pChocobo->f_5c = lolo.pChocobo->f_64 / 10;
			switch(D_00DC0AED) {
				case 1: lolo.pChocobo->wTerrainMask = 1; break;
				case 2: lolo.pChocobo->wTerrainMask = 2; break;
				case 3:
				case 4: lolo.pChocobo->wTerrainMask = 0; break;
				default:
					lolo.pChocobo->wTerrainMask = 1|2;
			}//end switch
			lolo.pChocobo->f_64 = D_00DC0AEC;
			//goto 00772793
		} else {
			lolo.pChocobo->wTopSpeed = D_0097A3E0[D_00DC0AF3][0] + (rand() % D_0097A3E0[D_00DC0AF3][1]);
			lolo.pChocobo->f_56 = D_0097A3E0[D_00DC0AF3][2] + (rand() % D_0097A3E0[D_00DC0AF3][3]);
			lolo.pChocobo->f_5e = 50;
			lolo.pChocobo->f_62 = 100;
			lolo.pChocobo->wType = rand() % CHOCOBO_TYPE_MAX;
			lolo.pChocobo->dwStamina =
			lolo.pChocobo->dwMaxStamina = D_0097A3E0[D_00DC0AF3][0] + (rand() % 300);
			lolo.pChocobo->wIsAutomatic = 1;
			lolo.pChocobo->f_4c = (rand() & 7)?0:2;
			//!!!lolo.pChocobo->f_64 is not set yet!!!
			lolo.pChocobo->f_5c = lolo.pChocobo->f_64 / 10;
			lolo.pChocobo->wTerrainMask = 1|2;
			lolo.pChocobo->f_64 = (rand() & 1) * 50 + 50;
		}
		if(lolo.pChocobo->f_64 < 40) {
			lolo.pChocobo->f_52 = 3;
			lolo.pChocobo->f_66 = (40 - lolo.pChocobo->f_64) / 10;
		} else if(lolo.pChocobo->f_64 < 60) {
			lolo.pChocobo->f_52 = 2;
			lolo.pChocobo->f_66 = (60 - lolo.pChocobo->f_64) / 5;
		} else if(lolo.pChocobo->f_64 < 80) {
			lolo.pChocobo->f_52 = 1;
			lolo.pChocobo->f_66 = (80 - lolo.pChocobo->f_64) / 5;
		} else {
			lolo.pChocobo->f_52 = 0;
			lolo.pChocobo->f_66 = (110 - lolo.pChocobo->f_64) / 5;
		}
		lolo.pChocobo->f_5c = lolo.pChocobo->f_64 / 8;
		lolo.pChocobo->wLastSprint = D_00E7112C->dwLastSprintPoint;
		lolo.pChocobo->wRankPos = lolo.i;
		lolo.pChocobo->wSpeed = lolo.pChocobo->f_56 / 2;
		lolo.pChocobo->f_4e = lolo.pChocobo->f_56;
		lolo.pChocobo->wPathT_cur = 10;
		lolo.pChocobo->wPathT_next = 11;
		lolo.pChocobo->f_84 = 0;
		lolo.pChocobo->f_9a = -1;
		lolo.pChocobo->f_a0 = 0;
		lolo.pChocobo->f_9e = 0;
		lolo.pChocobo->f_9c = 0;
		lolo.pChocobo->f_a2 = 0;
		lolo.bp_f4 = 256 - lolo.pChocobo->f_7c;
		lolo.pChocobo->f_96 = lolo.pChocobo->f_7c;

		S_MK_TRACK_POS(lolo.pChocobo->sPos_cur, lolo.pChocobo->wPathT_cur, lolo.pChocobo->f_7c, lolo.bp_f4);

		lolo.pChocobo->sPos_orig.vx = lolo.pChocobo->sPos_cur.vx;
		lolo.pChocobo->sPos_orig.vy = lolo.pChocobo->sPos_cur.vy;
		lolo.pChocobo->sPos_orig.vz = lolo.pChocobo->sPos_cur.vz;

		S_MK_TRACK_POS(lolo.pChocobo->sPos_next, lolo.pChocobo->wPathT_next, lolo.pChocobo->f_7c, lolo.bp_f4);

		lolo.pChocobo->sRot_cur.vx = 0;
		lolo.pChocobo->sRot_cur.vy = 0;
		lolo.pChocobo->sRot_cur.vz = 0;

		lolo.pChocobo->sRot_next.vx = 0;
		lolo.pChocobo->sRot_next.vy = 0;
		lolo.pChocobo->sRot_next.vz = 0;

		//0x800 and 0x801?!?
		// anyway, this value is overwritten a
		// few lines below.
		lolo.pChocobo->sRot_cur.vy = C_0077CFBF(&(D_00E715FC[0x800].sVect_Left), &(D_00E715FC[0x801].sVect_Left));//chocobo:make dir angle?

		lolo.pChocobo->wPosition = 0;
		lolo.pChocobo->wAnimationCounter = 0;
		lolo.pChocobo->wAnimationCounterIncr = lolo.pChocobo->wSpeed / D_00E7101C;
		lolo.pChocobo->wFinished = 0;
		lolo.pChocobo->wAnimationId = 0;//run

		lolo.bp_d8.vx = lolo.pChocobo->sPos_next.vx - lolo.pChocobo->sPos_cur.vx;
		lolo.bp_d8.vy = lolo.pChocobo->sPos_next.vy - lolo.pChocobo->sPos_cur.vy;
		lolo.bp_d8.vz = lolo.pChocobo->sPos_next.vz - lolo.pChocobo->sPos_cur.vz;
		psx_VectorNormal(&lolo.bp_d8, &lolo.bp_d8);
		lolo.pChocobo->sRot_cur.vy = lolo.pChocobo->sRot_next.vy = C_0077CF40(lolo.bp_d8.vx, lolo.bp_d8.vz);//chocobo:atan2?
	}//end for
	//-- "TEIOH" --
	if(D_00DC0AF2) {//else 00772EA7
		lolo.sPos_cur = D_00E71158[1].sPos_cur;
		lolo.sPos_next = D_00E71158[1].sPos_next;

		D_00E71158[1] = D_00E71158[0];
		D_00E71158[1].sPos_cur = lolo.sPos_cur;
		D_00E71158[1].sPos_orig = lolo.sPos_cur;
		D_00E71158[1].sPos_next = lolo.sPos_next;
		D_00E71158[1].dwMaxStamina += D_00E71158[1].dwMaxStamina / 4;
		D_00E71158[1].dwStamina += D_00E71158[1].dwStamina / 4;
		D_00E71158[1].f_56 += D_00E71158[1].f_56 / 10;
		D_00E71158[1].wTopSpeed += D_00E71158[1].wTopSpeed / 10;
		D_00E71158[1].f_5e = 100;
		D_00E71158[1].f_64 = 100;
		D_00E71158[1].wChocoboId = 2;//twice?
		D_00E71158[1].wType = CHOCOBO_TYPE_3;
		D_00E71158[1].wTerrainMask = 0;
		D_00E71158[1].wChocoboId = 9;//twice?
		D_00E71158[1].wJockeyId = 1;
	}
	//-- chocobos'names/abilities --
	for(lolo.bp_e4 = 0; lolo.bp_e4 < 45; lolo.bp_e4 ++)
		lolo.bp_c4[lolo.bp_e4] = lolo.bp_e4;
	for(lolo.bp_e4 = 0; lolo.bp_e4 < 200; lolo.bp_e4 ++) {
		lolo.bp_ec = rand() % 45;
		lolo.bp_e0 = rand() % 45;
		SWAP(lolo.bp_c4[lolo.bp_ec], lolo.bp_c4[lolo.bp_e0], lolo.dwTemp_1);
	}//end for
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		if(D_00DC0AF2 && lolo.i == 1) {//else 00773008
			//-- "TEIOH" --
			for(lolo.j = 0; lolo.j < 8; lolo.j ++)
				D_00E71158[lolo.i].aName[lolo.j] = D_0097C8A8[lolo.j];
			//goto 007730BE
		} else {
			lolo.bp_118 = D_0097CC58[lolo.bp_c4[lolo.i]];
			for(lolo.j = 0; lolo.j < 6; lolo.j ++) {
				D_00E71158[lolo.i].aName[lolo.j] = *lolo.bp_118;
				lolo.bp_118 ++;
			}//end for
			D_00E71158[lolo.i].aName[lolo.j] = 0xff;
			//-- special (dis)abilities --
			if(D_00E71128 && lolo.i != 0)
				C_00773487(lolo.i, 0, 0);//set some special (dis)abilities
			//-- --
		}
	}//end for
	//-- player's chocobo's name --
	if(D_00E71128) {
		struct tDummyName { char name[6]; };//size 6
		*(struct tDummyName *)D_00E71158[0].aName = *(struct tDummyName *)D_00DC0ADC;
		D_00E71158[0].aName[6] = 0xff;
	}
	//-- models color --
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		lolo.pChocobo = &(D_00E71158[lolo.i]);
		lolo.pModel = &(D_00E719E8[lolo.pChocobo->wChocoboId]);
		//-- "TEIOH" --
		if(D_00DC0AF2 && lolo.i == 1)
			continue;
		//-- player --
		if(D_00E71128 && lolo.i == 0)
			continue;
		//-- set model color --
		switch(lolo.pChocobo->wType) {
			case CHOCOBO_TYPE_0://black?
				lolo.pModel->bR =
				lolo.pModel->bG =
				lolo.pModel->bB = 0;
				lolo.bp_10.r = (float)lolo.pModel->bR / 256.0f;
				lolo.bp_10.g = (float)lolo.pModel->bG / 256.0f;
				lolo.bp_10.b = (float)lolo.pModel->bB / 256.0f;
				lolo.bp_10.a = 1.0f;
				C_00684E20(&lolo.bp_10, lolo.pModel->pHRC->f_b4, lolo.bp_c8);//anm: apply add color to skeleton?
			break;
			case CHOCOBO_TYPE_1://green
				lolo.pModel->bR = 0x40;
				lolo.pModel->bG = 0x40;
				lolo.pModel->bB = 0;
				lolo.bp_10.r = (float)lolo.pModel->bR / 256.0f;
				lolo.bp_10.g = (float)lolo.pModel->bG / 256.0f;
				lolo.bp_10.b = (float)lolo.pModel->bB / 256.0f;
				lolo.bp_10.a = 1.0f;
				C_00684E20(&lolo.bp_10, lolo.pModel->pHRC->f_b4, lolo.bp_c8);//anm: apply add color to skeleton?
			break;
			case CHOCOBO_TYPE_2://brown?
				lolo.pModel->bR = 0x40;
				lolo.pModel->bG = 0x10;
				lolo.pModel->bB = 0;
				lolo.bp_10.r = (float)lolo.pModel->bR / 256.0f;
				lolo.bp_10.g = (float)lolo.pModel->bG / 256.0f;
				lolo.bp_10.b = (float)lolo.pModel->bB / 256.0f;
				lolo.bp_10.a = 1.0f;
				C_00684E20(&lolo.bp_10, lolo.pModel->pHRC->f_b4, lolo.bp_c8);//anm: apply add color to skeleton?
			break;
			case CHOCOBO_TYPE_3://dark blue?
				lolo.pModel->bR = 0;
				lolo.pModel->bG = 0x10;
				lolo.pModel->bB = 0x40;
				lolo.bp_10.r = (float)lolo.pModel->bR / 256.0f;
				lolo.bp_10.g = (float)lolo.pModel->bG / 256.0f;
				lolo.bp_10.b = (float)lolo.pModel->bB / 256.0f;
				lolo.bp_10.a = 1.0f;
				C_00684E20(&lolo.bp_10, lolo.pModel->pHRC->f_b4, lolo.bp_c8);//anm: apply add color to skeleton?
			break;
		}//end switch
		//-- --
	}//end for
}

void C_007734AC(int, int);//set some special (dis)ability

//set some special (dis)abilities
void C_00773487(int bp08, int bp0c, int bp10) {
	C_007734AC(bp08, bp0c);//set some special (dis)ability
	C_007734AC(bp08, bp10);//set some special (dis)ability
}

//set some special (dis)ability
void C_007734AC(int bp08, int bp0c) {
	struct t_chocobo_ChocoboInfo *pChocobo;

	pChocobo = &(D_00E71158[bp08]);
	switch(bp0c) {
		case 1:
			pChocobo->wLastSprint = D_00E7112C->dwLastSprintPoint + 20;
		break;
		case 2:
			pChocobo->dwMaxStamina += (pChocobo->dwMaxStamina * 4) / 3;
			pChocobo->dwStamina = pChocobo->dwMaxStamina;
		break;
		case 3:
			pChocobo->wLastSprint = D_00E7112C->dwLastSprintPoint - 20;
		break;
		case 4:
			pChocobo->f_4c = 2;
		break;
		case 5:
			pChocobo->f_9a = 0;
		break;
		case 6:
			pChocobo->f_64 = 100;
			pChocobo->f_52 = 0;
			pChocobo->wType = CHOCOBO_TYPE_3;
		break;
		case 7:
			pChocobo->f_9c = -1;
		break;
		case 8:
			pChocobo->dwMaxStamina /= 2;
			pChocobo->dwStamina = pChocobo->dwMaxStamina;
		break;
		case 9:
			pChocobo->wTerrainMask &= 2;
		break;
		case 10:
			pChocobo->wTerrainMask &= 1;
		break;
		case 11:
			pChocobo->f_a0 = -1;
			if(rand() & 1)
				pChocobo->dwMaxStamina /= 2;
		break;
		case 12:
			pChocobo->f_a2 = -1;
		break;
		case 13:
			pChocobo->f_52 = 3;
		break;
	}//end switch
}

void C_007737B4(short);//update 1 chococo info?
void C_00775A45(int);//move tracker?

//chocobo:refresh 6 chocobos info?
void C_00773668() {
	struct {
		int dwTemp;//bp_3c
		int aPathT[6];//bp_38
		int j;//bp_20
		int i;//bp_1c
		int aChocobo[6];//bp_18
	}lolo;

	//-- chocobos position --
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		lolo.aPathT[lolo.i] = D_00E71158[lolo.i].wPathT_cur;
		lolo.aChocobo[lolo.i] = lolo.i;
	}//end for
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		for(lolo.j = lolo.i; lolo.j < 6; lolo.j ++) {
			if(lolo.aPathT[lolo.i] < lolo.aPathT[lolo.j]) {
				SWAP(lolo.aPathT[lolo.i], lolo.aPathT[lolo.j], lolo.dwTemp);
				SWAP(lolo.aChocobo[lolo.i], lolo.aChocobo[lolo.j], lolo.dwTemp);
			}
		}//end for
	}//end for
	for(lolo.i = 0; lolo.i < 6; lolo.i ++)
		D_00E71158[lolo.aChocobo[lolo.i]].wRankPos = lolo.i;
	//-- last chocobo --
	D_00E72EEC = lolo.aChocobo[5];
	//-- --
	for(lolo.i = 0; lolo.i < 6; lolo.i ++)
		C_007737B4(lolo.i);//update 1 chococo info?
	//-- camera --
	if(D_00E71128)
		C_00775A45(1);//move tracker?
	else
		C_00775A45(0);//move tracker?
}

void C_00773DD8(short);//move 1 chocobo?

//update 1 chococo info?
void C_007737B4(short bp08) {
	struct {
		int dwVolume;//local_20
		int dwInvSpeed_2;//local_19
		int dwAngle;//local_18
		struct VECTOR local_17;
		struct t_chocobo_ChocoboInfo *pChocobo_2;//local_13
		int dwInvSpeed_1;//local_12
		struct t_chocobo_Model3D *pModelC;//local_11
		struct SVECTOR local_10;
		int dwDiffZ;//local_8
		struct t_chocobo_Model3D *pModelJ;//local_7
		int i;//local_6
		int dwDiffX;//local_5
		int dwDistance;//local_4
		int local_3;
		struct t_chocobo_ChocoboInfo *pChocobo_1;//local_2
		int local_1;
	}lolo;

	lolo.pChocobo_1 = &(D_00E71158[bp08]);
	if(D_00E710F8 == 0) {
		//init/start?
		lolo.pChocobo_1->wAnimationId = 3;//draw
		lolo.pChocobo_1->wAnimationCounterIncr = 0x100;
		lolo.pChocobo_1->wSpeed = 10;
	} else if(lolo.pChocobo_1->wSpeed) {
		C_00773DD8(bp08);//move 1 chocobo?
		lolo.pChocobo_1->wAnimationCounterIncr = lolo.pChocobo_1->wSpeed / D_00E7101C;
		//goto 007738DD
	} else {
		//finish line?
		D_00E710E0 ++;
		if(D_00DC0AF2 && lolo.pChocobo_1->wJockeyId == 1) {
			//-- "TEIOH" --
			switch(lolo.pChocobo_1->wPosition) {
				case 1: lolo.pChocobo_1->wAnimationId = 2; break;//win
				case 2: lolo.pChocobo_1->wAnimationId = 3; break;//draw
				default:
					lolo.pChocobo_1->wAnimationId = 4;//lose
			}//end switch
			//goto 007738D4
		} else {
			switch(lolo.pChocobo_1->wPosition) {
				case 1: lolo.pChocobo_1->wAnimationId = 2; break;//win
				case 6: lolo.pChocobo_1->wAnimationId = 4; break;//lose
				default:
					lolo.pChocobo_1->wAnimationId = 3;//draw
			}//end switch
		}
		lolo.pChocobo_1->wAnimationCounterIncr = 0x100;
	}
	lolo.pChocobo_1->wAnimationCounter += lolo.pChocobo_1->wAnimationCounterIncr;
	lolo.pChocobo_1->f_74 += lolo.pChocobo_1->wAnimationCounterIncr;
	lolo.pModelJ = &(D_00E719E8[lolo.pChocobo_1->wJockeyId]);
	lolo.pModelC = &(D_00E719E8[lolo.pChocobo_1->wChocoboId]);
	if((lolo.pChocobo_1->wAnimationCounter >> 8) >= D_0096EBC0[lolo.pChocobo_1->wAnimationId]) {
		if(lolo.pChocobo_1->wPrevAnimationId != lolo.pChocobo_1->wAnimationId) {
			lolo.pChocobo_1->wPrevAnimationId = lolo.pChocobo_1->wAnimationId;
			lolo.pChocobo_1->wAnimationCounter = 0;
		} else {
			lolo.pChocobo_1->wAnimationCounter &= 0xff;
		}
	}
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		if(lolo.i == bp08)
			continue;
		lolo.pChocobo_2 = &(D_00E71158[lolo.i]);
		lolo.dwDiffX = lolo.pChocobo_1->sPos_cur.vx - lolo.pChocobo_2->sPos_cur.vx;
		lolo.dwDiffZ = lolo.pChocobo_1->sPos_cur.vz - lolo.pChocobo_2->sPos_cur.vz;
		lolo.dwDiffX = psx_SquareRoot0(lolo.dwDiffX * lolo.dwDiffX + lolo.dwDiffZ * lolo.dwDiffZ);
		if(lolo.dwDiffX < 150) {//else 00773C8E
			if(lolo.pChocobo_2->wFinished) {
				lolo.pChocobo_2->wSpeed = lolo.pChocobo_1->wSpeed;
				lolo.pChocobo_1->wSpeed = 10;
			}
			if(lolo.pChocobo_2->wSpeed == 0 || lolo.pChocobo_1->wSpeed == 0)
				continue;
			lolo.local_17.vx = lolo.pChocobo_1->sPos_cur.vx - lolo.pChocobo_2->sPos_cur.vx;
			lolo.local_17.vy = 0;
			lolo.local_17.vz = lolo.pChocobo_1->sPos_cur.vz - lolo.pChocobo_2->sPos_cur.vz;
			lolo.dwInvSpeed_2 = 0x80000 / lolo.pChocobo_2->wSpeed;
			psx_VectorNormal(&lolo.local_17, &lolo.local_17);
			lolo.dwInvSpeed_1 = 0x80000 / lolo.pChocobo_1->wSpeed;
			lolo.dwAngle = C_0077CF40(lolo.local_17.vx, lolo.local_17.vz);//chocobo:atan2?
			//-- chocobo makes noise --
			if(lolo.pChocobo_1->wJockeyId == 0 && lolo.pChocobo_1->wSFXCounter < 0) {//else 00773BC4
				lolo.pChocobo_1->wSFXCounter = 30;
				//note: problem here when D_00E71000[bp08] < 0
				lolo.dwVolume = 0x7f - (D_00E71000[bp08] >> 5);
				D_00E71664->wOpCode = SOUND_OP_A3;//set volume
				D_00E71664->f_04[0] = lolo.dwVolume;
				C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);

				D_00E71664->wOpCode = SOUND_OP_2B;//play SFX[ch 4]
				D_00E71664->f_04[0] = lolo.pChocobo_1->f_7c / 2;//pan
				D_00E71664->f_04[1] = (rand() & 1) + 0x114;//soundId
				C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);
			}
			//-- --
			if(lolo.dwInvSpeed_2) {//else 00773C44
				lolo.pChocobo_1->sPos_cur.vx += psx_rsin(lolo.dwAngle) / lolo.dwInvSpeed_2;
				lolo.pChocobo_1->sPos_cur.vz += -psx_rcos(lolo.dwAngle) / lolo.dwInvSpeed_2;
				lolo.pChocobo_1->wSpeed -= lolo.pChocobo_1->wSpeed / 8;
				if(lolo.pChocobo_1->wSpeed < 100)
					lolo.pChocobo_1->wSpeed = 100;
			}
			if(lolo.dwInvSpeed_1) {//else 00773C8E
				lolo.pChocobo_2->sPos_cur.vx -= psx_rsin(lolo.dwAngle) / lolo.dwInvSpeed_1;
				lolo.pChocobo_2->sPos_cur.vz -= -psx_rcos(lolo.dwAngle) / lolo.dwInvSpeed_1;
			}
		}
		//-- --
		if(lolo.pChocobo_1->f_4c == 2 && lolo.dwDiffX < 170 && (rand(), 0))//???
			lolo.pChocobo_1->f_48 = 4;
		//-- --
	}//end for
	//-- chocobos culling --
	//-- determine visibility + update model --
	D_00E71020[bp08] = 0;
	lolo.dwDistance = psx_RotTransPers(&(lolo.pChocobo_1->sPos_cur), (int *)&lolo.local_10, &lolo.local_1, &lolo.local_3);
	if(
		lolo.dwDistance < 2200 &&
		lolo.local_10.vx > -20 && lolo.local_10.vx < 350 &&
		lolo.local_10.vy > 0 && lolo.local_10.vy < 320
	) {
		lolo.pModelC->dwPatchRotY = 0; lolo.pModelJ->dwPatchRotY = 0;
		lolo.pModelC->bRotY = lolo.pModelJ->bRotY = 256 - (lolo.pChocobo_1->sRot_cur.vy >> 4);
		lolo.pModelC->wX = lolo.pModelJ->wX = lolo.pChocobo_1->sPos_cur.vx;
		lolo.pModelC->wY = lolo.pModelJ->wY = lolo.pChocobo_1->sPos_cur.vy;
		lolo.pModelC->wZ = lolo.pModelJ->wZ = lolo.pChocobo_1->sPos_cur.vz;
		D_00E71020[bp08] = 1;
		D_00E71000[bp08] = lolo.dwDistance;
	}
	//-- --
}

//move 1 chocobo?
void C_00773DD8(short bp08) {
	struct {
		int dwPathT_next;//bp_94
		int bp_90;
		struct VECTOR bp_8c,bp_7c;
		int dwPosition;//bp_6c
		int bp_68;
		struct VECTOR bp_64;
		int bp_54;
		DECL_short(wEvent);
		struct SVECTOR *vTrackRight;//bp_4c
		struct VECTOR bp_48;
		struct SVECTOR *vTrackLeft;//bp_38
		int dwPathT;//bp_34
		int j;//bp_30
		int dwSpeed;//bp_2c
		int i;//bp_28
		struct t_chocobo_ChocoboInfo *pChocobo;//bp_24
		struct VECTOR bp_20,bp_10;
	}lolo;

	lolo.pChocobo = &(D_00E71158[bp08]);
	//-- --
	if(lolo.pChocobo->wFinished) {
		lolo.pChocobo->wSpeed -= (lolo.pChocobo->wPosition + 1) * 80 + lolo.pChocobo->wSpeed / 64;
		if(lolo.pChocobo->wSpeed < 100) {
			lolo.pChocobo->wSpeed = 0;
		} else {
			lolo.pChocobo->wAnimationId = 0;//run
			lolo.pChocobo->f_48 = 0;
			if(lolo.pChocobo->f_4c == 2) {
				lolo.pChocobo->wAnimationCounter = 0;
				lolo.pChocobo->wAnimationId = 1;//turbo
				lolo.pChocobo->wSpeed -= 50;
			}
		}
	}
	lolo.dwSpeed = lolo.pChocobo->wSpeed;
	//-- --
	//TRK_CHOCOBO_DIR(lolo.pChocobo->wPathT_next);
	lolo.vTrackLeft = &(D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Left);
	lolo.vTrackRight = &(D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Right);

	lolo.bp_10.vx = lolo.vTrackRight->vx - lolo.vTrackLeft->vx;
	lolo.bp_10.vy = 0;
	lolo.bp_10.vz = lolo.vTrackRight->vz - lolo.vTrackLeft->vz;

	lolo.bp_20.vx = lolo.pChocobo->sPos_cur.vx - lolo.vTrackLeft->vx;
	lolo.bp_20.vy = 0;
	lolo.bp_20.vz = lolo.pChocobo->sPos_cur.vz - lolo.vTrackLeft->vz;
	psx_OuterProduct12(&lolo.bp_10, &lolo.bp_20, &lolo.bp_10);
	if(lolo.bp_10.vy >= 0) {//else ________
		//crossed new "segment"
		lolo.pChocobo->f_84 = 0;
		lolo.j = lolo.pChocobo->wPathT_cur + 20;
		for(lolo.i = lolo.pChocobo->wPathT_cur - 5; lolo.i < lolo.j; lolo.i ++) {
			lolo.dwPathT = (lolo.i + D_00E710E4) % D_00E710E4;
			//TRK_CHOCOBO_DIR(lolo.dwPathT);
			lolo.vTrackLeft = &(D_00E715FC[lolo.dwPathT].sVect_Left);
			lolo.vTrackRight = &(D_00E715FC[lolo.dwPathT].sVect_Right);

			lolo.bp_10.vx = lolo.vTrackRight->vx - lolo.vTrackLeft->vx;
			lolo.bp_10.vy = 0;
			lolo.bp_10.vz = lolo.vTrackRight->vz - lolo.vTrackLeft->vz;

			lolo.bp_20.vx = lolo.pChocobo->sPos_cur.vx - lolo.vTrackLeft->vx;
			lolo.bp_20.vy = 0;
			lolo.bp_20.vz = lolo.pChocobo->sPos_cur.vz - lolo.vTrackLeft->vz;
			psx_OuterProduct12(&lolo.bp_10, &lolo.bp_20, &lolo.bp_10);
			if(lolo.bp_10.vy < 0)
				break;
		}//end for
		lolo.pChocobo->wPathT_cur = lolo.pChocobo->wPathT_next;
		lolo.pChocobo->wPathT_next = lolo.dwPathT + D_00E710E4;
		lolo.pChocobo->wPathT_next %= D_00E710E4;
		//===========
		//== SPEED ==
		if(bp08 != 0 || D_00E71128 == 0 || lolo.pChocobo->wIsAutomatic) {//else 00774336
			//===============
			//== AUTOMATIC ==
			//===============
			if(rand() < 5000) {//else 00774315
				switch(lolo.pChocobo->wType) {
					case CHOCOBO_TYPE_3:
						if(lolo.pChocobo->wLastSprint < lolo.pChocobo->wPathT_cur)
							lolo.pChocobo->f_7c = (lolo.pChocobo->f_7c * 7 + lolo.pChocobo->f_96) / 8;
					//no break
					case CHOCOBO_TYPE_0:
						for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
							if(D_00E71158[lolo.i].wRankPos == 0)
								break;
						}
						if(lolo.i != bp08) {//else 0077419D
							//note:I think this should be wPosition instead of wRankPos.
							// wRankPos being between 0 to 5, the difference will never
							// be over 30.
							if(D_00E71158[lolo.i].wRankPos - lolo.pChocobo->wRankPos > 30) {
								lolo.pChocobo->wAcceleration = 10;
							} else if(lolo.pChocobo->f_4e > (lolo.pChocobo->f_56 * 5) / 4) {
								lolo.pChocobo->wAcceleration = -5;
							} else if(lolo.pChocobo->f_4e < lolo.pChocobo->f_56) {
								lolo.pChocobo->wAcceleration = 3;
							} else {
								lolo.pChocobo->wAcceleration = 0;
							}
						}
					break;
					case CHOCOBO_TYPE_1:
						if(D_00E72EEC == bp08) {
							if(lolo.pChocobo->f_48 == 0)
								lolo.pChocobo->f_48 = rand() & 40;//should be modulo?
						} else if(lolo.pChocobo->f_4e > (lolo.pChocobo->f_56 * 5) / 4) {
							lolo.pChocobo->wAcceleration = -5;
						} else if(lolo.pChocobo->f_4e < (lolo.pChocobo->f_56 * 9) / 10) {
							lolo.pChocobo->wAcceleration = 3;
						} else {
							lolo.pChocobo->wAcceleration = 0;
						}
					break;
					case CHOCOBO_TYPE_2:
						if(lolo.pChocobo->dwStamina > lolo.pChocobo->dwMaxStamina / 3) {
							lolo.pChocobo->wAcceleration = 20;
							if(lolo.pChocobo->wLastSprint > lolo.pChocobo->wPathT_cur && lolo.pChocobo->f_9a)
								lolo.pChocobo->f_48 = 10;
						} else if(lolo.pChocobo->f_4e > (lolo.pChocobo->f_56 * 10) / 9) {
							lolo.pChocobo->wAcceleration = -10;
						} else {
							lolo.pChocobo->wAcceleration = 2;
						}
					break;
				}//end switch
				if(lolo.pChocobo->wLastSprint < lolo.pChocobo->wPathT_cur && lolo.pChocobo->wType != CHOCOBO_TYPE_2) {//else 00774315
					if(lolo.pChocobo->f_9a)
						lolo.pChocobo->f_48 = 50;
					if(lolo.pChocobo->f_48)
						D_00E710E8 = -1;
					lolo.pChocobo->f_7c = (lolo.pChocobo->f_7c * 7 + lolo.pChocobo->f_96) / 8;
				}
			}
			lolo.pChocobo->f_4a = (lolo.pChocobo->f_4a + lolo.pChocobo->f_7c) / 2;
		} else {
			//============
			//== MANUAL ==
			//============
			if(lolo.pChocobo->wLastSprint < lolo.pChocobo->wPathT_cur && lolo.pChocobo->f_48)
				D_00E710E8 = -1;
			if(lolo.pChocobo->dwStamina > 0 && lolo.pChocobo->wFinished == 0) {
				//-- speed up --
				if(D_00E71620 & BIT(CH_KEY_SWITCH))
					lolo.pChocobo->wAcceleration = 2;
				//-- speed down --
				if(D_00E71620 & BIT(CH_KEY_CANCEL))
					lolo.pChocobo->wAcceleration = -2;
				//-- dash --
				if(D_00E71620 & BIT(CH_KEY_OK)) {
					if(lolo.pChocobo->dwStamina > 0)
						lolo.pChocobo->f_48 = 2;
				}
			}
		}
		//==   ==
		//=======
		if((rand() & 0x3f) < lolo.pChocobo->f_62 && lolo.pChocobo->f_48 == 0) {//else 007744C9
			lolo.pChocobo->f_4e += (lolo.pChocobo->f_4e * lolo.pChocobo->wAcceleration) / 100;
			lolo.i = (lolo.pChocobo->f_56 * 5) / 4;
			if(lolo.pChocobo->f_4e > lolo.i)
				lolo.pChocobo->f_4e = lolo.i;
			if(lolo.pChocobo->dwStamina < 0)
				lolo.pChocobo->f_4e = lolo.pChocobo->f_56;
			if(lolo.pChocobo->f_4e > lolo.pChocobo->f_56)
				lolo.pChocobo->dwStamina -= (lolo.pChocobo->f_4e - lolo.pChocobo->f_56) / 0x80;
			if(lolo.pChocobo->wAcceleration > 0)
				lolo.pChocobo->wAcceleration --;
			else if(lolo.pChocobo->wAcceleration < 0)
				lolo.pChocobo->wAcceleration ++;
		}
		if(lolo.pChocobo->f_48) {//else 00774590
			lolo.pChocobo->f_48 --;
			if(lolo.pChocobo->f_48 < 0)
				lolo.pChocobo->f_48 = 0;
			lolo.pChocobo->dwStamina -= lolo.pChocobo->dwMaxStamina / 300;
			if(lolo.pChocobo->dwStamina <= 0) {
				lolo.pChocobo->f_48 = 0;
				lolo.pChocobo->dwStamina = 0;
			}
			if(lolo.pChocobo->f_48 == 0)
				lolo.pChocobo->wAnimationId = 0;//run
			else
				lolo.pChocobo->wAnimationId = 1;//turbo
			if(lolo.pChocobo->f_a0 && D_00E715D8 < 150)
				lolo.pChocobo->f_54 = 5500;
			else
				lolo.pChocobo->f_54 = lolo.pChocobo->wTopSpeed;
		} else if(lolo.pChocobo->f_a2) {
			lolo.pChocobo->f_54 = lolo.pChocobo->f_56;
		} else {
			lolo.pChocobo->f_54 += ((lolo.pChocobo->f_4e - lolo.pChocobo->f_54) * lolo.pChocobo->f_5e) / 100;
		}
		if(lolo.pChocobo->wRankPos > 1 && lolo.pChocobo->f_4c == 1)
			lolo.pChocobo->f_54 = (lolo.pChocobo->f_54 * 9) / 10;
		//==============
		//== POSITION ==
		if(!lolo.pChocobo->wIsAutomatic && D_00E71128) {//else 00774787
			//============
			//== MANUAL ==
			//============
			if((rand() & 0x3f) < lolo.pChocobo->f_62) {//else 007746B8
				if(D_00E71620 & BIT(CH_KEY_LEFT))
					lolo.pChocobo->f_7c += lolo.pChocobo->f_66 + lolo.pChocobo->f_62 / 32;
				if(D_00E71620 & BIT(CH_KEY_RIGHT))
					lolo.pChocobo->f_7c -= lolo.pChocobo->f_66 + lolo.pChocobo->f_62 / 32;
			}
			//-- --
			if((D_00E71620 & 0xffff) && lolo.pChocobo->f_62 < (rand() & 0x1f)) {//else 00774782
				lolo.i = 25 - lolo.pChocobo->f_62 / 2;
				lolo.pChocobo->f_7c += ((rand() & 3) - 1) * lolo.i;
				if(lolo.pChocobo->dwStamina > 0 && (rand() & 7) == 0) {//else 00774782
					lolo.pChocobo->dwStamina -= lolo.pChocobo->dwMaxStamina / 500;
					if(lolo.pChocobo->f_4c == 2)
						lolo.pChocobo->f_48 = 10;
					else
						lolo.pChocobo->wSpeed -= lolo.pChocobo->wSpeed / 4;
				}
			}
			//goto 007748FA
		} else {
			//===============
			//== AUTOMATIC ==
			//===============
			lolo.i = D_00E7112C->pGUIDE[lolo.pChocobo->wPathT_cur].f_00[lolo.pChocobo->f_52];
			lolo.i -= lolo.pChocobo->f_7c;
			if(lolo.i < 0) {
				if(-lolo.i > lolo.pChocobo->f_66)
					lolo.i = -lolo.pChocobo->f_66 + lolo.pChocobo->f_50;
			} else if(lolo.i > lolo.pChocobo->f_66) {
				lolo.i = lolo.pChocobo->f_66 + lolo.pChocobo->f_50;
			}
			for(lolo.j = 0; lolo.j < 6; lolo.j ++) {
				if(lolo.j == bp08)
					continue;
				lolo.dwPathT = lolo.pChocobo->wPathT_cur - D_00E71158[lolo.j].wPathT_cur;
				lolo.dwPathT = (lolo.dwPathT < 0)?-lolo.dwPathT:lolo.dwPathT;
				if(lolo.dwPathT < 20) {//else 007748E3
					lolo.dwPathT = lolo.pChocobo->f_7c - D_00E71158[lolo.j].f_7c;
					lolo.dwPathT = (lolo.dwPathT < 0)?-lolo.dwPathT:lolo.dwPathT;
					if((lolo.dwPathT < 0x10 && (rand() & 0x1f) == 0) || lolo.pChocobo->wFinished)
						lolo.i += ((rand() & 7) - 3) * 0x10;
				}
			}//end for
			lolo.pChocobo->f_7c += lolo.i;
		}
		//==  ==
		//======
		if(lolo.pChocobo->wFinished == 0) {//else 007749B1
			lolo.pChocobo->wSpeed = (D_00E7112C->pGUIDE[lolo.pChocobo->wPathT_cur].f_04[lolo.pChocobo->f_52] * lolo.pChocobo->f_54) / 0x400 + lolo.pChocobo->f_54;
			if(lolo.pChocobo->dwStamina <= 5) {
				lolo.pChocobo->wSpeed = lolo.pChocobo->wSpeed - lolo.pChocobo->wSpeed / 4;
				lolo.pChocobo->wAnimationId = 5;//tired
			} else if(D_00E72EEC == bp08) {
				lolo.pChocobo->wSpeed += lolo.pChocobo->wSpeed / 8;
			}
		}
		if(lolo.pChocobo->f_48 == 0 && lolo.pChocobo->wRankPos < 3) {//else 00774A59
			if(lolo.pChocobo->wType != CHOCOBO_TYPE_2) {//else 00774A1D
				if(lolo.pChocobo->wPathT_cur < lolo.pChocobo->wLastSprint)
					lolo.pChocobo->wSpeed -= lolo.pChocobo->wSpeed / (lolo.pChocobo->wRankPos + 7);
			} else {
				if(lolo.pChocobo->wPathT_cur < lolo.pChocobo->wLastSprint)
					lolo.pChocobo->wSpeed -= lolo.pChocobo->wSpeed / (lolo.pChocobo->wRankPos + 8);
			}
		}
		//-- terrain effect? --
		lolo.i = lolo.pChocobo->wTerrainMask & D_00E715FC[lolo.pChocobo->wPathT_cur].bTerrainFlags;
		if(lolo.i)
			lolo.pChocobo->wSpeed -= (lolo.pChocobo->wSpeed * lolo.i) / 4;
		//-- clamp lolo.pChocobo->f_7c --
		if(lolo.pChocobo->f_7c > 216)
			lolo.pChocobo->f_7c = 216;
		else if(lolo.pChocobo->f_7c < 48)
			lolo.pChocobo->f_7c = 48;
		//-- compute next yaw/rot_y? --
		lolo.bp_90 = 256 - lolo.pChocobo->f_7c;

		lolo.dwPathT_next = lolo.pChocobo->wPathT_next;
		S_MK_TRACK_POS(lolo.pChocobo->sPos_next, lolo.dwPathT_next, lolo.pChocobo->f_7c, lolo.bp_90);

		lolo.dwPathT_next = (lolo.pChocobo->wPathT_next + 1) % D_00E710E4;
		MK_TRACK_POS(lolo.bp_7c, lolo.dwPathT_next, lolo.pChocobo->f_7c, lolo.bp_90);

		lolo.bp_8c.vx = lolo.bp_7c.vx - lolo.pChocobo->sPos_cur.vx;
		lolo.bp_8c.vy = 0;
		lolo.bp_8c.vz = lolo.bp_7c.vz - lolo.pChocobo->sPos_cur.vz;
		psx_VectorNormal(&lolo.bp_8c, &lolo.bp_8c);
		lolo.pChocobo->sRot_next.vy = C_0077CF40(lolo.bp_8c.vx, lolo.bp_8c.vz);//chocobo:atan2?
		//-- camera event --
		lolo.wEvent = D_00E715FC[lolo.pChocobo->wPathT_cur].bCameraEvent;
		if(lolo.wEvent) {
			C_00771697(lolo.wEvent, bp08);//chocobo:set camera event
			D_00E715FC[lolo.pChocobo->wPathT_cur - 1].bCameraEvent = 0;
			D_00E715FC[lolo.pChocobo->wPathT_cur].bCameraEvent = 0;
			D_00E715FC[lolo.pChocobo->wPathT_cur + 1].bCameraEvent = 0;
		}
		//-- animation event --
		lolo.wEvent = D_00E715FC[lolo.pChocobo->wPathT_cur].sVect_Right.pad;
		if(lolo.wEvent)
			C_007722F6(lolo.wEvent);//chocobo:set animation event?
		//goto 007750B3
	} else {
		lolo.bp_54 = 256 - lolo.pChocobo->f_7c;
		lolo.pChocobo->f_84 ++;
		if(lolo.pChocobo->f_84 > 15 && D_00E710F8 && lolo.pChocobo->wFinished == 0) {//else 007750B3
			lolo.pChocobo->wPathT_cur += 2;
			lolo.pChocobo->wPathT_next += 2;

			S_MK_TRACK_POS(lolo.pChocobo->sPos_cur, lolo.pChocobo->wPathT_cur, lolo.pChocobo->f_7c, lolo.bp_54);
			S_MK_TRACK_POS(lolo.pChocobo->sPos_next, lolo.pChocobo->wPathT_next, lolo.pChocobo->f_7c, lolo.bp_54);

			lolo.pChocobo->wSpeed = lolo.pChocobo->f_54 = lolo.pChocobo->f_4e = lolo.pChocobo->f_56;
			lolo.pChocobo->f_84 = 0;

			lolo.bp_64.vx = lolo.pChocobo->sPos_next.vx - lolo.pChocobo->sPos_cur.vx;
			lolo.bp_64.vy = 0;
			lolo.bp_64.vz = lolo.pChocobo->sPos_next.vz - lolo.pChocobo->sPos_cur.vz;
			psx_VectorNormal(&lolo.bp_64, &lolo.bp_64);
			lolo.pChocobo->sRot_cur.vy = lolo.pChocobo->sRot_next.vy = C_0077CF40(lolo.bp_64.vx, lolo.bp_64.vz);//chocobo:atan2?
		}
	}
	//-- --
	if(lolo.pChocobo->wPathT_cur > D_00E710E4 - 10 && lolo.pChocobo->wFinished == 0) {//else 00775238
		lolo.pChocobo->wFinished = -1;
		lolo.pChocobo->sPos_next.vx = lolo.pChocobo->sPos_orig.vx;
		lolo.pChocobo->sPos_next.vy = lolo.pChocobo->sPos_orig.vy;
		lolo.pChocobo->sPos_next.vz = lolo.pChocobo->sPos_orig.vz;
		lolo.dwPosition = 1;
		for(lolo.bp_68 = 0; lolo.bp_68 < 6; lolo.bp_68 ++) {
			if(D_00E71158[lolo.bp_68].wPosition >= lolo.dwPosition)
				lolo.dwPosition = D_00E71158[lolo.bp_68].wPosition + 1;
		}//end for
		lolo.pChocobo->wPosition = lolo.dwPosition;
		if(lolo.dwPosition == 1) {
			D_00E71134 = bp08;
			//-- finish line BGM --
			if(D_00E71128 == 0) {
				D_00E71664->wOpCode = SOUND_OP_10;//"MUSIC"
				D_00E71664->f_04[0] = 0x3b;
				C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);
			}
			//-- --
		}
		if(lolo.dwPosition == 2)
			D_00E71038 = -1;
		//-- finish line BGM --
		if(D_00E71128 && bp08 == 0) {//else 00775238
			if(D_00E71158[0].wPosition == 1)
				D_00E71664->f_04[0] = 0x3b;
			else
				D_00E71664->f_04[0] = 0x3c;
			D_00E71664->wOpCode = SOUND_OP_10;//"MUSIC"
			C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);
		}
		//-- --
	}
	//-- --
	if(lolo.pChocobo->sRot_cur.vy - lolo.pChocobo->sRot_next.vy > 3000)
		lolo.pChocobo->sRot_cur.vy -= 0x1000;
	if(lolo.pChocobo->sRot_cur.vy - lolo.pChocobo->sRot_next.vy < -3000)
		lolo.pChocobo->sRot_cur.vy += 0x1000;
	lolo.pChocobo->sRot_cur.vy = (lolo.pChocobo->sRot_cur.vy * 3 + lolo.pChocobo->sRot_next.vy) / 4;
	if(lolo.dwSpeed) {//else 0077537B
		lolo.pChocobo->vSpeed_dec.vx += (psx_rsin(lolo.pChocobo->sRot_cur.vy) * lolo.dwSpeed) / 64;
		lolo.pChocobo->vSpeed_dec.vz += (-psx_rcos(lolo.pChocobo->sRot_cur.vy) * lolo.dwSpeed) / 64;
		lolo.pChocobo->sPos_cur.vx += lolo.pChocobo->vSpeed_dec.vx / 0x1000;
		lolo.pChocobo->sPos_cur.vz += lolo.pChocobo->vSpeed_dec.vz / 0x1000;
		lolo.pChocobo->vSpeed_dec.vx &= 0x80000fff;
		lolo.pChocobo->vSpeed_dec.vz &= 0x80000fff;
	}
	lolo.bp_10.vx = D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Right.vx - D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Left.vx;
	lolo.bp_10.vy = D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Right.vy - D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Left.vy;
	lolo.bp_10.vz = D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Right.vz - D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Left.vz;

	lolo.bp_20.vx = D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Left.vx - D_00E715FC[lolo.pChocobo->wPathT_cur].sVect_Left.vx;
	lolo.bp_20.vy = D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Left.vy - D_00E715FC[lolo.pChocobo->wPathT_cur].sVect_Left.vy;
	lolo.bp_20.vz = D_00E715FC[lolo.pChocobo->wPathT_next].sVect_Left.vz - D_00E715FC[lolo.pChocobo->wPathT_cur].sVect_Left.vz;
	psx_OuterProduct12(&lolo.bp_20, &lolo.bp_10, &lolo.bp_48);
	if(lolo.bp_48.vy) {
		//-- --
		//
		//
		//
		//
		//
		//
		//-- --
		lolo.i = (
			(D_00E715FC[lolo.pChocobo->wPathT_cur].sVect_Left.vx - lolo.pChocobo->sPos_cur.vx) * lolo.bp_48.vx +
			(D_00E715FC[lolo.pChocobo->wPathT_cur].sVect_Left.vz - lolo.pChocobo->sPos_cur.vz) * lolo.bp_48.vz +
			lolo.bp_48.vy * D_00E715FC[lolo.pChocobo->wPathT_cur].sVect_Left.vy
		) / lolo.bp_48.vy;
	} else {
		lolo.i = lolo.pChocobo->sPos_cur.vy;
	}
	lolo.pChocobo->sPos_cur.vy = (lolo.pChocobo->sPos_prev.vy + lolo.i) / 2;
	lolo.pChocobo->sPos_prev.vy = lolo.pChocobo->sPos_cur.vy;
}

//chocobo:for camera:track chocobo?
void C_0077554D(int bp08) {
	struct {
		int local_7;
		struct t_chocobo_ChocoboInfo *pTracker;//local_6
		struct VECTOR local_5;
		struct t_chocobo_ChocoboInfo *pChocobo;//local_1
	}lolo;

	//-- already tracking it? --
	if(D_00E715DC == bp08)
		return;
	//-- --
	D_00E715DC = bp08;
	lolo.pTracker = &TRACKER_CHOCOBO;
	lolo.pChocobo = &(D_00E71158[bp08]);
	*lolo.pTracker = *lolo.pChocobo;
	//-- compute next yaw/rot_y? --
	lolo.pTracker->f_7c = 127;
	lolo.local_7 = 256 - lolo.pTracker->f_7c;
	//

	S_MK_TRACK_POS(lolo.pTracker->sPos_cur, lolo.pTracker->wPathT_cur, lolo.pTracker->f_7c, lolo.local_7);
	S_MK_TRACK_POS(lolo.pTracker->sPos_next, lolo.pTracker->wPathT_next, lolo.pTracker->f_7c, lolo.local_7);

	lolo.local_5.vx = lolo.pTracker->sPos_next.vx - lolo.pTracker->sPos_cur.vx;
	lolo.local_5.vy = 0;
	lolo.local_5.vz = lolo.pTracker->sPos_next.vz - lolo.pTracker->sPos_cur.vz;
	psx_VectorNormal(&lolo.local_5, &lolo.local_5);
	lolo.pTracker->sRot_next.vy = C_0077CF40(lolo.local_5.vx, lolo.local_5.vz);//chocobo:atan2?
}

//chocobo:for camera(bType 2):track chocobo?
void C_007757CE(int bp08, int dwSpeed/*bp0c*/, int dwPathT/*bp10*/) {
	struct {
		int local_7;
		struct t_chocobo_ChocoboInfo *pTracker;//local_6
		struct VECTOR local_5;
		int dwPathT_next;//local_1
	}lolo;

	D_00E715DC = bp08;
	lolo.pTracker = &TRACKER_CHOCOBO;
	*lolo.pTracker = D_00E71158[bp08];
	lolo.dwPathT_next = (dwPathT + 1 + D_00E710E4) % D_00E710E4;
	lolo.pTracker->wPathT_next = lolo.dwPathT_next;
	lolo.pTracker->wPathT_cur = dwPathT;
	//-- compute next yaw/rot_y? --
	lolo.pTracker->f_7c = 127;
	lolo.local_7 = 256 - lolo.pTracker->f_7c;
	lolo.pTracker->wSpeed = dwSpeed;

	S_MK_TRACK_POS(lolo.pTracker->sPos_cur, dwPathT, lolo.pTracker->f_7c, lolo.local_7);
	S_MK_TRACK_POS(lolo.pTracker->sPos_next, lolo.dwPathT_next, lolo.pTracker->f_7c, lolo.local_7);

	lolo.local_5.vx = lolo.pTracker->sPos_next.vx - lolo.pTracker->sPos_cur.vx;
	lolo.local_5.vy = 0;
	lolo.local_5.vz = lolo.pTracker->sPos_next.vz - lolo.pTracker->sPos_cur.vz;
	psx_VectorNormal(&lolo.local_5, &lolo.local_5);
	lolo.pTracker->sRot_next.vy = C_0077CF40(lolo.local_5.vx, lolo.local_5.vz);//chocobo:atan2?
}

//move tracker?
void C_00775A45(int dwPlayerAsJockey/*bp08*/) {
	struct {
		int dwPathT_next;//bp_7c
		int bp_78;
		struct VECTOR bp_74,bp_64;
		char _p_54[4];
		int bp_50;
		int dwEvent;//bp_4c
		struct SVECTOR *vTrackRight;//local_18
		struct VECTOR bp_44;
		struct SVECTOR *vTrackLeft;//local_13
		int dwPathT;//local_12
		int j;//local_11
		int i;//local_10
		struct t_chocobo_ChocoboInfo *pTracker;//local_9
		struct VECTOR bp_20,bp_10;//local_8,local_4
	}lolo;

	lolo.pTracker = &TRACKER_CHOCOBO;
	//-- --
	//TRK_CHOCOBO_DIR(lolo.pTracker->wPathT_next);
	lolo.vTrackLeft = &(D_00E715FC[lolo.pTracker->wPathT_next].sVect_Left);
	lolo.vTrackRight = &(D_00E715FC[lolo.pTracker->wPathT_next].sVect_Right);

	lolo.bp_10.vx = lolo.vTrackRight->vx - lolo.vTrackLeft->vx;
	lolo.bp_10.vy = 0;
	lolo.bp_10.vz = lolo.vTrackRight->vz - lolo.vTrackLeft->vz;

	lolo.bp_20.vx = lolo.pTracker->sPos_cur.vx - lolo.vTrackLeft->vx;
	lolo.bp_20.vy = 0;
	lolo.bp_20.vz = lolo.pTracker->sPos_cur.vz - lolo.vTrackLeft->vz;
	psx_OuterProduct12(&lolo.bp_10, &lolo.bp_20, &lolo.bp_10);
	if(lolo.bp_10.vy >= 0) {//else 00775F25
		//crossed new "segment"
		lolo.pTracker->f_84 = 0;
		lolo.j = lolo.pTracker->wPathT_cur + 60;
		for(lolo.i = lolo.pTracker->wPathT_cur; lolo.i < lolo.j; lolo.i ++) {
			lolo.dwPathT = (lolo.i + D_00E710E4) % D_00E710E4;
			//TRK_CHOCOBO_DIR(lolo.dwPathT);
			lolo.vTrackLeft = &(D_00E715FC[lolo.dwPathT].sVect_Left);
			lolo.vTrackRight = &(D_00E715FC[lolo.dwPathT].sVect_Right);

			lolo.bp_10.vx = lolo.vTrackRight->vx - lolo.vTrackLeft->vx;
			lolo.bp_10.vy = 0;
			lolo.bp_10.vz = lolo.vTrackRight->vz - lolo.vTrackLeft->vz;

			lolo.bp_20.vx = lolo.pTracker->sPos_cur.vx - lolo.vTrackLeft->vx;
			lolo.bp_20.vy = 0;
			lolo.bp_20.vz = lolo.pTracker->sPos_cur.vz - lolo.vTrackLeft->vz;
			psx_OuterProduct12(&lolo.bp_10, &lolo.bp_20, &lolo.bp_10);
			if(lolo.bp_10.vy < 0)
				break;
		}//end for
		lolo.pTracker->wPathT_cur = lolo.pTracker->wPathT_next;
		lolo.pTracker->wPathT_next = lolo.dwPathT + D_00E710E4;
		lolo.pTracker->wPathT_next %= D_00E710E4;
		//-- compute next yaw/rot_y? --
		lolo.bp_78 = 256 - lolo.pTracker->f_7c;

		lolo.dwPathT_next = lolo.pTracker->wPathT_next;
		S_MK_TRACK_POS(lolo.pTracker->sPos_next, lolo.dwPathT_next, lolo.pTracker->f_7c, lolo.bp_78);

		lolo.dwPathT_next = (lolo.pTracker->wPathT_next + 1) % D_00E710E4;
		MK_TRACK_POS(lolo.bp_64, lolo.dwPathT_next, lolo.pTracker->f_7c, lolo.bp_78);

		lolo.bp_74.vx = lolo.bp_64.vx - lolo.pTracker->sPos_cur.vx;
		lolo.bp_74.vy = 0;
		lolo.bp_74.vz = lolo.bp_64.vz - lolo.pTracker->sPos_cur.vz;
		psx_VectorNormal(&lolo.bp_74, &lolo.bp_74);
		lolo.pTracker->sRot_next.vy = C_0077CF40(lolo.bp_74.vx, lolo.bp_74.vz);//chocobo:atan2?
		//-- animation event --
		lolo.dwEvent = D_00E715FC[lolo.pTracker->wPathT_cur].sVect_Right.pad;
		if(lolo.dwEvent)
			C_007722F6(lolo.dwEvent);//chocobo:set animation event?
		//-- sound event[player as jockey only] --
		if(D_00E71128) {//else 00775F25
			lolo.dwEvent = D_00E715FC[lolo.pTracker->wPathT_cur].sVect_Left.pad;
			if(lolo.dwEvent) {//else 00775F25
				lolo.dwEvent --;
				D_00E71664->wOpCode = D_00E7112C->pSoundEvent[lolo.dwEvent].f_00;
				for(lolo.bp_50 = 0; lolo.bp_50 < 6; lolo.bp_50 ++)
					D_00E71664->f_04[lolo.bp_50] = D_00E7112C->pSoundEvent[lolo.dwEvent].f_02[lolo.bp_50];
				C_00740D80(D_00E71664->wOpCode, D_00E71664->f_04[0], D_00E71664->f_04[1], D_00E71664->f_04[2], D_00E71664->f_04[3], D_00E71664->f_04[4], D_00E71664->f_04[5], 0, 0);
			}
		}
		//-- --
	}
	//-- --
	if(lolo.pTracker->sRot_cur.vy - lolo.pTracker->sRot_next.vy > 3000)
		lolo.pTracker->sRot_cur.vy -= 0x1000;
	if(lolo.pTracker->sRot_cur.vy - lolo.pTracker->sRot_next.vy < -3000)
		lolo.pTracker->sRot_cur.vy += 0x1000;
	lolo.pTracker->sRot_cur.vy = (lolo.pTracker->sRot_cur.vy * 7 + lolo.pTracker->sRot_next.vy) / 8;
	{
		lolo.pTracker->vSpeed_dec.vx += (psx_rsin(lolo.pTracker->sRot_cur.vy) * lolo.pTracker->wSpeed) / 64;
		lolo.pTracker->vSpeed_dec.vz += (-psx_rcos(lolo.pTracker->sRot_cur.vy) * lolo.pTracker->wSpeed) / 64;
		lolo.pTracker->sPos_cur.vx += lolo.pTracker->vSpeed_dec.vx / 0x1000;
		lolo.pTracker->sPos_cur.vz += lolo.pTracker->vSpeed_dec.vz / 0x1000;
		lolo.pTracker->vSpeed_dec.vx &= 0x80000fff;
		lolo.pTracker->vSpeed_dec.vz &= 0x80000fff;
	}
	lolo.bp_10.vx = D_00E715FC[lolo.pTracker->wPathT_next].sVect_Right.vx - D_00E715FC[lolo.pTracker->wPathT_next].sVect_Left.vx;
	lolo.bp_10.vy = D_00E715FC[lolo.pTracker->wPathT_next].sVect_Right.vy - D_00E715FC[lolo.pTracker->wPathT_next].sVect_Left.vy;
	lolo.bp_10.vz = D_00E715FC[lolo.pTracker->wPathT_next].sVect_Right.vz - D_00E715FC[lolo.pTracker->wPathT_next].sVect_Left.vz;

	lolo.bp_20.vx = D_00E715FC[lolo.pTracker->wPathT_next].sVect_Left.vx - D_00E715FC[lolo.pTracker->wPathT_cur].sVect_Left.vx;
	lolo.bp_20.vy = D_00E715FC[lolo.pTracker->wPathT_next].sVect_Left.vy - D_00E715FC[lolo.pTracker->wPathT_cur].sVect_Left.vy;
	lolo.bp_20.vz = D_00E715FC[lolo.pTracker->wPathT_next].sVect_Left.vz - D_00E715FC[lolo.pTracker->wPathT_cur].sVect_Left.vz;
	psx_OuterProduct12(&lolo.bp_20, &lolo.bp_10, &lolo.bp_44);
	if(lolo.bp_44.vy) {//else 007762A3
		//-- camera height[bType -1] --
		lolo.i = (
			(D_00E715FC[TARGET_CHOCOBO.wPathT_cur].sVect_Left.vx - lolo.pTracker->sPos_cur.vx) * lolo.bp_44.vx +
			(D_00E715FC[TARGET_CHOCOBO.wPathT_cur].sVect_Left.vz - lolo.pTracker->sPos_cur.vz) * lolo.bp_44.vz + 
			lolo.bp_44.vy * D_00E715FC[TARGET_CHOCOBO.wPathT_cur].sVect_Left.vy
		) / lolo.bp_44.vy;
		D_00E3BAF4 = (D_00E3BAF4 * 7 + lolo.i) / 8;
		//-- --
		lolo.i = (
			(D_00E715FC[lolo.pTracker->wPathT_cur].sVect_Left.vx - lolo.pTracker->sPos_cur.vx) * lolo.bp_44.vx +
			(D_00E715FC[lolo.pTracker->wPathT_cur].sVect_Left.vz - lolo.pTracker->sPos_cur.vz) * lolo.bp_44.vz + 
			lolo.bp_44.vy * D_00E715FC[lolo.pTracker->wPathT_cur].sVect_Left.vy
		) / lolo.bp_44.vy;
	} else {
		lolo.i = lolo.pTracker->sPos_cur.vy;
	}
	lolo.pTracker->sPos_cur.vy = (lolo.pTracker->sPos_prev.vy + lolo.i) / 2;
	lolo.pTracker->sPos_prev.vy = lolo.pTracker->sPos_cur.vy;
	//-- --
	if(dwPlayerAsJockey && D_00E710F8) {//else 00776362
		lolo.dwPathT = TARGET_CHOCOBO.wPathT_cur - lolo.pTracker->wPathT_cur;
		lolo.pTracker->wSpeed = TARGET_CHOCOBO.wSpeed;
		if(TARGET_CHOCOBO.wFinished == 0) {//else 00776362
			if(lolo.dwPathT < 1)
				lolo.pTracker->wSpeed = 0;
			else if(lolo.dwPathT > 2)
				lolo.pTracker->wSpeed += lolo.dwPathT * 150;
		}
	}
}

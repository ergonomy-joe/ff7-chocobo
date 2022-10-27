/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
extern int D_0096EBC0[];
extern short D_0097A3E0[][4];
extern unsigned char D_0097C8A8[];
unsigned char D_0097CC58[][7];//chocobo names
////////////////////////////////////////
extern int D_00E3BAF4;
extern int D_00E71000[];//chocobo signed distance from camera
extern int D_00E7101C;
extern int D_00E71020[];//"visible chocobo" flags
extern int D_00E71038;
extern int D_00E710E0;
extern int D_00E710E4;
extern int D_00E710E8;
extern int D_00E710F8;
extern int D_00E71134;
extern struct t_chocobo_a4 D_00E71158[/*6*/];
extern struct t_chocobo_a4 D_00E71530;
extern int D_00E715D8;
extern int D_00E715DC;
extern struct t_chocobo_data_18 *D_00E715FC;
////////////////////////////////////////
int D_00E72EEC;
////////////////////////////////////////
int C_00772340(int bp08) {
	if(bp08 == 0)
		return 0x3de;
	else
		return 0x320;
}

void C_00773487(int, int, int);//set some special abilities?

void C_00772357() {
	struct {
		struct t_chocobo_3c *bp_134;
		char _p_130[0xc];
		int j;//bp_124
		char _p_120[8];
		unsigned char *bp_118;
		char _p_114[4];
		struct SVECTOR bp_110;
		struct SVECTOR bp_108;
		int dwTemp_0;//bp_100
		int bp_fc;
		int bp_f8;
		int bp_f4;
		int dwTemp_1;//bp_f0
		int bp_ec;
		short i; char _p_e8[2];//bp_e8
		int bp_e4;
		int bp_e0;
		struct t_chocobo_a4 *bp_dc;
		struct VECTOR bp_d8;
		struct t_aa0 *bp_c8;
		int bp_c4[45];
		struct fBGRA bp_10;
	}lolo;

	lolo.bp_c8 = C_00676578();
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		lolo.bp_dc = &(D_00E71158[lolo.i]);
		lolo.bp_dc->f_7c = (lolo.i * 0xe0) / 6 + 0x10;
	}
	for(lolo.i = 0; lolo.i < 40; lolo.i ++) {
		lolo.bp_f8 = rand() % 6;
		lolo.bp_fc = rand() % 6;
		SWAP(D_00E71158[lolo.bp_f8].f_7c, D_00E71158[lolo.bp_fc].f_7c, lolo.dwTemp_0);
	}
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		lolo.bp_dc = &(D_00E71158[lolo.i]);
		if(D_00E71128 && lolo.i == 0) {//else 00772657
			lolo.bp_dc->wTopSpeed = D_00DC0AE6 + (D_00DC0AE7 << 8);
			lolo.bp_dc->f_56 = D_00DC0AE8 + (D_00DC0AE9 << 8);
			lolo.bp_dc->f_5e = D_00DC0AEA;
			lolo.bp_dc->f_62 = D_00DC0AEB;
			lolo.bp_dc->f_06 = rand() % 4;
			lolo.bp_dc->dwStamina =
			lolo.bp_dc->dwMaxStamina = D_00DC0AF6 + (D_00DC0AF7 << 8);
			lolo.bp_dc->wIsAutomatic = 1;
			lolo.bp_dc->f_4c = D_00DC0AEE;
			lolo.bp_dc->f_5c = lolo.bp_dc->f_64 / 10;
			switch(D_00DC0AED) {
				case 1: lolo.bp_dc->f_86 = 1; break;
				case 2: lolo.bp_dc->f_86 = 2; break;
				case 3:
				case 4: lolo.bp_dc->f_86 = 0; break;
				default:
					lolo.bp_dc->f_86 = 3;
			}//end switch
			lolo.bp_dc->f_64 = D_00DC0AEC;
			//goto 00772793
		} else {
			lolo.bp_dc->wTopSpeed = D_0097A3E0[D_00DC0AF3][0] + (rand() % D_0097A3E0[D_00DC0AF3][1]);
			lolo.bp_dc->f_56 = D_0097A3E0[D_00DC0AF3][2] + (rand() % D_0097A3E0[D_00DC0AF3][3]);
			lolo.bp_dc->f_5e = 50;
			lolo.bp_dc->f_62 = 100;
			lolo.bp_dc->f_06 = rand() % 4;
			lolo.bp_dc->dwStamina =
			lolo.bp_dc->dwMaxStamina = D_0097A3E0[D_00DC0AF3][0] + (rand() % 300);
			lolo.bp_dc->wIsAutomatic = 1;
			lolo.bp_dc->f_4c = (rand() & 7)?0:2;
			lolo.bp_dc->f_5c = lolo.bp_dc->f_64 / 10;
			lolo.bp_dc->f_86 = 3;
			lolo.bp_dc->f_64 = (rand() & 1) * 50 + 50;
		}
		if(lolo.bp_dc->f_64 < 40) {
			lolo.bp_dc->f_52 = 3;
			lolo.bp_dc->f_66 = (40 - lolo.bp_dc->f_64) / 10;
		} else if(lolo.bp_dc->f_64 < 60) {
			lolo.bp_dc->f_52 = 2;
			lolo.bp_dc->f_66 = (60 - lolo.bp_dc->f_64) / 5;
		} else if(lolo.bp_dc->f_64 < 80) {
			lolo.bp_dc->f_52 = 1;
			lolo.bp_dc->f_66 = (80 - lolo.bp_dc->f_64) / 5;
		} else {
			lolo.bp_dc->f_52 = 0;
			lolo.bp_dc->f_66 = (0x6e - lolo.bp_dc->f_64) / 5;
		}
		lolo.bp_dc->f_5c = lolo.bp_dc->f_64 / 8;
		lolo.bp_dc->f_98 = D_00E7112C->f_04;
		lolo.bp_dc->f_82 = lolo.i;
		lolo.bp_dc->f_04 = lolo.bp_dc->f_56 / 2;
		lolo.bp_dc->f_4e = lolo.bp_dc->f_56;
		lolo.bp_dc->f_00 = 0xa;
		lolo.bp_dc->f_02 = 0xb;
		lolo.bp_dc->f_84 = 0;
		lolo.bp_dc->f_9a = -1;
		lolo.bp_dc->f_a0 = 0;
		lolo.bp_dc->f_9e = 0;
		lolo.bp_dc->f_9c = 0;
		lolo.bp_dc->f_a2 = 0;
		lolo.bp_f4 = 0x100 - lolo.bp_dc->f_7c;
		lolo.bp_dc->f_96 = lolo.bp_dc->f_7c;
		lolo.bp_dc->f_10.f_00 = (D_00E715FC[lolo.bp_dc->f_00].f_00.f_00 * lolo.bp_dc->f_7c + D_00E715FC[lolo.bp_dc->f_00].f_08.f_00 * lolo.bp_f4) / 0x100;
		lolo.bp_dc->f_10.f_02 = (D_00E715FC[lolo.bp_dc->f_00].f_00.f_02 * lolo.bp_dc->f_7c + D_00E715FC[lolo.bp_dc->f_00].f_08.f_02 * lolo.bp_f4) / 0x100;
		lolo.bp_dc->f_10.f_04 = (D_00E715FC[lolo.bp_dc->f_00].f_00.f_04 * lolo.bp_dc->f_7c + D_00E715FC[lolo.bp_dc->f_00].f_08.f_04 * lolo.bp_f4) / 0x100;
		lolo.bp_dc->f_40.f_00 = lolo.bp_dc->f_10.f_00;
		lolo.bp_dc->f_40.f_02 = lolo.bp_dc->f_10.f_02;
		lolo.bp_dc->f_40.f_04 = lolo.bp_dc->f_10.f_04;
		lolo.bp_dc->f_28.f_00 = (D_00E715FC[lolo.bp_dc->f_02].f_00.f_00 * lolo.bp_dc->f_7c + D_00E715FC[lolo.bp_dc->f_02].f_08.f_00 * lolo.bp_f4) / 0x100;
		lolo.bp_dc->f_28.f_02 = (D_00E715FC[lolo.bp_dc->f_02].f_00.f_02 * lolo.bp_dc->f_7c + D_00E715FC[lolo.bp_dc->f_02].f_08.f_02 * lolo.bp_f4) / 0x100;
		lolo.bp_dc->f_28.f_04 = (D_00E715FC[lolo.bp_dc->f_02].f_00.f_04 * lolo.bp_dc->f_7c + D_00E715FC[lolo.bp_dc->f_02].f_08.f_04 * lolo.bp_f4) / 0x100;
		lolo.bp_dc->f_30.f_00 = 0;
		lolo.bp_dc->f_30.f_02 = 0;
		lolo.bp_dc->f_30.f_04 = 0;
		lolo.bp_dc->f_38.f_00 = 0;
		lolo.bp_dc->f_38.f_02 = 0;
		lolo.bp_dc->f_38.f_04 = 0;
		lolo.bp_dc->f_30.f_02 = C_0077CFBF(&(D_00E715FC[0x800].f_00), &(D_00E715FC[0x801].f_00));//chocobo:make dir angle?
		lolo.bp_dc->f_70 = 0;
		lolo.bp_dc->wAnimationCounter = 0;
		lolo.bp_dc->wAnimationCounterIncr = lolo.bp_dc->f_04 / D_00E7101C;
		lolo.bp_dc->f_7e = 0;
		lolo.bp_dc->wAnmNum = 0;
		lolo.bp_d8.f_00 = lolo.bp_dc->f_28.f_00 - lolo.bp_dc->f_10.f_00;
		lolo.bp_d8.f_04 = lolo.bp_dc->f_28.f_02 - lolo.bp_dc->f_10.f_02;
		lolo.bp_d8.f_08 = lolo.bp_dc->f_28.f_04 - lolo.bp_dc->f_10.f_04;
		psx_VectorNormal(&lolo.bp_d8, &lolo.bp_d8);
		lolo.bp_dc->f_30.f_02 = lolo.bp_dc->f_38.f_02 = C_0077CF40(lolo.bp_d8.f_00, lolo.bp_d8.f_08);//chocobo:some atan2?
	}//end for
	//-- "TEIOH" --
	if(D_00DC0AF2) {//else 00772EA7
		lolo.bp_108 = D_00E71158[1].f_10;
		lolo.bp_110 = D_00E71158[1].f_28;
		D_00E71158[1] = D_00E71158[0];
		D_00E71158[1].f_10 = lolo.bp_108;
		D_00E71158[1].f_40 = lolo.bp_108;
		D_00E71158[1].f_28 = lolo.bp_110;
		D_00E71158[1].dwMaxStamina += D_00E71158[1].dwMaxStamina / 4;
		D_00E71158[1].dwStamina += D_00E71158[1].dwStamina / 4;
		D_00E71158[1].f_56 += D_00E71158[1].f_56 / 10;
		D_00E71158[1].wTopSpeed += D_00E71158[1].wTopSpeed / 10;
		D_00E71158[1].f_5e = 100;
		D_00E71158[1].f_64 = 100;
		D_00E71158[1].f_90 = 2;//twice?
		D_00E71158[1].f_06 = 3;
		D_00E71158[1].f_86 = 0;
		D_00E71158[1].f_90 = 9;//twice?
		D_00E71158[1].f_92 = 1;
	}
	//-- chocobos'names --
	for(lolo.bp_e4 = 0; lolo.bp_e4 < 45; lolo.bp_e4 ++)
		lolo.bp_c4[lolo.bp_e4] = lolo.bp_e4;
	for(lolo.bp_e4 = 0; lolo.bp_e4 < 200; lolo.bp_e4 ++) {
		lolo.bp_ec = rand() % 45;
		lolo.bp_e0 = rand() % 45;
		SWAP(lolo.bp_c4[lolo.bp_ec], lolo.bp_c4[lolo.bp_e0], lolo.dwTemp_1);
	}
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		if(D_00DC0AF2 && lolo.i == 1) {//else 00773008
			//-- "TEIOH" --
			for(lolo.j = 0; lolo.j < 8; lolo.j ++)
				D_00E71158[lolo.i].f_88[lolo.j] = D_0097C8A8[lolo.j];
			//goto 007730BE
		} else {
			lolo.bp_118 = D_0097CC58[lolo.bp_c4[lolo.i]];
			for(lolo.j = 0; lolo.j < 6; lolo.j ++) {
				D_00E71158[lolo.i].f_88[lolo.j] = *lolo.bp_118;
				lolo.bp_118 ++;
			}//end for
			D_00E71158[lolo.i].f_88[lolo.j] = 0xff;
			//-- special abilities? --
			if(D_00E71128 && lolo.i)
				C_00773487(lolo.i, 0, 0);//set some special abilities?
			//-- --
		}
	}
	//-- user's chocobo's name --
	if(D_00E71128) {
		struct tDummyName { char name[6]; };//size 6
		*(struct tDummyName *)D_00E71158[0].f_88 = *(struct tDummyName *)D_00DC0ADC;
		D_00E71158[0].f_88[6] = 0xff;
	}
	//-- --
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		lolo.bp_dc = &(D_00E71158[lolo.i]);
		lolo.bp_134 = &(D_00E719E8[lolo.bp_dc->f_90]);
		//-- "TEIOH" --
		if(D_00DC0AF2 && lolo.i == 1)
			continue;
		//-- --
		if(D_00E71128 && lolo.i == 0)
			continue;
		//-- set color? --
		switch(lolo.bp_dc->f_06) {
			case 0:
				lolo.bp_134->f_06 =
				lolo.bp_134->f_07 =
				lolo.bp_134->f_08 = 0;
				lolo.bp_10.r = (float)lolo.bp_134->f_06 / 256.0f;
				lolo.bp_10.g = (float)lolo.bp_134->f_07 / 256.0f;
				lolo.bp_10.b = (float)lolo.bp_134->f_08 / 256.0f;
				lolo.bp_10.a = 1.0f;
				C_00684E20(&lolo.bp_10, lolo.bp_134->f_34->f_b4, lolo.bp_c8);//anm: apply add color to skeleton?
			break;
			case 1:
				lolo.bp_134->f_06 = 0x40;
				lolo.bp_134->f_07 = 0x40;
				lolo.bp_134->f_08 = 0;
				lolo.bp_10.r = (float)lolo.bp_134->f_06 / 256.0f;
				lolo.bp_10.g = (float)lolo.bp_134->f_07 / 256.0f;
				lolo.bp_10.b = (float)lolo.bp_134->f_08 / 256.0f;
				lolo.bp_10.a = 1.0f;
				C_00684E20(&lolo.bp_10, lolo.bp_134->f_34->f_b4, lolo.bp_c8);//anm: apply add color to skeleton?
			break;
			case 2:
				lolo.bp_134->f_06 = 0x40;
				lolo.bp_134->f_07 = 0x10;
				lolo.bp_134->f_08 = 0;
				lolo.bp_10.r = (float)lolo.bp_134->f_06 / 256.0f;
				lolo.bp_10.g = (float)lolo.bp_134->f_07 / 256.0f;
				lolo.bp_10.b = (float)lolo.bp_134->f_08 / 256.0f;
				lolo.bp_10.a = 1.0f;
				C_00684E20(&lolo.bp_10, lolo.bp_134->f_34->f_b4, lolo.bp_c8);//anm: apply add color to skeleton?
			break;
			case 3:
				lolo.bp_134->f_06 = 0;
				lolo.bp_134->f_07 = 0x10;
				lolo.bp_134->f_08 = 0x40;
				lolo.bp_10.r = (float)lolo.bp_134->f_06 / 256.0f;
				lolo.bp_10.g = (float)lolo.bp_134->f_07 / 256.0f;
				lolo.bp_10.b = (float)lolo.bp_134->f_08 / 256.0f;
				lolo.bp_10.a = 1.0f;
				C_00684E20(&lolo.bp_10, lolo.bp_134->f_34->f_b4, lolo.bp_c8);//anm: apply add color to skeleton?
			break;
		}
		//-- --
	}
}

void C_007734AC(int, int);//set some special ability?

//set some special abilities?
void C_00773487(int bp08, int bp0c, int bp10) {
	C_007734AC(bp08, bp0c);//set some special ability?
	C_007734AC(bp08, bp10);//set some special ability?
}

//set some special ability?
void C_007734AC(int bp08, int bp0c) {
	struct t_chocobo_a4 *bp_04;

	bp_04 = &(D_00E71158[bp08]);
	switch(bp0c) {
		case 1:
			bp_04->f_98 = D_00E7112C->f_04 + 20;
		break;
		case 2:
			bp_04->dwMaxStamina += (bp_04->dwMaxStamina * 4) / 3;
			bp_04->dwStamina = bp_04->dwMaxStamina;
		break;
		case 3:
			bp_04->f_98 = D_00E7112C->f_04 - 20;
		break;
		case 4:
			bp_04->f_4c = 2;
		break;
		case 5:
			bp_04->f_9a = 0;
		break;
		case 6:
			bp_04->f_64 = 100;
			bp_04->f_52 = 0;
			bp_04->f_06 = 3;
		break;
		case 7:
			bp_04->f_9c = -1;
		break;
		case 8:
			bp_04->dwMaxStamina /= 2;
			bp_04->dwStamina = bp_04->dwMaxStamina;
		break;
		case 9:
			bp_04->f_86 &= 2;
		break;
		case 0xa:
			bp_04->f_86 &= 1;
		break;
		case 0xb:
			bp_04->f_a0 = -1;
			if(rand() & 1)
				bp_04->dwMaxStamina /= 2;
		break;
		case 0xc:
			bp_04->f_a2 = -1;
		break;
		case 0xd:
			bp_04->f_52 = 3;
		break;
	}//end switch
}

void C_007737B4(short);
void C_00775A45(int);

void C_00773668() {
	struct {
		int dwTemp;//bp_3c
		int bp_38[6];
		int bp_20;
		int bp_1c;//local_7
		int bp_18[6];
	}lolo;

	for(lolo.bp_1c = 0; lolo.bp_1c < 6; lolo.bp_1c ++) {
		lolo.bp_38[lolo.bp_1c] = D_00E71158[lolo.bp_1c].f_00;
		lolo.bp_18[lolo.bp_1c] = lolo.bp_1c;
	}
	for(lolo.bp_1c = 0; lolo.bp_1c < 6; lolo.bp_1c ++) {
		for(lolo.bp_20 = lolo.bp_1c; lolo.bp_20 < 6; lolo.bp_20 ++) {
			if(lolo.bp_38[lolo.bp_1c] < lolo.bp_38[lolo.bp_20]) {
				SWAP(lolo.bp_38[lolo.bp_1c], lolo.bp_38[lolo.bp_20], lolo.dwTemp);
				SWAP(lolo.bp_18[lolo.bp_1c], lolo.bp_18[lolo.bp_20], lolo.dwTemp);
			}
		}
	}
	for(lolo.bp_1c = 0; lolo.bp_1c < 6; lolo.bp_1c ++)
		D_00E71158[lolo.bp_18[lolo.bp_1c]].f_82 = lolo.bp_1c;
	D_00E72EEC = lolo.bp_18[5];
	for(lolo.bp_1c = 0; lolo.bp_1c < 6; lolo.bp_1c ++)
		C_007737B4(lolo.bp_1c);
	if(D_00E71128)
		C_00775A45(1);
	else
		C_00775A45(0);
}

void C_00773DD8(short);

void C_007737B4(short bp08) {
	struct {
		int dwVolume;//local_20
		int local_19;
		int local_18;
		struct VECTOR local_17;
		struct t_chocobo_a4 *local_13;
		int local_12;
		struct t_chocobo_3c *local_11;
		struct SVECTOR local_10;
		int local_8;
		struct t_chocobo_3c *local_7;
		int i;//local_6
		int local_5;
		int dwDistance;//local_4
		int local_3;
		struct t_chocobo_a4 *local_2;
		int local_1;
	}lolo;

	lolo.local_2 = &(D_00E71158[bp08]);
	if(D_00E710F8 == 0) {
		lolo.local_2->wAnmNum = 3;
		lolo.local_2->wAnimationCounterIncr = 0x100;
		lolo.local_2->f_04 = 10;
	} else if(lolo.local_2->f_04) {
		C_00773DD8(bp08);
		lolo.local_2->wAnimationCounterIncr = lolo.local_2->f_04 / D_00E7101C;
		//goto 007738DD
	} else {
		D_00E710E0 ++;
		if(D_00DC0AF2 && lolo.local_2->f_92 == 1) {
			//-- "TEIOH" --
			switch(lolo.local_2->f_70) {
				case 1: lolo.local_2->wAnmNum = 2; break;
				case 2: lolo.local_2->wAnmNum = 3; break;
				default:
					lolo.local_2->wAnmNum = 4;
			}//end switch
			//goto 007738D4
		} else {
			switch(lolo.local_2->f_70) {
				case 1: lolo.local_2->wAnmNum = 2; break;
				case 6: lolo.local_2->wAnmNum = 4; break;
				default:
					lolo.local_2->wAnmNum = 3;
			}//end switch
		}
		lolo.local_2->wAnimationCounterIncr = 0x100;
	}
	lolo.local_2->wAnimationCounter += lolo.local_2->wAnimationCounterIncr;
	lolo.local_2->f_74 += lolo.local_2->wAnimationCounterIncr;
	lolo.local_7 = &(D_00E719E8[lolo.local_2->f_92]);
	lolo.local_11 = &(D_00E719E8[lolo.local_2->f_90]);
	if((lolo.local_2->wAnimationCounter >> 8) >= D_0096EBC0[lolo.local_2->wAnmNum]) {
		if(lolo.local_2->wPrevAnmNum != lolo.local_2->wAnmNum) {
			lolo.local_2->wPrevAnmNum = lolo.local_2->wAnmNum;
			lolo.local_2->wAnimationCounter = 0;
		} else {
			lolo.local_2->wAnimationCounter &= 0xff;
		}
	}
	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		if(lolo.i == bp08)
			continue;
		lolo.local_13 = &(D_00E71158[lolo.i]);
		lolo.local_5 = lolo.local_2->f_10.f_00 - lolo.local_13->f_10.f_00;
		lolo.local_8 = lolo.local_2->f_10.f_04 - lolo.local_13->f_10.f_04;
		lolo.local_5 = psx_SquareRoot0(lolo.local_5 * lolo.local_5 + lolo.local_8 * lolo.local_8);
		if(lolo.local_5 < 150) {//else 00773C8E
			if(lolo.local_13->f_7e) {
				lolo.local_13->f_04 = lolo.local_2->f_04;
				lolo.local_2->f_04 = 10;
			}
			if(lolo.local_13->f_04 == 0 || lolo.local_2->f_04 == 0)
				continue;
			lolo.local_17.f_00 = lolo.local_2->f_10.f_00 - lolo.local_13->f_10.f_00;
			lolo.local_17.f_04 = 0;
			lolo.local_17.f_08 = lolo.local_2->f_10.f_04 - lolo.local_13->f_10.f_04;
			lolo.local_19 = 0x80000 / lolo.local_13->f_04;
			psx_VectorNormal(&lolo.local_17, &lolo.local_17);
			lolo.local_12 = 0x80000 / lolo.local_2->f_04;
			lolo.local_18 = C_0077CF40(lolo.local_17.f_00, lolo.local_17.f_08);//chocobo:some atan2?
			//-- chocobo makes noise --
			if(lolo.local_2->f_92 == 0 && lolo.local_2->f_94 < 0) {//else 00773BC4
				lolo.local_2->f_94 = 30;
				//note: problem here when D_00E71000[bp08] < 0
				lolo.dwVolume = 0x7f - (D_00E71000[bp08] >> 5);
				D_00E71664->f_00 = 0xa3;//set volume
				D_00E71664->f_04[0] = lolo.dwVolume;
				C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);

				D_00E71664->f_00 = 0x2b;
				D_00E71664->f_04[0] = lolo.local_2->f_7c / 2;
				D_00E71664->f_04[1] = (rand() & 1) + 0x114;
				C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);
			}
			//-- --
			if(lolo.local_19) {//else 00773C44
				lolo.local_2->f_10.f_00 += psx_rsin(lolo.local_18) / lolo.local_19;
				lolo.local_2->f_10.f_04 += -psx_rcos(lolo.local_18) / lolo.local_19;
				lolo.local_2->f_04 -= lolo.local_2->f_04 / 8;
				if(lolo.local_2->f_04 < 100)
					lolo.local_2->f_04 = 100;
			}
			if(lolo.local_12) {//else 00773C8E
				lolo.local_13->f_10.f_00 -= psx_rsin(lolo.local_18) / lolo.local_12;
				lolo.local_13->f_10.f_04 -= -psx_rcos(lolo.local_18) / lolo.local_12;
			}
		}
		if(lolo.local_2->f_4c == 2 && lolo.local_5 < 0xaa && (rand(), 0))//???
			lolo.local_2->f_48 = 4;
	}//end for
	//-- determine chocobo's visibility --
	D_00E71020[bp08] = 0;
	lolo.dwDistance = psx_RotTransPers(&(lolo.local_2->f_10), (int *)&lolo.local_10, &lolo.local_1, &lolo.local_3);
	if(
		lolo.dwDistance < 2200 &&
		lolo.local_10.f_00 > -20 && lolo.local_10.f_00 < 350 &&
		lolo.local_10.f_02 > 0 && lolo.local_10.f_02 < 320
	) {
		lolo.local_11->f_24 = 0; lolo.local_7->f_24 = 0;
		lolo.local_11->f_0a = lolo.local_7->f_0a = 0x100 - (lolo.local_2->f_30.f_02 >> 4);
		lolo.local_11->f_00 = lolo.local_7->f_00 = lolo.local_2->f_10.f_00;
		lolo.local_11->f_02 = lolo.local_7->f_02 = lolo.local_2->f_10.f_02;
		lolo.local_11->f_04 = lolo.local_7->f_04 = lolo.local_2->f_10.f_04;
		D_00E71020[bp08] = 1;
		D_00E71000[bp08] = lolo.dwDistance;
	}
	//-- --
}

void C_00773DD8(short bp08) {
	struct {
		int bp_94;
		int bp_90;
		struct VECTOR bp_8c;
		struct VECTOR bp_7c;
		int bp_6c;
		int bp_68;
		struct VECTOR bp_64;
		int bp_54;
		short bp_50; char _p_50[2];
		struct SVECTOR *bp_4c;
		struct VECTOR bp_48;
		struct SVECTOR *bp_38;
		int bp_34;
		int bp_30;
		int bp_2c;
		int bp_28;
		struct t_chocobo_a4 *bp_24;
		struct VECTOR bp_20;
		struct VECTOR bp_10;
	}lolo;

	lolo.bp_24 = &(D_00E71158[bp08]);
	if(lolo.bp_24->f_7e) {
		lolo.bp_24->f_04 -= (lolo.bp_24->f_70 + 1) * 80 + lolo.bp_24->f_04 / 0x40;
		if(lolo.bp_24->f_04 < 100) {
			lolo.bp_24->f_04 = 0;
		} else {
			lolo.bp_24->wAnmNum = 0;
			lolo.bp_24->f_48 = 0;
			if(lolo.bp_24->f_4c == 2) {
				lolo.bp_24->wAnimationCounter = 0;
				lolo.bp_24->wAnmNum = 1;
				lolo.bp_24->f_04 -= 50;
			}
		}
	}
	lolo.bp_2c = lolo.bp_24->f_04;
	lolo.bp_38 = &(D_00E715FC[lolo.bp_24->f_02].f_00);
	lolo.bp_4c = &(D_00E715FC[lolo.bp_24->f_02].f_08);
	lolo.bp_10.f_00 = lolo.bp_4c->f_00 - lolo.bp_38->f_00;
	lolo.bp_10.f_04 = 0;
	lolo.bp_10.f_08 = lolo.bp_4c->f_04 - lolo.bp_38->f_04;
	lolo.bp_20.f_00 = lolo.bp_24->f_10.f_00 - lolo.bp_38->f_00;
	lolo.bp_20.f_04 = 0;
	lolo.bp_20.f_08 = lolo.bp_24->f_10.f_04 - lolo.bp_38->f_04;
	psx_OuterProduct12(&lolo.bp_10, &lolo.bp_20, &lolo.bp_10);
	if(lolo.bp_10.f_04 >= 0) {//else
		lolo.bp_24->f_84 = 0;
		lolo.bp_30 = lolo.bp_24->f_00 + 20;
		for(lolo.bp_28 = lolo.bp_24->f_00 - 5; lolo.bp_28 < lolo.bp_30; lolo.bp_28 ++) {
			lolo.bp_34 = (lolo.bp_28 + D_00E710E4) % D_00E710E4;
			lolo.bp_38 = &(D_00E715FC[lolo.bp_34].f_00);
			lolo.bp_4c = &(D_00E715FC[lolo.bp_34].f_08);
			lolo.bp_10.f_00 = lolo.bp_4c->f_00 - lolo.bp_38->f_00;
			lolo.bp_10.f_04 = 0;
			lolo.bp_10.f_08 = lolo.bp_4c->f_04 - lolo.bp_38->f_04;
			lolo.bp_20.f_00 = lolo.bp_24->f_10.f_00 - lolo.bp_38->f_00;
			lolo.bp_20.f_04 = 0;
			lolo.bp_20.f_08 = lolo.bp_24->f_10.f_04 - lolo.bp_38->f_04;
			psx_OuterProduct12(&lolo.bp_10, &lolo.bp_20, &lolo.bp_10);
			if(lolo.bp_10.f_04 < 0)
				break;
		}
		lolo.bp_24->f_00 = lolo.bp_24->f_02;
		lolo.bp_24->f_02 = lolo.bp_34 + D_00E710E4;
		lolo.bp_24->f_02 %= D_00E710E4;
		//===========
		//== SPEED ==
		if(bp08 != 0 || D_00E71128 == 0 || lolo.bp_24->wIsAutomatic) {//else 00774336
			//===============
			//== AUTOMATIC ==
			//===============
			if(rand() < 5000) {//else 00774315
				switch(lolo.bp_24->f_06) {
					case 3:
						if(lolo.bp_24->f_98 < lolo.bp_24->f_00)
							lolo.bp_24->f_7c = (lolo.bp_24->f_7c * 7 + lolo.bp_24->f_96) / 8;
					//no break
					case 0:
						for(lolo.bp_28 = 0; lolo.bp_28 < 6; lolo.bp_28 ++) {
							if(D_00E71158[lolo.bp_28].f_82 == 0)
								break;
						}
						if(lolo.bp_28 != bp08) {//else 0077419D
							if(D_00E71158[lolo.bp_28].f_82 - lolo.bp_24->f_82 > 0x1e) {
								lolo.bp_24->f_5a = 10;
							} else if(lolo.bp_24->f_4e > (lolo.bp_24->f_56 * 5) / 4) {
								lolo.bp_24->f_5a = -5;
							} else if(lolo.bp_24->f_4e < lolo.bp_24->f_56) {
								lolo.bp_24->f_5a = 3;
							} else {
								lolo.bp_24->f_5a = 0;
							}
						}
					break;
					case 1:
						if(D_00E72EEC == bp08) {
							if(lolo.bp_24->f_48 == 0)
								lolo.bp_24->f_48 = rand() & 40;//should be modulo?
						} else if(lolo.bp_24->f_4e > (lolo.bp_24->f_56 * 5) / 4) {
							lolo.bp_24->f_5a = -5;
						} else if(lolo.bp_24->f_4e < (lolo.bp_24->f_56 * 9) / 10) {
							lolo.bp_24->f_5a = 3;
						} else {
							lolo.bp_24->f_5a = 0;
						}
					break;
					case 2:
						if(lolo.bp_24->dwStamina > lolo.bp_24->dwMaxStamina / 3) {
							lolo.bp_24->f_5a = 20;
							if(lolo.bp_24->f_98 > lolo.bp_24->f_00 && lolo.bp_24->f_9a)
								lolo.bp_24->f_48 = 10;
						} else if(lolo.bp_24->f_4e > (lolo.bp_24->f_56 * 10) / 9) {
							lolo.bp_24->f_5a = -10;
						} else {
							lolo.bp_24->f_5a = 2;
						}
					break;
				}//end switch
				if(lolo.bp_24->f_98 < lolo.bp_24->f_00 && lolo.bp_24->f_06 != 2) {//else 00774315
					if(lolo.bp_24->f_9a)
						lolo.bp_24->f_48 = 50;
					if(lolo.bp_24->f_48)
						D_00E710E8 = -1;
					lolo.bp_24->f_7c = (lolo.bp_24->f_7c * 7 + lolo.bp_24->f_96) / 8;
				}
			}
			lolo.bp_24->f_4a = (lolo.bp_24->f_4a + lolo.bp_24->f_7c) / 2;
		} else {
			//============
			//== MANUAL ==
			//============
			if(lolo.bp_24->f_98 < lolo.bp_24->f_00 && lolo.bp_24->f_48)
				D_00E710E8 = -1;
			if(lolo.bp_24->dwStamina > 0 && lolo.bp_24->f_7e == 0) {
				//-- speed up --
				if(D_00E71620 & BIT(CH_KEY_SWITCH))
					lolo.bp_24->f_5a = 2;
				//-- speed down --
				if(D_00E71620 & BIT(CH_KEY_CANCEL))
					lolo.bp_24->f_5a = -2;
				//-- dash --
				if(D_00E71620 & BIT(CH_KEY_OK)) {
					if(lolo.bp_24->dwStamina > 0)
						lolo.bp_24->f_48 = 2;
				}
			}
		}
		//==   ==
		//=======
		if((rand() & 0x3f) < lolo.bp_24->f_62 && lolo.bp_24->f_48 == 0) {//else 007744C9
			lolo.bp_24->f_4e += (lolo.bp_24->f_4e * lolo.bp_24->f_5a) / 100;
			lolo.bp_28 = (lolo.bp_24->f_56 * 5) / 4;
			if(lolo.bp_24->f_4e > lolo.bp_28)
				lolo.bp_24->f_4e = lolo.bp_28;
			if(lolo.bp_24->dwStamina < 0)
				lolo.bp_24->f_4e = lolo.bp_24->f_56;
			if(lolo.bp_24->f_4e > lolo.bp_24->f_56)
				lolo.bp_24->dwStamina -= (lolo.bp_24->f_4e - lolo.bp_24->f_56) / 0x80;
			if(lolo.bp_24->f_5a > 0)
				lolo.bp_24->f_5a --;
			else if(lolo.bp_24->f_5a < 0)
				lolo.bp_24->f_5a ++;
		}
		if(lolo.bp_24->f_48) {//else 00774590
			lolo.bp_24->f_48 --;
			if(lolo.bp_24->f_48 < 0)
				lolo.bp_24->f_48 = 0;
			lolo.bp_24->dwStamina -= lolo.bp_24->dwMaxStamina / 300;
			if(lolo.bp_24->dwStamina <= 0) {
				lolo.bp_24->f_48 = 0;
				lolo.bp_24->dwStamina = 0;
			}
			if(lolo.bp_24->f_48 == 0)
				lolo.bp_24->wAnmNum = 0;
			else
				lolo.bp_24->wAnmNum = 1;
			if(lolo.bp_24->f_a0 && D_00E715D8 < 150)
				lolo.bp_24->f_54 = 5500;
			else
				lolo.bp_24->f_54 = lolo.bp_24->wTopSpeed;
		} else if(lolo.bp_24->f_a2) {
			lolo.bp_24->f_54 = lolo.bp_24->f_56;
		} else {
			lolo.bp_24->f_54 += ((lolo.bp_24->f_4e - lolo.bp_24->f_54) * lolo.bp_24->f_5e) / 100;
		}
		if(lolo.bp_24->f_82 > 1 && lolo.bp_24->f_4c == 1)
			lolo.bp_24->f_54 = (lolo.bp_24->f_54 * 9) / 0xa;
		//==============
		//== POSITION ==
		if(!lolo.bp_24->wIsAutomatic && D_00E71128) {//else 00774787
			//============
			//== MANUAL ==
			//============
			if((rand() & 0x3f) < lolo.bp_24->f_62) {//else 007746B8
				if(D_00E71620 & BIT(CH_KEY_LEFT))
					lolo.bp_24->f_7c += lolo.bp_24->f_66 + lolo.bp_24->f_62 / 0x20;
				if(D_00E71620 & BIT(CH_KEY_RIGHT))
					lolo.bp_24->f_7c -= lolo.bp_24->f_66 + lolo.bp_24->f_62 / 0x20;
			}
			//-- --
			if((D_00E71620 & 0xffff) && lolo.bp_24->f_62 < (rand() & 0x1f)) {//else 00774782
				lolo.bp_28 = 25 - lolo.bp_24->f_62 / 2;
				lolo.bp_24->f_7c += ((rand() & 3) - 1) * lolo.bp_28;
				if(lolo.bp_24->dwStamina > 0 && (rand() & 7) == 0) {//else 00774782
					lolo.bp_24->dwStamina -= lolo.bp_24->dwMaxStamina / 500;
					if(lolo.bp_24->f_4c == 2)
						lolo.bp_24->f_48 = 10;
					else
						lolo.bp_24->f_04 -= lolo.bp_24->f_04 / 4;
				}
			}
			//goto 007748FA
		} else {
			//===============
			//== AUTOMATIC ==
			//===============
			lolo.bp_28 = D_00E7112C->pGUIDE[lolo.bp_24->f_00].f_00[lolo.bp_24->f_52];
			lolo.bp_28 -= lolo.bp_24->f_7c;
			if(lolo.bp_28 < 0) {
				if(-lolo.bp_28 > lolo.bp_24->f_66)
					lolo.bp_28 = -lolo.bp_24->f_66 + lolo.bp_24->f_50;
			} else if(lolo.bp_28 > lolo.bp_24->f_66) {
				lolo.bp_28 = lolo.bp_24->f_66 + lolo.bp_24->f_50;
			}
			for(lolo.bp_30 = 0; lolo.bp_30 < 6; lolo.bp_30 ++) {
				if(lolo.bp_30 == bp08)
					continue;
				lolo.bp_34 = lolo.bp_24->f_00 - D_00E71158[lolo.bp_30].f_00;
				lolo.bp_34 = (lolo.bp_34 < 0)?-lolo.bp_34:lolo.bp_34;
				if(lolo.bp_34 < 20) {//else 007748E3
					lolo.bp_34 = lolo.bp_24->f_7c - D_00E71158[lolo.bp_30].f_7c;
					lolo.bp_34 = (lolo.bp_34 < 0)?-lolo.bp_34:lolo.bp_34;
					if((lolo.bp_34 < 0x10 && (rand() & 0x1f) == 0) || lolo.bp_24->f_7e)
						lolo.bp_28 += ((rand() & 7) - 3) * 0x10;
				}
			}
			lolo.bp_24->f_7c += lolo.bp_28;
		}
		//==  ==
		//======
		if(lolo.bp_24->f_7e == 0) {//else 007749B1
			lolo.bp_24->f_04 = (D_00E7112C->pGUIDE[lolo.bp_24->f_00].f_04[lolo.bp_24->f_52] * lolo.bp_24->f_54) / 0x400 + lolo.bp_24->f_54;
			if(lolo.bp_24->dwStamina <= 5) {
				lolo.bp_24->f_04 = lolo.bp_24->f_04 - lolo.bp_24->f_04 / 4;
				lolo.bp_24->wAnmNum = 5;
			} else if(D_00E72EEC == bp08) {
				lolo.bp_24->f_04 += lolo.bp_24->f_04 / 8;
			}
		}
		if(lolo.bp_24->f_48 == 0 && lolo.bp_24->f_82 < 3) {//else 00774A59
			if(lolo.bp_24->f_06 != 2) {//else 00774A1D
				if(lolo.bp_24->f_00 < lolo.bp_24->f_98)
					lolo.bp_24->f_04 -= lolo.bp_24->f_04 / (lolo.bp_24->f_82 + 7);
			} else {
				if(lolo.bp_24->f_00 < lolo.bp_24->f_98)
					lolo.bp_24->f_04 -= lolo.bp_24->f_04 / (lolo.bp_24->f_82 + 8);
			}
		}
		lolo.bp_28 = lolo.bp_24->f_86 & D_00E715FC[lolo.bp_24->f_00].f_13;
		if(lolo.bp_28)
			lolo.bp_24->f_04 -= (lolo.bp_24->f_04 * lolo.bp_28) / 4;
		if(lolo.bp_24->f_7c > 0xd8)
			lolo.bp_24->f_7c = 0xd8;
		else if(lolo.bp_24->f_7c < 0x30)
			lolo.bp_24->f_7c = 0x30;
		lolo.bp_90 = 0x100 - lolo.bp_24->f_7c;
		lolo.bp_94 = lolo.bp_24->f_02;

		lolo.bp_24->f_28.f_00 = (D_00E715FC[lolo.bp_94].f_00.f_00 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_94].f_08.f_00 * lolo.bp_90) / 0x100;
		lolo.bp_24->f_28.f_02 = (D_00E715FC[lolo.bp_94].f_00.f_02 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_94].f_08.f_02 * lolo.bp_90) / 0x100;
		lolo.bp_24->f_28.f_04 = (D_00E715FC[lolo.bp_94].f_00.f_04 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_94].f_08.f_04 * lolo.bp_90) / 0x100;

		lolo.bp_94 = (lolo.bp_24->f_02 + 1) % D_00E710E4;

		lolo.bp_7c.f_00 = (D_00E715FC[lolo.bp_94].f_00.f_00 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_94].f_08.f_00 * lolo.bp_90) / 0x100;
		lolo.bp_7c.f_04 = (D_00E715FC[lolo.bp_94].f_00.f_02 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_94].f_08.f_02 * lolo.bp_90) / 0x100;
		lolo.bp_7c.f_08 = (D_00E715FC[lolo.bp_94].f_00.f_04 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_94].f_08.f_04 * lolo.bp_90) / 0x100;

		lolo.bp_8c.f_00 = lolo.bp_7c.f_00 - lolo.bp_24->f_10.f_00;
		lolo.bp_8c.f_04 = 0;
		lolo.bp_8c.f_08 = lolo.bp_7c.f_08 - lolo.bp_24->f_10.f_04;
		psx_VectorNormal(&lolo.bp_8c, &lolo.bp_8c);
		lolo.bp_24->f_38.f_02 = C_0077CF40(lolo.bp_8c.f_00, lolo.bp_8c.f_08);//chocobo:some atan2?
		//-- set new camera info --
		lolo.bp_50 = D_00E715FC[lolo.bp_24->f_00].f_10;
		if(lolo.bp_50) {
			C_00771697(lolo.bp_50, bp08);//chocobo:set camera info?
			D_00E715FC[lolo.bp_24->f_00 - 1].f_10 = 0;
			D_00E715FC[lolo.bp_24->f_00].f_10 = 0;
			D_00E715FC[lolo.bp_24->f_00 + 1].f_10 = 0;
		}
		//-- --
		lolo.bp_50 = D_00E715FC[lolo.bp_24->f_00].f_08.f_06;
		if(lolo.bp_50)
			C_007722F6(lolo.bp_50);//set animation increment?
		//goto 007750B3
	} else {
		lolo.bp_54 = 0x100 - lolo.bp_24->f_7c;
		lolo.bp_24->f_84 ++;
		if(lolo.bp_24->f_84 > 0xf && D_00E710F8 && lolo.bp_24->f_7e == 0) {//else 007750B3
			lolo.bp_24->f_00 += 2;
			lolo.bp_24->f_02 += 2;

			lolo.bp_24->f_10.f_00 = (D_00E715FC[lolo.bp_24->f_00].f_00.f_00 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_24->f_00].f_08.f_00 * lolo.bp_54) / 0x100;
			lolo.bp_24->f_10.f_02 = (D_00E715FC[lolo.bp_24->f_00].f_00.f_02 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_24->f_00].f_08.f_02 * lolo.bp_54) / 0x100;
			lolo.bp_24->f_10.f_04 = (D_00E715FC[lolo.bp_24->f_00].f_00.f_04 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_24->f_00].f_08.f_04 * lolo.bp_54) / 0x100;

			lolo.bp_24->f_28.f_00 = (D_00E715FC[lolo.bp_24->f_02].f_00.f_00 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_24->f_02].f_08.f_00 * lolo.bp_54) / 0x100;
			lolo.bp_24->f_28.f_02 = (D_00E715FC[lolo.bp_24->f_02].f_00.f_02 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_24->f_02].f_08.f_02 * lolo.bp_54) / 0x100;
			lolo.bp_24->f_28.f_04 = (D_00E715FC[lolo.bp_24->f_02].f_00.f_04 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_24->f_02].f_08.f_04 * lolo.bp_54) / 0x100;

			lolo.bp_24->f_04 = lolo.bp_24->f_54 = lolo.bp_24->f_4e = lolo.bp_24->f_56;
			lolo.bp_24->f_84 = 0;

			lolo.bp_64.f_00 = lolo.bp_24->f_28.f_00 - lolo.bp_24->f_10.f_00;
			lolo.bp_64.f_04 = 0;
			lolo.bp_64.f_08 = lolo.bp_24->f_28.f_04 - lolo.bp_24->f_10.f_04;
			psx_VectorNormal(&lolo.bp_64, &lolo.bp_64);
			lolo.bp_24->f_30.f_02 = lolo.bp_24->f_38.f_02 = C_0077CF40(lolo.bp_64.f_00, lolo.bp_64.f_08);//chocobo:some atan2?
		}
	}
	if(lolo.bp_24->f_00 > D_00E710E4 - 10 && lolo.bp_24->f_7e == 0) {//else 00775238
		lolo.bp_24->f_7e = -1;
		lolo.bp_24->f_28.f_00 = lolo.bp_24->f_40.f_00;
		lolo.bp_24->f_28.f_02 = lolo.bp_24->f_40.f_02;
		lolo.bp_24->f_28.f_04 = lolo.bp_24->f_40.f_04;
		lolo.bp_6c = 1;
		for(lolo.bp_68 = 0; lolo.bp_68 < 6; lolo.bp_68 ++) {
			if(D_00E71158[lolo.bp_68].f_70 >= lolo.bp_6c)
				lolo.bp_6c = D_00E71158[lolo.bp_68].f_70 + 1;
		}
		lolo.bp_24->f_70 = lolo.bp_6c;
		if(lolo.bp_6c == 1) {
			D_00E71134 = bp08;
			if(D_00E71128 == 0) {
				D_00E71664->f_00 = 0x10;
				D_00E71664->f_04[0] = 0x3b;
				C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);
			}
		}
		if(lolo.bp_6c == 2)
			D_00E71038 = -1;
		if(D_00E71128 && bp08 == 0) {//else 00775238
			if(D_00E71158[0].f_70 == 1)
				D_00E71664->f_04[0] = 0x3b;
			else
				D_00E71664->f_04[0] = 60;
			D_00E71664->f_00 = 0x10;
			C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);
		}
	}
	if(lolo.bp_24->f_30.f_02 - lolo.bp_24->f_38.f_02 > 3000)
		lolo.bp_24->f_30.f_02 -= 0x1000;
	if(lolo.bp_24->f_30.f_02 - lolo.bp_24->f_38.f_02 < -3000)
		lolo.bp_24->f_30.f_02 += 0x1000;
	lolo.bp_24->f_30.f_02 = (lolo.bp_24->f_30.f_02 * 3 + lolo.bp_24->f_38.f_02) / 4;
	if(lolo.bp_2c) {//else 0077537B
		lolo.bp_24->f_18 += (psx_rsin(lolo.bp_24->f_30.f_02) * lolo.bp_2c) / 0x40;
		lolo.bp_24->f_20 += (-psx_rcos(lolo.bp_24->f_30.f_02) * lolo.bp_2c) / 0x40;
		lolo.bp_24->f_10.f_00 += lolo.bp_24->f_18 / 0x1000;
		lolo.bp_24->f_10.f_04 += lolo.bp_24->f_20 / 0x1000;
		lolo.bp_24->f_18 &= 0x80000fff;
		lolo.bp_24->f_20 &= 0x80000fff;
	}
	lolo.bp_10.f_00 = D_00E715FC[lolo.bp_24->f_02].f_08.f_00 - D_00E715FC[lolo.bp_24->f_02].f_00.f_00;
	lolo.bp_10.f_04 = D_00E715FC[lolo.bp_24->f_02].f_08.f_02 - D_00E715FC[lolo.bp_24->f_02].f_00.f_02;
	lolo.bp_10.f_08 = D_00E715FC[lolo.bp_24->f_02].f_08.f_04 - D_00E715FC[lolo.bp_24->f_02].f_00.f_04;

	lolo.bp_20.f_00 = D_00E715FC[lolo.bp_24->f_02].f_00.f_00 - D_00E715FC[lolo.bp_24->f_00].f_00.f_00;
	lolo.bp_20.f_04 = D_00E715FC[lolo.bp_24->f_02].f_00.f_02 - D_00E715FC[lolo.bp_24->f_00].f_00.f_02;
	lolo.bp_20.f_08 = D_00E715FC[lolo.bp_24->f_02].f_00.f_04 - D_00E715FC[lolo.bp_24->f_00].f_00.f_04;
	psx_OuterProduct12(&lolo.bp_20, &lolo.bp_10, &lolo.bp_48);
	if(lolo.bp_48.f_04)
		lolo.bp_28 = (
			(D_00E715FC[lolo.bp_24->f_00].f_00.f_00 - lolo.bp_24->f_10.f_00) * lolo.bp_48.f_00 +
			(D_00E715FC[lolo.bp_24->f_00].f_00.f_04 - lolo.bp_24->f_10.f_04) * lolo.bp_48.f_08 +
			lolo.bp_48.f_04 * D_00E715FC[lolo.bp_24->f_00].f_00.f_02
		) / lolo.bp_48.f_04;
	else
		lolo.bp_28 = lolo.bp_24->f_10.f_02;
	lolo.bp_24->f_0a = lolo.bp_24->f_10.f_02 = (lolo.bp_24->f_0a + lolo.bp_28) / 2;
}

void C_0077554D(int bp08) {
	struct {
		int local_7;
		struct t_chocobo_a4 *local_6;
		struct VECTOR local_5;
		struct t_chocobo_a4 *local_1;
	}lolo;

	if(D_00E715DC == bp08)
		return;
	D_00E715DC = bp08;
	lolo.local_6 = &D_00E71530;
	lolo.local_1 = &(D_00E71158[bp08]);
	*lolo.local_6 = *lolo.local_1;
	lolo.local_6->f_7c = 0x7f;
	lolo.local_7 = 0x100 - lolo.local_6->f_7c;
	lolo.local_6->f_10.f_00 = (D_00E715FC[lolo.local_6->f_00].f_00.f_00 * lolo.local_6->f_7c + D_00E715FC[lolo.local_6->f_00].f_08.f_00 * lolo.local_7) / 0x100;
	lolo.local_6->f_10.f_02 = (D_00E715FC[lolo.local_6->f_00].f_00.f_02 * lolo.local_6->f_7c + D_00E715FC[lolo.local_6->f_00].f_08.f_02 * lolo.local_7) / 0x100;
	lolo.local_6->f_10.f_04 = (D_00E715FC[lolo.local_6->f_00].f_00.f_04 * lolo.local_6->f_7c + D_00E715FC[lolo.local_6->f_00].f_08.f_04 * lolo.local_7) / 0x100;

	lolo.local_6->f_28.f_00 = (D_00E715FC[lolo.local_6->f_02].f_00.f_00 * lolo.local_6->f_7c + D_00E715FC[lolo.local_6->f_02].f_08.f_00 * lolo.local_7) / 0x100;
	lolo.local_6->f_28.f_02 = (D_00E715FC[lolo.local_6->f_02].f_00.f_02 * lolo.local_6->f_7c + D_00E715FC[lolo.local_6->f_02].f_08.f_02 * lolo.local_7) / 0x100;
	lolo.local_6->f_28.f_04 = (D_00E715FC[lolo.local_6->f_02].f_00.f_04 * lolo.local_6->f_7c + D_00E715FC[lolo.local_6->f_02].f_08.f_04 * lolo.local_7) / 0x100;

	lolo.local_5.f_00 = lolo.local_6->f_28.f_00 - lolo.local_6->f_10.f_00;
	lolo.local_5.f_04 = 0;
	lolo.local_5.f_08 = lolo.local_6->f_28.f_04 - lolo.local_6->f_10.f_04;
	psx_VectorNormal(&lolo.local_5, &lolo.local_5);
	lolo.local_6->f_38.f_02 = C_0077CF40(lolo.local_5.f_00, lolo.local_5.f_08);//chocobo:some atan2?
}

void C_007757CE(int bp08, int bp0c, int bp10) {
	struct {
		int local_7;
		struct t_chocobo_a4 *local_6;
		struct VECTOR local_5;
		int local_1;
	}lolo;

	D_00E715DC = bp08;
	lolo.local_6 = &D_00E71530;
	*lolo.local_6 = D_00E71158[bp08];
	lolo.local_1 = (bp10 + 1 + D_00E710E4) % D_00E710E4;
	lolo.local_6->f_02 = lolo.local_1;
	lolo.local_6->f_00 = bp10;
	lolo.local_6->f_7c = 0x7f;
	lolo.local_7 = 0x100 - lolo.local_6->f_7c;
	lolo.local_6->f_04 = bp0c;

	lolo.local_6->f_10.f_00 = (D_00E715FC[bp10].f_00.f_00 * lolo.local_6->f_7c + D_00E715FC[bp10].f_08.f_00 * lolo.local_7) / 0x100;
	lolo.local_6->f_10.f_02 = (D_00E715FC[bp10].f_00.f_02 * lolo.local_6->f_7c + D_00E715FC[bp10].f_08.f_02 * lolo.local_7) / 0x100;
	lolo.local_6->f_10.f_04 = (D_00E715FC[bp10].f_00.f_04 * lolo.local_6->f_7c + D_00E715FC[bp10].f_08.f_04 * lolo.local_7) / 0x100;

	lolo.local_6->f_28.f_00 = (D_00E715FC[lolo.local_1].f_00.f_00 * lolo.local_6->f_7c + D_00E715FC[lolo.local_1].f_08.f_00 * lolo.local_7) / 0x100;
	lolo.local_6->f_28.f_02 = (D_00E715FC[lolo.local_1].f_00.f_02 * lolo.local_6->f_7c + D_00E715FC[lolo.local_1].f_08.f_02 * lolo.local_7) / 0x100;
	lolo.local_6->f_28.f_04 = (D_00E715FC[lolo.local_1].f_00.f_04 * lolo.local_6->f_7c + D_00E715FC[lolo.local_1].f_08.f_04 * lolo.local_7) / 0x100;

	lolo.local_5.f_00 = lolo.local_6->f_28.f_00 - lolo.local_6->f_10.f_00;
	lolo.local_5.f_04 = 0;
	lolo.local_5.f_08 = lolo.local_6->f_28.f_04 - lolo.local_6->f_10.f_04;
	psx_VectorNormal(&lolo.local_5, &lolo.local_5);
	lolo.local_6->f_38.f_02 = C_0077CF40(lolo.local_5.f_00, lolo.local_5.f_08);//chocobo:some atan2?
}

void C_00775A45(int bp08) {
	struct {
		int bp_7c;
		int bp_78;
		struct VECTOR bp_74;
		struct VECTOR bp_64;
		char _p_54[4];
		int bp_50;
		int bp_4c;
		struct SVECTOR *bp_48;//local_18
		struct VECTOR bp_44;
		struct SVECTOR *bp_34;//local_13
		int bp_30;
		int bp_2c;//local_11
		int bp_28;//local_10
		struct t_chocobo_a4 *bp_24;//local_9
		struct VECTOR bp_20,bp_10;//local_8,local_4
	}lolo;

	lolo.bp_24 = &D_00E71530;
	lolo.bp_34 = &(D_00E715FC[lolo.bp_24->f_02].f_00);
	lolo.bp_48 = &(D_00E715FC[lolo.bp_24->f_02].f_08);

	lolo.bp_10.f_00 = lolo.bp_48->f_00 - lolo.bp_34->f_00;
	lolo.bp_10.f_04 = 0;
	lolo.bp_10.f_08 = lolo.bp_48->f_04 - lolo.bp_34->f_04;

	lolo.bp_20.f_00 = lolo.bp_24->f_10.f_00 - lolo.bp_34->f_00;
	lolo.bp_20.f_04 = 0;
	lolo.bp_20.f_08 = lolo.bp_24->f_10.f_04 - lolo.bp_34->f_04;
	psx_OuterProduct12(&lolo.bp_10, &lolo.bp_20, &lolo.bp_10);
	if(lolo.bp_10.f_04 >= 0) {//else 00775F25
		lolo.bp_24->f_84 = 0;
		lolo.bp_2c = lolo.bp_24->f_00 + 60;
		for(lolo.bp_28 = lolo.bp_24->f_00; lolo.bp_28 < lolo.bp_2c; lolo.bp_28 ++) {
			lolo.bp_30 = (lolo.bp_28 + D_00E710E4) % D_00E710E4;
			lolo.bp_34 = &(D_00E715FC[lolo.bp_30].f_00);
			lolo.bp_48 = &(D_00E715FC[lolo.bp_30].f_08);

			lolo.bp_10.f_00 = lolo.bp_48->f_00 - lolo.bp_34->f_00;
			lolo.bp_10.f_04 = 0;
			lolo.bp_10.f_08 = lolo.bp_48->f_04 - lolo.bp_34->f_04;

			lolo.bp_20.f_00 = lolo.bp_24->f_10.f_00 - lolo.bp_34->f_00;
			lolo.bp_20.f_04 = 0;
			lolo.bp_20.f_08 = lolo.bp_24->f_10.f_04 - lolo.bp_34->f_04;
			psx_OuterProduct12(&lolo.bp_10, &lolo.bp_20, &lolo.bp_10);
			if(lolo.bp_10.f_04 < 0)
				break;
		}
		lolo.bp_24->f_00 = lolo.bp_24->f_02;
		lolo.bp_24->f_02 = lolo.bp_30 + D_00E710E4;
		lolo.bp_24->f_02 %= D_00E710E4;
		lolo.bp_78 = 0x100 - lolo.bp_24->f_7c;

		lolo.bp_7c = lolo.bp_24->f_02;
		lolo.bp_24->f_28.f_00 = (D_00E715FC[lolo.bp_7c].f_00.f_00 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_7c].f_08.f_00 * lolo.bp_78) / 0x100;
		lolo.bp_24->f_28.f_02 = (D_00E715FC[lolo.bp_7c].f_00.f_02 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_7c].f_08.f_02 * lolo.bp_78) / 0x100;
		lolo.bp_24->f_28.f_04 = (D_00E715FC[lolo.bp_7c].f_00.f_04 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_7c].f_08.f_04 * lolo.bp_78) / 0x100;

		lolo.bp_7c = (lolo.bp_24->f_02 + 1) % D_00E710E4;
		lolo.bp_64.f_00 = (D_00E715FC[lolo.bp_7c].f_00.f_00 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_7c].f_08.f_00 * lolo.bp_78) / 0x100;
		lolo.bp_64.f_04 = (D_00E715FC[lolo.bp_7c].f_00.f_02 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_7c].f_08.f_02 * lolo.bp_78) / 0x100;
		lolo.bp_64.f_08 = (D_00E715FC[lolo.bp_7c].f_00.f_04 * lolo.bp_24->f_7c + D_00E715FC[lolo.bp_7c].f_08.f_04 * lolo.bp_78) / 0x100;

		lolo.bp_74.f_00 = lolo.bp_64.f_00 - lolo.bp_24->f_10.f_00;
		lolo.bp_74.f_04 = 0;
		lolo.bp_74.f_08 = lolo.bp_64.f_08 - lolo.bp_24->f_10.f_04;
		psx_VectorNormal(&lolo.bp_74, &lolo.bp_74);
		lolo.bp_24->f_38.f_02 = C_0077CF40(lolo.bp_74.f_00, lolo.bp_74.f_08);//chocobo:some atan2?
		//-- --
		lolo.bp_4c = D_00E715FC[lolo.bp_24->f_00].f_08.f_06;
		if(lolo.bp_4c)
			C_007722F6(lolo.bp_4c);//set animation increment?
		//-- sound events --
		if(D_00E71128) {//else 00775F25
			lolo.bp_4c = D_00E715FC[lolo.bp_24->f_00].f_00.f_06;
			if(lolo.bp_4c) {//else 00775F25
				lolo.bp_4c --;
				D_00E71664->f_00 = D_00E7112C->pSoundEvent[lolo.bp_4c].f_00;
				for(lolo.bp_50 = 0; lolo.bp_50 < 6; lolo.bp_50 ++)
					D_00E71664->f_04[lolo.bp_50] = D_00E7112C->pSoundEvent[lolo.bp_4c].f_02[lolo.bp_50];
				C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], D_00E71664->f_04[1], D_00E71664->f_04[2], D_00E71664->f_04[3], D_00E71664->f_04[4], D_00E71664->f_04[5], 0, 0);
			}
		}
		//-- --
	}
	if(lolo.bp_24->f_30.f_02 - lolo.bp_24->f_38.f_02 > 3000)
		lolo.bp_24->f_30.f_02 -= 0x1000;
	if(lolo.bp_24->f_30.f_02 - lolo.bp_24->f_38.f_02 < -3000)
		lolo.bp_24->f_30.f_02 += 0x1000;
	lolo.bp_24->f_30.f_02 = (lolo.bp_24->f_30.f_02 * 7 + lolo.bp_24->f_38.f_02) / 8;

	lolo.bp_24->f_18 += (psx_rsin(lolo.bp_24->f_30.f_02) * lolo.bp_24->f_04) / 0x40;
	lolo.bp_24->f_20 += (-psx_rcos(lolo.bp_24->f_30.f_02) * lolo.bp_24->f_04) / 0x40;
	lolo.bp_24->f_10.f_00 += lolo.bp_24->f_18 / 0x1000;
	lolo.bp_24->f_10.f_04 += lolo.bp_24->f_20 / 0x1000;
	lolo.bp_24->f_18 &= 0x80000fff;
	lolo.bp_24->f_20 &= 0x80000fff;

	lolo.bp_10.f_00 = D_00E715FC[lolo.bp_24->f_02].f_08.f_00 - D_00E715FC[lolo.bp_24->f_02].f_00.f_00;
	lolo.bp_10.f_04 = D_00E715FC[lolo.bp_24->f_02].f_08.f_02 - D_00E715FC[lolo.bp_24->f_02].f_00.f_02;
	lolo.bp_10.f_08 = D_00E715FC[lolo.bp_24->f_02].f_08.f_04 - D_00E715FC[lolo.bp_24->f_02].f_00.f_04;

	lolo.bp_20.f_00 = D_00E715FC[lolo.bp_24->f_02].f_00.f_00 - D_00E715FC[lolo.bp_24->f_00].f_00.f_00;
	lolo.bp_20.f_04 = D_00E715FC[lolo.bp_24->f_02].f_00.f_02 - D_00E715FC[lolo.bp_24->f_00].f_00.f_02;
	lolo.bp_20.f_08 = D_00E715FC[lolo.bp_24->f_02].f_00.f_04 - D_00E715FC[lolo.bp_24->f_00].f_00.f_04;
	psx_OuterProduct12(&lolo.bp_20, &lolo.bp_10, &lolo.bp_44);
	if(lolo.bp_44.f_04) {//else 007762A3
		lolo.bp_28 = (
			(D_00E715FC[D_00E71158[D_00E71624].f_00].f_00.f_00 - lolo.bp_24->f_10.f_00) * lolo.bp_44.f_00 +
			(D_00E715FC[D_00E71158[D_00E71624].f_00].f_00.f_04 - lolo.bp_24->f_10.f_04) * lolo.bp_44.f_08 + 
			lolo.bp_44.f_04 * D_00E715FC[D_00E71158[D_00E71624].f_00].f_00.f_02
		) / lolo.bp_44.f_04;
		D_00E3BAF4 = (D_00E3BAF4 * 7 + lolo.bp_28) / 8;
		lolo.bp_28 = (
			(D_00E715FC[lolo.bp_24->f_00].f_00.f_00 - lolo.bp_24->f_10.f_00) * lolo.bp_44.f_00 +
			(D_00E715FC[lolo.bp_24->f_00].f_00.f_04 - lolo.bp_24->f_10.f_04) * lolo.bp_44.f_08 + 
			lolo.bp_44.f_04 * D_00E715FC[lolo.bp_24->f_00].f_00.f_02
		) / lolo.bp_44.f_04;
	} else {
		lolo.bp_28 = lolo.bp_24->f_10.f_02;
	}
	lolo.bp_24->f_0a = lolo.bp_24->f_10.f_02 = (lolo.bp_24->f_0a + lolo.bp_28) / 2;
	if(bp08 && D_00E710F8) {//else 00776362
		lolo.bp_30 = D_00E71158[D_00E71624].f_00 - lolo.bp_24->f_00;
		lolo.bp_24->f_04 = D_00E71158[D_00E71624].f_04;
		if(D_00E71158[D_00E71624].f_7e == 0) {//else 00776362
			if(lolo.bp_30 < 1)
				lolo.bp_24->f_04 = 0;
			else if(lolo.bp_30 > 2)
				lolo.bp_24->f_04 += lolo.bp_30 * 150;
		}
	}
}

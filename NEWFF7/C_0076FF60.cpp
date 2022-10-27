/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- terrain/scenery?

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
int D_00971D08[] = {
	0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,
	0x6E,0x6F,0x70,0x71,0x72,0x73,0x86,0x87,
	0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
	0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,
	0x98,0x99,0x9A,0x9B,0xBF,0xC0,0xC1,0xC2,
	0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,
	0xCB,0xCC,0xCD,0xCE,0xCF
};
//00 00 00 00
////////////////////////////////////////
extern int D_00E70FE8;
extern struct t_chocobo_data_18 *D_00E715FC;
extern struct t_chocobo_unknown_54 D_00E71C60[];
extern int *D_00E72980;
extern int D_00E72988;
////////////////////////////////////////
//chocobo:init this module
void C_0076FF60(struct t_aa0 *bp08, struct t_rsd_74 *bp0c) {
	//-- SOLID --
	C_006745E6(4, bp0c);//rsd:init with blend mode?
	bp0c->f_2c |= 2;//LH/RH related?

	D_00E71BD4.f_00 = C_006710AC(1, DX_SFX_TYPE_02, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71BD4.f_10 = 1;
	D_00E71BD4.f_14 = 0;
	D_00E71BD4.dwIsTransparent = 0;

	D_00E71C28.f_00 = C_006710AC(1, DX_SFX_TYPE_02, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71C28.f_10 = 1;
	D_00E71C28.f_14 = 0;
	D_00E71C28.dwIsTransparent = 0;

	D_00E71BF0.f_00 = C_006710AC(1, DX_SFX_TYPE_0A, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71BF0.f_10 = 1;
	D_00E71BF0.f_14 = 0;
	D_00E71BF0.dwIsTransparent = 0;
	//-- TRANSPARENT --
	C_006745E6(1, bp0c);//rsd:init with blend mode?
	bp0c->f_2c |= 2;//LH/RH related?

	D_00E71C44.f_00 = C_006710AC(1, DX_SFX_TYPE_02, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71C44.f_10 = 1;
	D_00E71C44.f_14 = 0;
	D_00E71C44.dwIsTransparent = 1;

	D_00E71C0C.f_00 = C_006710AC(1, DX_SFX_TYPE_0A, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71C0C.f_10 = 1;
	D_00E71C0C.f_14 = 0;
	D_00E71C0C.dwIsTransparent = 1;
	//-- --
}

//chocobo:clean this module
void C_007700D9() {
	//-- SOLID --
	C_00670FD3(D_00E71BD4.f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71BD4.f_00 = 0;
	C_00670FD3(D_00E71C28.f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71C28.f_00 = 0;
	C_00670FD3(D_00E71BF0.f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71BF0.f_00 = 0;
	//-- TRANSPARENT --
	C_00670FD3(D_00E71C44.f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71C44.f_00 = 0;
	C_00670FD3(D_00E71C0C.f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71C0C.f_00 = 0;
	//-- --
}

//chocobo:render this module
void C_00770159() {
	//-- SOLID --
	if(D_00E71BD4.f_14) {
		C_006716F5(D_00E71BD4.f_00);//dx_sfx:reset something?
		D_00E71BD4.f_14 = 0;
	}
	if(D_00E71C28.f_14) {
		C_006716F5(D_00E71C28.f_00);//dx_sfx:reset something?
		D_00E71C28.f_14 = 0;
	}
	if(D_00E71BF0.f_14) {
		C_006716F5(D_00E71BF0.f_00);//dx_sfx:reset something?
		D_00E71BF0.f_14 = 0;
	}
	//-- TRANSPARENT --
	if(D_00E71C44.f_14) {
		C_006716F5(D_00E71C44.f_00);//dx_sfx:reset something?
		D_00E71C44.f_14 = 0;
	}
	if(D_00E71C0C.f_14) {
		C_006716F5(D_00E71C0C.f_00);//dx_sfx:reset something?
		D_00E71C0C.f_14 = 0;
	}
	//-- --
}

//render skydome
void C_00770206() {
	struct {
		struct t_chocobo_data_floatDG3 *local_3;
		struct t_chocobo_data_DOMEG3 *local_2;
		int i;//local_1
	}lolo;

	D_00E72988 = 1;
	for(lolo.i = 0; lolo.i < D_00E7112C->wNumDOMEG3; lolo.i ++) {
		lolo.local_2 = &(D_00E7112C->pDOMEG3[lolo.i]);
		lolo.local_3 = &(D_00E7112C->pFloatDOMEG3[lolo.i]);
		C_0077BB50(&D_00E72E60, D_00E71BD4.f_00, lolo.local_3);//render triangle?
	}//end for
	D_00E71BD4.f_14 = 1;
	D_00E72988 = 0;
}

void C_00770305(int, int);

//render track/scenery?
void C_00770291() {
	struct {
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	D_00E71108 = 0;
	lolo.local_1 = D_00E7112C->f_00;
	lolo.local_3 = (D_00E71124 + lolo.local_1) % lolo.local_1;
	lolo.local_2 = (D_00E70FE8 + lolo.local_1) % lolo.local_1;
	if(lolo.local_3 > lolo.local_2) {
		C_00770305(0, lolo.local_2);
		C_00770305(lolo.local_3, lolo.local_1);
	} else {
		C_00770305(lolo.local_3, lolo.local_2);
	}
}

int C_00770434(LPD3DMATRIX, short, int);//"SPRITE"
int C_007706D7(LPD3DMATRIX, int, int, int);//"DG4"
int C_00770767(LPD3DMATRIX, int, int, int);//"DG3"

void C_00770305(int bp08, int bp0c) {
	struct {
		int local_7;
		int dwNumPoly;//local_6
		int local_5;
		int *pMAPTABLE;//local_4
		int dwNumChunks;//local_3
		short wMAPPOINTER; char _ocal_2[2];//local_2
		int local_1;
	}lolo;

	lolo.local_5 = bp08;
	lolo.dwNumChunks = bp0c - bp08;
	lolo.dwNumPoly = D_00E71108;
	lolo.wMAPPOINTER = D_00E7112C->pMAPPOINTER[bp08];
	lolo.pMAPTABLE = &(D_00E7112C->pMAPTABLE[lolo.wMAPPOINTER]);
	for(;;) {
		lolo.local_7 = *lolo.pMAPTABLE;
		if(lolo.local_7 == -1)
			break;
		if(lolo.local_7 < 0) {//else 00770399
			lolo.dwNumChunks --;
			if(lolo.dwNumChunks < 0)
				break;
			lolo.local_5 ++;
			lolo.local_1 = D_00E715FC[lolo.local_5].f_13 & 0x80;
		}
		switch(((char *)&(lolo.local_7))[2]) {
			case 0: lolo.dwNumPoly += C_00770767(&D_00E72E60, (short)lolo.local_7, lolo.dwNumPoly, lolo.local_1); break;//"DG3"
			case 1: lolo.dwNumPoly += C_007706D7(&D_00E72E60, (short)lolo.local_7, lolo.dwNumPoly, lolo.local_1); break;//"DG4"
			case 0x21: lolo.dwNumPoly += C_00770434(&D_00E72E60, (short)lolo.local_7, lolo.dwNumPoly); break;//"SPRITE"
		}
		lolo.pMAPTABLE ++;
	}//end for
	D_00E71108 = lolo.dwNumPoly;
}

int C_00770685(int);//check y flip?

//"SPRITE"
int C_00770434(LPD3DMATRIX bp08, short bp0c, int _p10) {
	struct {
		struct t_chocobo_data_SPRITE pSPRITE; char _ocal_26[2];//local_26
		struct SVECTOR local_20;
		char _ocal_18[0x28];
		struct t_chocobo_unknown_54 *local_8;
		int dwDist;//local_7
		int local_6;
		int dwWidth;//local_5
		int _ocal_4;
		short wNewX; char _ocal_3[2];//local_3
		short local_2[2];
		int local_1;
	}lolo;

	lolo.pSPRITE = D_00E7112C->pSPRITE[bp0c];
	lolo.local_8 = &(D_00E71C60[D_00E72980[bp0c]]);
	lolo.dwDist = psx_RotTransPers(&lolo.pSPRITE.f_00, (int *)&lolo.local_20, &lolo.local_1, &lolo.local_6);
	if(lolo.dwDist > 4000 || lolo.dwDist < 0)
		return 0;
	lolo.local_2[0] = lolo.local_20.f_00;
	lolo.local_2[1] = lolo.local_20.f_02;
	if(lolo.local_2[0] < -40 || lolo.local_2[1] < -40)
		return 0;
	if(lolo.local_2[0] > 350 || lolo.local_2[1] > 270)
		return 0;

	if(lolo.dwDist)//unnecessary:at this point, lolo.dwDist cannot be 0
		lolo.dwWidth = (lolo.pSPRITE.wWidth * 270) / lolo.dwDist;
	lolo.local_2[0] -= lolo.dwWidth / 2;

	lolo.wNewX = lolo.local_2[0] + lolo.dwWidth;
	lolo.local_8->f_04[0].wX = lolo.local_2[0]; lolo.local_8->f_04[0].wY = lolo.local_2[1];
	lolo.local_8->f_04[1].wX = lolo.wNewX;      lolo.local_8->f_04[1].wY = lolo.local_2[1];

	lolo.local_8->f_04[2].wX = lolo.local_2[0];
	lolo.local_8->f_04[3].wX = lolo.wNewX;
	lolo.pSPRITE.f_00.f_02 -= lolo.pSPRITE.wHeight * 4;
	psx_RotTransPers(&lolo.pSPRITE.f_00, (int *)&lolo.local_20, &lolo.local_1, &lolo.local_6);
	lolo.local_8->f_04[2].wY =
	lolo.local_8->f_04[3].wY = lolo.local_20.f_02;

	lolo.local_8->fZ = C_0077C2AC(&lolo.pSPRITE.f_00, bp08);//projected Z?
	if(C_00770685(bp0c + 1)) {//check y flip?
		lolo.local_8->f_14[2].fU = 0.03f; lolo.local_8->f_14[2].fV = 0.03f;
		lolo.local_8->f_14[3].fU = 0.94f; lolo.local_8->f_14[3].fV = 0.03f;
		lolo.local_8->f_14[0].fU = 0.03f; lolo.local_8->f_14[0].fV = 0.94f;
		lolo.local_8->f_14[1].fU = 0.94f; lolo.local_8->f_14[1].fV = 0.94f;
	} else {
		lolo.local_8->f_14[0].fU = 0.03f; lolo.local_8->f_14[0].fV = 0.03f;
		lolo.local_8->f_14[1].fU = 0.94f; lolo.local_8->f_14[1].fV = 0.03f;
		lolo.local_8->f_14[2].fU = 0.03f; lolo.local_8->f_14[2].fV = 0.94f;
		lolo.local_8->f_14[3].fU = 0.94f; lolo.local_8->f_14[3].fV = 0.94f;
	}
	C_0077AD89(lolo.local_8);

	return 1;
}

//check y flip?
int C_00770685(int bp08) {
	int i;//local_1

	if(D_00E3B74C == 0) {
		for(i = 0; i < 0x35; i ++) {
			if(D_00971D08[i] == bp08)
				return 2;
		}//end for
	} else if(bp08 != 0x49) {
		return 2;
	}

	return 0;
}

//"DG4"
int C_007706D7(LPD3DMATRIX bp08, int bp0c, int _p10, int bp14) {
	struct t_chocobo_data_floatDG4 *local_2;
	struct t_chocobo_data_DG4 *local_1;

	local_1 = &(D_00E7112C->pDG4[bp0c]);
	local_2 = &(D_00E7112C->pFloatDG4[bp0c]);
	if(bp14 < 0)
		return 0;
	if(local_1->f_24.c.a == 0x38) {
		//-- SOLID --
		C_0077BE95(bp08, D_00E71BF0.f_00, local_2);//render quad?
		D_00E71BF0.f_14 = 1;
	} else {
		//-- TRANSPARENT --
		C_0077BE95(bp08, D_00E71C0C.f_00, local_2);//render quad?
		D_00E71C0C.f_14 = 1;
	}

	return 1;
}

//"DG3"
int C_00770767(LPD3DMATRIX bp08, int bp0c, int _p10, int bp14) {
	struct t_chocobo_data_floatDG3 *local_2;
	struct t_chocobo_data_DG3 *local_1;

	local_1 = &(D_00E7112C->pDG3[bp0c]);
	local_2 = &(D_00E7112C->pFloatDG3[bp0c]);
	if(bp14 < 0)
		return 0;
	if(local_1->f_18.c.a == 0x30) {
		//-- SOLID --
		C_0077BB50(bp08, D_00E71C28.f_00, local_2);//render triangle?
		D_00E71C28.f_14 = 1;
	} else {
		//-- TRANSPARENT --
		C_0077BB50(bp08, D_00E71C44.f_00, local_2);//render triangle?
		D_00E71C44.f_14 = 1;
	}

	return 1;
}

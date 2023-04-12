/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- terrain/scenery?

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
//-- y flip related --
int D_00971D08[0x35] = {
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
extern struct t_chocobo_data_TrackElement *D_00E715FC;
extern struct t_chocobo_SpriteBillboard D_00E71C60[];//3D sprite/billboard
extern int *D_00E72980;
extern int D_00E72988;//[unused]set to 1 during skydome rendering
////////////////////////////////////////
//chocobo:terrain/scenery.init
void C_0076FF60(struct t_aa0 *bp08, struct t_rsd_74 *bp0c) {
	//-- SOLID --
	C_006745E6(4, bp0c);//rsd:init with blend mode?
	bp0c->f_2c |= 2;//LH/RH related?
	//--skydome
	D_00E71BD4[0].f_00 = C_006710AC(1, DX_SFX_TYPE_02, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71BD4[0].dwActive = 1;
	D_00E71BD4[0].dwDoRender = 0;
	D_00E71BD4[0].dwIsTransparent = 0;
	//--triangles
	D_00E71BD4[3].f_00 = C_006710AC(1, DX_SFX_TYPE_02, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71BD4[3].dwActive = 1;
	D_00E71BD4[3].dwDoRender = 0;
	D_00E71BD4[3].dwIsTransparent = 0;
	//--quads
	D_00E71BD4[1].f_00 = C_006710AC(1, DX_SFX_TYPE_0A, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71BD4[1].dwActive = 1;
	D_00E71BD4[1].dwDoRender = 0;
	D_00E71BD4[1].dwIsTransparent = 0;
	//-- TRANSPARENT --
	C_006745E6(1, bp0c);//rsd:init with blend mode?
	bp0c->f_2c |= 2;//LH/RH related?
	//--triangles
	D_00E71BD4[4].f_00 = C_006710AC(1, DX_SFX_TYPE_02, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71BD4[4].dwActive = 1;
	D_00E71BD4[4].dwDoRender = 0;
	D_00E71BD4[4].dwIsTransparent = 1;
	//--quads
	D_00E71BD4[2].f_00 = C_006710AC(1, DX_SFX_TYPE_0A, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E71BD4[2].dwActive = 1;
	D_00E71BD4[2].dwDoRender = 0;
	D_00E71BD4[2].dwIsTransparent = 1;
	//-- --
}

//chocobo:terrain/scenery.clean
void C_007700D9() {
	//-- SOLID --
	C_00670FD3(D_00E71BD4[0].f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71BD4[0].f_00 = 0;
	C_00670FD3(D_00E71BD4[3].f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71BD4[3].f_00 = 0;
	C_00670FD3(D_00E71BD4[1].f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71BD4[1].f_00 = 0;
	//-- TRANSPARENT --
	C_00670FD3(D_00E71BD4[4].f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71BD4[4].f_00 = 0;
	C_00670FD3(D_00E71BD4[2].f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
	D_00E71BD4[2].f_00 = 0;
	//-- --
}

//chocobo:terrain/scenery.reset
void C_00770159() {
	//-- SOLID --
	if(D_00E71BD4[0].dwDoRender) {
		C_006716F5(D_00E71BD4[0].f_00);//dx_sfx:reset something?
		D_00E71BD4[0].dwDoRender = 0;
	}
	if(D_00E71BD4[3].dwDoRender) {
		C_006716F5(D_00E71BD4[3].f_00);//dx_sfx:reset something?
		D_00E71BD4[3].dwDoRender = 0;
	}
	if(D_00E71BD4[1].dwDoRender) {
		C_006716F5(D_00E71BD4[1].f_00);//dx_sfx:reset something?
		D_00E71BD4[1].dwDoRender = 0;
	}
	//-- TRANSPARENT --
	if(D_00E71BD4[4].dwDoRender) {
		C_006716F5(D_00E71BD4[4].f_00);//dx_sfx:reset something?
		D_00E71BD4[4].dwDoRender = 0;
	}
	if(D_00E71BD4[2].dwDoRender) {
		C_006716F5(D_00E71BD4[2].f_00);//dx_sfx:reset something?
		D_00E71BD4[2].dwDoRender = 0;
	}
	//-- --
}

//chocobo:render skydome
void C_00770206() {
	struct {
		struct t_chocobo_data_floatDG3 *local_3;
		struct t_chocobo_data_DOMEG3 *local_2_unused;
		int i;//local_1
	}lolo;

	D_00E72988 = 1;
	for(lolo.i = 0; lolo.i < D_00E7112C->wCountDOMEG3; lolo.i ++) {
		lolo.local_2_unused = &(D_00E7112C->pDOMEG3[lolo.i]);
		lolo.local_3 = &(D_00E7112C->pFloatDOMEG3[lolo.i]);
		C_0077BB50(&D_00E72E60, D_00E71BD4[0].f_00, lolo.local_3);//chocobo:draw triangle[3D]
	}//end for
	D_00E71BD4[0].dwDoRender = 1;
	D_00E72988 = 0;
}

void C_00770305(int, int);//render track/scenery(cont'd)?

//chocobo:render track/scenery?
void C_00770291() {
	struct {
		int dwPathT_0;//local_3
		int dwPathT_1;//local_2
		int dwPathT_max;//local_1
	}lolo;

	D_00E71108 = 0;//reset "# polygons rendered"
	lolo.dwPathT_max = D_00E7112C->dwTrackLength;
	lolo.dwPathT_0 = (D_00E71124 + lolo.dwPathT_max) % lolo.dwPathT_max;
	lolo.dwPathT_1 = (D_00E70FE8 + lolo.dwPathT_max) % lolo.dwPathT_max;
	if(lolo.dwPathT_0 > lolo.dwPathT_1) {
		C_00770305(0, lolo.dwPathT_1);//render track/scenery(cont'd)?
		C_00770305(lolo.dwPathT_0, lolo.dwPathT_max);//render track/scenery(cont'd)?
	} else {
		C_00770305(lolo.dwPathT_0, lolo.dwPathT_1);//render track/scenery(cont'd)?
	}
}

int C_00770434(LPD3DMATRIX, short, int);//"SPRITE"
int C_007706D7(LPD3DMATRIX, int, int, int);//"DG4"
int C_00770767(LPD3DMATRIX, int, int, int);//"DG3"

//render track/scenery(cont'd)?
void C_00770305(int dwPathT_0/*bp08*/, int dwPathT_1/*bp0c*/) {
	struct {
		int local_7;
		int dwPolyCount;//local_6
		int local_5;
		int *pMAPTABLE;//local_4
		int dwNumChunks;//local_3
		short wMAPPOINTER; char _ocal_2[2];//local_2
		int local_1;
	}lolo;

	lolo.local_5 = dwPathT_0;
	lolo.dwNumChunks = dwPathT_1 - dwPathT_0;
	lolo.dwPolyCount = D_00E71108;
	lolo.wMAPPOINTER = D_00E7112C->pMAPPOINTER[dwPathT_0];
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
			lolo.local_1 = D_00E715FC[lolo.local_5].bTerrainFlags & 0x80;
			//note:most of the time, lolo.local_1 is 0x80
			// only in the short course does it take the value 0
			// on some sections of the track.
		}
		switch(((char *)&(lolo.local_7))[2]) {
			case 0: lolo.dwPolyCount += C_00770767(&D_00E72E60, (short)lolo.local_7, lolo.dwPolyCount, lolo.local_1); break;//"DG3"
			case 1: lolo.dwPolyCount += C_007706D7(&D_00E72E60, (short)lolo.local_7, lolo.dwPolyCount, lolo.local_1); break;//"DG4"
			case 0x21: lolo.dwPolyCount += C_00770434(&D_00E72E60, (short)lolo.local_7, lolo.dwPolyCount); break;//"SPRITE"
		}//end switch
		lolo.pMAPTABLE ++;
	}//end for
	D_00E71108 = lolo.dwPolyCount;
}

int C_00770685(int);//check y flip?

//"SPRITE"
int C_00770434(LPD3DMATRIX bp08, short wInd/*bp0c*/, int dwPolyCount_unused/*_p10*/) {
	struct {
		struct t_chocobo_data_SPRITE pSPRITE; char _ocal_26[2];//local_26
		struct SVECTOR local_20;
		char _ocal_18[0x28];
		struct t_chocobo_SpriteBillboard *pBillboard;//local_8
		int dwDist;//local_7
		int local_6;
		int dwWidth;//local_5
		int _ocal_4;
		short wX1,unusedwY1;
		short wX0,wY0;
		int local_1;
	}lolo;

	lolo.pSPRITE = D_00E7112C->pSPRITE[wInd];
	lolo.pBillboard = &(D_00E71C60[D_00E72980[wInd]]);
	lolo.dwDist = psx_RotTransPers(&lolo.pSPRITE.f_00, (int *)&lolo.local_20, &lolo.local_1, &lolo.local_6);
	if(lolo.dwDist > 4000 || lolo.dwDist < 0)
		return 0;
	lolo.wX0 = lolo.local_20.f_00;
	lolo.wY0 = lolo.local_20.f_02;
	if(lolo.wX0 < -40 || lolo.wY0 < -40)
		return 0;
	if(lolo.wX0 > 350 || lolo.wY0 > 270)
		return 0;

	if(lolo.dwDist)//unnecessary:at this point, lolo.dwDist cannot be 0
		lolo.dwWidth = (lolo.pSPRITE.wWidth * 270) / lolo.dwDist;
	lolo.wX0 -= lolo.dwWidth / 2;

	lolo.wX1 = lolo.wX0 + lolo.dwWidth;
	lolo.pBillboard->wX0 = lolo.wX0; lolo.pBillboard->wY0 = lolo.wY0;
	lolo.pBillboard->wX1 = lolo.wX1; lolo.pBillboard->wY1 = lolo.wY0;

	lolo.pBillboard->wX2 = lolo.wX0;
	lolo.pBillboard->wX3 = lolo.wX1;
	lolo.pSPRITE.f_00.f_02 -= lolo.pSPRITE.wHeight * 4;
	psx_RotTransPers(&lolo.pSPRITE.f_00, (int *)&lolo.local_20, &lolo.local_1, &lolo.local_6);
	lolo.pBillboard->wY2 =
	lolo.pBillboard->wY3 = lolo.local_20.f_02;

	lolo.pBillboard->fZ = C_0077C2AC(&lolo.pSPRITE.f_00, bp08);//chocobo:projected Z?
	if(C_00770685(wInd + 1)) {//check y flip?
		lolo.pBillboard->fU2 = 0.03f; lolo.pBillboard->fV2 = 0.03f;
		lolo.pBillboard->fU3 = 0.94f; lolo.pBillboard->fV3 = 0.03f;
		lolo.pBillboard->fU0 = 0.03f; lolo.pBillboard->fV0 = 0.94f;
		lolo.pBillboard->fU1 = 0.94f; lolo.pBillboard->fV1 = 0.94f;
	} else {
		lolo.pBillboard->fU0 = 0.03f; lolo.pBillboard->fV0 = 0.03f;
		lolo.pBillboard->fU1 = 0.94f; lolo.pBillboard->fV1 = 0.03f;
		lolo.pBillboard->fU2 = 0.03f; lolo.pBillboard->fV2 = 0.94f;
		lolo.pBillboard->fU3 = 0.94f; lolo.pBillboard->fV3 = 0.94f;
	}
	C_0077AD89(lolo.pBillboard);//chocobo:draw sprite[billboard]

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
int C_007706D7(LPD3DMATRIX bp08, int dwInd/*bp0c*/, int dwPolyCount_unused/*_p10*/, int bp14) {
	struct {
		struct t_chocobo_data_floatDG4 *local_2;
		struct t_chocobo_data_DG4 *local_1;
	}lolo;

	lolo.local_1 = &(D_00E7112C->pDG4[dwInd]);
	lolo.local_2 = &(D_00E7112C->pFloatDG4[dwInd]);
	//note:bp14 is 0 or 0x80, never negative
	if(bp14 < 0)
		return 0;
	if(lolo.local_1->color1.c.a == 0x38) {
		//-- SOLID --
		C_0077BE95(bp08, D_00E71BD4[1].f_00, lolo.local_2);//chocobo:draw quad[3D]
		D_00E71BD4[1].dwDoRender = 1;
	} else {
		//-- TRANSPARENT --
		C_0077BE95(bp08, D_00E71BD4[2].f_00, lolo.local_2);//chocobo:draw quad[3D]
		D_00E71BD4[2].dwDoRender = 1;
	}

	return 1;
}

//"DG3"
int C_00770767(LPD3DMATRIX bp08, int dwInd/*bp0c*/, int dwPolyCount_unused/*_p10*/, int bp14) {
	struct {
		struct t_chocobo_data_floatDG3 *local_2;
		struct t_chocobo_data_DG3 *local_1;
	}lolo;

	lolo.local_1 = &(D_00E7112C->pDG3[dwInd]);
	lolo.local_2 = &(D_00E7112C->pFloatDG3[dwInd]);
	//note:bp14 is 0 or 0x80, never negative
	if(bp14 < 0)
		return 0;
	if(lolo.local_1->color0.c.a == 0x30) {
		//-- SOLID --
		C_0077BB50(bp08, D_00E71BD4[3].f_00, lolo.local_2);//chocobo:draw triangle[3D]
		D_00E71BD4[3].dwDoRender = 1;
	} else {
		//-- TRANSPARENT --
		C_0077BB50(bp08, D_00E71BD4[4].f_00, lolo.local_2);//chocobo:draw triangle[3D]
		D_00E71BD4[4].dwDoRender = 1;
	}

	return 1;
}

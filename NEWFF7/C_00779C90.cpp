/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#include "ff7.h"
#include "chocobo_data.h"
#include "menu_data.h"

#include <time.h>
////////////////////////////////////////
struct t_chocobo_local_quad_2 {
	/*00*/struct t_g_drv_0c vert_0;
	/*0c*/struct t_g_drv_0c vert_1;
	/*18*/struct t_g_drv_0c vert_2;
	/*24*/struct t_g_drv_0c vert_3;
	/*30*/float fU_0,fV_0;
	/*38*/float fU_1,fV_1;
	/*40*/float fU_2,fV_2;
	/*48*/float fU_3,fV_3;
};
////////////////////////////////////////
extern struct t_chocobo_48 D_00E3B908;
extern LARGE_INTEGER D_00E3BA30;
extern LARGE_INTEGER D_00E3BA38;
extern int D_00E3BA8C;
extern double D_00E3BAC0;
extern int D_00E3BAC8;
extern int D_00E3BAD0;//endgame flag?
extern int D_00E3BAD4;

extern int D_00E70FE8;
extern int D_00E71018;
extern int D_00E71020[/*6*/];//"visible chocobo" flags
extern int D_00E71038;
extern int D_00E710E0;
extern int D_00E710EC;//fade:current alpha
extern int D_00E710F8;

extern int D_00E715D4;//fade:alpha incr
extern int D_00E715D8;//counter before start
extern struct t_chocobo_data_18 *D_00E715FC;

extern struct t_chocobo_local_1c D_00E72DF0;
////////////////////////////////////////
struct MATRIX D_00E73DB0;
unsigned char D_00E73DD0;
//00E73DD4~
D3DMATRIX D_00E73E60;
//00E73EA0~
double D_00E73EE0;
int D_00E73EE8;
int D_00E73EEC;
struct t_chocobo_data_18 *D_00E73EF0;
int D_00E73EF4;
int D_00E73EF8;
int D_00E73EFC;
////////////////////////////////////////
void __00779C90(struct t_aa0 *bp08) {
	C_0067656B(bp08);//set some game object?
}

struct t_aa0 *__00779CA1() {
	return C_00676578();
}

void __00779CAB(struct t_aa0 *bp08) {
	C_00676605(bp08);//set quit flag to game obj?
}

void __00779CBC() {
	C_006765BD();//directx:clean?
}

//chocobo.tempo?
//(credits, battle, world, field, swirl, menu, condor, submarine and chocobo tempo are very close)
void C_00779CC6(struct t_aa0 *_p08) {
//#pragma pack(1)
	struct {
		LARGE_INTEGER local_4;
		double local_2;
	}lolo;
//#pragma pack()

	lolo.local_2 = 0;
	TS_getCPUTimeStamp(&D_00E3BA30);
	TS_diff(&D_00E3BA30, &D_00E3BA38, &lolo.local_4);
	lolo.local_2 = TS_toDouble(&lolo.local_4);
	if(!D_00E3BAC8) {
		if(lolo.local_2 <= D_00E3BAC0) {
			while(lolo.local_2 < D_00E3BAC0) {
				TS_getCPUTimeStamp(&D_00E3BA30);
				TS_diff(&D_00E3BA30, &D_00E3BA38, &lolo.local_4);
				lolo.local_2 = TS_toDouble(&lolo.local_4);
			}//end while
			D_00E3BAC8 = 0;
			D_00E73EE0 = 0;
		} else {
			D_00E73EE0 = lolo.local_2 - D_00E3BAC0;
			D_00E3BAC8 = 1;
		}
	} else {
		while(lolo.local_2 < D_00E3BAC0 - D_00E73EE0) {
			TS_getCPUTimeStamp(&D_00E3BA30);
			TS_diff(&D_00E3BA30, &D_00E3BA38, &lolo.local_4);
			lolo.local_2 = TS_toDouble(&lolo.local_4);
		}//end while
		D_00E3BAC8 = 0;
		D_00E73EE0 = 0;
	}
}

void C_0077B29E(struct t_aa0 *);//chocobo.reset?

void C_00779E14(struct t_aa0 *bp08) {
	int i;//local_1

	D_00E73DD0 = 0;
	if(D_00E3BAD4 == 0) {
		C_0076DDD6(bp08);//ch_app:debug<empty>?
		//goto 00779F05
	} else {
		if(D_00E3BAC8 == 0) {
			C_0076DDD6(bp08);//ch_app:debug<empty>?
			D_00E3BAC8 = 0;
			//goto 00779EF9
		} else {
			C_00779CC6(bp08);//chocobo.tempo?
			D_00E3BAC8 = 0;
			C_0077B29E(bp08);//chocobo.reset?
			for(i = 0; i < D_00E719EC; i ++)
				D_00E719E8[i].f_20 = 0;
			C_0076DDF0();//chobobo.input.reset?
			bp08->f_040 += 1.0;
			D_00E3BA38.LowPart = 0;
			C_0076DC5B(bp08);
			if(D_00E3BAD0)
				return;
			C_0076DDD6(bp08);//ch_app:debug<empty>?
		}
		C_00779CC6(bp08);//chocobo.tempo?
	}
	C_0077B29E(bp08);//chocobo.reset?
	for(i = 0; i < D_00E719EC; i ++)
		D_00E719E8[i].f_20 = 0;
	C_0076DDF0();//chobobo.input.reset?
	D_00E3BA38.LowPart = 0;
}

void __00779F59(struct t_aa0 *bp08) {
	time_t local_1;

	//-- a randomize macro? --
	if(bp08->f_9b0) {
		srand(bp08->f_9b0);
	} else {
		time(&local_1);
		srand(local_1);
	}
	//-- --
}

struct t_aa0 *__00779F99() {
	return C_00676E7E();//directx:init some game object?
}

void __00779FA3(int bp08, int bp0c) {
	C_0076DCBF(bp08, bp0c);//ch_app:unused init?
}

void __00779FB8(struct t_plytopd_e4 *bp08, float fX/*bp0c*/, float fY/*bp10*/, float fZ/*bp14*/) {
	if(bp08) {
		bp08->f_38.sPos.f_00 = fX;
		bp08->f_38.sPos.f_04 = fY;
		bp08->f_38.sPos.f_08 = fZ;
	}
}

int __00779FDE(struct t_aa0 *bp08, D3DMATRIX bp0c) {
	C_0067CBF1(&bp0c, bp08);//dx_mat:set "struct t_aa0::f_2fc"

	return 1;
}

int __00779FF8(struct t_aa0 *bp08, struct t_local_plytopd_24 *bp0c, int dwBlendMode/*bp10*/) {
	struct {
		struct t_rsd_74 *local_33;
		int dwFPS;//local_32
		int dwAnimIndex;//local_31
		struct t_plytopd_e4 *local_30;
		struct t_rsd_74 local_29;
	}lolo;

	if(bp0c == 0)
		return 0;
	lolo.local_30 = bp0c->f_20;
	if(lolo.local_30 == 0) {
		lolo.local_33 = &lolo.local_29;
		C_0067455E(lolo.local_33);//rsd:init with blend mode 4?
		C_00674659(dwBlendMode, lolo.local_33);//rsd:set blend mode?
		lolo.dwAnimIndex = 0;
		lolo.dwFPS = bp0c->dwFPS;
		lolo.local_30 = C_006968C4(lolo.dwFPS, lolo.dwAnimIndex, bp0c, lolo.local_33, bp08);//plytopd:...
		if(lolo.local_30)
			bp0c->f_20 = lolo.local_30;
	}

	return 1;
}

//load HRC/RSD?
struct tSkeleton *C_0077A092(const char *bp08, const char *bp0c, struct t_rsd_74 *bp10, struct t_aa0 *bp14) {
	struct {
		const char *local_2;
		struct tSkeleton *local_1;
	}lolo;

	lolo.local_2 = 0;
	if(D_00972174 == 0)
		//== DEVEL ==
		lolo.local_1 = C_006934F5(lolo.local_2, bp08);//plytopd:load ".HRC" file(2)?
	else
		//== RELEASE ==
		lolo.local_1 = C_00692EE1(&(bp10->f_40), lolo.local_2, bp08);//plytopd:load ".HRC" file?
	//== ==
	if(lolo.local_1) {
		C_00693902(bp0c, lolo.local_1, bp10, bp14);//plytopd:load ".RSD" files?
		C_00693E0D(1, lolo.local_1);//plytopd:set skeleton "active"?
	}

	return lolo.local_1;
}

void C_0077A2D2(int, struct t_animationHeader *, struct t_plytopd_e4 *);

struct t_plytopd_e4 *C_0077A10A(int dwFPS/*bp08*/, struct tSkeleton *bp0c, struct t_aa0 *bp10, struct t_animationHeader *bp14) {
	struct t_plytopd_e4 *local_1;

	local_1 = C_00695A2B(dwFPS, 0, bp0c, bp10);//plytopd:...
	if(local_1) {
		C_0077A2D2(0, bp14, local_1);
		local_1->f_28 = 0;
	}

	return local_1;
}

//load ".anm" file(renamed ".a")?
struct t_animationHeader *C_0077A150(struct t_rsd_74 *bp08, const char *bp0c) {
	struct {
		char drive[_MAX_DRIVE]; char _ocal_258;
		char fname[_MAX_FNAME];//local_257
		char dir[_MAX_DIR];//local_193
		char ext[_MAX_EXT];//local_129
		char local_65[256];
		struct t_animationHeader *local_1;
	}lolo;

	lolo.local_1 = 0;
	_splitpath(bp0c, lolo.drive, lolo.dir, lolo.fname, lolo.ext);
	strcpy(lolo.ext, /*00980DA0*/".a");
	strcpy(lolo.local_65, lolo.drive);
	strcat(lolo.local_65, lolo.dir);
	strcat(lolo.local_65, lolo.fname);
	strcat(lolo.local_65, lolo.ext);
	if(C_0069254C(bp0c, lolo.local_65)) {//plytopd:convert ".anm"[TEXT] to ".A"[BIN]
		if(D_00972174 == 0)
			//== DEVEL ==
			lolo.local_1 = C_00692346(lolo.local_65);//plytopd:load ".A" file(2)?
		else
			//== RELEASE ==
			lolo.local_1 = C_006921CE(&(bp08->f_40), lolo.local_65);//plytopd:load ".A" file?
	}

	return lolo.local_1;
}

void C_0077A2D2(int _p08, struct t_animationHeader *bp0c, struct t_plytopd_e4 *bp10) {
	//
	C_00695E6A(1, bp0c, bp10);//plytopd:...
}

//load ".HRC" file?
struct t_plytopd_e4 *C_0077A2E9(int dwFPS/*bp08*/, struct t_animationHeader *bp0c, struct t_rsd_74 *bp10, struct t_aa0 *bp14, const char *bp18, const char *bp1c) {
	struct {
		struct tSkeleton *local_2;
		struct t_plytopd_e4 *local_1;
	}lolo;

	lolo.local_1 = 0;
	lolo.local_2 = C_0077A092(bp18, bp1c, bp10, bp14);//load HRC/RSD?
	if(lolo.local_2)
		lolo.local_1 = C_0077A10A(dwFPS, lolo.local_2, bp14, bp0c);

	return lolo.local_1;
}

//set animation #
int C_0077A339(struct t_chocobo_3c *bp08, int dwAnmNum/*bp0c*/) {
	if(bp08 == 0)
		return 0;
	if(dwAnmNum >= bp08->wMaxAnmNum)
		return 0;
	C_0077A2D2(0, bp08->f_38[dwAnmNum], bp08->f_34);
	bp08->wAnmNum = bp08->wPrevAnmNum = dwAnmNum;
	bp08->dwMaxAnimationFrame = bp08->f_34->f_08;

	return 1;
}

void C_0077A3A2(struct t_chocobo_48 *bp08) {
	C_00672080(
		D_00E3BA68.dwScrXOfs + bp08->f_14[0].wX * D_00E3BA68.f_18,
		D_00E3BA68.dwScrYOfs + bp08->f_14[0].wY * D_00E3BA68.f_18 + D_00E3BA8C,
		bp08->dwWidth * D_00E3BA68.f_18,
		bp08->dwHeight * D_00E3BA68.f_18,
		bp08->wU,
		bp08->wV,
		bp08->dwWidth,
		bp08->dwHeight,
		bp08->f_30,
		bp08->fZ,
		1.0f,
		D_00E72990[bp08->f_00].f_00
	);//dx_sfx:make "textured" quad
	D_00E72990[bp08->f_00].f_14 = 1;
	D_00E72990[bp08->f_00].f_0c = 1;
}

//draw sprite?
void C_0077A469(struct t_chocobo_48 *bp08) {
	struct t_dx_rend_vertex_20 *local_4[4];

	if(C_0066E272(1, D_00E72990[bp08->f_00].f_00)) {//else 0077A7BA
		*(D_00E72990[bp08->f_00].f_00->lpbCurPalette) = bp08->f_30;
		D_00E72990[bp08->f_00].f_00->dwLastPalette = bp08->f_30;
		MK_VERTEX(&(D_00E72990[bp08->f_00].f_00->f_70.asVertex[0]), local_4[3], D_00E3BA68.dwScrXOfs + bp08->f_14[0].wX * D_00E3BA68.f_18, D_00E3BA68.dwScrYOfs + bp08->f_14[0].wY * D_00E3BA68.f_18 + D_00E3BA8C, bp08->fZ, 1.0f, 0x80ffffff, 0xff000000, bp08->fU, bp08->fV);
		MK_VERTEX(&(D_00E72990[bp08->f_00].f_00->f_70.asVertex[1]), local_4[2], D_00E3BA68.dwScrXOfs + bp08->f_14[0].wX * D_00E3BA68.f_18, D_00E3BA68.dwScrYOfs + bp08->f_14[0].wY * D_00E3BA68.f_18 + bp08->dwHeight * D_00E3BA68.f_18 + D_00E3BA8C, bp08->fZ, 1.0f, 0x80ffffff, 0xff000000, bp08->fU, bp08->fV + bp08->fTexHeight);
		MK_VERTEX(&(D_00E72990[bp08->f_00].f_00->f_70.asVertex[2]), local_4[1], D_00E3BA68.dwScrXOfs + bp08->f_14[0].wX * D_00E3BA68.f_18 + bp08->dwWidth * D_00E3BA68.f_18, D_00E3BA68.dwScrYOfs + bp08->f_14[0].wY * D_00E3BA68.f_18 + D_00E3BA8C, bp08->fZ, 1.0f, 0x80ffffff, 0xff000000, bp08->fU + bp08->fTexWidth, bp08->fV);
		MK_VERTEX(&(D_00E72990[bp08->f_00].f_00->f_70.asVertex[3]), local_4[0], D_00E3BA68.dwScrXOfs + bp08->f_14[0].wX * D_00E3BA68.f_18 + bp08->dwWidth * D_00E3BA68.f_18, D_00E3BA68.dwScrYOfs + bp08->f_14[0].wY * D_00E3BA68.f_18 + bp08->dwHeight * D_00E3BA68.f_18 + D_00E3BA8C, bp08->fZ, 1.0f, 0x80ffffff, 0xff000000, bp08->fU + bp08->fTexWidth, bp08->fV + bp08->fTexHeight);
		D_00E72990[bp08->f_00].f_14 = 1;
	}
	D_00E72990[bp08->f_00].f_0c = 0;
}

//draw a color rectangle?
void C_0077A7D0(struct t_chocobo_48 *bp08) {
	unsigned dwBGRA;

	dwBGRA = (0x80 << 24) | (bp08->f_04.c.r << 16) | (bp08->f_04.c.g << 8) | bp08->f_04.c.b;
	C_00671D2A(
		D_00E3BA68.dwScrXOfs + bp08->f_14[0].wX * D_00E3BA68.f_18,
		D_00E3BA68.dwScrYOfs + bp08->f_14[0].wY * D_00E3BA68.f_18 + D_00E3BA8C,
		bp08->dwWidth * D_00E3BA68.f_18,
		bp08->dwHeight * D_00E3BA68.f_18,
		dwBGRA,
		0,
		bp08->fZ,
		D_00E72990[bp08->f_00].f_00
	);//dx_sfx:make "plain" quad
	D_00E72990[bp08->f_00].f_14 = 1;
	D_00E72990[bp08->f_00].f_0c = 1;
}

void C_0077A89F(struct t_chocobo_48 *bp08) {
	struct {
		struct t_dx_rend_vertex_20 *local_8[4];
		int local_4;
		unsigned local_3;
		int local_2;
		int local_1;
	}lolo;

	if(C_0066E272(1, D_00E72990[bp08->f_00].f_00)) {//else 0077AC31
		//-- --
		lolo.local_2 = bp08->f_04.c.r * 2;
		if(lolo.local_2 > 0xff)
			lolo.local_2 = 0xff;
		lolo.local_4 = bp08->f_04.c.g * 2;
		if(lolo.local_4 > 0xff)
			lolo.local_4 = 0xff;
		lolo.local_1 = bp08->f_04.c.b * 2;
		if(lolo.local_1 > 0xff)
			lolo.local_1 = 0xff;
		lolo.local_3 = (0x80 << 24) | (lolo.local_2 << 16) | (lolo.local_4 << 8) | lolo.local_1;
		//-- --
		*(D_00E72990[bp08->f_00].f_00->lpbCurPalette) = bp08->f_30;
		D_00E72990[bp08->f_00].f_00->dwLastPalette = bp08->f_30;
		MK_VERTEX(&(D_00E72990[bp08->f_00].f_00->f_70.asVertex[0]), lolo.local_8[3], D_00E3BA68.dwScrXOfs + bp08->f_14[0].wX * D_00E3BA68.f_18, (float)(D_00E3BA68.dwScrYOfs + bp08->f_14[0].wY * D_00E3BA68.f_18) + D_00E3BA8C, bp08->fZ, 1.0f, lolo.local_3, 0xff000000, bp08->fU, bp08->fV);
		MK_VERTEX(&(D_00E72990[bp08->f_00].f_00->f_70.asVertex[1]), lolo.local_8[2], D_00E3BA68.dwScrXOfs + bp08->f_14[2].wX * D_00E3BA68.f_18, (float)(D_00E3BA68.dwScrYOfs + bp08->f_14[2].wY * D_00E3BA68.f_18) + D_00E3BA8C, bp08->fZ, 1.0f, lolo.local_3, 0xff000000, bp08->fU, bp08->fV + bp08->fTexHeight);
		MK_VERTEX(&(D_00E72990[bp08->f_00].f_00->f_70.asVertex[2]), lolo.local_8[1], D_00E3BA68.dwScrXOfs + bp08->f_14[1].wX * D_00E3BA68.f_18, (float)(D_00E3BA68.dwScrYOfs + bp08->f_14[1].wY * D_00E3BA68.f_18) + D_00E3BA8C, bp08->fZ, 1.0f, lolo.local_3, 0xff000000, bp08->fU + bp08->fTexWidth, bp08->fV);
		MK_VERTEX(&(D_00E72990[bp08->f_00].f_00->f_70.asVertex[3]), lolo.local_8[0], D_00E3BA68.dwScrXOfs + bp08->f_14[3].wX * D_00E3BA68.f_18, (float)(D_00E3BA68.dwScrYOfs + bp08->f_14[3].wY * D_00E3BA68.f_18) + D_00E3BA8C, bp08->fZ, 1.0f, lolo.local_3, 0xff000000, bp08->fU + bp08->fTexWidth, bp08->fV + bp08->fTexHeight);
		D_00E72990[bp08->f_00].f_14 = 1;
		D_00E72990[bp08->f_00].f_0c = 0;
	}
}

//[for sw patch]
void C_0077AC35(struct t_chocobo_48 *bp08) {
	struct {
		int local_4;
		tBGRA local_3;
		int local_2;
		int local_1;
	}lolo;

	//-- --
	lolo.local_2 = bp08->f_04.c.r * 2;
	if(lolo.local_2 > 0xff)
		lolo.local_2 = 0xff;
	lolo.local_4 = bp08->f_04.c.g * 2;
	if(lolo.local_4 > 0xff)
		lolo.local_4 = 0xff;
	lolo.local_1 = bp08->f_04.c.b * 2;
	if(lolo.local_1 > 0xff)
		lolo.local_1 = 0xff;
	if(lolo.local_2 == 0xff && lolo.local_4 == 0xff && lolo.local_1 == 0xff)
		return;
	//-- --
	if(bp08->f_14[1].wX - bp08->f_14[0].wX != bp08->dwWidth - 2)
		return;
	//-- --
	if(C_0066E272(1, D_00E72DF0.f_00)) {
		lolo.local_3.c.b = 0x40;
		lolo.local_3.c.g = 0x40;
		lolo.local_3.c.r = 0x40;
		lolo.local_3.c.a = 0x80;
		C_00671D2A(
			D_00E3BA68.dwScrXOfs + (bp08->f_14[0].wX + 2) * D_00E3BA68.f_18,
			D_00E3BA68.dwScrYOfs + (bp08->f_14[0].wY + 2) * D_00E3BA68.f_18 + D_00E3BA8C,
			(bp08->dwWidth - 7) * D_00E3BA68.f_18,
			(bp08->dwHeight - 7) * D_00E3BA68.f_18,
			lolo.local_3.bgra,
			0,
			0.004f,
			D_00E72DF0.f_00
		);//dx_sfx:make "plain" quad
		D_00E72DF0.f_14 = 1;
	}
}

void C_0077AD89(struct t_chocobo_unknown_54 *bp08) {
	struct {
		struct t_dx_rend_vertex_20 *local_8[4];
		int _ocal_4[4];
	}lolo;

	if(C_0066E272(1, bp08->f_48)) {
		*(bp08->f_48->lpbCurPalette) = bp08->f_40;
		bp08->f_48->dwLastPalette = bp08->f_40;
		MK_VERTEX(&(bp08->f_48->f_70.asVertex[0]), lolo.local_8[3], D_00E3BA68.dwScrXOfs + bp08->f_04[0].wX * D_00E3BA68.f_18, (float)bp08->f_04[0].wY * D_00E3BA68.f_18 + D_00E3BA68.dwScrYOfs + D_00E3BA8C, bp08->fZ, 1.0f, 0xa0ffffff, 0xff000000, bp08->f_14[0].fU, bp08->f_14[0].fV);
		MK_VERTEX(&(bp08->f_48->f_70.asVertex[1]), lolo.local_8[2], D_00E3BA68.dwScrXOfs + bp08->f_04[2].wX * D_00E3BA68.f_18, (float)bp08->f_04[2].wY * D_00E3BA68.f_18 + D_00E3BA68.dwScrYOfs + D_00E3BA8C, bp08->fZ, 1.0f, 0xa0ffffff, 0xff000000, bp08->f_14[2].fU, bp08->f_14[2].fV);
		MK_VERTEX(&(bp08->f_48->f_70.asVertex[2]), lolo.local_8[1], D_00E3BA68.dwScrXOfs + bp08->f_04[1].wX * D_00E3BA68.f_18, (float)bp08->f_04[1].wY * D_00E3BA68.f_18 + D_00E3BA68.dwScrYOfs + D_00E3BA8C, bp08->fZ, 1.0f, 0xa0ffffff, 0xff000000, bp08->f_14[1].fU, bp08->f_14[1].fV);
		MK_VERTEX(&(bp08->f_48->f_70.asVertex[3]), lolo.local_8[0], D_00E3BA68.dwScrXOfs + bp08->f_04[3].wX * D_00E3BA68.f_18, (float)bp08->f_04[3].wY * D_00E3BA68.f_18 + D_00E3BA68.dwScrYOfs + D_00E3BA8C, bp08->fZ, 1.0f, 0xa0ffffff, 0xff000000, bp08->f_14[3].fU, bp08->f_14[3].fV);
		bp08->f_50 = 1;
	}
}

void __0077B03E(struct t_chocobo_48 *bp08) {
	struct {
		unsigned short i; char _ocal_5[2];//local_5
		int local_4;
		struct t_dx_sfx_84 *local_3;
		int local_2;
		int local_1;
	}lolo;

	//-- --
	lolo.local_2 = bp08->f_04.c.r * 2;
	if(lolo.local_2 > 0xff)
		lolo.local_2 = 0xff;
	lolo.local_4 = bp08->f_04.c.g * 2;
	if(lolo.local_4 > 0xff)
		lolo.local_4 = 0xff;
	lolo.local_1 = bp08->f_04.c.b * 2;
	if(lolo.local_1 > 0xff)
		lolo.local_1 = 0xff;
	//-- --
	lolo.local_3 = C_00672080(
		D_00E3BA68.dwScrXOfs + bp08->f_14[0].wX * D_00E3BA68.f_18,
		D_00E3BA68.dwScrYOfs + bp08->f_14[0].wY * D_00E3BA68.f_18 + D_00E3BA8C,
		bp08->dwWidth * D_00E3BA68.f_18,
		bp08->dwHeight * D_00E3BA68.f_18,
		bp08->wU,
		bp08->wV,
		bp08->dwWidth,
		bp08->dwHeight,
		bp08->f_30,
		bp08->fZ,
		1.0f,
		D_00E72990[bp08->f_00].f_00
	);//dx_sfx:make "textured" quad
	for(lolo.i = 0; lolo.i < 4; lolo.i ++) {
		lolo.local_3->f_5c[lolo.i].c.b = lolo.local_2;
		lolo.local_3->f_5c[lolo.i].c.g = lolo.local_4;
		lolo.local_3->f_5c[lolo.i].c.r = lolo.local_1;
		lolo.local_3->f_5c[lolo.i].c.a = 0xff;
	}//end for
	D_00E72990[bp08->f_00].f_14 = 1;
	D_00E72990[bp08->f_00].f_0c = 1;
}

void C_0077B1CE(struct t_chocobo_48 *bp08) {
	tBGRA local_1;

	local_1.c.b = 0;
	local_1.c.g = 0;
	local_1.c.r = 0;
	if(bp08->f_04.c.r > 0xff)//nonsense test?
		bp08->f_04.c.r = 0xff;
	local_1.c.a = bp08->f_04.c.r;
	C_00671D2A(
		D_00E3BA68.dwScrXOfs + bp08->f_14[0].wX * D_00E3BA68.f_18,
		D_00E3BA68.dwScrYOfs + bp08->f_14[0].wY * D_00E3BA68.f_18 + D_00E3BA8C,
		bp08->dwWidth * D_00E3BA68.f_18,
		bp08->dwHeight * D_00E3BA68.f_18,
		local_1.bgra,
		0,
		bp08->fZ,
		D_00E72990[bp08->f_00].f_00
	);//dx_sfx:make "plain" quad
	D_00E72990[bp08->f_00].f_14 = 1;
	D_00E72990[bp08->f_00].f_0c = 1;
}

//chocobo.reset?
void C_0077B29E(struct t_aa0 *bp08) {
	C_007715A4();//[reset this module]
	C_00770159();//chocobo:render this module
	C_0076FDD3();//ch_chr:reset?
	C_00666DA3(bp08);//calls "instance:reset"
	C_00666DC0(bp08);//calls "dx_sfx:reset heaps"
}

//chocobo:renderer?
void C_0077B2CA() {
#pragma pack(1)
	struct {
		unsigned short i; char _ocal_6[2];//local_6
		LARGE_INTEGER local_5;
		LARGE_INTEGER local_3;
		struct t_aa0 *local_1;
	}lolo;
#pragma pack()

	lolo.local_1 = C_00676578();
	//-- stats --
	TS_getCPUTimeStamp(&lolo.local_5);
	//-- --
	if(D_00E3BAC8)
		return;
	g_drv_beginScene(0, lolo.local_1);
	//===========
	//== SOLID ==
	//===========
	C_00660E95(0, lolo.local_1);//G_DRV_84:change_layer?

	g_drv_setRenderState(G_DRV_STATE_02, 0, lolo.local_1);
	//-- 2D elements[solid] --
	for(lolo.i = 0; lolo.i < 0x28; lolo.i ++) {
		if(D_00E72990[lolo.i].f_10 && D_00E72990[lolo.i].f_14 && D_00E72990[lolo.i].dwIsTransparent == 0) {
			if(D_00E72990[lolo.i].f_0c)
				C_00660E6A(D_00E72990[lolo.i].f_00, lolo.local_1);//G_DRV_80:render "struct t_dx_sfx_e0 *"(through "G_DRV_78")?
			else
				C_0066E641(D_00E72990[lolo.i].f_00, lolo.local_1);//dx_spr:render
		}
	}
	C_006FDC26(lolo.local_1);//menu.refresh strings?
	//-- scenery[solid] --
	if(D_00E71BD4.f_14)
		C_0066E641(D_00E71BD4.f_00, lolo.local_1);//dx_spr:render
	if(D_00E71C28.f_14)
		C_0066E641(D_00E71C28.f_00, lolo.local_1);//dx_spr:render
	if(D_00E71BF0.f_14)
		C_0066E641(D_00E71BF0.f_00, lolo.local_1);//dx_spr:render
	//-- --
	C_0076FE41(lolo.local_1);//ch_chr:render(solid)?
	//-- animated models[solid] --
	g_drv_setRenderState(G_DRV_STATE_02, 1, lolo.local_1);

	for(lolo.i = 0; lolo.i < D_00E719EC; lolo.i ++) {
		if(D_00E719E8[lolo.i].f_20 && D_00E719E8[lolo.i].dwIsTransparent == 0)
			C_006840DA(
				D_00E719E8[lolo.i].f_34->f_20,
				D_00E719E8[lolo.i].f_34->f_34,
				&(D_00E719E8[lolo.i].f_34->f_38),
				D_00E719E8[lolo.i].f_34->f_b4,
				D_00E719E8[lolo.i].f_34->f_b8
			);//anm:...(a big one)
	}
	//=================
	//== TRANSPARENT ==
	//=================
	C_00660E95(1, lolo.local_1);//G_DRV_84:change_layer?

	g_drv_setRenderState(G_DRV_STATE_02, 0, lolo.local_1);
	//-- scenery[transparent] --
	if(D_00E71C44.f_14)
		C_0066E641(D_00E71C44.f_00, lolo.local_1);//dx_spr:render
	if(D_00E71C0C.f_14)
		C_0066E641(D_00E71C0C.f_00, lolo.local_1);//dx_spr:render
	//-- patch for SW --
	if(D_00E3BA68.dwSWRenderer) {
		if(D_00E72DF0.f_14)
			C_00660E6A(D_00E72DF0.f_00, lolo.local_1);//G_DRV_80:render "struct t_dx_sfx_e0 *"(through "G_DRV_78")?
	}
	//-- --
	C_0076FECC(lolo.local_1);//ch_chr:render(transparent)?
	//-- 2D elements[transparent] --
	for(lolo.i = 0; lolo.i < 0x28; lolo.i ++) {
		if(D_00E72990[lolo.i].f_10 && D_00E72990[lolo.i].f_14 && D_00E72990[lolo.i].dwIsTransparent) {
			if(D_00E72990[lolo.i].f_0c)
				C_00660E6A(D_00E72990[lolo.i].f_00, lolo.local_1);//G_DRV_80:render "struct t_dx_sfx_e0 *"(through "G_DRV_78")?
			else
				C_0066E641(D_00E72990[lolo.i].f_00, lolo.local_1);//dx_spr:render
		}
	}
	//-- animated models[transparent] --
	g_drv_setRenderState(G_DRV_STATE_02, 1, lolo.local_1);

	for(lolo.i = 0; lolo.i < D_00E719EC; lolo.i ++) {
		if(D_00E719E8[lolo.i].f_20 && D_00E719E8[lolo.i].dwIsTransparent)
			C_006840DA(
				D_00E719E8[lolo.i].f_34->f_20,
				D_00E719E8[lolo.i].f_34->f_34,
				&(D_00E719E8[lolo.i].f_34->f_38),
				D_00E719E8[lolo.i].f_34->f_b4,
				D_00E719E8[lolo.i].f_34->f_b8
			);//anm:...(a big one)
	}
	//=======
	//==   ==
	//=======
	g_drv_endScene(lolo.local_1);
	//-- stats --
	TS_getCPUTimeStamp(&lolo.local_3);
	if(lolo.local_1->f_794)
		TS_diff(&lolo.local_3, &lolo.local_5, &(lolo.local_1->f_794->f_a0));
	//-- --
}

//refresh rotation[3D model]?
void C_0077B7E2(struct t_chocobo_3c *bp08) {
	struct {
		char _ocal_101[0x150];
		float local_17;
		char _ocal_16[0x40];
	}lolo;

	if(bp08->f_28) {
		bp08->f_20 = 1;
		C_0077A339(bp08, bp08->wAnmNum);//set animation #
		bp08->f_34->f_00 = 1;
		bp08->f_34->f_24 = 1;
		bp08->f_34->f_18 = 1;
		if(bp08->dwAnimationFrame >= bp08->dwMaxAnimationFrame)
			bp08->f_34->f_20 = bp08->dwMaxAnimationFrame - 1;
		else
			bp08->f_34->f_20 = bp08->dwAnimationFrame;
		//-- rot --
		lolo.local_17 = ((float)/*local_102*/bp08->f_0a * 360.0f) / 250.0f;
		bp08->f_34->f_38.sRot.f_00 = 0;
		if(bp08->f_24 == 0)
			bp08->f_34->f_38.sRot.f_04 = -lolo.local_17;
		else
			bp08->f_34->f_38.sRot.f_04 = -lolo.local_17 + 180.0f;
		bp08->f_34->f_38.sRot.f_08 = -180.0f;
		//-- pos --
		bp08->f_34->f_38.sPos.f_00 = /*local_103*/(float)bp08->f_00;
		if(bp08->dwAdjustYPos)
			bp08->f_34->f_38.sPos.f_04 = /*local_104*/(float)bp08->f_02;
		else
			bp08->f_34->f_38.sPos.f_04 = /*local_105*/(float)(bp08->f_02 -10);
		bp08->f_34->f_38.sPos.f_08 = /*local_106*/(float)bp08->f_04;
		//-- --
		bp08->f_20 = 1;
	}
}

void __0077B964(struct MATRIX *bp08, LPD3DMATRIX bp0c) {
	C_006611FB(bp08, bp0c);//psx:transformation to D3DMATRIX(1)
}

void __0077B979(LPD3DMATRIX bp08, float fX/*bp0c*/, float fY/*bp10*/, float fZ/*bp14*/, struct tVECTOR_F4 *bp18) {
	struct t_g_drv_0c local_3;

	local_3.f_00 = fX;
	local_3.f_04 = fY;
	local_3.f_08 = fZ;
	C_0066CE40(bp08, &local_3, bp18);//[optimized]still another vector/matrix operation(w=1)
}

void C_0077B9A9(struct t_aa0 *bp08) {
	D_00E73E60 = D_00E72E18;
	C_0067CBF1(&D_00E73E60, bp08);//dx_mat:set "struct t_aa0::f_2fc"
}

//[static]render triangle?
void C_0077B9D4(unsigned dwColor_0/*bp08*/, unsigned dwColor_1/*bp0c*/, unsigned dwColor_2/*bp10*/, struct t_g_drv_0c *bp14, struct t_g_drv_0c *bp18, struct t_g_drv_0c *bp1c, LPD3DMATRIX bp20, struct t_dx_sfx_e0 *bp24) {
	struct {
		struct t_dx_rend_vertex_20 *local_18;
		float rhw_2;//local_17
		struct t_dx_rend_vertex_20 *local_16;
		float rhw_1;//local_15
		struct t_dx_rend_vertex_20 *local_14;
		float rhw_0;//local_13
		struct tVECTOR_F4 vert_2;//local_12
		struct tVECTOR_F4 vert_0;//local_8
		struct tVECTOR_F4 vert_1;//local_4
	}lolo;

	C_0066CE40(bp20, bp14, &lolo.vert_0);//[optimized]still another vector/matrix operation(w=1)
	if(lolo.vert_0.f_0c > 0.0) {
		C_0066CE40(bp20, bp18, &lolo.vert_1);//[optimized]still another vector/matrix operation(w=1)
		if(lolo.vert_1.f_0c > 0.0) {
			C_0066CE40(bp20, bp1c, &lolo.vert_2);//[optimized]still another vector/matrix operation(w=1)
			if(lolo.vert_2.f_0c > 0.0) {
				if(C_0066E272(1, bp24)) {
					lolo.rhw_0 = 1.0f / lolo.vert_0.f_0c;
					MK_VERTEX_NOTEXTURE_1(&(bp24->f_70.asVertex[0]), lolo.local_14, lolo.vert_0.f_00 * lolo.rhw_0, lolo.vert_0.f_04 * lolo.rhw_0, lolo.vert_0.f_08 * lolo.rhw_0, lolo.rhw_0, dwColor_0);
					lolo.rhw_1 = 1.0f / lolo.vert_1.f_0c;
					MK_VERTEX_NOTEXTURE_1(&(bp24->f_70.asVertex[1]), lolo.local_16, lolo.vert_1.f_00 * lolo.rhw_1, lolo.vert_1.f_04 * lolo.rhw_1, lolo.vert_1.f_08 * lolo.rhw_1, lolo.rhw_1, dwColor_1);
					lolo.rhw_2 = 1.0f / lolo.vert_2.f_0c;
					MK_VERTEX_NOTEXTURE_1(&(bp24->f_70.asVertex[2]), lolo.local_18, lolo.vert_2.f_00 * lolo.rhw_2, lolo.vert_2.f_04 * lolo.rhw_2, lolo.vert_2.f_08 * lolo.rhw_2, lolo.rhw_2, dwColor_2);
				}
			}
		}
	}
}

//render triangle?
void C_0077BB50(LPD3DMATRIX bp08, struct t_dx_sfx_e0 *bp0c, struct t_chocobo_data_floatDG3 *bp10) {
	C_0077B9D4(bp10->f_24.rgba, bp10->f_28.rgba, bp10->f_2c.rgba, &(bp10->f_00), &(bp10->f_0c), &(bp10->f_18), bp08, bp0c);//[static]render triangle?
}

//[unused]render triangle?
void __0077BB8C(LPD3DMATRIX bp08, struct t_dx_sfx_e0 *bp0c, struct SVECTOR *bp10, struct SVECTOR *bp14, struct SVECTOR *bp18, unsigned bp1c, unsigned bp20, unsigned bp24) {
	struct {
		struct t_g_drv_0c local_13;
		struct t_g_drv_0c local_10;
		tRGBA local_7;
		struct t_g_drv_0c local_6;
		tRGBA local_3;
		tRGBA local_2;
		unsigned char local_1; char _ocal_1[3];
	}lolo;

	lolo.local_3.rgba = bp1c | (0xff << 24);
	SWAP(lolo.local_3.c.r, lolo.local_3.c.b, lolo.local_1);

	lolo.local_2.rgba = bp20 | (0xff << 24);
	SWAP(lolo.local_2.c.r, lolo.local_2.c.b, lolo.local_1);

	lolo.local_7.rgba = bp24 | (0xff << 24);
	SWAP(lolo.local_7.c.r, lolo.local_7.c.b, lolo.local_1);

	lolo.local_13.f_00 = (float)bp10->f_00;
	lolo.local_13.f_04 = (float)bp10->f_02;
	lolo.local_13.f_08 = (float)bp10->f_04;

	lolo.local_6.f_00 = (float)bp14->f_00;
	lolo.local_6.f_04 = (float)bp14->f_02;
	lolo.local_6.f_08 = (float)bp14->f_04;

	lolo.local_10.f_00 = (float)bp18->f_00;
	lolo.local_10.f_04 = (float)bp18->f_02;
	lolo.local_10.f_08 = (float)bp18->f_04;

	C_0077B9D4(lolo.local_3.rgba, lolo.local_2.rgba, lolo.local_7.rgba, &lolo.local_13, &lolo.local_6, &lolo.local_10, bp08, bp0c);//[static]render triangle?
}

//[static]render quad?
void C_0077BCA4(unsigned dwColor_0/*bp08*/, unsigned dwColor_1/*bp0c*/, unsigned dwColor_2/*bp10*/, unsigned dwColor_3/*bp14*/, struct t_g_drv_0c *bp18, struct t_g_drv_0c *bp1c, struct t_g_drv_0c *bp20, struct t_g_drv_0c *bp24, LPD3DMATRIX bp28, struct t_dx_sfx_e0 *bp2c) {
	struct {
		struct t_dx_rend_vertex_20 *local_24;
		float rhw_3;//local_23
		struct t_dx_rend_vertex_20 *local_22;
		float rhw_2;//local_21
		struct t_dx_rend_vertex_20 *local_20;
		float rhw_1;//local_19
		struct t_dx_rend_vertex_20 *local_18;
		float rhw_0;//local_17
		struct tVECTOR_F4 vert_2;//local_16
		struct tVECTOR_F4 vert_3;//local_12
		struct tVECTOR_F4 vert_0;//local_8
		struct tVECTOR_F4 vert_1;//local_4
	}lolo;

	C_0066CE40(bp28, bp18, &lolo.vert_0);//[optimized]still another vector/matrix operation(w=1)
	if(lolo.vert_0.f_0c > 0.0) {
		C_0066CE40(bp28, bp1c, &lolo.vert_1);//[optimized]still another vector/matrix operation(w=1)
		if(lolo.vert_1.f_0c > 0.0) {
			C_0066CE40(bp28, bp20, &lolo.vert_2);//[optimized]still another vector/matrix operation(w=1)
			if(lolo.vert_2.f_0c > 0.0) {
				C_0066CE40(bp28, bp24, &lolo.vert_3);//[optimized]still another vector/matrix operation(w=1)
				if(lolo.vert_3.f_0c > 0.0) {
					if(C_0066E272(1, bp2c)) {
						lolo.rhw_0 = 1.0f / lolo.vert_0.f_0c;
						MK_VERTEX_NOTEXTURE_1(&(bp2c->f_70.asVertex[0]), lolo.local_18, lolo.vert_0.f_00 * lolo.rhw_0, lolo.vert_0.f_04 * lolo.rhw_0, lolo.vert_0.f_08 * lolo.rhw_0, lolo.rhw_0, dwColor_0);
						lolo.rhw_1 = 1.0f / lolo.vert_1.f_0c;
						MK_VERTEX_NOTEXTURE_1(&(bp2c->f_70.asVertex[1]), lolo.local_20, lolo.vert_1.f_00 * lolo.rhw_1, lolo.vert_1.f_04 * lolo.rhw_1, lolo.vert_1.f_08 * lolo.rhw_1, lolo.rhw_1, dwColor_1);
						lolo.rhw_2 = 1.0f / lolo.vert_2.f_0c;
						MK_VERTEX_NOTEXTURE_1(&(bp2c->f_70.asVertex[2]), lolo.local_22, lolo.vert_2.f_00 * lolo.rhw_2, lolo.vert_2.f_04 * lolo.rhw_2, lolo.vert_2.f_08 * lolo.rhw_2, lolo.rhw_2, dwColor_2);
						lolo.rhw_3 = 1.0f / lolo.vert_3.f_0c;
						MK_VERTEX_NOTEXTURE_1(&(bp2c->f_70.asVertex[3]), lolo.local_24, lolo.vert_3.f_00 * lolo.rhw_3, lolo.vert_3.f_04 * lolo.rhw_3, lolo.vert_3.f_08 * lolo.rhw_3, lolo.rhw_3, dwColor_3);
					}
				}
			}
		}
	}
}

//render quad?
void C_0077BE95(LPD3DMATRIX bp08, struct t_dx_sfx_e0 *bp0c, struct t_chocobo_data_floatDG4 *bp10) {
	C_0077BCA4(bp10->f_30.rgba, bp10->f_34.rgba, bp10->f_38.rgba, bp10->f_3c.rgba, &(bp10->f_00), &(bp10->f_0c), &(bp10->f_18), &(bp10->f_24), bp08, bp0c);//[static]render quad?
}

//[unused]render quad?
void __0077BEDF(LPD3DMATRIX bp08, struct t_dx_sfx_e0 *bp0c, struct SVECTOR *bp10, struct SVECTOR *bp14, struct SVECTOR *bp18, struct SVECTOR *bp1c, unsigned bp20, unsigned bp24, unsigned bp28, unsigned bp2c) {
	struct {
		struct t_g_drv_0c local_17;
		struct t_g_drv_0c local_14;
		tRGBA local_11;
		struct t_g_drv_0c local_10;
		tRGBA local_7;
		tRGBA local_6;
		tRGBA local_5;
		unsigned char local_4; char _ocal_4[3];
		struct t_g_drv_0c local_3;
	}lolo;

	lolo.local_6.rgba = bp20 | (0xff << 24);
	SWAP(lolo.local_6.c.r, lolo.local_6.c.b, lolo.local_4);

	lolo.local_5.rgba = bp24 | (0xff << 24);
	SWAP(lolo.local_5.c.r, lolo.local_5.c.b, lolo.local_4);

	lolo.local_11.rgba = bp28 | (0xff << 24);
	SWAP(lolo.local_11.c.r, lolo.local_11.c.b, lolo.local_4);

	lolo.local_7.rgba = bp2c | (0xff << 24);
	SWAP(lolo.local_7.c.r, lolo.local_7.c.b, lolo.local_4);

	lolo.local_17.f_00 = (float)bp10->f_00;
	lolo.local_17.f_04 = (float)bp10->f_02;
	lolo.local_17.f_08 = (float)bp10->f_04;

	lolo.local_10.f_00 = (float)bp14->f_00;
	lolo.local_10.f_04 = (float)bp14->f_02;
	lolo.local_10.f_08 = (float)bp14->f_04;

	lolo.local_14.f_00 = (float)bp18->f_00;
	lolo.local_14.f_04 = (float)bp18->f_02;
	lolo.local_14.f_08 = (float)bp18->f_04;

	lolo.local_3.f_00 = (float)bp1c->f_00;
	lolo.local_3.f_04 = (float)bp1c->f_02;
	lolo.local_3.f_08 = (float)bp1c->f_04;

	C_0077BCA4(lolo.local_6.rgba, lolo.local_5.rgba, lolo.local_11.rgba, lolo.local_7.rgba, &lolo.local_17, &lolo.local_10, &lolo.local_14, &lolo.local_3, bp08, bp0c);//[static]render quad?
}

void C_0077C04B(struct t_chocobo_local_quad_2 *bp08, LPD3DMATRIX bp0c, struct t_dx_sfx_e0 *bp10) {
	struct {
		struct t_dx_rend_vertex_20 *local_25;
		float rhw_3;//local_24
		struct t_dx_rend_vertex_20 *local_23;
		float rhw_2;//local_22
		struct t_dx_rend_vertex_20 *local_21;
		float rhw_1;//local_20
		struct t_dx_rend_vertex_20 *local_19;
		float rhw_0;//local_18
		struct tVECTOR_F4 vert_2;//local_17
		struct tVECTOR_F4 vert_3;//local_13
		struct tVECTOR_F4 vert_0;//local_9
		struct tVECTOR_F4 vert_1;//local_5
		unsigned dwColor;//local_1
	}lolo;

	lolo.dwColor = 0xffffffff;
	C_0066CE40(bp0c, &(bp08->vert_0), &lolo.vert_0);//[optimized]still another vector/matrix operation(w=1)
	if(lolo.vert_0.f_0c > 0.0) {
		C_0066CE40(bp0c, &(bp08->vert_1), &lolo.vert_1);//[optimized]still another vector/matrix operation(w=1)
		if(lolo.vert_1.f_0c > 0.0) {
			C_0066CE40(bp0c, &(bp08->vert_2), &lolo.vert_2);//[optimized]still another vector/matrix operation(w=1)
			if(lolo.vert_2.f_0c > 0.0) {
				C_0066CE40(bp0c, &(bp08->vert_3), &lolo.vert_3);//[optimized]still another vector/matrix operation(w=1)
				if(lolo.vert_3.f_0c > 0.0) {
					if(C_0066E272(1, bp10)) {
						lolo.rhw_0 = 1.0f / lolo.vert_0.f_0c;
						MK_VERTEX_0(&(bp10->f_70.asVertex[0]), lolo.local_19, lolo.vert_0.f_00 * lolo.rhw_0, lolo.vert_0.f_04 * lolo.rhw_0, lolo.vert_0.f_08 * lolo.rhw_0, lolo.rhw_0, lolo.dwColor, bp08->fU_0, bp08->fV_0);
						lolo.rhw_1 = 1.0f / lolo.vert_1.f_0c;
						MK_VERTEX_0(&(bp10->f_70.asVertex[1]), lolo.local_21, lolo.vert_1.f_00 * lolo.rhw_1, lolo.vert_1.f_04 * lolo.rhw_1, lolo.vert_1.f_08 * lolo.rhw_1, lolo.rhw_1, lolo.dwColor, bp08->fU_1, bp08->fV_1);
						lolo.rhw_2 = 1.0f / lolo.vert_2.f_0c;
						MK_VERTEX_0(&(bp10->f_70.asVertex[2]), lolo.local_23, lolo.vert_2.f_00 * lolo.rhw_2, lolo.vert_2.f_04 * lolo.rhw_2, lolo.vert_2.f_08 * lolo.rhw_2, lolo.rhw_2, lolo.dwColor, bp08->fU_2, bp08->fV_2);
						lolo.rhw_3 = 1.0f / lolo.vert_3.f_0c;
						MK_VERTEX_0(&(bp10->f_70.asVertex[3]), lolo.local_25, lolo.vert_3.f_00 * lolo.rhw_3, lolo.vert_3.f_04 * lolo.rhw_3, lolo.vert_3.f_08 * lolo.rhw_3, lolo.rhw_3, lolo.dwColor, bp08->fU_3, bp08->fV_3);
					}
				}
			}
		}
	}
}

//projected Z?
float C_0077C2AC(struct SVECTOR *bp08, LPD3DMATRIX bp0c) {
	struct {
		struct t_g_drv_0c local_8;
		struct tVECTOR_F4 vert;//local_5
		float rhw;//local_1
	}lolo;

	lolo.local_8.f_00 = (float)bp08->f_00;
	lolo.local_8.f_04 = (float)bp08->f_02;
	lolo.local_8.f_08 = (float)bp08->f_04;
	C_0066CE40(bp0c, &lolo.local_8, &lolo.vert);//[optimized]still another vector/matrix operation(w=1)
	if(lolo.vert.f_0c > 0.0) {
		lolo.rhw = 1.0f / lolo.vert.f_0c;
		return lolo.vert.f_08 * lolo.rhw;
	}

	return 0.999f;
}

void __0077C323(
	LPD3DMATRIX bp08,
	struct t_dx_sfx_e0 *bp0c,
	struct SVECTOR *pVert_0/*bp10*/,
	struct SVECTOR *pVert_1/*bp14*/,
	struct SVECTOR *pVert_2/*bp18*/,
	struct SVECTOR *pVert_3/*bp1c*/,
	float fU_0/*bp20*/, float fV_0/*bp24*/,
	float fU_1/*bp28*/, float fV_1/*bp2c*/,
	float fU_2/*bp30*/, float fV_2/*bp34*/,
	float fU_3/*bp38*/, float fV_3/*bp3c*/
) {
	struct t_chocobo_local_quad_2 local_20;

	local_20.vert_0.f_00 = (float)pVert_0->f_00; local_20.vert_0.f_04 = (float)pVert_0->f_02; local_20.vert_0.f_08 = (float)pVert_0->f_04;
	local_20.vert_1.f_00 = (float)pVert_1->f_00; local_20.vert_1.f_04 = (float)pVert_1->f_02; local_20.vert_1.f_08 = (float)pVert_1->f_04;
	local_20.vert_2.f_00 = (float)pVert_2->f_00; local_20.vert_2.f_04 = (float)pVert_2->f_02; local_20.vert_2.f_08 = (float)pVert_2->f_04;
	local_20.vert_3.f_00 = (float)pVert_3->f_00; local_20.vert_3.f_04 = (float)pVert_3->f_02; local_20.vert_3.f_08 = (float)pVert_3->f_04;

	local_20.fU_0 = fU_0; local_20.fV_0 = fV_0;
	local_20.fU_1 = fU_1; local_20.fV_1 = fV_1;
	local_20.fU_2 = fU_2; local_20.fV_2 = fV_2;
	local_20.fU_3 = fU_3; local_20.fV_3 = fV_3;

	C_0077C04B(&local_20, bp08, bp0c);
}

void C_0077C430(struct t_aa0 *bp08, struct t_rsd_74 *bp0c) {
	C_0076B87E();
	C_0076BAFD(bp08, bp0c);
	C_00772357();
	C_007757CE(0, 0, 0);
	C_0076BA66();
}

void C_0077CCFF(void);//other 3D models?
void C_0077CEA9(void);

//chocobo:refresh
void C_0077C462() {
	struct {
		int j;//bp_70
		int bp_6c;
		int bp_68;
		int dwTemp;//bp_64
		int bp_60[6];
		int bp_48[6];
		struct t_chocobo_3c *bp_30;
		char _p_2c[4];
		struct t_chocobo_3c *bp_28;
		int i;//bp_24
		int dwAnimationFrame;//bp_20
		int bp_1c_unused[4];
		struct t_chocobo_a4 *bp_0c;
		int bp_08;
		int dwAnmNum;//bp_04
	}lolo;

	//-- --
	lolo.bp_1c_unused[0] = 0;
	lolo.bp_1c_unused[1] = 0x190;
	lolo.bp_1c_unused[2] = 0x1e8;
	lolo.bp_1c_unused[3] = 0;
	//-- --
	lolo.bp_08 = 0;
	while(lolo.bp_08 == 0) {
		switch(D_00E3B740) {
			case 0://"init"
				if(D_00DC0AE4 == 0) {
					C_00776375();
					D_00E3B740 = 1;//to "bet menu"
				} else {
					D_00E3B740 = 2;//to "start race"
				}
				lolo.bp_08 = 0;
				D_00E73EFC = 0;
			break;
			case 1://"bet menu"
				lolo.bp_08 = 1;
				C_00776452();//refresh "bet menu"
			break;
			case 2://"start race"
				lolo.bp_08 = 0;
				C_0077CEA9();
				D_00E71624 = 0;
				D_00E710EC = 0xff;
				D_00E715D4 = -0x10;
				for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
					if(D_00E71128 && D_00E71158[lolo.i].f_92 == 0)
						continue;
					D_00E71158[lolo.i].dwStamina <<= 1;
					D_00E71158[lolo.i].dwMaxStamina <<= 1;
				}//end for

				D_00E71664->f_00 = 0x10;
				D_00E71664->f_04[0] = 8;
				C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);

				D_00E73EE8 = D_00E73EEC = 0;
				D_00E71018 = 0;
				D_00E3B740 = 3;//to "race"
				D_00E73EFC = 0;
			break;
			case 3://"race"
				lolo.bp_08 = 1;
				if(D_00E710E0 > 0xBB8) {//else 0077C69F
					D_00E715D4 = 0x10;
					if(D_00E73EFC == 0) {//else 0077C69F
						D_00E71664->f_00 = 0xc1;
						D_00E71664->f_04[0] = 0x3c;
						D_00E71664->f_04[1] = 0;
						C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0, 0);
						D_00E73EFC = 1;
					}
				}
				D_00E71104 = 0;
				C_007718B0();//chocobo:refresh camera?
				//-- --
				D_00E73EF0 = &(D_00E715FC[D_00E71158[D_00E71624].f_00]);
				if(D_00E3B74C == 1 && D_00E71158[D_00E71624].f_00 > 0x35 && D_00E71158[D_00E71624].f_00 < 0x9b)
					D_00E73EF0->f_14.c.a = 1;
				//-- skydome --
				if(D_00E73EF0->f_14.c.a & 1)
					C_00770206();//render skydome
				//-- some transparent color layer --
				if(D_00E73EF0->f_14.c.a & 2) {
					D_00E3B908.f_04.c.r = D_00E73EF0->f_14.c.r;
					D_00E3B908.f_04.c.g = D_00E73EF0->f_14.c.g;
					D_00E3B908.f_04.c.b = D_00E73EF0->f_14.c.b;
					C_0077A7D0(&D_00E3B908);//draw a color rectangle?
				}
				//-- --
				C_00773668();
				C_00770291();//render track?
				C_0077CCFF();//other 3D models?
				//-- render chocobos --
				for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
					if(D_00E71020[lolo.i]) {
						lolo.bp_0c = &(D_00E71158[lolo.i]);
						lolo.dwAnmNum = lolo.bp_0c->wAnmNum;
						lolo.dwAnimationFrame = lolo.bp_0c->wAnimationCounter >> 8;
						lolo.bp_28 = &(D_00E719E8[lolo.bp_0c->f_92]);
						lolo.bp_30 = &(D_00E719E8[lolo.bp_0c->f_90]);

						lolo.bp_28->wPrevAnmNum = lolo.bp_28->wAnmNum;
						lolo.bp_28->wAnmNum = lolo.dwAnmNum;
						lolo.bp_28->dwAnimationFrame = lolo.dwAnimationFrame;

						lolo.bp_30->wPrevAnmNum = lolo.bp_30->wPrevAnmNum;/*???should be dwAnmNum???*/
						lolo.bp_30->wAnmNum = lolo.dwAnmNum;
						lolo.bp_30->dwAnimationFrame = lolo.dwAnimationFrame;
						//-- chocobo --
						C_0077B7E2(lolo.bp_28);//refresh rotation[3D model]?
						//-- jockey --
						C_0077B7E2(lolo.bp_30);//refresh rotation[3D model]?
					}
				}//end for
				//-- counter before start --
				D_00E715D8 ++;
				if(D_00E715D8 == 60) {//else 0077C8E1
					D_00E710F8 = -1;
					for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
						if(D_00E71158[lolo.i].f_a0)
							D_00E71158[lolo.i].f_48 = 60;
						else
							D_00E71158[lolo.i].f_48 = 10;
					}//end for
				}
				//-- set previous input mask --
				D_00E71100 = D_00E71620;
				//-- <numpad 5> skip end of race --
				if((D_00E71620 & BIT(CH_KEY_START)) && D_00E71038) {
					D_00E715D4 = 0x10;

					D_00E71664->f_00 = 0xc1;
					D_00E71664->f_04[0] = 0x3c;
					D_00E71664->f_04[1] = 0;
					C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], D_00E71664->f_04[1], 0, 0, 0, 0, 0 ,0);
				}
				//-- --
				C_0076E149();//chocobo:compute input mask
				//-- automatic/manual --
				if(D_00E71100 != D_00E71620 && D_00E71128 && (D_00E71620 & BIT(CH_KEY_ASSIST)))
					D_00E71158[0].wIsAutomatic = D_00E71158[0].wIsAutomatic?0:1;
				//-- [PgDn][Target] .. regain stamina? --
				if(D_00E73EF4) {
					if(D_00E71620 & BIT(CH_KEY_PGDN)) {
						D_00E73EF4 = D_00E73EF4 == 0;
						D_00E73EF8 ++;
					}
				} else {
					if(D_00E71620 & BIT(CH_KEY_TARGET)) {
						D_00E73EF4 = D_00E73EF4 == 0;
						D_00E73EF8 ++;
					}
				}
				if(D_00E71128 && D_00E73EF8 > 0xa) {
					D_00E71158[0].dwStamina += D_00E71158[0].dwMaxStamina / 150;
					if(D_00E71158[0].dwStamina > D_00E71158[0].dwMaxStamina)
						D_00E71158[0].dwStamina = D_00E71158[0].dwMaxStamina;
					D_00E73EF8 = 0;
				}
				//-- --
				if(D_00E710EC > 0xff && D_00E715D4 > 0) {
					D_00E715D4 = 0;
					D_00E3B740 = 4;//to "after the race"
				}
				if(D_00E3B740 == 3) {
					D_00E71158[0].f_94 --;
					D_00E71018 ++;
					C_0076E2B0();//refresh race 2D stuff
					C_0077946A();//refresh fade in/out
				}
				C_0077B2CA();//chocobo:renderer?
			break;
			case 4://"after the race"
				lolo.bp_68 = 0;
				lolo.bp_6c = 0;
				lolo.bp_08 = 0;
				for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
					if(D_00E71158[lolo.i].f_70 > lolo.bp_68)
						lolo.bp_68 = D_00E71158[lolo.i].f_70;
				}//end for
				lolo.bp_68 ++;
				for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
					if(D_00E71158[lolo.i].f_70 == 0) {
						lolo.bp_48[lolo.bp_6c] = lolo.i;
						lolo.bp_60[lolo.bp_6c] = D_00E71158[lolo.i].f_00;
						lolo.bp_6c ++;
					}
				}//end for
				for(lolo.i = 0; lolo.i < lolo.bp_6c; lolo.i ++) {
					for(lolo.j = 0; lolo.j < lolo.bp_6c - 1; lolo.j ++) {
						if(lolo.bp_60[lolo.j] < lolo.bp_60[lolo.i]) {
							SWAP(lolo.bp_60[lolo.j], lolo.bp_60[lolo.i], lolo.dwTemp);
							SWAP(lolo.bp_48[lolo.j], lolo.bp_48[lolo.i], lolo.dwTemp);
						}
					}//end for
				}//end for
				for(lolo.i = 0; lolo.i < lolo.bp_6c; lolo.i ++) {
					D_00E71158[lolo.bp_48[lolo.i]].f_70 = lolo.bp_68;
					lolo.bp_68 ++;
				}//end for
				//-- --
				D_00E71664->f_00 = 0xe4;
				D_00E71664->f_04[0] = 0x40;
				C_00740D80(D_00E71664->f_00, D_00E71664->f_04[0], 0, 0, 0, 0, 0, 0, 0);
				//-- --
				if(D_00DC0AE4 == 0) {
					C_00778A3C();
					D_00E3B740 = 5;//to "bet results"
				} else {
					D_00E3B740 = 6;//to "transition to end"
				}
			break;
			case 5://"bet results"
				C_00778C5D();//refresh "bet results"
				lolo.bp_08 = 1;
			break;
			case 6://"transition to end"
				D_00DC0AF5 = D_00E71158[0].f_70 - 1;
				D_00E3BAD0 = 1;
				lolo.bp_08 = 1;
			break;
		}//end switch
	}//end while
}

void C_0077CD69(int, int);

//other 3D models?
void C_0077CCFF() {
	struct {
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_1 = D_00E7112C->f_00;
	lolo.local_3 = (D_00E71124 + lolo.local_1) % lolo.local_1;
	lolo.local_2 = (D_00E70FE8 + lolo.local_1) % lolo.local_1;
	if(lolo.local_3 > lolo.local_2) {
		C_0077CD69(0, lolo.local_2);
		C_0077CD69(lolo.local_3, lolo.local_1);
	} else {
		C_0077CD69(lolo.local_3, lolo.local_2);
	}
}

void C_0077CD69(int bp08, int bp0c) {
	struct {
		int local_7;
		struct t_chocobo_3c *local_6;
		struct t_chocobo_local_10_xxx *local_5;
		char _ocal_4[8];
		int i;//local_2
		int local_1;
	}lolo;

	for(lolo.i = bp08; lolo.i < bp0c; lolo.i ++) {
		lolo.local_7 = D_00E715FC[lolo.i].f_11;
		if(lolo.local_7) {
			lolo.local_5 = &(D_00E7112C->f_40[lolo.local_7 - 1]);
			lolo.local_1 = lolo.local_5->f_0f;
			lolo.local_6 = &(D_00E719E8[lolo.local_1]);
			//-- pos --
			lolo.local_6->f_00 = lolo.local_5->f_00;
			lolo.local_6->f_02 = lolo.local_5->f_02;
			lolo.local_6->f_04 = lolo.local_5->f_04;
			//-- rot --
			lolo.local_6->f_09 = lolo.local_5->f_0c;
			lolo.local_6->f_0a = lolo.local_5->f_0d;
			lolo.local_6->f_0b = lolo.local_5->f_0e;
			//-- --
			lolo.local_6->dwAnimationFrame = lolo.local_5->wAnimationFrame;
			C_0077B7E2(lolo.local_6);//refresh rotation[3D model]?
			lolo.local_5->wAnimationFrame += lolo.local_5->wAnimtionIncr;
			if(lolo.local_5->wAnimationFrame >= lolo.local_6->dwMaxAnimationFrame) {
				if(lolo.local_5->wFlags & 2)
					lolo.local_5->wAnimationFrame = 0;
				else
					lolo.local_5->wAnimationFrame = lolo.local_6->dwMaxAnimationFrame;
			}
			if(lolo.local_5->wAnimationFrame < 0)
				lolo.local_5->wAnimationFrame = 0;
		}
	}//end for
}

void C_0077CEA9() {
	struct {
		struct t_chocobo_3c *local_4;
		struct t_chocobo_3c *local_3;
		int i;//local_2
		struct t_chocobo_a4 *local_1;
	}lolo;

	for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
		lolo.local_1 = &(D_00E71158[lolo.i]);
		lolo.local_3 = &(D_00E719E8[lolo.local_1->f_92]);
		lolo.local_4 = &(D_00E719E8[lolo.local_1->f_90]);
		lolo.local_3->f_09 = 0xc0; lolo.local_4->f_09 = 0xc0;
		lolo.local_3->f_0a = 0; lolo.local_4->f_0a = 0;
		lolo.local_3->f_0b = 0x80; lolo.local_4->f_0b = 0x80;
	}//end for
}

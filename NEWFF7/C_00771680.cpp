/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- camera related?

#include "ff7.h"
#include "chocobo_data.h"

#include <math.h>

#define _CIsqrt sqrt
#if (_MSC_VER < 1500)
#define _CIatan2 atan2
#else
#define _CIatan2(a,b) atan2((double)(a), (double)(b))
#endif
////////////////////////////////////////
extern short D_0097A108[][3];
extern struct t_chocobo_cameraInfo D_0097A120[];
extern struct t_chocobo_cameraInfo D_0097A2A0[];
////////////////////////////////////////
extern int D_00E3BAF4;

extern int D_00E70FE8;
extern int D_00E71018;
extern int D_00E7103C;
extern int D_00E7104C;
extern int D_00E71054;
extern int D_00E710E0;
extern int D_00E710E4;
extern struct t_chocobo_cameraInfo D_00E71110;
extern int D_00E71134;
extern struct MATRIX D_00E71138;//set but not read
extern struct t_chocobo_data_18 *D_00E715FC;

extern struct SVECTOR D_00E72E10;
extern D3DMATRIX D_00E72E18;
extern short D_00E72E58;
extern short D_00E72E5C;
extern D3DMATRIX D_00E72E60;
extern struct SVECTOR D_00E72EA0;
extern struct MATRIX D_00E72EB0;
extern struct SVECTOR D_00E72ED0;//camera pos?
extern struct SVECTOR D_00E72ED8;//camera LookAt?
extern int D_00E72EE0;
////////////////////////////////////////
struct t_chocobo_cameraInfo *C_00771680(int bp08) {
	if(bp08 == 0)
		return D_0097A120;
	else
		return D_0097A2A0;
}

//chocobo:set camera info?
void C_00771697(short bp08, short bp0c) {
	if(D_00E71128 == -1) {
		D_00E71110.bType = -1;
		D_00E72E58 = bp0c;
		D_00E72E5C = bp08;
	} else {
		D_00E72EE0 = -1;
		if(bp08 != -1) {
			D_00E7103C = D_00E71624 = bp0c;
			D_00E71110 = D_00E7112C->f_38[bp08 - 1];
		}
	}
}

//compute camera transform?
void C_0077170F(struct MATRIX *bp08, struct SVECTOR *sCamPos/*bp0c*/, struct SVECTOR *sLookAt/*bp10*/) {
	struct {
		D3DMATRIX sMatRotYX;//local_117
		D3DMATRIX sMatRotX;//local_101
		float fRotZ;//local_85
		D3DMATRIX sMatRotZ;//local_84
		float fRotY;//local_68
		int _ocal_67[4];
		struct VECTOR unused_local_63;
		int local_59[21];
		D3DMATRIX sMatRotYXZ;//local_38
		struct VECTOR local_22;
		float fAngle;//local_18
		float fRotX;//local_17
		D3DMATRIX sMatRotY;//local_16
	}lolo;

	VECTOR_init(lolo.unused_local_63, 0, 0xfff, 0);

	lolo.local_22.f_00 = sLookAt->f_00 - sCamPos->f_00;
	lolo.local_22.f_04 = sLookAt->f_02 - sCamPos->f_02;
	lolo.local_22.f_08 = sLookAt->f_04 - sCamPos->f_04;

	lolo.local_22.f_00 = -lolo.local_22.f_00;

	lolo.fAngle = _CIatan2((float)lolo.local_22.f_04, _CIsqrt((float)(lolo.local_22.f_00 * lolo.local_22.f_00 + lolo.local_22.f_08 * lolo.local_22.f_08)));
	lolo.fRotX = C_0067A268(lolo.fAngle);//radian2degree?
	C_0067BE13(lolo.fRotX, &lolo.sMatRotX);//dx_mat:x_rotate(1)

	lolo.fAngle = _CIatan2(lolo.local_22.f_00, lolo.local_22.f_08);
	lolo.fRotY = C_0067A268(lolo.fAngle);//radian2degree?
	C_0067BE71(lolo.fRotY, &lolo.sMatRotY);//dx_mat:y_rotate(1)

	lolo.fRotZ = 180.0f;
	C_0067BECE(lolo.fRotZ, &lolo.sMatRotZ);//dx_mat:z_rotate(1)

	C_0066C56E(&lolo.sMatRotY, &lolo.sMatRotX, &lolo.sMatRotYX);//matrix multiplication 3x3?
	C_0066C56E(&lolo.sMatRotYX, &lolo.sMatRotZ, &lolo.sMatRotYXZ);//matrix multiplication 3x3?

	C_0066C53C(&lolo.sMatRotYXZ);//set matrix to "something"?
	C_0066134B(bp08, &lolo.sMatRotYXZ);//psx:D3DMATRIX to transformation(1)
	psx_ApplyMatrix(bp08, sCamPos, &lolo.local_22);
	bp08->f_12[0] = -lolo.local_22.f_00;
	bp08->f_12[1] = -lolo.local_22.f_04;
	bp08->f_12[2] = -lolo.local_22.f_08;
}

void C_00771F9F(void);
void C_007720B9(void);

//chocobo:refresh camera?
void C_007718B0() {
	C_00771F9F();
	switch(D_00E71110.bType) {
		default:
			D_00E71124 = (D_00E71530.f_00 + D_00E710E4 - 10) % D_00E710E4;
			D_00E70FE8 = (D_00E71124 + D_00E715FC[D_00E71530.f_00].f_12) % D_00E710E4;

			D_00E72ED0.f_02 = D_00E3BAF4 + D_0097A108[D_00E7104C][0];
			D_00E72ED0.f_00 = ((D_00E72ED0.f_00 + D_00E71530.f_10.f_00) - (psx_rsin(D_00E71530.f_30.f_02) >> D_0097A108[D_00E7104C][2])) / 2;
			D_00E72ED0.f_04 = ((D_00E72ED0.f_04 + D_00E71530.f_10.f_04) - ((-psx_rcos(D_00E71530.f_30.f_02)) >> D_0097A108[D_00E7104C][2])) / 2;

			D_00E72ED8.f_02 = (D_00E72ED8.f_02 * 3 + D_00E71158[D_00E71624].f_10.f_02 + D_0097A108[D_00E7104C][1]) / 4;
			D_00E72ED8.f_00 = (D_00E71158[D_00E71624].f_10.f_00 * 7 + D_00E71530.f_10.f_00) / 8;
			D_00E72ED8.f_04 = (D_00E71158[D_00E71624].f_10.f_04 * 7 + D_00E71530.f_10.f_04) / 8;
		break;
		case 1:
			D_00E72ED0 = D_00E71110.f_04;
			if(D_00E71110.f_01) {
				D_00E71124 = (D_00E71158[D_00E71624].f_00 + D_00E710E4 - 60) % D_00E710E4;
				D_00E70FE8 = (D_00E71124 + 120) % D_00E710E4;

				D_00E72ED8.f_00 = D_00E71158[D_00E71624].f_10.f_00;
				D_00E72ED8.f_02 = D_00E71158[D_00E71624].f_10.f_02;
				D_00E72ED8.f_04 = D_00E71158[D_00E71624].f_10.f_04;
			} else {
				D_00E71124 = D_00E71110.f_04.f_06;
				D_00E70FE8 = D_00E71110.f_0c.f_06;
				D_00E72ED8 = D_00E71110.f_0c;
			}
		break;
		case 2:
			if(D_00E71530.f_00 > D_00E71158[D_00E71624].f_00) {
				D_00E71124 = (D_00E71158[D_00E71624].f_00 + D_00E710E4 - 100) % D_00E710E4;
				D_00E70FE8 = D_00E71530.f_00 + 10;
			} else {
				D_00E71124 = D_00E71530.f_00 - 15;
				D_00E70FE8 = (D_00E71158[D_00E71624].f_00 + D_00E710E4 + 100) % D_00E710E4;
			}
			D_00E72ED0.f_02 = D_00E71530.f_10.f_02 + D_00E71110.f_02;
			D_00E72ED0.f_00 = D_00E71530.f_10.f_00 - (psx_rsin(D_00E71530.f_30.f_02) >> D_0097A108[D_00E7104C][2]);
			D_00E72ED0.f_04 = D_00E71530.f_10.f_04 - ((-psx_rcos(D_00E71530.f_30.f_02)) >> D_0097A108[D_00E7104C][2]);

			D_00E72ED8.f_00 = (D_00E71158[D_00E71624].f_10.f_00 + D_00E71530.f_10.f_00) / 2;
			D_00E72ED8.f_02 = (D_00E71158[D_00E71624].f_10.f_02 + D_00E71530.f_10.f_02) / 2 + 200;
			D_00E72ED8.f_04 = (D_00E71158[D_00E71624].f_10.f_04 + D_00E71530.f_10.f_04) / 2;
		break;
		case 3:
			D_00E71124 = (D_00E71158[D_00E71624].f_00 + D_00E710E4 - 60) % D_00E710E4;
			D_00E70FE8 = (D_00E71124 + 120) % D_00E710E4;

			D_00E72ED0.f_00 = D_00E71158[D_00E71624].f_10.f_00;
			D_00E72ED0.f_02 = D_00E71158[D_00E71624].f_10.f_02;
			D_00E72ED0.f_04 = D_00E71158[D_00E71624].f_10.f_04;

			D_00E72ED0.f_02 += psx_rcos(D_00E71018 * 16) / D_00E71110.f_04.f_00 + D_00E71110.f_04.f_02;
			D_00E72ED0.f_00 -= psx_rcos(D_00E71018 * 16) / D_00E71110.f_04.f_04;
			D_00E72ED0.f_04 -= psx_rsin(D_00E71018 * 16) / D_00E71110.f_04.f_06;

			D_00E72ED8.f_00 = D_00E71158[D_00E71624].f_10.f_00;
			D_00E72ED8.f_02 = D_00E71158[D_00E71624].f_10.f_02;
			D_00E72ED8.f_04 = D_00E71158[D_00E71624].f_10.f_04;
		break;
		case 0xa:
			D_00E71124 = D_00E710E4 - 20;
			D_00E70FE8 = 70;

			D_00E72ED0.f_00 = D_00E71158[D_00E71624].f_10.f_00;
			D_00E72ED0.f_02 = D_00E71158[D_00E71624].f_10.f_02;
			D_00E72ED0.f_04 = D_00E71158[D_00E71624].f_10.f_04;

			D_00E72ED0.f_02 += 800;
			D_00E72ED0.f_00 -= psx_rcos(D_00E71018 * 16) / 6;
			D_00E72ED0.f_04 -= psx_rsin(D_00E71018 * 16) / 6;

			D_00E72ED8.f_00 = D_00E71158[D_00E71624].f_10.f_00;
			D_00E72ED8.f_02 = D_00E71158[D_00E71624].f_10.f_02;
			D_00E72ED8.f_04 = D_00E71158[D_00E71624].f_10.f_04;

			D_00E72ED8.f_02 += 200;
		break;
	}//end switch
	C_007720B9();
}

void C_00771F9F() {
	int bp_04;

	if(D_00E71110.bType == 2) {//else 00772053
		switch(D_00E71110.f_01) {
			case 0: bp_04 = 0; break;
			case 1: bp_04 = D_00E71158[D_00E71624].f_04 / 2; break;
			case 2: bp_04 = D_00E71158[D_00E71624].f_04; break;
			case 3: bp_04 = D_00E71158[D_00E71624].f_04 * 2; break;
		}//end switch
		if(D_00E72EE0) {
			C_007757CE(D_00E71624, bp_04, D_00E71110.f_04.f_06);
			D_00E72EE0 = 0;
		}
	} else {
		C_0077554D(D_00E71624);
	}
	if((D_00E710E0 && D_00E71128 == 0) || (D_00E71128 && D_00E71158[0].f_7e)) {
		D_00E71624 = D_00E71134;
		D_00E71110.bType = 0xa;
		D_00E71054 = 1;
	}
}

void C_007720B9() {
	struct {
		struct SVECTOR unused_local_16;
		struct VECTOR unused_local_14;
		struct MATRIX local_10; char _ocal_10[2];
		int unused_local_2;
		struct t_aa0 *local_1;
	}lolo;

	//-- unused stuff --
	VECTOR_init(lolo.unused_local_14, 0, 0, 0);
	lolo.unused_local_2 = 0;
	SVECTOR_init(lolo.unused_local_16, 0, 0, 0);
	//-- --
	if(D_00E71054) {
		D_00E72E10 = D_00E72ED0;
		D_00E72EA0 = D_00E72ED8;
		D_00E71054 = 0;
	}
	//-- null matrix --
	lolo.local_10.f_00[0][0] = 0; lolo.local_10.f_00[0][1] = 0; lolo.local_10.f_00[0][2] = 0;
	lolo.local_10.f_00[1][0] = 0; lolo.local_10.f_00[1][1] = 0; lolo.local_10.f_00[1][2] = 0;
	lolo.local_10.f_00[2][0] = 0; lolo.local_10.f_00[2][1] = 0; lolo.local_10.f_00[2][2] = 0;
	lolo.local_10.f_12[0] = 0;
	lolo.local_10.f_12[1] = 0;
	lolo.local_10.f_12[2] = 0;
	//-- --
	D_00E72EA0.f_00 = (D_00E72EA0.f_00 * 3 + D_00E72ED8.f_00) / 4;
	D_00E72EA0.f_02 = (D_00E72EA0.f_02 * 7 + D_00E72ED8.f_02) / 8;
	D_00E72EA0.f_04 = (D_00E72EA0.f_04 * 3 + D_00E72ED8.f_04) / 4;

	D_00E72E10.f_00 = (D_00E72E10.f_00 * 3 + D_00E72ED0.f_00) / 4;
	D_00E72E10.f_02 = (D_00E72E10.f_02 * 7 + D_00E72ED0.f_02) / 8;
	D_00E72E10.f_04 = (D_00E72E10.f_04 * 3 + D_00E72ED0.f_04) / 4;

	C_0077170F(&lolo.local_10, &D_00E72E10, &D_00E72EA0);//compute camera transform?
	D_00E73DB0 = D_00E71138 = lolo.local_10;
	C_00663813(&D_00E73DB0, &D_00E72EB0);//psx:TransposeMatrix+trans?
	psx_SetRotMatrix(&D_00E72EB0);
	psx_SetTransMatrix(&D_00E72EB0);
	lolo.local_1 = C_00676578();
	C_0077B9A9(lolo.local_1);
	C_006611FB(&D_00E73DB0, &D_00E72E18);//psx:transformation to D3DMATRIX(1)
	C_0067D2BF(&D_00E72E18, &D_00E72E60);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
}

//set animation increment?
void C_007722F6(short bp08) {
	if(bp08 > 0x80)
		D_00E7112C->f_40[bp08 - 0x80].wAnimtionIncr = -1;
	else
		D_00E7112C->f_40[bp08].wAnimtionIncr = 1;
}

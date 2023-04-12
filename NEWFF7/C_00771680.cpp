/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- camera

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
extern int D_00E7103C;//camera:tracking chocobo[unused]
extern int D_00E7104C;//index in D_0097A108[]
extern int D_00E71054;//flag:set camera pos/lookAt
extern int D_00E710E0;
extern int D_00E710E4;
extern struct t_chocobo_cameraInfo D_00E71110;
extern int D_00E71134;//first chocobo
extern struct MATRIX D_00E71138;//[set|not used]
extern struct t_chocobo_data_TrackElement *D_00E715FC;
////////////////////////////////////////
struct SVECTOR D_00E72E10;//camera pos[current]
D3DMATRIX D_00E72E18;//transformation matrix[for animated models]?
short D_00E72E58;//camera:tracking chocobo[unused]
short D_00E72E5C;//camera:event[unused]
D3DMATRIX D_00E72E60;//transformation x perspective[for static models]?
struct SVECTOR D_00E72EA0;//camera LookAt[current]
//char __00E72EA8[8];
struct MATRIX D_00E72EB0;
struct SVECTOR D_00E72ED0;//camera pos[target]
struct SVECTOR D_00E72ED8;//camera LookAt[target]
int D_00E72EE0;//flag:camera event?
//00E72EE4
////////////////////////////////////////
//chocobo:get camera info array
struct t_chocobo_cameraInfo *C_00771680(int bp08/*long/short race*/) {
	if(bp08 == 0)
		return D_0097A120;
	else
		return D_0097A2A0;
}

//chocobo:set camera event
void C_00771697(short wEvent/*bp08*/, short wChocobo/*bp0c*/) {
	if(D_00E71128 == -1) {
		D_00E71110.bType = -1;
		D_00E72E58 = wChocobo;
		D_00E72E5C = wEvent;
	} else {
		D_00E72EE0 = -1;
		if(wEvent != -1) {
			D_00E7103C = D_00E71624 = wChocobo;
			D_00E71110 = D_00E7112C->pCameraInfo[wEvent - 1];
		}
	}
}

//compute camera transform?
void C_0077170F(struct MATRIX *pMtxCam/*bp08*/, struct SVECTOR *sCamPos/*bp0c*/, struct SVECTOR *sLookAt/*bp10*/) {
	struct {
		D3DMATRIX sMatRotYX;//local_117
		D3DMATRIX sMatRotX;//local_101
		float fRotZ;//local_85
		D3DMATRIX sMatRotZ;//local_84
		float fRotY;//local_68
		char _ocal_67[0x10];
		struct VECTOR unused_local_63;
		char _ocal_59[0x54];
		D3DMATRIX sMatRotYXZ;//local_38
		struct VECTOR vect;//local_22
		float fAngle;//local_18
		float fRotX;//local_17
		D3DMATRIX sMatRotY;//local_16
	}lolo;

	//-- --
	VECTOR_init(lolo.unused_local_63, 0, 0xfff, 0);
	//-- --
	lolo.vect.f_00 = sLookAt->f_00 - sCamPos->f_00;
	lolo.vect.f_04 = sLookAt->f_02 - sCamPos->f_02;
	lolo.vect.f_08 = sLookAt->f_04 - sCamPos->f_04;

	lolo.vect.f_00 = -lolo.vect.f_00;
	//-- pitch --
	lolo.fAngle = _CIatan2((float)lolo.vect.f_04, _CIsqrt((float)(lolo.vect.f_00 * lolo.vect.f_00 + lolo.vect.f_08 * lolo.vect.f_08)));
	lolo.fRotX = C_0067A268(lolo.fAngle);//dx_mat:radian2degree?
	C_0067BE13(lolo.fRotX, &lolo.sMatRotX);//dx_mat:x_rotate(1)
	//-- yaw --
	lolo.fAngle = _CIatan2(lolo.vect.f_00, lolo.vect.f_08);
	lolo.fRotY = C_0067A268(lolo.fAngle);//dx_mat:radian2degree?
	C_0067BE71(lolo.fRotY, &lolo.sMatRotY);//dx_mat:y_rotate(1)
	//-- roll[fixed value] --
	lolo.fRotZ = 180.0f;
	C_0067BECE(lolo.fRotZ, &lolo.sMatRotZ);//dx_mat:z_rotate(1)
	//-- --
	C_0066C56E(&lolo.sMatRotY, &lolo.sMatRotX, &lolo.sMatRotYX);//matrix multiplication 3x3?
	C_0066C56E(&lolo.sMatRotYX, &lolo.sMatRotZ, &lolo.sMatRotYXZ);//matrix multiplication 3x3?

	C_0066C53C(&lolo.sMatRotYXZ);//set matrix to "something"?
	C_0066134B(pMtxCam, &lolo.sMatRotYXZ);//psx:D3DMATRIX to transformation(1)
	//-- --
	psx_ApplyMatrix(pMtxCam, sCamPos, &lolo.vect);
	pMtxCam->f_12[0] = -lolo.vect.f_00;
	pMtxCam->f_12[1] = -lolo.vect.f_04;
	pMtxCam->f_12[2] = -lolo.vect.f_08;
}

void C_00771F9F(void);//track chocobo?
void C_007720B9(void);//refresh camera's matrix stuff?

//chocobo:refresh camera?
void C_007718B0() {
	C_00771F9F();//track chocobo?
	//-- --
	switch(D_00E71110.bType) {
		default://
			//(used at start line and when the player is a jockey)
			//-- culling --
			D_00E71124 = (TRACKER_CHOCOBO.wPathT_cur + D_00E710E4 - 10) % D_00E710E4;
			D_00E70FE8 = (D_00E71124 + D_00E715FC[TRACKER_CHOCOBO.wPathT_cur].bCullDistance) % D_00E710E4;
			//-- pos --
			D_00E72ED0.f_02 = D_00E3BAF4 + D_0097A108[D_00E7104C][0];
			D_00E72ED0.f_00 = ((D_00E72ED0.f_00 + TRACKER_CHOCOBO.sPos_cur.f_00) - (psx_rsin(TRACKER_CHOCOBO.sRot_cur.f_02) >> D_0097A108[D_00E7104C][2])) / 2;
			D_00E72ED0.f_04 = ((D_00E72ED0.f_04 + TRACKER_CHOCOBO.sPos_cur.f_04) - ((-psx_rcos(TRACKER_CHOCOBO.sRot_cur.f_02)) >> D_0097A108[D_00E7104C][2])) / 2;
			//-- LookAt --
			D_00E72ED8.f_02 = (D_00E72ED8.f_02 * 3 + TARGET_CHOCOBO.sPos_cur.f_02 + D_0097A108[D_00E7104C][1]) / 4;
			D_00E72ED8.f_00 = (TARGET_CHOCOBO.sPos_cur.f_00 * 7 + TRACKER_CHOCOBO.sPos_cur.f_00) / 8;
			D_00E72ED8.f_04 = (TARGET_CHOCOBO.sPos_cur.f_04 * 7 + TRACKER_CHOCOBO.sPos_cur.f_04) / 8;
		break;
		case 1://fixed
			//-- pos --
			D_00E72ED0 = D_00E71110.sPos;
			//-- --
			if(D_00E71110.bParam) {
				//look at target
				//-- culling --
				D_00E71124 = (TARGET_CHOCOBO.wPathT_cur + D_00E710E4 - 60) % D_00E710E4;
				D_00E70FE8 = (D_00E71124 + 120) % D_00E710E4;
				//-- LookAt --
				D_00E72ED8.f_00 = TARGET_CHOCOBO.sPos_cur.f_00;
				D_00E72ED8.f_02 = TARGET_CHOCOBO.sPos_cur.f_02;
				D_00E72ED8.f_04 = TARGET_CHOCOBO.sPos_cur.f_04;
			} else {
				//look at point
				//-- culling --
				D_00E71124 = D_00E71110.sPos.f_06;
				D_00E70FE8 = D_00E71110.sLookAt.f_06;
				//-- LookAt --
				D_00E72ED8 = D_00E71110.sLookAt;
			}
		break;
		case 2://follow/track target
			//-- culling --
			if(TRACKER_CHOCOBO.wPathT_cur > TARGET_CHOCOBO.wPathT_cur) {
				D_00E71124 = (TARGET_CHOCOBO.wPathT_cur + D_00E710E4 - 100) % D_00E710E4;
				D_00E70FE8 = TRACKER_CHOCOBO.wPathT_cur + 10;
			} else {
				D_00E71124 = TRACKER_CHOCOBO.wPathT_cur - 15;
				D_00E70FE8 = (TARGET_CHOCOBO.wPathT_cur + D_00E710E4 + 100) % D_00E710E4;
			}
			//-- pos --
			D_00E72ED0.f_02 = TRACKER_CHOCOBO.sPos_cur.f_02 + D_00E71110.wHeight;
			D_00E72ED0.f_00 = TRACKER_CHOCOBO.sPos_cur.f_00 - (psx_rsin(TRACKER_CHOCOBO.sRot_cur.f_02) >> D_0097A108[D_00E7104C][2]);
			D_00E72ED0.f_04 = TRACKER_CHOCOBO.sPos_cur.f_04 - ((-psx_rcos(TRACKER_CHOCOBO.sRot_cur.f_02)) >> D_0097A108[D_00E7104C][2]);
			//-- LookAt --
			D_00E72ED8.f_00 = (TARGET_CHOCOBO.sPos_cur.f_00 + TRACKER_CHOCOBO.sPos_cur.f_00) / 2;
			D_00E72ED8.f_02 = (TARGET_CHOCOBO.sPos_cur.f_02 + TRACKER_CHOCOBO.sPos_cur.f_02) / 2 + 200;
			D_00E72ED8.f_04 = (TARGET_CHOCOBO.sPos_cur.f_04 + TRACKER_CHOCOBO.sPos_cur.f_04) / 2;
		break;
		case 3://rotate around target
			//-- culling --
			D_00E71124 = (TARGET_CHOCOBO.wPathT_cur + D_00E710E4 - 60) % D_00E710E4;
			D_00E70FE8 = (D_00E71124 + 120) % D_00E710E4;
			//-- pos --
			D_00E72ED0.f_00 = TARGET_CHOCOBO.sPos_cur.f_00;
			D_00E72ED0.f_02 = TARGET_CHOCOBO.sPos_cur.f_02;
			D_00E72ED0.f_04 = TARGET_CHOCOBO.sPos_cur.f_04;

			D_00E72ED0.f_02 += psx_rcos(D_00E71018 * 16) / D_00E71110.sPos.f_00 + D_00E71110.sPos.f_02;
			D_00E72ED0.f_00 -= psx_rcos(D_00E71018 * 16) / D_00E71110.sPos.f_04;
			D_00E72ED0.f_04 -= psx_rsin(D_00E71018 * 16) / D_00E71110.sPos.f_06;
			//-- LookAt --
			D_00E72ED8.f_00 = TARGET_CHOCOBO.sPos_cur.f_00;
			D_00E72ED8.f_02 = TARGET_CHOCOBO.sPos_cur.f_02;
			D_00E72ED8.f_04 = TARGET_CHOCOBO.sPos_cur.f_04;
		break;
		case 0xa://finish line(rotate around target)
			//-- culling --
			D_00E71124 = D_00E710E4 - 20;
			D_00E70FE8 = 70;
			//-- pos --
			D_00E72ED0.f_00 = TARGET_CHOCOBO.sPos_cur.f_00;
			D_00E72ED0.f_02 = TARGET_CHOCOBO.sPos_cur.f_02;
			D_00E72ED0.f_04 = TARGET_CHOCOBO.sPos_cur.f_04;

			D_00E72ED0.f_02 += 800;
			D_00E72ED0.f_00 -= psx_rcos(D_00E71018 * 16) / 6;
			D_00E72ED0.f_04 -= psx_rsin(D_00E71018 * 16) / 6;
			//-- LookAt --
			D_00E72ED8.f_00 = TARGET_CHOCOBO.sPos_cur.f_00;
			D_00E72ED8.f_02 = TARGET_CHOCOBO.sPos_cur.f_02;
			D_00E72ED8.f_04 = TARGET_CHOCOBO.sPos_cur.f_04;

			D_00E72ED8.f_02 += 200;
		break;
	}//end switch
	//-- --
	C_007720B9();//refresh camera's matrix stuff?
}

//track chocobo?
void C_00771F9F() {
	int dwSpeed;

	if(D_00E71110.bType == 2) {//else 00772053
		switch(D_00E71110.bParam) {
			case 0: dwSpeed = 0; break;
			case 1: dwSpeed = TARGET_CHOCOBO.wSpeed / 2; break;
			case 2: dwSpeed = TARGET_CHOCOBO.wSpeed; break;
			case 3: dwSpeed = TARGET_CHOCOBO.wSpeed * 2; break;
		}//end switch
		if(D_00E72EE0) {
			C_007757CE(D_00E71624, dwSpeed, D_00E71110.sPos.f_06);//chocobo:for camera(bType 2):track chocobo?
			D_00E72EE0 = 0;
		}
	} else {
		C_0077554D(D_00E71624);//chocobo:for camera:track chocobo?
	}
	//-- finish line --
	if((D_00E710E0 && D_00E71128 == 0) || (D_00E71128 && D_00E71158[0].wFinished)) {
		D_00E71624 = D_00E71134;
		D_00E71110.bType = 0xa;
		D_00E71054 = 1;
	}
}

//refresh camera's matrix stuff?
void C_007720B9() {
	struct {
		struct SVECTOR unused_local_16;
		struct VECTOR unused_local_14;
		struct MATRIX mtxCam; char _ocal_10[2];
		int unused_local_2;
		struct t_aa0 *local_1;
	}lolo;

	//-- unused stuff --
	VECTOR_init(lolo.unused_local_14, 0, 0, 0);
	lolo.unused_local_2 = 0;
	SVECTOR_init(lolo.unused_local_16, 0, 0, 0);
	//-- --
	if(D_00E71054) {
		D_00E72E10 = D_00E72ED0;//pos
		D_00E72EA0 = D_00E72ED8;//LookAt
		D_00E71054 = 0;
	}
	//-- null matrix --
	lolo.mtxCam.f_00[0][0] = 0; lolo.mtxCam.f_00[0][1] = 0; lolo.mtxCam.f_00[0][2] = 0;
	lolo.mtxCam.f_00[1][0] = 0; lolo.mtxCam.f_00[1][1] = 0; lolo.mtxCam.f_00[1][2] = 0;
	lolo.mtxCam.f_00[2][0] = 0; lolo.mtxCam.f_00[2][1] = 0; lolo.mtxCam.f_00[2][2] = 0;
	lolo.mtxCam.f_12[0] = 0;
	lolo.mtxCam.f_12[1] = 0;
	lolo.mtxCam.f_12[2] = 0;
	//-- LookAt --
	D_00E72EA0.f_00 = (D_00E72EA0.f_00 * 3 + D_00E72ED8.f_00) / 4;
	D_00E72EA0.f_02 = (D_00E72EA0.f_02 * 7 + D_00E72ED8.f_02) / 8;
	D_00E72EA0.f_04 = (D_00E72EA0.f_04 * 3 + D_00E72ED8.f_04) / 4;
	//-- pos --
	D_00E72E10.f_00 = (D_00E72E10.f_00 * 3 + D_00E72ED0.f_00) / 4;
	D_00E72E10.f_02 = (D_00E72E10.f_02 * 7 + D_00E72ED0.f_02) / 8;
	D_00E72E10.f_04 = (D_00E72E10.f_04 * 3 + D_00E72ED0.f_04) / 4;
	//-- --
	C_0077170F(&lolo.mtxCam, &D_00E72E10, &D_00E72EA0);//compute camera transform?
	D_00E73DB0 = D_00E71138 = lolo.mtxCam;
#if 1	//original code
	C_00663813(&D_00E73DB0, &D_00E72EB0);//psx:TransposeMatrix()+TransMatrix()[for chocobo]
	psx_SetRotMatrix(&D_00E72EB0);
	psx_SetTransMatrix(&D_00E72EB0);
#elif 0	//could also have been written like this:
	psx_TransposeMatrix(&D_00E73DB0, &D_00E72EB0);
	psx_SetRotMatrix(&D_00E72EB0);
	psx_SetTransMatrix(&D_00E73DB0);
#elif 0	//or like this:
	psx_TransposeMatrix(&D_00E73DB0, &D_00E72EB0);
	psx_TransMatrix(&D_00E72EB0, (struct VECTOR *)D_00E73DB0.f_12);
	psx_SetRotMatrix(&D_00E72EB0);
	psx_SetTransMatrix(&D_00E72EB0);
#endif
	//-- --
	//note: when calling this function here, it is the matrix from
	// the previous frame that will be used for 3D animated models.
	// is this a bug?
	lolo.local_1 = C_00676578();
	C_0077B9A9(lolo.local_1);//chocobo:set transformation matrix[3D models]?
	//-- --
	C_006611FB(&D_00E73DB0, &D_00E72E18);//psx:transformation to D3DMATRIX(1)
	C_0067D2BF(&D_00E72E18, &D_00E72E60);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
}

//chocobo:set animation event?
void C_007722F6(short bp08) {
	if(bp08 > 0x80)
		D_00E7112C->pScenaryModel[bp08 - 0x80].wAnimationIncr = -1;
	else
		D_00E7112C->pScenaryModel[bp08].wAnimationIncr = 1;
}

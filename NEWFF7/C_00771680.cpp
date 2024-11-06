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
	lolo.vect.vx = sLookAt->vx - sCamPos->vx;
	lolo.vect.vy = sLookAt->vy - sCamPos->vy;
	lolo.vect.vz = sLookAt->vz - sCamPos->vz;

	lolo.vect.vx = -lolo.vect.vx;
	//-- pitch --
	lolo.fAngle = _CIatan2((float)lolo.vect.vy, _CIsqrt((float)(lolo.vect.vx * lolo.vect.vx + lolo.vect.vz * lolo.vect.vz)));
	lolo.fRotX = dx_mat_radianToDegree(lolo.fAngle);
	C_0067BE13(lolo.fRotX, &lolo.sMatRotX);//dx_mat:x_rotate(1)
	//-- yaw --
	lolo.fAngle = _CIatan2(lolo.vect.vx, lolo.vect.vz);
	lolo.fRotY = dx_mat_radianToDegree(lolo.fAngle);
	C_0067BE71(lolo.fRotY, &lolo.sMatRotY);//dx_mat:y_rotate(1)
	//-- roll[fixed value] --
	lolo.fRotZ = 180.0f;
	C_0067BECE(lolo.fRotZ, &lolo.sMatRotZ);//dx_mat:z_rotate(1)
	//-- --
	fast_MatrixMultiplication3x3(&lolo.sMatRotY, &lolo.sMatRotX, &lolo.sMatRotYX);
	fast_MatrixMultiplication3x3(&lolo.sMatRotYX, &lolo.sMatRotZ, &lolo.sMatRotYXZ);

	fast_MatrixResetTrans(&lolo.sMatRotYXZ);
	C_0066134B(pMtxCam, &lolo.sMatRotYXZ);//psx:D3DMATRIX to transformation(1)
	//-- --
	psx_ApplyMatrix(pMtxCam, sCamPos, &lolo.vect);
	pMtxCam->t[0] = -lolo.vect.vx;
	pMtxCam->t[1] = -lolo.vect.vy;
	pMtxCam->t[2] = -lolo.vect.vz;
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
			D_00E72ED0.vy = D_00E3BAF4 + D_0097A108[D_00E7104C][0];
			D_00E72ED0.vx = ((D_00E72ED0.vx + TRACKER_CHOCOBO.sPos_cur.vx) - (psx_rsin(TRACKER_CHOCOBO.sRot_cur.vy) >> D_0097A108[D_00E7104C][2])) / 2;
			D_00E72ED0.vz = ((D_00E72ED0.vz + TRACKER_CHOCOBO.sPos_cur.vz) - ((-psx_rcos(TRACKER_CHOCOBO.sRot_cur.vy)) >> D_0097A108[D_00E7104C][2])) / 2;
			//-- LookAt --
			D_00E72ED8.vy = (D_00E72ED8.vy * 3 + TARGET_CHOCOBO.sPos_cur.vy + D_0097A108[D_00E7104C][1]) / 4;
			D_00E72ED8.vx = (TARGET_CHOCOBO.sPos_cur.vx * 7 + TRACKER_CHOCOBO.sPos_cur.vx) / 8;
			D_00E72ED8.vz = (TARGET_CHOCOBO.sPos_cur.vz * 7 + TRACKER_CHOCOBO.sPos_cur.vz) / 8;
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
				D_00E72ED8.vx = TARGET_CHOCOBO.sPos_cur.vx;
				D_00E72ED8.vy = TARGET_CHOCOBO.sPos_cur.vy;
				D_00E72ED8.vz = TARGET_CHOCOBO.sPos_cur.vz;
			} else {
				//look at point
				//-- culling --
				D_00E71124 = D_00E71110.sPos.pad;
				D_00E70FE8 = D_00E71110.sLookAt.pad;
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
			D_00E72ED0.vy = TRACKER_CHOCOBO.sPos_cur.vy + D_00E71110.wHeight;
			D_00E72ED0.vx = TRACKER_CHOCOBO.sPos_cur.vx - (psx_rsin(TRACKER_CHOCOBO.sRot_cur.vy) >> D_0097A108[D_00E7104C][2]);
			D_00E72ED0.vz = TRACKER_CHOCOBO.sPos_cur.vz - ((-psx_rcos(TRACKER_CHOCOBO.sRot_cur.vy)) >> D_0097A108[D_00E7104C][2]);
			//-- LookAt --
			D_00E72ED8.vx = (TARGET_CHOCOBO.sPos_cur.vx + TRACKER_CHOCOBO.sPos_cur.vx) / 2;
			D_00E72ED8.vy = (TARGET_CHOCOBO.sPos_cur.vy + TRACKER_CHOCOBO.sPos_cur.vy) / 2 + 200;
			D_00E72ED8.vz = (TARGET_CHOCOBO.sPos_cur.vz + TRACKER_CHOCOBO.sPos_cur.vz) / 2;
		break;
		case 3://rotate around target
			//-- culling --
			D_00E71124 = (TARGET_CHOCOBO.wPathT_cur + D_00E710E4 - 60) % D_00E710E4;
			D_00E70FE8 = (D_00E71124 + 120) % D_00E710E4;
			//-- pos --
			D_00E72ED0.vx = TARGET_CHOCOBO.sPos_cur.vx;
			D_00E72ED0.vy = TARGET_CHOCOBO.sPos_cur.vy;
			D_00E72ED0.vz = TARGET_CHOCOBO.sPos_cur.vz;

			D_00E72ED0.vy += psx_rcos(D_00E71018 * 16) / D_00E71110.sPos.vx + D_00E71110.sPos.vy;
			D_00E72ED0.vx -= psx_rcos(D_00E71018 * 16) / D_00E71110.sPos.vz;
			D_00E72ED0.vz -= psx_rsin(D_00E71018 * 16) / D_00E71110.sPos.pad;
			//-- LookAt --
			D_00E72ED8.vx = TARGET_CHOCOBO.sPos_cur.vx;
			D_00E72ED8.vy = TARGET_CHOCOBO.sPos_cur.vy;
			D_00E72ED8.vz = TARGET_CHOCOBO.sPos_cur.vz;
		break;
		case 0xa://finish line(rotate around target)
			//-- culling --
			D_00E71124 = D_00E710E4 - 20;
			D_00E70FE8 = 70;
			//-- pos --
			D_00E72ED0.vx = TARGET_CHOCOBO.sPos_cur.vx;
			D_00E72ED0.vy = TARGET_CHOCOBO.sPos_cur.vy;
			D_00E72ED0.vz = TARGET_CHOCOBO.sPos_cur.vz;

			D_00E72ED0.vy += 800;
			D_00E72ED0.vx -= psx_rcos(D_00E71018 * 16) / 6;
			D_00E72ED0.vz -= psx_rsin(D_00E71018 * 16) / 6;
			//-- LookAt --
			D_00E72ED8.vx = TARGET_CHOCOBO.sPos_cur.vx;
			D_00E72ED8.vy = TARGET_CHOCOBO.sPos_cur.vy;
			D_00E72ED8.vz = TARGET_CHOCOBO.sPos_cur.vz;

			D_00E72ED8.vy += 200;
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
			C_007757CE(D_00E71624, dwSpeed, D_00E71110.sPos.pad);//chocobo:for camera(bType 2):track chocobo?
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
		DECL_struct_MATRIX(mtxCam);
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
	lolo.mtxCam.m[0][0] = 0; lolo.mtxCam.m[0][1] = 0; lolo.mtxCam.m[0][2] = 0;
	lolo.mtxCam.m[1][0] = 0; lolo.mtxCam.m[1][1] = 0; lolo.mtxCam.m[1][2] = 0;
	lolo.mtxCam.m[2][0] = 0; lolo.mtxCam.m[2][1] = 0; lolo.mtxCam.m[2][2] = 0;
	lolo.mtxCam.t[0] = 0;
	lolo.mtxCam.t[1] = 0;
	lolo.mtxCam.t[2] = 0;
	//-- LookAt --
	D_00E72EA0.vx = (D_00E72EA0.vx * 3 + D_00E72ED8.vx) / 4;
	D_00E72EA0.vy = (D_00E72EA0.vy * 7 + D_00E72ED8.vy) / 8;
	D_00E72EA0.vz = (D_00E72EA0.vz * 3 + D_00E72ED8.vz) / 4;
	//-- pos --
	D_00E72E10.vx = (D_00E72E10.vx * 3 + D_00E72ED0.vx) / 4;
	D_00E72E10.vy = (D_00E72E10.vy * 7 + D_00E72ED0.vy) / 8;
	D_00E72E10.vz = (D_00E72E10.vz * 3 + D_00E72ED0.vz) / 4;
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
	psx_TransMatrix(&D_00E72EB0, (struct VECTOR *)D_00E73DB0.t);
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

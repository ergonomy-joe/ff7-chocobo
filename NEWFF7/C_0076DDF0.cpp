/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- input

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
//"condor"(C_005FAB70.cpp) and "chocobo"(C_0076DDF0.cpp)
// input modules are very similar.
////////////////////////////////////////
int D_0096E518[0xe][3] = {
	{DIK_LEFT,0,LOCAL_DIK_JOY_LEFT},
	{DIK_DOWN,0,LOCAL_DIK_JOY_DOWN},
	{DIK_RIGHT,0,LOCAL_DIK_JOY_RIGHT},
	{DIK_UP,0,LOCAL_DIK_JOY_UP},
	{DIK_F10,0,LOCAL_DIK_JOY_B1},
	{DIK_F5,0,LOCAL_DIK_JOY_B2},
	{DIK_F2,0,LOCAL_DIK_JOY_B3},
	{DIK_RSHIFT,0,LOCAL_DIK_JOY_B4},
	{DIK_SPACE,0,LOCAL_DIK_JOY_B5},
	{DIK_F4,0,LOCAL_DIK_JOY_B6},
	{DIK_F6,0,LOCAL_DIK_JOY_B7},
	{DIK_F7,0,LOCAL_DIK_JOY_B8},
	{DIK_F8,0,LOCAL_DIK_JOY_B9},
	{DIK_F9,0,LOCAL_DIK_JOY_BA}
};
////////////////////////////////////////
unsigned D_00E71620;//input mask
int D_00E71624;
int D_00E71628[15];
//00E71664
////////////////////////////////////////
//chobobo.input.reset?
void C_0076DDF0() {
	D_00E71628[0] = 0;
	D_00E71628[1] = 0;
	D_00E71628[2] = 0;
	D_00E71628[3] = 0;

	D_00E71628[5] = 0;
	D_00E71628[6] = 0;
	D_00E71628[7] = 0;
	D_00E71628[8] = 0;
	D_00E71628[9] = 0;
	D_00E71628[10] = 0;
	D_00E71628[11] = 0;
	D_00E71628[12] = 0;
	D_00E71628[13] = 0;
	D_00E71628[14] = 0;
}

int C_0076DECF(int);//get mask?

void __0076DE81() {
	struct {
		int dwMask;//local_2
		int i;//local_1
	}lolo;

	for(lolo.i = 0; lolo.i < 0xe; lolo.i ++) {
		lolo.dwMask = C_0076DECF(lolo.i);//get mask?
		PAD_setCommand(0, lolo.dwMask, D_0096E518[lolo.i][0]);
	}//end for
}

//get mask?
int C_0076DECF(int bp08) {
	switch(bp08) {
		case 0: return BIT(15);//left
		case 1: return BIT(14);//down
		case 2: return BIT(13);//right
		case 3: return BIT(12);//up
		case 4: return BIT(11);//start
		case 5: return BIT(8);//assist
		case 6: return BIT(7);//switch
		case 7: return BIT(6);//cancel
		case 8: return BIT(5);//ok
		case 9: return BIT(4);//menu
		case 10: return BIT(3);//PgDn
		case 11: return BIT(1);//target
		case 12: return BIT(2);//PgUp
		case 13: return BIT(0);//camera
	}//end switch

	return 200;
}

int C_0076E10D(int);//test triggered mask for choboco?
int C_0076E12B(int);//test pressed mask for chocobo?

//chocobo:refresh input
void C_0076DF8C() {
	struct t_aa0 *local_1;

	local_1 = C_00676578();
	PAD_refresh(local_1);
	if(C_0076E12B(PAD_UP)) D_00E71628[1] = 1;//up
	if(C_0076E12B(PAD_DOWN)) D_00E71628[2] = 1;//down
	if(C_0076E12B(PAD_LEFT)) D_00E71628[0] = 1;//left
	if(C_0076E12B(PAD_RIGHT)) D_00E71628[3] = 1;//right

	if(C_0076E12B(PAD_07)) D_00E71628[5] = 1;//switch
	if(C_0076E12B(PAD_05)) D_00E71628[6] = 1;//ok
	if(C_0076E10D(PAD_04)) D_00E71628[7] = 1;//menu
	if(C_0076E10D(PAD_08)) D_00E71628[14] = 1;//assist
	if(C_0076E12B(PAD_03)) D_00E71628[9] = 1;//PgDn
	if(C_0076E12B(PAD_01)) D_00E71628[10] = 1;//target
	if(C_0076E12B(PAD_02)) D_00E71628[11] = 1;//PgUp
	if(C_0076E10D(PAD_00)) D_00E71628[12] = 1;//camera
	if(C_0076E12B(PAD_06)) D_00E71628[8] = 1;//cancel
	if(C_0076E10D(PAD_11)) D_00E71628[13] = 1;//start
}

//test triggered mask for choboco?
int C_0076E10D(int bp08) {
	if(PAD_testTrigger(bp08))
		return 1;
	else
		return 0;
}

//test pressed mask for chocobo?
int C_0076E12B(int bp08) {
	if(PAD_test(bp08))
		return 1;
	else
		return 0;
}

//chocobo:compute input mask
void C_0076E149() {
	D_00E71620 = 
		(D_00E71628[0] << CH_KEY_LEFT) |
		(D_00E71628[2] << CH_KEY_DOWN) |
		(D_00E71628[3] << CH_KEY_RIGHT) |
		(D_00E71628[1] << CH_KEY_UP) |
		(D_00E71628[13] << CH_KEY_START) |
		(D_00E71628[14] << CH_KEY_ASSIST) |
		(D_00E71628[5] << CH_KEY_SWITCH) |
		(D_00E71628[8] << CH_KEY_CANCEL) |
		(D_00E71628[6] << CH_KEY_OK) |
		(D_00E71628[7] << CH_KEY_MENU) |
		(D_00E71628[9] << CH_KEY_PGDN) |
		(D_00E71628[10] << CH_KEY_TARGET) |
		(D_00E71628[11] << CH_KEY_PGUP) |
		(D_00E71628[12] << CH_KEY_CAMERA)
	;
#if (_MSC_VER < 1500)
	//
#else
	//extern int MAIN_inputMask2;
	//D_00E71620 |= (MAIN_inputMask2 << 0x10);
#endif
}

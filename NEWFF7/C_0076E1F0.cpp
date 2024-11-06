/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- sound FX

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
//-- long course --
int D_0096E5C0[9] = {
	0x026,
	0x0C5,
	0x097,
	0x18C,
	0x025,
	0x090,
	0x233,
	0x231,
	0x1D0
};
//0096E5E4  00 00 00 00
struct t_chocobo_data_SoundEventInfo D_0096E5E8[] = {
	{SOUND_OP_A4,{0x008,0x001,0,0,0,0}},
	{SOUND_OP_A5,{0x008,0x001,0,0,0,0}},
	{SOUND_OP_A6,{0x008,0x001,0,0,0,0}},
	{SOUND_OP_A7,{0x008,0x001,0,0,0,0}},
	{SOUND_OP_28,{0x040,0x026,0,0,0,0}},
	{SOUND_OP_29,{0x040,0x0C5,0,0,0,0}},
	{SOUND_OP_28,{0x05A,0x097,0,0,0,0}},
	{SOUND_OP_28,{0x18C,0x18C,0,0,0,0}},
	{SOUND_OP_A4,{0x078,0x000,0,0,0,0}},
	{SOUND_OP_E4,{0x07F,0x000,0,0,0,0}},
	{SOUND_OP_29,{0x040,0x025,0,0,0,0}},
	{SOUND_OP_2A,{0x028,0x090,0,0,0,0}},
	{SOUND_OP_2B,{0x068,0x090,0,0,0,0}},
	{SOUND_OP_E4,{0x040,0x090,0,0,0,0}},
	{SOUND_OP_A4,{0x001,0x07F,0,0,0,0}},
	{SOUND_OP_C1,{0x078,0x050,0,0,0,0}},
	{SOUND_OP_A4,{0x078,0x07F,0,0,0,0}},
	{SOUND_OP_A4,{0x078,0x028,0,0,0,0}},
	{SOUND_OP_29,{0x040,0x233,0,0,0,0}},
	{SOUND_OP_29,{0x040,0x231,0,0,0,0}},
	{SOUND_OP_28,{0x064,0x1D0,0,0,0,0}}
};
//-- short course --
int D_0096E738[7] = {
	0x026,
	0x0C5,
	0x0BF,
	0x17D,
	0x097,
	0x007,
	0x19A
};
//0096E754  00 00 00 00
struct t_chocobo_data_SoundEventInfo D_0096E758[] = {
	{SOUND_OP_A4,{0x008,0x001,0,0,0,0}},
	{SOUND_OP_A5,{0x008,0x001,0,0,0,0}},
	{SOUND_OP_A6,{0x008,0x001,0,0,0,0}},
	{SOUND_OP_A7,{0x008,0x001,0,0,0,0}},
	{SOUND_OP_28,{0x040,0x026,0,0,0,0}},
	{SOUND_OP_29,{0x020,0x0C5,0,0,0,0}},
	{SOUND_OP_28,{0x040,0x0BF,0,0,0,0}},
	{SOUND_OP_A4,{0x001,0x07F,0,0,0,0}},
	{SOUND_OP_C1,{0x078,0x064,0,0,0,0}},
	{SOUND_OP_29,{0x032,0x17D,0,0,0,0}},
	{SOUND_OP_A5,{0x010,0x07F,0,0,0,0}},
	{SOUND_OP_29,{0x05A,0x097,0,0,0,0}},
	{SOUND_OP_28,{0x03C,0x007,0,0,0,0}},
	{SOUND_OP_A5,{0x078,0x000,0,0,0,0}},
	{SOUND_OP_E4,{0x07F,0x000,0,0,0,0}},
	{SOUND_OP_E4,{0x040,0x000,0,0,0,0}},
	{SOUND_OP_A5,{0x03C,0x07F,0,0,0,0}},
	{SOUND_OP_29,{0x040,0x19A,0,0,0,0}}
};
////////////////////////////////////////
int *D_00E71668;//SFX list
int D_00E7166C;//# of SFX
////////////////////////////////////////
//chocobo:get sounds info
struct t_chocobo_data_SoundEventInfo *C_0076E1F0(int bp08/*long/short race*/) {
	if(bp08 == 0) {
		D_00E71668 = D_0096E5C0;
		D_00E7166C = 9;
		return D_0096E5E8;
	} else {
		D_00E71668 = D_0096E738;
		D_00E7166C = 7;
		return D_0096E758;
	}
}

//chocobo:load/prepare SFX
void C_0076E22F() {
	int i;//local_1

	for(i = 0; i < D_00E7166C; i ++)
		sound_load(D_00E71668[i], 0);
}

//chocobo:free SFX
void C_0076E26C() {
	int i;//local_1

	for(i = 0; i < D_00E7166C; i ++)
		sound_unload(D_00E71668[i], 0xf);
}

/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
//chocobo color[by index]
tRGBA D_0096E878[] = {
	{0x00,0xFF,0x00,0x00},
	{0x00,0xFF,0xFF,0x00},
	{0xFF,0x80,0x80,0x00},
	{0xFF,0x00,0x00,0x00},
	{0x00,0x00,0xFF,0x00},
	{0xFF,0xFF,0xFF,0x00}
};
//chocobo color[by type]
tRGBA D_0096E890[] = {
	{0xFF,0xFF,0x00,0x00},
	{0x00,0xFF,0x00,0x00},
	{0x00,0x00,0xFF,0x00},
	{0x80,0x80,0x80,0x00},
	{0xFF,0xFF,0x3C,0x00}
};
//00 00 00 00
struct {
	int _0096E8A8[5];
	int _0096E8BC[5];
	int __0096E8D0;//unused
	int __0096E8D4;//unused
} local_data = {
	{1,4,5,0,0},
	{3,5,6,0,0},
	0,
	3
};
//== [HIRES] ==
struct t_chocobo_48 D_0096E8D8[] = {
	{0x0E,{0x80,0x80,0x80,0x00},0,0,0,0,{{0x0F,0x1A},{0,0},{0,0},{0,0}},0.222f,0x18,0x18,0,0.75f,0.75f,48.0f,48.0f,0},
	{0x0F,{0x80,0x80,0x80,0x00},0,0,0,0,{{0x35,0x22},{0,0},{0,0},{0,0}},0.222f,0x18,0x18,0,0.75f,0.75f,48.0f,48.0f,0}
};
struct t_chocobo_48 D_0096E968[] = {
	{0x14,{0x80,0x80,0x80,0x00},0,0,0,0,{{0xF8,0xAA},{0,0},{0,0},{0,0}},0.222f,0x40,0x38,0,0.98f,0.88f,128.0f,112.0f,0},
	{0x15,{0x80,0x80,0x80,0x00},0,0,0,0,{{0xF8,0xAA},{0,0},{0,0},{0,0}},0.222f,0x40,0x38,0,0.98f,0.88f,128.0f,112.0f,0}
};
//== [LORES] ==
struct t_chocobo_48 D_0096E9F8[] = {
	{0x0E,{0x80,0x80,0x80,0x00},0,0,0,0,{{0x0F,0x1A},{0,0},{0,0},{0,0}},0.222f,0x18,0x18,0,0.75f,0.75f,24.0f,24.0f,0},
	{0x0F,{0x80,0x80,0x80,0x00},0,0,0,0,{{0x35,0x22},{0,0},{0,0},{0,0}},0.222f,0x18,0x18,0,0.75f,0.75f,24.0f,24.0f,0}
};
struct t_chocobo_48 D_0096EA88[] = {
	{0x14,{0x80,0x80,0x80,0x00},0,0,0,0,{{0xF8,0xAA},{0,0},{0,0},{0,0}},0.222f,0x40,0x38,0,0.98f,0.88f,64.0f,56.0f,0},
	{0x15,{0x80,0x80,0x80,0x00},0,0,0,0,{{0xF8,0xAA},{0,0},{0,0},{0,0}},0.222f,0x40,0x38,0,0.98f,0.88f,64.0f,56.0f,0}
};
//== ==
int D_0096EB18[] = {0x12,0x1A,0x22,0x22,0x22,0x22};
//== [HIRES] ==
float D_0096EB30[6] = {
	 0.0f/256.0f,
	48.0f/256.0f,//0.1875f
	96.0f/256.0f,//0.375f
	 0.0f/256.0f,
	48.0f/256.0f,//0.1875f
	96.0f/256.0f//0.375f
};
float D_0096EB48[8] = {
	  0.0f/256.0f,
	 64.0f/256.0f,//0.25f
	128.0f/256.0f,//0.5f
	192.0f/256.0f,//0.75f
	  0.0f/256.0f,
	 64.0f/256.0f,//0.25f
	128.0f/256.0f,//0.5f
	  0.0f/256.0f
};
float D_0096EB68 = 48.0f/256.0f;//0.1875f
float D_0096EB6C = 48.0f/128.0f;//0.375f
float D_0096EB70 = 64.0f/256.0f;//0.25f
float D_0096EB74 = 64.0f/128.0f;//0.5f
//== [LORES] ==
float D_0096EB78[6] = {
	0,
	0.09f,//ROUND(24.0f/256.0f)?
	0.19f,//ROUND(48.0f/256.0f)?
	0.28f,//ROUND(72.0f/256.0f)?
	0.38f,//ROUND(96.0f/256.0f)?
	0.47f//ROUND(120.0f/256.0f)?
};
float D_0096EB90[8] = {
	0,
	0.13f,//ROUND(32.0f/256.0f)?
	0.25f,//ROUND(64.0f/256.0f)?
	0.38f,//ROUND(96.0f/256.0f)?
	0.5f,//ROUND(128.0f/256.0f)?
	0.63f,//ROUND(160.0f/256.0f)?
	0.75f,//ROUND(192.0f/256.0f)?
	0
};
float D_0096EBB0 = 0.09f;//ROUND(24.0f/256.0f)?
float D_0096EBB4 = 0.97f;//ROUND(24.0f/24.0f)?
float D_0096EBB8 = 0.121f;//ROUND(32.0f/256.0f)?
float D_0096EBBC = 0.97f;//ROUND(32.0f/32.0)f
//-- maybe not in this module --
//max frames per animation?
int D_0096EBC0[] = {
	/*0096EBC0*/0x18,0x12,0x14,0x14,
	/*0096EBD0*/0x14,0x12,0x1E,0x00
};
////////////////////////////////////////
extern struct t_chocobo_48 D_00E3B950;
extern struct t_chocobo_48 D_00E3B998;
extern struct t_chocobo_48 D_00E3B9E0;
extern struct t_chocobo_48 *D_00E3BAB4;
extern struct t_chocobo_48 *D_00E3BAB8;
extern int D_00E71018;
extern int D_00E71038;
extern int D_00E710F0;
/*NOTE: one possible explanation for the bug:
extern struct {
	char __0000[0x186a0];//scratchpad?0x186a0=100000
	char __186a0[0x18];
	struct {//size 0x18
		short wX,wY;
		char __14[0x14];
	}f_186b8[1];
}*D_00E710F0;
*/
extern int D_00E710F8;
extern int D_00E71108;
extern int D_00E71128;
////////////////////////////////////////
struct t_chocobo_48 D_00E71670[6];//current face(sprite)
int D_00E71820[6];
struct t_chocobo_48 D_00E71838[6];//current ranking(sprite)
//00e719e8
////////////////////////////////////////
struct t_chocobo_local_8 {
	/*00*/int f_00;/*index in D_00E71158*/
	/*04*/int f_04;/*value*/
};

//refresh race 2D stuff
void C_0076E2B0() {
	struct {
		int bp_50;
		unsigned j;//bp_4c
		unsigned i_0;//bp_48
		struct t_chocobo_a4 *bp_44;
		struct t_chocobo_local_8 bp_40[6];
		struct t_chocobo_local_8 bp_10;
		int i_1;//bp_08
		struct t_chocobo_a4 *bp_04;
	}lolo;

	if((D_00E71018 % 0x10) == 0) {//else 0076EA40
		//-- --
		for(lolo.i_0 = 0; lolo.i_0 < 6; lolo.i_0 ++) {
			if(D_00E71158[lolo.i_0].f_7e)
				lolo.bp_40[lolo.i_0].f_04 = D_00E71158[lolo.i_0].f_70;
			else
				lolo.bp_40[lolo.i_0].f_04 = D_00E71158[lolo.i_0].f_82 + 10;
			lolo.bp_40[lolo.i_0].f_00 = lolo.i_0;
		}//end for
		for(lolo.i_0 = 0; lolo.i_0 < 6; lolo.i_0 ++) {
			for(lolo.j = 0; lolo.j < 5; lolo.j ++) {
				if(lolo.bp_40[lolo.j].f_04 > lolo.bp_40[lolo.j + 1].f_04)
					SWAP(lolo.bp_40[lolo.j], lolo.bp_40[lolo.j + 1], lolo.bp_10);
			}
		}//end for
		//-- update ranking/face sprites --
		for(lolo.i_0 = 0; lolo.i_0 < 6; lolo.i_0 ++) {
			lolo.bp_44 = &(D_00E71158[lolo.bp_40[lolo.i_0].f_00]);
			D_00E71670[lolo.i_0].f_00 = 0x11;
			D_00E71670[lolo.i_0].f_04.c.r = D_00E71670[lolo.i_0].f_04.c.g = D_00E71670[lolo.i_0].f_04.c.b = 0x80;
			D_00E71838[lolo.i_0].f_00 = 0x10;
			if(D_00E71128) {//else 0076E4A6
				D_00E71670[lolo.i_0].f_14[0].wX = lolo.i_0 * 40 + 8;
				D_00E71838[lolo.i_0].f_14[0].wX = D_00E71670[lolo.i_0].f_14[0].wX + 8;
				D_00E71838[lolo.i_0].f_14[0].wY = D_0096EB18[lolo.i_0];
				D_00E71670[lolo.i_0].f_14[0].wY = D_00E71838[lolo.i_0].f_14[0].wY + 22;
			} else {
				D_00E71670[lolo.i_0].f_14[0].wX = lolo.i_0 * 50 + 16;
				D_00E71838[lolo.i_0].f_14[0].wX = D_00E71670[lolo.i_0].f_14[0].wX + 8;
				D_00E71838[lolo.i_0].f_14[0].wY = D_0096EB18[lolo.i_0] + 140;
				D_00E71670[lolo.i_0].f_14[0].wY = D_00E71838[lolo.i_0].f_14[0].wY + 22;
			}
			if(D_00E3BA68.dwGrMode == 2) {//else 0076E841
				//== HIRES ==
				if(lolo.bp_44->f_92 < 3) {//else 0076E56D
					D_00E71838[lolo.i_0].wU = lolo.bp_44->f_92 * 48;
					D_00E71838[lolo.i_0].wV = 0;
					D_00E71838[lolo.i_0].fV = 0.0f/128.0f;
				} else {
					D_00E71838[lolo.i_0].wU = (lolo.bp_44->f_92 - 3) * 48;
					D_00E71838[lolo.i_0].wV = 48;
					D_00E71838[lolo.i_0].fV = 48.0f/128.0f;//0.375f
				}
				D_00E71838[lolo.i_0].fU = D_0096EB30[lolo.bp_44->f_92];
				D_00E71838[lolo.i_0].dwWidth = D_00E71838[lolo.i_0].dwHeight = 24;
				D_00E71838[lolo.i_0].fWidth = D_00E71838[lolo.i_0].fHeight = 48.0f;
				D_00E71838[lolo.i_0].fTexWidth = D_0096EB68;
				D_00E71838[lolo.i_0].fTexHeight = D_0096EB6C;
				if(lolo.bp_44->f_7e) {//else 0076E6EF
					D_00E71670[lolo.i_0].fU = D_0096EB48[local_data._0096E8BC[lolo.bp_44->f_70]];
					if(local_data._0096E8BC[lolo.bp_44->f_70] < 4) {//else 0076E6AA
						D_00E71670[lolo.i_0].wV = 0;
						D_00E71670[lolo.i_0].fV = 0;
						D_00E71670[lolo.i_0].wU = local_data._0096E8BC[lolo.bp_44->f_70] * 64;
					} else {
						D_00E71670[lolo.i_0].wV = 64;
						D_00E71670[lolo.i_0].fV = 64.0f/128.0f;//0.5f
						D_00E71670[lolo.i_0].wU = (local_data._0096E8BC[lolo.bp_44->f_70] - 4) * 64;
					}
					//goto 0076E7AC
				} else {
					D_00E71670[lolo.i_0].fU = D_0096EB48[local_data._0096E8A8[lolo.bp_44->wAnmNum]];
					if(local_data._0096E8A8[lolo.bp_44->wAnmNum] < 4) {//else 0076E769
						D_00E71670[lolo.i_0].wU = local_data._0096E8A8[lolo.bp_44->wAnmNum] * 64;
						D_00E71670[lolo.i_0].wV = 0;
						D_00E71670[lolo.i_0].fV = 0;
					} else {
						D_00E71670[lolo.i_0].wU = (local_data._0096E8A8[lolo.bp_44->wAnmNum] - 4) * 64;
						D_00E71670[lolo.i_0].wV = 64;
						D_00E71670[lolo.i_0].fV = 64.0f/128.0f;//0.5f
					}
				}
				D_00E71838[lolo.i_0].f_30 = 0;
				D_00E71670[lolo.i_0].f_30 = D_00E71820[lolo.bp_44->f_92];
				D_00E71670[lolo.i_0].dwWidth = 31;
				D_00E71670[lolo.i_0].dwHeight = 32;
				D_00E71670[lolo.i_0].fWidth = 63.0f;
				D_00E71670[lolo.i_0].fHeight = 64.0f;
				D_00E71670[lolo.i_0].fTexWidth = D_0096EB70;
				D_00E71670[lolo.i_0].fTexHeight = D_0096EB74;
				//goto 0076EA3B
			} else {
				//== LORES ==
				D_00E71838[lolo.i_0].wU = lolo.bp_44->f_92 * 24;
				D_00E71838[lolo.i_0].wV = 0;
				D_00E71838[lolo.i_0].fU = D_0096EB78[lolo.bp_44->f_92];
				D_00E71838[lolo.i_0].fV = 0;
				D_00E71838[lolo.i_0].dwWidth = D_00E71838[lolo.i_0].dwHeight = 24;
				D_00E71838[lolo.i_0].fWidth = D_00E71838[lolo.i_0].fHeight = 24.0f;
				D_00E71838[lolo.i_0].fTexWidth = D_0096EBB0;
				D_00E71838[lolo.i_0].fTexHeight = D_0096EBB4;
				if(lolo.bp_44->f_7e) {
					D_00E71670[lolo.i_0].wU = local_data._0096E8BC[lolo.bp_44->f_70] * 32;
					D_00E71670[lolo.i_0].fU = D_0096EB90[local_data._0096E8BC[lolo.bp_44->f_70]];
				} else {
					D_00E71670[lolo.i_0].fU = D_0096EB90[local_data._0096E8A8[lolo.bp_44->wAnmNum]];
					D_00E71670[lolo.i_0].wU = local_data._0096E8A8[lolo.bp_44->wAnmNum] * 32;
				}
				D_00E71670[lolo.i_0].wV = 0;
				D_00E71670[lolo.i_0].fV = 0;
				D_00E71838[lolo.i_0].f_30 = 0;
				D_00E71670[lolo.i_0].f_30 = D_00E71820[lolo.bp_44->f_92];
				D_00E71670[lolo.i_0].dwWidth = 31;
				D_00E71670[lolo.i_0].dwHeight = 32;
				D_00E71670[lolo.i_0].fWidth = 31.0f;
				D_00E71670[lolo.i_0].fHeight = 32.0f;
				D_00E71670[lolo.i_0].fTexWidth = D_0096EBB8;
				D_00E71670[lolo.i_0].fTexHeight = D_0096EBBC;
			}
		}//end for
	}
	//-- manual/automatic sprite --
	if(D_00E71128) {
		if(D_00E71158[0].wIsAutomatic)
			C_0077A469(D_00E3BAB8);//draw sprite?
		else
			C_0077A469(D_00E3BAB8 + 1);//draw sprite?
		D_00E71108 ++;
	}
	//-- --
	for(lolo.i_1 = 0; lolo.i_1 < 6; lolo.i_1 ++) {
		//-- draw crowns --
		if(D_00E71038) {//else 0076EB7B
			lolo.bp_50 = D_00E71018 & 8;
			//-- crown #1--
			if(lolo.bp_50)
				D_00E3BAB4->f_30 = 0;
			else
				D_00E3BAB4->f_30 = 1;
			if(D_00E71128 == 0) {
				D_00E3BAB4->f_14[0].wY = 0xa6;
				D_00E3BAB4->f_14[0].wX = 0x17;
			}
			C_0077A469(D_00E3BAB4);//draw sprite?
			D_00E71108 ++;
			//-- crown #2--
			if(lolo.bp_50)
				(D_00E3BAB4 + 1)->f_30 = 0;
			else
				(D_00E3BAB4 + 1)->f_30 = 1;
			if(D_00E71128 == 0) {
				(D_00E3BAB4 + 1)->f_14[0].wY = 0xae;
				(D_00E3BAB4 + 1)->f_14[0].wX = 0x47;
			}
			C_0077A469(D_00E3BAB4 + 1);//draw sprite?
			D_00E71108 ++;
		}
		//-- draw face & ranking --
		if(D_00E710F8) {
			//-- current ranking --
			C_0077A469(&(D_00E71838[lolo.i_1]));//draw sprite?
			D_00E71108 ++;
			//-- current face --
			C_0077A469(&(D_00E71670[lolo.i_1]));//draw sprite?
			D_00E71108 ++;
		}
		//-- --
		lolo.bp_04 = &(D_00E71158[lolo.i_1]);
		if(lolo.bp_04->f_7e)
			continue;
		//-- draw position on map --
/*
	[0]-----[1]
	 |       |
	 |       |
	 |       |
	 |       |
	 |       |
	[2]-----[3]
*/
		//note:only f_14[0] and dwWidth and dwHeight are used(because of the bug?)
		D_00E3B758[lolo.i_1].f_14[0].wX = D_00E3B758[lolo.i_1].f_14[2].wX = lolo.bp_04->f_10.f_00 / 650 + 282;
#if (_MSC_VER < 1500)// || defined(__JOE_FIX_BUGS__)
		//original
		D_00E3B758[lolo.i_1].f_14[1].wX = D_00E3B758[lolo.i_1].f_14[3].wX = *(short *)(D_00E710F0 + 0x186b8 + lolo.i_1 * 0x18) + 3;
		//D_00E3B758[lolo.i_1].f_14[1].wX = D_00E3B758[lolo.i_1].f_14[3].wX = D_00E710F0->f_186b8[lolo.i_1].wX + 3;
#else
		D_00E3B758[lolo.i_1].f_14[1].wX = D_00E3B758[lolo.i_1].f_14[3].wX = D_00E3B758[lolo.i_1].f_14[0].wX + 3;
#endif
		D_00E3B758[lolo.i_1].f_14[0].wY = D_00E3B758[lolo.i_1].f_14[1].wY = lolo.bp_04->f_10.f_04 / 610 + 40;
		D_00E3B758[lolo.i_1].f_14[2].wY = D_00E3B758[lolo.i_1].f_14[3].wY = D_00E3B758[lolo.i_1].f_14[0].wY + 3;
		D_00E3B758[lolo.i_1].dwWidth = D_00E3B758[lolo.i_1].dwHeight = 3;
		if(lolo.i_1 == D_00E71624 && (D_00E71018 & 8)) {
			D_00E3B758[lolo.i_1].f_04.c.r = D_0096E878[lolo.i_1].c.r;
			D_00E3B758[lolo.i_1].f_04.c.g = D_0096E878[lolo.i_1].c.g;
			D_00E3B758[lolo.i_1].f_04.c.b = D_0096E878[lolo.i_1].c.b;
		} else {
			D_00E3B758[lolo.i_1].f_04.c.r = D_0096E878[lolo.i_1].c.r / 2;
			D_00E3B758[lolo.i_1].f_04.c.g = D_0096E878[lolo.i_1].c.g / 2;
			D_00E3B758[lolo.i_1].f_04.c.b = D_0096E878[lolo.i_1].c.b / 2;
		}
		if(lolo.i_1 == D_00E71624)
			D_00E3B758[lolo.i_1].fZ = 0.22f;
		else
			D_00E3B758[lolo.i_1].fZ = 0.23f;
		C_0077A7D0(&(D_00E3B758[lolo.i_1]));//draw a color rectangle?
	}//end for
	//-- draw map --
	C_0077A469(&D_00E3B950);//draw sprite?
	//-- draw stamina gauge --
	lolo.bp_04 = D_00E71158;
	if(D_00E71128) {//else 0076EEB5
		if(lolo.bp_04->f_48 && (D_00E71018 & 4))
			D_00E3B9E0.f_00 = 0x17;
		else
			D_00E3B9E0.f_00 = 0x16;
		C_0077A469(&D_00E3B9E0);//draw sprite?
		//-- --
		lolo.i_1 = 208 - ((lolo.bp_04->dwStamina * 0x44) / lolo.bp_04->dwMaxStamina);
		if(lolo.i_1 > 209)
			lolo.i_1 = 209;
		D_00E3B998.f_14[0].wY = D_00E3B998.f_14[1].wY = lolo.i_1;
		D_00E3B998.dwHeight = D_00E3B998.f_14[3].wY - D_00E3B998.f_14[1].wY;
		C_0077A7D0(&D_00E3B998);//draw a color rectangle?
	}
}

void C_0076EEB9() {
	struct {
		int bp_10;
		int bp_0c;
		int bp_08;
		int bp_04;
	}lolo;

	lolo.bp_10 = 0x270;
	lolo.bp_0c = 0xfa;
	lolo.bp_08 = 0x10;
	lolo.bp_04 = 6;

	D_00E71820[0] = 0;
	D_00E71820[1] = 3;
	D_00E71820[2] = 8;
	D_00E71820[3] = 5;
	D_00E71820[4] = 6;
	D_00E71820[5] = 7;
	if(D_00E3B744) {
		switch(D_00DC0AED) {
			case 0: D_00E71820[0] = 1; break;
			case 1: D_00E71820[0] = 2; break;
			case 2: D_00E71820[0] = 3; break;
			case 3: D_00E71820[0] = 4; break;
			case 4: D_00E71820[0] = 1; break;
		}
	}
	if(D_00DC0AF2)
		D_00E71820[1] = 4;
	if(D_00E71128)
		D_0096E878[0] = D_0096E890[D_00DC0AED];
	if(D_00DC0AF2)
		D_0096E878[1].c.r = D_0096E878[1].c.g = D_0096E878[1].c.b = 0x80;
}

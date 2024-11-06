/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- trigonometry

#include "ff7.h"
#include "chocobo_data.h"

extern short D_0097CDA0[];

//chocobo:atan2?
short C_0077CF40(short bp08, short bp0c) {
	if(bp08 > 0xfff)
		return 0x400;
	if(bp08 < -0xfff)
		return 0xc00;
	bp08 = bp08 + 0x1000;
	bp08 &= 0x1fff;
	if(bp0c > 0)
		return (D_0097CDA0[bp08] + 0x400) & 0xfff;
	else
		return (D_0097CDA0[0x2000 - bp08] + 0xc00) & 0xfff;
}

//chocobo:make dir angle?
short C_0077CFBF(struct SVECTOR *bp08, struct SVECTOR *bp0c) {
	struct VECTOR local_4;

	local_4.vx = bp0c->vx - bp08->vx;
	local_4.vy = bp0c->vy - bp08->vy;
	local_4.vz = bp0c->vz - bp08->vz;
	psx_VectorNormal(&local_4, &local_4);

	return C_0077CF40(local_4.vx, local_4.vz);//chocobo:atan2?
}

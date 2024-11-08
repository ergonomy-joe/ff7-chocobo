/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
//-- long course --
struct t_chocobo_data_ScenaryModelInfo D_00972A78[] = {
	{{  6745,1750, 5320,3},1,0,216,135,124,17},
	{{ -3369,  10,-8209,2},1,0,192,  0,128,16},
	{{ -3050,3020, 5380,0},0,0,192,126,128,18},
	{{ 10276,1581,-2870,2},1,0,192,128,128,19},
	{{  5614,1670,12250,2},1,0,192,  0,  0,20},
	{{ -8640,   0,-6484,1},0,0,192,  0,  0,21},
	{{  3074,2201, 6336,2},0,0,192,  0,  0,22},
	{{  3074,2201, 6336,2},0,0,192,  0,  0,23},
	{{ -6907,  12,-8769,1},0,0,192,  0,  0,24},
	{{ -5245,  16,-8772,1},0,0,192,  0,  0,25},
	{{ -3459,  10,-8772,2},1,0,192,  0,  0,26},
	{{ -3459,  10,-8772,3},1,0,192,  0,  0,27},
	{{ -9292,2664,-9378,3},1,0,192,  0,  0,28},
	{{-10999, 897,-1482,0},0,0,192,  0,  0,29},
	{{-10999, 897,-1482,0},0,0,192,180,  0,30}
};
//-- short course --
struct t_chocobo_data_ScenaryModelInfo D_00972B68[] = {
	{{  2422, 281, -691,2},1,0,192,  0,128,16},
	{{ -5193,3322, 8641,0},0,0,192,  0,  0,17},
	{{ -5181,3170, 8722,3},1,0,192,  0,  0,18},
	{{ -6677,2852, -128,0},0,0,192,  0,  0,19},
	{{ -6651,2720, -193,3},1,0,192,  0,  0,20},
	{{ -6984, 616,-7235,2},1,0,192,  0,  0,21},
	{{ -7242, 330,-8769,2},1,0,192,  0,  0,22},
	{{ -8861,  84,-6792,2},1,0,192,  0,  0,23},
	{{ -2612,2283,  151,3},1,0,192,  0,  0,24},
	{{ -2898,1922, 1113,3},1,0,192,  0,  0,25},
	{{ -2514,3342, -813,3},1,0,192,  0,  0,26},
	{{ -2070,1333, 1968,3},1,0,192,  0,  0,27},
	{{ -4539,1782,   29,3},1,0,192,  0,  0,28},
	{{ -2541,2230,-2086,3},1,0,192,  0,  0,29},
	{{  -638,2769,  284,3},1,0,192,  0,  0,30},
	{{-10237,1530, -353,0},0,0,192,  0,  0,31},
	{{ -3459,  10,-8772,2},1,0,192,  0,  0,32},
	{{ -3459,  10,-8772,3},1,0,192,  0,  0,33},
	{{-11361,3962, 4677,3},1,0,192,  0,  0,34}
};
////////////////////////////////////////
//chocobo:get scenery models array?
struct t_chocobo_data_ScenaryModelInfo *C_00771660(int bp08) {
	if(bp08 == 0)
		return D_00972A78;
	else
		return D_00972B68;
}

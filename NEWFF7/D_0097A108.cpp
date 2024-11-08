/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#include "ff7.h"
#include "chocobo_data.h"

//-- for camera --
//(pos_height,lookAt_height,shift)
short D_0097A108[][3] = {
	{-500,-500,3},//[unused]
	{ 250, 300,3},
	{9500,7500,3},//[unused]
	{   0,   0,0}//[unused]pad?
};
//-- long course --
struct t_chocobo_cameraInfo D_0097A120[] = {
	{1,1,   0,{ -659,  10,-8198,   0},{   0,   0,   0,  0}},
	{2,1, 500,{    0,   0,    0,  50},{   0,   0,   0,  0}},
	{1,0,   0,{ 8503, 500,-3281, 120},{4146, 238, 500,210}},
	{3,0,   0,{    4,1400,    4,   4},{   0,   0,   0,  0}},
	{1,1,   0,{15537,1352,-2906,   0},{   0,   0,   0,  0}},
	{2,2,1000,{    0,   0,    0, 320},{   0,   0,   0,  0}},
	{1,1,   0,{11315,1800, 6027,   0},{   0,   0,   0,  0}},
	{3,0,   0,{    3,1000,    3,   5},{   0,   0,   0,  0}},
	{1,1,   0,{ 3882,1800, 7353,   0},{   0,   0,   0,  0}},
	{1,0,   0,{-2097,2359, 7900, 550},{1191,1600,7636,660}},
	{3,0,   0,{    3,2000,    4,   3},{   0,   0,   0,  0}},
	{2,2, 400,{    0,   0,    0, 730},{   0,   0,   0,  0}},
	{1,1,   0,{-8594,2800, 1389,   0},{   0,   0,   0,  0}},
	{2,2, 700,{    0,   0,    0, 800},{   0,   0,   0,  0}},
	{3,0,   0,{    4,1400,    2,   4},{   0,   0,   0,  0}},
	{2,0,1400,{    0,   0,    0,1020},{   0,   0,   0,  0}},
	{1,1,   0,{-8328, 802,-3122,   0},{   0,   0,   0,  0}},
	{3,0,   0,{    6,1400,    3,   6},{   0,   0,   0,  0}},
	{2,1, 300,{    0,   0,    0, 510},{   0,   0,   0,  0}}
};
//0097A29C  00 00 00 00
//-- short course --
struct t_chocobo_cameraInfo D_0097A2A0[] = {
	{1,1,   0,{  -659, 200,-8198,  0},{     0,   0,    0,  0}},
	{1,0,   0,{  2222, 200,-8359,  0},{ -3729, 300,-9336, 60}},
	{1,0,   0,{  2825, 310,-7464, 50},{  2422, 281, -917,140}},
	{2,1,1700,{     0,   0,    0,120},{     0,   0,    0,  0}},
	{1,0,   0,{ -2704,3868,-3086,295},{ -2026,3012, 1770,508}},
	{1,1,   0,{ -5973,3700, 4776,  0},{     0,   0,    0,  0}},
	{1,0,   0,{ -8083,2900, 1358,450},{ -5977,2712, 5904,560}},
	{2,2, 100,{     0,   0,    0,580},{     0,   0,    0,  0}},
	{1,1,   0,{-14930,1992, 7423,  0},{     0,   0,    0,  0}},
	{2,3, 700,{     0,   0,    0,680},{     0,   0,    0,  0}},
	{2,1, 700,{     0,   0,    0,170},{     0,   0,    0,  0}},
	{1,1,   0,{-13972,2538,  531,  0},{     0,   0,    0,  0}},
	{1,0,   0,{-11608,1001,-3321,730},{-11211,1108, -105,790}},
	{3,0,   0,{     4,1400,    4,  4},{     0,   0,    0,  0}},
	{3,0,   0,{     9,1200,    5,  5},{     0,   0,    0,  0}},
	{1,0,   0,{ -9208, 512,-5262,792},{ -9015, 568,-3013,840}}
};
//-- --
//chocobos characteristics base[by type]
short D_0097A3E0[][4] = {
	{2500,500,1700,200},
	{3000,600,2200,300},
	{3500,700,3000,500},
	{5000,800,4000,500}
};
char __0097A400[] = {
	0x1B,0x00,0x00,0x00,
	0x30,0x00,0x00,0x00,
	0x3B,0x00,0x00,0x00,
	0x3F,0x00,0x00,0x00,
	0x40,0x00,0x00,0x00,
	0x40,0x00,0x00,0x00,
	0x3E,0x00,0x00,0x00,
	0x3B,0x00,0x00,0x00,
	0x35,0x00,0x00,0x00,
	0x32,0x00,0x00,0x00,
	0x2D,0x00,0x00,0x00,
	0x28,0x00,0x00,0x00,
	0x21,0x00,0x00,0x00,
	0x14,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x0A,0x00
};

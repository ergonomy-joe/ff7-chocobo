/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#define __FF7FILE__ "C:\\FF7\\chocobo\\ch_chr.cpp"

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
struct t_chocobo_local_data_30 {//size 0x30
	/*00*/int dwAnimationsCount;
	/*04*/const char *pszHRC;
	/*08*/const char *pszANM[0xa];
};
////////////////////////////////////////
//-- DEVEL --
struct t_chocobo_local_data_30 D_0096EBE0[] = {
	{6,/*009704B8*/"data\\chr\\chocobo\\rsd\\chocobo.hrc",
		/*009704DC*/"data\\chr\\chocobo\\anm\\run.anm",
		/*009704FC*/"data\\chr\\chocobo\\anm\\turbo.anm",
		/*0097051C*/"data\\chr\\chocobo\\anm\\win.anm",
		/*0097053C*/"data\\chr\\chocobo\\anm\\draw.anm",
		/*0097055C*/"data\\chr\\chocobo\\anm\\lose.anm",
		/*0097057C*/"data\\chr\\chocobo\\anm\\tired.anm"},
	{5,/*0097059C*/"data\\chr\\metman\\rsd\\metman.hrc",
		/*009705BC*/"data\\chr\\metman\\anm\\run.anm",
		/*009705D8*/"data\\chr\\metman\\anm\\turbo.anm",
		/*009705F8*/"data\\chr\\cloud\\anm\\win.anm",
		/*00970614*/"data\\chr\\metman\\anm\\draw.anm",
		/*00970634*/"data\\chr\\metman\\anm\\lose.anm"},
	{6,/*00970654*/"data\\chr\\cloud\\rsd\\cloud.hrc",
		/*00970674*/"data\\chr\\cloud\\anm\\run.anm",
		/*00970690*/"data\\chr\\cloud\\anm\\turbo.anm",
		/*009706B0*/"data\\chr\\cloud\\anm\\win.anm",
		/*009706CC*/"data\\chr\\cloud\\anm\\draw.anm",
		/*009706E8*/"data\\chr\\cloud\\anm\\lose.anm",
		/*00970704*/"data\\chr\\cloud\\anm\\tired.anm"},
	{1,/*00970724*/"data\\chr\\aurora\\rsd\\aurora.hrc",/*00970744*/"data\\chr\\aurora\\anm\\aurora.anm"},
	{1,/*00970764*/"data\\chr\\ufo\\rsd\\ufo.hrc",/*00970780*/"data\\chr\\ufo\\anm\\ufo.anm"},
	{1,/*0097079C*/"data\\chr\\conya\\rsd\\conya.hrc",/*009707BC*/"data\\chr\\conya\\anm\\conya.anm"},
	{1,/*009707DC*/"data\\chr\\canoe\\rsd\\canoe.hrc",/*009707FC*/"data\\chr\\canoe\\anm\\canoe.anm"},
	{1,/*0097081C*/"data\\chr\\dia\\rsd\\dia1.hrc",/*00970838*/"data\\chr\\dia\\anm\\dia1.anm"},
	{1,/*00970854*/"data\\chr\\dia\\rsd\\dia2.hrc",/*00970870*/"data\\chr\\dia\\anm\\dia2.anm"},
	{1,/*0097088C*/"data\\chr\\dia\\rsd\\dia3.hrc",/*009708A8*/"data\\chr\\dia\\anm\\dia3.anm"},
	{1,/*009708C4*/"data\\chr\\dia\\rsd\\dia4.hrc",/*009708E0*/"data\\chr\\dia\\anm\\dia4.anm"},
	{1,/*009708FC*/"data\\chr\\dia\\rsd\\dia5.hrc",/*00970918*/"data\\chr\\dia\\anm\\dia5.anm"},
	{1,/*00970934*/"data\\chr\\dia\\rsd\\dia6.hrc",/*00970950*/"data\\chr\\dia\\anm\\dia6.anm"},
	{1,/*0097096C*/"data\\chr\\dia\\rsd\\dia7.hrc",/*00970988*/"data\\chr\\dia\\anm\\dia7.anm"},
	{1,/*009709A4*/"data\\chr\\goal\\rsd\\goal.hrc",/*009709C0*/"data\\chr\\goal\\anm\\goal.anm"},
	{1,/*009709DC*/"data\\chr\\goal\\rsd\\goalbar.hrc",/*009709FC*/"data\\chr\\goal\\anm\\goalbar.anm"},
	{1,/*00970A1C*/"data\\chr\\star\\rsd\\star.hrc",/*00970A38*/"data\\chr\\star\\anm\\star.anm"},
	{1,/*00970A54*/"data\\chr\\shell1\\rsd\\shell1.hrc",/*00970A74*/"data\\chr\\shell1\\anm\\shell1.anm"},
	{1,/*00970A94*/"data\\chr\\shell2\\rsd\\shell2.hrc",/*00970AB4*/"data\\chr\\shell2\\anm\\shell2.anm"},
	{1,/*00970AD4*/"data\\chr\\shell1\\rsd\\pearl1.hrc",/*00970AF4*/"data\\chr\\shell1\\anm\\pearl1.anm"},
	{1,/*00970B14*/"data\\chr\\shell2\\rsd\\pearl2.hrc",/*00970B34*/"data\\chr\\shell2\\anm\\pearl2.anm"},
	{1,/*00970B54*/"data\\chr\\hane\\rsd\\hane.hrc",/*00970B70*/"data\\chr\\hane\\anm\\hane.anm"},
	{1,/*00970B8C*/"data\\chr\\hane\\rsd\\hanebig.hrc",/*00970BAC*/"data\\chr\\hane\\anm\\hanebig.anm"},
	{1,/*00970BCC*/"data\\chr\\ice\\rsd\\ice1.hrc",/*00970BE8*/"data\\chr\\ice\\anm\\ice1.anm"},
	{1,/*00970C04*/"data\\chr\\ice\\rsd\\ice2.hrc",/*00970C20*/"data\\chr\\ice\\anm\\ice2.anm"},
	{1,/*00970C3C*/"data\\chr\\ice\\rsd\\ice3.hrc",/*00970C58*/"data\\chr\\ice\\anm\\ice3.anm"},
	{1,/*00970C74*/"data\\chr\\shark\\rsd\\shark.hrc",/*00970C94*/"data\\chr\\shark\\anm\\shark1.anm"},
	{1,/*00970CB4*/"data\\chr\\shark\\rsd\\shark.hrc",/*00970CD4*/"data\\chr\\shark\\anm\\shark2.anm"},
	{1,/*00970CF4*/"data\\chr\\fla\\rsd\\fla.hrc",/*00970D10*/"data\\chr\\fla\\anm\\fla.anm"},
	{1,/*00970D2C*/"data\\chr\\thunder\\rsd\\thunderl.hrc",/*00970D50*/"data\\chr\\thunder\\anm\\thunderl.anm"},
	{1,/*00970D74*/"data\\chr\\thunder\\rsd\\thunderr.hrc",/*00970D98*/"data\\chr\\thunder\\anm\\thunderr.anm"},
	{1,/*00970DBC*/"data\\chr\\fuusha\\rsd\\fuusha.hrc",/*00970DDC*/"data\\chr\\fuusha\\anm\\fuusha.anm"},
	{1,/*00970DFC*/"data\\chr\\taki\\rsd\\taki_r.hrc",/*00970E1C*/"data\\chr\\taki\\anm\\taki.anm"},
	{1,/*00970E38*/"data\\chr\\fuusha\\rsd\\fuusha.hrc",/*00970E58*/"data\\chr\\fuusha\\anm\\fuusha.anm"},
	{1,/*00970E78*/"data\\chr\\morgly\\rsd\\morgly.hrc",/*00970E98*/"data\\chr\\morgly\\anm\\win.anm"},
	{1,/*00970EB4*/"data\\chr\\tobira\\rsd\\tobira.hrc",/*00970ED4*/"data\\chr\\tobira\\anm\\tobira.anm"},
	{5,/*00970EF4*/"data\\chr\\metman1\\rsd\\metman1.hrc",
		/*00970F18*/"data\\chr\\cloud\\anm\\run.anm",
		/*00970F34*/"data\\chr\\metman\\anm\\turbo.anm",
		/*00970F54*/"data\\chr\\metman\\anm\\win.anm",
		/*00970F70*/"data\\chr\\metman\\anm\\draw.anm",
		/*00970F90*/"data\\chr\\metman\\anm\\lose.anm"},
	{6,/*00970FB0*/"data\\chr\\cid\\rsd\\cid.hrc",
		/*00970FCC*/"data\\chr\\cloud\\anm\\run.anm",
		/*00970FE8*/"data\\chr\\cloud\\anm\\turbo.anm",
		/*00971008*/"data\\chr\\cloud\\anm\\win.anm",
		/*00971024*/"data\\chr\\cloud\\anm\\draw.anm",
		/*00971040*/"data\\chr\\cloud\\anm\\lose.anm",
		/*0097105C*/"data\\chr\\cloud\\anm\\tired.anm"},
	{6,/*0097107C*/"data\\chr\\tifa\\rsd\\tifa.hrc",
		/*00971098*/"data\\chr\\cloud\\anm\\run.anm",
		/*009710B4*/"data\\chr\\cloud\\anm\\turbo.anm",
		/*009710D4*/"data\\chr\\tifa\\anm\\win.anm",
		/*009710F0*/"data\\chr\\cloud\\anm\\draw.anm",
		/*0097110C*/"data\\chr\\cloud\\anm\\lose.anm",
		/*00971128*/"data\\chr\\cloud\\anm\\tired.anm"}
};
//-- RELEASE --
struct t_chocobo_local_data_30 D_0096F330[] = {
	{6,/*00971148*/"CD.hrc",
		/*00971150*/"DB.anm",
		/*00971158*/"DC.anm",
		/*00971160*/"DD.anm",
		/*00971168*/"DE.anm",
		/*00971170*/"DF.anm",
		/*00971178*/"DG.anm"},
	{5,/*00971180*/"DH.hrc",
		/*00971188*/"DV.anm",
		/*00971190*/"DW.anm",
		/*00971198*/"DX.anm",
		/*009711A0*/"DY.anm",
		/*009711A8*/"DZ.anm"},
	{6,/*009711B0*/"EA.hrc",
		/*009711B8*/"EO.anm",
		/*009711C0*/"EP.anm",
		/*009711C8*/"EQ.anm",
		/*009711D0*/"ER.anm",
		/*009711D8*/"ES.anm",
		/*009711E0*/"ET.anm"},
	{1,/*009711E8*/"EU.hrc",/*009711F0*/"EY.anm"},
	{1,/*009711F8*/"EZ.hrc",/*00971200*/"FH.anm"},
	{1,/*00971208*/"FI.hrc",/*00971210*/"GJ.anm"},
	{1,/*00971218*/"GK.hrc",/*00971220*/"GV.anm"},
	{1,/*00971228*/"GW.hrc",/*00971230*/"GY.anm"},
	{1,/*00971238*/"GZ.hrc",/*00971240*/"HB.anm"},
	{1,/*00971248*/"HC.hrc",/*00971250*/"HE.anm"},
	{1,/*00971258*/"HF.hrc",/*00971260*/"HH.anm"},
	{1,/*00971268*/"HI.hrc",/*00971270*/"HK.anm"},
	{1,/*00971278*/"HL.hrc",/*00971280*/"HN.anm"},
	{1,/*00971288*/"HO.hrc",/*00971290*/"HQ.anm"},
	{1,/*00971298*/"HR.hrc",/*009712A0*/"IA.anm"},
	{1,/*009712A8*/"IB.hrc",/*009712B0*/"IE.anm"},
	{1,/*009712B8*/"IF.hrc",/*009712C0*/"IK.anm"},
	{1,/*009712C8*/"IL.hrc",/*009712D0*/"IP.anm"},
	{1,/*009712D8*/"IQ.hrc",/*009712E0*/"IU.anm"},
	{1,/*009712E8*/"IV.hrc",/*009712F0*/"IX.anm"},
	{1,/*009712F8*/"IY.hrc",/*00971300*/"JA.anm"},
	{1,/*00971308*/"JB.hrc",/*00971310*/"JE.anm"},
	{1,/*00971318*/"JF.hrc",/*00971320*/"JK.anm"},
	{1,/*00971328*/"JL.hrc",/*00971330*/"JN.anm"},
	{1,/*00971338*/"JO.hrc",/*00971340*/"JQ.anm"},
	{1,/*00971348*/"JR.hrc",/*00971350*/"JT.anm"},
	{1,/*00971358*/"JU.hrc",/*00971360*/"KD.anm"},
	{1,/*00971368*/"KE.hrc",/*00971370*/"KN.anm"},
	{1,/*00971378*/"KO.hrc",/*00971380*/"KQ.anm"},
	{1,/*00971388*/"data\\chr\\thunder\\rsd\\thunderl.hrc",/*009713AC*/"data\\chr\\thunder\\anm\\thunderl.anm"},
	{1,/*009713D0*/"data\\chr\\thunder\\rsd\\thunderr.hrc",/*009713F4*/"data\\chr\\thunder\\anm\\thunderr.anm"},
	{1,/*00971418*/"KR.hrc",/*00971420*/"KT.anm"},
	{1,/*00971428*/"KU.hrc",/*00971430*/"KW.anm"},
	{1,/*00971438*/"KX.hrc",/*00971440*/"KZ.anm"},
	{1,/*00971448*/"LA.hrc",/*00971450*/"LJ.anm"},
	{1,/*00971458*/"LK.hrc",/*00971460*/"LO.anm"},
	{5,/*00971468*/"LP.hrc",
		/*00971470*/"MD.anm",
		/*00971478*/"ME.anm",
		/*00971480*/"MF.anm",
		/*00971488*/"MG.anm",
		/*00971490*/"MH.anm"},
	{6,/*00971498*/"MI.hrc",
		/*009714A0*/"MW.anm",
		/*009714A8*/"MX.anm",
		/*009714B0*/"MY.anm",
		/*009714B8*/"MZ.anm",
		/*009714C0*/"NA.anm",
		/*009714C8*/"NB.anm"},
	{6,/*009714D0*/"NC.hrc",
		/*009714D8*/"NQ.anm",
		/*009714E0*/"NR.anm",
		/*009714E8*/"NS.anm",
		/*009714F0*/"NT.anm",
		/*009714F8*/"NU.anm",
		/*00971500*/"NV.anm"}
};
//-- long course --
int D_0096FA80[][2] = {
	{0x00,0},
	{0x00,0},
	{0x00,0},
	{0x00,0},
	{0x00,0},
	{0x00,0},
	{0x02,0},
	{0x25,0},
	{0x26,0},
	{0x24,0},
	{0x01,0},
	{0x01,0},
	{0x01,0},
	{0x01,0},
	{0x01,0},
	{0x01,0},
	{0x22,0},
	{0x20,1},
	{0x23,0},
	{0x1F,0},
	{0x1C,1},
	{0x17,1},
	{0x1A,0},
	{0x1B,0},
	{0x18,1},
	{0x19,1},
	{0x0E,0},
	{0x0F,1},
	{0x03,1},
	{0x05,0},
	{0x05,0}
};
//-- short course --
int D_0096FB78[][2] = {
	{0x00,0},
	{0x00,0},
	{0x00,0},
	{0x00,0},
	{0x00,0},
	{0x00,0},
	{0x02,0},
	{0x25,0},
	{0x26,0},
	{0x24,0},
	{0x01,0},
	{0x01,0},
	{0x01,0},
	{0x01,0},
	{0x01,0},
	{0x01,0},
	{0x22,0},
	{0x11,0},
	{0x13,1},
	{0x12,0},
	{0x14,1},
	{0x15,0},
	{0x16,0},
	{0x10,0},
	{0x07,1},
	{0x08,1},
	{0x09,1},
	{0x0A,1},
	{0x0B,1},
	{0x0C,1},
	{0x0D,1},
	{0x06,0},
	{0x0E,0},
	{0x0F,1},
	{0x04,1}
};
//== LORES ==
//-- DEVEL --
const char *D_0096FC90[7] = {
	/*00971594*/"FIRE.TIM",
	/*009715A0*/"HANA1.TIM",
	/*009715AC*/"HANA2.TIM",
	/*009715B8*/"HANA3.TIM",
	/*009715C4*/"HANA4.TIM",
	/*009715D0*/"KOTORI.TIM",
	/*009715DC*/"MATE.TIM"
};
//00 00 00 00
//-- RELEASE --
const char *D_0096FCB0[7] = {
	/*009715E8*/"PN.TIM",
	/*009715F0*/"PO.TIM",
	/*009715F8*/"PP.TIM",
	/*00971600*/"PQ.TIM",
	/*00971608*/"PR.TIM",
	/*00971610*/"PS.TIM",
	/*00971618*/"PT.TIM"
};
//00 00 00 00
//== HIRES ==
//-- DEVEL --
const char *D_0096FCD0[7] = {
	/*00971620*/"FIRE_1.TIM",
	/*0097162C*/"HANA1_1.TIM",
	/*00971638*/"HANA2_1.TIM",
	/*00971644*/"HANA3_1.TIM",
	/*00971650*/"HANA4_2.TIM",
	/*0097165C*/"KOTORI_1.TIM",
	/*0097166C*/"MATE_1.TIM"
};
//00 00 00 00
//-- RELEASE --
const char *D_0096FCF0[7] = {
	/*00971678*/"NW.tim",
	/*00971680*/"NX.tim",
	/*00971688*/"NY.tim",
	/*00971690*/"NZ.tim",
	/*00971698*/"OA.tim",
	/*009716A0*/"OB.tim",
	/*009716A8*/"OC.tim"
};
//00 00 00 00
//== LORES ==
//-- DEVEL --
const char *D_0096FD10[0x24] = {
	/*009716B0*/"AMMONITE.TIM",
	/*009716C0*/"ANEMONE.TIM",
	/*009716CC*/"BOAT.TIM",
	/*009716D8*/"BUBBLE.TIM",
	/*009716E4*/"CAW.TIM",
	/*009716EC*/"CONDOR.TIM",
	/*009716F8*/"FIRE.TIM",
	/*00971704*/"FISH.TIM",
	/*00971710*/"FUNE.TIM",
	/*0097171C*/"GRASS.TIM",
	/*00971728*/"HELI.TIM",
	/*00971734*/"HETIMA1.TIM",
	/*00971740*/"HETIMA2.TIM",
	/*0097174C*/"HETIMA3.TIM",
	/*00971758*/"IKADA.TIM",
	/*00971764*/"INDIAN.TIM",
	/*00971770*/"KINOKO.TIM",
	/*0097177C*/"KOTORI.TIM",
	/*00971788*/"KUMA.TIM",
	/*00971794*/"NAPO.TIM",
	/*009717A0*/"PATER.TIM",
	/*009717AC*/"PENGUIN1.TIM",
	/*009717BC*/"PENGUIN2.TIM",
	/*009717CC*/"PIG1.TIM",
	/*009717D8*/"PIG2.TIM",
	/*009717E4*/"POLL.TIM",
	/*009717F0*/"S_KABA1.TIM",
	/*009717FC*/"S_KABA2.TIM",
	/*00971808*/"SARDINE.TIM",
	/*00971814*/"SEAWEED.TIM",
	/*00971820*/"SHELL.TIM",
	/*0097182C*/"SHIP.TIM",
	/*00971838*/"SMOKE.TIM",
	/*00971844*/"TAIMATU.TIM",
	/*00971850*/"TAIMATUT.TIM",
	/*00971860*/"WHALE.TIM"
};
//-- RELEASE --
const char *D_0096FDA0[0x24] = {
	/*0097186C*/"PU.TIM",
	/*00971874*/"PV.TIM",
	/*0097187C*/"PW.TIM",
	/*00971884*/"PX.TIM",
	/*0097188C*/"PY.TIM",
	/*00971894*/"PZ.TIM",
	/*0097189C*/"QA.TIM",
	/*009718A4*/"QB.TIM",
	/*009718AC*/"QC.TIM",
	/*009718B4*/"QD.TIM",
	/*009718BC*/"QE.TIM",
	/*009718C4*/"QF.TIM",
	/*009718CC*/"QG.TIM",
	/*009718D4*/"QH.TIM",
	/*009718DC*/"QI.TIM",
	/*009718E4*/"QJ.TIM",
	/*009718EC*/"QK.TIM",
	/*009718F4*/"QL.TIM",
	/*009718FC*/"QM.TIM",
	/*00971904*/"QN.TIM",
	/*0097190C*/"QO.TIM",
	/*00971914*/"QP.TIM",
	/*0097191C*/"QQ.TIM",
	/*00971924*/"QR.TIM",
	/*0097192C*/"QS.TIM",
	/*00971934*/"QT.TIM",
	/*0097193C*/"QU.TIM",
	/*00971944*/"QV.TIM",
	/*0097194C*/"QW.TIM",
	/*00971954*/"QX.TIM",
	/*0097195C*/"QY.TIM",
	/*00971964*/"QZ.TIM",
	/*0097196C*/"RA.TIM",
	/*00971974*/"RB.TIM",
	/*0097197C*/"RC.TIM",
	/*00971984*/"RD.TIM"
};
//== HIRES ==
//-- DEVEL --
const char *D_0096FE30[0x24] = {
	/*0097198C*/"AMMONIT1.TIM",
	/*0097199C*/"ANEMONE1.TIM",
	/*009719AC*/"BOAT_1.TIM",
	/*009719B8*/"BUBBLE_1.TIM",
	/*009719C8*/"CAW_1.TIM",
	/*009719D4*/"CONDOR_1.TIM",
	/*009719E4*/"FIRE_1.TIM",
	/*009719F0*/"FISH_1.TIM",
	/*009719FC*/"FUNE_1.TIM",
	/*00971A08*/"GRASS_1.TIM",
	/*00971A14*/"HELI_1.TIM",
	/*00971A20*/"HETIMA11.TIM",
	/*00971A30*/"HETIMA21.TIM",
	/*00971A40*/"HETIMA31.TIM",
	/*00971A50*/"IKADA_1.TIM",
	/*00971A5C*/"INDIAN_1.TIM",
	/*00971A6C*/"KINOKO_1.TIM",
	/*00971A7C*/"KOTORI_1.TIM",
	/*00971A8C*/"KUMA_1.TIM",
	/*00971A98*/"NAPO_1.TIM",
	/*00971AA4*/"PATER_1.TIM",
	/*00971AB0*/"PENGU1_1.TIM",
	/*00971AC0*/"PENGU2_1.TIM",
	/*00971AD0*/"PIG1_1.TIM",
	/*00971ADC*/"PIG2_1.TIM",
	/*00971AE8*/"POLL_1.TIM",
	/*00971AF4*/"S_KABA11.TIM",
	/*00971B04*/"S_KABA21.TIM",
	/*00971B14*/"SARD_1.TIM",
	/*00971B20*/"SEAW_1.TIM",
	/*00971B2C*/"SHELL_1.TIM",
	/*00971B38*/"SHIP_1.TIM",
	/*00971B44*/"SMOKE_1.TIM",
	/*00971B50*/"TAIM_1.TIM",
	/*00971B5C*/"TAIMT_1.TIM",
	/*00971B68*/"WHALE_1.TIM"
};
//-- RELEASE --
const char *D_0096FEC0[0x24] = {
	/*00971B74*/"OD.tim",
	/*00971B7C*/"OE.tim",
	/*00971B84*/"OF.tim",
	/*00971B8C*/"OG.tim",
	/*00971B94*/"OH.tim",
	/*00971B9C*/"OI.tim",
	/*00971BA4*/"OJ.tim",
	/*00971BAC*/"OK.tim",
	/*00971BB4*/"OL.tim",
	/*00971BBC*/"OM.tim",
	/*00971BC4*/"ON.tim",
	/*00971BCC*/"OO.tim",
	/*00971BD4*/"OP.tim",
	/*00971BDC*/"OQ.tim",
	/*00971BE4*/"OR.tim",
	/*00971BEC*/"OS.tim",
	/*00971BF4*/"OT.tim",
	/*00971BFC*/"OU.tim",
	/*00971C04*/"OV.tim",
	/*00971C0C*/"OW.tim",
	/*00971C14*/"OX.tim",
	/*00971C1C*/"OY.tim",
	/*00971C24*/"OZ.tim",
	/*00971C2C*/"PA.tim",
	/*00971C34*/"PB.tim",
	/*00971C3C*/"PC.tim",
	/*00971C44*/"PD.tim",
	/*00971C4C*/"PE.tim",
	/*00971C54*/"PF.tim",
	/*00971C5C*/"PG.tim",
	/*00971C64*/"PH.tim",
	/*00971C6C*/"PI.tim",
	/*00971C74*/"PJ.tim",
	/*00971C7C*/"PK.tim",
	/*00971C84*/"PL.tim",
	/*00971C8C*/"PM.tim"
};
//== ==
//sprite id->D_00E71C60[long course]
int D_0096FF50[] = {
	0x00,0x00,0x00,0x01,0x01,0x01,0x02,0x02,0x02,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
	0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x05,0x05,0x05,0x05,0x05,
	0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,
	0x06,0x06,0x06,0x06,0x06,0x06,0x07,0x07,0x07,0x07,0x08,0x08,0x08,0x08,0x08,0x09,
	0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,
	0x09,0x0A,0x0A,0x0A,0x0B,0x0B,0x0B,0x0C,0x0C,0x0C,0x0D,0x0D,0x0D,0x0D,0x0D,0x0E,
	0x0E,0x0E,0x0E,0x0F,0x0F,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x11,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x13,
	0x13,0x13,0x13,0x14,0x14,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,
	0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x17,0x17,0x17,0x17,0x17,
	0x17,0x17,0x17,0x18,0x18,0x18,0x18,0x18,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,
	0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x1A,0x1A,
	0x1A,0x1A,0x1A,0x1A,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1C,
	0x1C,0x1C,0x1C,0x1D,0x1D,0x1D,0x1D,0x1E,0x1E,0x1E,0x1E,0x1F,0x1F,0x1F,0x20,0x20,
	0x20,0x20,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x22,
	0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x23,0x23,0x23
};
//0097034F 00
//sprite id->D_00E71C60[short course]
int D_00970350[] = {
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,
	2,2,2,2,2,2,2,1,2,2,2,2,3,3,3,3,
	3,1,3,3,3,3,3,3,3,3,1,4,4,4,4,4,
	4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,
	4,4,4,4,4,4,4,4,5,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,6,6
};
//009704B8	"data\\chr\\chocobo\\rsd\\chocobo.hrc
//...
//00971500	"NV.anm"

//00971508	__FF7FILE__
//00971524	__FF7FILE__
//00971540	__FF7FILE__
//0097155C	__FF7FILE__
//00971578	__FF7FILE__

//00971594	"FIRE.TIM"
//...
//00971C8C	"PM.tim"
////////////////////////////////////////
extern int *D_00E72980;
extern int D_00E72984;//3D sprites/billboard count
////////////////////////////////////////
//ch_chr:clean(1)?
int C_0076EFF0() {
	struct {
		int j;//local_2
		int i;//local_1
	}lolo;

	if(D_00E719E8) {//else 0076F1A7
		for(lolo.i = 0; lolo.i < D_00E719EC; lolo.i ++) {
			//-- ".HRC" --
			if(D_00E719E8[lolo.i].pHRC) {//else 0076F0A6
				if(D_00E719E8[lolo.i].pHRC->f_b4)
					C_00692CEE(D_00E719E8[lolo.i].pHRC->f_b4);//plytopd:release skeleton
				mem_free(D_00E719E8[lolo.i].pHRC, __FF7FILE__, 0x8b);
				D_00E719E8[lolo.i].pHRC = 0;
			}
			//-- ".ANM" --
			for(lolo.j = 0; lolo.j < D_00E719E8[lolo.i].wAnimationCount; lolo.j ++) {
				if(D_00E719E8[lolo.i].ppANM && D_00E719E8[lolo.i].ppANM[lolo.j]) {
					C_00691E8E(D_00E719E8[lolo.i].ppANM[lolo.j]);
					D_00E719E8[lolo.i].ppANM[lolo.j] = 0;
				}
			}//end for
			if(D_00E719E8[lolo.i].ppANM) {
				mem_free(D_00E719E8[lolo.i].ppANM, __FF7FILE__, 0x99);
				D_00E719E8[lolo.i].ppANM = 0;
			}
			//-- --
		}//end for
		mem_free(D_00E719E8, __FF7FILE__, 0x9e);
		D_00E719E8 = 0;
	}

	return 1;
}

//ch_chr:init(1)?
int C_0076F1B0(struct t_rsd_74 *bp08, struct t_aa0 *bp0c, int bp10) {
	struct {
		char drive[_MAX_DRIVE]; char _ocal_326;//local_326
		char fname[_MAX_FNAME];//local_325
		int (*local_261)[2];
		char dir[_MAX_DIR];//local_260
		char ext[_MAX_EXT];//local_196
		DECL_unsigned_short(j);//local_132
		DECL_unsigned_short(i);//local_131
		struct t_chocobo_Model3D *pModel;//local_130
		int dwModelsCount;//local_129
		char szPath[0x100];//local_128
		char szFileName[0x100];//local_64
	}lolo;

	if(bp10 == 0) {
		lolo.dwModelsCount = 0x1f;
		lolo.local_261 = D_0096FA80;
	} else {
		lolo.dwModelsCount = 0x23;
		lolo.local_261 = D_0096FB78;
	}
	D_00E719EC = lolo.dwModelsCount;
	D_00E719EE = 0;
	D_00E719E8 = (struct t_chocobo_Model3D *)mem_malloc(D_00E719EC * sizeof(struct t_chocobo_Model3D), __FF7FILE__, 0xbb);
	if(D_00E719E8 == 0)
		return 0;
	//== RELEASE ==
	if(D_00972174) {
		bp08->f_40.dwUseArchive = 1;
		bp08->f_40.dwArchiveId = ARCHIVE_07;
		bp08->f_40.f_0c = 0;
	}
	//== ==
	for(lolo.i = 0; lolo.i < D_00E719EC; lolo.i ++) {
		lolo.pModel = &(D_00E719E8[lolo.i]);
		lolo.pModel->wX = 0;
		lolo.pModel->wY = 0;
		lolo.pModel->wZ = 0;
		lolo.pModel->bR =
		lolo.pModel->bG =
		lolo.pModel->bB = 0x80;
		lolo.pModel->wScaling = 640;
		if(lolo.local_261[lolo.i][1] == 1)
			lolo.pModel->dwIsTransparent = 1;
		else
			lolo.pModel->dwIsTransparent = 0;
		if(lolo.pModel->dwIsTransparent == 0) {//else 0076F392
			C_0067455E(bp08);//rsd:init with blend mode 4?
			//== RELEASE ==
			if(D_00972174) {
				bp08->f_40.dwUseArchive = 1;
				bp08->f_40.dwArchiveId = ARCHIVE_07;
				bp08->f_40.f_0c = 0;
			}
			//== ==
			bp08->dwRSDFlags |= RSD_02000000 | RSD_00100000;
			C_00674659(4, bp08);//rsd:set blend mode?
		} else {
			C_0067455E(bp08);//rsd:init with blend mode 4?
			//== RELEASE ==
			if(D_00972174) {
				bp08->f_40.dwUseArchive = 1;
				bp08->f_40.dwArchiveId = ARCHIVE_07;
				bp08->f_40.f_0c = 0;
			}
			//== ==
			bp08->dwRSDFlags |= RSD_02000000 | RSD_00100000;
			C_00674659(1, bp08);//rsd:set blend mode?
		}
		bp08->fScaling = ((float)lolo.pModel->wScaling / 4096.0f) * 30.4309f;
		lolo.pModel->f_10 = (char)lolo.i;
		lolo.pModel->wAnimationCount = D_0096EBE0[lolo.local_261[lolo.i][0]].dwAnimationsCount;
		if(lolo.i >= 0x10 || lolo.i < 6)
			lolo.pModel->dwAdjustYPos = 1;
		else
			lolo.pModel->dwAdjustYPos = 0;
		lolo.pModel->dwDoRender = 0;
		lolo.pModel->dwActive = 1;
		lolo.pModel->wAnimationId = 0;
		lolo.pModel->wPrevAnimationId = 0;
		lolo.pModel->dwPatchRotY = 0;
		//-- --
		if(bp10) {
			if(lolo.i == 0x11 || lolo.i == 0x13 || lolo.i == 0x16 || lolo.i == 0x1f)
				lolo.pModel->dwPatchRotY = 1;
		}
		//-- ".ANM" --
		lolo.pModel->ppANM = (struct t_animationHeader **)mem_malloc(lolo.pModel->wAnimationCount * sizeof(struct t_animationHeader *), __FF7FILE__, 0xfb);
		for(lolo.j = 0; lolo.j < lolo.pModel->wAnimationCount; lolo.j ++) {
			strcpy(lolo.szFileName, D_00E3B640);
			if(D_00972174 == 0)
				//== DEVEL ==
				strcat(lolo.szFileName, D_0096EBE0[lolo.local_261[lolo.i][0]].pszANM[lolo.j]);
			else
				//== RELEASE ==
				strcat(lolo.szFileName, D_0096F330[lolo.local_261[lolo.i][0]].pszANM[lolo.j]);
			lolo.pModel->ppANM[lolo.j] = C_0077A150(bp08, lolo.szFileName);//chocobo:load ".anm" file(renamed ".a")?
			C_00692412(((float)lolo.pModel->wScaling / 4096.0f) * 30.4309f, lolo.pModel->ppANM[lolo.j]);//plytopd:scale TX,TY,TZ?
		}//end for
		//-- ".HRC" --
		if(lolo.pModel->wAnimationCount > 0) {//else 0076F90F
			strcpy(lolo.szFileName, D_00E3B640);
			if(D_00972174 == 0)
				//== DEVEL ==
				strcat(lolo.szFileName, D_0096EBE0[lolo.local_261[lolo.i][0]].pszHRC);
			else
				//== RELEASE ==
				strcat(lolo.szFileName, D_0096F330[lolo.local_261[lolo.i][0]].pszHRC);
			_splitpath(lolo.szFileName, lolo.drive, lolo.dir, lolo.fname, lolo.ext);
			strcpy(lolo.szPath, lolo.drive);
			strcat(lolo.szPath, lolo.dir);
			lolo.pModel->pHRC = C_0077A2E9(30, lolo.pModel->ppANM[0], bp08, bp0c, lolo.szFileName, lolo.szPath);//chocobo:load ".HRC" file?
			for(lolo.j = 0; lolo.j < lolo.pModel->wAnimationCount; lolo.j ++)
				C_00684C32(lolo.pModel->ppANM[lolo.j], lolo.pModel->pHRC->f_b4);
			C_0077A339(lolo.pModel, 0);//chocobo:set animation id
			if(lolo.pModel->pHRC == 0)
				return 0;
			lolo.pModel->pHRC->f_00 = 1;
		}
	}//end for

	return 1;
}

//ch_chr:init(2)?
void C_0076F920(struct t_rsd_74 *bp08, struct t_aa0 *bp0c, int bp10) {
	struct {
		const char **local_34;
		int i;//local_33
		char local_32[128];
	}lolo;

	//== RELEASE ==
	if(D_00972174) {
		bp08->f_40.dwUseArchive = 1;
		bp08->f_40.dwArchiveId = ARCHIVE_07;
		bp08->f_40.f_0c = 0;
	}
	//== ==
	if(bp10 == 0) {//else 0076FA1D
		D_00E72984 = 0x24;
		if(D_00972174 == 0) {
			//===========
			//== DEVEL ==
			//===========
			if(D_00E3BA68.dwGrMode == 2)
				lolo.local_34 = D_0096FE30;
			else
				lolo.local_34 = D_0096FD10;
		} else {
			//=============
			//== RELEASE ==
			//=============
			if(D_00E3BA68.dwGrMode == 2)
				lolo.local_34 = D_0096FEC0;
			else
				lolo.local_34 = D_0096FDA0;
		}
		strcpy(lolo.local_32, D_00E3B640);
		strcat(lolo.local_32, /*971C94*/"data\\long\\lsprite");
		D_00E72980 = D_0096FF50;
	} else {
		D_00E72984 = 7;
		if(D_00972174 == 0) {
			//===========
			//== DEVEL ==
			//===========
			if(D_00E3BA68.dwGrMode == 2)
				lolo.local_34 = D_0096FCD0;
			else
				lolo.local_34 = D_0096FC90;
		} else {
			//=============
			//== RELEASE ==
			//=============
			if(D_00E3BA68.dwGrMode == 2)
				lolo.local_34 = D_0096FCF0;
			else
				lolo.local_34 = D_0096FCB0;
		}
		strcpy(lolo.local_32, D_00E3B640);
		strcat(lolo.local_32, /*971CA8*/"data\\short\\ssprite");
		D_00E72980 = D_00970350;
	}
	for(lolo.i = 0; lolo.i < D_00E72984; lolo.i ++) {
		if(bp10 == 0) {//else 0076FBE0
			if(lolo.i != 3 && lolo.i != 6 && lolo.i != 0x21) {//else 0076FB7D
				C_006745E6(4, bp08);//rsd:init with blend mode?
				if(D_00972174) {
					//=============
					//== RELEASE ==
					//=============
					bp08->f_40.dwUseArchive = 1;
					bp08->f_40.dwArchiveId = ARCHIVE_07;
					bp08->f_40.f_0c = 0;
				}
				D_00E71C60[lolo.i].dwIsTransparent = 0;
			} else {
				C_006745E6(1, bp08);//rsd:init with blend mode?
				if(D_00972174) {
					//=============
					//== RELEASE ==
					//=============
					bp08->f_40.dwUseArchive = 1;
					bp08->f_40.dwArchiveId = ARCHIVE_07;
					bp08->f_40.f_0c = 0;
				}
				D_00E71C60[lolo.i].dwIsTransparent = 1;
			}
			bp08->szDir = lolo.local_32;
			bp08->dwRSDFlags |= RSD_00000010;
		} else {
			if(lolo.i) {//else 0076FC33
				C_006745E6(4, bp08);//rsd:init with blend mode?
				if(D_00972174) {
					//=============
					//== RELEASE ==
					//=============
					bp08->f_40.dwUseArchive = 1;
					bp08->f_40.dwArchiveId = ARCHIVE_07;
					bp08->f_40.f_0c = 0;
				}
				D_00E71C60[lolo.i].dwIsTransparent = 0;
			} else {
				C_006745E6(1, bp08);//rsd:init with blend mode?
				if(D_00972174) {
					//=============
					//== RELEASE ==
					//=============
					bp08->f_40.dwUseArchive = 1;
					bp08->f_40.dwArchiveId = ARCHIVE_07;
					bp08->f_40.f_0c = 0;
				}
				D_00E71C60[lolo.i].dwIsTransparent = 1;
			}
			bp08->szDir = lolo.local_32;
			bp08->dwRSDFlags |= RSD_00000010;
		}
		D_00E71C60[lolo.i].f_48 = C_006710AC(1, DX_SFX_TYPE_0C, bp08, lolo.local_34[lolo.i], bp0c->f_910);//dx_sfx:alloc/create?
		D_00E71C60[lolo.i].dwActive = 1;
		D_00E71C60[lolo.i].dwDoRender = 0;
		D_00E71C60[lolo.i].dwWidth = D_00E71C60[lolo.i].dwHeight = D_00E3BA94;
		D_00E71C60[lolo.i].f_00.c.r = D_00E71C60[lolo.i].f_00.c.g = D_00E71C60[lolo.i].f_00.c.b = 0x80;
		D_00E71C60[lolo.i].f_40 = 0;
	}//end for
}

//ch_chr:clean(2)?
void C_0076FD68() {
	int i;

	for(i = 0; i < D_00E72984; i ++) {
		if(D_00E71C60[i].dwActive) {
			C_00670FD3(D_00E71C60[i].f_48);//dx_sfx:release "struct t_dx_sfx_e0 *"
			D_00E71C60[i].f_48 = 0;
			D_00E71C60[i].dwActive = 0;
		}
	}//end for
}

//ch_chr:reset
void C_0076FDD3() {
	unsigned short i;//local_1

	for(i = 0; i < D_00E72984; i ++) {
		if(D_00E71C60[i].dwActive && D_00E71C60[i].dwDoRender) {
			D_00E71C60[i].dwDoRender = 0;
		}
	}//end for
}

//ch_chr:render(solid)?
void C_0076FE41(struct t_aa0 *bp08) {
	unsigned short i;//local_1

	for(i = 0; i < D_00E72984; i ++) {
		if(D_00E71C60[i].dwActive && D_00E71C60[i].dwDoRender && !D_00E71C60[i].dwIsTransparent)
			C_0066E641(D_00E71C60[i].f_48, bp08);//dx_spr:render
	}//end for
}

//ch_chr:render(transparent)?
void C_0076FECC(struct t_aa0 *bp08) {
	unsigned short i;//local_1

	for(i = 0; i < D_00E72984; i ++) {
		if(D_00E71C60[i].dwActive && D_00E71C60[i].dwDoRender && D_00E71C60[i].dwIsTransparent)
			C_0066E641(D_00E71C60[i].f_48, bp08);//dx_spr:render
	}//end for
}

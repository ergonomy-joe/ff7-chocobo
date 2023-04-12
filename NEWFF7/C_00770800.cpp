/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo -- 2D elements?

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
const char *D_00971DE0[] = {
	/*00972178*/"data\\tim\\class_c",
	/*0097218C*/"data\\tim\\class_b",
	/*009721A0*/"data\\tim\\class_a",
	/*009721B4*/"data\\tim\\class_s"
};
const char *D_00971DF0 = /*009721C8*/"data\\tim\\class_z";
const char *D_00971DF4 = /*009721DC*/"data\\tim\\kao";
//=================
//== DEVEL HIRES ==
//=================
//"class_a"[DEVEL]
const char *D_00971DF8[] = {
	/*009721EC*/"A00-0.TIM",
	/*009721F8*/"A00-1.TIM",
	/*00972204*/"A01A.TIM",
	/*00972210*/"A01B.TIM",
	/*0097221C*/"A02A_1.TIM",
	/*00972228*/"A02B_1.TIM",
	/*00972234*/"A03A_1a.TIM",
	/*00972240*/"A03A_1b.TIM",
	/*0097224C*/"A03B_1.TIM",
	/*00972258*/"A04.TIM"
};
//"class_b"[DEVEL]
const char *D_00971E20[] = {
	/*00972260*/"B00-0.TIM",
	/*0097226C*/"B00-1.TIM",
	/*00972278*/"B01A.TIM",
	/*00972284*/"B01B.TIM",
	/*00972290*/"B02A_1.TIM",
	/*0097229C*/"B02B_1.TIM",
	/*009722A8*/"B03A_1a.TIM",
	/*009722B4*/"B03A_1b.TIM",
	/*009722C0*/"B03B_1.TIM",
	/*009722CC*/"B04.TIM"
};
//"class_c"[DEVEL]
const char *D_00971E48[] = {
	/*009722D4*/"C00-0.TIM",
	/*009722E0*/"C00-1.TIM",
	/*009722EC*/"C01A.TIM",
	/*009722F8*/"C01B.TIM",
	/*00972304*/"C02A_1.TIM",
	/*00972310*/"C02B_1.TIM",
	/*0097231C*/"C03A_1a.TIM",
	/*00972328*/"C03A_1b.TIM",
	/*00972334*/"C03B.TIM",
	/*00972340*/"C04.TIM"
};
//"class_s"[DEVEL]
const char *D_00971E70[] = {
	/*00972348*/"S00-0.TIM",
	/*00972354*/"S00-1.TIM",
	/*00972360*/"S01A.TIM",
	/*0097236C*/"S01B.TIM",
	/*00972378*/"S02A_1.TIM",
	/*00972384*/"S02B_1.TIM",
	/*00972390*/"S03A_1a.TIM",
	/*0097239C*/"S03A_1b.TIM",
	/*009723A8*/"S03B_1.TIM",
	/*009723B4*/"S04.TIM"
};
//"class_z"[DEVEL]
const char *D_00971E98[] = {
	/*009723BC*/"z01_1.tim",
	/*009723C8*/"z02.tim",
	/*009723D0*/"z04_1.tim",
	/*009723DC*/"z05_1.tim"
};
//"kao"[DEVEL]
const char *D_00971EA8[] = {
	/*009723E8*/"C_KAN1.TIM",
	/*009723F4*/"C_KAN2.TIM",
	/*00972400*/"C_NUM.TIM",
	/*0097240C*/"C_ICON1.TIM",
	/*00972418*/"USFONT1.TIM",
	/*00972424*/"CLC_MINI.TIM",
	/*00972434*/"CSC_MINI.TIM",
	/*00972444*/"C_AUTO.TIM",
	/*00972450*/"C_MANUAL.TIM",
	/*00972460*/"BAR4.TIM",
	/*0097246C*/"BAR5.TIM"
};
//00971ED4  00 00 00 00
//===================
//== RELEASE HIRES ==
//===================
//"class_a"[RELEASE]
const char *D_00971ED8[] = {
	/*00972478*/"AA.tim",
	/*00972480*/"AB.tim",
	/*00972488*/"AC.tim",
	/*00972490*/"AD.tim",
	/*00972498*/"AE.tim",
	/*009724A0*/"AF.tim",
	/*009724A8*/"AG.tim",
	/*009724B0*/"AH.tim",
	/*009724B8*/"AI.tim",
	/*009724C0*/"AJ.tim"
};
//"class_b"[RELEASE]
const char *D_00971F00[] = {
	/*009724C8*/"AK.tim",
	/*009724D0*/"AL.tim",
	/*009724D8*/"AM.tim",
	/*009724E0*/"AN.tim",
	/*009724E8*/"AO.tim",
	/*009724F0*/"AP.tim",
	/*009724F8*/"AQ.tim",
	/*00972500*/"AR.tim",
	/*00972508*/"AS.tim",
	/*00972510*/"AT.tim"
};
//"class_c"[RELEASE]
const char *D_00971F28[] = {
	/*00972518*/"AU.tim",
	/*00972520*/"AV.tim",
	/*00972528*/"AW.tim",
	/*00972530*/"AX.tim",
	/*00972538*/"AY.tim",
	/*00972540*/"AZ.tim",
	/*00972548*/"BA.tim",
	/*00972550*/"BB.tim",
	/*00972558*/"BC.tim",
	/*00972560*/"BD.tim"
};
//"class_s"[RELEASE]
const char *D_00971F50[] = {
	/*00972568*/"BE.tim",
	/*00972570*/"BF.tim",
	/*00972578*/"BG.tim",
	/*00972580*/"BH.tim",
	/*00972588*/"BI.tim",
	/*00972590*/"BJ.tim",
	/*00972598*/"BK.tim",
	/*009725A0*/"BL.tim",
	/*009725A8*/"BM.tim",
	/*009725B0*/"BN.tim"
};
//"class_z"[RELEASE]
const char *D_00971F78[] = {
	/*009725B8*/"BO.tim",
	/*009725C0*/"BP.tim",
	/*009725C8*/"BQ.tim",
	/*009725D0*/"BR.tim"
};
//"kao"[RELEASE]
const char *D_00971F88[] = {
	/*009725D8*/"BS.tim",
	/*009725E0*/"BT.tim",
	/*009725E8*/"BU.tim",
	/*009725F0*/"BV.tim",
	/*009725F8*/"BW.tim",
	/*00972600*/"BX.tim",
	/*00972608*/"BY.tim",
	/*00972610*/"BZ.tim",
	/*00972618*/"CA.tim",
	/*00972620*/"CB.tim",
	/*00972628*/"CC.tim"
};
//00971FB4  00 00 00 00
//=================
//== DEVEL LORES ==
//=================
//"class_a"[DEVEL]
const char *D_00971FB8[] = {
	/*00972630*/"A00-0.TIM",
	/*0097263C*/"A00-1.TIM",
	/*00972648*/"A01A.TIM",
	/*00972654*/"A01B.TIM",
	/*00972660*/"A02A.TIM",
	/*0097266C*/"A02B.TIM",
	/*00972678*/"A03A.TIM",
	/*00972684*/"NULL.TIM",
	/*00972690*/"A03B.TIM",
	/*0097269C*/"A04.TIM"
};
//"class_b"[DEVEL]
const char *D_00971FE0[] = {
	/*009726A4*/"B00-0.TIM",
	/*009726B0*/"B00-1.TIM",
	/*009726BC*/"B01A.TIM",
	/*009726C8*/"B01B.TIM",
	/*009726D4*/"B02A.TIM",
	/*009726E0*/"B02B.TIM",
	/*009726EC*/"B03A.TIM",
	/*009726F8*/"NULL.TIM",
	/*00972704*/"B03B.TIM",
	/*00972710*/"B04.TIM"
};
//"class_c"[DEVEL]
const char *D_00972008[] = {
	/*00972718*/"C00-0.TIM",
	/*00972724*/"C00-1.TIM",
	/*00972730*/"C01A.TIM",
	/*0097273C*/"C01B.TIM",
	/*00972748*/"C02A.TIM",
	/*00972754*/"C02B.TIM",
	/*00972760*/"C03A.TIM",
	/*0097276C*/"NULL.TIM",
	/*00972778*/"C03B.TIM",
	/*00972784*/"C04.TIM"
};
//"class_s"[DEVEL]
const char *D_00972030[] = {
	/*0097278C*/"S00-0.TIM",
	/*00972798*/"S00-1.TIM",
	/*009727A4*/"S01A.TIM",
	/*009727B0*/"S01B.TIM",
	/*009727BC*/"S02A.TIM",
	/*009727C8*/"S02B.TIM",
	/*009727D4*/"S03A.TIM",
	/*009727E0*/"NULL.TIM",
	/*009727EC*/"S03B.TIM",
	/*009727F8*/"S04.TIM"
};
//"class_z"[DEVEL]
const char *D_00972058[] = {
	/*00972800*/"z01.tim",
	/*00972808*/"z02.tim",
	/*00972810*/"z04.tim",
	/*00972818*/"z05.tim"
};
//"kao"[DEVEL]
const char *D_00972068[] = {
	/*00972820*/"CHO_KAN1.TIM",
	/*00972830*/"CHO_KAN2.TIM",
	/*00972840*/"CHO_NUM.TIM",
	/*0097284C*/"CHO_ICON.TIM",
	/*0097285C*/"USFONT1.TIM",
	/*00972868*/"LC_MINI.TIM",
	/*00972874*/"SC_MINI.TIM",
	/*00972880*/"AUTO.TIM",
	/*0097288C*/"MANUAL.TIM",
	/*00972898*/"BAR4.TIM",
	/*009728A4*/"BAR5.TIM"
};
//00972094  00 00 00 00
//===================
//== RELEASE LORES ==
//===================
//"class_a"[RELEASE]
const char *D_00972098[] = {
	/*009728B0*/"AA.tim",
	/*009728B8*/"AB.tim",
	/*009728C0*/"AC.tim",
	/*009728C8*/"AD.tim",
	/*009728D0*/"RE.tim",
	/*009728D8*/"RF.tim",
	/*009728E0*/"RG.tim",
	/*009728E8*/"NULL.tim",
	/*009728F4*/"RH.tim",
	/*009728FC*/"AJ.tim"
};
//"class_b"[RELEASE]
const char *D_009720C0[] = {
	/*00972904*/"AK.tim",
	/*0097290C*/"AL.tim",
	/*00972914*/"AM.tim",
	/*0097291C*/"AN.tim",
	/*00972924*/"RI.TIM",
	/*0097292C*/"RJ.TIM",
	/*00972934*/"RK.TIM",
	/*0097293C*/"NULL.TIM",
	/*00972948*/"RL.TIM",
	/*00972950*/"AT.tim"
};
//"class_c"[RELEASE]
const char *D_009720E8[] = {
	/*00972958*/"AU.tim",
	/*00972960*/"AV.tim",
	/*00972968*/"AW.tim",
	/*00972970*/"AX.tim",
	/*00972978*/"RM.TIM",
	/*00972980*/"RN.TIM",
	/*00972988*/"RO.TIM",
	/*00972990*/"NULL.TIM",
	/*0097299C*/"RP.TIM",
	/*009729A4*/"BD.tim"
};
//"class_s"[RELEASE]
const char *D_00972110[] = {
	/*009729AC*/"BE.tim",
	/*009729B4*/"BF.tim",
	/*009729BC*/"BG.tim",
	/*009729C4*/"BH.tim",
	/*009729CC*/"RQ.TIM",
	/*009729D4*/"RR.TIM",
	/*009729DC*/"RS.TIM",
	/*009729E4*/"NULL.TIM",
	/*009729F0*/"RT.TIM",
	/*009729F8*/"BN.tim"
};
//"class_z"[RELEASE]
const char *D_00972138[] = {
	/*00972A00*/"RU.tim",
	/*00972A08*/"BP.tim",
	/*00972A10*/"RV.tim",
	/*00972A18*/"RW.tim"
};
//"kao"[RELEASE]
const char *D_00972148[] = {
	/*00972A20*/"RX.TIM",
	/*00972A28*/"RY.TIM",
	/*00972A30*/"RZ.TIM",
	/*00972A38*/"SA.TIM",
	/*00972A40*/"BW.tim",
	/*00972A48*/"SB.TIM",
	/*00972A50*/"SC.TIM",
	/*00972A58*/"SD.TIM",
	/*00972A60*/"SE.TIM",
	/*00972A68*/"CB.tim",
	/*00972A70*/"CC.tim"
};
//== ==
int D_00972174 = 1;//{devel,fs}/{release,archive} flag
////////////////////////////////////////
struct t_chocobo_local_1c D_00E72990[0x28];//renderers for UI?//check
struct t_chocobo_local_1c D_00E72DF0;//[for SW patch]
int D_00E72E0C;//index in D_00E72990[] for init
//D_00E72E10
////////////////////////////////////////
//chocobo:2D elements.init
void C_00770800(struct t_aa0 *bp08, struct t_rsd_74 *bp0c, int bp10, int dwRaceRank/*bp14*/) {
	struct {
		unsigned short i; char _p_118[2];//bp_118
		const char **bp_114;
		int bp_110;
		int dwBlendMode;//bp_10c
		const char **bp_108;
		const char **bp_104;
		char bp_100[0x100];
	}lolo;

	D_00E72E0C = 0;
	switch(dwRaceRank) {
		case 0://"class_c"
			if(D_00972174 == 0) {
				//===========
				//== DEVEL ==
				//===========
				if(D_00E3BA68.dwGrMode == 2)
					lolo.bp_108 = D_00971E48;
				else
					lolo.bp_108 = D_00972008;
			} else {
				//=============
				//== RELEASE ==
				//=============
				if(D_00E3BA68.dwGrMode == 2)
					lolo.bp_108 = D_00971F28;
				else
					lolo.bp_108 = D_009720E8;
			}
			lolo.bp_110 = 0;
		break;
		case 1://"class_b"
			if(D_00972174 == 0) {
				//===========
				//== DEVEL ==
				//===========
				if(D_00E3BA68.dwGrMode == 2)
					lolo.bp_108 = D_00971E20;
				else
					lolo.bp_108 = D_00971FE0;
			} else {
				//=============
				//== RELEASE ==
				//=============
				if(D_00E3BA68.dwGrMode == 2)
					lolo.bp_108 = D_00971F00;
				else
					lolo.bp_108 = D_009720C0;
			}
			lolo.bp_110 = 1;
		break;
		case 2://"class_a"
			if(D_00972174 == 0) {
				//===========
				//== DEVEL ==
				//===========
				if(D_00E3BA68.dwGrMode == 2)
					lolo.bp_108 = D_00971DF8;
				else
					lolo.bp_108 = D_00971FB8;
			} else {
				//=============
				//== RELEASE ==
				//=============
				if(D_00E3BA68.dwGrMode == 2)
					lolo.bp_108 = D_00971ED8;
				else
					lolo.bp_108 = D_00972098;
			}
			lolo.bp_110 = 1;
		break;
		case 3://"class_s"
			if(D_00972174 == 0) {
				//===========
				//== DEVEL ==
				//===========
				if(D_00E3BA68.dwGrMode == 2)
					lolo.bp_108 = D_00971E70;
				else
					lolo.bp_108 = D_00972030;
			} else {
				//=============
				//== RELEASE ==
				//=============
				if(D_00E3BA68.dwGrMode == 2)
					lolo.bp_108 = D_00971F50;
				else
					lolo.bp_108 = D_00972110;
			}
			lolo.bp_110 = 0;
		break;
	}//end switch
	//-- "data\\tim\\class_{c|b|a|s}" --
	strcpy(lolo.bp_100, D_00E3B640);
	strcat(lolo.bp_100, D_00971DE0[dwRaceRank]);
	bp0c->szDir = lolo.bp_100;
	bp0c->dwRSDFlags |= RSD_00000010;
	for(lolo.i = 0; lolo.i < 0xa; lolo.i ++) {
		if(D_00E3BA68.dwGrMode != 2 && lolo.i == 7) {
			D_00E72E0C ++;
			continue;
		}
		D_00E72990[D_00E72E0C].dwIsTransparent = 0;
		if((lolo.i != 2 && lolo.i != 3) || !lolo.bp_110) {//else 00770B69
			lolo.dwBlendMode = 4;
			C_006745E6(lolo.dwBlendMode, bp0c);//rsd:init with blend mode?
			//== RELEASE ==
			if(D_00972174) {
				bp0c->f_40.dwUseArchive = 1;
				bp0c->f_40.dwArchiveId = ARCHIVE_07;
				bp0c->f_40.f_0c = 0;
			}
			//== ==
			strcpy(lolo.bp_100, D_00E3B640);
			strcat(lolo.bp_100, D_00971DE0[dwRaceRank]);
			bp0c->szDir = lolo.bp_100;
			bp0c->dwRSDFlags |= RSD_00000010;
			//goto 00770C39
		} else {
			D_00E72990[D_00E72E0C].dwIsTransparent = 1;
			lolo.dwBlendMode = 0;
			C_006745E6(lolo.dwBlendMode, bp0c);//rsd:init with blend mode?
			//== RELEASE ==
			if(D_00972174) {
				bp0c->f_40.dwUseArchive = 1;
				bp0c->f_40.dwArchiveId = ARCHIVE_07;
				bp0c->f_40.f_0c = 0;
			}
			//== ==
			strcpy(lolo.bp_100, D_00E3B640);
			strcat(lolo.bp_100, D_00971DE0[dwRaceRank]);
			bp0c->szDir = lolo.bp_100;
			bp0c->dwRSDFlags |= RSD_00000010;
		}
		D_00E72990[D_00E72E0C].f_00 = C_006710AC(1, DX_SFX_TYPE_0C, bp0c, lolo.bp_108[lolo.i], bp08->f_910);//dx_sfx:alloc/create?
		D_00E72990[D_00E72E0C].dwActive = 1;
		D_00E72990[D_00E72E0C].dwDoRender = 0;
		D_00E72E0C ++;
	}//end for
	//-- --
	if(lolo.bp_110) {//else 00770DC2
		lolo.dwBlendMode = 4;
		C_006745E6(lolo.dwBlendMode, bp0c);//rsd:init with blend mode?
		//== RELEASE ==
		if(D_00972174) {
			bp0c->f_40.dwUseArchive = 1;
			bp0c->f_40.dwArchiveId = ARCHIVE_07;
			bp0c->f_40.f_0c = 0;
		}
		//== ==
		strcpy(lolo.bp_100, D_00E3B640);
		strcat(lolo.bp_100, D_00971DE0[dwRaceRank]);
		bp0c->szDir = lolo.bp_100;
		bp0c->dwRSDFlags |= RSD_00000010;
		D_00E72990[0x1a].dwIsTransparent = 0;
		D_00E72990[0x1a].f_00 = C_006710AC(1, DX_SFX_TYPE_0C, bp0c, lolo.bp_108[3], bp08->f_910);//dx_sfx:alloc/create?
		D_00E72990[0x1a].dwActive = 1;
		D_00E72990[0x1a].dwDoRender = 0;
	}
	//-- "data\\tim\\class_z" --
	strcpy(lolo.bp_100, D_00E3B640);
	strcat(lolo.bp_100, D_00971DF0);
	bp0c->szDir = lolo.bp_100;
	bp0c->dwRSDFlags |= RSD_00000010;
	if(D_00972174 == 0) {
		//===========
		//== DEVEL ==
		//===========
		if(D_00E3BA68.dwGrMode == 2)
			lolo.bp_114 = D_00971E98;
		else
			lolo.bp_114 = D_00972058;
	} else {
		//=============
		//== RELEASE ==
		//=============
		if(D_00E3BA68.dwGrMode == 2)
			lolo.bp_114 = D_00971F78;
		else
			lolo.bp_114 = D_00972138;
	}
	for(lolo.i = 0; lolo.i < 4; lolo.i ++) {
		D_00E72990[D_00E72E0C].dwIsTransparent = 0;
		D_00E72990[D_00E72E0C].f_00 = C_006710AC(1, DX_SFX_TYPE_0C, bp0c, lolo.bp_114[lolo.i], bp08->f_910);//dx_sfx:alloc/create?
		D_00E72990[D_00E72E0C].dwActive = 1;
		D_00E72990[D_00E72E0C].dwDoRender = 0;
		D_00E72E0C ++;
	}//end for
	//-- "data\\tim\\kao" --
	strcpy(lolo.bp_100, D_00E3B640);
	strcat(lolo.bp_100, D_00971DF4);
	bp0c->szDir = lolo.bp_100;
	bp0c->dwRSDFlags |= RSD_00000010;
	if(D_00972174 == 0) {
		//===========
		//== DEVEL ==
		//===========
		if(D_00E3BA68.dwGrMode == 2)
			lolo.bp_104 = D_00971EA8;
		else
			lolo.bp_104 = D_00972068;
	} else {
		//=============
		//== RELEASE ==
		//=============
		if(D_00E3BA68.dwGrMode == 2)
			lolo.bp_104 = D_00971F88;
		else
			lolo.bp_104 = D_00972148;
	}
	for(lolo.i = 0; lolo.i < 0xb; lolo.i ++) {
		if(lolo.i == 4) {
			D_00E72E0C ++;
			continue;
		}
		D_00E72990[D_00E72E0C].dwIsTransparent = 0;
		if(D_00E3B74C == 0 && lolo.i == 6)
			continue;
		if(D_00E3B74C == 1 && lolo.i == 5)
			continue;
		if(lolo.i != 6 && lolo.i != 5) {//else 00771181
			lolo.dwBlendMode = 4;
			C_006745E6(lolo.dwBlendMode, bp0c);//rsd:init with blend mode?
			//== RELEASE ==
			if(D_00972174) {
				bp0c->f_40.dwUseArchive = 1;
				bp0c->f_40.dwArchiveId = ARCHIVE_07;
				bp0c->f_40.f_0c = 0;
			}
			//== ==
			strcpy(lolo.bp_100, D_00E3B640);
			strcat(lolo.bp_100, D_00971DF4);
			bp0c->szDir = lolo.bp_100;
			bp0c->dwRSDFlags |= RSD_00000010;
		} else {
			D_00E72990[D_00E72E0C].dwIsTransparent = 1;
			lolo.dwBlendMode = 0;
			C_006745E6(lolo.dwBlendMode, bp0c);//rsd:init with blend mode?
			//== RELEASE ==
			if(D_00972174) {
				bp0c->f_40.dwUseArchive = 1;
				bp0c->f_40.dwArchiveId = ARCHIVE_07;
				bp0c->f_40.f_0c = 0;
			}
			//== ==
			strcpy(lolo.bp_100, D_00E3B640);
			strcat(lolo.bp_100, D_00971DF4);
			bp0c->szDir = lolo.bp_100;
			bp0c->dwRSDFlags |= RSD_00000010;
		}
		if(lolo.i < 7 || bp10 != 0) {//else 00771352
			if(lolo.i == 0xa || lolo.i == 9) {//else 007712B0
				if(D_00E3BA68.dwGrMode == 2)
					bp0c->f_70 |= SWRENDERFLAG_00000040;
				else
					bp0c->f_70 |= SWRENDERFLAG_00000020;
			}
			if(lolo.i == 8 || lolo.i == 7)
				bp0c->f_70 |= SWRENDERFLAG_00000020;
			D_00E72990[D_00E72E0C].f_00 = C_006710AC(1, DX_SFX_TYPE_0C, bp0c, lolo.bp_104[lolo.i], bp08->f_910);//dx_sfx:alloc/create?
			D_00E72990[D_00E72E0C].dwActive = 1;
			D_00E72990[D_00E72E0C].dwDoRender = 0;
			D_00E72E0C ++;
		}
	}//end for
	//-- --
	D_00E72E0C = 0x18;
	D_00E72990[0x18].f_00 = C_006710AC(1, DX_SFX_TYPE_08, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E72990[0x18].dwActive = 1;
	D_00E72990[0x18].dwDoRender = 0;
	D_00E72E0C ++;
	//-- --
	lolo.dwBlendMode = 0;
	C_006745E6(lolo.dwBlendMode, bp0c);//rsd:init with blend mode?
	bp0c->f_70 |= SWRENDERFLAG_00004000;
	//== RELEASE ==
	if(D_00972174) {
		bp0c->f_40.dwUseArchive = 1;
		bp0c->f_40.dwArchiveId = ARCHIVE_07;
		bp0c->f_40.f_0c = 0;
	}
	//== ==
	D_00E72990[D_00E72E0C].f_00 = C_006710AC(1, DX_SFX_TYPE_08, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
	D_00E72990[D_00E72E0C].dwActive = 1;
	D_00E72990[D_00E72E0C].dwDoRender = 0;
	D_00E72990[D_00E72E0C].dwIsTransparent = 1;
	D_00E72E0C ++;
	//-- [for SW patch] --
	if(D_00E3BA68.dwSWRenderer) {
		lolo.dwBlendMode = 1;
		C_006745E6(lolo.dwBlendMode, bp0c);//rsd:init with blend mode?
		bp0c->f_70 |= SWRENDERFLAG_00004000;
		D_00E72DF0.f_00 = C_006710AC(1, DX_SFX_TYPE_08, bp0c, 0, bp08->f_910);//dx_sfx:alloc/create?
		D_00E72DF0.dwDoRender = 0;
		D_00E72DF0.dwActive = 1;
	}
}

//chocobo:2D elements.clean
void C_007714E9() {
	unsigned short i;//local_1

	for(i = 0; i < 0x28; i ++) {
		if(D_00E72990[i].dwActive) {
			C_00670FD3(D_00E72990[i].f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
			D_00E72990[i].f_00 = 0;
			D_00E72990[i].dwActive = 0;
		}
	}//end for
	//-- [for SW patch] --
	if(D_00E3BA68.dwSWRenderer) {
		if(D_00E72DF0.dwActive) {
			C_00670FD3(D_00E72DF0.f_00);//dx_sfx:release "struct t_dx_sfx_e0 *"
			D_00E72DF0.f_00 = 0;
			D_00E72DF0.dwActive = 0;
		}
	}
}

//chocobo:2D elements.reset
void C_007715A4() {
	unsigned short i;//local_1

	for(i = 0; i < 0x28; i ++) {
		if(D_00E72990[i].dwActive && D_00E72990[i].dwDoRender) {
			C_006716F5(D_00E72990[i].f_00);//dx_sfx:reset something?
			D_00E72990[i].dwDoRender = 0;
		}
	}//end for
	//-- [for SW patch] --
	if(D_00E3BA68.dwSWRenderer) {
		if(D_00E72DF0.dwDoRender) {
			C_006716F5(D_00E72DF0.f_00);//dx_sfx:reset something?
			D_00E72DF0.dwDoRender = 0;
		}
	}
}

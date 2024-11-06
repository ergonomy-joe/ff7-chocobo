/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//Chocobo --

#define __FF7FILE__ "C:\\FF7\\chocobo\\ch_ddraw.cpp"

#include "ff7.h"
#include "chocobo_data.h"
////////////////////////////////////////
int D_00E73C10;//0=RGB565,1=...
int D_00E73C14,D_00E73C18,D_00E73C1C;//RGB mask
LPDIRECTDRAW D_00E73C20;
LPDIRECTDRAWSURFACE D_00E73C24;
LPDIRECTDRAWSURFACE D_00E73C28;
////////////////////////////////////////
//ch_ddraw:init
void C_007794F0(struct t_aa0 *bp08) {
	D_00E73C20 = bp08->lpDD;
	D_00E73C24 = bp08->f_07c[0];
	D_00E73C28 = bp08->f_07c[1];
}

//ch_ddraw:[start]
int __0077951B() {
	struct t_aa0 *local_1;

	local_1 = C_00676578();
	if(C_0067806E(local_1))//graphic driver:START?
		C_007794F0(local_1);//ch_ddraw:init

	return 1;
}

//ch_ddraw:[stop]
void __0077954C() {
	struct t_aa0 *local_1;

	if(D_00E73C20) {
		local_1 = C_00676578();
		C_00679864(local_1);//graphic driver:STOP?
		D_00E73C20 = 0;
		D_00E73C24 = 0;
	}
}

//ch_ddraw:init(2)
int C_00779585(struct t_aa0 *bp08) {
	struct tTextureInfo *local_1;

	local_1 = &(bp08->f_79c);
	if(local_1->dwRedBitCount == 5 && local_1->dwGreenBitCount == 6 && local_1->dwBlueBitCount == 5)
		D_00E73C10 = 0;
	else
		D_00E73C10 = 1;
	D_00E73C14 = local_1->dwRedMask;
	D_00E73C18 = local_1->dwGreenMask;
	D_00E73C1C = local_1->dwBlueMask;

	return 1;
}

//ch_ddraw:flip
int __007795F1() {
	struct t_aa0 *local_1;

	local_1 = C_00676578();
	g_drv_flip(local_1);

	return 1;
}

//ch_ddraw:Lock
int __00779612(LPDIRECTDRAWSURFACE bp08, void **bp0c, unsigned *pdwPitch/*bp10*/) {
	struct {
		DDSURFACEDESC local_28;
		HRESULT hResult;//local_1
	}lolo;

	memset(&lolo.local_28, 0, sizeof(DDSURFACEDESC));
	lolo.local_28.dwSize = sizeof(DDSURFACEDESC);
	lolo.hResult = bp08->Lock(0, &lolo.local_28, DDLOCK_WAIT, 0);
	if(lolo.hResult != 0)
		return 0;
	*bp0c = lolo.local_28.lpSurface;
	*pdwPitch = lolo.local_28.lPitch;

	return lolo.hResult == 0;
}

//ch_ddraw:Unlock
int __0077966D(LPDIRECTDRAWSURFACE bp08) {
	bp08->Unlock(0);

	return 1;
}

//ch_ddraw:Blt
int __00779688(LPDIRECTDRAWSURFACE bp08, LPDIRECTDRAWSURFACE bp0c, LPRECT bp10, LPRECT bp14, DWORD bp18, LPDDBLTFX bp1c) {
	struct {
		HRESULT hResult;//bp_08
		LPDIRECTDRAWSURFACE bp_04;
	}lolo;

	while(1) {
		lolo.bp_04 = bp08;
		lolo.hResult = lolo.bp_04->Blt(bp14, bp0c, bp10, bp18, bp1c);
		switch(lolo.hResult) {
			case 0: return 1;
			case DDERR_SURFACELOST: break;//0x887601C2
			case DDERR_WASSTILLDRAWING: return 1;//0x8876021C
			default:
				return 0;
		}//end switch
	}

	return 1;
}

//ch_ddraw:BltFast
int __007796FF(LPDIRECTDRAWSURFACE bp08, LPDIRECTDRAWSURFACE bp0c, LPRECT bp10, LPRECT bp14, DWORD bp18) {
	struct {
		HRESULT hResult;//bp_08
		LPDIRECTDRAWSURFACE bp_04;
	}lolo;

	while(1) {
		lolo.bp_04 = bp08;
		lolo.hResult = lolo.bp_04->BltFast(bp14->left, bp14->top, bp0c, bp10, bp18);
		switch(lolo.hResult) {
			case 0: return 1;
			case DDERR_SURFACELOST: break;//0x887601C2
			case DDERR_WASSTILLDRAWING: return 1;//0x8876021C
			default:
				return 0;
		}//end switch
	}

	return 1;
}

//ch_ddraw:SetColorKey
void C_0077977B(LPDIRECTDRAWSURFACE bp08, int dwColorKey/*bp0c*/, int dwFlags/*bp10*/) {
	DDCOLORKEY ddColorKey;

	ddColorKey.dwColorSpaceLowValue = dwColorKey;
	ddColorKey.dwColorSpaceHighValue = dwColorKey;
	bp08->SetColorKey(dwFlags, &ddColorKey);
}

//ch_ddraw:CreateSurface
LPDIRECTDRAWSURFACE __007797A5(int dwWidth/*bp08*/, int dwHeight/*bp0c*/) {
	struct {
		LPDIRECTDRAWSURFACE local_29;
		DDSURFACEDESC local_28;
		HRESULT hResult;//local_1
	}lolo;

	lolo.local_28.dwSize = sizeof(DDSURFACEDESC);//x6c
	lolo.local_28.dwFlags = DDSD_WIDTH|DDSD_HEIGHT|DDSD_CAPS;
	lolo.local_28.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
	lolo.local_28.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
	lolo.local_28.dwWidth = dwWidth;
	lolo.local_28.dwHeight = dwHeight;
	lolo.hResult = D_00E73C20->CreateSurface(&lolo.local_28, &lolo.local_29, 0);
	if(lolo.hResult != 0)
		return 0;
	C_0077977B(lolo.local_29, 0, DDCKEY_SRCBLT);//ch_ddraw:SetColorKey

	return lolo.local_29;
}

//ch_ddraw:allocate surface memory?
void *__00779815(int dwWidth/*bp08*/, int dwHeight/*bp0c*/) {
	void *local_1;

	local_1 = mem_malloc(dwWidth * dwHeight * 2, __FF7FILE__, 0xe4);
	if(local_1 == 0)
		return 0;

	return local_1;
}

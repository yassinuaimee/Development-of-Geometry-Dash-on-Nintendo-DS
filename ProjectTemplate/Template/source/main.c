/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "ResRedBG.h"

int main(void) {

	    // Activate main engine and background 3 in standard tiled mode
		VRAM_A_CR=VRAM_ENABLE|VRAM_A_MAIN_BG;
		REG_DISPCNT= MODE_0_2D|DISPLAY_BG3_ACTIVE;

		// 3) Configure the background
		BGCTRL[3]=BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;

		//Copy tiles and palette (shared by all backgrounds in this case)
		swiCopy(ResRedBGPal,BG_PALETTE,ResRedBGPalLen/2);
		swiCopy(ResRedBGTiles,BG_TILE_RAM(1),ResRedBGTilesLen/2);
		//Copy maps (32x24 components of 2 bytes for each of the map bases)
		swiCopy(&ResRedBGMap[0], BG_MAP_RAM(0), 32*24);

		//Local variables to track the shifting
		int bg3 = 0;
//		int bg1 = 0;

		//Shifting background
	    while(1) {
	    	//Assign shift registers (they are not readable!)
	    	REG_BG3HOFS = bg3;
//	    	REG_BG1HOFS = bg1;
	    	//Update local variables that track the shifting
//	    	if(--bg0 < 0) bg0 = 255;
	    	if(++bg3 > 255) bg3 = 0;
	        swiWaitForVBlank();
	    }


//    consoleDemoInit();
//    printf("\nTemplate nds\n");
}



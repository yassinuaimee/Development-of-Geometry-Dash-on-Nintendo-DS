#include <nds.h>
#include <stdio.h>
#include "clouds.h"

int main(void) {

	// Activate main engine and backgrounds 0, 1 and 2 in standard tiled mode
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE | DISPLAY_BG2_ACTIVE;
	BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;
	BGCTRL[1] = BG_COLOR_256 | BG_MAP_BASE(1) | BG_TILE_BASE(1) | BG_32x32;
	BGCTRL[2] = BG_COLOR_256 | BG_MAP_BASE(2) | BG_TILE_BASE(1) | BG_32x32;

	//Copy tiles and palette (shared by all backgrounds in this case)
	swiCopy(cloudsTiles, BG_TILE_RAM(1), cloudsTilesLen/2);
	swiCopy(cloudsPal, BG_PALETTE, cloudsPalLen/2);
	//Copy maps (32x24 components of 2 bytes for each of the map bases)
	swiCopy(&cloudsMap[0], BG_MAP_RAM(1), 32*24);
	//swiCopy(&cloudsMap[32*24], BG_MAP_RAM(0), 32*24);
	//swiCopy(&cloudsMap[32*48], BG_MAP_RAM(2), 32*24);

	//Local variables to track the shifting
	int bg0 = 0, bg1 = 0;

	//Shifting background
    while(1) {
    	//Assign shift registers (they are not readable!)
    	//REG_BG0HOFS = bg0;
    	//REG_BG1HOFS = bg1;
    	//Update local variables that track the shifting
    	if(--bg0 < 0) bg0 = 255;
    	if(++bg1 > 255) bg1 = 0;
        swiWaitForVBlank();
    }
}

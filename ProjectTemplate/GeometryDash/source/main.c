/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "ResRedBG.h"
#include "sprite.h"
#define SCREEN_WIDTH	256
#define	SCREEN_HEIGHT	192

#define	SPRITE_WIDTH	8
#define	SPRITE_HEIGHT	8
u16* gfx;

void configureBG3()
{
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
}
int main(void) {



	    configureBG3();
	    configureSprites();
		//Local variables to track the shifting
		int bg3 = 0;
//		int bg1 = 0;
		int x = 30, y = 0, keys;
		//Shifting background
	    while(1) {
	    	scanKeys();
	    	keys = keysHeld();

	       	//Modify position of the sprite accordingly
	    	if((keys & KEY_DOWN) && (y < (SCREEN_HEIGHT - SPRITE_HEIGHT))) y+=2;
	      	if((keys & KEY_UP) && (y  > 0)) y-=2;
	    	//Assign shift registers (they are not readable!)
	    	REG_BG3HOFS = bg3;
//	    	REG_BG1HOFS = bg1;
	    	//Update local variables that track the shifting
//	    	if(--bg0 < 0) bg0 = 255;
	    	if(++bg3 > 255) bg3 = 0;
	    	oamSet(&oamMain,0,x, y,0,0,SpriteSize_32x32,SpriteColorFormat_256Color,gfx,-1,false,false,false, false,false);
	        swiWaitForVBlank();
	        oamUpdate(&oamMain);
	    }


//    consoleDemoInit();
//    printf("\nTemplate nds\n");
}



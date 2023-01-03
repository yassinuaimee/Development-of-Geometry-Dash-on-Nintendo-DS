#include "sprite.h"


void configureSprites() {
	//Set up memory bank to work in sprite mode (offset since we are using VRAM A for backgrounds)
	VRAM_G_CR = VRAM_ENABLE | VRAM_G_MAIN_SPRITE;//0x06400000

	//Initialize sprite manager and the engine
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	u16* gfx;
	//Allocate space for the graphic to show in the sprite
	gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	//Copy data for the graphic (palette and bitmap)
	swiCopy(dashPal, SPRITE_PALETTE, dashPalLen/2);
	swiCopy(dashTiles, gfx, dashTilesLen/2);
}
/*void jumpintimer(timeconstant(between 0 and 8)){//might also receive bool finish jump
	timeconstant++;
	switch timeconstant:
		case 0:none
		case 1:move 3
		case 2:move 2
		case 3:move 1
		case 4:none
		case 5:none
		case 6:move -1
		case 7:move -2
		case 8:move-3
	if(jumpfinish or floordetected)
		{
		timeconstant=0
		}
	return;
}
*/

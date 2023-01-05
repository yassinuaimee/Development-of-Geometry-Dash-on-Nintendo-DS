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
int y; //vertical position of sprite,
int tim=10;//timer counter
bool jump;

unsigned char full[]={
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255
};
// unsigned char empty[]={
//		 254,254,254,254,254,254,254,254,
//		 254,254,254,254,254,254,254,254,
//		 254,254,254,254,254,254,254,254,
//		 254,254,254,254,254,254,254,254,
//		 254,254,254,254,254,254,254,254,
//		 254,254,254,254,254,254,254,254,
//		 254,254,254,254,254,254,254,254,
//		 254,254,254,254,254,254,254,254
// };

unsigned char empty[]={
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0
 };

 unsigned char ld[]={
		 0,0,0,0,255,255,255,255,
		 0,0,0,255,255,255,255,255,
		 0,0,255,255,255,255,255,255,
		 0,0,255,255,255,255,255,255,
		 0,255,255,255,255,255,255,255,
		 0,255,255,255,255,255,255,255,
		 255,255,255,255,255,255,255,255,
		 255,255,255,255,255,255,255,255
 };

 unsigned char lm[]={
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,255,
		 0,0,0,0,0,0,255,255,
		 0,0,0,0,0,0,255,255,
		 0,0,0,0,0,255,255,255,
		 0,0,0,0,0,255,255,255,
		 0,0,0,0,255,255,255,255
 };

 unsigned char um[]={
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,255,255,0,0,0,
		 0,0,255,255,255,255,0,0,
		 0,0,255,255,255,255,0,0,
		 0,255,255,255,255,255,255,0,
		 0,255,255,255,255,255,255,0,
 };
//unsigned char um[]={
// 		 0,0,0,0,0,0,0,0,
// 		 0,0,0,0,0,0,0,0,
// 		 0,0,0,0,0,0,0,0,
// 		 0,0,0,0,0,0,0,0,
// 		 0,0,0,0,0,0,0,0,
// 		 0,0,0,0,0,0,0,0,
// 		 0,0,0,0,0,0,0,0,
// 		 0,0,0,0,0,0,0,0
//  };

 unsigned char rm[]={
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 255,0,0,0,0,0,0,0,
		 255,255,0,0,0,0,0,0,
		 255,255,0,0,0,0,0,0,
		 255,255,255,0,0,0,0,0,
		 255,255,255,0,0,0,0,0,
		 255,255,255,255,0,0,0,0,
 };

 unsigned char rd[]={
 		 255,255,255,255,0,0,0,0,
 		 255,255,255,255,255,0,0,0,
 		 255,255,255,255,255,255,0,0,
 		 255,255,255,255,255,255,0,0,
 		 255,255,255,255,255,255,255,0,
 		 255,255,255,255,255,255,255,0,
 		 255,255,255,255,255,255,255,255,
 		 255,255,255,255,255,255,255,255,
  };


 void ISR_TIMER0()
  {
  	tim++;
  	switch (tim){
  		 case 1:
  			 y=y-16;
  			 break;
  		 case 2:
  			 y=y-10;
  			 break;
  		 case 3:
  			 y=y-5;
  		 	 break;
  		 case 4:
  			 y=y-3;
  			 break;
  		 case 5:
  			 break;
  		 case 6:
  			 y=y+3;
  			 break;
  		 case 7:
  		 	y=y+5;
  		 	break;
  		 case 8:
  			y=y+10;
  		 	break;
  		 case 9:
  			y=y+16;
  		 	break;
  		 default:
  			jump=0;
  		 }

  }

 void configTimer0(){
 	TIMER_DATA(0) =TIMER_FREQ_1024(10);
 	TIMER0_CR = TIMER_ENABLE|TIMER_DIV_1024|TIMER_IRQ_REQ;
 	irqSet(IRQ_TIMER0,&ISR_TIMER0);
 	irqEnable(IRQ_TIMER0);
 }

int main(void) {
	// Activate main engine and background 3 in standard tiled mode
	VRAM_A_CR=VRAM_ENABLE|VRAM_A_MAIN_BG;
	REG_DISPCNT= MODE_0_2D|DISPLAY_BG3_ACTIVE|DISPLAY_BG2_ACTIVE;

//	// Configure the background image
	BGCTRL[3]=BG_COLOR_256 | BG_MAP_BASE(25) | BG_TILE_BASE(0) | BG_32x32;
//
//	//Copy tiles and palette (shared by all backgrounds in this case)
	swiCopy(ResRedBGPal,BG_PALETTE,ResRedBGPalLen/2);
	swiCopy(ResRedBGTiles,BG_TILE_RAM(0),ResRedBGTilesLen/2);
//	//Copy maps (32x24 components of 2 bytes for each of the map bases)
	swiCopy(ResRedBGMap,BG_MAP_RAM(25), ResRedBGMapLen/2);
//	swiCopy(&ResRedBGMap[0], BG_MAP_RAM(25), 32*24);

//	VRAM_B_CR=VRAM_ENABLE|VRAM_B_MAIN_BG;
//
	BGCTRL[2]=BG_COLOR_256 | BG_MAP_BASE(30) | BG_TILE_BASE(5) | BG_64x32;
//	//assigning colors to palette
	BG_PALETTE[255] = ARGB16(1,15,0,31);
	BG_PALETTE[254] = ARGB16(1,0,0,0);// 0 to make it transparent
//
//	//copying the tiles in tile ram
	dmaCopy(empty,&BG_TILE_RAM(5)[0],64);//0
	dmaCopy(full,&BG_TILE_RAM(5)[32],64);//1
	dmaCopy(ld,&BG_TILE_RAM(5)[64],64);//2
	dmaCopy(lm,&BG_TILE_RAM(5)[96],64);//3
	dmaCopy(um,&BG_TILE_RAM(5)[128],64);//4
	dmaCopy(rm,&BG_TILE_RAM(5)[160],64);//5
	dmaCopy(rd,&BG_TILE_RAM(5)[192],64);//6
	configureSprites();
	configTimer0();
//
//////		//creating the map with obstacles
	int row,col;

	for(row=0; row<24;row++){
		for(col=0;col<32;col++){

			if(row==14){	//top of the triangle
				if(col==13 || col==25){
					BG_MAP_RAM(30)[row*32+col] = 4;
				}
				if(col==6 || col==17 || col==29){
					BG_MAP_RAM(31)[row*32+col] = 4;
				}
			}
			else if(row==15){ //center of traingle
				if(col==12 || col==24){
					BG_MAP_RAM(30)[row*32+col] = 3;
					BG_MAP_RAM(30)[row*32+col+1] = 1;
					BG_MAP_RAM(30)[row*32+col+2] = 5;
				}
				if(col==5 ||col==16 || col==28){
					BG_MAP_RAM(31)[row*32+col] = 3;
					BG_MAP_RAM(31)[row*32+col+1] = 1;
					BG_MAP_RAM(31)[row*32+col+2] = 5;
				}
			}
			else if(row==16 ){ //bottom of triangle
				if(col==12 || col==24){
					BG_MAP_RAM(30)[row*32+col] = 2;
					BG_MAP_RAM(30)[row*32+col+1] = 1;
					BG_MAP_RAM(30)[row*32+col+2] = 6;
				}
				if(col==5 ||col==16 || col==28){
					BG_MAP_RAM(31)[row*32+col] = 2;
					BG_MAP_RAM(31)[row*32+col+1] = 1;
					BG_MAP_RAM(31)[row*32+col+2] = 6;
				}
			}
			else if(row>16){ //horizontal bar at the bottom
				BG_MAP_RAM(30)[row*32+col] = 1;
				BG_MAP_RAM(31)[row*32+col] = 1;
			}
				else{ //assigning anything else to transparent
					BG_MAP_RAM(30)[row*32+col] = 0;
					BG_MAP_RAM(31)[row*32+col] = 0;
				}

		}
	}

		//Local  variables to track the shifting
		int bg3 = 0;
//		int bg1 = 0;
		int bg2=0;

		//Shifting background
	y=104;
	jump=0;
	while(1)
	{
	    //Assign shift registers (they are not readable!)
		REG_BG3HOFS = bg3;
//	    REG_BG1HOFS = bg1;
		REG_BG2HOFS = bg2;
		//Update local variables that track the shifting
//	    if(--bg0 < 0) bg0 = 255;
		bg3+=2;
	    if(bg3 > 255) bg3 = 0;

	    if(++bg2 > 511) bg2 = 0;
		int x = 30;
		int keys;
		scanKeys();
		keys = keysDown();
		if(keys & KEY_UP){
			if (jump!=1)tim=0;
			else jump=1;
		}
		oamSet(&oamMain,0,x, y,0,0,SpriteSize_32x32,SpriteColorFormat_256Color,gfx,-1,false,false,false, false,false);
		swiWaitForVBlank();
		oamUpdate(&oamMain);
	}

//    consoleDemoInit();
//    printf("\nTemplate nds\n");
}



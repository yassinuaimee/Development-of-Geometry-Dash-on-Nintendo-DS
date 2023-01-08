/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "ResRedBG.h"
#include "sprite.h"

#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#define SCREEN_WIDTH	256
#define	SCREEN_HEIGHT	192

#define	SPRITE_WIDTH	8
#define	SPRITE_HEIGHT	8
u16* gfx;
int y; //vertical position of sprite,
int tim=13;//timer counter
bool jump=0;

unsigned char full[]={
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254
};
unsigned char otherfull[]={
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3
};
unsigned char otherfullmore[]={
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2
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
unsigned char full_obst[]={
 		 255,255,255,255,255,255,255,255,
 		 255,255,255,255,255,255,255,255,
 		 255,255,255,255,255,255,255,255,
 		 255,255,255,255,255,255,255,255,
 		 255,255,255,255,255,255,255,255,
 		 255,255,255,255,255,255,255,255,
 		 255,255,255,255,255,255,255,255,
 		 255,255,255,255,255,255,255,255
  };

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

 unsigned char ilu[]={
		 255,255,255,255,255,255,255,255,
		 255,255,255,255,255,255,255,255,
		 0,255,255,255,255,255,255,255,
		 0,255,255,255,255,255,255,255,
		 0,0,255,255,255,255,255,255,
		 0,0,255,255,255,255,255,255,
		 0,0,0,255,255,255,255,255,
		 0,0,0,0,255,255,255,255,
 };

 unsigned char iru[]={
		 255,255,255,255,255,255,255,255,
		 255,255,255,255,255,255,255,255,
		 255,255,255,255,255,255,255,0,
		 255,255,255,255,255,255,255,0,
		 255,255,255,255,255,255,0,0,
		 255,255,255,255,255,255,0,0,
		 255,255,255,255,255,0,0,0,
		 255,255,255,255,0,0,0,0,
 };

 unsigned char imd[]={
		 0,255,255,255,255,255,255,0,
		 0,255,255,255,255,255,255,0,
		 0,0,255,255,255,255,0,0,
		 0,0,255,255,255,255,0,0,
		 0,0,0,255,255,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0
 };

 unsigned char ilm[]={
		 0,0,0,0,255,255,255,255,
		 0,0,0,0,0,255,255,255,
		 0,0,0,0,0,255,255,255,
		 0,0,0,0,0,0,255,255,
		 0,0,0,0,0,0,255,255,
		 0,0,0,0,0,0,0,255,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
 };

 unsigned char irm[]={
		 255,255,255,255,0,0,0,0,
		 255,255,255,0,0,0,0,0,
		 255,255,255,0,0,0,0,0,
		 255,255,0,0,0,0,0,0,
		 255,255,0,0,0,0,0,0,
		 255,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
 };


 void ISR_TIMER0()
  {
  	tim++;
  	switch (tim){
  		 case 1:
  			 y=90;
  			 break;
  		 case 2:
  			 y=80;
  			 break;
  		 case 3:
  			 y=74;
  		 	 break;
  		 case 4:
  			 y=71;
  			 break;
  		 case 5:
  			 y=70;
  			 break;
  		 case 6:
  			 break;
  		 case 7:
  		 	y=71;
  		 	break;
  		 case 8:
  			y=74;
  		 	break;
  		 case 9:
  			y=80;
  		 	break;
  		 case 10:
  			 y=90;
  			 break;
  		 case 11:
  			 y=104;
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
 void collision(){
	 if(((BG_MAP_RAM(30)[352+4]== 2)||(BG_MAP_RAM(30)[352+4]== 5)||(BG_MAP_RAM(30)[352+5]== 2)||(BG_MAP_RAM(30)[352+5]== 5))&&(y>80)) BG_PALETTE_SUB[255]=ARGB16(1,0,31,1);
	 if(((BG_MAP_RAM(30)[384+4]== 2)||(BG_MAP_RAM(30)[384+4]== 5)||(BG_MAP_RAM(30)[384+5]== 2)||(BG_MAP_RAM(30)[384+5]== 5))&&(y>80)) BG_PALETTE_SUB[255]=ARGB16(1,0,31,1);
	 if(((BG_MAP_RAM(30)[320+4]== 2)||(BG_MAP_RAM(30)[320+4]== 5)||(BG_MAP_RAM(30)[320+5]== 2)||(BG_MAP_RAM(30)[320+5]== 5))&&(y>80)) BG_PALETTE_SUB[255]=ARGB16(1,0,31,1);
 }

void configSub(){
	VRAM_C_CR=VRAM_ENABLE|VRAM_C_SUB_BG;
	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG0_ACTIVE;
	BGCTRL_SUB[0] =BG_32x32|BG_COLOR_256|BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(full, &BG_TILE_RAM_SUB(1)[0], 64);
	dmaCopy(otherfull,&BG_TILE_RAM_SUB(1)[32], 64);
	dmaCopy(otherfullmore,&BG_TILE_RAM_SUB(1)[64], 64);
	BG_PALETTE_SUB[255]=ARGB16(1,20,3,5);
	BG_PALETTE_SUB[3]=ARGB16(1,22,5,7);
	BG_PALETTE_SUB[2]=ARGB16(1,15,31,0);
	int row,col, prod;
		for(row=0;row<24;row++)
		{
			for(col=0;col<32;col++){
				//BG_MAP_RAM_SUB(1)[row*32+col]=1;
				prod=(row-12)*(row-12)+(col-16)*(col-16);
				if((prod<5)||((prod<32)&&(prod>20))||((prod<70)&&(prod>55))||((prod<120)&&(prod>100))||((prod<180)&&(prod>160))||((prod<250)&&(prod>230))||((prod<350)&&(prod>320))){
						BG_MAP_RAM_SUB(0)[row*32+col]=1;
				}
				else{
						BG_MAP_RAM_SUB(0)[row*32+col]=0;

				}
			}}

		for(row=10;row<13;row++){
			for(col=9;col<22;col++){
				if((row=10)&&((col==10)||(col==12)||(col==14)||(col==16)||(col==17)||(col==18)||(col==20)||(col==21)))BG_MAP_RAM_SUB(0)[row*32+col]=2;
				if((row=11)&&((col==10)||(col==12)||(col==14)||(col==16)||(col==18)||(col==20)||(col==21)))BG_MAP_RAM_SUB(0)[row*32+col]=2;
				if((row=12)&&((col==9)||(col==10)||(col==12)||(col==13)||(col==14)||(col==16)||(col==18)||(col==20)))BG_MAP_RAM_SUB(0)[row*32+col]=2;

			}
		}
	};

void ActivateMain(){
	VRAM_A_CR=VRAM_ENABLE|VRAM_A_MAIN_BG;
	REG_DISPCNT= MODE_0_2D|DISPLAY_BG3_ACTIVE|DISPLAY_BG2_ACTIVE;
}


void ConfigureBG3(){
//	// Configure the background image
	BGCTRL[3]=BG_COLOR_256 | BG_MAP_BASE(25) | BG_TILE_BASE(0) | BG_32x32;
//
//	//Copy tiles and palette (shared by all backgrounds in this case)
	swiCopy(ResRedBGPal,BG_PALETTE,ResRedBGPalLen/2);
	swiCopy(ResRedBGTiles,BG_TILE_RAM(0),ResRedBGTilesLen/2);
//	//Copy maps (32x24 components of 2 bytes for each of the map bases)
	swiCopy(ResRedBGMap,BG_MAP_RAM(25), ResRedBGMapLen/2);
//	swiCopy(&ResRedBGMap[0], BG_MAP_RAM(25), 32*24);
}

void ConfigureBG2(){

	BGCTRL[2]=BG_COLOR_256 | BG_MAP_BASE(30) | BG_TILE_BASE(5) | BG_64x32;
//	//assigning colors to palette
	BG_PALETTE[255] = ARGB16(1,15,0,31);
	BG_PALETTE[254] = ARGB16(1,31,21,0);
//	//copying the tiles in tile ram
	dmaCopy(empty,&BG_TILE_RAM(5)[0],64);//0
	dmaCopy(full,&BG_TILE_RAM(5)[32],64);//1
	dmaCopy(ld,&BG_TILE_RAM(5)[64],64);//2
	dmaCopy(lm,&BG_TILE_RAM(5)[96],64);//3
	dmaCopy(um,&BG_TILE_RAM(5)[128],64);//4
	dmaCopy(rm,&BG_TILE_RAM(5)[160],64);//5
	dmaCopy(rd,&BG_TILE_RAM(5)[192],64);//6
	dmaCopy(full_obst,&BG_TILE_RAM(5)[224],64);//7
	dmaCopy(ilu,&BG_TILE_RAM(5)[256],64);//8
	dmaCopy(ilm,&BG_TILE_RAM(5)[288],64);//9
	dmaCopy(imd,&BG_TILE_RAM(5)[320],64);//10
	dmaCopy(irm,&BG_TILE_RAM(5)[352],64);//11
	dmaCopy(iru,&BG_TILE_RAM(5)[384],64);//12
	configureSprites();
	configTimer0();
}

void DrawMap(){

}

//void ShiftBG3(int bg3){
//	REG_BG3HOFS = bg3;
//	bg3+=2;
//    if(bg3 > 255) bg3 = 0;
//}							//shifting does not work when in function
//
//void ShiftBG2(int bg2){
//	REG_BG2HOFS = bg2;
//    if(++bg2 > 511) bg2 = 0;
//}

int main(void) {

//	//Init the sound library
	mmInitDefaultMem((mm_addr)soundbank_bin);
//	//Load module
//	mmLoad(MOD_EYE_OF_THE_TIGER);

	configSub();
	ActivateMain();
	ConfigureBG3();
	ConfigureBG2();
//	DrawMap();
	//creating the map with obstacles

	int row,col;
	//map1
//	for(row=0; row<24;row++){
//		for(col=0;col<32;col++){
//
//			if(row==14){	//top of the triangle
//				if(col==13 || col==25){
//					BG_MAP_RAM(30)[row*32+col] = 4;
//				}
//				if(col==6 || col==24){
//					BG_MAP_RAM(31)[row*32+col] = 4;
//				}
//			}
//			else if(row==15){ //center of traingle
//				if(col==12 || col==24){
//					BG_MAP_RAM(30)[row*32+col] = 3;
//					BG_MAP_RAM(30)[row*32+col+1] = 7;
//					BG_MAP_RAM(30)[row*32+col+2] = 5;
//
//				}
//				if(col==5 || col==23 ){
//					BG_MAP_RAM(31)[row*32+col] = 3;
//					BG_MAP_RAM(31)[row*32+col+1] = 7;
//					BG_MAP_RAM(31)[row*32+col+2] = 5;
//					if (col==5){
//						BG_MAP_RAM(31)[row*32+col+3] = 3;
//						BG_MAP_RAM(31)[row*32+col+4] = 5;
//					}
//				}
//			}
//			else if(row==16 ){ //bottom of triangle
//				if(col==12 || col==24){
//					BG_MAP_RAM(30)[row*32+col] = 2;
//					BG_MAP_RAM(30)[row*32+col+1] = 7;
//					BG_MAP_RAM(30)[row*32+col+2] = 6;
//				}
//				if(col==5  || col==23 ){
//					BG_MAP_RAM(31)[row*32+col] = 2;
//					BG_MAP_RAM(31)[row*32+col+1] = 7;
//					BG_MAP_RAM(31)[row*32+col+2] = 6;
//					if (col==5){
//						BG_MAP_RAM(31)[row*32+col+3] = 2;
//						BG_MAP_RAM(31)[row*32+col+4] = 6;
//					}
//				}
//			}
//			else if(row>16){ //horizontal bar at the bottom
//				BG_MAP_RAM(30)[row*32+col] = 1;
//				BG_MAP_RAM(31)[row*32+col] = 1;
//			}
//			else{ //assigning anything else to transparent
//				BG_MAP_RAM(30)[row*32+col] = 0;
//				BG_MAP_RAM(31)[row*32+col] = 0;
//			}
//
//		}
//	}

	//test map
	for(row=0; row<24;row++){
		for(col=0;col<32;col++){

			if(row==14){	//top of the triangle
				if(col==13 || col==25){
					BG_MAP_RAM(30)[row*32+col] = 4;
				}
				if(col==6 || col==24){
					BG_MAP_RAM(31)[row*32+col] = 4;
				}
			}
			else if(row==15){ //center of traingle
				if(col==12 || col==24){
					BG_MAP_RAM(30)[row*32+col] = 3;
					BG_MAP_RAM(30)[row*32+col+1] = 7;
					BG_MAP_RAM(30)[row*32+col+2] = 5;

				}
				if(col==5 || col==23 ){
					BG_MAP_RAM(31)[row*32+col] = 3;
					BG_MAP_RAM(31)[row*32+col+1] = 7;
					BG_MAP_RAM(31)[row*32+col+2] = 5;
					if (col==5){
						BG_MAP_RAM(31)[row*32+col+3] = 3;
						BG_MAP_RAM(31)[row*32+col+4] = 5;
					}
				}
			}
			else if(row==16 ){ //bottom of triangle
				if(col==12 || col==24){
					BG_MAP_RAM(30)[row*32+col] = 2;
					BG_MAP_RAM(30)[row*32+col+1] = 7;
					BG_MAP_RAM(30)[row*32+col+2] = 6;
				}
				if(col==5  || col==23 ){
					BG_MAP_RAM(31)[row*32+col] = 2;
					BG_MAP_RAM(31)[row*32+col+1] = 7;
					BG_MAP_RAM(31)[row*32+col+2] = 6;
					if (col==5){
						BG_MAP_RAM(31)[row*32+col+3] = 2;
						BG_MAP_RAM(31)[row*32+col+4] = 6;
					}
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

	//map with tall triangle
//	for(row=0; row<24;row++){
//		for(col=0;col<32;col++){
//
//			if(row==13){	//top of the triangle
//				if(col==7 ){
//					BG_MAP_RAM(30)[row*32+col] = 4;
//				}
//			}
//			else if(row==14){ //center of triangle
//				if(col==6 ){
//					BG_MAP_RAM(30)[row*32+col] = 3;
//					BG_MAP_RAM(30)[row*32+col+1] = 7;
//					BG_MAP_RAM(30)[row*32+col+2] = 5;
//				}
//				else if(col==21){
//					BG_MAP_RAM(30)[row*32+col] = 4;
//				}
//			}
//			else if(row==15 ){ //bottom of triangle
//				if(col==6){
//					BG_MAP_RAM(30)[row*32+col] = 2;
//					BG_MAP_RAM(30)[row*32+col+1] = 7;
//					BG_MAP_RAM(30)[row*32+col+2] = 6;
//				}
//				else if(col==20){
//					BG_MAP_RAM(30)[row*32+col] = 3;
//					BG_MAP_RAM(30)[row*32+col+1] = 7;
//					BG_MAP_RAM(30)[row*32+col+2] = 5;
//					BG_MAP_RAM(30)[row*32+col+3] = 3;
//					BG_MAP_RAM(30)[row*32+col+4] = 5;
//				}
//			}
//			else if(row==16){
//				if(col>5 && col<9){
//					BG_MAP_RAM(30)[row*32+col] = 7;
//				}
//				if(col==20){
//					BG_MAP_RAM(30)[row*32+col] = 2;
//					BG_MAP_RAM(30)[row*32+col+1] = 7;
//					BG_MAP_RAM(30)[row*32+col+2] = 6;
//					BG_MAP_RAM(30)[row*32+col+3] = 2;
//					BG_MAP_RAM(30)[row*32+col+4] = 6;
//				}
//			}
//			else if(row>16){ //horizontal bar at the bottom
//				BG_MAP_RAM(30)[row*32+col] = 1;
//			}
//			else{ //assigning anything else to transparent
//				BG_MAP_RAM(30)[row*32+col] = 0;
//			}
//
//		}
//	}

	//Local  variables to track the shifting
	int bg3 = 0;
//	int bg1 = 0;
	int bg2=0;
	int c1=0,c2=0;

	//Shifting background
	y=104;
	jump=0;
	while(1)
	{
//		mmStart(MOD_EYE_OF_THE_TIGER,MM_PLAY_LOOP);

		collision();
		if(tim%20==0){
			BG_PALETTE_SUB[3]=ARGB16(1,22,5,7);
		}
		if(tim%20==5){
			BG_PALETTE_SUB[3]=ARGB16(1,20,6,7);
		}

		if(tim%20==10){
			BG_PALETTE_SUB[3]=ARGB16(1,22,8,5);
		}
		if(tim%20==15){
			BG_PALETTE_SUB[3]=ARGB16(1,22,5,1);
		}
	    //Assign shift registers (they are not readable!)
//		ShiftBG3(bg3);
		REG_BG3HOFS = bg3;
		bg3+=2;
	    if(bg3 > 255) bg3 = 0;

		REG_BG2HOFS = bg2;
		if(++bg2 > 511) bg2 = 0;
		if(bg2==255){
			c1+=1;
			c1=c1%2;
		}
		if(bg2==511){
			c2+=1;
			c2=c2%2;
		}
//		ShiftBG2(bg2);

//	    REG_BG1HOFS = bg1;
		//Update local variables that track the shifting
//	    if(--bg0 < 0) bg0 = 255;


		if(bg2==255 && c1==0){

			for(row=0; row<24;row++){
				for(col=0;col<32;col++){
					BG_MAP_RAM(30)[row*32+col] = 0;
				}
			}


			for(row=0; row<24;row++){
				for(col=0;col<32;col++){

					if(row==14){	//top of the triangle
						if(col==13 ){
							BG_MAP_RAM(30)[row*32+col] = 4;
						}
					}
					else if(row==15){ //center of triangle
						if(col==12 ){
							BG_MAP_RAM(30)[row*32+col] = 3;
							BG_MAP_RAM(30)[row*32+col+1] = 7;
							BG_MAP_RAM(30)[row*32+col+2] = 5;

						}
					}
					else if(row==16 ){ //bottom of triangle
						if(col==12 ){
							BG_MAP_RAM(30)[row*32+col] = 2;
							BG_MAP_RAM(30)[row*32+col+1] = 7;
							BG_MAP_RAM(30)[row*32+col+2] = 6;
						}
					}
					else if(row>16){ //horizontal bar at the bottom
						BG_MAP_RAM(30)[row*32+col] = 1;
					}
					else{ //assigning anything else to transparent
						BG_MAP_RAM(30)[row*32+col] = 0;
					}

				}
			}
		}

		else if(bg2==255 && c1==1){
			for(row=0; row<24;row++){
				for(col=0;col<32;col++){
					BG_MAP_RAM(30)[row*32+col] = 0;
				}
			}
			for(row=0; row<24;row++){
				for(col=0;col<32;col++){

					if(row==14){	//top of the triangle
						if(col==7 ){
							BG_MAP_RAM(30)[row*32+col] = 4;
						}
					}
					else if(row==15){ //center of traingle
						if(col==6 ){
							BG_MAP_RAM(30)[row*32+col] = 3;
							BG_MAP_RAM(30)[row*32+col+1] = 1;
							BG_MAP_RAM(30)[row*32+col+2] = 5;

						}
					}
					else if(row==16 ){ //bottom of triangle
						if(col==6 ){
							BG_MAP_RAM(30)[row*32+col] = 2;
							BG_MAP_RAM(30)[row*32+col+1] = 1;
							BG_MAP_RAM(30)[row*32+col+2] = 6;
						}
					}
					else if(row>16){ //horizontal bar at the bottom
						BG_MAP_RAM(30)[row*32+col] = 1;
					}
					else{ //assigning anything else to transparent
						BG_MAP_RAM(30)[row*32+col] = 0;
					}

				}
			}
		}

		else if(bg2==511 && c2==0){
			for(row=0; row<24;row++){
				for(col=0;col<32;col++){
					BG_MAP_RAM(31)[row*32+col] = 0;
				}
			}
			for(row=0; row<24;row++){
				for(col=0;col<32;col++){

					if(row==14){	//top of the triangle
						if(col==6 || col==24){
							BG_MAP_RAM(31)[row*32+col] = 4;
						}
					}
					else if(row==15){ //center of traingle
						if(col==5 || col==23 ){
							BG_MAP_RAM(31)[row*32+col] = 3;
							BG_MAP_RAM(31)[row*32+col+1] = 7;
							BG_MAP_RAM(31)[row*32+col+2] = 5;
							if (col==5){
								BG_MAP_RAM(31)[row*32+col+3] = 3;
								BG_MAP_RAM(31)[row*32+col+4] = 5;
							}
						}
					}
					else if(row==16 ){ //bottom of triangle
						if(col==5  || col==23 ){
							BG_MAP_RAM(31)[row*32+col] = 2;
							BG_MAP_RAM(31)[row*32+col+1] = 7;
							BG_MAP_RAM(31)[row*32+col+2] = 6;
							if (col==5){
								BG_MAP_RAM(31)[row*32+col+3] = 2;
								BG_MAP_RAM(31)[row*32+col+4] = 6;
							}
						}
					}
					else if(row>16){ //horizontal bar at the bottom
						BG_MAP_RAM(31)[row*32+col] = 1;
					}
					else{ //assigning anything else to transparent
						BG_MAP_RAM(31)[row*32+col] = 0;
					}

				}
			}
		}

		else if(bg2==511 && c2==1){
			for(row=0; row<24;row++){
				for(col=0;col<32;col++){
					BG_MAP_RAM(31)[row*32+col] = 0;
				}
			}
			for(row=0; row<24;row++){
				for(col=0;col<32;col++){

					if(row==14){	//top of the triangle
						if(col==23 ){
							BG_MAP_RAM(31)[row*32+col] = 4;
						}
					}
					else if(row==15){ //center of traingle
						if(col==22){
							BG_MAP_RAM(31)[row*32+col] = 3;
							BG_MAP_RAM(31)[row*32+col+1] = 1;
							BG_MAP_RAM(31)[row*32+col+2] = 5;

						}
					}
					else if(row==16 ){ //bottom of triangle
						if(col==22){
							BG_MAP_RAM(31)[row*32+col] = 2;
							BG_MAP_RAM(31)[row*32+col+1] = 1;
							BG_MAP_RAM(31)[row*32+col+2] = 6;
						}
					}
					else if(row>16){ //horizontal bar at the bottom
						BG_MAP_RAM(31)[row*32+col] = 1;
					}
					else{ //assigning anything else to transparent
						BG_MAP_RAM(31)[row*32+col] = 0;
					}

				}
			}
		}

		int x = 30;
		int keys;
		scanKeys();
		keys = keysDown();
		if((keys & KEY_UP)&&(!jump)){
			tim=0;
			jump=1;
		}
		if(jump)BG_PALETTE_SUB[2]=ARGB16(1,0,31,1);
		else BG_PALETTE_SUB[2]=ARGB16(1,20,3,5);
		oamSet(&oamMain,0,x, y,0,0,SpriteSize_32x32,SpriteColorFormat_256Color,gfx,-1,false,false,false, false,false);
		swiWaitForVBlank();
		oamUpdate(&oamMain);
	}

//    consoleDemoInit();
//    printf("\nTemplate nds\n");

}



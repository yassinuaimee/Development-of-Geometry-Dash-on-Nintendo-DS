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
int tim;//timer counter
bool jump=0;
int bg2=0;
int playsfx=0;


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

 unsigned char ld[]={ //ld for left down
		 0,0,0,0,255,255,255,255,
		 0,0,0,255,255,255,255,255,
		 0,0,255,255,255,255,255,255,
		 0,0,255,255,255,255,255,255,
		 0,255,255,255,255,255,255,255,
		 0,255,255,255,255,255,255,255,
		 255,255,255,255,255,255,255,255,
		 255,255,255,255,255,255,255,255
 };

 unsigned char lm[]={ //lm for left middle
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,255,
		 0,0,0,0,0,0,255,255,
		 0,0,0,0,0,0,255,255,
		 0,0,0,0,0,255,255,255,
		 0,0,0,0,0,255,255,255,
		 0,0,0,0,255,255,255,255
 };

 unsigned char um[]={ //upper middle
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
// unsigned char full_obst[]={
// 		3,3,3,3,3,3,3,3,
// 		3,3,3,3,3,3,3,3,
// 		3,3,3,3,3,3,3,3,
// 		3,3,3,3,3,3,3,3,
// 		3,3,3,3,3,3,3,3,
// 		3,3,3,3,3,3,3,3,
// 		3,3,3,3,3,3,3,3,
// 		3,3,3,3,3,3,3,3
// };

 unsigned char rm[]={ //right middle

		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 255,0,0,0,0,0,0,0,
		 255,255,0,0,0,0,0,0,
		 255,255,0,0,0,0,0,0,
		 255,255,255,0,0,0,0,0,
		 255,255,255,0,0,0,0,0,
		 255,255,255,255,0,0,0,0,
 };

 unsigned char rd[]={ //right down
 		 255,255,255,255,0,0,0,0,
 		 255,255,255,255,255,0,0,0,
 		 255,255,255,255,255,255,0,0,
 		 255,255,255,255,255,255,0,0,
 		 255,255,255,255,255,255,255,0,
 		 255,255,255,255,255,255,255,0,
 		 255,255,255,255,255,255,255,255,
 		 255,255,255,255,255,255,255,255,
  };

 unsigned char lm2[]={  //for the small trianagle
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,255,
		 0,0,0,0,0,0,255,255,
		 0,0,0,0,0,0,255,255,
		 0,0,0,0,0,255,255,255,
		 0,0,0,0,0,255,255,255,
		 0,0,0,0,255,255,255,255
 };

 unsigned char rm2[]={ //same

		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 255,0,0,0,0,0,0,0,
		 255,255,0,0,0,0,0,0,
		 255,255,0,0,0,0,0,0,
		 255,255,255,0,0,0,0,0,
		 255,255,255,0,0,0,0,0,
		 255,255,255,255,0,0,0,0,
 };

 void ISR_TIMER0()
  {
  	tim++;
  	switch (tim){// on utilise l'ISR principalement pour faire le saut, le deplacement vertical du sprite
  		 case 1:
  			 y=90;
  			 break;
  		 case 2:// le decalage pas lineaire de y se fait pour donner une sensation de gravité
  			 y=83;
  			 break;
  		 case 3:
  			 y=76;
  		 	 break;
  		 case 4:
  			 y=74;
  			 break;
  		 case 5:
  			 y=72;
  			 break;
  		 case 6:
  			 y=70;
  			 break;
  		 case 7:
  		 	y=68;
  		 	break;
  		 case 8:
  			y=70;
  		 	break;
  		 case 9:
  			y=72;
  		 	break;
  		 case 10:
  			 y=74;
  			 break;
  		 case 11:
  			 y=76;
  			 break;
  		case 12:
  		  	 y=83;
  		  	 break;
  		case 13:
  		  	 y=90;
  		  	break;
  		case 14:
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


 int collision(){//on fait pas vraiment une detection de collision mais on cheque si on a un obstacle dans la position horizontal du sprite et on impose une hauteur minimale
	 	int shift=(int)bg2/8;//le deplacement du background ne change pas la memoire, en fonction du deplacement faut chequer un endroit memoire ou un autre
	 	int detc;//pour chequer plusieurs endroits dans l'horizontale
	 	for(detc=6;detc<8;detc++){
	 		if((((bg2<(256-detc*8))&&(BG_MAP_RAM(30)[480+shift+detc]== 7 ||BG_MAP_RAM(30)[480+shift+detc]== 5))||
	 				((((bg2>(512-detc*8))&&(bg2<512)))&&
	 						(BG_MAP_RAM(30)[480+shift+detc-32]== 7 || BG_MAP_RAM(30)[480+shift+detc-32]== 5))||
	 						(((bg2>(256-detc*8)&&(bg2<(512-detc*8)))&&
	 								(BG_MAP_RAM(31)[480+shift+detc-32]== 7  || BG_MAP_RAM(31)[480+shift+detc-32]== 5))))
	 								&&(y>76)) {
	 			playsfx+=1;
	 			return 1;
			}
	 		if((((bg2<(256-detc*8))&&(BG_MAP_RAM(30)[480+shift+detc]== 8 || BG_MAP_RAM(30)[480+shift+detc]== 9))||((((bg2>(512-detc*8))&&(bg2<512)))&&(BG_MAP_RAM(30)[480+shift+detc-32]== 8 || BG_MAP_RAM(30)[480+shift+detc-32]== 9))||(((bg2>(256-detc*8)&&(bg2<(512-detc*8)))&&(BG_MAP_RAM(31)[480+shift+detc-32]== 8 || BG_MAP_RAM(31)[480+shift+detc-32]==9))))&&(y>80)){
	 			playsfx+=1;
	 			return 1;
			}
//	 		if((((bg2<(256-detc*8))&&(BG_MAP_RAM(30)[480+shift+detc]== 8))||((((bg2>(512-detc*8))&&(bg2<512)))&&(BG_MAP_RAM(30)[480+shift+detc-32]== 8))||(((bg2>(256-detc*8)&&(bg2<(512-detc*8)))&&(BG_MAP_RAM(31)[480+shift+detc-32]== 8))))&&(y>80)){
//	 			playsfx+=1;
//	 			return 1;
//			}

		}

	 	return 0;
	 }

 void configbackgrundloser(){

	 BGCTRL_SUB[0] =BG_32x32|BG_COLOR_256|BG_MAP_BASE(1) | BG_TILE_BASE(1);
	int row,col;
	for(row=0;row<24;row++)
		{
			for(col=0;col<32;col++){
				BG_MAP_RAM_SUB(1)[row*32+col]=0;//on remplit le background

				}}

			for(row=10;row<13;row++){
				for(col=9;col<23;col++){//on ecrive le message lost
					if((row=10)&&((col==9)||(col==12)||(col==13)||(col==14)||(col==17)||(col==18)||(col==20)||(col==21)||(col==22)))BG_MAP_RAM_SUB(1)[row*32+col]=2;
					if((row=11)&&((col==9)||(col==12)||(col==14)||(col==17)||(col==21)))BG_MAP_RAM_SUB(1)[row*32+col]=2;
					if((row=12)&&((col==9)||(col==10)||(col==12)||(col==17)||(col==13)||(col==14)||(col==16)||(col==21)))BG_MAP_RAM_SUB(1)[row*32+col]=2;

						}
					}

 }

void configSub(){
	VRAM_C_CR=VRAM_ENABLE|VRAM_C_SUB_BG;
	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG1_ACTIVE;//
	BGCTRL_SUB[1] =BG_32x32|BG_COLOR_256|BG_MAP_BASE(0) | BG_TILE_BASE(1);

	dmaCopy(full, &BG_TILE_RAM_SUB(1)[0], 64);
	dmaCopy(otherfull,&BG_TILE_RAM_SUB(1)[32], 64);
	dmaCopy(otherfullmore,&BG_TILE_RAM_SUB(1)[64], 64);
	BG_PALETTE_SUB[254]=ARGB16(1,20,3,5);
	BG_PALETTE_SUB[3]=ARGB16(1,22,5,7);
	BG_PALETTE_SUB[2]=ARGB16(1,15,31,0);
	int row,col, prod;
		for(row=0;row<24;row++)
		{
			for(col=0;col<32;col++){
				prod=(row-12)*(row-12)+(col-16)*(col-16);
				if((prod<5)||((prod<32)&&(prod>20))||((prod<70)&&(prod>55))||((prod<120)&&(prod>100))||((prod<180)&&(prod>160))||((prod<250)&&(prod>230))||((prod<350)&&(prod>320))){
						BG_MAP_RAM_SUB(0)[row*32+col]=1;// on cree un patter agreable, des "cercles" qui vont changer de couleur
				}
				else{
						BG_MAP_RAM_SUB(0)[row*32+col]=0;//on rempli le rest du background

				}
			}}

		for(row=10;row<13;row++){
			for(col=9;col<22;col++){//on ecrive le message jump
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
	//BG_PALETTE[3] = ARGB16(1,0,21,0);
//	//copying the tiles in tile ram
	dmaCopy(empty,&BG_TILE_RAM(5)[0],64);//0
	dmaCopy(full,&BG_TILE_RAM(5)[32],64);//1
	dmaCopy(ld,&BG_TILE_RAM(5)[64],64);//2
	dmaCopy(lm,&BG_TILE_RAM(5)[96],64);//3
	dmaCopy(um,&BG_TILE_RAM(5)[128],64);//4
	dmaCopy(rm,&BG_TILE_RAM(5)[160],64);//5
	dmaCopy(rd,&BG_TILE_RAM(5)[192],64);//6
	dmaCopy(full_obst,&BG_TILE_RAM(5)[224],64);//7
	dmaCopy(lm2,&BG_TILE_RAM(5)[256],64);//8
	dmaCopy(rm2,&BG_TILE_RAM(5)[288],64);//9

}

void InitMap(){

	int row,col;
	//map1
	for(row=0; row<24;row++){
		for(col=0;col<32;col++){
			BG_MAP_RAM(30)[row*32+col] = 0;
			BG_MAP_RAM(31)[row*32+col] = 0;
		}
	}
	for(row=0; row<24;row++){
		for(col=0;col<32;col++){

			if(row==14){	//top of the triangle
				if(col==25){
					BG_MAP_RAM(30)[row*32+col] = 4;
				}
				if(col==6 || col==16 || col== 29){
					BG_MAP_RAM(31)[row*32+col] = 4;
				}
			}
			else if(row==15){ //center of triangle
				if(col==24){
					BG_MAP_RAM(30)[row*32+col] = 3;
					BG_MAP_RAM(30)[row*32+col+1] = 7;
					BG_MAP_RAM(30)[row*32+col+2] = 5;

				}
				if(col==5 || col==15 || col== 28){
					BG_MAP_RAM(31)[row*32+col] = 3;
					BG_MAP_RAM(31)[row*32+col+1] = 7;
					BG_MAP_RAM(31)[row*32+col+2] = 5;
					if (col==15){
						BG_MAP_RAM(31)[row*32+col+3] = 8;
						BG_MAP_RAM(31)[row*32+col+4] = 9;
					}
				}
			}
			else if(row==16 ){ //bottom of triangle
				if(col==24){
					BG_MAP_RAM(30)[row*32+col] = 2;
					BG_MAP_RAM(30)[row*32+col+1] = 7;
					BG_MAP_RAM(30)[row*32+col+2] = 6;
				}
				if(col==5 || col==15 || col== 28 ){
					BG_MAP_RAM(31)[row*32+col] = 2;
					BG_MAP_RAM(31)[row*32+col+1] = 7;
					BG_MAP_RAM(31)[row*32+col+2] = 6;
					if (col==15){
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

}

void InitMap1(){

	int row,col;
	//map1
	for(row=0; row<24;row++){ //empty the ram
		for(col=0;col<32;col++){
			BG_MAP_RAM(30)[row*32+col] = 0;
			BG_MAP_RAM(31)[row*32+col] = 0;
		}
	}
	for(row=0; row<24;row++){
		for(col=0;col<32;col++){

			if(row==15){ //top of the triangle
				if(col==22){
					BG_MAP_RAM(30)[row*32+col+3] = 8;
					BG_MAP_RAM(30)[row*32+col+4] = 9;

				}
				if(col==4 || col==14 || col== 25){
					BG_MAP_RAM(31)[row*32+col+3] = 8;
					BG_MAP_RAM(31)[row*32+col+4] = 9;
				}
			}
			else if(row==16 ){ //bottom of triangle
				if(col==22){
					BG_MAP_RAM(30)[row*32+col+3] = 2;
					BG_MAP_RAM(30)[row*32+col+4] = 6;
				}
				if(col==4 || col==14 || col== 25 ){
					BG_MAP_RAM(31)[row*32+col+3] = 2;
					BG_MAP_RAM(31)[row*32+col+4] = 6;
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

}

void ChangeMap1(int c1,int c2){
	int row,col;

	if(bg2==255 && c1==0){

		for(row=0; row<24;row++){
			for(col=0;col<32;col++){
				BG_MAP_RAM(30)[row*32+col] = 0;
			}
		}
		for(row=0; row<24;row++){
			for(col=0;col<32;col++){

				if(row==14){	//top of the triangle
					if(col==10||col==20){
						BG_MAP_RAM(30)[row*32+col] = 4;
					}

				}
				else if(row==15){ //center of triangle
					if(col==9||col==19){
						BG_MAP_RAM(30)[row*32+col] = 3;
						BG_MAP_RAM(30)[row*32+col+1] = 7;
						BG_MAP_RAM(30)[row*32+col+2] = 5;
						if (col==19){ //for double triangle
							BG_MAP_RAM(30)[row*32+col+3] = 8;
							BG_MAP_RAM(30)[row*32+col+4] = 9;
						}
					}
				}
				else if(row==16 ){ //bottom of triangle
					if(col==9||col==19){
						BG_MAP_RAM(30)[row*32+col] = 2;
						BG_MAP_RAM(30)[row*32+col+1] = 7;
						BG_MAP_RAM(30)[row*32+col+2] = 6;
						if (col==19){ //for double triangle
							BG_MAP_RAM(30)[row*32+col+3] = 2;
							BG_MAP_RAM(30)[row*32+col+4] = 6;
						}
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
					if(col==10||col==20){
						BG_MAP_RAM(30)[row*32+col] = 4;
					}

				}
				else if(row==15){ //center of triangle
					if(col==9||col==19){
						BG_MAP_RAM(30)[row*32+col] = 3;
						BG_MAP_RAM(30)[row*32+col+1] = 7;
						BG_MAP_RAM(30)[row*32+col+2] = 5;
						if (col==19){ //for double triangle
							BG_MAP_RAM(30)[row*32+col+3] = 8;
							BG_MAP_RAM(30)[row*32+col+4] = 9;
						}
					}
				}
				else if(row==16 ){ //bottom of triangle
					if(col==9||col==19){
						BG_MAP_RAM(30)[row*32+col] = 2;
						BG_MAP_RAM(30)[row*32+col+1] = 7;
						BG_MAP_RAM(30)[row*32+col+2] = 6;
						if (col==19){ //for double triangle
							BG_MAP_RAM(30)[row*32+col+3] = 2;
							BG_MAP_RAM(30)[row*32+col+4] = 6;
						}
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
					if(col==10 || col==25){
						BG_MAP_RAM(31)[row*32+col] = 4;
					}
				}
				else if(row==15){ //center of triangle
					if(col==9 || col==24 ){
						BG_MAP_RAM(31)[row*32+col] = 3;
						BG_MAP_RAM(31)[row*32+col+1] = 7;
						BG_MAP_RAM(31)[row*32+col+2] = 5;
						BG_MAP_RAM(31)[row*32+col+3] = 8;
						BG_MAP_RAM(31)[row*32+col+4] = 9;
					}
				}
				else if(row==16 ){ //bottom of triangle
					if(col==9  || col==24 ){
						BG_MAP_RAM(31)[row*32+col] = 2;
						BG_MAP_RAM(31)[row*32+col+1] = 7;
						BG_MAP_RAM(31)[row*32+col+2] = 6;
						BG_MAP_RAM(31)[row*32+col+3] = 2;
						BG_MAP_RAM(31)[row*32+col+4] = 6;

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
					if(col==7 || col==17 || col==28){
						BG_MAP_RAM(31)[row*32+col] = 4;
					}
				}
				else if(row==15){ //center of triangle
					if(col==6 || col==16 || col==27){
						BG_MAP_RAM(31)[row*32+col] = 3;
						BG_MAP_RAM(31)[row*32+col+1] = 7;
						BG_MAP_RAM(31)[row*32+col+2] = 5;

					}
				}
				else if(row==16 ){ //bottom of triangle
					if(col==6 || col==16 || col==27){
						BG_MAP_RAM(31)[row*32+col] = 2;
						BG_MAP_RAM(31)[row*32+col+1] = 7;
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

}



void blinkeffect(){// en fonction de la variable incremente dans l'ISR on chosi un couleur, ça pourrait s'inclure dans l'isr
	if(tim%20==0){//vu que l'isr incremente tim dix fois par segonde, on changera de couleur chaque 0.5 segondes, le fait que le saut reinitialise a 0 le compteur fait que la majorite du temps on regarde le premier couleur
				BG_PALETTE_SUB[3]=ARGB16(1,22,5,7);//les quatre sont des couleurs assez similaires pour que ça soit plus agreable
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
}


////////////////////////////////////////////////////////////////////////////////

int main(void) {

//	//Init the sound library
	mmInitDefaultMem((mm_addr)soundbank_bin);
//	//Load module
	mmLoad(MOD_MUSIC);
	mmStart(MOD_MUSIC,MM_PLAY_LOOP);
	//load sound effects
	mmLoadEffect(SFX_RESULT);
	mmLoadEffect(SFX_LASER);


	configSub();
	ActivateMain();
	ConfigureBG3();
	ConfigureBG2();
	configureSprites();
	configbackgrundloser();

	configTimer0();

	InitMap1(); 	//creating first map with obstacles


	//Local  variables to track the shifting
	int bg3=0;
	//local variables to change maps
	int c1=0,c2=0;
	//local variable to end and restart the game
	int lost=0;

	y=104;//position verticale du sprite par defaut, juste au dessus de la ligne orange dans le background
	jump=0;





	while(1)
	{
		if(collision()){//on fait un appel a la fonction que detecte si notre sprite touche un obstacle

			//activate the losing background with losing message
			REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG0_ACTIVE;
			lost=1;// la fonction collision se met a un que pendant un moment court, ce variable nous permet de tenir l'etat lost
			if(playsfx<4){ //if we lose we play the sound effect
				mmEffect(SFX_RESULT);
			}
			BG_PALETTE_SUB[254]=ARGB16(1,0,0,0);//pour le sub on a reutilise des tiles dans differents backgrounds, normalement c rouge avec la possibilite de vert
			BG_PALETTE_SUB[2]=ARGB16(1,31,0,0);// quand on perd on veut fond noire, dans la ligne en haut et message en rouge dans cette ligne
			mmStop(); //stop module music
		}
		blinkeffect();

		//Assign shift registers (they are not readable!)
		REG_BG3HOFS = bg3;
		REG_BG2HOFS = bg2;

		//Shifting backgrounds
		if(lost==0){
			bg3+=2;
			if(bg3 > 255) bg3 = 0;
			if(++bg2 > 511) bg2 = 0;
		}

		//condition to change maps when screen has ended
		if(bg2==255){
			c1+=1;
			c1=c1%2;
		}
		if(bg2==511){
			c2+=1;
			c2=c2%2;
		}

		ChangeMap1(c1,c2);

		int x = 32;//position fixe horizontale du sprite

		//identifying the keys and mapping different actions
		int keys;
		scanKeys();
		keys = keysDown();

		//if we press up or the touchscreen while not already jumping then
		//we jump
		if(((keys & KEY_UP)||(keys & KEY_TOUCH))&&(!jump)&& lost==0){
			int i;
			for(i=0;i<7;i++){
				mmEffect(SFX_LASER);
			}
			tim=0;//pour rentrer dans le switch de l'ISR
			jump=1;//pour ne pas permettre re rentrer dans l'interruption si on est deja dedans
		}//we restart the game when we have lost and pressed on start button
		else if((keys & KEY_START) && lost==1){
			//resetting all variables to initial conditions
			lost=0;
			bg2=0;
			bg3=0;
			playsfx=0;
			//reactivating background 1 for the sub
			REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG1_ACTIVE;
			//reinitializing the map
			InitMap();
			//starting thhe music again
			mmStart(MOD_MUSIC,MM_PLAY_LOOP);
			BG_PALETTE_SUB[254]=ARGB16(1,20,3,5);//on remet les couleurs de jeu dans la palette du sub
			BG_PALETTE_SUB[2]=ARGB16(1,15,31,0);
		}



		if(jump)BG_PALETTE_SUB[2]=ARGB16(1,0,31,1);//pour que le message jump soit visible
		else BG_PALETTE_SUB[2]=ARGB16(1,20,3,5);// pour que le message jump soit pas visible, meme couleur que le background
		oamSet(&oamMain,0,x, y,0,0,SpriteSize_32x32,SpriteColorFormat_256Color,gfx,-1,false,false,false, false,false);
		swiWaitForVBlank();
		oamUpdate(&oamMain);
	}
}






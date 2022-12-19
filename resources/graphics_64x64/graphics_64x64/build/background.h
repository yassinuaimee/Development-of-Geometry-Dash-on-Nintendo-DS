
//{{BLOCK(background)

//======================================================================
//
//	background, 512x512@8, 
//	+ palette 256 entries, not compressed
//	+ 261 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 64x64 
//	Total size: 512 + 16704 + 8192 = 25408
//
//	Time-stamp: 2022-12-19, 12:03:37
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 16704
extern const unsigned int backgroundTiles[4176];

#define backgroundMapLen 8192
extern const unsigned short backgroundMap[4096];

#define backgroundPalLen 512
extern const unsigned short backgroundPal[256];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)

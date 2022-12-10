
//{{BLOCK(background)

//======================================================================
//
//	background, 256x192@8, 
//	+ palette 253 entries, not compressed
//	+ 113 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 506 + 7232 + 1536 = 9274
//
//	Time-stamp: 2022-12-05, 19:44:47
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 7232
extern const unsigned int backgroundTiles[1808];

#define backgroundMapLen 1536
extern const unsigned short backgroundMap[768];

#define backgroundPalLen 506
extern const unsigned short backgroundPal[254];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)


//{{BLOCK(clouds)

//======================================================================
//
//	clouds, 256x576@8, 
//	Transparent color : 00,00,00
//	+ palette 256 entries, not compressed
//	+ 871 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x72 
//	Total size: 512 + 55744 + 4608 = 60864
//
//	Time-stamp: 2022-12-10, 15:27:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CLOUDS_H
#define GRIT_CLOUDS_H

#define cloudsTilesLen 55744
extern const unsigned int cloudsTiles[13936];

#define cloudsMapLen 4608
extern const unsigned short cloudsMap[2304];

#define cloudsPalLen 512
extern const unsigned short cloudsPal[256];

#endif // GRIT_CLOUDS_H

//}}BLOCK(clouds)

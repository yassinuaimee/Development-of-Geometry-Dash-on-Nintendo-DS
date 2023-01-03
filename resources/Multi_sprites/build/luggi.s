
@{{BLOCK(luggi)

@=======================================================================
@
@	luggi, 32x32@4, 
@	+ palette 256 entries, not compressed
@	+ 16 tiles not compressed
@	Total size: 512 + 512 = 1024
@
@	Time-stamp: 2020-12-11, 14:42:19
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global luggiTiles		@ 512 unsigned chars
luggiTiles:
	.word 0xAAAAAAAA,0xAAAAAAAA,0xEAAAAAAA,0x99AAAAAA,0xB79AAAAA,0x4939AAAA,0x44959AAA,0x44F690AA
	.word 0x70B990AA,0x46C1799A,0x4444B979,0x1644441B,0xC6C44446,0xB8E64444,0x74919444,0x7AE9B644
	.word 0xAAA99D3B,0xA9971C64,0x96CC4444,0x29444461,0xB4444142,0x44446C99,0x444919A9,0x44679AA9
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA0,0xAAAAAA99,0xAAAAA9A4,0xAAAA95C6,0xAAAEAC64,0xAAA94644
	.word 0x4446F9AA,0x4444929A,0x4444469A,0x444441D9,0x44444649,0x64444499,0xDC444499,0x97144499
	.word 0x79997644,0xA999AB44,0x11992644,0x9997A444,0x3C990414,0xC197B98C,0x4446CC89,0xCB64441E
	.word 0x44B79AE9,0x44BA9A39,0x44689E2C,0x444A79A1,0x41B799C3,0xC89B791C,0x9BCC6444,0xE14446BC
	.word 0xAA98B444,0xA9194444,0xA9644444,0x9DC44444,0x95644444,0x99444446,0x994444CF,0x99444979

	.word 0xC9F14689,0xCA98C9CE,0xA699B39A,0x99AA99AA,0xAAAAAAAA,0x9AAAAAAA,0xA9AAAAAA,0x19AAAAAA
	.word 0x7A861646,0x9999CF9C,0xAAAA99AD,0xAAAAAAE9,0xAAAAAAAA,0xAAAAAAA9,0xAAAAAA9E,0xAAAA9910
	.word 0x6461B8A7,0xC92C9999,0x2599AAAA,0x9EAAAAAA,0xAAAAAAAA,0x9AAAAAAA,0xE9AAAAAA,0x0199AAAA
	.word 0x9364179C,0xEA9C89AC,0xA91C996A,0xAA990A99,0xAAAAAAAA,0xAAAAAAA9,0xAAAAAA9A,0xAAAAAA91
	.word 0x239AAAAA,0x919AAAAA,0x919AAAAA,0x239AAAAA,0x19AAAAAA,0xB9AAAAAA,0x9AAAAAAA,0xAAAAAAAA
	.word 0x99993A2D,0x35DF2844,0x66FDD444,0x44444444,0xD444444D,0x6D44D4D0,0x0F26621B,0x99955E99
	.word 0xD2A39999,0x44820D53,0x444DDF66,0x44444444,0xD444444D,0x0D4444D6,0xB12660F4,0x99E55999
	.word 0xAAAAA982,0xAAAAA919,0xAAAAA919,0xAAAAA932,0xAAAAAA91,0xAAAAAA9B,0xAAAAAAA9,0xAAAAAAAA

	.section .rodata
	.align	2
	.global luggiPal		@ 512 unsigned chars
luggiPal:
	.hword 0x0000,0x4A53,0x0240,0x6F7B,0x2EC6,0x5AD7,0x1A81,0x430D
	.hword 0x0443,0x7FFF,0x4B2F,0x5B74,0x7BDD,0x3DF0,0x26A4,0x10A6
	.hword 0x5351,0x1660,0x6376,0x6319,0x1E82,0x56B5,0x0002,0x73BC
	.hword 0x36E9,0x1260,0x1CE8,0x1A80,0x6798,0x0844,0x7FDF,0x0422
	.hword 0x673A,0x6FBA,0x5752,0x3AEA,0x0A40,0x26A5,0x4B30,0x472E
	.hword 0x5F76,0x77BD,0x7BDE,0x1EA2,0x1680,0x32C7,0x4211,0x1E81
	.hword 0x7BDF,0x6397,0x0001,0x6FBB,0x0864,0x77DD,0x6B99,0x2AC6
	.hword 0x5774,0x0022,0x4E73,0x5EF7,0x0E40,0x5753,0x77DC,0x470D

	.hword 0x3B0B,0x4F51,0x32E8,0x6797,0x432D,0x56B6,0x5B75,0x5352
	.hword 0x6339,0x4F30,0x0E60,0x2AC5,0x73BB,0x0843,0x6B5A,0x32C8
	.hword 0x14A6,0x0423,0x6396,0x6739,0x675A,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(luggi)

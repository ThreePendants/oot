.include "macro.inc"

 # assembler directives
 .set noat      # allow manual use of $at
 .set noreorder # don't insert nops after branches
 .set gp=64     # allow use of 64-bit general purpose registers

.section .data

.balign 16

glabel D_80A480D0
 .word gDustTex8, gDustTex7, gDustTex6, gDustTex5, gDustTex4, gDustTex3, gDustTex2, gDustTex1
glabel D_80A480F0
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A480FC
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A48108
 .word 0x00000000, 0x3E99999A, 0x00000000
glabel D_80A48114
 .word 0x0A000939, 0x20010000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000000, 0x00000100, 0x00280041, 0x00000000, 0x00000000
glabel D_80A48140
 .word 0x00000000, 0x00000000, 0xFF000000
glabel En_Go2_InitVars
 .word 0x01AE0400, 0x00000039, 0x00C90000, 0x000005A0
.word EnGo2_Init
.word EnGo2_Destroy
.word EnGo2_Update
.word EnGo2_Draw
glabel D_80A4816C
 .byte 0x00, 0x00
glabel D_80A4816E
 .byte 0x00, 0x00
glabel D_80A48170
 .word 0x00000044
glabel D_80A48174
 .word 0x00940000, 0x00000000, 0x00180034, 0x00000140, 0x017C0190, 0x00780000, 0x00000000, 0x001E0044, 0x00000000, 0x0000002E, 0x005A0000, 0x00000000, 0x001E0044, 0x00000000, 0x0000001E, 0x00440000, 0x00000000, 0x001E0044, 0x00000000, 0x0000001E, 0x00440000, 0x00000000, 0x001E0044, 0x00000000, 0x0000001E, 0x00440000, 0x00000000, 0x001E0044, 0x00000000, 0x0000001E, 0x00440000, 0x00000000, 0x001E0044
glabel D_80A481F8
 .word 0x41F00000, 0x3CD4FDF4, 0x06000000, 0x42700000, 0x41C00000, 0x3C03126F, 0x06000000, 0x41F00000, 0x41E00000, 0x3E23D70A, 0x05000000, 0x43BE0000, 0x41E00000, 0x3C23D70A, 0x07000000, 0x42200000, 0x41F00000, 0x3C75C28F, 0x06000000, 0x41F00000, 0x41E00000, 0x3C23D70A, 0x06000000, 0x41F00000, 0x41E00000, 0x3C23D70A, 0x06000000, 0x41F00000, 0x41E00000, 0x3C23D70A, 0x06000000, 0x41F00000, 0x41E00000, 0x3C23D70A, 0x06000000, 0x41F00000, 0x41E00000, 0x3C23D70A, 0x06000000, 0x41F00000, 0x41E00000, 0x3C23D70A, 0x06000000, 0x41F00000, 0x41E00000, 0x3C23D70A, 0x06000000, 0x41F00000, 0x41E00000, 0x3C23D70A, 0x06000000, 0x41F00000, 0x41E00000, 0x3C23D70A, 0x06000000, 0x41F00000
glabel D_80A482D8
 .word 0x42A00000, 0x42A00000, 0xC1200000, 0xC1200000, 0x44480000, 0x44480000, 0x00000000, 0x00000000, 0x41A00000, 0x42200000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000, 0x41A00000
glabel D_80A48348
 .word 0x06004930, 0x00000000, 0x00000000, 0xBF800000, 0x00000000, 0x00000000, 0x06004930, 0x00000000, 0x00000000, 0xBF800000, 0x00000000, 0xC1000000, 0x060029A8, 0x3F800000, 0x00000000, 0xBF800000, 0x00000000, 0xC1000000, 0x06010590, 0x3F800000, 0x00000000, 0xBF800000, 0x00000000, 0xC1000000, 0x06003768, 0x3F800000, 0x00000000, 0xBF800000, 0x00000000, 0xC1000000, 0x060038E4, 0x3F800000, 0x00000000, 0xBF800000, 0x02000000, 0xC1000000, 0x06002D80, 0x3F800000, 0x00000000, 0xBF800000, 0x02000000, 0xC1000000, 0x0600161C, 0x3F800000, 0x00000000, 0xBF800000, 0x00000000, 0xC1000000, 0x06001A00, 0x3F800000, 0x00000000, 0xBF800000, 0x00000000, 0xC1000000, 0x060021D0, 0x3F800000, 0x00000000, 0xBF800000, 0x00000000, 0xC1000000, 0x06004930, 0x00000000, 0x00000000, 0xBF800000, 0x01000000, 0xC1000000, 0x06000750, 0x3F800000, 0x00000000, 0xBF800000, 0x00000000, 0xC1000000, 0x06000D5C, 0x3F800000, 0x00000000, 0xBF800000, 0x00000000, 0xC1000000
glabel D_80A48480
 .word 0x0C000000, 0x3E4CCCCD, 0x3E4CCCCD, 0x00000001, 0x41900000, 0x00000000, 0x0C000000, 0x3DCCCCCD, 0x3E4CCCCD, 0x0000000C, 0x41D00000, 0x00000000, 0x0C000000, 0x3DCCCCCD, 0x3E99999A, 0x00000004, 0x41200000, 0x00000000, 0x0C000000, 0x3E4CCCCD, 0x3E4CCCCD, 0x00000001, 0x41900000, 0x00000000, 0x0C000000, 0x3F000000, 0x3ECCCCCD, 0x00000003, 0x42280000, 0x00000000, 0x0C000000, 0x3F000000, 0x3ECCCCCD, 0x00000003, 0x42280000, 0x00000000, 0x0C000000, 0x3F000000, 0x3ECCCCCD, 0x00000003, 0x42280000, 0x00000000, 0x0C000000, 0x3F000000, 0x3ECCCCCD, 0x00000003, 0x42280000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
glabel D_80A4854C
 .word 0x00000000, 0x00000000
glabel D_80A48554
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A48560
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A4856C
 .word 0x44160000, 0x00000000, 0x00000000
glabel D_80A48578
 .word 0x0600DA80, 0x0600CE80, 0x0600D280, 0x0600D680
glabel D_80A48588
 .word 0x0600DE80, 0x0600E680


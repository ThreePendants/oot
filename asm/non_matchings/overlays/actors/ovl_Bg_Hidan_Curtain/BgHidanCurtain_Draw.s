glabel BgHidanCurtain_Draw
/* 0084C 808859EC 27BDFF90 */  addiu   $sp, $sp, 0xFF90           ## $sp = FFFFFF90
/* 00850 808859F0 AFB10038 */  sw      $s1, 0x0038($sp)           
/* 00854 808859F4 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 00858 808859F8 AFBF003C */  sw      $ra, 0x003C($sp)           
/* 0085C 808859FC AFB00034 */  sw      $s0, 0x0034($sp)           
/* 00860 80885A00 AFA40070 */  sw      $a0, 0x0070($sp)           
/* 00864 80885A04 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 00868 80885A08 3C068088 */  lui     $a2, %hi(D_80885CCC)       ## $a2 = 80880000
/* 0086C 80885A0C 24C65CCC */  addiu   $a2, $a2, %lo(D_80885CCC)  ## $a2 = 80885CCC
/* 00870 80885A10 27A40058 */  addiu   $a0, $sp, 0x0058           ## $a0 = FFFFFFE8
/* 00874 80885A14 240702AD */  addiu   $a3, $zero, 0x02AD         ## $a3 = 000002AD
/* 00878 80885A18 0C031AB1 */  jal     func_800C6AC4              
/* 0087C 80885A1C 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 00880 80885A20 0C024F61 */  jal     func_80093D84              
/* 00884 80885A24 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 00888 80885A28 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 0088C 80885A2C 8FA90070 */  lw      $t1, 0x0070($sp)           
/* 00890 80885A30 3C0FFA00 */  lui     $t7, 0xFA00                ## $t7 = FA000000
/* 00894 80885A34 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 00898 80885A38 AE0E02D0 */  sw      $t6, 0x02D0($s0)           ## 000002D0
/* 0089C 80885A3C 35EF8080 */  ori     $t7, $t7, 0x8080           ## $t7 = FA008080
/* 008A0 80885A40 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 008A4 80885A44 91390153 */  lbu     $t9, 0x0153($t1)           ## 00000153
/* 008A8 80885A48 3C01FFDC */  lui     $at, 0xFFDC                ## $at = FFDC0000
/* 008AC 80885A4C 3C0CFB00 */  lui     $t4, 0xFB00                ## $t4 = FB000000
/* 008B0 80885A50 03215025 */  or      $t2, $t9, $at              ## $t2 = FFDC0000
/* 008B4 80885A54 AC4A0004 */  sw      $t2, 0x0004($v0)           ## 00000004
/* 008B8 80885A58 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 008BC 80885A5C 3C0DFF00 */  lui     $t5, 0xFF00                ## $t5 = FF000000
/* 008C0 80885A60 3C0FDB06 */  lui     $t7, 0xDB06                ## $t7 = DB060000
/* 008C4 80885A64 244B0008 */  addiu   $t3, $v0, 0x0008           ## $t3 = 00000008
/* 008C8 80885A68 AE0B02D0 */  sw      $t3, 0x02D0($s0)           ## 000002D0
/* 008CC 80885A6C AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000000
/* 008D0 80885A70 AC4D0004 */  sw      $t5, 0x0004($v0)           ## 00000004
/* 008D4 80885A74 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 008D8 80885A78 35EF0020 */  ori     $t7, $t7, 0x0020           ## $t7 = DB060020
/* 008DC 80885A7C 240D0020 */  addiu   $t5, $zero, 0x0020         ## $t5 = 00000020
/* 008E0 80885A80 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 008E4 80885A84 AE0E02D0 */  sw      $t6, 0x02D0($s0)           ## 000002D0
/* 008E8 80885A88 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 008EC 80885A8C 85230156 */  lh      $v1, 0x0156($t1)           ## 00000156
/* 008F0 80885A90 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 008F4 80885A94 240E0040 */  addiu   $t6, $zero, 0x0040         ## $t6 = 00000040
/* 008F8 80885A98 00030823 */  subu    $at, $zero, $v1            
/* 008FC 80885A9C 00015900 */  sll     $t3, $at,  4               
/* 00900 80885AA0 01615823 */  subu    $t3, $t3, $at              
/* 00904 80885AA4 316C00FF */  andi    $t4, $t3, 0x00FF           ## $t4 = 00000008
/* 00908 80885AA8 240A0001 */  addiu   $t2, $zero, 0x0001         ## $t2 = 00000001
/* 0090C 80885AAC 24190040 */  addiu   $t9, $zero, 0x0040         ## $t9 = 00000040
/* 00910 80885AB0 24180020 */  addiu   $t8, $zero, 0x0020         ## $t8 = 00000020
/* 00914 80885AB4 AFB80010 */  sw      $t8, 0x0010($sp)           
/* 00918 80885AB8 AFB90014 */  sw      $t9, 0x0014($sp)           
/* 0091C 80885ABC AFAA0018 */  sw      $t2, 0x0018($sp)           
/* 00920 80885AC0 AFAC0020 */  sw      $t4, 0x0020($sp)           
/* 00924 80885AC4 AFAE0028 */  sw      $t6, 0x0028($sp)           
/* 00928 80885AC8 AFAD0024 */  sw      $t5, 0x0024($sp)           
/* 0092C 80885ACC AFA0001C */  sw      $zero, 0x001C($sp)         
/* 00930 80885AD0 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 00934 80885AD4 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 00938 80885AD8 AFA2004C */  sw      $v0, 0x004C($sp)           
/* 0093C 80885ADC 0C0253D0 */  jal     Gfx_TwoTexScroll              
/* 00940 80885AE0 3066007F */  andi    $a2, $v1, 0x007F           ## $a2 = 00000000
/* 00944 80885AE4 8FA8004C */  lw      $t0, 0x004C($sp)           
/* 00948 80885AE8 3C18DA38 */  lui     $t8, 0xDA38                ## $t8 = DA380000
/* 0094C 80885AEC 37180003 */  ori     $t8, $t8, 0x0003           ## $t8 = DA380003
/* 00950 80885AF0 AD020004 */  sw      $v0, 0x0004($t0)           ## 00000004
/* 00954 80885AF4 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 00958 80885AF8 3C058088 */  lui     $a1, %hi(D_80885CE4)       ## $a1 = 80880000
/* 0095C 80885AFC 24A55CE4 */  addiu   $a1, $a1, %lo(D_80885CE4)  ## $a1 = 80885CE4
/* 00960 80885B00 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 00964 80885B04 AE0F02D0 */  sw      $t7, 0x02D0($s0)           ## 000002D0
/* 00968 80885B08 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 0096C 80885B0C 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 00970 80885B10 240602BA */  addiu   $a2, $zero, 0x02BA         ## $a2 = 000002BA
/* 00974 80885B14 0C0346A2 */  jal     Matrix_NewMtx              
/* 00978 80885B18 AFA20048 */  sw      $v0, 0x0048($sp)           
/* 0097C 80885B1C 8FA30048 */  lw      $v1, 0x0048($sp)           
/* 00980 80885B20 3C0B0402 */  lui     $t3, 0x0402                ## $t3 = 04020000
/* 00984 80885B24 256B84B0 */  addiu   $t3, $t3, 0x84B0           ## $t3 = 040184B0
/* 00988 80885B28 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 0098C 80885B2C 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 00990 80885B30 3C0ADE00 */  lui     $t2, 0xDE00                ## $t2 = DE000000
/* 00994 80885B34 3C068088 */  lui     $a2, %hi(D_80885CFC)       ## $a2 = 80880000
/* 00998 80885B38 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 0099C 80885B3C AE1902D0 */  sw      $t9, 0x02D0($s0)           ## 000002D0
/* 009A0 80885B40 AC4B0004 */  sw      $t3, 0x0004($v0)           ## 00000004
/* 009A4 80885B44 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 009A8 80885B48 8E250000 */  lw      $a1, 0x0000($s1)           ## 00000000
/* 009AC 80885B4C 24C65CFC */  addiu   $a2, $a2, %lo(D_80885CFC)  ## $a2 = 80885CFC
/* 009B0 80885B50 27A40058 */  addiu   $a0, $sp, 0x0058           ## $a0 = FFFFFFE8
/* 009B4 80885B54 0C031AD5 */  jal     func_800C6B54              
/* 009B8 80885B58 240702BE */  addiu   $a3, $zero, 0x02BE         ## $a3 = 000002BE
/* 009BC 80885B5C 8FBF003C */  lw      $ra, 0x003C($sp)           
/* 009C0 80885B60 8FB00034 */  lw      $s0, 0x0034($sp)           
/* 009C4 80885B64 8FB10038 */  lw      $s1, 0x0038($sp)           
/* 009C8 80885B68 03E00008 */  jr      $ra                        
/* 009CC 80885B6C 27BD0070 */  addiu   $sp, $sp, 0x0070           ## $sp = 00000000


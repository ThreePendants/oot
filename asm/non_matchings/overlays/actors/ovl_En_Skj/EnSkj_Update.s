glabel EnSkj_Update
/* 024D8 80B00788 27BDFFB8 */  addiu   $sp, $sp, 0xFFB8           ## $sp = FFFFFFB8
/* 024DC 80B0078C AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 024E0 80B00790 AFB10020 */  sw      $s1, 0x0020($sp)           
/* 024E4 80B00794 AFB0001C */  sw      $s0, 0x001C($sp)           
/* 024E8 80B00798 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 024EC 80B0079C 0C00BC65 */  jal     func_8002F194              
/* 024F0 80B007A0 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 024F4 80B007A4 3C0180B0 */  lui     $at, %hi(D_80B01EA0)       ## $at = 80B00000
/* 024F8 80B007A8 AC221EA0 */  sw      $v0, %lo(D_80B01EA0)($at)  
/* 024FC 80B007AC 860E02C6 */  lh      $t6, 0x02C6($s0)           ## 000002C6
/* 02500 80B007B0 860302CA */  lh      $v1, 0x02CA($s0)           ## 000002CA
/* 02504 80B007B4 24090003 */  addiu   $t1, $zero, 0x0003         ## $t1 = 00000003
/* 02508 80B007B8 25CF0001 */  addiu   $t7, $t6, 0x0001           ## $t7 = 00000001
/* 0250C 80B007BC 10600003 */  beq     $v1, $zero, .L80B007CC     
/* 02510 80B007C0 A60F02C6 */  sh      $t7, 0x02C6($s0)           ## 000002C6
/* 02514 80B007C4 2478FFFF */  addiu   $t8, $v1, 0xFFFF           ## $t8 = FFFFFFFF
/* 02518 80B007C8 A61802CA */  sh      $t8, 0x02CA($s0)           ## 000002CA
.L80B007CC:
/* 0251C 80B007CC 860202CC */  lh      $v0, 0x02CC($s0)           ## 000002CC
/* 02520 80B007D0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02524 80B007D4 10400002 */  beq     $v0, $zero, .L80B007E0     
/* 02528 80B007D8 2459FFFF */  addiu   $t9, $v0, 0xFFFF           ## $t9 = FFFFFFFF
/* 0252C 80B007DC A61902CC */  sh      $t9, 0x02CC($s0)           ## 000002CC
.L80B007E0:
/* 02530 80B007E0 860202CE */  lh      $v0, 0x02CE($s0)           ## 000002CE
/* 02534 80B007E4 10400003 */  beq     $v0, $zero, .L80B007F4     
/* 02538 80B007E8 2448FFFF */  addiu   $t0, $v0, 0xFFFF           ## $t0 = FFFFFFFF
/* 0253C 80B007EC A60802CE */  sh      $t0, 0x02CE($s0)           ## 000002CE
/* 02540 80B007F0 860202CE */  lh      $v0, 0x02CE($s0)           ## 000002CE
.L80B007F4:
/* 02544 80B007F4 54400003 */  bnel    $v0, $zero, .L80B00804     
/* 02548 80B007F8 920A02D2 */  lbu     $t2, 0x02D2($s0)           ## 000002D2
/* 0254C 80B007FC A20902D5 */  sb      $t1, 0x02D5($s0)           ## 000002D5
/* 02550 80B00800 920A02D2 */  lbu     $t2, 0x02D2($s0)           ## 000002D2
.L80B00804:
/* 02554 80B00804 11400016 */  beq     $t2, $zero, .L80B00860     
/* 02558 80B00808 00000000 */  nop
/* 0255C 80B0080C 8E0B02DC */  lw      $t3, 0x02DC($s0)           ## 000002DC
/* 02560 80B00810 15600013 */  bne     $t3, $zero, .L80B00860     
/* 02564 80B00814 00000000 */  nop
/* 02568 80B00818 920C02D1 */  lbu     $t4, 0x02D1($s0)           ## 000002D1
/* 0256C 80B0081C 24010009 */  addiu   $at, $zero, 0x0009         ## $at = 00000009
/* 02570 80B00820 1581000B */  bne     $t4, $at, .L80B00850       
/* 02574 80B00824 00000000 */  nop
/* 02578 80B00828 C6040024 */  lwc1    $f4, 0x0024($s0)           ## 00000024
/* 0257C 80B0082C 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 02580 80B00830 27A5003C */  addiu   $a1, $sp, 0x003C           ## $a1 = FFFFFFF4
/* 02584 80B00834 E7A4003C */  swc1    $f4, 0x003C($sp)           
/* 02588 80B00838 C6060028 */  lwc1    $f6, 0x0028($s0)           ## 00000028
/* 0258C 80B0083C 24060013 */  addiu   $a2, $zero, 0x0013         ## $a2 = 00000013
/* 02590 80B00840 E7A60040 */  swc1    $f6, 0x0040($sp)           
/* 02594 80B00844 C608002C */  lwc1    $f8, 0x002C($s0)           ## 0000002C
/* 02598 80B00848 0C007D52 */  jal     Item_DropCollectible
              
/* 0259C 80B0084C E7A80044 */  swc1    $f8, 0x0044($sp)           
.L80B00850:
/* 025A0 80B00850 0C00B55C */  jal     Actor_Kill
              
/* 025A4 80B00854 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 025A8 80B00858 1000003E */  beq     $zero, $zero, .L80B00954   
/* 025AC 80B0085C 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B00860:
/* 025B0 80B00860 0C00B56E */  jal     Actor_SetFocus
              
/* 025B4 80B00864 3C0541F0 */  lui     $a1, 0x41F0                ## $a1 = 41F00000
/* 025B8 80B00868 3C053C23 */  lui     $a1, 0x3C23                ## $a1 = 3C230000
/* 025BC 80B0086C 34A5D70A */  ori     $a1, $a1, 0xD70A           ## $a1 = 3C23D70A
/* 025C0 80B00870 0C00B58B */  jal     Actor_SetScale
              
/* 025C4 80B00874 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 025C8 80B00878 8E190274 */  lw      $t9, 0x0274($s0)           ## 00000274
/* 025CC 80B0087C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 025D0 80B00880 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 025D4 80B00884 0320F809 */  jalr    $ra, $t9                   
/* 025D8 80B00888 00000000 */  nop
/* 025DC 80B0088C 960D02C4 */  lhu     $t5, 0x02C4($s0)           ## 000002C4
/* 025E0 80B00890 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 025E4 80B00894 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 025E8 80B00898 0C2BFB0F */  jal     func_80AFEC3C              
/* 025EC 80B0089C A60D010E */  sh      $t5, 0x010E($s0)           ## 0000010E
/* 025F0 80B008A0 26050278 */  addiu   $a1, $s0, 0x0278           ## $a1 = 00000278
/* 025F4 80B008A4 AFA5002C */  sw      $a1, 0x002C($sp)           
/* 025F8 80B008A8 0C0189B7 */  jal     Collider_UpdateCylinder
              
/* 025FC 80B008AC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02600 80B008B0 920E02D3 */  lbu     $t6, 0x02D3($s0)           ## 000002D3
/* 02604 80B008B4 3C0F80B0 */  lui     $t7, %hi(D_80B01EA0)       ## $t7 = 80B00000
/* 02608 80B008B8 51C00012 */  beql    $t6, $zero, .L80B00904     
/* 0260C 80B008BC 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 02610 80B008C0 8DEF1EA0 */  lw      $t7, %lo(D_80B01EA0)($t7)  
/* 02614 80B008C4 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 02618 80B008C8 34211E60 */  ori     $at, $at, 0x1E60           ## $at = 00011E60
/* 0261C 80B008CC 15E0000C */  bne     $t7, $zero, .L80B00900     
/* 02620 80B008D0 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 02624 80B008D4 02212821 */  addu    $a1, $s1, $at              
/* 02628 80B008D8 AFA50030 */  sw      $a1, 0x0030($sp)           
/* 0262C 80B008DC 0C0175E7 */  jal     CollisionCheck_SetAT
              ## CollisionCheck_setAT
/* 02630 80B008E0 8FA6002C */  lw      $a2, 0x002C($sp)           
/* 02634 80B008E4 92180114 */  lbu     $t8, 0x0114($s0)           ## 00000114
/* 02638 80B008E8 8FA50030 */  lw      $a1, 0x0030($sp)           
/* 0263C 80B008EC 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 02640 80B008F0 57000004 */  bnel    $t8, $zero, .L80B00904     
/* 02644 80B008F4 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 02648 80B008F8 0C01767D */  jal     CollisionCheck_SetAC
              ## CollisionCheck_setAC
/* 0264C 80B008FC 8FA6002C */  lw      $a2, 0x002C($sp)           
.L80B00900:
/* 02650 80B00900 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
.L80B00904:
/* 02654 80B00904 34211E60 */  ori     $at, $at, 0x1E60           ## $at = 00011E60
/* 02658 80B00908 02212821 */  addu    $a1, $s1, $at              
/* 0265C 80B0090C 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 02660 80B00910 0C017713 */  jal     CollisionCheck_SetOC
              ## CollisionCheck_setOC
/* 02664 80B00914 8FA6002C */  lw      $a2, 0x002C($sp)           
/* 02668 80B00918 0C02927F */  jal     SkelAnime_Update
              
/* 0266C 80B0091C 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 02670 80B00920 0C00B638 */  jal     Actor_MoveForward
              
/* 02674 80B00924 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02678 80B00928 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 0267C 80B0092C 44810000 */  mtc1    $at, $f0                   ## $f0 = 20.00
/* 02680 80B00930 24080007 */  addiu   $t0, $zero, 0x0007         ## $t0 = 00000007
/* 02684 80B00934 AFA80014 */  sw      $t0, 0x0014($sp)           
/* 02688 80B00938 44060000 */  mfc1    $a2, $f0                   
/* 0268C 80B0093C 44070000 */  mfc1    $a3, $f0                   
/* 02690 80B00940 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 02694 80B00944 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 02698 80B00948 0C00B92D */  jal     Actor_UpdateBgCheckInfo              
/* 0269C 80B0094C E7A00010 */  swc1    $f0, 0x0010($sp)           
/* 026A0 80B00950 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B00954:
/* 026A4 80B00954 8FB0001C */  lw      $s0, 0x001C($sp)           
/* 026A8 80B00958 8FB10020 */  lw      $s1, 0x0020($sp)           
/* 026AC 80B0095C 03E00008 */  jr      $ra                        
/* 026B0 80B00960 27BD0048 */  addiu   $sp, $sp, 0x0048           ## $sp = 00000000

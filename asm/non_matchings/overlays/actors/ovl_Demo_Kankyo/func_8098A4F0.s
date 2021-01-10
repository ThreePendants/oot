.rdata
glabel D_8098C910
    .asciz "../z_demo_kankyo.c"
    .balign 4

glabel D_8098C924
    .asciz "../z_demo_kankyo.c"
    .balign 4

glabel D_8098C938
    .asciz "../z_demo_kankyo.c"
    .balign 4

.text
glabel func_8098A4F0
/* 01670 8098A4F0 27BDFF20 */  addiu   $sp, $sp, 0xFF20           ## $sp = FFFFFF20
/* 01674 8098A4F4 AFB30054 */  sw      $s3, 0x0054($sp)           
/* 01678 8098A4F8 00A09825 */  or      $s3, $a1, $zero            ## $s3 = 00000000
/* 0167C 8098A4FC AFBF006C */  sw      $ra, 0x006C($sp)           
/* 01680 8098A500 AFBE0068 */  sw      $s8, 0x0068($sp)           
/* 01684 8098A504 AFB70064 */  sw      $s7, 0x0064($sp)           
/* 01688 8098A508 AFB60060 */  sw      $s6, 0x0060($sp)           
/* 0168C 8098A50C AFB5005C */  sw      $s5, 0x005C($sp)           
/* 01690 8098A510 AFB40058 */  sw      $s4, 0x0058($sp)           
/* 01694 8098A514 AFB20050 */  sw      $s2, 0x0050($sp)           
/* 01698 8098A518 AFB1004C */  sw      $s1, 0x004C($sp)           
/* 0169C 8098A51C AFB00048 */  sw      $s0, 0x0048($sp)           
/* 016A0 8098A520 F7BE0040 */  sdc1    $f30, 0x0040($sp)          
/* 016A4 8098A524 F7BC0038 */  sdc1    $f28, 0x0038($sp)          
/* 016A8 8098A528 F7BA0030 */  sdc1    $f26, 0x0030($sp)          
/* 016AC 8098A52C F7B80028 */  sdc1    $f24, 0x0028($sp)          
/* 016B0 8098A530 F7B60020 */  sdc1    $f22, 0x0020($sp)          
/* 016B4 8098A534 F7B40018 */  sdc1    $f20, 0x0018($sp)          
/* 016B8 8098A538 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 016BC 8098A53C 0080A025 */  or      $s4, $a0, $zero            ## $s4 = 00000000
/* 016C0 8098A540 3C068099 */  lui     $a2, %hi(D_8098C910)       ## $a2 = 80990000
/* 016C4 8098A544 24C6C910 */  addiu   $a2, $a2, %lo(D_8098C910)  ## $a2 = 8098C910
/* 016C8 8098A548 27A400B4 */  addiu   $a0, $sp, 0x00B4           ## $a0 = FFFFFFD4
/* 016CC 8098A54C 24070591 */  addiu   $a3, $zero, 0x0591         ## $a3 = 00000591
/* 016D0 8098A550 0C031AB1 */  jal     Graph_OpenDisps              
/* 016D4 8098A554 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 016D8 8098A558 3C020405 */  lui     $v0, %hi(gDust5Tex)                ## $v0 = 04050000
/* 016DC 8098A55C 3C0100FF */  lui     $at, 0x00FF                ## $at = 00FF0000
/* 016E0 8098A560 3421FFFF */  ori     $at, $at, 0xFFFF           ## $at = 00FFFFFF
/* 016E4 8098A564 24422DB0 */  addiu   $v0, $v0, %lo(gDust5Tex)           ## $v0 = 04052DB0
/* 016E8 8098A568 0041B824 */  and     $s7, $v0, $at              
/* 016EC 8098A56C 3C0141F0 */  lui     $at, 0x41F0                ## $at = 41F00000
/* 016F0 8098A570 4481F000 */  mtc1    $at, $f30                  ## $f30 = 30.00
/* 016F4 8098A574 00027100 */  sll     $t6, $v0,  4               
/* 016F8 8098A578 000E7F02 */  srl     $t7, $t6, 28               
/* 016FC 8098A57C 3C0142F0 */  lui     $at, 0x42F0                ## $at = 42F00000
/* 01700 8098A580 3C198016 */  lui     $t9, %hi(gSegments)
/* 01704 8098A584 3C080401 */  lui     $t0, %hi(gEffectDustDL)                ## $t0 = 04010000
/* 01708 8098A588 25080050 */  addiu   $t0, $t0, %lo(gEffectDustDL)           ## $t0 = 04010050
/* 0170C 8098A58C 27396FA8 */  addiu   $t9, %lo(gSegments)
/* 01710 8098A590 000FC080 */  sll     $t8, $t7,  2               
/* 01714 8098A594 3C1E0100 */  lui     $s8, %hi(D_01000000)                ## $s8 = 01000000
/* 01718 8098A598 3C15E300 */  lui     $s5, 0xE300                ## $s5 = E3000000
/* 0171C 8098A59C 4481E000 */  mtc1    $at, $f28                  ## $f28 = 120.00
/* 01720 8098A5A0 36B51801 */  ori     $s5, $s5, 0x1801           ## $s5 = E3001801
/* 01724 8098A5A4 27DE0000 */  addiu   $s8, $s8, %lo(D_01000000)           ## $s8 = 01000000
/* 01728 8098A5A8 0319B021 */  addu    $s6, $t8, $t9              
/* 0172C 8098A5AC AFA80078 */  sw      $t0, 0x0078($sp)           
/* 01730 8098A5B0 00009025 */  or      $s2, $zero, $zero          ## $s2 = 00000000
.L8098A5B4:
/* 01734 8098A5B4 00124880 */  sll     $t1, $s2,  2               
/* 01738 8098A5B8 01324821 */  addu    $t1, $t1, $s2              
/* 0173C 8098A5BC 000948C0 */  sll     $t1, $t1,  3               
/* 01740 8098A5C0 02898821 */  addu    $s1, $s4, $t1              
/* 01744 8098A5C4 86240170 */  lh      $a0, 0x0170($s1)           ## 00000170
/* 01748 8098A5C8 24018000 */  addiu   $at, $zero, 0x8000         ## $at = FFFF8000
/* 0174C 8098A5CC 00812021 */  addu    $a0, $a0, $at              
/* 01750 8098A5D0 00042400 */  sll     $a0, $a0, 16               
/* 01754 8098A5D4 0C01DE1C */  jal     Math_SinS
              ## sins?
/* 01758 8098A5D8 00042403 */  sra     $a0, $a0, 16               
/* 0175C 8098A5DC 44922000 */  mtc1    $s2, $f4                   ## $f4 = 0.00
/* 01760 8098A5E0 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 01764 8098A5E4 44814000 */  mtc1    $at, $f8                   ## $f8 = 10.00
/* 01768 8098A5E8 46802520 */  cvt.s.w $f20, $f4                  
/* 0176C 8098A5EC 86240170 */  lh      $a0, 0x0170($s1)           ## 00000170
/* 01770 8098A5F0 24018000 */  addiu   $at, $zero, 0x8000         ## $at = FFFF8000
/* 01774 8098A5F4 00812021 */  addu    $a0, $a0, $at              
/* 01778 8098A5F8 00042400 */  sll     $a0, $a0, 16               
/* 0177C 8098A5FC 461EA183 */  div.s   $f6, $f20, $f30            
/* 01780 8098A600 00042403 */  sra     $a0, $a0, 16               
/* 01784 8098A604 46083282 */  mul.s   $f10, $f6, $f8             
/* 01788 8098A608 00000000 */  nop
/* 0178C 8098A60C 461C0402 */  mul.s   $f16, $f0, $f28            
/* 01790 8098A610 460AF580 */  add.s   $f22, $f30, $f10           
/* 01794 8098A614 46008487 */  neg.s   $f18, $f16                 
/* 01798 8098A618 46169602 */  mul.s   $f24, $f18, $f22           
/* 0179C 8098A61C 0C01DE0D */  jal     Math_CosS
              ## coss?
/* 017A0 8098A620 00000000 */  nop
/* 017A4 8098A624 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 017A8 8098A628 44812000 */  mtc1    $at, $f4                   ## $f4 = 5.00
/* 017AC 8098A62C 86240170 */  lh      $a0, 0x0170($s1)           ## 00000170
/* 017B0 8098A630 3C014496 */  lui     $at, 0x4496                ## $at = 44960000
/* 017B4 8098A634 46040182 */  mul.s   $f6, $f0, $f4              
/* 017B8 8098A638 44814000 */  mtc1    $at, $f8                   ## $f8 = 1200.00
/* 017BC 8098A63C 24018000 */  addiu   $at, $zero, 0x8000         ## $at = FFFF8000
/* 017C0 8098A640 00812021 */  addu    $a0, $a0, $at              
/* 017C4 8098A644 00042400 */  sll     $a0, $a0, 16               
/* 017C8 8098A648 00042403 */  sra     $a0, $a0, 16               
/* 017CC 8098A64C 0C01DE0D */  jal     Math_CosS
              ## coss?
/* 017D0 8098A650 46083680 */  add.s   $f26, $f6, $f8             
/* 017D4 8098A654 3C014140 */  lui     $at, 0x4140                ## $at = 41400000
/* 017D8 8098A658 44818000 */  mtc1    $at, $f16                  ## $f16 = 12.00
/* 017DC 8098A65C 3C014396 */  lui     $at, 0x4396                ## $at = 43960000
/* 017E0 8098A660 44812000 */  mtc1    $at, $f4                   ## $f4 = 300.00
/* 017E4 8098A664 4610A481 */  sub.s   $f18, $f20, $f16           
/* 017E8 8098A668 C66A00E0 */  lwc1    $f10, 0x00E0($s3)          ## 000000E0
/* 017EC 8098A66C C66800E4 */  lwc1    $f8, 0x00E4($s3)           ## 000000E4
/* 017F0 8098A670 C67000E8 */  lwc1    $f16, 0x00E8($s3)          ## 000000E8
/* 017F4 8098A674 46049182 */  mul.s   $f6, $f18, $f4             
/* 017F8 8098A678 46185300 */  add.s   $f12, $f10, $f24           
/* 017FC 8098A67C 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 01800 8098A680 461C0482 */  mul.s   $f18, $f0, $f28            
/* 01804 8098A684 461A4280 */  add.s   $f10, $f8, $f26            
/* 01808 8098A688 46065380 */  add.s   $f14, $f10, $f6            
/* 0180C 8098A68C 46169102 */  mul.s   $f4, $f18, $f22            
/* 01810 8098A690 46048200 */  add.s   $f8, $f16, $f4             
/* 01814 8098A694 44064000 */  mfc1    $a2, $f8                   
/* 01818 8098A698 0C034261 */  jal     Matrix_Translate              
/* 0181C 8098A69C 00000000 */  nop
/* 01820 8098A6A0 3C0142FA */  lui     $at, 0x42FA                ## $at = 42FA0000
/* 01824 8098A6A4 44816000 */  mtc1    $at, $f12                  ## $f12 = 125.00
/* 01828 8098A6A8 3C014270 */  lui     $at, 0x4270                ## $at = 42700000
/* 0182C 8098A6AC 44817000 */  mtc1    $at, $f14                  ## $f14 = 60.00
/* 01830 8098A6B0 44066000 */  mfc1    $a2, $f12                  
/* 01834 8098A6B4 0C0342A3 */  jal     Matrix_Scale              
/* 01838 8098A6B8 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 0183C 8098A6BC 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 01840 8098A6C0 3C0BE700 */  lui     $t3, 0xE700                ## $t3 = E7000000
/* 01844 8098A6C4 3C0ED2D2 */  lui     $t6, 0xD2D2                ## $t6 = D2D20000
/* 01848 8098A6C8 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 0184C 8098A6CC AE0A02D0 */  sw      $t2, 0x02D0($s0)           ## 000002D0
/* 01850 8098A6D0 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 01854 8098A6D4 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 01858 8098A6D8 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 0185C 8098A6DC 35CEFFFF */  ori     $t6, $t6, 0xFFFF           ## $t6 = D2D2FFFF
/* 01860 8098A6E0 3C0DFA00 */  lui     $t5, 0xFA00                ## $t5 = FA000000
/* 01864 8098A6E4 244C0008 */  addiu   $t4, $v0, 0x0008           ## $t4 = 00000008
/* 01868 8098A6E8 AE0C02D0 */  sw      $t4, 0x02D0($s0)           ## 000002D0
/* 0186C 8098A6EC AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 01870 8098A6F0 AC4E0004 */  sw      $t6, 0x0004($v0)           ## 00000004
/* 01874 8098A6F4 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 01878 8098A6F8 3C18FB00 */  lui     $t8, 0xFB00                ## $t8 = FB000000
/* 0187C 8098A6FC 2419FFFF */  addiu   $t9, $zero, 0xFFFF         ## $t9 = FFFFFFFF
/* 01880 8098A700 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 01884 8098A704 AE0F02D0 */  sw      $t7, 0x02D0($s0)           ## 000002D0
/* 01888 8098A708 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 0188C 8098A70C AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 01890 8098A710 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 01894 8098A714 240900C0 */  addiu   $t1, $zero, 0x00C0         ## $t1 = 000000C0
/* 01898 8098A718 240B0010 */  addiu   $t3, $zero, 0x0010         ## $t3 = 00000010
/* 0189C 8098A71C 24480008 */  addiu   $t0, $v0, 0x0008           ## $t0 = 00000008
/* 018A0 8098A720 AE0802D0 */  sw      $t0, 0x02D0($s0)           ## 000002D0
/* 018A4 8098A724 AC550000 */  sw      $s5, 0x0000($v0)           ## 00000000
/* 018A8 8098A728 AC490004 */  sw      $t1, 0x0004($v0)           ## 00000004
/* 018AC 8098A72C 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 018B0 8098A730 3C0DDA38 */  lui     $t5, 0xDA38                ## $t5 = DA380000
/* 018B4 8098A734 35AD0003 */  ori     $t5, $t5, 0x0003           ## $t5 = DA380003
/* 018B8 8098A738 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 018BC 8098A73C AE0A02D0 */  sw      $t2, 0x02D0($s0)           ## 000002D0
/* 018C0 8098A740 AC550000 */  sw      $s5, 0x0000($v0)           ## 00000000
/* 018C4 8098A744 AC4B0004 */  sw      $t3, 0x0004($v0)           ## 00000004
/* 018C8 8098A748 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 018CC 8098A74C 3C058099 */  lui     $a1, %hi(D_8098C924)       ## $a1 = 80990000
/* 018D0 8098A750 24A5C924 */  addiu   $a1, $a1, %lo(D_8098C924)  ## $a1 = 8098C924
/* 018D4 8098A754 244C0008 */  addiu   $t4, $v0, 0x0008           ## $t4 = 00000008
/* 018D8 8098A758 AE0C02D0 */  sw      $t4, 0x02D0($s0)           ## 000002D0
/* 018DC 8098A75C AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 018E0 8098A760 8E640000 */  lw      $a0, 0x0000($s3)           ## 00000000
/* 018E4 8098A764 240605B5 */  addiu   $a2, $zero, 0x05B5         ## $a2 = 000005B5
/* 018E8 8098A768 0C0346A2 */  jal     Matrix_NewMtx              
/* 018EC 8098A76C 00408825 */  or      $s1, $v0, $zero            ## $s1 = 00000000
/* 018F0 8098A770 AE220004 */  sw      $v0, 0x0004($s1)           ## 00000004
/* 018F4 8098A774 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 018F8 8098A778 3C0FDB06 */  lui     $t7, 0xDB06                ## $t7 = DB060000
/* 018FC 8098A77C 35EF0020 */  ori     $t7, $t7, 0x0020           ## $t7 = DB060020
/* 01900 8098A780 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 01904 8098A784 AE0E02D0 */  sw      $t6, 0x02D0($s0)           ## 000002D0
/* 01908 8098A788 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 0190C 8098A78C 8ED80000 */  lw      $t8, 0x0000($s6)           ## 00000000
/* 01910 8098A790 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 01914 8098A794 0317C821 */  addu    $t9, $t8, $s7              
/* 01918 8098A798 03214021 */  addu    $t0, $t9, $at              
/* 0191C 8098A79C AC480004 */  sw      $t0, 0x0004($v0)           ## 00000004
/* 01920 8098A7A0 0C025314 */  jal     func_80094C50              
/* 01924 8098A7A4 8E640000 */  lw      $a0, 0x0000($s3)           ## 00000000
/* 01928 8098A7A8 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 0192C 8098A7AC 3C0ADA38 */  lui     $t2, 0xDA38                ## $t2 = DA380000
/* 01930 8098A7B0 354A0001 */  ori     $t2, $t2, 0x0001           ## $t2 = DA380001
/* 01934 8098A7B4 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 01938 8098A7B8 AE0902D0 */  sw      $t1, 0x02D0($s0)           ## 000002D0
/* 0193C 8098A7BC AC5E0004 */  sw      $s8, 0x0004($v0)           ## 00000004
/* 01940 8098A7C0 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 01944 8098A7C4 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 01948 8098A7C8 26520001 */  addiu   $s2, $s2, 0x0001           ## $s2 = 00000001
/* 0194C 8098A7CC 3C0CDE00 */  lui     $t4, 0xDE00                ## $t4 = DE000000
/* 01950 8098A7D0 244B0008 */  addiu   $t3, $v0, 0x0008           ## $t3 = 00000008
/* 01954 8098A7D4 AE0B02D0 */  sw      $t3, 0x02D0($s0)           ## 000002D0
/* 01958 8098A7D8 00129400 */  sll     $s2, $s2, 16               
/* 0195C 8098A7DC AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000000
/* 01960 8098A7E0 8FAD0078 */  lw      $t5, 0x0078($sp)           
/* 01964 8098A7E4 00129403 */  sra     $s2, $s2, 16               
/* 01968 8098A7E8 2A41001E */  slti    $at, $s2, 0x001E           
/* 0196C 8098A7EC 1420FF71 */  bne     $at, $zero, .L8098A5B4     
/* 01970 8098A7F0 AC4D0004 */  sw      $t5, 0x0004($v0)           ## 00000004
/* 01974 8098A7F4 3C068099 */  lui     $a2, %hi(D_8098C938)       ## $a2 = 80990000
/* 01978 8098A7F8 24C6C938 */  addiu   $a2, $a2, %lo(D_8098C938)  ## $a2 = 8098C938
/* 0197C 8098A7FC 27A400B4 */  addiu   $a0, $sp, 0x00B4           ## $a0 = FFFFFFD4
/* 01980 8098A800 8E650000 */  lw      $a1, 0x0000($s3)           ## 00000000
/* 01984 8098A804 0C031AD5 */  jal     Graph_CloseDisps              
/* 01988 8098A808 240705C2 */  addiu   $a3, $zero, 0x05C2         ## $a3 = 000005C2
/* 0198C 8098A80C 8FBF006C */  lw      $ra, 0x006C($sp)           
/* 01990 8098A810 D7B40018 */  ldc1    $f20, 0x0018($sp)          
/* 01994 8098A814 D7B60020 */  ldc1    $f22, 0x0020($sp)          
/* 01998 8098A818 D7B80028 */  ldc1    $f24, 0x0028($sp)          
/* 0199C 8098A81C D7BA0030 */  ldc1    $f26, 0x0030($sp)          
/* 019A0 8098A820 D7BC0038 */  ldc1    $f28, 0x0038($sp)          
/* 019A4 8098A824 D7BE0040 */  ldc1    $f30, 0x0040($sp)          
/* 019A8 8098A828 8FB00048 */  lw      $s0, 0x0048($sp)           
/* 019AC 8098A82C 8FB1004C */  lw      $s1, 0x004C($sp)           
/* 019B0 8098A830 8FB20050 */  lw      $s2, 0x0050($sp)           
/* 019B4 8098A834 8FB30054 */  lw      $s3, 0x0054($sp)           
/* 019B8 8098A838 8FB40058 */  lw      $s4, 0x0058($sp)           
/* 019BC 8098A83C 8FB5005C */  lw      $s5, 0x005C($sp)           
/* 019C0 8098A840 8FB60060 */  lw      $s6, 0x0060($sp)           
/* 019C4 8098A844 8FB70064 */  lw      $s7, 0x0064($sp)           
/* 019C8 8098A848 8FBE0068 */  lw      $s8, 0x0068($sp)           
/* 019CC 8098A84C 03E00008 */  jr      $ra                        
/* 019D0 8098A850 27BD00E0 */  addiu   $sp, $sp, 0x00E0           ## $sp = 00000000

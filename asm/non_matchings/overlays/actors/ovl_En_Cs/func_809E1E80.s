glabel EnCs_GetPathPointCount
/* 005D0 809E1E80 000570C0 */  sll     $t6, $a1,  3               
/* 005D4 809E1E84 01C47821 */  addu    $t7, $t6, $a0              
/* 005D8 809E1E88 03E00008 */  jr      $ra                        
/* 005DC 809E1E8C 91E20000 */  lbu     $v0, 0x0000($t7)           ## 00000000

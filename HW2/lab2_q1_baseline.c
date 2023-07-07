// TODO : 
"addi t5, zero, 16\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi t0, zero, 0\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"1:\n\t"
"lh t1, 0(%[h])\n\t"  //Load
"addi %[lw_cnt], %[lw_cnt], 1\n\t"
"lh t2, 0(%[x])\n\t"  //Load
"addi %[lw_cnt], %[lw_cnt], 1\n\t"
"add t3, t1, t2\n\t"  //
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"sh t3, 0(%[y])\n\t"  //t3 value y[i]
"addi %[sw_cnt], %[sw_cnt], 1\n\t"
"addi %[h], %[h], 2\n\t" //ptr++
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi %[x], %[x], 2\n\t" //ptr++
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi %[y], %[y], 2\n\t" //ptr++
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi t0, t0, 1\n\t"    
"addi %[arith_cnt], %[arith_cnt], 1\n\t"  
"addi %[others_cnt], %[others_cnt], 1\n\t"
"bne t0, t5, 1b\n\t"                

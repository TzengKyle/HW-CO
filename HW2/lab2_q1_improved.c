// TODO : 
"addi t1, zero, 16\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"1:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"vsetvli t0, t1, e16, ta, ma\n\t"
"addi %[lw_cnt], %[lw_cnt], 1\n\t"
"vle16.v v0, (%[x])\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"sub t1, t1, t0\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"slli t0, t0, 1\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"add %[x], %[x], t0\n\t"        // 將 a1 指針向後移動一個向量的大小，以便讀取下一個向量
"addi %[lw_cnt], %[lw_cnt], 1\n\t"
"vle16.v v1, (%[h])\n\t"      // 從 a2 中的地址讀取一個 32 位元的整數，存到 v1 向量中
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"add %[h], %[h], t0\n\t"       // 將 a2 指針向後移動一個向量的大小，以便讀取下一個向量
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"vadd.vv v2, v0, v1\n\t"   // 使用向量加法將 v0 和 v1 的每個元素相加，結果存儲在 v2 向
"addi %[sw_cnt], %[sw_cnt], 1\n\t"
"vse16.v v2, (%[y])\n\t"      // 將 v2 向量的值存儲到 a3 中的地址
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"add %[y], %[y], t0\n\t"        // 將 a3 指針向後移動一個向量的大小，以便寫入下一個向量
"addi %[others_cnt], %[others_cnt], 1\n\t"
"bnez t1, 1b\n\t"

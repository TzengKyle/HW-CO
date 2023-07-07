#include<stdio.h>
int main()
{ 
   	 FILE *input = fopen("../input/4.txt","r"); 
	 int f,i=0;
	 int h[9]={0}, x[3]={0}, y[3]={0}; 
	 for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
	 for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
	 for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
	 int *p_x = &x[0] ;
	 int *p_h = &h[0] ;
	 int *p_y = &y[0] ;
	 
	 asm volatile(
	 	"li t5, 3\n\t"  //used for inner and outer for loop
	 	"li t6, 0\n\t"  //outer loop cntr
		"3:\n\t"
		"beq t6, t5, 4f\n\t"  //outer loop branch
		"li t0, 0\n\t"  //inter loop cntr
		"1:\n\t"
		"beq t0, t5, 2f\n\t"  //inter loop branch
		"lw t1, 0(%[p_h])\n\t"  //Load
		"lw t2, 0(%[p_x])\n\t"  //Load
		"lw t3, 0(%[p_y])\n\t"  //Load
		"mul t4, t1, t2\n\t"    //multi
		"add t3, t3, t4\n\t"    //add
		"sw t3, 0(%[p_y])\n\t"  //store
		"addi %[p_h], %[p_h], 4\n\t" //ptr++
		"addi %[p_x], %[p_x], 4\n\t" //ptr++
		"addi t0, t0, 1\n\t"         
		"j 1b\n\t"                    
		"2:\n\t"
		//
		"addi %[p_x], %[p_x], -12\n\t"
		"addi %[p_y], %[p_y], 4\n\t"
		"addi t6, t6, 1\n\t"
		"j 3b\n\t"
		"4:\n\t"
		:[p_h] "+r" (p_h), [p_x] "+r" (p_x), [p_y] "+r" (p_y)   // Output operands
		:
		:"t0", "t1", "t2", "t3", "t4", "t5", "t6"       // Clobbered registers
	 );

	 p_y = &y[0];
	 for(i = 0; i<3; i++)
	 	printf("%d \n", *p_y++);
	 return(0) ; 
 
}

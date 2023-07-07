/*
 * description: 1x3 matrix - multiply benchmarking
 *
 * |h11 h12 h13|   |x1|   |y1|   | h11*x1+h12*x2+h13*x3 |
 * |h21 h22 h23| * |x2| + |y2| = | h21*x1+h22*x2+h23*x3 |
 * |h31 h32 h33|   |x3|   |y3|   | h31*x1+h32*x2+h33*x3 |
 * 
 * Element are to store in following order:
 
 * 
 * matrix h[9]={h11,h12,h13, h21,h22,h23, h31,h32,h33}
 * vector x[3]={x1,x2,x3}
 * vector y[3]={y1,y2,y3}
 */
#include<stdio.h>
int main()
{ 
	 FILE *input = fopen("../input/3.txt","r"); 
	 int f,i=0;
	 int h[9]={0}, x[3]={0}, y[3]={0}; 
	 for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
	 for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
	 for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
	 int *p_x = &x[0] ;
	 int *p_h = &h[0] ;
	 int *p_y = &y[0] ;
	 
	 for (i = 0 ; i < 3; i++)
	 { 
		 p_x = &x[0] ; 
		 for (f = 0 ; f < 3; f++)
			 asm volatile(
			 	"mul %[h], %[h], %[x]\n\t"
			 	"add %[y], %[y], %[h]\n\t"
				"addi %[p_h], %[p_h], 4\n\t"
				"addi %[p_x], %[p_x], 4\n\t"
			 	:[h] "+r" (*p_h), [y] "+r" (*p_y), [p_h] "+r" (p_h), [p_x] "+r" (p_x)
			 	:[x] "r" (*p_x)
			 );
		 p_y++;
	 }
	 p_y = &y[0];
	 for(i = 0; i<3; i++)
	 	printf("%d \n", *p_y++);
	 return(0) ; 
 
}

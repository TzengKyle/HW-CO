#include <stdio.h>
int main ()
{
	FILE *input = fopen("../input/1.txt","r"); 
	int a, b; 
	fscanf(input, "%d %d", &a, &b);
	asm volatile(
		"sub %[A], %[A], %[B]\n\t" //AssemblerTemplate
		:[A] "+r"(a) //OutputOperands, "=r" means write-only, "+r"means read/write
		:[B] "r"(b) //InputOperands 
	);
	printf("%d\n", a);
	return 0;
}

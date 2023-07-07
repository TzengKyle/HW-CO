// description: cn = an - bn
#include <stdio.h>
int main ()
	{
	FILE *input = fopen("../input/2.txt","r"); 
	int a[10] = {0}, b[10]= {0}, c[10] = {0}; 
	int i, arr_size = 10;
	for(i = 0; i<arr_size; i++) {fscanf(input,"%d", &a[i]);}
	for(i = 0; i<arr_size; i++) {fscanf(input,"%d", &b[i]);}
	for(i = 0; i<arr_size; i++) {fscanf(input,"%d", &c[i]);}
	int *p_a = &a[0];
	int *p_b = &b[0];
	int *p_c = &c[0];

	/* Original C code segment
	 for (int i = 0; i < arr_size; i++){
	 *p_c++ = *p_a++ - *p_b++;
	 }
	 */
	for (int i = 0; i < arr_size; i++)
	    asm volatile("sub %[c], %[a], %[b]\n\t"
	    	"addi %[p_a], %[p_a], 4\n\t"
		"addi %[p_b], %[p_b], 4\n\t"
		"addi %[p_c], %[p_c], 4\n\t"
	    	:[c] "+r" (*p_c), [p_a] "+r" (p_a), [p_b] "+r" (p_b), [p_c] "+r" (p_c)
	    	:[a] "r" (*p_a), [b] "r" (*p_b)
	    	

        );
    
	    
	p_c = &c[0];
	for (int i = 0; i < arr_size; i++)
		printf("%d ", *p_c++);
	return 0;
}

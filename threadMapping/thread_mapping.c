#include <stdio.h>
int main(){
	int source[32];
	int dst[32];
	int i;
	for(i=0;i<32;i++)
		source[i]=i;
   for(i=0;i<32;i++){
		dst[i] = ( (source[i]<<1) | (source[i]>>4)) &0x1F;
/* int OffsThrRowPermuted = ((OffsThreadInRow << 1) | (OffsThreadInRow >> 4) & 0x1)&0x1F;*/
		printf("%d\t",dst[i]);
	}
	printf("\n");
}
